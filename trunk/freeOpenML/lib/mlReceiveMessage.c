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
#include <string.h>


#warning find a way to generate status....

int32_t MLAPI
mlReceiveMessage( MLopenid openid, int16_t *status, MLpv** reply)
{
	struct mlID* id=(struct mlID*)openid;
	errno=0;
	int32_t length;

	mlPopMQueue(&(id->pipes[id->current_pipe].out), reply, &length,status);
	if (errno)
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
			return errno;
		}

	return errno;
}
