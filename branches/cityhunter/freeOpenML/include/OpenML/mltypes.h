/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




/**
 * modifications for using standard C99 types : these types are defined for
 * compatibility, they will never be used inside the code
 */

/* note: do not change the following define name */
#ifndef __ML_TYPES_H_
	#define __ML_TYPES_H_


	#ifdef __cplusplus
		extern "C" {
	#endif

	#include <sys/types.h>
	#include <float.h>

	#if defined(WIN32) || defined(WIN64)
		#define _WIN32_WINNT	0x0400
		#include <Windows.h> // Needed for HANDLE definition
	#endif

	#if defined(_WIN64)
		#include <basetsd.h>
	#endif /* _WIN64 */

	/* platform feature selection */
	#if defined(WIN32)
		#define ML_OS_NT	1
		#define ML_OS_NT32	1
		#define ML_ARCH_IA32	1
	#endif

	#if  defined(WIN64)
		#define ML_OS_NT	1
		#define ML_OS_NT64	1
		#define ML_ARCH_IA64	1
	#endif

	#if defined(__sgi)
		#define ML_OS_IRIX	1
		#define ML_OS_UNIX	1
		#define ML_ARCH_MIPS	1
	#endif

	#if defined(linux)
		#define ML_OS_LINUX	1
		#define ML_OS_UNIX	1

		#if defined(__i386)
		#define ML_ARCH_IA32	1
		#endif
	#endif

	/* Basic types */
	typedef int8_t		MLbyte;
	typedef int32_t		MLint32;

	#ifdef ML_OS_UNIX
		typedef int64_t			MLint64;
	#else // ML_OS_NT
		#ifdef ML_OS_NT32
			typedef __int64         MLint64;
		#else // ML_OS_NT64
			typedef LONG64          MLint64;
		#endif // ML_OS_NT
	#endif // ML_OS_LINUX


	typedef float			MLreal32;
	typedef double			MLreal64;


	/* MLstatus is already defined in some legacy IRIX libraries */
	#if (!defined(_VL_H_)) && (!defined(__INC_ML_GENERAL_H__))
	typedef int32_t MLstatus;
	#endif

	/* Waitable - handle on NT, file descriptor on Irix/Linux */
	#ifdef	ML_OS_NT
	typedef HANDLE MLwaitable;
	#else  /* Un*x */
	typedef int32_t MLwaitable;
	#endif

	/* Calling discipline exposed in function prototypes on NT */
	#ifdef	ML_OS_NT
		#define MLAPI __stdcall
	#else  /* Un*x */
		#define MLAPI
	#endif

	#ifdef __cplusplus
		}
	#endif

#endif /* __ML_TYPES_H_ */
