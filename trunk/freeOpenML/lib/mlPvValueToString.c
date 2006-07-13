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

int32_t MLAPI
mlPvValueToString(u_int64_t objectId, MLpv* pv, char* str, int16_t* bufferSize)
{
	int16_t min;

	if (pv->params.CLASS == ML_CLASS_ID
			&& pv->params.type == int64 )
		{
			*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
			                       "=0x%llX",pv->value.int64);
			return errno;
		}


	switch (pv->params.type)
	{
	case none          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=???");
		return errno;
	case byte           :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%hhd",pv->value.byte);
		return errno;
	case int16          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%hd",pv->value.int16);
		return errno;
	case int32          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%d",pv->value.int32);
		return errno;
	case int64          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%lld",pv->value.int64);
		return errno;
	case real32         :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%f",pv->value.real32);
		return errno;
	case real64         :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%F",pv->value.real64);
		return errno;
	case int16_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pInt16);
		return errno;
	case int32_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pInt32);
		return errno;
	case int64_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pInt64);
		return errno;
	case real32_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pReal32);
		return errno;
	case real64_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pReal64);
		return errno;
	case pv_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pPv);
		return errno;
	case byte_array :
		min =*bufferSize < (pv->length+1) ?	(*bufferSize)*sizeof(char) :
		       (pv->length+1)* sizeof(char);
		*bufferSize-=snprintf (str,min,"=%s",pv->value.pByte);
		return errno;
	case msg_array :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pMsg);
		return errno;
	default :
		return EINVAL;
	}
}
