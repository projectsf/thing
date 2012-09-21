SOURCES=./boostSignalsExample.cpp 
OUTPUTNAME=./run.x
BOOST_INC=-I/home/a0871095/opteronPort/boost/boost_1_33_1
BOOST_LIB_INCLUDE=-L/home/a0871095/opteronPort/boost/boost_1_33_1/lib
#BOOST_LIB_INCLUDE=-L/home/a0871095/opteronPort/boost/boost_1_33_1/stage/lib
BOOST_LIBS=-lboost_signals-gcc-1_33_1
CC=g++
CFLAGS=$(BOOST_LIB_INCLUDE) -Wall -ftemplate-depth-100 -O0 -fno-inline -g -fPIC
#CFLAGS=$(BOOST_LIB_INCLUDE) $(BOOST_INC)
LIB=$(BOOST_LIBS)
LINK_OPT =  $(BOOST_LIB_INCLUDE) -g -dynamic

# $(OUTPUTNAME): $(SOURCES)
# 	g++ -o $(OUTPUTNAME) $(SOURCES) $(BOOST_INC) $(BOOST_LIB_INCLUDE) $(BOOST_LIBS)

clean:
	rm -f run.x

.PHONY=clean

.cpp.o:
	$(CC) -c $(CFLAGS) $<

boostSignalsExample.o:	boostSignalsExample.cpp

run.x: boostSignalsExample.o
	$(CC) $(LINK_OPT) -o $@ $^ $(LIB)
	