/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of version 2.1 of the GNU Lesser General Public
* License as published by the Free Software Foundation.
*
* This program is distributed in the hope that it would be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* Further, this software is distributed without any warranty that it
* is free of the rightful claim of any third person regarding
* infringement or the like.  Any license provided herein, whether
* implied or otherwise, applies only to this software file.  Patent
* licenses, if any, provided herein do not apply to combinations of
* this program with other software, or any other product whatsoever.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307,
* USA.
*
************************************************************************/

#define __ML_MODULES

#include "OpenML/OpenML.h"
#include <unistd.h>

u_int64_t id=0;

int open_called=0;
int close_called=0;

//this should cause the plugin load to fail
int32_t
PvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
				MLpv** capabilities) {return 1; }
int32_t _mlOpen  (struct mlID* id, MLpv *options) {return 1;}
int32_t _mlClose (struct mlID* openid){return 1;}
int32_t GetControls 	( struct mlID* openid, MLpv* controls) {return 1;}
int32_t SetControls 	( struct mlID* openid, MLpv* controls) {return 1;}
int32_t GetReceiveWaitHandle( struct mlID* openid,	MLwaitable* handle)
	{return 1;}
int32_t BeginTransfer( struct mlID* openid	) {return 1;}
int32_t EndTransfer	( struct mlID* openid	) {return 1;}
int32_t XcodeWork		( struct mlID* codec	) {return 1;}

struct mlID fwd_dev={
	.mlPvGetCapabilities	=	PvGetCapabilities,
	.mlOpen								=	_mlOpen,
	.mlClose							=	_mlClose,
	.mlGetControls				=	GetControls,
	.mlSetControls				= SetControls,
	.mlGetReceiveWaitHandle =GetReceiveWaitHandle,
	.mlBeginTransfer 			=BeginTransfer,
	.mlEndTransfer 				=EndTransfer,
	.mlXcodeWork					=NULL,//this will cause loading to fail
	};

//this is the standard initialization function
u_int32_t module_init(int argc, char** argv)
{
	fprintf(stderr, "initializing mlplugin-failed9\n");
	return mlDeviceRegister(&fwd_dev);
}

