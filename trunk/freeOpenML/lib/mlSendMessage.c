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
mlSendMessage(MLopenid id, MLpv* buffers)
{
	struct mlID *current=(struct mlID *)id;
	errno=0;
	mlCopyPushMQueue( &(current->pipes[current->current_pipe].in),buffers,0);
	if (errno)
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
		}
	return errno;
}
