/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#include <OpenML/OpenML.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char** argv)
	{
		int16_t major;
		int16_t minor;
		if (mlGetVersion(&major,&minor)) return 1;
		if (major != 1) return 2;
		if (minor != 0) return 3;
		if ( 0 == mlGetVersion(NULL,&minor)) return 4;
		if ( 0 == mlGetVersion(&major,NULL)) return 5;
		return 0;
	}
