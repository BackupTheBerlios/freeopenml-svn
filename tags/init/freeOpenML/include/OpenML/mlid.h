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


	#define MLopenid void *

	#define DEVICE_INTERNAL_ID_Shft 	0
	#define DEVICE_ID_Shft						32
	#define SYS_ID_Shft							(DEVICE_ID_Shft+16)

	///16 bits for system (65536 systems at a time), set by OMLib
	#define ID_SYSTEM_MASK ((u_int64_t)0xFFFF<<SYS_ID_Shft)
	///16 bits for device ID (65536 devices)set by OMLib
	#define ID_DEVICE_MASK ((u_int64_t)0xFFFF<<DEVICE_ID_Shft)
	///32 bits leaved to device drivers these bits are freely set by the driver to fit internal
	///requirement
	#define ID_DEVICE_INTERNAL_MASK (0xFFFFFFFF<<0)
	#define ID_DEVICE_INTERNAL_PIPE (0xFFFF<<0)


	#define SYSTEM_ID(id)			((id) & ID_SYSTEM_MASK)
	#define DEVICE_ID(id)			((id) & ID_DEVICE_MASK)
	#define MAKE_DEV_ID(dev)	(((u_int64_t)(dev)&0xFFFF)<<32)
	#define MAKE_SYS_ID(sys)	(((u_int64_t)(sys)&0xFFFF)<<48)
	#define MAKE_ID(sys,dev,id) (sys|dev|id)



	#define ML_SYSTEM_LOCALHOST MAKE_ID(MAKE_SYS_ID(1),MAKE_DEV_ID(0),0)

	#define ML_ID 									ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64				,0)
	#define ML_SYSTEM_DEVICE_IDS		ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,1)
	#define ML_PARENT_ID 						ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64				,2)
	#define ML_DEVICE_JACK_IDS			ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,3)
	#define ML_DEVICE_PATH_IDS			ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,4)
	#define ML_DEVICE_XCODE_IDS			ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,5)
	#define ML_PARAM_IDS						ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,6)
	#define ML_OPEN_OPTIONS_IDS			ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,7)
	#define ML_XCODE_SRC_PIPE_IDS 	ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,8)
	#define ML_XCODE_DEST_PIPE_IDS  ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,9)
	#define ML_JACK_ALIAS_IDS	    	ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,10)
	#define ML_JACK_PATH_IDS	    	ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,11)
	#define ML_PATH_SRC_JACK_IDS	 	ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,12)
	#define ML_PATH_DST_JACK_IDS	 	ML_PARAM_NAME(ML_CLASS_ID,ML_TYPE_INT64_ARRAY	,13)
	
	#ifdef __cplusplus
	}
	#endif

#endif
