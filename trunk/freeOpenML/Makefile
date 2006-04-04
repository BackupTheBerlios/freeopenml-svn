# (C) 2005-2005 MALET Jean-Luc aka cityhunter
#this file is provided under the thermes of the BSD licence, you can use it, modify it
#include it into your commercial software as you want

# as a general rule to avoid issues
#    make variables first
#    make rules following (first appearing rule is the default when issuing 'make')
#    includes last


.PHONY : all clean debug install distclean
all :

MSGSUBDIR?=.
#includes
export TOPSRC_DIR?=$(PWD)
include ${TOPSRC_DIR}/Makefile.confiserie

#prevent commands to be outputed,  run make -n to see exactly what is performed
#or comment this during developement
ifndef DEBUG
export MAKEFLAGS+=s
endif

#your subdirs
subdirs = lib 
#drivers tests applications

all :  $(subdirs) runtest

#your subdirs
Makefile.confiserie : ./configure
	./configure

all clean debug install  : $(subdirs)
debug : all

install : ${subdirs}

distclean :
	rm -f  Makefile.confiserie
	rm -f .config.cache

# special rule :: with nothing that follow tells make to rebuild the subdirs everytime
# this rules runs make on the subtree

$(subdirs) ::
	echo ${PWD}/$@/
	test -e $@ || mkdir -p $@
	test -e $@/Makefile || cp ${TOPSRC_DIR}/${MSGSUBDIR}/$@/Makefile $@/Makefile
	$(MAKE) $(MAKECMDGOALS) -C $@ MSGSUBDIR=${MSGSUBDIR}/$@ 
	echo ${PWD}



runtest :
	echo no tests available
	#./test.sh 2>/dev/null

install :
	echo "[ installing ] ftp in /app"
	cp -R ftp /app
	cp -R etc/init.d/* /etc/init.d


include ${confiserie}/Makefiles/Makefile.tags
