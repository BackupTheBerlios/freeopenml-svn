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


extern MLpv localhost_cap[];

int main (int argc, char** argv)
{
	u_int64_t id=0;
	MLpv* capabilities;
	MLpv* current;
	int i;
	if (mlPluginLoad("mlforward-0.0.0.so", &id)) return 1;

	if ( 0 == mlGetCapabilities( 3, &capabilities) ) return 2;
	if ( 0 != mlGetCapabilities(ML_SYSTEM_LOCALHOST, &capabilities) ) return 3;
	if ( localhost_cap != capabilities ) return 4;
	if ( 0 != mlGetCapabilities(id, &capabilities) ) return 5;
	current=capabilities;
	i=0;
	while (current->param != ML_END)
		{
			if (i==0 && current->param != ML_ID)
				return 6;
			i++;
			current++;
		}
	return 0;
}
