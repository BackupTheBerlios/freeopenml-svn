/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <OpenML/OpenML.h>


int RecursiveParseAndDisplay(u_int64_t id, u_int32_t level)
{
	MLpv* capabilities;
	MLpv* current;
	char buffer[80];
	int i=0;

	u_int16_t size;

	if ( mlGetCapabilities(id,&capabilities))
		{
			perror (" in get capabilities ");
			exit(1);
		}
	current=capabilities;
	while (current->param != ML_END)
		{
			size=80-2*level;
			if (mlPvToStringAlign(id, current ,buffer, &size,level))
				{
					perror (" in current To String ");
					exit(1);
				}
			printf("%s\n",buffer);
			if ( ML_PARAM_GET_CLASS(current->param) == ML_CLASS_ID )
				{
					if ( ML_PARAM_GET_TYPE(current->param) == ML_TYPE_INT64_ARRAY )
						{
							for (i=0; i < current->length; i++)
								{
									printf("\n");
									RecursiveParseAndDisplay(current->value.pInt64[i],level+1);
								}
						}
				}
			current++;
		}
	//printf("\n");
	return 0;
}

int main ( int argc, char ** argv)
{
	mlInit(argc,argv);
	return RecursiveParseAndDisplay(ML_SYSTEM_LOCALHOST,0);
}
