/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES


#include <OpenML/OpenML.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

int32_t
MessageCount (struct mlMessageQueue *queue)
{
	int32_t count=0;
	MLpv* current=&(queue->head);
	while (current->length != 0)
		{
			count+=current->length;
			current=current->value.pPv+current->length-1;
		}
	return count;
}

inline int32_t
firstMessLength (struct mlMessageQueue *queue)
{
	errno=0;
	return queue->head.length;
}

inline int32_t
mlMessageLength(MLpv* message)
{
	int32_t i=0;
	errno=0;
	while (message[i].param != ML_END)
		{
			i++;
		}
	return (i+1);
}

int
mlInitMQueue(struct mlMessageQueue *queue)
{
	errno=0;
	queue->head.param=ML_END;
	queue->head.value.pPv=NULL;
	queue->tail=&(queue->head);
	sem_init(&(queue->count),0,0);
	if (errno)
		fprintf(stderr, "%s : %s\n","sem_init failed",strerror (errno));
	return errno;
}

inline int
mlCopyMLpv(MLpv*out, MLpv* in, int32_t count)
{
	errno=0;
	int i=0;
	memcpy( (void*) out, (void*) in, count*sizeof(MLpv));
	while (in[i].param != ML_END)
		{
			switch (ML_PARAM_GET_TYPE(in[i].param))
				{
				case ML_TYPE_BYTE_ARRAY :
					in[i].value.pByte=malloc( in[i].maxLength * sizeof(int8_t));
					if ( NULL == in[i].value.pByte)
						return errno;
					memcpy( (void*) out[i].value.pByte, (void*) in[i].value.pByte,
									in[i].maxLength * sizeof(int8_t));
					break;
				case ML_TYPE_INT32_ARRAY :
					in[i].value.pInt32=malloc( in[i].maxLength * sizeof(int32_t));
					if ( NULL == in[i].value.pInt32)
						return errno;
					memcpy( (void*) out[i].value.pInt32, (void*) in[i].value.pInt32,
									in[i].maxLength * sizeof(int32_t));
					break;
				case ML_TYPE_INT64_ARRAY :
					in[i].value.pInt64=malloc( in[i].maxLength * sizeof(int64_t));
					if ( NULL == in[i].value.pInt64)
						return errno;
					memcpy( (void*) out[i].value.pInt64, (void*) in[i].value.pInt64,
									in[i].maxLength * sizeof(int64_t));
					break;
				case ML_TYPE_REAL32_ARRAY :
					in[i].value.pReal32=malloc( in[i].maxLength * sizeof(float));
					if ( NULL == in[i].value.pReal32)
						return errno;
					memcpy( (void*) out[i].value.pReal32, (void*) in[i].value.pReal32,
									in[i].maxLength * sizeof(float));
					break;
				case ML_TYPE_REAL64_ARRAY :
					in[i].value.pReal64=malloc( in[i].maxLength * sizeof(double));
					if ( NULL == in[i].value.pReal64)
						return errno;
					memcpy( (void*) out[i].value.pReal64, (void*) in[i].value.pReal64,
									in[i].maxLength * sizeof(double));
					break;
				case ML_TYPE_PV_ARRAY :
					in[i].value.pPv=malloc( in[i].maxLength * sizeof(MLpv));
					if ( NULL == in[i].value.pPv)
						return errno;
					memcpy( (void*) out[i].value.pPv, (void*) in[i].value.pPv,
									in[i].maxLength * sizeof(MLpv));
					break;
				case ML_TYPE_MSG_ARRAY :
					in[i].value.pMsg=malloc( in[i].maxLength * sizeof(MLpv*));
					if ( NULL == in[i].value.pMsg)
						return errno;
					memcpy( (void*) out[i].value.pMsg, (void*) in[i].value.pMsg,
									in[i].maxLength * sizeof(MLpv*));
					break;
				}
			i++;
		}
	out[count-1].value.pPv=NULL;
	return errno;
}


u_int32_t
mlCopyPushMQueue(struct mlMessageQueue *queue, MLpv* message, int32_t length)
{
	errno=0;
	if (length == 0 )
		length = mlMessageLength(message);

	MLpv* copy= malloc(length*sizeof(MLpv));
	if (copy ==NULL)
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
			return ENOMEM;
		}
	mlCopyMLpv(copy,message,length);
	return mlPushMQueue(queue,copy,length);
}

u_int32_t
mlPushMQueue(struct mlMessageQueue *queue, MLpv* message, int32_t length)
{
	errno=0;
	pthread_mutex_lock(&(queue->queue_mtx));
	if (length == 0 )
		length=mlMessageLength(message);

	if (queue->head.value.pPv==NULL)
		{
			queue->head.value.pPv=message;
			queue->head.length=length;
		}
	else
		{
			queue->tail->value.pPv=message;
			queue->tail->length=length;
		}
	queue->tail=&(message[length-1]);
	sem_post(&(queue->count));
	pthread_mutex_unlock(&(queue->queue_mtx));
	return errno;
}

u_int32_t
mlCopyPopMQueue(struct mlMessageQueue *queue, MLpv** message, int32_t* length,
								int16_t* status)
{
	errno=0;
	MLpv* data=NULL;
	MLpv* copy;
	int32_t len;

	len=firstMessLength (queue);
	if (length != NULL)
		*length=len;
	copy = malloc(len*sizeof(MLpv));
	if (copy == NULL)
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
			return ENOMEM;
		}

	if ( mlPopMQueue(queue, &data, &len, status) )
		{
			return errno;
		}

	mlCopyMLpv(copy,data,len);
	*message=copy;
	free(data);
	return 0;
}

u_int32_t
mlPopMQueue(struct mlMessageQueue *queue, MLpv** message, int32_t* length,
						int16_t* status)
{
	int32_t len;


	errno=0;
	if (sem_wait(&(queue->count)))
		return errno;
	pthread_mutex_lock(&(queue->queue_mtx));
	if (queue->head.value.pPv==NULL)
		{
			if (message != NULL)
				*message=NULL;
			if (length != NULL )
				*length=0;
			errno = EAGAIN;
			pthread_mutex_unlock(&(queue->queue_mtx));
			return EAGAIN;
		}
	len=firstMessLength (queue);
	*message=queue->head.value.pPv;
	if ( length != NULL )	*length=len;
	queue->head.length=(*message)[queue->head.length - 1].length;
	queue->head.value.pPv=(*message)[len - 1].value.pPv;
	(*message)[len - 1].value.pPv=NULL;
	if (status !=NULL)
		{
			*status=(*message)[len - 1].length;
		}
	(*message)[len - 1].length=0;
	if (queue->head.value.pPv == NULL) queue->tail=&(queue->head);
	pthread_mutex_unlock(&(queue->queue_mtx));
	return 0;
}
