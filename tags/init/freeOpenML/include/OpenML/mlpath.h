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

	#define ML_PATH_TYPE_INT32     							ML_PARAM_NAME( ML_CLASS_PATH, ML_TYPE_INT32,				0)
	#define ML_PATH_SRC_JACK_ID    							ML_PARAM_NAME( ML_CLASS_PATH, ML_TYPE_INT64,				1)
	#define ML_PATH_DST_JACK_ID    							ML_PARAM_NAME( ML_CLASS_PATH, ML_TYPE_INT64,				2)
	#define MLI_PATH_INTERNAL_ID   							ML_PARAM_NAME( ML_CLASS_PATH, ML_TYPE_INT32,				3)
	#define ML_PATH_PIXEL_LINE_ALIGNMENT_INT32 	ML_PARAM_NAME( ML_CLASS_PATH, ML_TYPE_INT32, 				4)
	#define ML_PATH_BUFFER_ALIGNMENT_INT32 			ML_PARAM_NAME( ML_CLASS_PATH, ML_TYPE_INT32,  			5)
	#define ML_PATH_FEATURES_BYTE_ARRAY 				ML_FEATURES


	// ML_PATH_TYPE enumerated values
	#define ML_PATH_TYPE_DEV_TO_MEM	0
	#define ML_PATH_TYPE_MEM_TO_DEV	1
	#define ML_PATH_TYPE_DEV_TO_DEV	2



	//--------------------------------------------------------------------------
	// video path parameters
	//--------------------------------------------------------------------------
	// Video jack parameters
	#define ML_VIDEO_TIMING_INT32					ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32,  1)
	#define ML_VIDEO_COLORSPACE_INT32  		ML_IMAGE_COLORSPACE_INT32 //redondant
	#define ML_VIDEO_PRECISION_INT32   		ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32,  3)
	#define ML_VIDEO_SIGNAL_PRESENT_INT32 ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32,  4)
	#define ML_VIDEO_GENLOCK_SOURCE_ID 		ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT64,  5)

	// Video raster parameters
	#define ML_VIDEO_START_X_INT32 	  		ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32, 6) //horizontal blanking
	#define ML_VIDEO_START_Y_F1_INT32 		ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32, 7) //vertical blanking Field 1
	#define ML_VIDEO_START_Y_F2_INT32 		ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32, 8) //vertical blanking Field 2
	#define ML_VIDEO_WIDTH_INT32     			ML_IMAGE_WIDTH_INT32   //this has nothing related with the video but with the image
	#define ML_VIDEO_HEIGHT_F1_INT32  		ML_IMAGE_HEIGHT_1_INT32  //this has nothing related with the video but with the image
	#define ML_VIDEO_HEIGHT_F2_INT32  		ML_IMAGE_HEIGHT_1_INT32  //this has nothing related with the video but with the image
	#define ML_VIDEO_OUTPUT_REPEAT_INT32 	ML_PARAM_NAME( ML_CLASS_VIDEO, ML_TYPE_INT32, 12)
	#define ML_VIDEO_SAMPLING_INT32 			ML_IMAGE_SAMPLING_INT32 //redondant


	// ML_VIDEO_TIMING_INT32 enumerations

	/* The following two params are meaningful only when
	* querying the sensed timing on a video device
	*/
	#define ML_TIMING_NONE	0    /* no signal is present */
	#define ML_TIMING_UNKNOWN 1 /* the timing of the signal can not be determined */
	#define ML_TIMING_525	2 /* NTSC */
	#define ML_TIMING_625	3 /* PAL */
	/*
	* SMPTE 274M formats: 1125 total lines, 1920x1080 active picture,
	* square pixels, 16:9 picture aspect ratio.
	* 'p' suffix means progressive scanning,
	* 'i' suffix means 2:1 interlaced,
	* 'PsF' suffix means progressive split field.
	*/
	#define ML_TIMING_1125_1920x1080_60p			4  /* 148.5 MHz */
	#define ML_TIMING_1125_1920x1080_5994p		5  /* 148.5/1.001 MHz */
	#define ML_TIMING_1125_1920x1080_50p			6  /* 148.5 MHz */
	#define ML_TIMING_1125_1920x1080_60i			7  /* 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_5994i		8  /* 74.25/1.001 MHz */
	#define ML_TIMING_1125_1920x1080_50i			9  /* 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_30p			10 /* 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_2997p		11 /* 74.25/1.001 MHz */
	#define ML_TIMING_1125_1920x1080_25p			12 /* 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_24p			14 /* 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_2398p		15 /* 74.25/1.001 MHz */
	#define ML_TIMING_1125_1920x1080_24PsF		16 /* Sony proposed 274M 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_2398PsF	17 /* Sony proposed 274M 74.25/1.001 MHz */
	#define ML_TIMING_1125_1920x1080_30PsF		18 /* Sony proposed 274M 74.25 MHz */
	#define ML_TIMING_1125_1920x1080_2997PsF	19 /* Sony proposed 274M 74.25/1.001 MHz */
	#define ML_TIMING_1125_1920x1080_25PsF		20 /* Sony proposed 274M 74.25 MHz */
	/*
	* other "high-definition" formats
	*/
	#define ML_TIMING_1250_1920x1080_50p			21 /* SMPTE 295M 148.5 MHz */
	#define ML_TIMING_1250_1920x1080_50i    	22 /* SMPTE 295M 74.25 MHz */
	#define ML_TIMING_1125_1920x1035_60i    	23 /* SMPTE 260M/240M 74.25 MHz */
	#define ML_TIMING_1125_1920x1035_5994i  	24 /* SMPTE 260M/240M 74.25/1.001 MHz*/
	#define ML_TIMING_750_1280x720_60p      	25 /* SMPTE 296M 74.25 MHz */
	#define ML_TIMING_750_1280x720_5994p    	26 /* SMPTE 296M 74.25/1.001 MHz */
	#define ML_TIMING_525_720x483_5994p      	27 /* SMPTE 293M 27.0 MHz */


	// ML_VIDEO_OUTPUT_REPEAT_INT32 enumerations
	#define ML_VIDEO_REPEAT_NONE	0
	#define ML_VIDEO_REPEAT_FIELD	1
	#define ML_VIDEO_REPEAT_FRAME	2


	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_PATH_H */


