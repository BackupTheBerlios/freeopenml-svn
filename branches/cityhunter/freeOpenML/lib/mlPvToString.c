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
#include <string.h>

inline void
addpading(int level, char* str, int16_t* bufferSize)
{
	if (*bufferSize>2*level+1)
		{
			memset ((void*)str,' ', 2*level*sizeof(char));
			str[2*level+1]='\0';
			*bufferSize-=2*level;
		}
	else
		{
			memset ((void*)str,' ', (*bufferSize-1)*sizeof(char));
			str[*bufferSize-1]='\0';
			*bufferSize=0;
		}
}

int32_t MLAPI
mlPvToStringAlign(u_int64_t objectId, MLpv* pv, char* str, int16_t* bufferSize,
						int level)
{
	int16_t originalSize=*bufferSize;

	addpading(level,str,bufferSize);
	if (mlPvParamToString(objectId, pv, str+(originalSize-*bufferSize),
												bufferSize))
		return errno;
	if (mlPvValueToString(objectId, pv, str+(originalSize-*bufferSize),
												bufferSize))
		return errno;
	if (ML_PARAM_GET_TYPE(pv->param)>ML_TYPE_BYTE_ARRAY
			&& ML_PARAM_GET_TYPE(pv->param)<ML_TYPE_MSG_ARRAY)
		{
			addpading(1,str+(originalSize-*bufferSize),bufferSize);
			*bufferSize -= snprintf (str+(originalSize-*bufferSize),
															*bufferSize*sizeof(char),
															"[length=%d]",
															pv->length);
			if (errno) return errno;
		}
	if (ML_PARAM_GET_TYPE(pv->param)>ML_TYPE_BYTE_POINTER
			&& ML_PARAM_GET_TYPE(pv->param)<ML_TYPE_PV_POINTER)
		{
			addpading(1,str+(originalSize-*bufferSize),bufferSize);
			*bufferSize -= snprintf (str+(originalSize-*bufferSize),
															*bufferSize*sizeof(char),
															"[length=%d]",
															pv->length);
			if (errno) return errno;
		}
	return errno;
}
