#/***********************************************************************
#* copyright (c) 2004 MALET Jean-luc aka cityhunter
#* This program is free software; you can redistribute it and/or modify
#* it under the terms of the artistic license as published in the top 
#* source dir of the package
#************************************************************************/

.PHONY : all clean debug install $(target)


#prevent commands to be outputed,  run make -n to see exactly what is performed
#or comment this during developement
export MAKEFLAGS+=s

#your subdirs
target = lib drivers tests applications

all :  $(target) 

#your targets
Makefile.confiserie : ./configure
	./configure
	
debug : all

clean : $(target)
	rm Makefile.confiserie

install: $(target)
	$(INSTALLMSG) include in  $(INSTALL_PREFIX)/include"
	mkdir -p $(INSTALL_PREFIX)/include/OpenML
	$(INSTALL) -C include/OpenML/* $(INSTALL_PREFIX)/include/OpenML
	$(INSTALL) -C include/fourcc.h $(INSTALL_PREFIX)/include

#special rule :: with nothing that follow tells make to rebuild the target everytime
#this rules runs make on the subtree
$(target) ::
	$(MAKE) $(MAKECMDGOALS) -C $@ MSGSUBDIR=$@/

runtest :
	./test.sh 2>/dev/null


#as a gneral rule includ must be last : it defines rules, since make execute the first found rule 
#in case of 'make' this can cause you not having the right behaviour
#remember : a Makefile isn't linearly executed....
export TOPSRC_DIR?=$(PWD)
include $(TOPSRC_DIR)/Makefile.confiserie


#your targets
$(TOPSRC_DIR)/Makefile.confiserie : ./configure
	./configure
