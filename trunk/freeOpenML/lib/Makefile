#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top source dir of the
#* package
#************************************************************************/ 

#general variables
.PHONY : all lib clean debug tests


#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS  += -lpthread -ldl -lrt
CFLAGS   += -Wall -fPIC -Werror-implicit-function-declaration  
CPPFLAGS += -I../include

#here goes your sources : the rules are as follow 
# liblist must contain the names of your libs including the $(SHAREDLIBEXT) (or .so
# if you're not using automatic library type detection) $(STATICLIBEXT) (or .a)
# then for each libraries listed here, you must create a variable with the format
# sources_nomlibwithoutextension which must contain the list of sources (not headers)
# at this time extension supported are .c .cc .C .cpp more can be added on demand
SHAREDLIBEXT = .so

VERSION=0.0.0

ifdef SHAREDLIBEXT
liblist += libOpenML.$(VERSION)$(SHAREDLIBEXT)
all :
	ln -sf libOpenML.$(VERSION)$(SHAREDLIBEXT) libOpenML$(SHAREDLIBEXT)
endif
ifdef STATICLIBEXT
liblist += libOpenML.$(VERSION)$(STATICLIBEXT)
all:
	
endif

#here goes your sources
sources_libOpenML.$(VERSION) = mlBeginTransfer.c mlGetCapabilities.c mlGetSystemUST.c
sources_libOpenML.$(VERSION) += mlModules.c mlPvValueToString.c mlSendMessage.c 
sources_libOpenML.$(VERSION) += mlClose.c mlGetControls.c mlGetVersion.c mlOpen.c
sources_libOpenML.$(VERSION) += mlSelectPipe.c mlSetControls.c mlEndTransfer.c
sources_libOpenML.$(VERSION) += mlGetMessageCount.c mlMessageName.c mlPvToString.c
sources_libOpenML.$(VERSION) += mlPvParamToString.c mlReceiveMessage.c mlXcodeWork.c
sources_libOpenML.$(VERSION) += register.c mlFreeMessage.c mlGetReceiveWaitHandle.c
sources_libOpenML.$(VERSION) += mlMessageQueue.c 
#sources_libOpenML.$(VERSION) += mlPvXXXXFromString.c

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all
	
clean : 
	$(CLEANINGMSG) $(MSGSUBDIR)

install :
	$(INSTALLMSG) $(liblist) in $(INSTALL_PREFIX)/lib/mlplugins
	mkdir -p  $(INSTALL_PREFIX)/lib/mlplugins
	$(INSTALL) -C $(liblist) $(INSTALL_PREFIX)/lib/mlplugins

#create the dependencies (the - is for avoiding it to be too verbose)
-include $(TOPSRC_DIR)/$(sources_libOpenML.$(VERSION):%.c=.DEP/%.d)
export TOPSRC_DIR?=$(PWD)
include $(TOPSRC_DIR)/Makefile.confiserie



