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
#normaly you shou only modify  the test_sources variable to add a test here

#general variables
.PHONY : all test clean debug


#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+=-L../lib -lOpenML
CFLAGS+= -I../include -Wall -Werror-implicit-function-declaration

#here goes your sources
test_sources = todo.c register_test.c version_test.c send_receive_test.c
test_sources += open_close_test.c GetCapabilities_test.c MessageQueue_test.c
test_sources += streamon_test.c mlInit_test.c streamon_test2.c streamoff_test.c
test_sources += messagecount_test.c

test_prog = $(test_sources:%.c=%)


#now the target
all : test
	$(SUCCESSMSG) $<

test : $(test_prog) Makefile

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

#see info make for automatic variable substitution
$(test_prog) : $(shared_sources:%c=%o)

clean :
	$(CLEANINGMSG) $(MSGSUBDIR)
	rm -f *.o $(test_prog)
	rm -Rf .DEP

install :


#as a gneral rule includ must be last : it defines rules, since make execute the first found rule 
#in case of 'make' this can cause you not having the right behaviour
#remember : a Makefile isn't linearly executed....
export TOPSRC_DIR?=$(PWD)
include $(TOPSRC_DIR)/Makefile.confiserie


#create the dependencies (the - is for avoiding it to be too verbose)
-include $(test_sources:%.c=.DEP/%.d)



