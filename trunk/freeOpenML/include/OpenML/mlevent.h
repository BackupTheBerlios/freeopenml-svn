/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#ifndef __ML_EVENT_H__
	#define __ML_EVENT_H__

	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>
	//message signification for mlReceiveMessage()

	/*
	* The following event is generated if the event queue overflows.   This
	* can only happen if the application i) enables events and ii) does
	* not read them fast enough.  It is not maskable (except indirectly,
	* by not enabling any events).
	*/
	#define ML_EVENT_QUEUE   MLparam (event, int32,  2)
	#define ML_EVENT_DEVICE	 MLparam (event, int32,  3)
	#define ML_EVENT_VIDEO	 MLparam (event, int32,  4)
	#define ML_EVENT_XCODE	 MLparam (event, int32,  5)
	#define ML_EVENT_AUDIO	 MLparam (event, int32,  6)

	/*
	* The following event messages are generated spontaneously by devices.
	* They are only generated if the application explicitly asks for them.
	* Most devices will only support a subset of all the possible events.
	* To select/query events use the DEVICE_EVENTS parameter.
	*/
	enum ml_event
		{
			ML_EVENT_DEVICE_INFO,
			ML_EVENT_DEVICE_ERROR,
			ML_EVENT_DEVICE_UNAVAILABLE,

			ML_EVENT_VIDEO_SEQUENCE_LOST,
			ML_EVENT_VIDEO_SYNC_GAINED,
			ML_EVENT_VIDEO_SYNC_LOST,
			ML_EVENT_VIDEO_VERTICAL_RETRACE,

			ML_EVENT_XCODE_FAILED,

			ML_EVENT_AUDIO_SEQUENCE_LOST,
			ML_EVENT_AUDIO_SAMPLE_RATE_CHANGED,

			ML_EVENT_QUEUE_OVERFLOW,
		};

	
	#ifdef __cplusplus
	}
	#endif

#endif
