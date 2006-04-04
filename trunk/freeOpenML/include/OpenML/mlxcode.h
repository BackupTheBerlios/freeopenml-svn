/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef _ML_XCODE_H
	#define _ML_XCODE_H
	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>

	//--------------------------------------------------------------------------
	// mlXcode parameters used when obtaining the capabilities of a transcoder
	// Some parameter-value pairs returned by mlXcodeGetCapabilities have
	// a pre-defined location in the list. Their indexes into the array
	// are specified in mlXcodeIndexes
	//
	// See also the subsystem-independent capabilities defined in mlparam.h
	//--------------------------------------------------------------------------

	// define's for default src and dst pipe

	#define ML_XCODE_SRC_PIPE ((int64_t)0x1 )
	#define ML_XCODE_DST_PIPE ((int64_t)0x8 )


	#define ML_XCODE_ENGINE_TYPE_INT32      	  MLparam (xcode, int32,				0)
	#define ML_XCODE_IMPLEMENTATION_TYPE_INT32	MLparam (xcode, int32,				1)
	#define ML_XCODE_PIXEL_LINE_ALIGNMENT_INT32	MLparam (xcode, int32,				2)
	#define ML_XCODE_BUFFER_ALIGNMENT_INT32			ML_PATH_BUFFER_ALIGNMENT_INT32
	#define ML_XCODE_EXTENSIONS_BYTE_ARRAY   	 	MLparam (xcode, byte_array, 	3)
	#define ML_XCODE_SRC_COUNT             			MLparam (xcode, int64_array, 6)
	#define ML_XCODE_DEST_COUNT            			MLparam (xcode, int64_array, 7)
	#define ML_PIPE_TYPE_INT32 									MLparam (xcode, int32, 			8)
	#define ML_XCODE_SPATIAL_QUALITY_REAL32     MLparam (xcode, real32,      9)
	#define ML_XCODE_BITRATE_INT32							MLparam (xcode, int32,				10)
	#define ML_XCODE_FEATURES										ML_FEATURES

	enum __pipe_type {
		ML_PIPE_TYPE_MEM_TO_ENGINE,
		ML_PIPE_TYPE_ENGINE_TO_MEM,
	};

	enum __stream_type {
		ML_XCODE_STREAM_SINGLE,
		ML_XCODE_STREAM_MULTI,
	};


	// ML_XCODE_IMPLEMENTATION_TYPE_INT32 enumerated values
	enum ml_xcode_imp {
			ML_XCODE_IMPLEMENTATION_TYPE_SW,
			ML_XCODE_IMPLEMENTATION_TYPE_HW,
	};


	// ML_XCODE_MODE_INT32 enumerated values
	enum ml_xcode_mode {
			ML_XCODE_MODE_SYNCHRONOUS,
			ML_XCODE_MODE_ASYNCHRONOUS,
	};

	// ML_XCODE_ENGINE_INT32 enumerated values
	enum ml_xcode_engine {
			ML_XCODE_ENGINE_TYPE_NULL,
	};



	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_XCODE_H */
