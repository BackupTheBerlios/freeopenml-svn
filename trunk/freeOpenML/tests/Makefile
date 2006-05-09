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
all :

#load configuration file
export TOPSRC_DIR?=..
include $(TOPSRC_DIR)/Makefile.confiserie

#addition to environnement variable, be carefull when nesting subdirs in this makefile
LDFLAGS+=-L../lib -lOpenML -ldl
CFLAGS+= -I../include -Wall -Werror-implicit-function-declaration


noinst_PROGRAMS = todo register_test version_test send_receive_test
noinst_PROGRAMS+= open_close_test GetCapabilities_test MessageQueue_test
noinst_PROGRAMS+= streamon_test mlInit_test streamon_test2 streamoff_test
noinst_PROGRAMS+= messagecount_test

todo_SOURCES                 = todo.c
register_test_SOURCES        = register_test.c
version_test_SOURCES         = version_test.c
send_receive_test_SOURCES    = send_receive_test.c
open_close_test_SOURCES      = open_close_test.c
GetCapabilities_test_SOURCES = GetCapabilities_test.c
MessageQueue_test_SOURCES    = MessageQueue_test.c
streamon_test_SOURCES        = streamon_test.c
mlInit_test_SOURCES          = mlInit_test.c
streamon_test2_SOURCES       = streamon_test2.c
streamoff_test_SOURCES       = streamoff_test.c
messagecount_test_SOURCES    = messagecount_test.c

#a special target : it only modify CFLAGS variables before making it the standard way
debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

#helpers
include ${confiserie}/C/Makefile.autoapp
include ${confiserie}/C/Makefile.beautifull_rules


