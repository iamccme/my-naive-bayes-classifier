#############################################################
# friso chinese word segmentation makefile.					#
#		do not use it for commercial use.					#
# @author	chenxin 										#
# @email	chenxin619315@gmail.com   						#
#############################################################

#complie
CC = gcc
#include directory
INCLUDE = .
#complie flags for devolep
CFLAGS = -g -Wall
#complile flags for products
FFLAGS = -O2 -Wall
#extension libs for friso
ELIB = m
LIB_FILE = libfriso.so
LIBRARY_DIR = /usr/lib
INSTALL_DIR = /usr/local/bin


SOURCE = friso.o friso_array.o friso_hash.o friso_lexicon.o friso_link.o friso_string.o

all: share friso

share: $(SOURCE)
	$(CC) $(FFLAGS) $(SOURCE) -fPIC -shared -l$(ELIB) -o $(LIB_FILE)

friso: tst-friso.o
	$(CC) tst-friso.o -o ./friso -L. -lfriso

tst-friso.o: friso_API.h friso.h tst-friso.c
	$(CC) $(FFLAGS) -c tst-friso.c

friso.o: friso.c friso.h friso_API.h
	$(CC) $(FFLAGS) -c friso.c -l$(ELIB)

friso_array.o: friso_array.c friso_API.h
	$(CC) $(FFLAGS) -c friso_array.c

friso_hash.o: friso_hash.c friso_API.h
	$(CC) $(FFLAGS) -c friso_hash.c

friso_lexicon.o: friso_hash.o friso_lexicon.c friso_API.h
	$(CC) $(FFLAGS) -c friso_lexicon.c

friso_link.o: friso_link.c friso_API.h
	$(CC) $(FFLAGS) -c friso_link.c

friso_string.o: friso_string.c friso_API.h
	$(CC) $(FFLAGS) -c friso_string.c

#clean all the object files.
.PHONY: clean
clean:
	-rm friso $(LIB_FILE) $(SOURCE) tst-friso.o

#install friso
install: friso
	@if [ -d $(INSTALL_DIR) ] && [ -d $(LIBRARY_DIR) ];\
		then\
			cp friso $(INSTALL_DIR);\
			chmod a+x $(INSTALL_DIR)/friso;\
			chmod og-w $(INSTALL_DIR)/friso;\
			cp $(LIB_FILE) $(LIBRARY_DIR);\
			chmod a+x $(LIBRARY_DIR)/$(LIB_FILE);\
			chmod og-w $(LIBRARY_DIR)/$(LIB_FILE);\
			echo "install friso successfully.";\
			echo "Usage: friso -init friso configuration file path.";\
		else\
			echo "Sorry, $(INSTALL_DIR) or $(LIBRARY_DIR) does not exits.";\
	fi
