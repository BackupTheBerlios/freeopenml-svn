#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top source dir of the
#* package
#************************************************************************/ 

#general variables
.PHONY : all lib clean debug tests
all:

#includes (env)
export TOPSRC_DIR?=..
include $(TOPSRC_DIR)/Makefile.confiserie

#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS  += -lpthread -ldl -lrt
CFLAGS   += -Wall -fPIC -Werror-implicit-function-declaration  
CPPFLAGS += -I../include


lib_LIBRARIES = libOpenML
export libOpenML_VERSION="0.0.0"
#here goes your sources
libOpenML_SOURCES = mlBeginTransfer.c mlGetCapabilities.c mlGetSystemUST.c
libOpenML_SOURCES += mlModules.c mlPvValueToString.c mlSendMessage.c 
libOpenML_SOURCES += mlClose.c mlGetControls.c mlGetVersion.c mlOpen.c
libOpenML_SOURCES += mlSelectPipe.c mlSetControls.c mlEndTransfer.c
libOpenML_SOURCES += mlGetMessageCount.c mlMessageName.c mlPvToString.c
libOpenML_SOURCES += mlPvParamToString.c mlReceiveMessage.c mlXcodeWork.c
libOpenML_SOURCES += register.c mlFreeMessage.c mlGetReceiveWaitHandle.c
libOpenML_SOURCES += mlMessageQueue.c 
#libOpenML_SOURCES += mlPvXXXXFromString.c

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all
	
clean : 
	$(CLEANINGMSG) $(MSGSUBDIR)

#includes (helpers)
include ${confiserie}/Makefiles/Makefile.autolib
include ${confiserie}/C/Makefile.beautifull_rules



