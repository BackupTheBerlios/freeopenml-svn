/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES

#include "OpenML/OpenML.h"
#include <unistd.h>

char success[]="mlforward.so";

int main (int argc, char** argv)
{
	MLopenid openid;
	u_int64_t id;
	if ( mlPluginLoad(success,&id) ) //not ok O_O
				return 1;
	if ( 0== mlOpen(4,NULL,&openid) ) return 2;
	if ( 0== mlOpen (ML_SYSTEM_LOCALHOST,NULL,&openid) ) return 3;
	if ( mlOpen(id,NULL,&openid) ) return 4;
	if ( mlClose(openid) ) return 8;
	return 0;
}
