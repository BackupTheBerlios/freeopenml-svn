/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source
* dir of the package
************************************************************************/



//***************ML_IMAGE_COMPRESSION_INT32
#define	 FOURCC (A,B,C,D) (A<<24|B<<16|C<<8|D<<0)

#define  ML_COMPRESSION_BASELINE_JPEG	FOURCC(J,P,G,1)
#define  ML_COMPRESSION_LOSSLESS_JPEG	FOURCC(J,P,G,2)
#define  ML_COMPRESSION_DV_625				FOURCC(D,V, ,6)
#define  ML_COMPRESSION_DV_525				FOURCC(D,V, ,5)
#define  ML_COMPRESSION_DVCPRO_625		FOURCC(D,V,P,6)
#define  ML_COMPRESSION_DVCPRO_525		FOURCC(D,V,P,5)
#define  ML_COMPRESSION_DVCPRO50_625	FOURCC(D,V,5,6)
#define  ML_COMPRESSION_DVCPRO50_525	FOURCC(D,V,5,5)
#define  ML_COMPRESSION_SLIM					FOURCC(S,L,I,M)
#define  ML_COMPRESSION_MPEG2I				FOURCC(M,P,G,2)



//RGB Formats
//Label  	FOURCC in Hex  	Bits per pixel  	Description
#define FOURCC_BI_RGB		0x00000000 			/*1,4,8,16,24,32 	Basic Windows bitmap format. 1, 4 and 8 bpp versions are palettised. 16, 24 and 32bpp contain raw RGB samples.*/
#define FOURCC_RGB 			FOURCC(R,G,B,2) /*	1,4,8,16,24,32 	Alias for BI_RGB*/
#define FOURCC_BI_RLE8 	0x00000001 			/*8 	Run length encoded 8bpp RGB image.*/
#define FOURCC_RLE8 		FOURCC(R,L,E,8) /*	8 	Alias for BI_RLE8*/
#define FOURCC_BI_RLE4 	0x00000002 			/*4 	Run length encoded 4bpp RGB image.*/
#define FOURCC_RLE4 		FOURCC(R,L,E,4) /*4 	Alias for BI_RLE4*/
#define FOURCC_BI_BITFIELDS 	0x00000003/* 	16,24,32 	Raw RGB with arbitrary sample packing within a pixel. Packing and precision of R, G and B components is determined by bit masks for each.*/
#define FOURCC_raw 			0x32776173 			/*? 	Apparently "raw, uncompressed RGB bitmaps" but I have no idea how many bits per pixel (uses bpp field in header?)*/
#define FOURCC_RGBA 		FOURCC(R,G,B,A) /*	16,32 	Raw RGB with alpha. Sample precision and packing is arbitrary and determined using bit masks for each component, as for BI_BITFIELDS.*/
#define FOURCC_RGBT 		FOURCC(R,G,G,T) /*	16,32 	Raw RGB with a transparency field. Layout is as for BI_RGB at 16 and 32 bits per pixel but the msb in each pixel indicates whether the pixel is transparent or not.*/

//Packed YUV Formats
//Label 	FOURCC in Hex 	Bits per pixel 	Description*/
#define FOURCC_AYUV 	FOURCC(A,Y,U,V) 	/*32 	Combined YUV and alpha*/
#define FOURCC_CLJR		FOURCC(C,L,J,R) 	/*8 	Cirrus Logic format with 4 pixels packed into a u_int32. A form of YUV 4:1:1 wiht less than 8 bits per Y, U and V sample.*/
#define FOURCC_cyuv 	FOURCC(c,y,u,v) 	/*16 	Essentially a copy of UYVY except that the sense of the height is reversed - the image is upside down with respect to the UYVY version.*/
#define FOURCC_GREY 	FOURCC(G,R,E,Y) 	/*8 	Apparently a duplicate of Y800 (and also, presumably, "Y8	")*/
#define FOURCC_IRAW 	FOURCC(I,R,A,W) 	/*? 	Intel uncompressed YUV. I have no information on this format - can you help?*/
#define FOURCC_IUYV 	FOURCC(I,U,Y,V) 	/*16 	Interlaced version of UYVY (line order 0, 2, 4,....,1, 3, 5....) registered by Silviu Brinzei of Lead Technologies.*/
#define FOURCC_IY41 	FOURCC(I,Y,4,1)		/*12 	Interlaced version of Y41P (line order 0, 2, 4,....,1, 3, 5....) registered by Silviu Brinzei of Lead Technologies.*/
#define FOURCC_IYU1 	FOURCC(I,Y,U,1) 	/*12 	12 bit format used in mode 2 of the IEEE 1394 Digital Camera 1.04 spec. This is equivalent to Y411*/
#define FOURCC_IYU2 	FOURCC(I,Y,U,2) 	/*24 	24 bit format used in mode 0 of the IEEE 1394 Digital Camera 1.04 spec*/
#define FOURCC_UYNV 	FOURCC(U,Y,N,V) 	/*16 	A direct copy of UYVY registered by NVidia to work around problems in some old codecs which did not like hardware which offered more than 2 UYVY surfaces.*/
#define FOURCC_UYVP 	FOURCC(U,Y,V,P) 	/*24? 	YCbCr 4:2:2 extended precision 10-bits per component in U0Y0V0Y1 order. Registered by Rich Ehlers of Evans & Sutherland. (Awaiting confirmation of component packing structure)*/
#define FOURCC_UYVY 	FOURCC(U,Y,V,Y) 	/*16 	YUV 4:2:2 (Y sample at every pixel, U and V sampled at every second pixel horizontally on each line). A macropixel contains 2 pixels in 1 u_int32.*/
#define FOURCC_V210 	FOURCC(V,2,1,0) 	/*32 	10-bit 4:2:2 YCrCb equivalent to the Quicktime format of the same name.*/
#define FOURCC_V422 	FOURCC(V,4,2,2) 	/*16 	I am told that this is an upside down version of UYVY.*/
#define FOURCC_V655 	FOURCC(V,6,5,5) 	/*16? 	16 bit YUV 4:2:2 format registered by Vitec Multimedia. I have no information on the component ordering or packing.*/
#define FOURCC_VYUY 	FOURCC(V,Y,U,Y) 	/*? 	ATI Packed YUV Data (format unknown but you can get hold of a codec supporting it here)*/
#define FOURCC_Y422 	FOURCC(Y,4,2,2) 	/*16 	Direct copy of UYVY as used by ADS Technologies Pyro WebCam firewire camera.*/
#define FOURCC_YUY2 	FOURCC(Y,U,Y,2) 	/*16 	YUV 4:2:2 as for UYVY but with different component ordering within the u_int32 macropixel.*/
#define FOURCC_YUYV 	FOURCC(Y,U,Y,V) 	/*16 	Duplicate of YUY2*/
#define FOURCC_YUNV 	FOURCC(Y,U,N,V) 	/*16 	A direct copy of YUY2 registered by NVidia to work around problems in some old codecs which did not like hardware which offered more than 2 YUY2 surfaces.*/
#define FOURCC_YVYU 	FOURCC(Y,V,Y,U) 	/*16 	YUV 4:2:2 as for UYVY but with different component ordering within the u_int32 macropixel.*/
#define FOURCC_Y41P 	FOURCC(Y,4,1,P) 	/*12 	YUV 4:1:1 (Y sample at every pixel, U and V sampled at every fourth pixel horizontally on each line). A macropixel contains 8 pixels in 3 u_int32s.*/
#define FOURCC_Y411 	FOURCC(Y,4,1,1) 	/*12 	YUV 4:1:1 with a packed, 6 byte/4 pixel macroblock structure.*/
#define FOURCC_Y211 	FOURCC(Y,2,1,1) 	/*8 	Packed YUV format with Y sampled at every second pixel across each line and U and V sampled at every fourth pixel.*/
#define FOURCC_Y41T 	FOURCC(Y,4,1,T) 	/*12 	Format as for Y41P but the lsb of each Y component is used to signal pixel transparency .*/
#define FOURCC_Y42T 	FOURCC(Y,4,2,T) 	/*16 	Format as for UYVY but the lsb of each Y component is used to signal pixel transparency .*/
#define FOURCC_YUVP 	FOURCC(Y,U,V,P) 	/*24? 	YCbCr 4:2:2 extended precision 10-bits per component in Y0U0Y1V0 order. Registered by Rich Ehlers of Evans & Sutherland.*/
#define FOURCC_Y800 	FOURCC(Y,8,0,0) 	/*8 	Simple, single Y plane for monochrome images.*/
#define FOURCC_Y8 		FOURCC(Y,8, , ) 	/*8 	Duplicate of Y800 as far as I can see.*/


/*Planar YUV Formats*/
/*Label 	FOURCC in Hex 	Bits per pixel 	 Description*/
#define FOURCC_YVU9		FOURCC(Y,V,U,9)	/*9 	8 bit Y plane followed by 8 bit 4x4 subsampled V and U planes. Registered by Intel.*/
#define FOURCC_YUV9		FOURCC(Y,U,V,9)	/*9? 	Registered by Intel. I have no other information on this format. Probably a copy of YVU9.*/
#define FOURCC_IF09		FOURCC(I,F,0,9)	/*9.5 	As YVU9 but an additional 4x4 subsampled plane is appended containing delta information relative to the last frame. (Bpp is reported as 9)*/
#define FOURCC_YV16		FOURCC(Y,V,1,6)	/*16 	8 bit Y plane followed by 8 bit 2x1 subsampled V and U planes.*/
#define FOURCC_YV12		FOURCC(Y,V,1,2)	/*12 	8 bit Y plane followed by 8 bit 2x2 subsampled V and U planes.*/
#define FOURCC_I420		FOURCC(I,4,2,0)	/*12 	8 bit Y plane followed by 8 bit 2x2 subsampled U and V planes.*/
#define FOURCC_IYUV		FOURCC(I,Y,U,V)	/*12 	Duplicate FOURCC, identical to I420.*/
#define FOURCC_NV12		FOURCC(N,V,1,2)	/*12 	8-bit Y plane followed by an interleaved U/V plane with 2x2 subsampling*/
#define FOURCC_NV21		FOURCC(N,V,2,1)	/*12 	As NV12 with U and V reversed in the interleaved plane*/
#define FOURCC_IMC1		FOURCC(I,M,C,1)	/*12 	As YV12 except the U and V planes each have the same stride as the Y plane*/
#define FOURCC_IMC2		FOURCC(I,M,C,2)	/*12 	Similar to IMC1 except that the U and V lines are interleaved at half stride boundaries*/
#define FOURCC_IMC3		FOURCC(I,M,C,3)	/*12 	As IMC1 except that U and V are swapped*/
#define FOURCC_IMC4		FOURCC(I,M,C,4)	/*12 	As IMC2 except that U and V are swapped*/
#define FOURCC_CLPL		FOURCC(C,L,P,L)	/*12 	Format similar to YV12 but including a level of indirection.*/
#define FOURCC_Y41B		FOURCC(Y,4,1,B)	/*12? 	Weitek format listed as "YUV 4:1:1 planar". I have no other information on this format.*/
#define FOURCC_Y42B		FOURCC(Y,4,2,B)	/*16? 	Weitek format listed as "YUV 4:2:2 planar". I have no other information on this format.*/
/*****************************************************************************/
/***********************C O M P R E S S I O N		F O U R C C*******************/
/*****************************************************************************/
#define FOURCC_3IV1		FOURCC(3,I,V,1)	/*3IVX	MPEG4-based codec. Used by 3ivx Delta 1.0-3.5.		FOURCC "3IV0" was also used for a while but never publicly released.*/
#define FOURCC_3IV2		FOURCC(3,I,V,2)	/*3ivx 	3IVX 	MPEG4-based codec. To be used for "3ivx Delta 4.0."*/
#define FOURCC_8BPS		FOURCC(8,B,P,S)	/*Planar RGB Codec 	Apple? 	RLE codec storing RGB image in planar format under Quicktime.*/
#define FOURCC_AASC		FOURCC(A,A,S,C)	/*Autodesk Animator codec 	Autodesk 	This codec is part of Autodesk's discontinued Animator Studio for Windows. */
#define FOURCC_ABYR		FOURCC(A,B,Y,R)	/*? 	Kensington? 	Apparently a low resolution, low frame rate (6fps) codec similar to AJPG which is used in implementing movie capture in some digital cameras.*/
#define FOURCC_ADV1		FOURCC(A,D,V,1)	/*WaveCodec 	Loronix 	Apparently used in various CCTV products.*/
#define FOURCC_ADVJ		FOURCC(A,D,V,J)	/*Avid M-JPEG 	Avid Technology 	Also known as AVRn*/
#define FOURCC_AEMI		FOURCC(A,E,M,I)	/*Array VideoONE MPEG1-I Capture 	Array Microsystems 	Array's codec used for I frame only MPEG1 AVI files*/
#define FOURCC_AFLI		FOURCC(A,F,L,I)	/*Autodesk Animator codec 	Autodesk 	AVI equivalent of Autodesk's native FLI file format (presumably).*/
#define FOURCC_AFLC		FOURCC(A,F,L,C)	/*Autodesk Animator codec 	Autodesk 	AVI equivalent of the FLC native file format.*/
#define FOURCC_AJPG		FOURCC(A,J,P,G)	/*? 	? 	22fps JPEG-based codec used for movie capture by some digital cameras.*/
#define FOURCC_AMPG		FOURCC(A,M,P,G)	/*Array VideoONE MPEG 	Array Microsystems 	Codec for Array VideoONE hardware-based MPEG compression system.*/
#define FOURCC_ANIM		FOURCC(A,N,I,M)	/*RDX 	Intel 	?*/
#define FOURCC_AP41		FOURCC(A,P,4,1)	/*AngelPotion Definitive 	AngelPotion 	Another hacked version of Microsoft's MP43 codec. One source recommends against installing this codec "due to its occasional tendency to modify client structures". Apparently this means that it can destroy or otherwise mess up the	//HKEY_CLASSES_ROOT\avifile section of your registry leaving some tools incapable of playing video any more.*/
#define FOURCC_ASV1		FOURCC(A,S,V,1)	/*Asus Video 	Asus 	Codec supplied with the Asus TNT Video Capture adapter. Supposedly a very simple, DCT-based codec. Complete technical details can be found here.*/
#define FOURCC_ASV2		FOURCC(A,S,V,2)	/*Asus Video (2) 	Asus 	New codec from Asus. Supposedly a very simple DCT codec. Complete technical details can be found here.*/
#define FOURCC_ASVX		FOURCC(A,S,V,X)	/*Asus Video 2.0 	Asus 	Unusual codec which stores audio in the .avi file but puts the video in a companion .asv file. Click here for information on how to play back these files on Windows 2000 PCs.*/
#define FOURCC_AUR2		FOURCC(A,U,R,2)	/*Aura 2 Codec - YUV 422 	Auravision 	?*/
#define FOURCC_AURA		FOURCC(A,U,R,A)	/*Aura 1 Codec - YUV 411 	Auravision 	?*/
#define FOURCC_AVRn		FOURCC(A,V,R,n)	/*Avid M-JPEG 	Avid Technology 	Also known as ADVJ in Quicktime files.*/
#define FOURCC_BINK		FOURCC(B,I,N,K)	/*Bink Video 	RAD Game Tools 	Pretty popular codec in Windows games. I'm not sure if this is available as a standard Windows codec but the web site makes it sound interesting enough to list here even if it does require non-standard tools to use.*/
#define FOURCC_BLZ0		FOURCC(B,L,Z,0)	/*? 	Blizzard 	MPEG-4 codec used in WarCraft 3 movies.*/
#define FOURCC_BT20		FOURCC(B,T,2,0)	/*Prosumer Video 	Conexant 	Codec optimised for realtime compression of YUV images. Download the ZIP and add VIDC.BT20=btvvc32.drv and VIDC.Y41P=btvvc32.drv to the [drivers32] section of your SYSTEM.INI to enable the codec*/
#define FOURCC_BTCV		FOURCC(B,T,C,V)	/*Composite Video Codec 	Conexant 	This, now obsolete, format supported a special data format used by the Brooktree Bt2115 chipset which could perform "software encoded video output" - a kind of software TV-out capability.*/
#define FOURCC_BW10		FOURCC(B,W,1,0)	/*Broadway MPEG Capture/Compression 	Data Translation 	Codec for Broadway hardware-based MPEG compression system.*/
#define FOURCC_CC12		FOURCC(C,C,1,2)	/*YUV12 Codec 	Intel 	?*/
#define FOURCC_CDVC		FOURCC(C,D,V,C)	/*Canopus DV Codec 	Canopus 	Allegedly used with digital video cameras. The Canopus download page has a free software-only version of this codec which will install on machines which are not equipped with their capture hardware. Apparently if you edit the AVI and change the		FOURCC to dvsd, it will play with these codecs too.*/
#define FOURCC_CFCC		FOURCC(C,F,C,C)	/*DPS Perception 	Digital Processing Systems 	Native format used when capturing AVIs using a DPS Perception adapter.*/
#define FOURCC_CGDI		FOURCC(C,G,D,I)	/*Camcorder Video 	Microsoft 	AVI format used by Office 97 camcorder application.*/
#define FOURCC_CHAM		FOURCC(C,H,A,M)	/*Caviara Champagne 	Winnov 	?*/
#define FOURCC_CMYK		FOURCC(C,M,Y,K)	/*Uncompressed CMYK 	Colorgraph 	Uncompressed 32bpp CMYK as used in printing processes.*/
#define FOURCC_CJPG		FOURCC(C,J,P,G)	/*WebCam JPEG 	Creative Labs 	Used by Creative Video Blaster Webcam Go control. See here for info on how to download and install this codec.*/
#define FOURCC_CPLA		FOURCC(C,P,L,A)	/*YUV 4:2:0 	Weitek 	This sounds like an uncompressed format to me. Anyone know?*/
#define FOURCC_CRAM		FOURCC(C,R,A,M)	/*Microsoft Video 1 	Microsoft 	Allegedly identical to MSVC.*/
#define FOURCC_CSCD		FOURCC(C,S,C,D)	/*CamStudio Codec 	RenderSoft
																				Software 	Open source (GPL license) codec optimised for screen capture applications.
																				Source download is available.*/
#define FOURCC_CVID		FOURCC(C,V,I,D)	/*Cinepak 	Providenza & Boekelheide 	Originally owned by Supermac then Radius, now P & B. Complete technical details can be found here.*/
#define FOURCC_CWLT		FOURCC(C,W,L,T)	/*Color WLT DIB 	Microsoft 	Apparently WLT is "with lookup table". Presumably, therefore, this is similar to a standard DIB using		FOURCC 0?*/
#define FOURCC_CYUV		FOURCC(C,Y,U,V)	/*Creative YUV 	Creative Labs 	Proprietary YUV compression algorithm*/
#define FOURCC_CYUY		FOURCC(C,Y,U,Y)	/*? 	ATI Technologies 	Proprietary YUV compression algorithm*/
#define FOURCC_D261		FOURCC(D,2,6,1)	/*H.261 	DEC 	Presumably now owned by Intel.*/
#define FOURCC_D263		FOURCC(D,2,6,3)	/*H.263 	DEC 	Presumably now owned by Intel.*/
#define FOURCC_davc		FOURCC(d,a,v,c)	/*MPEG-4/H.264 	Dicas 	H.264/MPEG-4 AVC base profile codec. Dicas tell me that this codec will be available for free download from their site some time in June 2004. I am waiting to hear the exact URL for the download.*/
#define FOURCC_DCL1		FOURCC(D,C,L,1)	/*Data Connection Conferencing Codec 	Data Connection Ltd. 	Format used in Data Connection Ltd's conferencing services.*/
#define FOURCC_DIV3		FOURCC(D,I,V,3)	/*DivX MPEG-4 	DivX 	Low motion codec (optimised for low motion source material?). Several sources tell me that this is an old and illegal codec that should not be used to encode new material.*/
#define FOURCC_DIV4		FOURCC(D,I,V,4)	/*DivX MPEG-4 	DivX 	Fast motion codec.Several sources tell me that this is an old and illegal codec that should not be used to encode new material.*/
#define FOURCC_DIV5		FOURCC(D,I,V,5)	/*? 	? 	Apparently almost as old as DIV3 and DIV4. Changing DIV5 AVI's		FOURCC to DIV3 or DIV4 seems to allow them to play just fine.*/
#define FOURCC_DIVX		FOURCC(D,I,V,X)	/*DivX 	OpenDivX 	This		FOURCC code is used for versions 4.0 and later of the DivX codec. DivX, "the MP3 of video,"	is the popular and market-leading MPEG-4 video codec that is emerging as the standard for full screen, full motion, DVD-quality video over IP-based networks.
																				Apparently version 5 also encodes using		FOURCC DX50.*/
#define FOURCC_divx		FOURCC(d,i,v,x)	/*DivX 	? 	Apparently used interchangeably with "DIVX".*/
#define FOURCC_DM4V		FOURCC(D,M,4,V)	/*MPEG-4 	Dicas 	MPEG4 codec compatible with DivX4 and 5.*/
#define FOURCC_dmb1		FOURCC(d,m,b,1)	/*Rainbow Runner hardware compression 	Matrox 	Hardware codec used by Matrox Rainbow Runner video capture product. Apparently a form of Motion JPEG).*/
#define FOURCC_DMB2		FOURCC(D,M,B,2)	/*? 	? 	MJPEG codec used by Paradigm.*/
#define FOURCC_DMK2		FOURCC(D,M,K,2)	/*? 	? 	Movies generated by a ViewSonic V36 PDA appear to be AVI files using this video codec. Oddly enough, they are named .mpg - go figure.*/
#define FOURCC_DSVD		FOURCC(D,S,V,D)	/*DV Codec 	? 	The DSVD codec is a VFW-based compressor that firewire- and DV-based capture cards use. It is supported by Graphedit (from divx-digest.com), Adobe Premier and StudioDV. VirtualDub doesn't support the format.
																				I suspect that this and DVSD are one and the same - perhaps one of my informants typed the		FOURCC wrongly?*/
#define FOURCC_DUCK		FOURCC(D,U,C,K)	/*TrueMotion S 	Duck Corporation 	Rather nice RGB codec which, strangely enough, appears to have two distinct		FOURCCs.*/
#define FOURCC_dv25		FOURCC(d,v,2,5)	/*DVCPRO 	Matrox 	SMPTE 314M 25Mb/s compressed video. A professional variant of DVC (dvsd). Unlike dvsd, it uses 4:1:1 sampling structure for both NTSC and PAL.*/
#define FOURCC_dv50		FOURCC(d,v,5,0)	/*DVCPRO50 	Matrox 	SMPTE 314M 50Mb/s compressed video. Has twice the data rate (50Mbits/sec) of dv25 and uses 4:2:2 sampling structure.*/
#define FOURCC_DVAN		FOURCC(D,V,A,N)	/*? 	? 	?*/
#define FOURCC_DVCS		FOURCC(D,V,C,S)	/*DV Video 	Microsoft? 	A generic DV codec along the same lines as DVSD. Microsoft indicates here that this codec should be considered obsolete now that standard		FOURCCs for the various DV flavours have been defined.*/
#define FOURCC_DVE2		FOURCC(D,V,E,2)	/*DVE-2 Videoconferencing Codec 	InSoft 	?*/
#define FOURCC_dvh1		FOURCC(d,v,h,1)	/*SMPTE 370M 	Panasonic? 	SMPTE 370M - data structure for DV based audio, data and compressed video at 100 Mb/s - 1080/60i, 1080/50i, and 720/60p. This is basically a high definition variant of dv25 and dv50.*/
#define FOURCC_dvhd		FOURCC(d,v,h,d)	/*50Mbps Consumer DV 	Microsoft? 	SD-DVCR 1125-60 or SD-DVCR 1250-50. See also dvsl and dvsd.*/
#define FOURCC_dvsd		FOURCC(d,v,s,d)	/*25Mbps Consumer DV 	Pinnacle Systems? 	SD-DVCR 525-60 or SD-DVCR 625-50. See also dvsl and dvhd.
																				Implemented in the miroVideo DV300 SW only codec which requires the presence of the 1394 (Firewire) interface card with which it shipped.*/
#define FOURCC_DVSD		FOURCC(D,V,S,D) /*DV Video 	Microsoft? 	Used by Adobe After Effects, Uleads Mediastudio 6 (and probably VideoStudio) as a generic DV		FOURCC. Probably the same as "dvsd". Sources indicate that these		FOURCCs were used interchangeably in early versions. Microsoft indicates here that this codec should be considered obsolete now that standard		FOURCCs for the various DV flavours have been defined.
																				Some versions include only decompression. If you need a compress/decompress DVSD codec, I am told that the MainConcept DV codec is worth a look and you can download a demo version here.*/
#define FOURCC_dvsl		FOURCC(d,v,s,l)	/*12.5Mbps Consumer DV 	Microsoft? 	SD-DVCR 525-60 or SD-DVCR 625-50. See also dvsd and dvhd.*/
#define FOURCC_DVX1		FOURCC(D,V,X,1)	/*DVX1000SP Video Decoder 	Lucent 	?*/
#define FOURCC_DVX2		FOURCC(D,V,X,2)	/*DVX2000S Video Decoder 	Lucent 	?*/
#define FOURCC_DVX3		FOURCC(D,V,X,3)	/*DVX3000S Video Decoder 	Lucent 	?*/
#define FOURCC_DX50		FOURCC(D,X,5,0)	/*DivX MPEG-4
																			version 5 	DivX 	Apparently this is used interchangeably with the DIVX		FOURCC when using version 5 of the codec.*/
#define FOURCC_DXGM		FOURCC(D,X,G,M)	/*? 	Electronic Arts? 	The movies in the game "Lord of the Rings: Return of the King" are encoded in this format. Also used in movies from "Robin Hood" by CinemaWare.*/
#define FOURCC_DXTn		FOURCC(D,X,T,n)	/*DirectX Compressed Texture 	Microsoft 	5 different versions (DXT1 - DXT5) of compressed texture formats exist. Full documentation is to be found in the DirectX SDK. More info can also be found on S3's Texture Compression web site.*/
#define FOURCC_DXTC		FOURCC(D,X,T,C)	/*DirectX Texture Compression 	Microsoft 	Another of the DXTn set, I suppose.*/
#define FOURCC_ELK0		FOURCC(E,L,K,0)	/*? 	Elsa 	Codec used by some Elsa graphics cards. May be a YUV format with reduced colour resolution.*/
#define FOURCC_EKQ0		FOURCC(E,K,Q,0)	/*Elsa Quick Codec 	Elsa 	?*/
#define FOURCC_EM2V		FOURCC(E,M,2,V)	/*Etymonix MPEG-2 Video 	Etymonix 	HIgh quality, MPEG-2 I picture codec with user selectable YUV 4:2:0, 4:2:2 or 4:4:4 compression. Suitable for use in video editing applications. Free trial version available.*/
#define FOURCC_ESCP		FOURCC(E,S,C,P)	/*Escape 	Eidos Technologies 	Codec used by Eidos Technologies ESCAPE VideoStudio.*/
#define FOURCC_ETV1		FOURCC(E,T,V,1)	/*eTreppid Video Codec 	eTreppid Technologies 	?*/
#define FOURCC_ETV2		FOURCC(E,T,V,2)	/*eTreppid Video Codec 	eTreppid Technologies 	?*/
#define FOURCC_ETVC		FOURCC(E,T,V,C)	/*eTreppid Video Codec 	eTreppid Technologies 	?*/
#define FOURCC_FFV1		FOURCC(F,F,V,1)	/*FFMPEG Codec 	Michael Niedermayer 	A lossless video codec based on arithmetic coding developed in the open source ffmpeg project.*/
#define FOURCC_FLJP		FOURCC(F,L,J,P)	/*Field Encoded Motion JPEG 	D-Vision 	Field encoded motion JPEG with LSI bitstream format.*/
#define FOURCC_FRWA		FOURCC(F,R,W,A)	/*Forward Motion JPEG with alpha channel 	SoftLab-Nsk 	A version of motion JPEG as used in the Forward project from SoftLab-Nsk. This format also includes an 8-bit alpha channel per image.*/
#define FOURCC_FRWD		FOURCC(F,R,W,D)	/*Forward Motion JPEG 	SoftLab-Nsk 	A version of motion JPEG as used in the Forward project from SoftLab-Nsk. Similar to FRWD but without the alpha information.*/
#define FOURCC_FVF1		FOURCC(F,V,F,1)	/*Fractal Video Frame 	Iterated Systems 	 */
#define FOURCC_GJPG		FOURCC(G,J,P,G)	/*GT891x Codec 	Grand Tech 	Shipped as part of the driver package with some dgital cameras from Fuji.*/
#define FOURCC_GLZW		FOURCC(G,L,Z,W)	/*Motion LZW 	gabest@freemail.hu 	GIF-like codec written by gabest@freemail.hu.*/
#define FOURCC_GPEG		FOURCC(G,P,E,G)	/*Motion JPEG 	gabest@freemail.hu 	Motion JPEG codec written as a learning exercise by gabest@freemail.hu.*/
#define FOURCC_GWLT		FOURCC(G,W,L,T)	/*Greyscale WLT DIB 	Microsoft 	8bpp greyscale image. WLT apparently means "with lookup table" so it is a palettized format.*/
#define FOURCC_H260		FOURCC(H,2,6,0)	/*through H269 	ITU H.26n 	Intel 	Conferencing codecs
																			H.263 format video is for POTS-based videoconferencing. Used, for example, in some Osprey products.
																			Supposedly, the Vanguard Software H.264 codec, available in beta form here, is pretty good.*/
#define FOURCC_HFYU		FOURCC(H,F,Y,U)	/*Huffman Lossless Codec 	? 	Huffman codec for YUV and RGB formats. Available in source and DLL forms. Full technical information can be found here. I am told that further information can also be found here.*/
#define FOURCC_HMCR		FOURCC(H,M,C,R)	/*Rendition Motion Compensation Format 	Rendition 	Proprietary motion compensation surface format used by Rendition V2x00 DirectDraw driver.*/
#define FOURCC_HMRR		FOURCC(H,M,R,R)	/*Rendition Motion Compensation Format 	Rendition 	Newer, proprietary motion compensation surface format used by Rendition drivers.*/
#define FOURCC_i263		FOURCC(i,2,6,3)	/*ITU H.263 	Intel 	PictureWorks NetCard Player - another H.263 implementation from Intel. There's a FAQ on this codec here and it can also be downloaded from here.*/
#define FOURCC_IAN		FOURCC(I,A,N, )	/*Indeo 4 Codec 	Intel 	One of a collection of		FOURCCs used in Indeo 4.*/
#define FOURCC_ICLB		FOURCC(I,C,L,B)	/*CellB Videoconferencing Codec 	InSoft 	?*/
#define FOURCC_IGOR		FOURCC(I,G,O,R)	/*Power DVD 	? 	?*/
#define FOURCC_IJPG		FOURCC(I,J,P,G)	/*Intergraph JPEG 	Intergraph 	Intergraph's version of a JPEG codec (don't you hate it when I just state the obvious ?)*/
#define FOURCC_ILVC		FOURCC(I,L,V,C)	/*Layered Video 	Intel 	?*/
#define FOURCC_ILVR		FOURCC(I,L,V,R)	/*ITU H.263+ Codec 	? 	?*/
#define FOURCC_IPDV		FOURCC(I,P,D,V)	/*Giga AVI DV Codec 	I-O Data Device, Inc. 	Codec used with I-O Data Device's IEEE1394 Digital Video Control & Capture Board. This codec implements I-O DATA's original indexed AVI architecture.*/
#define FOURCC_IR21		FOURCC(I,R,2,1)	/*Indeo 2.1 	Intel 	Old Indeo codec*/
#define FOURCC_IRAW		FOURCC(I,R,A,W)	/*Intel Uncompressed UYUV 	Intel 	No indication of the pixel format - sorry.*/
#define FOURCC_IV30		FOURCC(I,V,3,0)	/*through IV39 	Indeo 3 	Ligos 	The family of Indeo Video 3 codecs originally developed by Intel but now handled by Ligos.*/
#define FOURCC_IV32		FOURCC(I,V,3,2)	/*Indeo 3.2 	Ligos 	Fairly widespread Indeo 3 codec*/
#define FOURCC_IV40		FOURCC(I,V,4,0)	/*through IV49 	Indeo Interactive 	Ligos 	Indeo 4.1 improves image quality and introduces transparency masks.*/
#define FOURCC_IV50		FOURCC(I,V,5,0)	/*Indeo Interactive 	Ligos 	Version 5.0 of the Indeo codec series designed for internet video delivery.*/
#define FOURCC_JBYR		FOURCC(J,B,Y,R)	/*? 	Kensington? 	?*/
#define FOURCC_JPEG		FOURCC(J,P,E,G)	/*JPEG Still Image 	Microsoft 	?*/
#define FOURCC_JPGL		FOURCC(J,P,G,L)	/*JPEG Light? 	? 	Proprietary format used by many WebCams which are built around the DIVIO NW 801/802 chip such as the Logitec QuickCam Pro, VideoLogic HomeC@m and other cameras from Askey, Mustek, Microtek, and Tekom.*/
#define FOURCC_KMVC		FOURCC(K,M,V,C)	/*Karl Morton's Video Codec (presumably) 	? 	Shipped as part of the game "Worms" by Team17 Software. Info is allegedly obtainable from info@beamaim.demon.co.uk.*/
#define FOURCC_L261		FOURCC(L,2,6,1)	/*Lead H.26 	Lead Technologies 	?*/
#define FOURCC_L263		FOURCC(L,2,6,3)	/*Lead H.263 	Lead Technologies 	?*/
#define FOURCC_LBYR		FOURCC(L,B,Y,R)	/*? 	? 	?*/
#define FOURCC_LCMW		FOURCC(L,C,M,W)	/*Motion CMW Codec 	Lead Technologies 	?*/
#define FOURCC_LEAD		FOURCC(L,E,A,D)	/*LEAD Video Codec 	Lead Technologies 	Codec supporting standard MJPEG and Lead's proprietary MCMP formats. They state "an alternative to standard compression algorithms, MCMP delivers smaller file sizes and can maintain better image quality than MJPEG with the same or better image quality." Link offers download of a time-expiring version of the codec. No, MCMP isn't a		FOURCC.*/
#define FOURCC_LGRY		FOURCC(L,G,R,Y)	/*Grayscale Image 	Lead Technologies 	Supports 12 and 16bpp grayscale images with additional low and high range information required for medical images. Format public but not finalised when this update was made.*/
#define FOURCC_LJ2K		FOURCC(L,J,2,K)	/*Lead JPEG 2000 	Lead Technologies 	*/
#define FOURCC_Ljpg		FOURCC(L,j,p,g)	/*LEAD MJPEG Codec 	Lead Technologies 	Supports color JPEG 4:1:1, 4:2:2, 4:4:4, grayscale JPEG 4:0:0)		FOURCCs supported: MJPG, JPEG, dmb1 Lossless JPEG support including 24-bit color and 8,12 and 16-bit grayscale. Link offers download of a time-expiring version of the codec.*/
#define FOURCC_LZO1		FOURCC(L,Z,O,1)	/*Lempel-Ziv-Oberhumer Codec 	Markus Oberhumer 	A fast, lossless codec available in source code format.*/
#define FOURCC_M263		FOURCC(M,2,6,3)	/*H.263 	Microsoft 	Redmond's codec implementing the H.263 compression standard.*/
#define FOURCC_M261		FOURCC(M,2,6,1)	/*H.261 	Microsoft 	Redmond's codec implementing the H.261 compression standard.*/
#define FOURCC_M4CC		FOURCC(M,4,C,C)	/*m4cc 	MPEG-4 	Divio 	*/
#define FOURCC_M4S2		FOURCC(M,4,S,2)	/*MPEG-4 (automatic WMP download) 	Microsoft 	Final fully-compliant ISO MPEG4 decoder, compliant to MPEG-4 version 2 simple profile.*/
#define FOURCC_MC12		FOURCC(M,C,1,2)	/*Motion Compensation Format 	ATI Technologies 	Proprietary format used by ATI in MPEG decoding.*/
#define FOURCC_MCAM		FOURCC(M,C,A,M)	/*Motion Compensation Format 	ATI Technologies 	Proprietary format used by ATI in MPEG decoding.*/
#define FOURCC_MJ2C		FOURCC(M,J,2,C)	/*Motion JPEG 2000 	Morgan Multimedia 	Motion JPEG 2000*/
#define FOURCC_mJPG		FOURCC(m,J,P,G)	/*Motion JPEG including Huffman Tables 	IBM 	A version of Motion JPEG which includes Huffman tables with each AVI frame. Developed by IBM before the MJPEG standard was finalised.*/
#define FOURCC_MJPG		FOURCC(M,J,P,G)	/*Motion JPEG 	? 	Motion JPEG video. Codecs implementing MJPEG are (or have been) available from
																										* http://www.jpg.com/imagetech_video.htm
																										* http://www.pmatrix.com/
																										* Pegasus Imaging
																										* Morgan Multimedia (long trial period)

																				The format is also used by Matrox in their Rainbow Runner add-on video capture / MPEG playback board for various of their display adapters and by Canon who's cameras generate AVIs using this codec.*/
#define FOURCC_MMES		FOURCC(M,M,E,S)	/*MPEG-2 ES 	Matrox 	Matrox MPEG-2 video elementary stream.MPEG-2 main profile or 4:2:2 profile closed GOP IBP or I-frame only decoder.*/
#define FOURCC_MP2A		FOURCC(M,P,2,A)	/*Eval download 	Media Excel 	MPEG-2 Audio*/
#define FOURCC_MP2T		FOURCC(M,P,2,T)	/*Eval download 	Media Excel 	MPEG-2 Transport Stream*/
#define FOURCC_MP2V		FOURCC(M,P,2,V)	/*Eval download 	Media Excel 	MPEG-2 Video*/
#define FOURCC_MP42		FOURCC(M,P,4,2)	/*MPEG-4 (automatic WMP download) 	Microsoft 	Apparently one of several different and incompatible MPEG-4 codecs. Rumour has it that this codec is downloadable from the Microsoft site somewhere. This codec is distributed as part of Microsoft Windows Media Tools 4. Includes quality improvements over the earlier MPG4. Download as part of "Windows Media Codecs 8.0 for IT Professionals."*/
#define FOURCC_MP43		FOURCC(M,P,4,3)	/*MPEG-4 (automatic WMP download) 	Microsoft 	Yet another MPEG-4 variation from Microsoft. This		FOURCC is not, however, listed on Microsoft's codecs site. This codec is distributed as part of Microsoft Windows Media Tools 4. Includes further quality improvements over the earlier MPG4.*/
#define FOURCC_MP4A		FOURCC(M,P,4,A)	/*Eval download 	Media Excel 	MPEG-4 Audio*/
#define FOURCC_MP4S		FOURCC(M,P,4,S)	/*MPEG-4 (automatic WMP download) 	Microsoft ? 	The first ISO standard codec for use with the Sharp digital camera implementing a restricted feature set of MPEG4.*/
#define FOURCC_MP4T		FOURCC(M,P,4,T)	/*Eval download 	Media Excel 	MPEG-4 Transport Stream*/
#define FOURCC_MP4V		FOURCC(M,P,4,V)	/*Eval download 	Media Excel 	MPEG-4 Video*/
#define FOURCC_MPEG		FOURCC(M,P,E,G)	/*MPEG 	? 	MPEG video - presumably MPEG I ?*/
#define FOURCC_MPG4		FOURCC(M,P,G,4)	/*MPEG-4 (automatic WMP download) 	Microsoft 	MPEG-4 Video High Speed Compressor. Downloadable here, I am told. This codec was shipped with some versions of the Microsoft Netshow encoder (probably 3.0). This codec was based on early drafts of the MPEG-4 spec.*/
#define FOURCC_MPGI		FOURCC(M,P,G,I)	/*MPEG 	Sigma Designs 	Editable MPEG codec*/
#define FOURCC_MR16		FOURCC(M,R,1,6)	/*? 	? 	?*/
#define FOURCC_MRCA		FOURCC(M,R,C,A)	/*Mrcodec 	FAST Multimedia 	And I thought it stood for "Multi Role Combat Aircraft".*/
#define FOURCC_MRLE		FOURCC(M,R,L,E)	/*Microsoft RLE 	Microsoft 	Run length encoded RGB format from Microsoft. Basically the same as the BI_RLE formats but Michael Knapp clarifies:"MRLE is just *nearly* the same compression as the existing 4 and 8bit RLE formats but the 'copy bytes-chunk' always has an even byte-length. That means that an empty byte is added if the 'copy chunk' contains an odd number of bytes"*/
#define FOURCC_MSVC		FOURCC(M,S,V,C)	/*Microsoft Video 1 	Microsoft 	Original codec shipped with Video For Windows. Deals with 8bpp and 16bpp images. Quality leaves a lot to be desired (IMHO). Full technical details are available here.*/
#define FOURCC_MSZH		FOURCC(M,S,Z,H)	/*AVImszh 	Kenji Oshima 	Kenji Oshima also developed a multi-threaded M3JPEG codec based on one by Morgan Multimedia. You can download this here. Algorithm information can be found here. This is supposedly the same thing as ZLIB.*/
#define FOURCC_MTX1		FOURCC(M,T,X,1)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX2		FOURCC(M,T,X,2)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX3		FOURCC(M,T,X,3)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX4		FOURCC(M,T,X,4)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX5		FOURCC(M,T,X,5)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX6		FOURCC(M,T,X,6)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX7		FOURCC(M,T,X,7)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX8		FOURCC(M,T,X,8)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MTX9		FOURCC(M,T,X,9)	/*? 	Matrox 	Apparently these are MJPG variations registered by Matrox consumer products group.*/
#define FOURCC_MVI1		FOURCC(M,V,I,1)	/*Motion Pixels MVI1 Codec 	? 	Part of the Motion Pixels player. Install the player and the codec will become available to other multimedia applications. Read more at this site (look for Treasure Quest).*/
#define FOURCC_MVI2		FOURCC(M,V,I,2)	/*Motion Pixels MVI2 Codec 	? 	As for MVI1, this is part of the Motion Pixels player. Read more at this site.*/
#define FOURCC_MWV1		FOURCC(M,W,V,1)	/*Aware Motion Wavelets 	Aware Inc. 	Wavelet compression-based codec optimised for Intel MMX platforms. Allegedly downloadable from here. Codec filename is icmw_32.dll.*/
#define FOURCC_nAVI		FOURCC(n,A,V,I)	/*Download here 	? 	?*/
#define FOURCC_NTN1		FOURCC(N,T,N,1)	/*Video Compression 1 	Nogatech/Zoran 	?*/
#define FOURCC_NTN2		FOURCC(N,T,N,2)	/*Video Compression 2 	Nogatech/Zoran 	An evolution of NTN1.*/
#define FOURCC_NVDS		FOURCC(N,V,D,S)	/*NVidia Texture Format 	NVidia 	?*/
#define FOURCC_NVHS		FOURCC(N,V,H,S)	/*NVidia Texture Format 	NVidia 	Apparently a texture format introduced for GEForce 3.*/
#define FOURCC_NHVU		FOURCC(N,H,V,U)	/*NVidia Texture Format 	NVidia 	Apparently a texture format introduced for GEForce 3.*/
#define FOURCC_NVS0		FOURCC(N,V,S,0)
#define FOURCC_NVS1		FOURCC(N,V,S,1)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVS2		FOURCC(N,V,S,2)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVS3		FOURCC(N,V,S,3)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVS4		FOURCC(N,V,S,4)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVS5		FOURCC(N,V,S,5)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVT0		FOURCC(N,V,T,0)
#define FOURCC_NVT1		FOURCC(N,V,T,1)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVT2		FOURCC(N,V,T,2)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVT3		FOURCC(N,V,T,3)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVT4		FOURCC(N,V,T,4)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_NVT5		FOURCC(N,V,T,5)	/*? 	NVidia? 	Supported by GEForce 2 GTS Pro / 64Mb DDR. Possibly a texture format.*/
#define FOURCC_PDVC		FOURCC(P,D,V,C)	/*DVC codec 	I-O Data Device, Inc. 	DV codec for I-O DATA Digital Video Capture products.*/
#define FOURCC_PGVV		FOURCC(P,G,V,V)	/*Radius Video Vision 	Radius 	?*/
#define FOURCC_PHMO		FOURCC(P,H,M,O)	/*Photomotion 	IBM 	?*/
#define FOURCC_PIM1		FOURCC(P,I,M,1)	/*Download here 	Pinnacle Systems 	MPEG-1 based codec*/
#define FOURCC_PIM2		FOURCC(P,I,M,2)	/*? 	Pinnacle Systems 	Pinnacle DC1000 firewire video editing card supports this format.*/
#define FOURCC_pimj		FOURCC(p,i,m,j)	/*Pegasus Lossless JPEG 	Pegasus Imaging 	High speed compression and decompression of 24-bit RGB and 8-bit grayscale using Predictor 1 Lossless JPEG. Well suited for medical video. You may find additional information here.*/
#define FOURCC_PIXL		FOURCC(P,I,X,L)	/*Video XL 	Pinnacle Systems 	This is apparently an alias for VIXL.*/
#define FOURCC_PVEZ		FOURCC(P,V,E,Z)	/*PowerEZ 	Horizons Technology 	TrueMotion based codec (?) It appears that Horizons Technology has now been acquired by Raytheon and is no longer in the codec business (can someone confirm this - their URL is now redirected). Allegedly, you can download this codec from support.private.com but I'm not going to add a link since this is an adult video company and I don't want to get this site associated with porn.*/
#define FOURCC_PVMM		FOURCC(P,V,M,M)	/*PacketVideo Corporation MPEG-4 	PacketVideo Corporation 	Software MPEG4 codec that supports multiple bitrate encoding/decoding. It is also error resilient allowing transmission over wired/wireless networks.*/
#define FOURCC_PVW2		FOURCC(P,V,W,2)	/*Pegasus Wavelet 2000 Compression 	Pegasus Imaging 	High speed compression and decompression of 24-bit RGB and 8-bit grayscale using Pegasus' proprietary Wavelet2000 wavelet technology. Well suited for low motion, low bandwidth applications. More information is available here.*/
#define FOURCC_qpeq		FOURCC(q,p,e,q)	/*QPEG 1.1 	Q-Team 	?*/
#define FOURCC_QPEG		FOURCC(Q,P,E,G)	/*QPEG 	Q-Team 	Q-Team Dr.Knabe's 8-bit output codec with automatic palette switching for seamless edits.*/
#define FOURCC_rle		FOURCC(r,l,e, )	/*Apple Animation 	Apple 	Yes this really is lower case. This format is used to compress Quicktime files. Available in 1, 2, 4, 8, 16, 24 and 32bit flavors.*/
#define FOURCC_RLE		FOURCC(R,L,E, )	/*Run Length Encoder 	Microsoft? 	I expect this is an equivalent to one of the the BI_RLEx		FOURCCs (see the RGB page). The Win2K clock.avi sample uses this format. Final character in the		FOURCC is a space.*/
#define FOURCC_RLE4		FOURCC(R,L,E,4)	/*4bpp Run Length Encoder 	Microsoft 	Equivalent to BI_RLE4. See RGB page for more details.*/
#define FOURCC_RLE8		FOURCC(R,L,E,8)	/*8bpp Run Length Encoder 	Microsoft 	Equivalent to BI_RLE8. See RGB page for more details.*/
#define FOURCC_RMP4		FOURCC(R,M,P,4)	/*MPEG-4 AS Profile Codec 	Sigma Designs 	Press release here describes this codec.*/
#define FOURCC_RPZA		FOURCC(R,P,Z,A)	/*Apple Video 	Apple 	RGB555 block-based codec used in Quicktime files.*/
#define FOURCC_RT21		FOURCC(R,T,2,1)	/*Real Time Video 2.1 	Intel 	What Indeo was called before the marketing guys got their hands on it. RTV or Real Time Video was the format produced by Intel's ActionMedia II adapter back in the late 80s. When the 80486 came along, this migrated to the software-decodable Indeo formats used today.*/
#define FOURCC_rv20		FOURCC(r,v,2,0)	/*RealVideo G2 	Real 	RealVideo G2 (6.0 and greater versions of the player and encoder)*/
#define FOURCC_rv30		FOURCC(r,v,3,0)	/*RealVideo 8 	Real 	*/
#define FOURCC_RV40		FOURCC(R,V,4,0)	/*RealVideo 10? 	Real 	I'm not entirely sure about this one but someone tells me that an AVI encoded with RV40 became playable after installing RealPlayer 10.*/
#define FOURCC_RVX		FOURCC(R,V,X, )	/*RDX 	Intel 	?*/
#define FOURCC_s422		FOURCC(s,4,2,2)	/*VideoCap C210*/
#define FOURCC_YUV		FOURCC(Y,U,V, )	/*Codec 	Tekram International 	YUV422 codec shipped as part of the driver package for Tekram's C210 product.*/
#define FOURCC_SAN3		FOURCC(S,A,N,3)	/*DivX 3 	? 	A direct copy of DivX 3.11a, apparently. If you use a		FOURCC changer tool on these AVIs they will play with the standard DivX codecs.*/
#define FOURCC_SDCC		FOURCC(S,D,C,C)	/*Digital Camera Codec 	Sun Communications 	?*/
#define FOURCC_SEDG		FOURCC(S,E,D,G)	/*Samsung MPEG-4 	Samsung 	MPEG-4 hardware and software codec used in Samsung digital video products.*/
#define FOURCC_SFMC		FOURCC(S,F,M,C)	/*Surface Fitting Method 	CrystalNet 	CrystalGram video email codec.*/
#define FOURCC_SMC		FOURCC(S,M,C, )	/*Apple Graphics 	Apple 	8-bit, block-based codec used in Quicktime files.*/
#define FOURCC_SMSC		FOURCC(S,M,S,C)	/*Proprietary codec 	Radius 	?*/
#define FOURCC_SMSD		FOURCC(S,M,S,D)	/*Proprietary codec 	Radius 	?*/
#define FOURCC_smsv		FOURCC(s,m,s,v)	/*Wavelet Video 	WorldConnect (corporate site) 	Windows 95 codec installed automatically (and without warning) whenever you receive and play back a file sent from VisualMail. Very low bandwidth format.*/
#define FOURCC_SP40		FOURCC(S,P,4,0)	/*? 	SunPlus 	Appears to be an uncompressed YUV format of some kind but I have no information on this other than that.*/
#define FOURCC_SP44		FOURCC(S,P,4,4)	/*? 	SunPlus 	Presumably a precursor to SP54?*/
#define FOURCC_SP54		FOURCC(S,P,5,4)	/*? 	SunPlus 	Apparently a form of MJPEG but with some header or other missing. Software shipped with a number of low end digital cameras and webcams such as Aiptek's Pocketcam digital still camera, Logitech's ClickSmart and Mustek's gSmart mini 2 use this format. These use SunPlus chipsets so presumably this explains the "SP".You can download a tool that will convert this to MJPEG here.*/
#define FOURCC_SPIG		FOURCC(S,P,I,G)	/*Spigot 	Radius 	?*/
#define FOURCC_SQZ2		FOURCC(S,Q,Z,2)	/*VXTreme Video Codec V2 	Microsoft 	?*/
#define FOURCC_SV10		FOURCC(S,V,1,0)	/*Video R1 	Sorenson Media 	Allegedly popular as a Quicktime codec. Used for trailer videos on Star Wars Episode 1 and other games.*/
#define FOURCC_STVA		FOURCC(S,T,V,A)	/*ST CMOS Imager Data (Bayer) 	ST Microelectronics 	Data from ST CMOS Imagers that is passed to a codec external to the driver for processing to a displayable format. More info may be available at the ST Vision and Imaging Unit web site.*/
#define FOURCC_STVB		FOURCC(S,T,V,B)	/*ST CMOS Imager Data (Nudged Bayer) 	ST Microelectronics 	Data from ST CMOS Imagers that is passed to a codec external to the driver for processing to a displayable format. More info may be available at the ST Vision and Imaging Unit web site.*/
#define FOURCC_STVC		FOURCC(S,T,V,C)	/*ST CMOS Imager Data (Bunched) 	ST Microelectronics 	Data from ST CMOS Imagers that is passed to a codec external to the driver for processing to a displayable format. More info may be available at the ST Vision and Imaging Unit web site.*/
#define FOURCC_STVX		FOURCC(S,T,V,X)	/*ST CMOS Imager Data (Extended CODEC Data Format) 	ST Microelectronics 	Data from ST CMOS Imagers that is passed to a codec external to the driver for processing to a displayable format. More info may be available at the ST Vision and Imaging Unit web site.*/
#define FOURCC_STVY		FOURCC(S,T,V,Y)	/*ST CMOS Imager Data (Extended CODEC Data Format with Correction Data) 	ST Microelectronics 	Data from ST CMOS Imagers that is passed to a codec external to the driver for processing to a displayable format. More info may be available at the ST Vision and Imaging Unit web site.*/
#define FOURCC_SVQ1		FOURCC(S,V,Q,1)	/*Sorenson Video 1 	Sorenson Media 	Hierarchicial adaptive multistage vector quantizer with mean removal and interframe motion compensation. Used in Quicktime. Complete technical details can be found here.*/
#define FOURCC_SVQ3		FOURCC(S,V,Q,3)	/*Sorenson Video 3 	Sorenson Media 	Video codec used in Quicktime files. A variant of H.264*/
#define FOURCC_TLMS		FOURCC(T,L,M,S)	/*Motion Intraframe Codec 	TeraLogic 	?*/
#define FOURCC_TLST		FOURCC(T,L,S,T)	/*Motion Intraframe Codec 	TeraLogic 	?*/
#define FOURCC_TM20		FOURCC(T,M,2,0)	/*TrueMotion 2.0 	Duck Corporation 	Version 2.0 of Duck Corp's Truemotion codec.*/
#define FOURCC_TM2X		FOURCC(T,M,2,X)	/*TrueMotion 2X 	Duck Corporation 	Duck Corp's follow-on codec after TM20.*/
#define FOURCC_TMIC		FOURCC(T,M,I,C)	/*Motion Intraframe Codec 	TeraLogic 	?*/
#define FOURCC_TMOT		FOURCC(T,M,O,T)	/*TrueMotion S 	Horizons Technology 	Another		FOURCC for TrueMotion S. This relates to the version of the codec licensed by Horizons Technology and is not compatible with DUCK.*/
#define FOURCC_TR20		FOURCC(T,R,2,0)	/*TrueMotion RT 2.0 	Duck Corporation 	Realtime version of TrueMotion.*/
#define FOURCC_TSCC		FOURCC(T,S,C,C)	/*TechSmith Screen Capture Codec 	Techsmith Corp. 	Codec used by the Camtasia Screen "camcorder" application.*/
#define FOURCC_TV10		FOURCC(T,V,1,0)	/*Tecomac Low-Bit Rate Codec 	Tecomac, Inc. 	?*/
#define FOURCC_TVJP		FOURCC(T,V,J,P)	/*? 	Pinnacle/Truevision 	Used by the Targa 2000 board.*/
#define FOURCC_TVMJ		FOURCC(T,V,M,J)	/*? 	Pinnacle/Truevision 	Used by the Targa 2000 board.*/
#define FOURCC_TY2C		FOURCC(T,Y,2,C)	/*Trident Decompression Driver 	Trident Microsystems 	?*/
#define FOURCC_TY2N		FOURCC(T,Y,2,N)	/*? 	Trident Microsystems 	?*/
#define FOURCC_TY0N		FOURCC(T,Y,0,N)	/*? 	Trident Microsystems 	?*/
#define FOURCC_UCOD		FOURCC(U,C,O,D)	/*ClearVideo 	eMajix.com 	Fractal compression-based video codec available as a Video for Windows codec and in the ClearFusion Netscape plugin package.*/
#define FOURCC_ULTI		FOURCC(U,L,T,I)	/*Ultimotion 	IBM Corp. 	Shipped with OS/2 but also available for Video for Windows. Link is to a very old version of the codec for Windows.*/
#define FOURCC_V210		FOURCC(V,2,1,0)	/*10-bit 4:2:2 Component YCbCr 	AJA Video Systems 	Uncompressed format supported by AJA Video Systems Xena adapter.*/
#define FOURCC_V261		FOURCC(V,2,6,1)	/*Lucent VX2000S 	Lucent 	?*/
#define FOURCC_V655		FOURCC(V,6,5,5)	/*YUV 4:2:2 	Vitec Multimedia 	Component ordering and packing unknown. Can you help?*/
#define FOURCC_VCR1		FOURCC(V,C,R,1)	/*ATI Video Codec 1 	ATI Technologies 	Codec used by some ATI TV-PC products. The link here allows you to download a version which is not specific to ATI hardware, allowing videos captured on an ATI-enabled system to be played back elsewhere.*/
#define FOURCC_VCR2		FOURCC(V,C,R,2)	/*ATI Video Codec 2 	ATI Technologies 	Codec used by some ATI TV-PC products. As for VCR1, this link is for a non-ATI specific version of the codec.*/
#define FOURCC_VCR3		FOURCC(V,C,R,3)	/*ATI Video Codecs 	ATI Technologies 	Registered for ATI Video Codecs version 3-9. I'm not sure these actually exist but the registrations are valid.*/
#define FOURCC_VCR4		FOURCC(V,C,R,4)
#define FOURCC_VCR5		FOURCC(V,C,R,5)
#define FOURCC_VCR6		FOURCC(V,C,R,6)
#define FOURCC_VCR7		FOURCC(V,C,R,7)
#define FOURCC_VCR8		FOURCC(V,C,R,8)
#define FOURCC_VDCT		FOURCC(V,D,C,T)	/*VideoMaker Pro DIB 	Vitec Multimedia 	16bpp format - no information on colour space, packing or component ordering.*/
#define FOURCC_VDOM		FOURCC(V,D,O,M)	/*VDOWave 	VDONet 	Another streaming video format from VDONet.*/
#define FOURCC_VDOW		FOURCC(V,D,O,W)	/*VDOLive 	VDONet 	H.263 internet streaming video format. Allegedly to be used (being used ?) by Microsoft in it's NetShow offering.*/
#define FOURCC_VDTZ		FOURCC(V,D,T,Z)	/*VideoTizer YUV Codec 	Darim Vision Co. 	Codec used to store YUV AVIs captured with Darim Vision's VideoTizer product.*/
#define FOURCC_VGPX		FOURCC(V,G,P,X)	/*VideoGramPix 	Alaris 	Alaris VGPixel 32-bit AVI compression driver. It seems that this codec is installed along with the software for the "Alaris Wee Cam."	The codec doesn't appear to be available separately but, allegedly, works fine if you install the Wee Cam software even without the camera. You may also find some information at http://www.alaris.com/vg_tech/vg_tchtx.htm and http://www.videogram.com/.*/
#define FOURCC_VIFP		FOURCC(V,I,F,P)	/*VFAPI Codec 	? 	Take a look at http://www.doom9.org/ where you may find more information.*/
#define FOURCC_VIDS		FOURCC(V,I,D,S)	/*? 	Vitec Multimedia 	YUV 4:2:2 CCIR 601 for V422 (no, I don't understand this either)*/
#define FOURCC_VIVO		FOURCC(V,I,V,O)	/*Vivo H.263 	Vivo Software 	Vivo's version of the videoconferencing "standard" H.263 compression format (version 2.0.0).*/
#define FOURCC_VIXL		FOURCC(V,I,X,L)	/*Video XL 	Miro (now part of Pinnacle Systems) 	Used my MiroVideo products such as the DC10, DC20, DC30, etc. A motion JPEG format that is accelerated in hardware with the Zoran chipset*/
#define FOURCC_VLV1		FOURCC(V,L,V,1)	/*? 	VideoLogic 	Codec probably used in VideoLogic's Captivator product line*/
#define FOURCC_VP30		FOURCC(V,P,3,0)	/*VP3 	On2 	On2 tell me "On2's VP3 codec will encode video into a VP3 file in multiple bit rates (roughly 220 Kbps, 330 Kbps, and 440 Kbps) and at optimum frame rates (usually 29.97 fps). This multiple bit rate file allows the TrueCast server to scale dynamically and smoothly as bandwidth congestion increases and decreases, providing the viewer with a consistent and reliable experience, without choppiness or interruption."*/
#define FOURCC_VP31		FOURCC(V,P,3,1)	/*VP31 	On2 	The successor to VP30. This algorithm was open sourced by On2 in 2001-2002 and is the basis for the Theora Video Codec. Technical details are available here.*/
#define FOURCC_VP40		FOURCC(V,P,4,0)	/*VP40 	On2 	Another in On2/Duck's line of video codecs.*/
#define FOURCC_VP50		FOURCC(V,P,5,0)	/*VP50 	On2 	..and another*/
#define FOURCC_VP60		FOURCC(V,P,6,0)	/*VP60 	On2 	..and another*/
#define FOURCC_VP61		FOURCC(V,P,6,1)	/*VP61 	On2 	..I can feel a pattern developing.*/
#define FOURCC_VP62		FOURCC(V,P,6,2)	/*VP62 	On2 	..I wonder which one will be next?*/
#define FOURCC_VQC1		FOURCC(V,Q,C,1)	/*VideoQuest Codec 1 	ViewQuest 	Digital video camera codec. ViewQuest offer lots of driver downloads on their site so you may find this in one of those packages.*/
#define FOURCC_VQC2		FOURCC(V,Q,C,2)	/*VideoQuest Codec 2 	ViewQuest 	Codec apparently used in Kodak DVC325 digital camera. Check the ViewQuest site download page - you may find the codec there somewhere.*/
#define FOURCC_VQJC		FOURCC(V,Q,J,C)	/*? 	? 	?*/
#define FOURCC_vssv		FOURCC(v,s,s,v)	/*VSS Video 	Vanguard Software Solutions 	Real-time or near-real-time encoding with high compression ratios and good image quality.*/
#define FOURCC_VUUU		FOURCC(V,U,U,U)	/*? 	? 	?*/
#define FOURCC_VX1K		FOURCC(V,X,1,K)	/*VX1000S Video Codec 	Lucent 	?*/
#define FOURCC_VX2K		FOURCC(V,X,2,K)	/*VX2000S Video Codec 	Lucent 	?*/
#define FOURCC_VXSP		FOURCC(V,X,S,P)	/*VX1000SP Video Codec 	Lucent 	?*/
#define FOURCC_VYU9		FOURCC(V,Y,U,9)	/*ATI YUV 	ATI Technologies 	Planar YUV format supported by some ATI capture systems?*/
#define FOURCC_VYUY		FOURCC(V,Y,U,Y)	/*ATI YUV 	ATI Technologies 	Packed YUV format supported by some ATI capture systems?*/
#define FOURCC_WBVC		FOURCC(W,B,V,C)	/*W9960 	Winbond Electronics 	?*/
#define FOURCC_WHAM		FOURCC(W,H,A,M)	/*Microsoft Video 1 	Microsoft 	Yet another		FOURCC describing Microsoft's MSVC/CRAM codec.*/
#define FOURCC_WINX		FOURCC(W,I,N,X)	/*Winnov Software Compression 	Winnov 	Software codec used by some Winnov Videum products.*/
#define FOURCC_WJPG		FOURCC(W,J,P,G)	/*Winbond JPEG? 	? 	Format supported by AverMedia USB TV-tuner/capture device. When downloading, look for the file USBTV20.ZIP.*/
#define FOURCC_WMV1		FOURCC(W,M,V,1)	/*Windows Media Video 7 	Microsoft 	*/
#define FOURCC_WMV2		FOURCC(W,M,V,2)	/*Windows Media Video 8 	Microsoft 	*/
#define FOURCC_WMV3		FOURCC(W,M,V,3)	/*Windows Media Video 9 	Microsoft 	You may find other useful information here.*/
#define FOURCC_WNV1		FOURCC(W,N,V,1)	/*Winnov Hardware Compression 	Winnov 	Hardware codec used by Winnov Videum products.*/
#define FOURCC_x263		FOURCC(x,2,6,3)	/*Download here 	Xirlink 	Another H.263 codec. This one is apparently used by an IBM-branded webcam.*/
#define FOURCC_X264		FOURCC(X,2,6,4)	/*XiWave H.264 	XiWave 	XiWave's planned implementation of the ITU H.264 video codec standard known as MPEG Part 10. Typically offers up to two times the compression ratio of existing MPEG-4 and four times that delivered by MPEG-2.*/
#define FOURCC_XVID		FOURCC(X,V,I,D)	/*XVID MPEG-4 	XVID 	Codec is available in source form from XVID web site. Can also be downloaded as part of the Gordian Knot Codec Pack.*/
#define FOURCC_XLV0		FOURCC(X,L,V,0)	/*XL Video Decoder 	NetXL Inc. 	?*/
#define FOURCC_XMPG		FOURCC(X,M,P,G)	/*XING MPEG 	XING Corporation 	Editable (I frame only) MPEG codec*/
#define FOURCC_XWV0		FOURCC(X,W,V,0)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV1		FOURCC(X,W,V,1)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV2		FOURCC(X,W,V,2)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV3		FOURCC(X,W,V,3)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV4		FOURCC(X,W,V,4)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV5		FOURCC(X,W,V,5)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV6		FOURCC(X,W,V,6)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV7		FOURCC(X,W,V,7)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV8		FOURCC(X,W,V,8)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XWV9		FOURCC(X,W,V,9)	/*XiWave Video Codec 	XiWave 	XWV3 is currently used to describe Xi-3 Video. Others are unused.*/
#define FOURCC_XXAN		FOURCC(X,X,A,N)	/*? 	Origin? 	Codec useing Huffman and RLE encoding paired with basic interframing. This format is used in Wing Commander 3 and 4 movies The codec filename is xanlib.dll and a player, xanmovie, is available on the the Kilrathi Saga and Crusader game CDs.*/
#define FOURCC_Y411		FOURCC(Y,4,1,1)	/*YUV 4:1:1 	Microsoft 	Supposedly 16bpp packed but 4:1:1 is usually 12bpp - odd. This is an uncompressed YUV format.*/
#define FOURCC_Y41P		FOURCC(Y,4,1,P)	/*Brooktree YUV 4:1:1 	Conexant 	This is an uncompressed YUV 411 format I registered about 7 years ago. I've stumbled on a few AVIs that use it, though, so I am listing it here. Download the ZIP and add VIDC.BT20=btvvc32.drv and VIDC.Y41P=btvvc32.drv to the [drivers32] section of your SYSTEM.INI to enable the codec*/
#define FOURCC_Y444		FOURCC(Y,4,4,4)	/*? 	? 	Format provided by the Windows 2000 drivers for the iRez Stealth Fire camera. Seems to be a copy of IYU2.*/
#define FOURCC_Y8			FOURCC(Y,8, , )	/*Grayscale video 	? 	Probably a duplicate of the uncompressed Y800 format. The 2 last characters are spaces. See also GREY which appears to be another duplicate*/
#define FOURCC_YC12		FOURCC(Y,C,1,2)	/*YUV 12 codec 	Intel 	?*/
#define FOURCC_YUV8		FOURCC(Y,U,V,8)	/*Caviar YUV8 	Winnov 	?*/
#define FOURCC_YUVP		FOURCC(Y,U,V,P)	/*? 	? 	An uncompressed YCrCb 4:2:2 format using 10-bit precision components ordered Y0 U0 Y1 V0. I have no idea how the 10 bit samples are packed - sorry.*/
#define FOURCC_YUY2		FOURCC(Y,U,Y,2)	/*Raw, uncompressed YUV 4:2:2 	Microsoft (probably) 	Yes, I know this isn't a compressed format but I get so many questions about where to find a codec for YUY2 AVIs that it's here to allow people to find the answer easily. I'm told "VirtualDub has been able to decode YUY2 internally since V1.3a. Newer versions of Ben Rudiak-Gould's Huffyuv codec will also convert YUY2 or UYVY data to RGB"*/
#define FOURCC_YV16		FOURCC(Y,V,1,6)	/*YUV 4:2:2 Planar 	Elecard 	Uncompressed format similar to YV12 but with twice the chroma resolution.*/
#define FOURCC_YV92		FOURCC(Y,V,9,2)	/*? 	Intel 	Codec used by Intel's Smart Video Recorder product. Apparently a compresssed YVU9 format.*/
#define FOURCC_ZLIB		FOURCC(Z,L,I,B)	/*? 	? 	A generic lossless codec that you can download from here. Apparently also contains the MSZH codec. Algorithm info can be found here. May be the same algorithm used in compressing PNG images.*/
#define FOURCC_ZPEG		FOURCC(Z,P,E,G)	/*Video Zipper 	Metheus 	?*/
#define FOURCC_ZyGo		FOURCC(Z,y,G,o)	/*ZyGoVideo 	ZyGo Digital 	Video codec usually packaged in Quicktime files. Investigations suggest that it may be a variant of H.263.*/
#define FOURCC_ZYYY		FOURCC(Z,Y,Y,Y)	/*? 	? 	?*/
