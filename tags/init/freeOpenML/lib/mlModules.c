/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/



#define __ML_MODULES
#include <stdlib.h>
#include <OpenML/OpenML.h>


/** helper converter that convert the pointer to the devices descriptors structures array
 * into ids array
 * @param count : the number of subdevices the array contains
 * @param type : the type of the IDS
 * @param deviceArray : a general void pointer to the array
 * @param newMessage : the message to modify
 * @return field writen on success else 0 and set errno
 */
inline int32_t
pointerArrayToIds(u_int32_t count,u_int64_t type,void* deviceArray,
									MLpv* newMessage) 
{
	int j;
	errno=0;
	struct system_desc** ids=(struct system_desc**) deviceArray;
	if (count)
		{
			newMessage->param=type;
			newMessage->value.pInt64=malloc(sizeof(u_int64_t)*count);
			if (newMessage->value.pInt64 == NULL)
				goto err;
			for (j=0; j<count; j++)
				{
					newMessage->value.pInt64[j]=ids[j]->id;
				}
			newMessage->length=count;
			return 1;
		}
	return 0;
	
	err:
		if (newMessage->value.pByte != NULL)
			free(newMessage->value.pByte);
		return 0;
}

/** helper converter that copy double '\0' terminated strings
 * @param size : the size of the array
 * @param type : the parameter type of the message
 * @param feats : the double \0 terminated string to copy
 * @param newMessage : the message to modify
 * @return 0 on success, errno else
 */
inline int32_t
featsToIds(size_t size,u_int64_t type, char* feats, MLpv* newMessage)
{
	errno=0;
	if ( feats != NULL )
		{
			newMessage->param=type;
			newMessage->value.pByte=malloc(size);
			if (newMessage->value.pByte == NULL)
				return 0;
			memcpy(newMessage->value.pPv,feats,size);
			return 1;
		}
	return 0;
}

/** helper module api used to update a structure device tree from a message
 * @param message : the input message
 * @param dev : the top level structure that descibs the device
 * @return 0 on success, errno else
 */
int32_t 
processMessage (MLpv* message, struct device_desc* dev)
{
	err:
		return errno;
}


/**converter from param describer structure into a MLpv message suitable to communicate with
 * the program
 * @param params : the struct param_desc to convert
 * @return the allocated message or NULL on failure, set errno
 */
MLpv* 
paramToMessage (struct param_desc* params)
{
	MLpv newMessage[PARAM_FIELD_COUNT+1];
	MLpv* pMess;
	struct type_desc* parent;
	int i=0;

	memset(&newMessage,0,sizeof(MLpv)*(PARAM_FIELD_COUNT+1));

	newMessage[i].param=ML_ID;
	newMessage[i].value.int64=params->id;
	i++;

	newMessage[i].param=ML_NAME;
	newMessage[i].value.pByte=malloc(sizeof(char)*NAME_MAX_LENGTH);
	if (newMessage[i].value.pByte == NULL)
		goto err;
	memcpy(newMessage[i].value.pByte,params->name,sizeof(char)*NAME_MAX_LENGTH);
	newMessage[i].length=strlen(newMessage[i].value.pByte);
	newMessage[i].maxLength=NAME_MAX_LENGTH;
	i++;
	
	newMessage[i].param=ML_PARENT_ID;
	if (params->xparent != NULL)
		parent=(struct type_desc*)(params->xparent);
	else if (params->jparent != NULL)
		parent=(struct type_desc*)(params->jparent);
	else if (params->paparent != NULL)
		parent=(struct type_desc*)(params->paparent);
	else if (params->piparent != NULL)
		parent=(struct type_desc*)(params->piparent);
	else
		{
			errno=EBADMSG;
			goto err;
		}
	newMessage[i].value.int64=parent->id;
	i++;
	
	newMessage[i].param=ML_PARAM_TYPE;
	newMessage[i].value.int32=params->type;
	i++;
	
	newMessage[i].param=ML_PARAM_ACCESS;
	newMessage[i].value.int32=params->access;
	i++;
	
	newMessage[i].param=ML_PARAM_DEFAULT;
	newMessage[i].value=params->defaults;
	i++;
	
	if (params->mins != NULL )
		{
			if (params->maxs == NULL )
				{
					errno=EBADMSG;
					goto err;
				}
			newMessage[i].param=ML_PARAM_MINS;
			#warning : not sure : are all pointers types same size?
			newMessage[i].value.pByte=malloc(params->minsmaxsLength);
			if (newMessage[i].value.pByte == NULL ) goto err;
			memcpy(newMessage[i].value.pByte, params->mins, params->minsmaxsLength);
			i++;
		}
	
	if (params->maxs != NULL )
		{
			if (params->mins == NULL )
				{
					errno=EBADMSG;
					goto err;
				}
			newMessage[i].param=ML_PARAM_MAXS;
			#warning : not sure : are all pointers types same size?
			newMessage[i].value.pByte=malloc(params->minsmaxsLength);
			if (newMessage[i].value.pByte == NULL ) goto err;
			memcpy(newMessage[i].value.pByte, params->maxs, params->minsmaxsLength);
			i++;
		}
	newMessage[i].param=ML_PARAM_INCREMENT;
	newMessage[i].value=params->increment;
	i++;
	
	if (params->enum_vals != NULL )
		{
			if (params->enumNames == NULL )
				{
					errno=EBADMSG;
					goto err;
				}
			newMessage[i].param=ML_PARAM_ENUM_VALUES;
			#warning : not sure : are all pointers types same size?
			newMessage[i].value.pByte=malloc(params->enumValsLength);
			if (newMessage[i].value.pByte == NULL ) goto err;
			memcpy(newMessage[i].value.pByte, params->enum_vals, 
							params->enumValsLength);
			i++;
		}
	if (params->enumNames != NULL )
		{
			if (params->enum_vals == NULL )
				{
					errno=EBADMSG;
					goto err;
				}
			newMessage[i].param=ML_PARAM_ENUM_NAMES;
			#warning : not sure : are all pointers types same size?
			newMessage[i].value.pByte=malloc(params->enumNamesLength);
			if (newMessage[i].value.pByte == NULL ) goto err;
			memcpy(newMessage[i].value.pByte, params->enumNames, 
							params->enumNamesLength);
			i++;
		}
	newMessage[i].param=ML_END;
	i++;	
	pMess=malloc(sizeof(MLpv)*i);
	if (pMess == NULL )
		goto err;
	memcpy(pMess,&newMessage, sizeof(MLpv)*i);
	return pMess;

	#if PARAM_FIELD_COUNT != 11
		#error PARAM_FIELD_COUNT != 11 fix this file too
	#endif
	err:
		mlFreeMessage(newMessage,0);
		return NULL;
}

u_int32_t
copyStringWithAlloc(char** dest, char* src, int16_t* length)
{
	*length=0;
	errno=0;
	if (src == NULL)
		{
			errno = EFAULT;
			return EFAULT;
		}
	if (dest == NULL)
		{
			errno = EFAULT;
			return EFAULT;
		}
	*length=strlen(src)+1;
	*dest=malloc(*length);
	if (*dest == NULL )
		return errno;
	memcpy(*dest, src, sizeof(char)*(*length));
	return errno;
}

u_int32_t
copyDoubleStringWithAlloc(char** dest, char* src, int16_t* length)
{
	*length=0;
	errno=0;
	if (src == NULL)
		{
			errno = EFAULT;
			return EFAULT;
		}
	if (dest == NULL)
		{
			errno = EFAULT;
			return EFAULT;
		}
	while (src[*length] != '\0' && src[*length+1] != '\0' )
		length++;
	
	length+=2;
	
	*dest=malloc(sizeof(char)*(*length));
	if (*dest == NULL )
		return errno;
	memcpy(*dest, src, sizeof(char)*(*length));
	return errno;
}

/** converter from the base object type_desc into a message, this converter is used to avoid code
 * duplication of some devices parameters that are common to devices, xcodes, jacks....
 * @param desc : the structure that descibes the common parts of the devices describers
 * @param newMessage : the message to store information in
 * @return the count of converted parts, 0 on faillure and set errno
 */
u_int32_t 
makeTypeDesc (struct type_desc* desc, MLpv* newMessage)
{
	int i=0;
	newMessage[i].param=ML_ID;
	newMessage[i].value.int64=desc->id;
	struct type_desc* parent=(struct type_desc*)desc->parent;
	i++;

	newMessage[i].param=ML_NAME;
	if ( copyStringWithAlloc((char**)&(newMessage[i].value.pByte),desc->name,
											&(newMessage[i].length)) )
		goto err;
	newMessage[i].maxLength=newMessage[i].length;
	i++;
	
	newMessage[i].param=ML_PARENT_ID;
	if (parent == NULL )
		newMessage[i].value.int64=ML_SYSTEM_LOCALHOST;
	else
		newMessage[i].value.int64=parent->id;
	i++;
	
	i+= pointerArrayToIds(desc->paramsCount,ML_PARAM_IDS, desc->params,
									&newMessage[i] );
	if ( errno )
		goto err;
	
	return i;
	
	err:
		mlFreeMessage(newMessage,0);
		return 0;
	
}

/**converter from dev describer structure into a MLpv message suitable to communicate with the 
 * program
 * @param dev : the struct param_desc to convert
 * @return the allocated message or NULL on failure, set errno
 */
MLpv* 
deviceToMessage (struct device_desc* dev)
{
	MLpv newMessage[DEVICE_FIELD_COUNT+1];	
	MLpv* pMess;
	int i=0;
	memset(&newMessage,0,sizeof(MLpv)*(DEVICE_FIELD_COUNT+1));
	
	i+=makeTypeDesc ((struct type_desc*) dev, newMessage);
	if ( 0 == i )
		goto err;
	
	newMessage[i].param=ML_DEVICE_VERSION;
	newMessage[i].value.int32=dev->version;
	i++;
	
	newMessage[i].param=ML_DEVICE_INDEX;
	if ( copyStringWithAlloc((char**)&(newMessage[i].value.pByte),dev->index,
											&(newMessage[i].length)) )
		goto err;
	newMessage[i].maxLength=newMessage[i].length;
	i++;

	newMessage[i].param=ML_DEVICE_LOCATION;
	if ( copyStringWithAlloc((char**)&(newMessage[i].value.pByte),dev->location,
											&(newMessage[i].length)) )
		goto err;
	newMessage[i].maxLength=newMessage[i].length;
	i++;
	
	
	i+= pointerArrayToIds(dev->jacksCount,ML_DEVICE_JACK_IDS, dev->jacks,
									&newMessage[i] );
	if ( errno )
		goto err;
	
	#warning clean?
	/*
	i+=pointerArrayToIds(dev->pathsCount,ML_DEVICE_PATH_IDS, dev->paths, 
									&newMessage[i] ) ;
	if ( errno )
		goto err;
	 */
	
	i+= pointerArrayToIds(dev->xcodesCount,ML_DEVICE_XCODE_IDS, dev->xcodes,
									&newMessage[i] );
	if ( errno )
		goto err;
	
	newMessage[i].param=ML_END;
	i++;	
	pMess=malloc(sizeof(MLpv)*i);
	if (pMess == NULL )
		goto err;
	memcpy(pMess,&newMessage, sizeof(MLpv)*i);
	return pMess;
	#if DEVICE_FIELD_COUNT != 10
		#error DEVICE_FIELD_COUNT != 10 fix this file too
	#endif
	err:
		mlFreeMessage(newMessage,0);
		return NULL;
}


/** converter from a xcode desciber structure into a MLpv suitable to communicate with the 
 * program
 * @param xcode : the xcode structure to convert
 * @return a pointer to the new message or NULL on error and set errno
 */
MLpv* 
xcodeToMessage (struct xcode_desc* xcode)
{
	MLpv newMessage[XCODE_FIELD_COUNT+1];	
	MLpv* pMess;
	int i=0;
	memset(&newMessage,0,sizeof(MLpv)*(XCODE_FIELD_COUNT+1));	

	i+=makeTypeDesc ((struct type_desc*) xcode,newMessage);
	if ( 0 == i )
		goto err;
	
	
	#warning add OpenOptions here
	
	
	if ( xcode->preset != NULL )
		{
			newMessage[i].param=ML_PRESET;
			newMessage[i].value.pPv=malloc(sizeof(MLpv)*xcode->preset->length);
			if (newMessage[i].value.pPv == NULL)
				goto err;
			memcpy(newMessage[i].value.pPv,xcode->preset->value.pPv,
							sizeof(MLpv)*xcode->preset->length);
			i++;
		}

	newMessage[i].param=ML_XCODE_ENGINE_TYPE_INT32;
	newMessage[i].value.int32=xcode->engineType;
	i++;
	
	newMessage[i].param=ML_XCODE_IMPLEMENTATION_TYPE_INT32;
	newMessage[i].value.int32=xcode->implementationType;
	i++;
	
	newMessage[i].param=ML_XCODE_BUFFER_ALIGNMENT_INT32;
	newMessage[i].value.int32=xcode->bufferAlignement;
	i++;
	
	i+= featsToIds(xcode->featsLength,ML_XCODE_FEATURES, xcode->feats, 
								&(newMessage[i]));
	if ( errno )
		goto err;
	
	i+= pointerArrayToIds(xcode->srcsCount,ML_XCODE_SRC_PIPE_IDS, xcode->srcs,
									&newMessage[i] );
	if ( errno )
		goto err;
	
	
	i+=pointerArrayToIds(xcode->destCount,ML_XCODE_DEST_PIPE_IDS, xcode->dest, 
									&newMessage[i] );
	if ( errno )
		goto err;
	
	newMessage[i].param=ML_END;
	i++;	
	pMess=malloc(sizeof(MLpv)*i);
	if (pMess == NULL )
		goto err;
	memcpy(pMess,&newMessage, sizeof(MLpv)*i);
	return pMess;
	#if XCODE_FIELD_COUNT != 13
		#error XCODE_FIELD_COUNT != 13 fix this file too
	#endif
	err:
		mlFreeMessage(newMessage,0);
		return NULL;
}

/** converter from a jack desciber structure into a MLpv suitable to communicate with the 
 * program
 * @param jack : the jack structure to convert
 * @return a pointer to the new message or NULL on error and set errno
 */
MLpv* 
jackToMessage (struct jack_desc* jack)
{
	MLpv newMessage[JACK_FIELD_COUNT+1];	
	MLpv* pMess;
	int i=0;
	memset(&newMessage,0,sizeof(MLpv)*(JACK_FIELD_COUNT+1));	

	i+=makeTypeDesc ((struct type_desc*) jack, newMessage);
	if ( 0 == i )
		goto err;
	
	newMessage[i].param=ML_JACK_TYPE_INT32;
	newMessage[i].value.int64=jack->type;
	i++;
	
	
	newMessage[i].param=ML_JACK_DIRECTION_INT32;
	newMessage[i].value.int64=jack->direction;
	i++;
	
	newMessage[i].param=ML_JACK_COMPONENT_SIZE_INT32;
	newMessage[i].value.int64=jack->size;
	i++;
	
	i+= pointerArrayToIds(jack->pathsCount,ML_JACK_PATH_IDS, jack->paths,
								&newMessage[i]);
	if ( errno )
		goto err;
	

	#warning add OpenOptions_desc
	
	i+=featsToIds(jack->featsLength,ML_JACK_FEATURES_BYTE_ARRAY, jack->feats, 
								&(newMessage[i]));
	if ( errno )
		goto err;
	
	newMessage[i].param=ML_END;
	i++;	
	pMess=malloc(sizeof(MLpv)*i);
	if (pMess == NULL )
		goto err;
	memcpy(pMess,&newMessage, sizeof(MLpv)*i);
	return pMess;
	#if JACK_FIELD_COUNT != 10
		#error JACK_FIELD_COUNT != 10 fix this file too
	#endif
	err:
		mlFreeMessage(newMessage,0);
		return NULL;
}

/** converter from a path desciber structure into a MLpv suitable to communicate with the 
 * program
 * @param pipe : the path structure to convert
 * @return a pointer to the new message or NULL on error and set errno
 */
MLpv* 
pathToMessage (struct path_desc* path)
{
	MLpv newMessage[PATH_FIELD_COUNT+1];	
	MLpv* pMess;
	int i=0;
	memset(&newMessage,0,sizeof(MLpv)*(PATH_FIELD_COUNT+1));	
	
	i+=makeTypeDesc ((struct type_desc*) path,newMessage);
	if ( 0 == i )
		goto err;
	
	newMessage[i].param=ML_PATH_TYPE_INT32;
	newMessage[i].value.int64=path->type;
	i++;
	
	#warning add openoptions here
	
	#warning add preset here
	
	newMessage[i].param=ML_PATH_COMPONENT_ALIGNEMENT;
	newMessage[i].value.int32=path->compAlignement;
	i++;
	
	i+=pointerArrayToIds(path->srcCount,ML_PATH_SRC_JACK_IDS, path->src, 
								&newMessage[i]);
	if ( errno )
		goto err;
	
	i+=pointerArrayToIds(path->destCount,ML_PATH_DST_JACK_IDS, path->dest,
								&newMessage[i]);
	if ( errno )
		goto err;
	
	i+=featsToIds(path->featsLength,ML_JACK_FEATURES_BYTE_ARRAY, path->feats, 
							&(newMessage[i]));
	if ( errno )
		goto err;

	
	newMessage[i].param=ML_END;
	i++;	
	pMess=malloc(sizeof(MLpv)*i);
	if (pMess == NULL )
		goto err;
	memcpy(pMess,&newMessage, sizeof(MLpv)*i);
	return pMess;
	#if PATH_FIELD_COUNT != 12
		#error PATH_FIELD_COUNT != 13 fix this file too
	#endif
	err:
		mlFreeMessage(newMessage,0);
		return NULL;
}


/** converter from a pipe desciber structure into a MLpv suitable to communicate with the 
 * program
 * @param pipe : the jack structure to convert
 * @return a pointer to the new message or NULL on error and set errno
 */
MLpv* 
pipeToMessage (struct pipe_desc* pipe)
{
		MLpv newMessage[PIPE_FIELD_COUNT+1];	
	MLpv* pMess;
	int i=0;
	memset(&newMessage,0,sizeof(MLpv)*(PIPE_FIELD_COUNT+1));	
	
	i+=makeTypeDesc ((struct type_desc*) pipe,newMessage);
	if ( 0 == i )
		goto err;
	
	newMessage[i].param=ML_PIPE_TYPE_INT32;
	newMessage[i].value.int32=pipe->type;
	i++;
	
	newMessage[i].param=ML_END;
	i++;	
	pMess=malloc(sizeof(MLpv)*i);
	if (pMess == NULL )
		goto err;
	memcpy(pMess,&newMessage, sizeof(MLpv)*i);
	return pMess;
	#if PIPE_FIELD_COUNT != 5
		#error PIPE_FIELD_COUNT != 5 fix this file too
	#endif
	err:
		mlFreeMessage(newMessage,0);
		return NULL;
}


static int32_t 
updatePathId(struct path_desc* path, u_int64_t new_id)
{
	path->desc.id=new_id;
	return 1;
}

static int32_t 
updateJackId(struct jack_desc* jack, u_int64_t new_id)
{	
	int count=0;
	int i;
	jack->desc.id=new_id;
	count++;
	for (i=0; i<jack->pathsCount;i++)
		{
			count+=updatePathId(jack->paths[i],new_id+count);
		}
	return count;
}

static int32_t 
updatePipeId(struct pipe_desc* pipe, u_int64_t new_id)
{
	pipe->desc.id=new_id;
	return 1;
}

static int32_t 
updateXcodeId(struct xcode_desc* xcode, u_int64_t new_id)
{	
	int count=0;
	int i;
	xcode->desc.id=new_id;
	count++;
	for (i=0; i<xcode->srcsCount;i++)
		{
			count+=updatePipeId(xcode->srcs[i],new_id+count);
		}
	for (i=0; i<xcode->destCount;i++)
		{
			count+=updatePipeId(xcode->dest[i],new_id+count);
		}
	return count;
}


static int32_t 
updateParamId(struct param_desc* params, u_int64_t new_id)
{
	params->id=new_id;
	return 1;
}

void
updateAllId(struct device_desc* dev, u_int64_t new_id)
{
	int i;
	dev->desc.id=new_id;
	new_id++;
	for (i=0; i<dev->jacksCount;i++)
		{
			new_id+=updateJackId(dev->jacks[i],new_id);
		}
	for (i=0; i<dev->xcodesCount;i++)
		{
			new_id+=updateXcodeId(dev->xcodes[i],new_id);
		}
}


MLpv* 
makeCapability(const u_int64_t id, struct device_desc* dev)
{
}
