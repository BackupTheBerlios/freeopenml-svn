/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of version 2.1 of the GNU Lesser General Public
* License as published by the Free Software Foundation.
*
* This program is distributed in the hope that it would be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* Further, this software is distributed without any warranty that it
* is free of the rightful claim of any third person regarding
* infringement or the like.  Any license provided herein, whether
* implied or otherwise, applies only to this software file.  Patent
* licenses, if any, provided herein do not apply to combinations of
* this program with other software, or any other product whatsoever.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307,
* USA.
*
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

struct in_out{
	mqd_t 					in;
	mqd_t 					out;
	pthread_t 			pid;
};

void
toto(void* queue)
{
	struct in_out* queues_info=(struct in_out*) queue;
	mq_close(queues_info->in);
	mq_close(queues_info->out);
	return;
}


void*
main_queue_handler (void* queue_info)
{
	struct mlID* id=(struct mlID*) queue_info;
	struct in_out* queue=(struct in_out*) id->priv;
	MLpv buffer;
	int prio,err;

	pthread_cleanup_push(toto, queue);
	pthread_cleanup_pop(0);
	while (1)
		{
			sem_wait( &(id->enable) );
			pthread_testcancel();
			err=mq_receive(queue->in ,(char*)(&buffer),sizeof(MLpv),&prio);
			#warning test and remove
			pthread_testcancel(); //linuxthread bug
			err=mq_send   (queue->out,(char*)(&buffer),sizeof(MLpv),prio);
		}

	return (void*)0;
}


int32_t
PvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
				MLpv** capabilities)
{
	fprintf(stderr, "__GetCapabilities mlplugin\n");
	return 0;
}


int32_t
Open  ( struct mlID* id, struct mq_attr *myAttr,
									char in[25], char out[25])
{
	struct in_out* fds=NULL;
	int i=0;

	fds=malloc(sizeof(struct in_out));
	if (NULL == fds) goto err;

	if ( -1 == snprintf (in, sizeof(char)*25,"/fwd_i%d",i))
		{
			errno = ENAMETOOLONG;
			goto err;
		}
	if ( -1 == snprintf (out, sizeof(char)*25,"/fwd_o%d",i))
		{
			errno = ENAMETOOLONG;
			goto err;
		}

	//seems that linux need attr to be null....
	fds->in=mq_open(in, O_RDONLY|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR,NULL);
	if (fds->in == (mqd_t)(-1) )
		goto err;

	//seems that linux need attr to be null....
	fds->out=mq_open(out, O_WRONLY|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR,NULL);
	if (fds->out == (mqd_t)(-1) )
		goto err;

	id->priv=(void*)fds;

	errno=pthread_create(&fds->pid, NULL,main_queue_handler,(void *)id);
	if (errno)goto err;
	errno=pthread_detach(fds->pid);
	if (errno)goto err;

	fprintf(stderr, "__Open mlplugin\n");
	return 0;

	err:
		if (fds != NULL ) free(fds);
		perror(NULL);
		return errno;
}


int32_t
Close ( MLopenid openid)
{
	struct in_out* queues_info=(struct in_out*) ((struct mlID*)openid)->priv;
	fprintf(stderr, "__Close mlplugin\n");
	pthread_cancel(queues_info->pid);
	free(queues_info);
	return 0;
}


struct mlID fwd_dev={
	.mlPvGetCapabilities	=	PvGetCapabilities,
	.mlOpen								=	Open,
	.mlClose							=	Close,
	};

u_int32_t module_init(int argc, char** argv)
{
	fprintf(stderr, "initializing mlplugin\n");
	return mlDeviceRegister(&fwd_dev);
}


//the _init function is called automatically upon dlopen()
u_int32_t
_init(void)
{
}

//the _fini function is called automatically upon last dlclose()
u_int32_t
_fini(void)
{
}

