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


int32_t MLAPI
mlSelectPipe(MLopenid openid, u_int64_t id)
{
	struct mlID *current=(struct mlID *)openid;
	errno = 0;
	if ( (id & ID_DEVICE_INTERNAL_PIPE) > current->pipes_count )
		{
			errno=ENODEV;
			return errno;
		}
	current->current_pipe=(id & ID_DEVICE_INTERNAL_PIPE);
	return 0;
}
