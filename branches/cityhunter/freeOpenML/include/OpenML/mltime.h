/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#ifndef __MLTIME_H
	#define __MLTIME_H

	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>
	// ust/msc support
	#define ML_VIDEO_UST_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 0)
	#define ML_VIDEO_MSC_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 1)
	#define ML_VIDEO_ASC_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 2)
	#define ML_AUDIO_UST_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 3)
	#define ML_AUDIO_MSC_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 4)
	#define ML_AUDIO_ASC_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 5)
	#define ML_IF_VIDEO_UST_LT  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 6)
	#define ML_IF_AUDIO_UST_LT  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 7)
	#define ML_WAIT_FOR_VIDEO_UST_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 8)
	#define ML_WAIT_FOR_AUDIO_UST_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 9)
	#define ML_WAIT_FOR_VIDEO_MSC_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 10)
	#define ML_WAIT_FOR_AUDIO_MSC_INT64  ML_PARAM_NAME( ML_CLASS_TIME, ML_TYPE_INT64, 11)

	#ifdef __cplusplus
	}
	#endif
#endif
