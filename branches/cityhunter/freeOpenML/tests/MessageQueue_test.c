/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#include <OpenML/mlMessageQueue.h>
#include <OpenML/mlsdk.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

MLpv message1[2];
MLpv message2[2];
MLpv message3[3];
MLpv message4[4];

int main (int argc, char** argv)
{
	struct mlMessageQueue queue;
	MLpv* message;
	int32_t length;

	if (mlInitMQueue(&queue))
		return errno;
	message1[0].param=ML_TYPE_INT64;
	message1[0].value.int64=1;
	message1[1].param=ML_END;
	message2[0].param=ML_TYPE_INT32;
	message2[0].value.int32=2;
	message2[1].param=ML_END;
	message3[0].param=ML_TYPE_INT64;
	message3[0].value.int64=8;
	message3[1].param=ML_TYPE_INT32;
	message3[0].value.int32=1;
	message3[2].param=ML_END;
	message4[0].param=ML_TYPE_INT32;
	message4[0].value.int32=5;
	message4[1].param=ML_TYPE_INT64;
	message4[0].value.int64=7;
	message4[2].param=ML_TYPE_INT32;
	message4[0].value.int32=9;
	message4[3].param=ML_END;

	if (mlCopyPushMQueue(&queue,message1,0)) return 1;
	if (mlCopyPopMQueue(&queue,&message,&length,NULL)) return 2;
	if (length != 2 ) return 3;
	if (memcmp( (void*) message1, (void*) message, 2*sizeof(MLpv))) return 4;
	mlFreeCapabilities(message);
	if (mlCopyPushMQueue(&queue,message2,0)) return 5;
	if (mlCopyPushMQueue(&queue,message4,0)) return 6;
	if (mlCopyPushMQueue(&queue,message3,0)) return 7;
	if (mlCopyPopMQueue(&queue,&message,&length,NULL)) return 8;
	if (length != 2 ) return 9;
	if (memcmp( (void*) message2, (void*) message, 2*sizeof(MLpv))) return 10;
	mlFreeCapabilities(message);
	if (mlCopyPopMQueue(&queue,&message,&length,NULL)) return 11;
	if (length != 4 ) return 12;
	if (memcmp( (void*) message4, (void*) message, 4*sizeof(MLpv))) return 13;
	mlFreeCapabilities(message);
	if (mlCopyPopMQueue(&queue,&message,&length,NULL)) return 14;
	if (length != 3 ) return 15;
	if (memcmp( (void*) message3, (void*) message, 3*sizeof(MLpv))) return 16;
	mlFreeCapabilities(message);
	return 0;
}
