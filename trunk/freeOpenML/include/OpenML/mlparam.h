/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef _ML_PARAM_H_
	#define _ML_PARAM_H_
	#ifdef __cplusplus
	extern "C" {
	#endif

	enum ML_param_class {
			ML_CLASS_CAP,
			ML_CLASS_USER,
			ML_CLASS_JACK,
			ML_CLASS_VIDEO,
			ML_CLASS_IMAGE,
			ML_CLASS_XCODE,
			ML_CLASS_BUFFER,
			ML_CLASS_EVENT,
			ML_CLASS_PATH,
			ML_CLASS_TIME,
			ML_CLASS_ID,
			//~ #DEFINE ML_CLASS_AUDIO				15
			ML_CLASS_CUSTOM_DD=128,
	};

		//************types defines
	enum ML_param_type {
			none=0,
			byte,
			int16,
			int32,
			int64,
			real32,
			real64,
		// pointer parameters have been removed
                // use shared memory buffer instead
		//	byte_pointer,
		//	int16_pointer,
		//	int32_pointer,
		//	int64_pointer,
		//	real32_pointer,
		//	real64_pointer,
		//	pv_pointer,
                        
                        buffer_id,
                        buffer_desc,

			byte_array,
			int16_array,
			int32_array,
			int64_array,
			real32_array,
			real64_array,
			pv_array,
			msg_array
	};


			
#pragma pack(push, 1)

	//------------------------------------------------------------------------MLpv
	// Parameter-value structure definition.
	typedef union MLvalue_u {
				uint8_t		byte;
				int16_t		int16;
				int32_t   int32;
				int64_t   int64;
				float  real32;
				double  real64;
				uint8_t*   pByte;
				int16_t*  pInt16;
				int32_t*  pInt32;
				int64_t*  pInt64;
				float* pReal32;
				double* pReal64;
                                uint64_t bufferid;
                                struct MLbuffer_t* buffer_desc;
				struct MLpv_t* pPv;
				struct MLpv_t** pMsg;
	} MLvalue;

	struct param_t {
			uint32_t id;
			enum ML_param_type type;
			enum ML_param_class CLASS;
	};

	typedef struct MLpv_t
	{
		union {
				uint64_t  param;
				struct param_t params;
		};
		MLvalue     value;
		int16_t     maxLength;
		int16_t     length;
		int16_t			offset;
	} MLpv;

#pragma pack(pop)

	//-------------------------------------------------------------------Constants
	// Constants for extracting information from the parameter name
	//classe types



	/*** paramter decoding  defines and macros**/
	#define ML_END	0

	
extern uint64_t MLparam (enum ML_param_class CLASS,
	                       enum ML_param_type type,
												 uint16_t id);


	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_PARAM_H_ */
