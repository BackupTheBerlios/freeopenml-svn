/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#include <semaphore.h>
#include <OpenML/mlparam.h>
#include <string.h>

struct mlMessageQueue {
	MLpv head;
	MLpv* tail;
	sem_t count;
	pthread_mutex_t queue_mtx;
	};

/** get message count
 * @param mlMessageQueue : the message qeue to query
 * @return number of message, -1 on error and set errno
 */
int32_t
MessageCount (struct mlMessageQueue *queue);

/**copy a message to the queue, allocating memory
 * @param mlMessageQueue : the message qeue to modify
 * @param message : the message to copy into
 */
u_int32_t
mlCopyPushMQueue(struct mlMessageQueue *queue, MLpv* message, int32_t length);

/**copy a message to the queue, using the message directly, application gives up all rights on the
 * current message
 * @param mlMessageQueue : the message qeue to modify
 * @param message : the message to copy into
 */
u_int32_t
mlPushMQueue(struct mlMessageQueue *queue, MLpv* message, int32_t length);

/**move a message from the queue, allocating memory
 * @param mlMessageQueue : the message qeue to modify
 * @param message : the message to copy into
 */
u_int32_t
mlCopyPopMQueue(struct mlMessageQueue *queue, MLpv** message, int32_t* length,
						int16_t* status);

/**move a message from the queue, allocating memory
 * @param mlMessageQueue : the message qeue to modify
 * @param message : the message to copy into
 */
u_int32_t
mlPopMQueue(struct mlMessageQueue *queue, MLpv** message, int32_t* length,
						int16_t* status);

/**initialize a queue for further processing
 */
inline int
mlInitMQueue(struct mlMessageQueue *queue);
