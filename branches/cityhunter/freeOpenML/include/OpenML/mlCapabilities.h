/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#ifndef _ML_CAPAB_H_
	#define _ML_CAPAB_H_
	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>
	#define ML_NAME								ML_PARAM_NAME(ML_CLASS_CAPABILITIES	,ML_TYPE_BYTE_ARRAY		,1)
	#define ML_DEVICE_VERSION			ML_PARAM_NAME(ML_CLASS_CAPABILITIES	,ML_TYPE_INT32					,4)
	#define ML_DEVICE_INDEX	 			ML_PARAM_NAME(ML_CLASS_CAPABILITIES	,ML_TYPE_BYTE_ARRAY		,5)
	#define ML_DEVICE_LOCATION		ML_PARAM_NAME(ML_CLASS_CAPABILITIES	,ML_TYPE_BYTE_ARRAY		,6)
	#define ML_PRESET							ML_PARAM_NAME(ML_CLASS_CAPABILITIES	,ML_TYPE_PV_ARRAY			,12)
	#define ML_FEATURES						ML_PARAM_NAME(ML_CLASS_CAPABILITIES	,ML_TYPE_BYTE_ARRAY		,13)

	#define ML_PATH_COMPONENT_ALIGNEMENT	ML_PATH_PIXEL_LINE_ALIGNMENT_INT32 //not sure

	#define ML_PARAM_TYPE					ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT32					,14)
	#define ML_PARAM_ACCESS				ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT32					,15)
	#define ML_PARAM_DEFAULT			ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT64					,16)
	#define ML_PARAM_MINS					ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT64					,17)
	#define ML_PARAM_MAXS					ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT64					,18)
	#define ML_PARAM_INCREMENT		ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT64					,19)
	#define ML_PARAM_ENUM_VALUES	ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_INT64					,20)
	#define ML_PARAM_ENUM_NAMES		ML_PARAM_NAME(ML_CLASS_CAPABILITIES,ML_TYPE_BYTE_ARRAY		,21)


	//ML_PARAM_ACCESS
	#define ML_ACCESS_READ							1<<0
	#define ML_ACCESS_WRITE							1<<1
	#define ML_ACCESS_PASS_THROUGH			1<<2
	#define ML_ACCESS_OPEN_OPTION				1<<3
	#define ML_ACCESS_IMMEDIATE					1<<4
	#define ML_ACCESS_QUEUED						1<<5
	#define ML_ACCESS_SEND_BUFFER				1<<6
	#define ML_ACCESS_DURING_TRANSFERT	1<<7
	#define ML_ACCESS_CONF 							1<<8		//configuration parameter, modify the device behaviour, input/output configuration....

	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_PARAM_H_ */
