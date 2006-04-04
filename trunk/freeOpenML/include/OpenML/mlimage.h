/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef __INC_MLIMAGE_H__
#define __INC_MLIMAGE_H__

	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mlparam.h>

	// Image parameters specify how images are stored or how they should
	// be interpreted by SDK subsystems.
	#define  ML_IMAGE_BUFFER_POINTER	    MLparam (buffer, byte_pointer,1)
	#define  ML_IMAGE_WIDTH_INT32					MLparam (image, int32,     2)
	#define  ML_IMAGE_HEIGHT_1_INT32			MLparam (image, int32,     3)
	#define  ML_IMAGE_HEIGHT_2_INT32			MLparam (image, int32,     4)
	#define  ML_IMAGE_ROW_BYTES_INT32			MLparam (image, int32,     5)
	#define  ML_IMAGE_SKIP_PIXELS_INT32		MLparam (image, int32,     6)
	#define  ML_IMAGE_SKIP_ROWS_INT32			MLparam (image, int32,     7)
	#define  ML_IMAGE_ORIENTATION_INT32		MLparam (image, int32,     8)
	#define  ML_IMAGE_BUFFER_SIZE_INT32		MLparam (image, int32,     9)

	  // Field/frame description
	#define  ML_IMAGE_TEMPORAL_SAMPLING_INT32  MLparam (image, int32, 10)
	#define  ML_IMAGE_INTERLEAVE_MODE_INT32    MLparam (image, int32, 11)
	#define  ML_IMAGE_DOMINANCE_INT32          MLparam (image, int32, 12)

	  // Pixel storage descriptions
	#define  ML_IMAGE_COMPRESSION_INT32 	MLparam (image, int32, 20)
	#define  ML_IMAGE_SAMPLING_INT32			MLparam (image, int32, 22)
	#define  ML_IMAGE_COLORSPACE_INT32		MLparam (image, int32, 23)
	#define  ML_IMAGE_PACKING_INT32	    	MLparam (image, int32, 24)

	  // Gamma of the stored image (see also ML_JACK_GAMMA_REAL32).
	  // the difference between the gamma of the input image/jack
	  // and that of the output image/jack determines the amount of
	  // gamma correction (if any).
	  // XXX - initial draft implementation of this parameter
	  // XXX - need detailed definition with equations and default value.
	#define  ML_IMAGE_GAMMA_REAL32        MLparam (image, real32, 25)

	  // Desired compression factor, a value of 1 indicates no compression,
	  // a value of 10 indicates that approximatly 10 compressed buffers
	  // require the same space as 1 uncompressed buffer.
	  // The size of the uncompressed buffer depends on image width,
	  // height, packing and sampling.
	#define  ML_IMAGE_COMPRESSION_FACTOR_REAL32  MLparam (image, real32, 33)

	  // Describes what happens to alpha when going xxx -> xxx4
	#define  ML_IMAGE_ALPHA_FILL_INT32	MLparam (image, int32, 40)

	  // Other ancilliary parts of an image
	  // "Horizontal ANCilliary" height/width/format/buffer pointer
	#define  ML_HANC_WIDTH_INT32				MLparam (image, int32, 50)
	#define  ML_HANC_HEIGHT_1_INT32	    MLparam (image, int32, 51)
	#define  ML_HANC_HEIGHT_2_INT32	    MLparam (image, int32, 52)
	#define  ML_HANC_FORMAT_INT32				MLparam (image, int32, 53)
	#define  ML_HANC_BUFFER_POINTER	    MLparam (buffer, byte_pointer,54)

	  // "Vertical ANCilliary" height/width/format/buffer pointer
	#define  ML_VANC_WIDTH_INT32				MLparam (image, int32, 60)
	#define  ML_VANC_HEIGHT_1_INT32	    MLparam (image, int32, 61)
	#define  ML_VANC_HEIGHT_2_INT32	    MLparam (image, int32, 62)
	#define  ML_VANC_FORMAT_INT32				MLparam (image, int32, 63)
	#define  ML_VANC_BUFFER_POINTER	    MLparam (buffer, byte_pointer,64)


	// For progressive scan images (ML_IMAGE_TEMPORAL_SAMPLING_INT32
	// is progressive), the height is only set on the first buffer
	// (ML_IMAGE_HEIGHT_1_INT32). For convenience, this parameter
	// is aliased to ML_IMAGE_HEIGHT_INT32.
	#define  ML_IMAGE_HEIGHT_INT32 ML_IMAGE_HEIGHT_1_INT32


	// ML_IMAGE_DOMINANCE_INT32 enumerations.  For images with a
	// field-based temporal sampling, describes the field dominance.

	//***************ML_IMAGE_DOMINANCE_INT32
	enum ml_dominance
		{
			ML_DOMINANCE_F1,
			ML_DOMINANCE_F2,
		};
	//***************ML_IMAGE_INTERLEAVE_MODE_INT32
	enum ml_mode
		{
		ML_INTERLEAVE_MODE_INTERLEAVED,
		ML_INTERLEAVE_MODE_SINGLE_FIELD,
		};
	//***************ML_IMAGE_ORIENTATION_INT32
	enum ml_orientation
		{
			ML_ORIENTATION_TOP_TO_BOTTOM,
			ML_ORIENTATION_BOTTOM_TO_TOP,
		};
	//***************ML_IMAGE_TEMPORAL_SAMPLING_INT32
	enum ml_temporal_sampling
		{
			ML_TEMPORAL_SAMPLING_FIELD_BASED,
			ML_TEMPORAL_SAMPLING_PROGRESSIVE,
		};
	//***************ML_IMAGE_COMPRESSION_INT32
	#include <fourcc.h>
	#define  ML_COMPRESSION_UNCOMPRESSED	FOURCC_raw
	//**************** ML_IMAGE_COLORSPACE_INT32
		#define	ML_RANGE_SHIFT						0
		#define ML_RANGE_FULL							1<<ML_RANGE_SHIFT
		#define ML_RANGE_HEAD         		2<<ML_RANGE_SHIFT
		#define ML_RANGE_MASK       		  0xf<<ML_RANGE_SHIFT
		#define ML_STANDARD_SHIFT					4
		#define ML_STANDARD_UNSPECIFIED		0<<ML_STANDARD_SHIFT
		#define ML_STANDARD_601						1<<ML_STANDARD_SHIFT
		#define ML_STANDARD_240M					2<<ML_STANDARD_SHIFT
		#define ML_STANDARD_709						3<<ML_STANDARD_SHIFT
		#define ML_STANDARD_MASK					0xf<<ML_STANDARD_SHIFT
		#define ML_REPRESENTATION_SHIFT		8
		#define ML_REPRESENTATION_RGB			1<<ML_REPRESENTATION_SHIFT
		#define ML_REPRESENTATION_CbYCr		2<<ML_REPRESENTATION_SHIFT
		#define ML_REPRESENTATION_MASK		0xf<<ML_REPRESENTATION_SHIFT

		#define ML_COLORSPACE_RGB_601_FULL    (ML_REPRESENTATION_RGB | ML_STANDARD_601 | ML_RANGE_FULL)
		#define ML_COLORSPACE_RGB_601_HEAD    (ML_REPRESENTATION_RGB | ML_STANDARD_601 | ML_RANGE_HEAD)
		#define ML_COLORSPACE_CbYCr_601_FULL  (ML_REPRESENTATION_CbYCr | ML_STANDARD_601 | ML_RANGE_FULL)
		#define ML_COLORSPACE_CbYCr_601_HEAD  (ML_REPRESENTATION_CbYCr | ML_STANDARD_601 | ML_RANGE_HEAD)

		  // Colorspaces based on SMPTE 240M
		#define ML_COLORSPACE_RGB_240M_FULL   (ML_REPRESENTATION_RGB | ML_STANDARD_240M | ML_RANGE_FULL)
		#define ML_COLORSPACE_RGB_240M_HEAD   (ML_REPRESENTATION_RGB | ML_STANDARD_240M | ML_RANGE_HEAD)
		#define ML_COLORSPACE_CbYCr_240M_FULL (ML_REPRESENTATION_CbYCr | ML_STANDARD_240M | ML_RANGE_FULL)
		#define ML_COLORSPACE_CbYCr_240M_HEAD (ML_REPRESENTATION_CbYCr | ML_STANDARD_240M | ML_RANGE_HEAD)

		  // Colorspaces based on ITU-R BT.709-2 60Hz
		#define ML_COLORSPACE_RGB_709_FULL    (ML_REPRESENTATION_RGB | ML_STANDARD_709 | ML_RANGE_FULL)
		#define ML_COLORSPACE_RGB_709_HEAD    (ML_REPRESENTATION_RGB | ML_STANDARD_709 | ML_RANGE_HEAD)
		#define ML_COLORSPACE_CbYCr_709_FULL  (ML_REPRESENTATION_CbYCr | ML_STANDARD_709 | ML_RANGE_FULL)
		#define ML_COLORSPACE_CbYCr_709_HEAD  (ML_REPRESENTATION_CbYCr | ML_STANDARD_709 | ML_RANGE_HEAD)


		// Some useful macros for checking colorspace

		#define ML_GET_COLORSPACE_RANGE(cs)          ((cs&ML_RANGE_MASK)>>ML_RANGE_SHIFT)
		#define ML_GET_COLORSPACE_STANDARD(cs)       ((cs&ML_STANDARD_MASK)>>ML_STANDARD_SHIFT)
		#define ML_GET_COLORSPACE_REPRESENTATION(cs) ((cs&ML_REPRESENTATION_MASK)>>ML_REPRESENTATION_SHIFT)

	//************************** ML_IMAGE_SAMPLING_INT32
	enum ml_image_sampling 
		{
			ML_SAMPLING_4444       =0x004444,
			ML_SAMPLING_4224       =0x004224,
			ML_SAMPLING_444        =0x004440,
			ML_SAMPLING_422        =0x004220,
			ML_SAMPLING_420_MPEG1  =0x104200,
			ML_SAMPLING_420_MPEG2  =0x204200,
			ML_SAMPLING_420_DVC625 =0x304200,
			ML_SAMPLING_411_DVC    =0x404110,
			ML_SAMPLING_4004       =0x004004,
			ML_SAMPLING_400        =0x004000,
			ML_SAMPLING_0004       =0x000004,   // linear alpha
		};
		// Some useful macros for checking sampling
		#define ML_IS_SAMPLING_422x(s) (((s)&0x00fff0)==0x004220)
		#define ML_IS_SAMPLING_444x(s) (((s)&0x00fff0)==0x004440)
		#define ML_IS_SAMPLING_xxx4(s) (((s)&0x00000f)==0x000004)
	//************************** ML_IMAGE_PACKING_INT32
		// A useful macro for defining component packing order
		#define ML_PACKING_FIELD_OFFSET 12
		#define ML_PACKING_ORDER(A,B,C,D) ((((A-1)&3)<<6|(((B-1)&3)<<4)|(((C-1)&3)<<2)|((D-1)&3)) << ML_PACKING_FIELD_OFFSET)

		#define ML_PACKING_PAD_FROM_MS   0x00000000  // pad by repeating the most significant part of value
		#define ML_PACKING_PAD_ZEROS     0x00400000  // pad with zeros
		#define ML_PACKING_PAD_FROM_LS   0x00800000  // pad with repeating the least significant bit
		#define ML_PACKING_DETAIL_MASK   0x000000ff

		#define ML_PACKING_UNSIGNED      0x00000100
		#define ML_PACKING_SIGNED        0x00000200
		#define ML_PACKING_REAL          0x00000300
		#define ML_PACKING_TYPE_MASK     0x00000f00

		// Packing order definitions adhere the the following bit assignment
		// for component position.
		// b7b6 << 12 = comp1 position (0=first,1=second,2=third,3=forth)
		// b5b4 << 12 = comp2 position (0=first,1=second,2=third,3=forth)
		// b3b2 << 12 = comp3 position (0=first,1=second,2=third,3=forth)
		// b1b0 << 12 = comp4 position (0=first,1=second,2=third,3=forth)
		#define ML_PACKING_1234          ML_PACKING_ORDER(1,2,3,4)
		#define ML_PACKING_1243          ML_PACKING_ORDER(1,2,4,3)
		#define ML_PACKING_1324          ML_PACKING_ORDER(1,3,2,4)
		#define ML_PACKING_1342          ML_PACKING_ORDER(1,3,4,2)
		#define ML_PACKING_1423          ML_PACKING_ORDER(1,4,2,3)
		#define ML_PACKING_1432          ML_PACKING_ORDER(1,4,3,2)
		#define ML_PACKING_2134          ML_PACKING_ORDER(2,1,3,4)
		#define ML_PACKING_2143          ML_PACKING_ORDER(2,1,4,3)
		#define ML_PACKING_2314          ML_PACKING_ORDER(2,3,1,4)
		#define ML_PACKING_2341          ML_PACKING_ORDER(2,3,4,1)
		#define ML_PACKING_2413          ML_PACKING_ORDER(2,4,1,3)
		#define ML_PACKING_2431          ML_PACKING_ORDER(2,4,3,1)
		#define ML_PACKING_3124          ML_PACKING_ORDER(3,1,2,4)
		#define ML_PACKING_3142          ML_PACKING_ORDER(3,1,4,2)
		#define ML_PACKING_3214          ML_PACKING_ORDER(3,2,1,4)
		#define ML_PACKING_3241          ML_PACKING_ORDER(3,2,4,1)
		#define ML_PACKING_3412          ML_PACKING_ORDER(3,4,1,2)
		#define ML_PACKING_3421          ML_PACKING_ORDER(3,4,2,1)
		#define ML_PACKING_4123          ML_PACKING_ORDER(4,1,2,3)
		#define ML_PACKING_4132          ML_PACKING_ORDER(4,1,3,2)
		#define ML_PACKING_4213          ML_PACKING_ORDER(4,2,1,3)
		#define ML_PACKING_4231          ML_PACKING_ORDER(4,2,3,1)
		#define ML_PACKING_4312          ML_PACKING_ORDER(4,3,1,2)
		#define ML_PACKING_4321          ML_PACKING_ORDER(4,3,2,1)

		#define ML_PACKING_ORDER_MASK    0x000ff000

		#define ML_PACKING_SIMPLE        0x10000000
		#define ML_PACKING_IN16L         0x21100000
		#define ML_PACKING_IN16R         0x21200000
		#define ML_PACKING_COMPLEX       0x40000000
		#define ML_PACKING_CLASS_MASK    0x70000000


		// ML_IMAGE_PACKING_INT32 - specifies the packing
		// of the pixels in the image buffer.
		//
		// ML_PACKING_{signed}{size}{order}
		//
		// {signed} 'S' if signed, or blank if unsigned component values
		//
		// {size} is the number of bits in each component.
		// May be a single number (if all components are the same size).
		// May end 'in16L' if each component is left-shifted in a 16-bit word
		// or 'in16R' if component is right-shifted in a 16-bit word.
		// For complex packings (where all components are packed into a
		// single integer) specify the size of each of the 4 components
		// separated by '_'.
		//
		// {order} is the order in which components are packed. Empty to
		// indicate normal component ordering (1,2,3,4), 'R' to indicate
		// reversed component ordering (4,3,2,1) or a numeric sequence to
		// indicate an unusual component order (e.g. 1324 is RBGA).


		// Simple packings
		// - all components the same size
		// - no padding between components
		// - treat as a stream of components
		#define ML_PACKING_8         (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 8  | ML_PACKING_1234)
		#define ML_PACKING_8_R       (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 8  | ML_PACKING_4321)
		#define ML_PACKING_8_4123    (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 8  | ML_PACKING_4123)
		#define ML_PACKING_8_3214    (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 8  | ML_PACKING_3214)
		#define ML_PACKING_8_2134    (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 8  | ML_PACKING_2134)
		#define ML_PACKING_10        (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 10 | ML_PACKING_1234)
		#define ML_PACKING_10_R      (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 10 | ML_PACKING_4321)
		#define ML_PACKING_10_2134   (ML_PACKING_SIMPLE | ML_PACKING_UNSIGNED | 10 | ML_PACKING_2134)
		#define ML_PACKING_S12       (ML_PACKING_SIMPLE | ML_PACKING_SIGNED   | 12 | ML_PACKING_1234)

		// Padded packings
		// - all components the same size
		// - each component padded to 16-bits
		// - treat as a stream of 16-bit shorts
		#define ML_PACKING_10in16L       (ML_PACKING_IN16L | ML_PACKING_UNSIGNED | 10 | ML_PACKING_1234)
		#define ML_PACKING_10in16L_R     (ML_PACKING_IN16L | ML_PACKING_UNSIGNED | 10 | ML_PACKING_4321)
		#define ML_PACKING_10in16R       (ML_PACKING_IN16R | ML_PACKING_UNSIGNED | 10 | ML_PACKING_1234)
		#define ML_PACKING_10in16R_R     (ML_PACKING_IN16R | ML_PACKING_UNSIGNED | 10 | ML_PACKING_4321)
		#define ML_PACKING_12in16L       (ML_PACKING_IN16L | ML_PACKING_UNSIGNED | 12 | ML_PACKING_1234)
		#define ML_PACKING_12in16L0_3214 (ML_PACKING_IN16L | ML_PACKING_UNSIGNED | 12 | ML_PACKING_3214 | ML_PACKING_PAD_ZEROS )
		#define ML_PACKING_S12in16L      (ML_PACKING_IN16L | ML_PACKING_SIGNED   | 12 | ML_PACKING_1234)
		#define ML_PACKING_S12in16R      (ML_PACKING_IN16R | ML_PACKING_SIGNED   | 12 | ML_PACKING_1234)
		#define ML_PACKING_S13in16L      (ML_PACKING_IN16L | ML_PACKING_SIGNED   | 13 | ML_PACKING_1234)
		#define ML_PACKING_S13in16R      (ML_PACKING_IN16R | ML_PACKING_SIGNED   | 13 | ML_PACKING_1234)

		// Complex packings
		// - all components packed together into a single 32-bit int
		// - treat as a stream of 32-bit integers
		#define ML_PACKING_10_10_10_2    (ML_PACKING_COMPLEX | 1 | ML_PACKING_1234)
		#define ML_PACKING_10_10_10_2_R  (ML_PACKING_COMPLEX | 1 | ML_PACKING_4321)


	// Currently Supported Horizontal and Vertical Ancilliary Data Formats:
	//************************** ML_HANC_FORMAT_INT32
		enum ml_hanc_format
			{
				ML_HANC_FORMAT_RAW,
				ML_HANC_FORMAT_PACKED_272M,
				ML_HANC_FORMAT_PACKED_299M,
			};


	//************************** ML_VANC_FORMAT_INT32
	enum ml_vanc_format
		{
			ML_VANC_FORMAT_RAW,
		};


	// Predefined image sizes (in bytes)
	// due to the nature of DV encoding, image sizes are fixed
	// these defines provide a global definition of those sizes
	// note that suffixes match "ML_COMPRESSION" suffixes.

	//************************** enum mlImageSizeDefinitions {
	enum ml_image_size
		{
			ML_IMAGE_SIZE_DV_625		=144000,
      ML_IMAGE_SIZE_DV_525		=120000,
			ML_IMAGE_SIZE_DVCPRO_625	=144000,
	    ML_IMAGE_SIZE_DVCPRO_525	=120000,
	    ML_IMAGE_SIZE_DVCPRO50_625	=288000,
	    ML_IMAGE_SIZE_DVCPRO50_525	=240000,
		};

	#ifdef __cplusplus
	}
	#endif

#endif

