#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter* This program is free software; you can redistribute it and/or modify
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
.PHONY : all lib clean debug

#load configuration
export TOPSRC_DIR?=../..
include $(TOPSRC_DIR)/Makefile.confiserie

LDFLAGS+= -lpthread
CFLAGS+= -I../../include -Wall -fPIC -Werror-implicit-function-declaration

noinst_so_LIBRARIES += mlplugin-failed1 mlplugin-failed2 mlplugin-failed3
noinst_so_LIBRARIES += mlplugin-failed4 mlplugin-failed5 mlplugin-failed6
noinst_so_LIBRARIES += mlplugin-failed7 mlplugin-failed8 mlplugin-failed9

mlplugin_failed1_SOURCES = mlplugin-failed1.c
mlplugin_failed1_VERSION = 0

mlplugin_failed2_SOURCES = mlplugin-failed2.c
mlplugin_failed2_VERSION = 0

mlplugin_failed3_SOURCES = mlplugin-failed3.c
mlplugin_failed3_VERSION = 0

mlplugin_failed4_SOURCES = mlplugin-failed4.c
mlplugin_failed4_VERSION = 0

mlplugin_failed5_SOURCES = mlplugin-failed5.c
mlplugin_failed5_VERSION = 0

mlplugin_failed6_SOURCES = mlplugin-failed6.c
mlplugin_failed6_VERSION = 0

mlplugin_failed7_SOURCES = mlplugin-failed7.c
mlplugin_failed7_VERSION = 0

mlplugin_failed8_SOURCES = mlplugin-failed8.c
mlplugin_failed8_VERSION = 0

mlplugin_failed9_SOURCES = mlplugin-failed9.c
mlplugin_failed9_VERSION = 0

debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : all

#load helpers makefiles
include ${confiserie}/Makefiles/Makefile.autolib
include ${confiserie}/C/Makefile.beautifull_rules


