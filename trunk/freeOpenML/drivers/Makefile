#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top source dir of the
#* package
#************************************************************************/
#general variables
.PHONY : all lib clean debug tests

#load configuration
export TOPSRC_DIR?=..
include $(TOPSRC_DIR)/Makefile.confiserie

#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+= -lpthread
CFLAGS+= -I../include -Wall -fPIC -Werror-implicit-function-declaration

#here goes your sources
lib_LIBRARIES += mlforward mlRotate

mlforward_VERSION = 0.0.0
mlforward_SOURCES = mlforward.c

mlRotate_VERSION = 0.0.0
mlRotate_SOURCES = mlRotate.c

all : tests

#a nesting : invoques make on the subdir
tests :
	$(MAKE) $(MAKECMDGOALS) -C $@ MSGSUBDIR=$(MSGSUBDIR)$@/

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all


#as a gneral rule includ must be last : it defines rules, since make execute the first found rule 
#in case of 'make' this can cause you not having the right behaviour
#remember : a Makefile isn't linearly executed....
include ${confiserie}/Makefiles/Makefile.autolib
include ${confiserie}/C/Makefile.beautifull_rules


