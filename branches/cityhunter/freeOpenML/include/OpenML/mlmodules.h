/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published in the top source dir of the
* package
************************************************************************/




#ifndef ML_MODULES_H
	#define ML_MODULES_H

	#ifdef __ML_MODULES
		#ifdef __cplusplus
		extern "C" {
		#endif

		#include <OpenML/mlparam.h>
		#include <OpenML/mlMessageQueue.h>
		
		struct mlPipe {
			struct mlMessageQueue in;
			struct mlMessageQueue out;
			};

		//this structure is used only for opening, closing, and get capabilities
		//the id stored here is used only in those functions....
		struct mlID {
			struct mlPipe* pipes;
			u_int16_t pipes_count;
			u_int16_t current_pipe;
			u_int64_t id;					//current ID (system id for system, device  ID... see mlid.h)
			int32_t (*mlPvGetCapabilities) ( const u_int64_t id,
									const u_int64_t paramid, MLpv** capabilities);
			int32_t (*mlOpen)  				( struct mlID* openid,  MLpv* options);
			int32_t (*mlClose) 				( struct mlID* openid);
			int32_t (*mlGetControls) 	( struct mlID* openid, MLpv* controls);
			int32_t (*mlSetControls) 	( struct mlID* openid, MLpv* controls);
			int32_t (*mlGetReceiveWaitHandle)( struct mlID* openid,
									MLwaitable* handle);
			int32_t (*mlBeginTransfer)( struct mlID* openid	);
			int32_t (*mlEndTransfer)	( struct mlID* openid	);
			int32_t (*mlXcodeWork)		( struct mlID* codec	);
			void* handle;
			void* priv; 					//module private data
			struct mlID* next;		//to make a simple linked list
			};

		extern struct mlID* localhost;

		/**
		 * this function load the plugin into the framework
		 * @param PluginName : a string containing the name of the plugin
		 * @param id : the id, used only for testsuite.
		 * @return 0 on success, 1 on faillure
		 */
		u_int32_t mlPluginLoad(char* PluginName, u_int64_t* id);

		/**
		 * this function is used to register a driver with the OML framework
		 * @param physdev : a mlID structure descibing the device
		 * @return 0 means failure, else the "MSB" of the ID  (first 32 bits)
		 */
		u_int32_t mlDeviceRegister(struct mlID* physdev);
		/**
		 *this function unregister an id from the OML framework
		 *@param id : the device id to unregister
		 *@return 0 on success !=0 on failure
		 */
		u_int32_t mlDeviceUnRegister(u_int32_t id);


		/********some internal helper structures and converters*********/
	
		#define NAME_MAX_LENGTH 25
		
		struct OpenOptions_desc {
			u_int32_t mode;
			u_int32_t recQueueCount;
			u_int32_t sendQueueCount;
			u_int32_t eventPayloadCount;
			u_int32_t messagePayloadCount;
			u_int32_t sendSignalCount;
			u_int32_t xcodeMode;
			u_int32_t xcodeStream;
		};
	
		#define PARAM_FIELD_COUNT 11
		struct param_desc {
			u_int64_t id;
			char name[NAME_MAX_LENGTH];
			struct xcode_desc* xparent;
			struct jack_desc* jparent;
			struct path_desc* paparent;
			struct pipe_desc* piparent;
			u_int32_t type;
			u_int32_t access;
			MLvalue defaults;
			void* mins; 		//intentionaly set to void to avoid dereferencing pointer 
			void* maxs;			//without a cast
			size_t minsmaxsLength;
			MLvalue increment;
			void* enum_vals;
			size_t enumValsLength;
			char* enumNames;
			size_t enumNamesLength;
		};
	
		struct system_desc {
			u_int64_t id;
			char name[NAME_MAX_LENGTH];
			struct device_desc** devices;
		};
	
	
		//base type used to derive others
		#define TYPE_DESC_FIELD_COUNT 4
		struct type_desc {
			u_int64_t 						id;
			char 									name[NAME_MAX_LENGTH];
			struct type_desc* 		parent;
			struct param_desc** 	params;
			u_int32_t 						paramsCount;
			};
	
		#define DEVICE_FIELD_COUNT 6+TYPE_DESC_FIELD_COUNT
		struct device_desc {
			struct type_desc			desc; //must be first
			u_int32_t 						version;
			char 									index[NAME_MAX_LENGTH];
			char 									location[NAME_MAX_LENGTH];
			struct jack_desc** 		jacks;  //a pointer to an array of devices describer
			u_int32_t 						jacksCount;	
		//	#warning clean?
/* 			struct path_desc** 		paths;	//a pointer to an array of devices describer
			u_int32_t 						pathsCount; */
			struct xcode_desc** 	xcodes;	//a pointer to an array of devices describer
			u_int32_t 						xcodesCount;
		};
	
	
	
		#define XCODE_FIELD_COUNT 9+TYPE_DESC_FIELD_COUNT
		struct xcode_desc {
			struct type_desc 			desc; //must be first
			struct OpenOptions_desc options;
			MLpv* 								preset;
			u_int32_t 						engineType;
			u_int32_t 						implementationType;
			u_int32_t 						componentAlignement;
			u_int32_t 						bufferAlignement;
			char* 								feats;
			size_t								featsLength;
			struct pipe_desc** 		srcs;	//a pointer to an array of devices describer
			u_int32_t 						srcsCount;
			struct pipe_desc** 		dest;	//a pointer to an array of devices describer
			u_int32_t 						destCount;
		};
	
		#define JACK_FIELD_COUNT 6+TYPE_DESC_FIELD_COUNT
		struct jack_desc {
			struct type_desc 			desc; //must be first
			u_int32_t 						type;
			u_int32_t 						direction;
			u_int32_t 						size;
			struct path_desc** 		paths; //a pointer to an array of devices describer
			u_int32_t 						pathsCount;
			struct OpenOptions_desc opts;
			char* 								feats;
			size_t 								featsLength;
		};
	
		#define PATH_FIELD_COUNT 8+TYPE_DESC_FIELD_COUNT
		struct path_desc {
			struct type_desc 			desc; //must be first
			u_int32_t 						type;
			struct OpenOptions_desc opts;
			MLpv* 								preset;
			u_int32_t 						compAlignement;
			u_int32_t 						bufferAlignement;
			struct jack_desc** 		src;	//a pointer to an array of devices describer
			u_int32_t 						srcCount;
			struct jack_desc** 		dest;	//a pointer to an array of devices describer
			u_int32_t 						destCount;
			char* 								feats;
			size_t 								featsLength;
		};
	
		#define PIPE_FIELD_COUNT 1+TYPE_DESC_FIELD_COUNT
		struct pipe_desc {
			struct type_desc 			desc; //must be first
			u_int32_t 						type;
		};
	
		/**this function process a message and update the device parameters tree
		 *@param message : the message to process
		 *@param dev : the device tree
		 *@return 0 on success, else errno 
		 */
		int32_t processMessage (MLpv* message, struct device_desc* dev);
		
		/** those functions are helper converter functions
		 * @param a pointer to the struct to convert
		 * @return NULL on error and set errno, else a malloc'ed message suitable for Capabilities query
		 */
		MLpv* paramToMessage (struct param_desc* params);
		MLpv* deviceToMessage (struct device_desc* dev);
		MLpv* xcodeToMessage (struct xcode_desc* xcode);
		MLpv* jackToMessage (struct jack_desc* jack);
		MLpv* pipeToMessage (struct pipe_desc* pipe);
			
		/**a function to automatically update all ids of a device capability tree
		 * @param dev : the top level device describer
		 * @param newid : the device id given by OpenML layer
		 */
		void updateAllId(struct device_desc* dev, u_int64_t new_id);
			
		/**a function that find a device describer for a given id and call helper converter functions
		 * @param id : the id to look for
		 * @param dev : the top level device describer
		 * @return NULL on error and set errno, else a malloc'ed message suitable for Capabilities query
		 */
		MLpv* makeCapability(const u_int64_t id, struct device_desc* dev);

		#ifdef __cplusplus
		}
		#endif


	#endif //__ML_MODULES
#endif // ML_MODULES_H
