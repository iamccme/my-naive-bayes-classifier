#############################################################
#  my-naive-bayes-classifier makefile.					    #
#		do not use it for commercial use.					#
# @author	chencheng 										#
# @email	chencheng1022@gmail.com   						#
#############################################################

#complie
CC = g++
#include directory
INCLUDE = ./
#complie flags for devolep
CFLAGS = -g -Wall
#complile flags for products
FFLAGS = -O2 -Wall
#extension libs for friso
ELIB = m
LIB_FILE = libclassifier.so
LOCAL_LIB_DIR=./lib
LIBRARY_DIR = /usr/lib/
INSTALL_DIR = /usr/local/bin


SOURCE = BayesClassifier.o TrainingDataManager.o PriorProbability.o ClassConditionalProbability.o ChineseSpliter.o 

all: share classifier

share: $(SOURCE)
	$(CC) $(FFLAGS) $(SOURCE) -fPIC -shared -L$(LOCAL_LIB_DIR) -lfriso -lboost_system -lboost_filesystem -o $(LIB_FILE)


classifier: tst-classifier.o 
	$(CC) tst-classifier.o -o ./classifier -L. -lclassifier

tst-classifier.o: tst-classifier.cpp
	$(CC) $(FFLAGS) -c tst-classifier.cpp
	#$(CC) ChineseSpliter.o -o ./CS -L$(LOCAL_LIB_DIR) -lfriso
	#$(CC) TrainingDataManager.o PriorProbability.o -o ./PP -lboost_system -lboost_filesystem
	#$(CC) TrainingDataManager.o ClassConditionalProbability.o -o ./CCP -lboost_system -lboost_filesystem

BayesClassifier.o: BayesClassifier.cpp
	$(CC) $(FFLAGS) -c BayesClassifier.cpp

ChineseSpliter.o: ChineseSpliter.cpp
	$(CC) $(FFLAGS) -c ChineseSpliter.cpp

TrainingDataManager.o: TrainingDataManager.cpp 
	##$(CC) $(FFLAGS) TrainingDataManager.cpp -o ./TD -I$(BOOST_INCLUDE) -L$(BOOST_LIB) -lboost_system -lboost_filesystem
	$(CC) $(FFLAGS) -c TrainingDataManager.cpp

PriorProbability.o: PriorProbability.cpp
	$(CC) $(FFLAGS) -c PriorProbability.cpp

ClassConditionalProbability.o: ClassConditionalProbability.cpp
	$(CC) $(FFLAGS) -c ClassConditionalProbability.cpp

#clean all the object files.
.PHONY: clean
clean:
	-rm classifier $(LIB_FILE) $(SOURCE) tst-classifier.o

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
