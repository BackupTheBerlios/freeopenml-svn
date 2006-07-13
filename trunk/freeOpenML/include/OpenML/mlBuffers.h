/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/

#ifndef _ML_BUFFERS_H_
	#define _ML_BUFFERS_H_
        #include <limits.h>
	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <unistd.h>
	#include <semaphore.h>

	struct sbuffer {
		sem_t sem;
		uint8_t data;
		};

        struct MLbuffer_t {
                uint64_t id;
                char desc[PATH_MAX];
                off_t offset;
                size_t size;
                struct MLbuffer_t* next;
        };
	#ifdef __cplusplus
	}
	#endif

uint64_t mlRegisterBuffer(struct MLbuffer_t* bufferdesc);
uint64_t mlGetBufferDesc(struct MLbuffer_t* bufferdesc, uint64_t id);
#endif /* _ML_BUFFERS_H_ */
