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

	#define ML_JACK_TYPE_INT32	    			MLparam (ML_CLASS_JACK, int32, 0)
	#define ML_JACK_DIRECTION_INT32   		MLparam (ML_CLASS_JACK, int32, 1)
	#define ML_JACK_COMPONENT_SIZE_INT32 	MLparam (ML_CLASS_JACK, int32, 2)
	#define ML_JACK_FEATURES_BYTE_ARRAY 	ML_FEATURES
	#define ML_JACK_INTERNAL_ID		    		MLparam (ML_CLASS_JACK, int32, 3)

	// ML_JACK_TYPE enumerated values
	enum ml_jack_type
		{
			ML_JACK_TYPE_COMPOSITE,
			ML_JACK_TYPE_SVIDEO,
			ML_JACK_TYPE_SDI,
			ML_JACK_TYPE_DUALLINK,
			ML_JACK_TYPE_SYNC,
			ML_JACK_TYPE_GENLOCK, // added in 2.0
			ML_JACK_TYPE_GPI,     // added in 2.0
			ML_JACK_TYPE_SERIAL,  // added in 2.0
			ML_JACK_TYPE_ANALOG_AUDIO, // added in 2.0
			ML_JACK_TYPE_AES,     // added in 2.0
			ML_JACK_TYPE_ADAT,    // added in 2.0
		};


	// ML_JACK_DIRECTION enumerated values
	enum ml_direction
		{
			ML_DIRECTION_IN,
			ML_DIRECTION_OUT,
		};


	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_JACK_H */


