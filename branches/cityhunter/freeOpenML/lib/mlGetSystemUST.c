/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#include <OpenML/OpenML.h>
#include <time.h>
int32_t
mlGetSystemUST( u_int64_t sysId, int64_t* ust)
{
	struct timespec current_time;
	if (sysId != ML_SYSTEM_LOCALHOST ) return ENODEV;
	if (ust == NULL ) return EINVAL;
	clock_gettime(CLOCK_REALTIME, &current_time);
	if (errno) return errno;
	*ust=current_time.tv_sec*1000000000+current_time.tv_nsec;
	return 0;
}
