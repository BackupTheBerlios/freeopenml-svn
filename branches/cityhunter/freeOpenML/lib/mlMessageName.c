/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <OpenML/OpenML.h>

const char* MLAPI
mlMessageName( int32_t status)
{
	switch (status)
		{
		case ML_MESSAGE_COMPLETE :
			return "ML_MESSAGE_COMPLETE";
		case ML_MESSAGE_ABORTED :
			return "ML_MESSAGE_ABORTED";
		case ML_MESSAGE_FAILED :
			return "ML_MESSAGE_FAILED";
		default :
			errno = EINVAL;
			return NULL;
		}
}
