/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES

#include "OpenML/OpenML.h"
#include <unistd.h>

char success[]="mlforward-0.0.0.so";

MLpv message []={
	{
		.param=ML_TYPE_INT64,
		.value.int64=11,
	},
	{
		.param=ML_TYPE_INT64,
		.value.int64=28,
	},
	{
		.param=ML_END,
	},
};

int main (int argc, char ** argv)
{
	u_int64_t id=0;
	int i=0;
	MLopenid openid;

	MLpv *cap=NULL;

	mlPluginLoad(success,&id);
	if (0 == id ) return 1;
	if (mlOpen(id,NULL,&openid)) return 2;
	//here begin the real test
	#warning add a way to test the activation of a stream
	if (mlSendMessage(openid,message)) return 3;
	if (mlBeginTransfer(openid)) return 4;
	if (mlReceiveMessage(openid,NULL,&cap)) return 5;
	if (mlFreeCapabilities(cap)) return 6;
	for (i=0; i<sizeof(message)/sizeof(MLpv); i++)
		{
		if ( message[i].param != cap[i].param ) return 7+2*i;
		if ( message[i].value.int64 != cap[i].value.int64 ) return 7+2*i+1;
		}
	return 0;
}
