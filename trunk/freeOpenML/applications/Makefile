#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top source dir of the
#* package
#************************************************************************/

#normaly you shou only modify  the test_sources variable to add a test here

#general variables
.PHONY : all test clean debug


#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+= -L../lib -lOpenML
CFLAGS+= -I../include -Wall -Werror-implicit-function-declaration

#here goes your sources
oml_capabilites_sources = oml_capabilities.c

programms = oml_capabilities


#now the target
all : $(programms)
	$(SUCCESSMSG) $<
	
oml_capabilites : $(oml_capabilites_sources:%.c=%.o)
	$(CCMESG) $@
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<


#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

#see info make for automatic variable substitution
$(test_prog) : $(shared_sources:%c=%o)

clean :
	$(CLEANINGMSG) $(MSGSUBDIR)
	rm -f *.o $(programms)
	rm -Rf .DEP

install :


#as a gneral rule includ must be last : it defines rules, since make execute the first found rule 
#in case of 'make' this can cause you not having the right behaviour
#remember : a Makefile isn't linearly executed....
export TOPSRC_DIR?=$(PWD)
include $(TOPSRC_DIR)/Makefile.confiserie


#create the dependencies (the - is for avoiding it to be too verbose)
-include $(oml_capabilites_sources:%.c=.DEP/%.d)



