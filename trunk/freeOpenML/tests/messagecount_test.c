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
	exit(6);
}

int main (int argc, char ** argv)
{
	struct sigaction s;
	u_int64_t id=0;
	int16_t count=64;
	MLopenid openid;

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

	if (mlGetSendMessageCount(openid,&count)) return 2;
	if (count!=0) return 3;
	if (mlSendMessage(openid,message)) return 1;
	if (mlSendMessage(openid,message)) return 1;
	if (mlSendMessage(openid,message)) return 1;
	if (mlGetSendMessageCount(openid,&count)) return 2;
	if (count!=9) return 3;
	if (mlBeginTransfer(openid)) return 1;
	sleep(1);
	if (mlGetSendMessageCount(openid,&count)) return 2;
	if (count!=0) return 3;
	if (mlGetReceiveMessageCount(openid,&count)) return 4;
	if (count!=9) return 5;
	return 0;
}
