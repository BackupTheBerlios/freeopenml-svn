/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef _ML_ID_H_
	#define _ML_ID_H_

	#ifdef __cplusplus
	extern "C" {
	#endif

  #include <OpenML/mlparam.h>
  #include <OpenML/mlmodules.h>
	#define MLopenid void *

#pragma pack(push, 1)
  struct ml_id {
			union 
				{
					uint64_t id;
					struct 
						{
							uint32_t device_internal;
							uint16_t device;
							uint16_t system;
						} internal_id;
				};
  };
#pragma pack(pop)

	extern struct mlID ML_localhost;

	#define ML_SYSTEM_LOCALHOST ((uint64_t) ML_localhost->id)

	#define ML_ID 									MLparam (ML_CLASS_ID, int64				,0)
	#define ML_SYSTEM_DEVICE_IDS		MLparam (ML_CLASS_ID, int64_array	,1)
	#define ML_PARENT_ID 						MLparam (ML_CLASS_ID, int64				,2)
	#define ML_DEVICE_JACK_IDS			MLparam (ML_CLASS_ID, int64_array	,3)
	#define ML_DEVICE_PATH_IDS			MLparam (ML_CLASS_ID, int64_array	,4)
	#define ML_DEVICE_XCODE_IDS			MLparam (ML_CLASS_ID, int64_array	,5)
	#define ML_PARAM_IDS						MLparam (ML_CLASS_ID, int64_array	,6)
	#define ML_OPEN_OPTIONS_IDS			MLparam (ML_CLASS_ID, int64_array	,7)
	#define ML_XCODE_SRC_PIPE_IDS 	MLparam (ML_CLASS_ID, int64_array	,8)
	#define ML_XCODE_DEST_PIPE_IDS  MLparam (ML_CLASS_ID, int64_array	,9)
	#define ML_JACK_ALIAS_IDS	    	MLparam (ML_CLASS_ID, int64_array	,10)
	#define ML_JACK_PATH_IDS	    	MLparam (ML_CLASS_ID, int64_array	,11)
	#define ML_PATH_SRC_JACK_IDS	 	MLparam (ML_CLASS_ID, int64_array	,12)
	#define ML_PATH_DST_JACK_IDS	 	MLparam (ML_CLASS_ID, int64_array	,13)
	
	#ifdef __cplusplus
	}
	#endif

#endif
