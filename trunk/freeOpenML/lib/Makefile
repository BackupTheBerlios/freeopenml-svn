#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of version 2.1 of the GNU Lesser General Public
#* License as published by the Free Software Foundation.
#*
#* This program is distributed in the hope that it wou be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#*
#* Further, this software is distributed without any warranty that it
#* is free of the rightful claim of any third person regarding
#* infringement or the like.  Any license provided herein, whether
#* implied or otherwise, applies only to this software file.  Patent
#* licenses, if any, provided herein do not apply to combinations of
#* this program with other software, or any other product whatsoever.
#*
#* You shou have received a copy of the GNU Lesser General Public
#* License along with this program; if not, write the Free Software
#* Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307,
#* USA.
#*
#************************************************************************/
#general variables
.PHONY : all lib clean debug 

#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+= -lpthread -ldl -lrt
CFLAGS+= -I../include -Wall -fPIC -Werror-implicit-function-declaration

#here goes your sources
lib_sources = mlBeginTransfer.c mlGetCapabilities.c mlGetSystemUST.c mlModules.c
lib_sources += mlPvValueToString.c mlSendMessage.c mlClose.c mlGetControls.c 
lib_sources += mlGetVersion.c mlOpen.c mlSelectPipe.c mlSetControls.c
lib_sources += mlEndTransfer.c mlGetMessageCount.c mlMessageName.c mlPvToString.c
lib_sources += mlPvParamToString.c mlReceiveMessage.c mlXcodeWork.c register.c
lib_sources += mlFreeMessage.c mlGetReceiveWaitHandle.c mlMessageQueue.c
#lib_sources +=  mlPvXXXXFromString.c

VERSION=0.0.0
#now the targets
all : libOpenML.so.$(VERSION)

libOpenML.so.$(VERSION) : $(lib_sources:%.c=%.o)
	rm -f libOpenML*
	$(LDMESG) $@
	$(LD) $(LDFLAGS) -shared -Bdynamic -soname $@ -o $@ $^
	ln -s $@ libOpenML.so
	$(SUCCESSMSG) $@


#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

clean : 
	$(CLEANINGMSG) $(MSGSUBDIR)
	rm -Rf *.o *.so* .DEP

install :
	$(INSTALLMSG) $(lib_sources:%.c=%.so) in $(INSTALL_PREFIX)/lib/mlplugins"
	mkdir -p  $(INSTALL_PREFIX)/lib/mlplugins
	$(INSTALL) -C $(lib_sources:%.c=%.so) $(INSTALL_PREFIX)/lib/mlplugins


#this must be last : it defines rules, since make execute the first found rule in case
#of 'make' this can cause you not having the right behaviour



#as a gneral rule includ must be last : it defines rules, since make execute the first found rule 
#in case of 'make' this can cause you not having the right behaviour
#remember : a Makefile isn't linearly executed....
export TOPSRC_DIR?=$(PWD)
include $(TOPSRC_DIR)/Makefile.confiserie


#create the dependencies (the - is for avoiding it to be too verbose)
-include $(lib_sources:%.c=.DEP/%.d)


