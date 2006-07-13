/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef _ML_PATH_H
	#define _ML_PATH_H

	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>

	//--------------------------------------------------------------------------
	// mlPath parameters used when obtaining the capabilities of a path.
	// Some parameter-value pairs returned by mlPathGetCapabilities have
	// a pre-defined location in the list. Their indexes into the array
	// are specified in mlPathIndexes
	//
	// See also the subsystem-independent capabilities defined in mlparam.h
	//--------------------------------------------------------------------------

	#define ML_PATH_TYPE_INT32     							MLparam(ML_CLASS_PATH, int32, 0)
	#define ML_PATH_SRC_JACK_ID    							MLparam(ML_CLASS_PATH, int64, 1)
	#define ML_PATH_DST_JACK_ID    							MLparam(ML_CLASS_PATH, int64, 2)
	#define MLI_PATH_INTERNAL_ID   							MLparam(ML_CLASS_PATH, int32, 3)
	#define ML_PATH_PIXEL_LINE_ALIGNMENT_INT32 	MLparam(ML_CLASS_PATH, int32, 4)
	#define ML_PATH_BUFFER_ALIGNMENT_INT32 			MLparam(ML_CLASS_PATH, int32, 5)
	#define ML_PATH_FEATURES_BYTE_ARRAY 				ML_FEATURES


	// ML_PATH_TYPE enumerated values
	#define ML_PATH_TYPE_DEV_TO_MEM	0
	#define ML_PATH_TYPE_MEM_TO_DEV	1
	#define ML_PATH_TYPE_DEV_TO_DEV	2



	//--------------------------------------------------------------------------
	// video path parameters
	//--------------------------------------------------------------------------
	// Video jack parameters
	#define ML_VIDEO_TIMING_INT32					MLparam( video, int32,  1)
	#define ML_VIDEO_COLORSPACE_INT32  		ML_IMAGE_COLORSPACE_INT32 //redondant
	#define ML_VIDEO_PRECISION_INT32   		MLparam( video, int32,  3)
	#define ML_VIDEO_SIGNAL_PRESENT_INT32 MLparam( video, int32,  4)
	#define ML_VIDEO_GENLOCK_SOURCE_ID 		MLparam( video, int64,  5)

	// Video raster parameters
	#define ML_VIDEO_START_X_INT32 	  		MLparam( video, int32, 6) //horizontal blanking
	#define ML_VIDEO_START_Y_F1_INT32 		MLparam( video, int32, 7) //vertical blanking
		                                                              //field 1
	#define ML_VIDEO_START_Y_F2_INT32 		MLparam( video, int32, 8) //vertical blanking
		                                                              //field 2
	#define ML_VIDEO_WIDTH_INT32     			ML_IMAGE_WIDTH_INT32   //this has nothing
		                                  	//related with the video but with the image
	#define ML_VIDEO_HEIGHT_F1_INT32  		ML_IMAGE_HEIGHT_1_INT32  //this has nothing
		                                    //related with the video but with the image
	#define ML_VIDEO_HEIGHT_F2_INT32  		ML_IMAGE_HEIGHT_1_INT32  //this has nothing
		                                    //related with the video but with the image
	#define ML_VIDEO_OUTPUT_REPEAT_INT32 	MLparam( video, int32, 12)
	#define ML_VIDEO_SAMPLING_INT32 			ML_IMAGE_SAMPLING_INT32 //redondant


	// ML_VIDEO_TIMING_INT32 enumerations

	/* The following two params are meaningful only when
	* querying the sensed timing on a video device
	*/
	enum ml_timings
		{
			ML_TIMING_NONE,    /* no signal is present */
			ML_TIMING_UNKNOWN, /* the timing of the signal can not be determined */
			ML_TIMING_525,	/* NTSC */
			ML_TIMING_625, /* PAL */

			/*
			 * SMPTE 274M formats: 1125 total lines, 1920x1080 active picture,
			 * square pixels, 16:9 picture aspect ratio.
			 * 'p' suffix means progressive scanning,
			 * 'i' suffix means 2:1 interlaced,
			 * 'PsF' suffix means progressive split field.
			 */
			ML_TIMING_1125_1920x1080_60p,			 /* 148.5 MHz */
			ML_TIMING_1125_1920x1080_5994p,		 /* 148.5/1.001 MHz */
			ML_TIMING_1125_1920x1080_50p,			 /* 148.5 MHz */
			ML_TIMING_1125_1920x1080_60i,			 /* 74.25 MHz */
			ML_TIMING_1125_1920x1080_5994i,		 /* 74.25/1.001 MHz */
			ML_TIMING_1125_1920x1080_50i,			 /* 74.25 MHz */
			ML_TIMING_1125_1920x1080_30p,			 /* 74.25 MHz */
			ML_TIMING_1125_1920x1080_2997p,		 /* 74.25/1.001 MHz */
			ML_TIMING_1125_1920x1080_25p,			 /* 74.25 MHz */
			ML_TIMING_1125_1920x1080_24p,			 /* 74.25 MHz */
			ML_TIMING_1125_1920x1080_2398p,		 /* 74.25/1.001 MHz */
			ML_TIMING_1125_1920x1080_24PsF,		 /* Sony proposed 274M 74.25 MHz */
			ML_TIMING_1125_1920x1080_2398PsF,	 /* Sony proposed 274M 74.25/1.001 MHz */
			ML_TIMING_1125_1920x1080_30PsF,		 /* Sony proposed 274M 74.25 MHz */
			ML_TIMING_1125_1920x1080_2997PsF,	 /* Sony proposed 274M 74.25/1.001 MHz */
			ML_TIMING_1125_1920x1080_25PsF,		 /* Sony proposed 274M 74.25 MHz */
			/*
			 * other "high-definition" formats
			 */
			ML_TIMING_1250_1920x1080_50p,			 /* SMPTE 295M 148.5 MHz */
			ML_TIMING_1250_1920x1080_50i,    	 /* SMPTE 295M 74.25 MHz */
			ML_TIMING_1125_1920x1035_60i,    	 /* SMPTE 260M/240M 74.25 MHz */
			ML_TIMING_1125_1920x1035_5994i,  	 /* SMPTE 260M/240M 74.25/1.001 MHz*/
			ML_TIMING_750_1280x720_60p,      	 /* SMPTE 296M 74.25 MHz */
			ML_TIMING_750_1280x720_5994p,    	 /* SMPTE 296M 74.25/1.001 MHz */
			ML_TIMING_525_720x483_5994p,      	 /* SMPTE 293M 27.0 MHz */
		};

	// ML_VIDEO_OUTPUT_REPEAT_INT32 enumerations
	enum ml_repeat
		{
			ML_VIDEO_REPEAT_NONE,
			ML_VIDEO_REPEAT_FIELD,
			ML_VIDEO_REPEAT_FRAME,
		};


	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_PATH_H */


