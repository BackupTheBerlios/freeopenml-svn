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
mlGetSendMessageCount(MLopenid id,  int16_t* count)
{
	struct mlID *current=(struct mlID *)id;
	int i;
	errno=0;
	*count=0;
	for (i=0; i<current->pipes_count; i++)
		{
			*count+=MessageCount(&(current->pipes[i].in));
		}
	if (*count<0)
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
		}
	return errno;
}


int32_t MLAPI
mlGetReceiveMessageCount(MLopenid id,  int16_t* count)
{
	struct mlID *current=(struct mlID *)id;
	int i;
	errno=0;
	*count=0;
	for (i=0; i<current->pipes_count; i++)
		{
			*count+=MessageCount (&(current->pipes[i].out));
		}
	if (*count<0)
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
		}
	return errno;
}
