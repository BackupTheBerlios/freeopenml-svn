/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/

#include <string.h>


int32_t MLAPI
mlPvXXXXFromString (int64_t objectid, const char* buffer, u_int32_t buffersize,
										MLpv* pv)
{
	char* value;
	errno=0;
	value=strchr(buffer,'=');
	if (value == NULL )
		{
			errno=EINVAL;
			return errno;
		}
	if ( find_param (buffer,pv))
		{
			errno=EINVAL;
			return errno;
		}
	if ( find_value (value+1,pv))
		{
			errno=EINVAL;
			return errno;
		}
	return errno;
}

int32_t
find_param(const char* buffer,MLpv* pv)
{
	struct mlparamtoname* current=params;
	int i=0;
	while (i < ML_PARAM_COUNT && !strncmp(current->name,buffer,current->length) )
		{
			current++;
		}
	if ( i == ML_PARAM_COUNT)
		return EINVAL
	pv->params=current->param;
	return 0;
}

int32_t
find_value(const char* buffer,MLpv* pv)
{
	int16_t min;

	if (ML_PARAM_GET_CLASS(pv->param) == ML_CLASS_ID
			&& ML_PARAM_GET_TYPE(pv->param) == ML_TYPE_INT64 )
		{
			snprintf (str, (*bufferSize)*sizeof(char),
														"=0x%llX",pv->value.int64);
			return errno;
		}


	switch (ML_PARAM_GET_TYPE(pv->param))
	{
	case ML_TYPE_NONE						:
		sscanf (str, "=???");
		return errno;
	case ML_TYPE_BYTE           :
		snprintf (str, "=%hhd",&pv->value.byte);
		return errno;
	case ML_TYPE_INT16          :
		snprintf (str, "=%hd",&pv->value.int16);
		return errno;
	case ML_TYPE_INT32          :
		snprintf (str, "=%d",&pv->value.int32);
		return errno;
	case ML_TYPE_INT64          :
		snprintf (str, "=%lld",&pv->value.int64);
		return errno;
	case ML_TYPE_REAL32         :
		snprintf (str, "=%f",&pv->value.real32);
		return errno;
	case ML_TYPE_REAL64         :
		snprintf (str, "=%F",&pv->value.real64);
		return errno;
	case ML_TYPE_BYTE_POINTER   :
		snprintf (str, "=%p",&pv->value.pByte);
		return errno;
	case ML_TYPE_INT16_POINTER  :
	case ML_TYPE_INT16_ARRAY :
		snprintf (str, "=%p",&pv->value.pInt16);
		return errno;
	case ML_TYPE_INT32_ARRAY :
	case ML_TYPE_INT32_POINTER  :
		snprintf (str, "=%p",&pv->value.pInt32);
		return errno;
	case ML_TYPE_INT64_ARRAY :
	case ML_TYPE_INT64_POINTER  :
		snprintf (str, "=%p",&pv->value.pInt64);
		return errno;
	case ML_TYPE_REAL32_ARRAY :
	case ML_TYPE_REAL32_POINTER :
		snprintf (str, "=%p",&pv->value.pReal32);
		return errno;
	case ML_TYPE_REAL64_ARRAY :
	case ML_TYPE_REAL64_POINTER :
		snprintf (str, "=%p",&pv->value.pReal64);
		return errno;
	case ML_TYPE_PV_ARRAY :
	case ML_TYPE_PV_POINTER     :
		snprintf (str, "=%p",&pv->value.pPv);
		return errno;
	case ML_TYPE_BYTE_ARRAY :
		snprintf (str,"=%s",&pv->value.pByte);
		return errno;
	case ML_TYPE_MSG_ARRAY :
		snprintf (str,"=%p",&pv->value.pMsg);
		return errno;
	default :
		return EINVAL;
	}
}
