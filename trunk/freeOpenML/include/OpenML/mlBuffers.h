/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#ifndef _ML_BUFFERS_H_
	#define _ML_BUFFERS_H_
	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <unistd.h>
	#include <semaphore.h>

	struct sbuffer {
		sem_t sem;
		u_int8_t data;
		};


	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_BUFFERS_H_ */
