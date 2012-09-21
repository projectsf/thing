SOURCES=./anotherMapOfTuplesExample.cpp 
OUTPUTNAME=./run.x
BOOST_INC=/home/maroney/builds/trunk/host/usr/include/boost-1_33_1
BOOST_LIB=/home/maroney/builds/trunk/host/usr/lib

$(OUTPUTNAME): $(SOURCES)
	g++ -g -o $(OUTPUTNAME) $(SOURCES) -I$(BOOST_INC) -L$(BOOST_LIB)

clean:
	rm -f run.x

.PHONY=clean
