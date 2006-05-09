/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES

#include "OpenML/OpenML.h"
#include <unistd.h>

char plugin[][120]={
	"mlplugin-failed1-0.so",
	"mlplugin-failed2-0.so",
	"mlplugin-failed3-0.so",
	"mlplugin-failed4-0.so",
	"mlplugin-failed5-0.so",
	"mlplugin-failed6-0.so",
	"mlplugin-failed7-0.so",
	"mlplugin-failed8-0.so",
	"mlplugin-failed9-0.so",
	"mlforward-0.0.0.so",
	"mlforward-0.0.0.so",
	"mlforward-0.0.0.so",
	"mlforward-0.0.0.so",
};


int main (int argc, char** argv)
{
	u_int64_t id[4]={0,0,0,0};
	int i=0;

	for (i=0; i<9; i++)
		{
			if (0==mlPluginLoad(plugin[i],NULL)) //no error O_O
			  {
			    fprintf (stderr, "step %d\n", i);
			    return 1;
			  }
		}
	if (mlPluginLoad(plugin[9],&id[0])) //not ok O_O
		return 5;
	if (SYSTEM_ID(id[0]) != ML_SYSTEM_LOCALHOST )
		return 6;
	if (DEVICE_ID(id[0]) >> 32 != 1)
		return 7;

	for (i=0; i<3; i++)
		{
			if (0==mlPluginLoad(plugin[9],&id[i+1])) //no error O_O
			  {
			    fprintf (stderr, "step %d\n", i);
			    return 8;
			  }
		}
	for (i=0; i<2; i++)
		{
			if (mlPluginLoad(plugin[10+i],&id[i+1]))
			  {
			    fprintf (stderr, "step %d\n", i);
			    return 9;
			  }
			if (SYSTEM_ID(id[i+1]) != ML_SYSTEM_LOCALHOST )
			  {
			    fprintf (stderr, "step %d\n", i);
			    return 10;
			  }
			if (DEVICE_ID(id[i+1]) >> 32 != i+1 )
			  {
			    fprintf (stderr, "step %d\n", i);
			    return 11;
			  }
		}
	if (0 == mlDeviceUnRegister(3) ) return 12;
	if (0 != mlDeviceUnRegister(id[2]) ) return 13;

	if (mlPluginLoad(plugin[9],&id[2])) //not ok O_O
		return 14;
	if (SYSTEM_ID(id[2]) != ML_SYSTEM_LOCALHOST )
		return 15;
	if (DEVICE_ID(id[2]) >> 32 != 3 )
		return 16;

	return 0;
}
