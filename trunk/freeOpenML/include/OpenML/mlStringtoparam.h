/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/

	
struct mlparamtoname {
	u_int64_t param;
	char* name;
	u_int8_t length;
	};

#define CONSTRUCT_NAME_ARRAY(NAME) {NAME, #NAME, sizeof(#NAME)},

extern const struct mlparamtoname params[];
#define ML_PARAM_COUNT 123
