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

MLpv localhost_cap []={
		{	.param=ML_ID,
			.value.int64=ML_SYSTEM_LOCALHOST,},
		{	.param=ML_NAME,
			.value.pByte=name,
			.length=(sizeof(name)/sizeof(char)),},
		{	.param=ML_SYSTEM_DEVICE_IDS,
			.value.pInt64=NULL,	},
		{	.param=ML_END,		},
	};

int32_t MLAPI
mlPvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
						MLpv** capabilities)
	{
	struct mlID* current = localhost;
	int i=0;
	errno=0;
	if (id == ML_SYSTEM_LOCALHOST)
		{
			if (paramid == 0)
				{
					localhost_cap[2].value.pInt64=malloc(sizeof(u_int64_t)*device_count);
					if (localhost_cap[2].value.pInt64 == NULL)
						return errno;
					while (current != NULL)
						{
							localhost_cap[2].value.pInt64[i]=current->id;
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
	while ( current != NULL  
					&& (SYSTEM_ID(id) | DEVICE_ID(id)) != current->id )
		current=current->next;
	if ( current == NULL )
		{
			errno = ENODEV;
			return ENODEV;
		}
	return current->mlPvGetCapabilities(id,paramid,capabilities);
	}
