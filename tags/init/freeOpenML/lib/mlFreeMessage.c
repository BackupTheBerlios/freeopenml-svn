/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#include <OpenML/OpenML.h>
#include <stdlib.h>

/**a cleaning function
 * @param capabilities : the message to free
 * @param all : free the message pointer too
 * @return 0
 */

int32_t MLAPI
mlFreeMessage(MLpv* capabilities,int all)
{
	int i=0;
	while (capabilities[i].param != ML_END)
		{
			switch (ML_PARAM_GET_TYPE(capabilities[i].param))
				{
				case ML_TYPE_BYTE_ARRAY :
					free(capabilities[i].value.pByte);
					break;
				case ML_TYPE_INT32_ARRAY :
					free(capabilities[i].value.pInt32);
					break;
				case ML_TYPE_INT64_ARRAY :
					free(capabilities[i].value.pInt64);
					break;
				case ML_TYPE_REAL32_ARRAY :
					free(capabilities[i].value.pReal32);
					break;
				case ML_TYPE_REAL64_ARRAY :
					free(capabilities[i].value.pReal64);
					break;
				case ML_TYPE_PV_ARRAY :
					free(capabilities[i].value.pPv);
					break;
				case ML_TYPE_MSG_ARRAY :
					free(capabilities[i].value.pMsg);
					break;
				}
			i++;
		}
	if (all)
		free(capabilities);
	return 0;
}
