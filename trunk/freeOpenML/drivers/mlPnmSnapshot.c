/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/

#define __ML_MODULES

#include "OpenML/OpenML.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>


#define MAX_OPEN_COUNT 10
#warning make it thread safe ^_-
char openstate[MAX_OPEN_COUNT]={0,};
int continuer =1;

char forward_name[] = "mlForward";

MLpv cap[]={
	{ ML_ID },
	{ ML_NAME, { .pByte=forward_name }, 10, 10 },
	{ ML_END}
	};

struct priv_data{
	pthread_mutex_t run_mtx;
	pthread_mutex_t module_mtx;
	char enable;
	pthread_t 			pid;
};

void
thread_cleaning(void* priv)
{
	return;
}

int writepnm(FILE* dest, long width, long height, char* data, char bpp)
{
	int i,j;
	int position;

	__u16* bpp16_data=(__u16*) data;
	fprintf(dest,"P6\n%ld %ld\n255\n",width,height);
	printf("P6\n%ld %ld\n255\n",width,height);
	fflush(dest);
	for (i=0; i<height; i++)
		for (j=0; j<width; j++)
			{
			if (bpp == 16)  //5-6-5
				{
				position=i*width+j;
				putc( (bpp16_data[position]&0x001F)<<3	,dest);
				putc( (bpp16_data[position]&0x07E0)>>3	,dest);
				putc( (bpp16_data[position]&0xF800)>>8	,dest);
				printf("-");
				}
			else
				{
				position=i*width+j;
				#define Y  (bpp16_data[position] >>8)
				#define V ((bpp16_data[position]&0x00F0)>>4)
				#define U  (bpp16_data[position]&0x000F)
				putc( Y + 1.402*V,dest);
				putc( Y - 0.344*U - 0.714*V,dest);
				putc( Y + 1.772 * U ,dest);
				printf(".");
				}

			}
	fflush(dest);
	return 0;
}

void*
main_queue_handler (void* queue_info)
{
	struct mlID* id=(struct mlID*) queue_info;
	struct priv_data* priv=(struct priv_data*) id->priv;
	MLpv* buffer;
	int length;

	//push must be followed by pop
	pthread_cleanup_push(thread_cleaning, priv);
	pthread_cleanup_pop(0);
	while (1)
		{
			pthread_mutex_lock(&priv->run_mtx); //synchro
			pthread_mutex_unlock(&priv->run_mtx);
			mlPopMQueue	(&id->in , &buffer, &length,NULL);
			mlPushMQueue(&id->out, buffer, length);
		}

	return (void*)0;
}


int32_t
PvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
				MLpv** capabilities)
{
	if ( paramid == 0)
		{
			*capabilities=cap;
			return 0;
		}
	return EINVAL;
}


int32_t
_mlOpen  ( struct mlID* id, MLpv* options)
{
	struct priv_data* fds=NULL;

	fds=malloc(sizeof(struct priv_data));
	if (NULL == fds) goto err;
	fds->pid=0;
	pthread_mutex_init(&fds->run_mtx,NULL);
	pthread_mutex_init(&fds->module_mtx,NULL);
	pthread_mutex_lock(&fds->run_mtx); //synchro prevent from running

	id->priv=(void*)fds;

	errno=pthread_create(&fds->pid, NULL,main_queue_handler,(void *)id);
	if (errno)goto err;
	errno=pthread_detach(fds->pid);
	if (errno)goto err;

	fprintf(stderr,"%s %s\n", __FILE__,__FUNCTION__);
	return 0;

	err:
		if (fds != NULL )
			{
				if (fds->pid != 0) pthread_cancel(fds->pid);
				free(fds);
			}
		fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
		return errno;
}


int32_t
_mlClose (struct mlID* openid)
{
	struct priv_data* queues_info=(struct priv_data*) openid->priv;
	fprintf(stderr,"%s %s\n", __FILE__,__FUNCTION__);
	pthread_cancel(queues_info->pid);
	free(queues_info);
	return 0;
}



int32_t
GetControls 	( struct mlID* openid, MLpv* controls)
{
	return 1;
}

int32_t
SetControls 	( struct mlID* openid, MLpv* controls)
{
	return 1;
}

int32_t
GetReceiveWaitHandle( struct mlID* openid,	MLwaitable* handle)
{
	return 1;
}

int32_t
BeginTransfer( struct mlID* openid	)
{
	struct mlID* id=(struct mlID*) openid;
	struct priv_data* priv=(struct priv_data*) id->priv;
	pthread_mutex_unlock(&priv->run_mtx);
	return errno;
}

int32_t
EndTransfer	( struct mlID* openid	)
{
	struct mlID* id=(struct mlID*) openid;
	struct priv_data* priv=(struct priv_data*) id->priv;
	pthread_mutex_lock(&priv->run_mtx);
	return errno;
}

int32_t
XcodeWork		( struct mlID* codec	)
{
	return 1;
}


struct mlID fwd_dev={
	.mlPvGetCapabilities	=	PvGetCapabilities,
	.mlOpen								=	_mlOpen,
	.mlClose							=	_mlClose,
	.mlGetControls				=	GetControls,
	.mlSetControls				= SetControls,
	.mlGetReceiveWaitHandle =GetReceiveWaitHandle,
	.mlBeginTransfer 			=BeginTransfer,
	.mlEndTransfer 				=EndTransfer,
	.mlXcodeWork					=XcodeWork,
	};

u_int32_t module_init(int argc, char** argv)
{
	fprintf(stderr, "initializing mlforward plugin\n");
	if (mlDeviceRegister(&fwd_dev))
		return errno;
	cap[0].value.int64=fwd_dev.id;
	return errno;
}

