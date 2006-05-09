#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top source dir of the
#* package
#************************************************************************/

#loading configuration file
export TOPSRC_DIR?=..
include $(TOPSRC_DIR)/Makefile.confiserie

#general variables
.PHONY : all test clean debug

#defaut target
all:

#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+= -L../lib -lOpenML
CFLAGS+= -I../include -Wall -Werror-implicit-function-declaration

#here goes your sources
bin_PROGRAMS = oml_capabilites
oml_capabilites_SOURCES = oml_capabilities.c

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

#helper makefiles 
include $(confiserie)/C/Makefile.autoapp
include $(confiserie)/C/Makefile.beautifull_rules



