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
mlXcodeWork(MLopenid codec)
{
	struct mlID* current = (struct mlID*) codec;
	errno=0;
	current->mlXcodeWork(current);
	return errno;
}
