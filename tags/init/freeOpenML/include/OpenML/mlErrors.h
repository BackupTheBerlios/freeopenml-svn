/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#include <errno.h>


#define ML_STATUS_NO_ERROR 								0
#define ML_STATUS_INVALID_ID 							ENODEV
#define ML_STATUS_INVALID_PARAMETER 			EBADMSG
#define ML_STATUS_INVALID_VALUE 					EINVAL
#define ML_STATUS_ACCESS_DENIED 					EACCES
#define ML_STATUS_INVALID_ARGUMENT				EINVAL
#define ML_STATUS_OUT_OF_MEMORY						ENOMEM
#define ML_STATUS_INSUFFICIENT_RESOURCES	EBUSY
#define ML_STATUS_DEVICE_UNAVAILABLE			ENXIO
#define ML_STATUS_INTERNAL_ERROR					EIO
#define ML_STATUS_INVALID_CONFIGURATION 	ENOTSUP
#define ML_STATUS_SEND_QUEUE_OVERFLOW			ENOSPC
#define ML_STATUS_RECEIVE_QUEUE_OVERFLOW	ENOSPC
#define ML_STATUS_NO_OPERATION						EINPROGRESS
#define ML_STATUS_RECEIVE_QUEUE_EMPTY			EAGAIN

#define ML_MESSAGE_COMPLETE					0
#define ML_MESSAGE_ABORTED					ECANCELED
#define ML_MESSAGE_FAILED						EBADMSG

#define ML_CONTROLS_COMPLETE				ML_MESSAGE_COMPLETE
#define ML_CONTROLS_ABORTED					ML_MESSAGE_ABORTED
#define	ML_CONTROLS_FAILED					ML_MESSAGE_FAILED

#define ML_BUFFERS_COMPLETE					ML_MESSAGE_COMPLETE
#define ML_BUFFERS_ABORTED					ML_MESSAGE_ABORTED
#define	ML_BUFFERS_FAILED						ML_MESSAGE_FAILED

#define ML_QUERY_CONTROLS_COMPLETE	ML_MESSAGE_COMPLETE
#define ML_QUERY_CONTROLS_ABORTED		ML_MESSAGE_ABORTED
#define	ML_QUERY_CONTROLS_FAILED		ML_MESSAGE_FAILED
