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

extern u_int32_t device_count;

char name[]="localhost";

MLpv localhost_cap [4];

int32_t MLAPI
mlPvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
						MLpv** capabilities)
	{
	struct mlID* current = localhost_tree;
	int i=0;
	errno=0;
	struct ml_id sid;
	sid.id=  id;
	
	if (id == ML_SYSTEM_LOCALHOST)
		{
			if (paramid == 0)
				{
					localhost_cap[0].param = ML_ID;
					localhost_cap[0].value.int64=ML_SYSTEM_LOCALHOST;
					localhost_cap[1].param = ML_NAME;
					localhost_cap[1].value.pByte=(uint8_t*)name;
					localhost_cap[2].length = (sizeof(name) /
                                                                   sizeof(char));
					localhost_cap[2].value.pInt64=malloc(sizeof(u_int64_t)*device_count);
					localhost_cap[2].param=ML_SYSTEM_DEVICE_IDS;
					localhost_cap[3].value.pInt64=NULL;
					localhost_cap[3].param=ML_END;
					if (localhost_cap[2].value.pInt64 == NULL)
						return errno;
					while (current != NULL)
						{
							localhost_cap[2].value.pInt64[i]=current->id.id;
							current=current->next;
							localhost_cap[2].length++;
							i++;
						}
					*capabilities=localhost_cap;
					return 0;
				}
			else
				{
					return EINVAL;
				}
		}
	while ( current != NULL  && 
			    sid.internal_id.system != current->id.internal_id.system &&
				 	sid.internal_id.device != current->id.internal_id.device )
		current=current->next;
	if ( current == NULL )
		{
			errno = ENODEV;
			return ENODEV;
		}
	return current->mlPvGetCapabilities(id,paramid,capabilities);
	}
