/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES
#include <OpenML/OpenML.h>
#include <unistd.h>
#include <stdlib.h>

int32_t MLAPI mlGetVersion(int16_t *major, int16_t *minor)
	{
	errno=0;
	if (major == NULL || minor == NULL ) return EINVAL;
	*major=1;
	*minor=0;
	return 0;
	}
