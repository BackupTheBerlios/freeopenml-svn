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


	//------------------------------------------------------------------------MLpv
	// Parameter-value structure definition.
	typedef union MLvalue_u {
				int8_t		byte;
				int16_t		int16;
				int32_t   int32;
				int64_t   int64;
				float  real32;
				double  real64;
				int8_t*   pByte;
				int16_t*  pInt16;
				int32_t*  pInt32;
				int64_t*  pInt64;
				float* pReal32;
				double* pReal64;
				struct MLpv_t* pPv;
				struct MLpv_t** pMsg;
	} MLvalue;

	typedef struct MLpv_t
	{
		u_int64_t  param;
		MLvalue     value;
		int16_t     maxLength;
		int16_t     length;
		int16_t			offset;
	} MLpv;

	//-------------------------------------------------------------------Constants
	// Constants for extracting information from the parameter name

	//classe types
	#define ML_CLASS_CAPABILITIES  1
	#define ML_CLASS_USER					2
	#define ML_CLASS_JACK					3
	#define ML_CLASS_VIDEO				4
	#define ML_CLASS_IMAGE				5
	#define ML_CLASS_XCODE				6
	#define ML_CLASS_BUFFER				7
	#define ML_CLASS_EVENT				8
	#define ML_CLASS_PATH					9
	#define ML_CLASS_TIME					10
	#define ML_CLASS_ID						11
	//~ #define ML_CLASS_AUDIO				15


	#define ML_CLASS_CUSTOM_DD		128

	//************types defines
	#define	 ML_TYPE_NONE						0
	#define  ML_TYPE_BYTE           1
	#define  ML_TYPE_INT16          2
	#define  ML_TYPE_INT32          3
	#define  ML_TYPE_INT64          4
	#define  ML_TYPE_REAL32         5
	#define  ML_TYPE_REAL64         6

	#define  ML_TYPE_BYTE_POINTER   7
	#define  ML_TYPE_INT16_POINTER  8
	#define  ML_TYPE_INT32_POINTER  9
	#define  ML_TYPE_INT64_POINTER  10
	#define  ML_TYPE_REAL32_POINTER 11
	#define  ML_TYPE_REAL64_POINTER 12
	#define  ML_TYPE_PV_POINTER     13

	#define  ML_TYPE_BYTE_ARRAY     14
	#define  ML_TYPE_INT16_ARRAY	  15
	#define  ML_TYPE_INT32_ARRAY    16
	#define  ML_TYPE_INT64_ARRAY    17
	#define  ML_TYPE_REAL32_ARRAY   18
	#define  ML_TYPE_REAL64_ARRAY   19
	#define  ML_TYPE_PV_ARRAY       20
	#define  ML_TYPE_MSG_ARRAY      21


	/*** paramter decoding  defines and macros**/
	#define ML_CLASS_SHIFT 48
	#define ML_PARAM_MASK_CLASS     ((int64_t)0xffff<<ML_CLASS_SHIFT)
	#define ML_TYPE_SHIFT  32
	#define ML_PARAM_MASK_TYPE			((int64_t)0xffff<<ML_TYPE_SHIFT)
	#define ML_ID_SHIFT	0
	#define ML_PARAM_MASK_ID		((int64_t)0xffffffff<<ML_ID_SHIFT)

	#define ML_PARAM_NAME( class, type, id ) 		\
			( (u_int64_t)(class)<<ML_CLASS_SHIFT 		\
			|(u_int64_t)(type)<<ML_TYPE_SHIFT				\
			|((id)<<ML_ID_SHIFT) )

	#define ML_PARAM_GET_ID(name)    (((name)&ML_PARAM_MASK_ID)>>ML_ID_SHIFT)
	#define ML_PARAM_GET_CLASS(name) (((name)&ML_PARAM_MASK_CLASS)>>ML_CLASS_SHIFT)
	#define ML_PARAM_GET_TYPE(name)  (((name)&ML_PARAM_MASK_TYPE)>>ML_TYPE_SHIFT)

	#define ML_END	0

	#ifdef __cplusplus
	}
	#endif

#endif /* _ML_PARAM_H_ */
