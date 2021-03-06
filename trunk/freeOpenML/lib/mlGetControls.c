/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top
* source dir of the
* package
************************************************************************/



#define __ML_MODULES
#include <OpenML/OpenML.h>
#include <unistd.h>
#include <stdlib.h>



int32_t MLAPI
mlGetControls( MLopenid openid, MLpv* controls)
{
	struct mlID* id=(struct mlID*)openid;
	errno=0;
	id->mlGetControls(id, controls);
	return errno;
}
