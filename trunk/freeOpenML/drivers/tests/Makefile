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

lib_test_sources = mlplugin-failed1.c mlplugin-failed2.c mlplugin-failed3.c
lib_test_sources += mlplugin-failed4.c mlplugin-failed5.c mlplugin-failed6.c
lib_test_sources += mlplugin-failed7.c mlplugin-failed8.c mlplugin-failed9.c


LIB_DIR:=
LIBS:= -lpthread
INCLUDEDIR:= -I../../include

all : plugin

CFLAGS+= $(INCLUDEDIR) -Wall -fPIC -Werror-implicit-function-declaration

plugin : $(lib_test_sources:%.c=../%.so)
	$(SUCCESSMSG) $(MSGSUBDIR)$@

debug : CFLAGS+= -g3 -gdwarf-2 -O0
debug : plugin

clean :
	$(CLEANINGMSG) $(MSGSUBDIR)
	rm -Rf *.o *.so .DEP


-include $(lib_test_sources:%.c=../.DEP/%.d)


#automatic linking
#~ %.so : %.o
	#~ echo "LD $@"
	#~ $(LD)  $(LDFLAGS) $(LIB_DIR) $(LIBS) -Bshareable -o $@ $^


#automatic compilation
../%.so: %.c
	$(CCMESG)  $(MSGSUBDIR)$<
	-rm -f $@
	$(CC) -shared $(CFLAGS) $(INCLUDEDIR) -o $@ $<

#automatic dependencies generation
../.DEP/%.d: %.c
	$(DEPMSG) $(MSGSUBDIR)$<
	mkdir -p .DEP
	$(CC) $(INCLUDEDIR) -M $(CPPFLAGS) $< 2>&- > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
