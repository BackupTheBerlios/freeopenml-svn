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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int32_t MLAPI mlOpen( u_int64_t id, MLpv* options, MLopenid* openid)
{
	struct ml_id* current = ML_localhost;
	struct ml_id** newid=(struct ml_id**) openid;
	errno=0;
	int i;

	if (id == ML_SYSTEM_LOCALHOST)
		{
			return EINVAL;
		}


	*newid = malloc(sizeof(struct mlID));
	if( *newid == NULL )
		goto err;

	while( current != NULL  &&
               id != current->id )
		current=current->next;
	if( current == NULL )
		{
			errno=ENODEV;
			goto err;
		}

	**newid = *current; //make a copy
	
	(*newid)->pipes = malloc(sizeof(struct mlPipe)*(*newid)->pipes_count);
	if( (*newid)->pipes == NULL )
		goto err;
	
	for (i=0; i<(*newid)->pipes_count; i++)
		{
			if(mlInitMQueue(&((*newid)->pipes[i].in)))
				goto err;
			if(mlInitMQueue(&((*newid)->pipes[i].out)))
				goto err;
		}



	(*newid)->mlOpen(*newid,options);
	if(errno) goto err;
	return 0;

	err:
		if( (*newid)->pipes != NULL ) free( (*newid)->pipes );
		if(*newid != NULL) free(*newid);
		fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
		return errno;
}
