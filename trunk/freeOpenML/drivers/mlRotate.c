/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



/**mlPlugin that perform copy basic software rotation (90, 180, 270)
 * futur hardware accelaration is planned
 */

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
int64_t baseID; //id used to construct all others id

#define IO_ID_SHFT 28
#define IO_ID_MASK ((int64_t)0xf<<IO_ID_SHFT)
#define OPEN_OPTIONS_SHFT 24
#define OPEN_OPTIONS_MASK ((int64_t)0xf<<OPEN_OPTIONS_SHFT)


extern struct pipe_desc* rotate_inputs[];
extern struct pipe_desc* rotate_outputs[];
extern struct xcode_desc* rotate_xcodes[];
extern struct device_desc rotate_dev;


struct xcode_desc rotate_xcode={
			.desc.name				=	"mlRotate xcoder",
			.desc.parent			=	(struct type_desc*) &rotate_dev,
			.engineType	=ML_XCODE_ENGINE_TYPE_NULL,
			.implementationType=ML_XCODE_IMPLEMENTATION_TYPE_SW,
			//.bufferAlignement=getpagesize();
			.srcsCount=1,
			.srcs=rotate_inputs,
			.destCount=1,
			.dest=rotate_outputs,
			.feats="rien\0de\0special\0",
	};
struct xcode_desc* rotate_xcodes[]={&rotate_xcode};

struct pipe_desc rotate_input0={
	.desc.name="input stream",
	.desc.parent=(struct type_desc*)&rotate_xcode,
	.type=ML_PIPE_TYPE_MEM_TO_ENGINE,
	};
struct pipe_desc* rotate_inputs[]={&rotate_input0};

struct pipe_desc rotate_output0={
	.desc.name="output stream",
	.desc.parent=(struct type_desc*)&rotate_xcode,
	.type=ML_PIPE_TYPE_ENGINE_TO_MEM,
	};
struct pipe_desc* rotate_outputs[]={&rotate_output0};
	


struct device_desc rotate_dev={
	.desc.name	=	"soft rotation",
	.version		=	1,
	.index			=	"",
	.location		=	"",
	.xcodes			=	rotate_xcodes,
	.xcodesCount=1,
	};




#define STATUS_HOLD_IN_SEM 1<<0
#define STATUS_HOLD_OUT_SEM 1<<1
#define STATUS_HOLD_RUN_MTX 1<<2
#define STATUS_HOLD_MOD_MTX 1<<3
struct priv_data{
	pthread_mutex_t run_mtx;
	pthread_mutex_t module_mtx;
	int32_t status;
	int32_t width;
	int32_t height;
	struct buffer* in_buff;
	struct buffer* out_buff;
	void (*perform_rotate)(u_int8_t* src, u_int8_t* dest,
													int32_t width, int32_t height);
	char enable;
	pthread_t 			pid;
};

void
thread_cleaning(void* data)
{
	struct priv_data*  priv= (struct priv_data*) data;
	if ( priv->status & STATUS_HOLD_IN_SEM )
		{
		sem_post(&(priv->in_buff->sem));
		}
	if ( priv->status & STATUS_HOLD_OUT_SEM )
		{
		sem_post(&(priv->in_buff->sem));
		}
	return;
}


#define rotate90 { \
	for (i=0; i<width; i++)\
		for (j=0; j<height; j++)\
			*(dest_bpp+i*height+j)=*(src_bpp + j*width + width-i);\
	}

#define rotate180 { \
	for (i=0; i<height; i++)\
		for (j=0; j<width; j++)\
			*(dest_bpp+i*width+j)=*(src_bpp + (height-i)*width + (width-j));\
	}

#define rotate270 { \
	for (i=0; i<width; i++)\
		for (j=0; j<height; j++)\
			*(dest_bpp+i*height+j)=*(src_bpp + (height-j)*width + i);\
	}

//general purpose already build in rotations
#warning create a hardware accelerated rotation
void rotate90_8bpp ( u_int8_t* src, u_int8_t* dest,
										int32_t width, int32_t height)
	{
	int i,j;
	u_int8_t* src_bpp=(u_int8_t*)src;
	u_int8_t* dest_bpp=(u_int8_t*) dest;
	rotate90;
	}
void rotate180_8bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int8_t* src_bpp=(u_int8_t*)src;
	u_int8_t* dest_bpp=(u_int8_t*) dest;
	rotate180;
	}
void rotate270_8bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int8_t* src_bpp=(u_int8_t*)src;
	u_int8_t* dest_bpp=(u_int8_t*) dest;
	rotate270;
	}
void rotate90_16bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int16_t* src_bpp=(u_int16_t*)src;
	u_int16_t* dest_bpp=(u_int16_t*) dest;
	rotate90;
	}
void rotate180_16bpp ( u_int8_t* src, u_int8_t* dest,
											 int32_t width, int32_t height)
	{
	int i,j;
	u_int16_t* src_bpp=(u_int16_t*)src;
	u_int16_t* dest_bpp=(u_int16_t*) dest;
	rotate180;
	}
void rotate270_16bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int16_t* src_bpp=(u_int16_t*)src;
	u_int16_t* dest_bpp=(u_int16_t*) dest;
	rotate270;
	}
/* void rotate90_24bpp ( u_int8_t* src, u_int8_t* dest,
													int32_t width, int32_t height)
	{
	int i,j;
	u_int16_t* src_bpp=(u_int16_t*)src;
	u_int16_t* dest_bpp=(u_int16_t*) dest;
	rotate90;
	}
void rotate180_24bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int16_t* src_bpp=(u_int16_t*)src;
	u_int16_t* dest_bpp=(u_int16_t*) dest;
	rotate180;
	}
void rotate270_24bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int16_t* src_bpp=(u_int16_t*)src;
	u_int16_t* dest_bpp=(u_int_t*) dest;
	rotate270;
	} */
void rotate90_32bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int32_t* src_bpp=(u_int32_t*)src;
	u_int32_t* dest_bpp=(u_int32_t*) dest;
	rotate90;
	}
void rotate180_32bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int32_t* src_bpp=(u_int32_t*)src;
	u_int32_t* dest_bpp=(u_int32_t*) dest;
	rotate180;
	}
void rotate270_32bpp ( u_int8_t* src, u_int8_t* dest,
											int32_t width, int32_t height)
	{
	int i,j;
	u_int32_t* src_bpp=(u_int32_t*)src;
	u_int32_t* dest_bpp=(u_int32_t*) dest;
	rotate270;
	}


int
process_message (struct mlPipe* pipe, MLpv** message, int32_t* length,
									struct priv_data* priv)
{
	MLpv* current;
	int rotate=0;
	while (rotate != 1 )
		{
			mlPopMQueue	(&(pipe[0].in) , message, length,NULL);
			current=*message;
			while (current->param != ML_END )
				{
					current++;
				}
			if ( rotate != 1)
				mlPushMQueue(&(pipe[0].out), *message, *length);
		}
	return 0;
}

int32_t
XcodeWork		( struct mlID* openid	)
{
	struct mlID* id=(struct mlID*) openid;
	struct priv_data* priv=(struct priv_data*) id->priv;
	MLpv* in_msg;
	MLpv* out_msg;
	
	int32_t in_length;
	int32_t out_length;
	pthread_mutex_lock(&priv->run_mtx); //synchro
	pthread_mutex_unlock(&priv->run_mtx);

	process_message(&id->pipes[0], &in_msg, &in_length, priv);
	process_message(&id->pipes[1], &out_msg, &out_length, priv);

	pthread_mutex_lock(&priv->module_mtx);
	sem_wait(&priv->in_buff->sem);
	priv->status |= STATUS_HOLD_IN_SEM;
	sem_wait(&priv->out_buff->sem);
	priv->status |= STATUS_HOLD_OUT_SEM;

	priv->perform_rotate( &(priv->in_buff->data),
												&(priv->out_buff->data),
												priv->width, priv->height);
	sem_post(&priv->out_buff->sem);
	priv->status &= ~STATUS_HOLD_OUT_SEM;
	sem_post(&priv->in_buff->sem);
	priv->status &= ~STATUS_HOLD_IN_SEM;
	pthread_mutex_unlock(&priv->module_mtx);

	mlPushMQueue(&id->pipes[0].out, in_msg, in_length);
	mlPushMQueue(&id->pipes[1].out, out_msg, out_length);
	return 1;
}

void*
main_queue_handler (void* queue_info)
{
	struct mlID* id=(struct mlID*) queue_info;
	struct priv_data* priv=(struct priv_data*) id->priv;
	pthread_cleanup_push(thread_cleaning, priv);
	pthread_cleanup_pop(0);
	while (1)
		{
			XcodeWork(queue_info);
		}

	return (void*)0;
}


int32_t
PvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
				MLpv** capabilities)
{
	if ( paramid == 0)
		{
			if ( (rotate_dev.desc.id == id)  )
				{
					*capabilities=deviceToMessage (&rotate_dev);
					return errno;
				}
			else if  ( rotate_output0.desc.id == id)
				{
					*capabilities=pipeToMessage (&rotate_output0);
					return errno;
				}
			else if  ( rotate_input0.desc.id == id )
				{
					*capabilities=pipeToMessage (&rotate_input0);
					return errno;
				}
			else if ( rotate_xcode.desc.id == id )
				{
					*capabilities=xcodeToMessage (&rotate_xcode);
					return errno;
				}
			else 
				return ENODEV;
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
	handle = NULL;
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




struct mlID fwd_dev={
	.pipes_count=2,
	.mlPvGetCapabilities	=	PvGetCapabilities,
	.mlOpen								=	_mlOpen,
	.mlClose							=	_mlClose,
	.mlGetControls				=	GetControls,
	.mlSetControls				= SetControls,
	.mlGetReceiveWaitHandle = GetReceiveWaitHandle,
	.mlBeginTransfer 			= BeginTransfer,
	.mlEndTransfer 				= EndTransfer,
	.mlXcodeWork					= XcodeWork,
	};

u_int32_t module_init(int argc, char** argv)
{
	fprintf(stderr, "initializing mlrotate plugin\n");
	if (mlDeviceRegister(&fwd_dev))
		return errno;
	updateAllId(&rotate_dev, fwd_dev.id);
	return errno;
}

