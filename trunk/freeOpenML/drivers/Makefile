#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top source dir of the
#* package
#************************************************************************/
#general variables
.PHONY : all lib clean debug tests

#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+= -lpthread
CFLAGS+= -I../include -Wall -fPIC -Werror-implicit-function-declaration

#here goes your sources
lib_sources = mlforward.c mlRotate.c

#now the targets
all : plugin

plugin : $(lib_sources:%.c=%.so) tests
	$(SUCCESSMSG) $@

#a nesting : invoques make on the subdir
tests :
	$(MAKE) $(MAKECMDGOALS) -C $@ MSGSUBDIR=$(MSGSUBDIR)$@/

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

clean : tests
	$(CLEANINGMSG) $(MSGSUBDIR)
	rm -Rf *.o *.so .DEP

install :
	$(INSTALLMSG) $(lib_sources:%.c=%.so) in $(INSTALL_PREFIX)/lib/mlplugins"
	mkdir -p  $(INSTALL_PREFIX)/lib/mlplugins
	$(INSTALL) -C $(lib_sources:%.c=%.so) $(INSTALL_PREFIX)/lib/mlplugins


#as a gneral rule includ must be last : it defines rules, since make execute the first found rule 
#in case of 'make' this can cause you not having the right behaviour
#remember : a Makefile isn't linearly executed....
export TOPSRC_DIR?=$(PWD)
include $(TOPSRC_DIR)/Makefile.confiserie


#create the dependencies (the - is for avoiding it to be too verbose)
-include $(lib_sources:%.c=.DEP/%.d)




