/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES

#include "OpenML/OpenML.h"
#include <unistd.h>
#include <sys/signal.h>
#include <errno.h>
#include <stdlib.h>

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

void handler(int sig)
{
	exit(0);
}

int main (int argc, char ** argv)
{
	struct sigaction s;
	u_int64_t id=0;
	MLopenid openid;

	MLpv *cap=NULL;

	sigemptyset(&s.sa_mask);
	s.sa_handler=handler;
	if ( sigaction (SIGALRM,&s,NULL) <0 )
		{
			fprintf(stderr, "%s : %s\n","sigaction",strerror (errno));
			exit(1);
		}

	mlPluginLoad(success,&id);
	if (0 == id ) return 1;
	if (mlOpen(id,NULL,&openid)) return 1;
	//here begin the real test

	if (mlSendMessage(openid,message)) return 3;
	alarm(2);
	if (0==mlReceiveMessage(openid,NULL,&cap)) return 5;
	return 1;
}
