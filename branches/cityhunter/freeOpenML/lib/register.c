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
#include <dlfcn.h>
#include <stdio.h>
#include <dirent.h>

#warning protect localhost parsing with mutexes
struct mlID *localhost= NULL;
u_int16_t device_count;

//used for internal testing
struct mlID* last_opened=NULL;


#warning check if an identical struct mlDevice isnt already present
#warning populate capability tree when loading
#warning add environnement based plugin loading
#warning add caching mechanism ? need to test performance before

const char defaultpath[]="/usr/lib/mlplugins";

u_int32_t
mlInit (int argc, char** argv)
{
	char path[_POSIX_PATH_MAX]="\0";
	char buffer[50];
	const char* env;
	int i=0;
	DIR* plugindir;
	struct dirent* entry;

	for (i=0; i<argc; i++)
		{
			if (!strncmp("--help",argv[i],6*sizeof(char)))
				{
					printf(	"\n\n libOpenML parameters : \n "
									"$ML_PLUGINS_PATH : environnement variable to the plugin"
									"directory\n\n");
				}
		}
	
		
	env=getenv("ML_PLUGINS_PATH");
	if (env==NULL)
		env=defaultpath;
	fprintf(stderr,"%s\n",env);
	plugindir=opendir(env);
	if ( plugindir == NULL )
		{
			fprintf(stderr, "%s : %s\n",__FUNCTION__,strerror (errno));
			return errno;
		}
	do
		{
			entry= readdir (plugindir);
			if (entry != NULL && NULL != strstr(entry->d_name,".so"))
				{
					snprintf(path, _POSIX_PATH_MAX, "%s/%s",env,entry->d_name);
					mlPluginLoad(path,NULL);
				}
		}
	while (entry != NULL);
	return 0;
}

u_int32_t
mlExit (void)
{
}

u_int32_t
mlPluginLoad(char* PluginName, u_int64_t* id)
{
	void* handle=NULL;
	u_int32_t (*init)(int argc, char** argv);
	char *error;
	errno=0;

	handle=dlopen(PluginName,RTLD_NOW);
	if ( NULL == handle )
		{
			fprintf (stderr, "%s\n", dlerror());
			return 1;
		}
	init=dlsym(handle, "module_init");
	if ((error = dlerror()) != NULL)
		{
			fprintf (stderr, "%s\n", error);
			dlclose(handle);
			return 1;
		}

	if (init(0,NULL))
		{
			fprintf(stderr, "%s %s : %s\n",__FILE__,__FUNCTION__,strerror (errno));
			dlclose(handle);
			return 1;
		}

	if (NULL==last_opened)
		{
		dlclose(handle);
		return 1;
		}
	last_opened->handle=handle;
	if (id != NULL) *id=last_opened->id;
	return 0;
}

u_int32_t
mlDeviceRegister(struct mlID* physdev)
{
	struct mlID *current=localhost;
	u_int16_t i=1;
	errno=0;

	last_opened=NULL;
	physdev->next=NULL;
	if ( physdev->mlPvGetCapabilities == NULL ) errno=EBADF;
	if ( physdev->mlOpen							== NULL ) errno=EBADF;
	if ( physdev->mlClose							== NULL ) errno=EBADF;
	if ( physdev->mlGetControls				== NULL ) errno=EBADF;
	if ( physdev->mlSetControls				== NULL ) errno=EBADF;
	if ( physdev->mlGetReceiveWaitHandle			== NULL ) errno=EBADF;
	if ( physdev->mlBeginTransfer			== NULL ) errno=EBADF;
	if ( physdev->mlEndTransfer				== NULL ) errno=EBADF;
	if ( physdev->mlXcodeWork					== NULL )errno=EBADF;
	if ( errno ) return errno;
	if (localhost==NULL)
		{
			localhost   = physdev;
			physdev->id = MAKE_ID(ML_SYSTEM_LOCALHOST,MAKE_DEV_ID(1),0);
			last_opened = physdev;
			return 0;
		}

	if (current->mlPvGetCapabilities == physdev->mlPvGetCapabilities
		|| current->mlOpen == physdev->mlOpen
		|| current->mlClose == physdev->mlClose)
		{
			errno=EEXIST;
			return errno;
		}
	while ( current->next != NULL && current->next->id==i+1 )
		{
			current=current->next;
			if (current->mlPvGetCapabilities == physdev->mlPvGetCapabilities
				|| current->mlOpen == physdev->mlOpen
				|| current->mlClose == physdev->mlClose)
				{
					errno=EEXIST;
					return errno;
				}
			i++;
		}
	if ( current->next != NULL )
		{
			struct mlID *tmp=current->next;
			current->next = physdev;
			physdev->next=tmp;
		}
	else
		{
			current->next=physdev;
		}
	physdev->id=MAKE_ID(ML_SYSTEM_LOCALHOST,MAKE_DEV_ID(i+1),0);
	last_opened=physdev;
	device_count++;
	return 0;
}

u_int32_t
mlDeviceUnRegister(u_int32_t id)
	{
		struct mlID *current=localhost;
		struct mlID *previous=localhost;
		errno=0;

		if ( SYSTEM_ID(id) != ML_SYSTEM_LOCALHOST) return 1;
		if ( localhost->next==NULL) return 1;
		if (current->id == id )
			{
				localhost->next=current->next;
				dlclose (current->handle);
				return 0;
			}
		while (current->next !=NULL && current->id != id )
			{
				previous=current;
				current=current->next;
			}
		if (id != current->id) return 1;
		previous->next=current->next;
		dlclose (current->handle);
		device_count--;
		return 0;
	}
