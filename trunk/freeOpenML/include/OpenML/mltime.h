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
	#define ML_VIDEO_UST_INT64  MLparam (time, int64, 0)
	#define ML_VIDEO_MSC_INT64  MLparam (time, int64, 1)
	#define ML_VIDEO_ASC_INT64  MLparam (time, int64, 2)
	#define ML_AUDIO_UST_INT64  MLparam (time, int64, 3)
	#define ML_AUDIO_MSC_INT64  MLparam (time, int64, 4)
	#define ML_AUDIO_ASC_INT64  MLparam (time, int64, 5)
	#define ML_IF_VIDEO_UST_LT  MLparam (time, int64, 6)
	#define ML_IF_AUDIO_UST_LT  MLparam (time, int64, 7)
	#define ML_WAIT_FOR_VIDEO_UST_INT64  MLparam (time, int64, 8)
	#define ML_WAIT_FOR_AUDIO_UST_INT64  MLparam (time, int64, 9)
	#define ML_WAIT_FOR_VIDEO_MSC_INT64  MLparam (time, int64, 10)
	#define ML_WAIT_FOR_AUDIO_MSC_INT64  MLparam (time, int64, 11)

	#ifdef __cplusplus
	}
	#endif
#endif
