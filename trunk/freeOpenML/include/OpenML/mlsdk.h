/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef _MLSDK_H
	#define _MLSDK_H
	#ifdef __cplusplus
	extern "C" {
	#endif

	#include <OpenML/mltypes.h>
	#include <OpenML/mlid.h>

	/**initialise the library
	 * @param argc : arg count as provided to main
	 * @param argv : argument values as provided to main
	 */
	u_int32_t MLAPI
	mlInit (int argc, char** argv);

	/** return the current version of OpenML API
	 * @param major : resulting major
	 * @param minor : resulting minor
	 * @return 0 on success, non zero means error
	 */
	int32_t MLAPI
	mlGetVersion(int16_t *major, int16_t *minor);

	/** Get capabilities array of an object identifier
	 * @param id : "device" identifier to query
	 * @param capabilities : resulting capabilities
	 * @return 0 on success, non zero on error
	 */
	#define mlGetCapabilities(id,capabilities) mlPvGetCapabilities(id,ML_END,capabilities)

	/** select and retrieve particular capabilities
	 *@param deviceid : the "object identifier" we are talking to
	 *@param paramid :the id of the parameter seeked
	 *@param capabilities : the capabilities returned for this paramid
	 *@return 0 on success, non zero on error
	 */
	int32_t MLAPI
	mlPvGetCapabilities( const u_int64_t id, const u_int64_t paramid,
						MLpv** capabilities);

	/** destroy allocated memory created by GetCap*  like functions
	 *@param capabilities : the capabilities to free
	 */
	#define mlFreeCapabilities(capabilities) mlFreeMessage(capabilities,1)

	/** destroy allocated memory created for a message functions
	 *@param capabilities : the capabilities to free
	 *@param all : de-allocate 
	 */
	int32_t MLAPI
	mlFreeMessage(MLpv* capabilities, int all);

	/** open an instance of the id "object"
	 *to make a comparison with the open() syscall : id is the name of the
	 *device, openid is the FD. an id device can be opened multiple time if
	 *supported and have unique id.
	 *@param id : the "device" we want to open
	 *@param options : the options of the open
	 *@param openid : the returned id for the "new" device
	 *@return 0 on success !=0 of error
	 */
	int32_t MLAPI
	mlOpen(u_int64_t id, MLpv* options, MLopenid* openid);

	/** release an id
	 *@param openid : the device to close
	 */
	int32_t MLAPI
	mlClose(MLopenid openid);
	
	
	/** select the pipe we're talking to
	 * @param openid : the device we're accessing
	 * @param id : the pipe id we are selecting
	 * @return 0 on success else errno 
	 */
	int32_t MLAPI
	mlSelectPipe(MLopenid openid, u_int64_t id);

	/** get the Id controls parameters, the controls are got "out of band" and
	 * then correspond to the actual state of the device
	 *@param openid : the device
	 *@param controls : returned the controls values
	 */
	int32_t MLAPI
	mlGetControls( MLopenid openid, MLpv* controls);

	/**read reply messages for the receive queue
	 *@param openId :the device concerned
	 *@param status : the error status (cause of the message)
	 *@param reply the message content
	 */
	int32_t MLAPI
	mlReceiveMessage( MLopenid openid, int16_t *status, MLpv** reply);

	/** set the Id controls parameters, the controls are set "out of band" and
	 * then affect the device immediatly
	 *@param openid : the device
	 *@param controls : the controls values to set
	 */
	int32_t MLAPI
	mlSetControls(MLopenid openid,MLpv* controls);

	/** set the Id controls parameters, the controls are set "in band" and then
	 * are queued and affect the device when they will be processed
	 *@param openid : the device
	 *@param controls : the controls values to set
	 */
	#define mlSendControls( openid, controls) mlSendMessage(openid,controls)

	/** enqueue a buffer descriptor to the message queue, the buffers are set "in
	 * band" and then are queued and will then be processed sequentially,
	 * eventually mixed with controls messages
	 *@param openid : the device
	 *@param buffers : the buffer descriptor
	 */
	#define mlSendBuffers( openid, buffers) mlSendMessage(openid,buffers)

	/**this find the Posix message queue associated to openid and send the messages
	 * this is a non standard call created because mlSet* mlSend* are quite the
	 * same...
	 * @param openid : the device we are talking to
	 * @param buffers : the message array to send
	 * @param prio : the priority to use (set are higher priority and send low
	 *        prio)
	 */
	int32_t MLAPI
	mlSendMessage( MLopenid openid, MLpv* buffers);


	/**prepare for asynchronous processing by getting a wait handle
	 * note : this function will be "deprecated" since current implementation is
	 * more versatile
	 * @param openId : the device
	 * @param handle : the retuned handle
	 */
	int32_t MLAPI
	mlGetReceiveWaitHandle( MLopenid openid, MLwaitable* handle);


	/** set the device from "ready state" to "processing state"
	 * before this call the device will not process enqueued messages, this
	 * effectively start a transfert
	 * @param openId : the device to start
	 */
	int32_t MLAPI
	mlBeginTransfer( MLopenid openid);

	/** set the device from "processing state" to "ready state"
	 * after this call the device will stop process enqueued messages, this
	 * effectively stop a transfert
	 * @param openId : the device to start
	 */
	int32_t MLAPI
	mlEndTransfer( MLopenid openid);


	/** perform synchronous work
	 * basically a transcoder is a "threaded" detached process that is standalone
	 * when this behaviour isn't wanted the following function has to be called
	 * to perform the work
	 * @param codec : the device id
	 */
	int32_t MLAPI
	mlXcodeWork(MLopenid codec);

	/** return the UST for a particular system
	 *@param sysId : id of the system
	 *@param ust : returned UST
	 */
	int32_t MLAPI
	mlGetSystemUST( u_int64_t sysId, int64_t* ust);

	/**
	 */
	int32_t MLAPI mlGetSendMessageCount( MLopenid openid, int16_t* count);
	/**
	 */
	int32_t MLAPI mlGetReceiveMessageCount( MLopenid openid, int16_t* count);

	//int32_t MLAPI mlSavePersistentControls( int64_t openId );
	//int32_t MLAPI mlRestorePersistentControls( int64_t openId );
	//int32_t MLAPI mlGetSendWaitHandle( int64_t openid, MLwaitable* handle);
	//int32_t MLAPI mlXcodeGetOpenPipe( int64_t openid, int64_t pipeid, int64_t* openpipeid);

	/** convert pv into human readable string
	 * @param objectId : device to query
	 * @param pv : pv to be converted
	 * @param str : resulting string "pv->value"
	 * @param bufferSize : max size of the string
	 * @return 0 on success other on faillure
	 */
	int32_t MLAPI
	mlPvValueToString(u_int64_t objectId, MLpv* pv,
					 char* str, int16_t* bufferSize);

	/** convert pv into human readable string
	 * @param objectId : device to query
	 * @param pv : pv to be converted
	 * @param str : resulting string "pv->param"
	 * @param bufferSize : max size of the string
	 * @return 0 on success other on faillure
	 */
	int32_t MLAPI
	mlPvParamToString(u_int64_t objectId, MLpv* pv,
					 char* str, int16_t* bufferSize);

	/** convert pv into human readable string
	 * @param objectId : device to query
	 * @param pv : pv to be converted
	 * @param str : resulting string "pv->param=pv->value"
	 * @param bufferSize : max size of the string
	 * @return 0 on success other on faillure
	 */
		#define mlPvToString(objectId,pv,str,bufferSize) mlPvToStringAlign(objectId,pv,str,bufferSize,0)
	int32_t MLAPI
	mlPvToStringAlign(u_int64_t objectId, MLpv* pv,
					char* str, int16_t* bufferSize,int level);

	/** convert pv into human readable string
	 * @param objectId : device to query
	 * @param pv : pv->value will be filled
	 * @param str : string to be looked for
	 * @param bufferSize : max size of the string
	 * @return 0 on success other on faillure
	 */
	/*
	int32_t MLAPI
	mlPvValueFromString( u_int64_t objectId, const u_int8_t* str,
						int16_t* bufferSize, MLpv* pv,
						int8_t* arrayData, int16_t arraySize);
	*/

	/** convert pv into human readable string
	 * @param objectId : device to query
	 * @param pv : pv->param will be filled
	 * @param str : string to be looked for
	 * @param bufferSize : max size of the string
	 * @return 0 on success other on faillure
	 */
	/*
	int32_t MLAPI
	mlPvParamFromString( u_int64_t objectId, const char* str,
						int16_t* size, MLpv* pv);
	*/

	/** convert pv into human readable string
	 * @param objectId : device to query
	 * @param pv : pv->param and pv->value will be filled
	 * @param str : string to be looked for
	 * @param bufferSize : max size of the string
	 * @return 0 on success other on faillure
	 */
	/*
	int32_t MLAPI
	mlPvFromString( u_int64_t objectId, const char* Str,
					   int16_t* bufferSize, MLpv* pv,
					   int8_t* arrayData, int16_t arraySize);
	*/

	/** find specific parameter into the provided parameter array
	 * @param params : the array to look into
	 * @param searchParam : the param we look for
	 * @return NULL if error, else the parameters
	 */
	/*
	MLpv* MLAPI
	mlPvFind( MLpv* params, u_int64_t searchParam);
	*/

	int32_t MLAPI
	mlPvCopy( MLpv* params, void* toBuffer, int16_t sizeofBuffer);

	/** return an human readable version of the status returned by most OML
	 * functions
	 * @param status : the status to translate
	 *@return human readable string
	 */
	#define mlStatusName(status)  mlMessageName(status)

	/** return an human readable version of a message signification
	 *@param status : the message to translate
	 *@return human readable string
	 */
	const char* MLAPI
	mlMessageName( int32_t status);



	#ifdef __cplusplus
	}
	#endif

#endif /* MLSDK_H */
