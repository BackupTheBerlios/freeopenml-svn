/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/





#ifndef _ML_JACK_H
	#define _ML_JACK_H
	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>

	//--------------------------------------------------------------------------
	// mlJackparameters used when obtaining the capabilities of a jack
	// Some parameter-value pairs returned by mlJackGetCapabilities have
	// a pre-defined location in the list. Their indexes into the array
	// are specified in mlJackIndexes
	//
	// See also the subsystem-independent capabilities defined in mlparam.h
	//--------------------------------------------------------------------------

	#define ML_JACK_TYPE_INT32	    			ML_PARAM_NAME( ML_CLASS_JACK, ML_TYPE_INT32,0)
	#define ML_JACK_DIRECTION_INT32   		ML_PARAM_NAME( ML_CLASS_JACK, ML_TYPE_INT32,1)
	#define ML_JACK_COMPONENT_SIZE_INT32 	ML_PARAM_NAME( ML_CLASS_JACK, ML_TYPE_INT32,2)
	#define ML_JACK_FEATURES_BYTE_ARRAY 	ML_FEATURES
	#define ML_JACK_INTERNAL_ID		    		ML_PARAM_NAME( ML_CLASS_JACK, ML_TYPE_INT32,3)

	// ML_JACK_TYPE enumerated values
	#define ML_JACK_TYPE_COMPOSITE		1
	#define ML_JACK_TYPE_SVIDEO				2
	#define ML_JACK_TYPE_SDI					3
	#define ML_JACK_TYPE_DUALLINK			4
	#define ML_JACK_TYPE_SYNC					5
	#define ML_JACK_TYPE_GENLOCK			6 // added in 2.0
	#define ML_JACK_TYPE_GPI					7 // added in 2.0
	#define ML_JACK_TYPE_SERIAL				8 // added in 2.0
	#define ML_JACK_TYPE_ANALOG_AUDIO	9 // added in 2.0
	#define ML_JACK_TYPE_AES					10 // added in 2.0
	#define ML_JACK_TYPE_ADAT					11 // added in 2.0


	// ML_JACK_DIRECTION enumerated values
	#define ML_DIRECTION_IN		0
	#define ML_DIRECTION_OUT	1


	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_JACK_H */


