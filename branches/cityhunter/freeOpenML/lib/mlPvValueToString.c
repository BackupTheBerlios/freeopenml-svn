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

	if (ML_PARAM_GET_CLASS(pv->param) == ML_CLASS_ID
			&& ML_PARAM_GET_TYPE(pv->param) == ML_TYPE_INT64 )
		{
			*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
			                       "=0x%llX",pv->value.int64);
			return errno;
		}


	switch (ML_PARAM_GET_TYPE(pv->param))
	{
	case ML_TYPE_NONE          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=???");
		return errno;
	case ML_TYPE_BYTE           :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%hhd",pv->value.byte);
		return errno;
	case ML_TYPE_INT16          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%hd",pv->value.int16);
		return errno;
	case ML_TYPE_INT32          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%d",pv->value.int32);
		return errno;
	case ML_TYPE_INT64          :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%lld",pv->value.int64);
		return errno;
	case ML_TYPE_REAL32         :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%f",pv->value.real32);
		return errno;
	case ML_TYPE_REAL64         :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%F",pv->value.real64);
		return errno;
	case ML_TYPE_BYTE_POINTER   :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pByte);
		return errno;
	case ML_TYPE_INT16_POINTER  :
	case ML_TYPE_INT16_ARRAY :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pInt16);
		return errno;
	case ML_TYPE_INT32_ARRAY :
	case ML_TYPE_INT32_POINTER  :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pInt32);
		return errno;
	case ML_TYPE_INT64_ARRAY :
	case ML_TYPE_INT64_POINTER  :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pInt64);
		return errno;
	case ML_TYPE_REAL32_ARRAY :
	case ML_TYPE_REAL32_POINTER :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pReal32);
		return errno;
	case ML_TYPE_REAL64_ARRAY :
	case ML_TYPE_REAL64_POINTER :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pReal64);
		return errno;
	case ML_TYPE_PV_ARRAY :
	case ML_TYPE_PV_POINTER     :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pPv);
		return errno;
	case ML_TYPE_BYTE_ARRAY :
		min =*bufferSize < (pv->length+1) ?	(*bufferSize)*sizeof(char) :
		       (pv->length+1)* sizeof(char);
		*bufferSize-=snprintf (str,min,"=%s",pv->value.pByte);
		return errno;
	case ML_TYPE_MSG_ARRAY :
		*bufferSize-=snprintf (str, (*bufferSize)*sizeof(char),
		                       "=%p",pv->value.pMsg);
		return errno;
	default :
		return EINVAL;
	}
}
