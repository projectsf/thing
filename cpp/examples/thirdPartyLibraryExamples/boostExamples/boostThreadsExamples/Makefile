SOURCES=*.cpp
OUTPUTNAME=./run.x
BOOST_INC=/home/maroney/builds/trunk/common/boost
BOOST_LIB=/home/maroney/builds/trunk/host/usr/lib
LIBS=-lboost_thread-gcc-mt-1_33_1 



$(OUTPUTNAME): $(SOURCES)
	g++ -g -o $(OUTPUTNAME) $(SOURCES) -I$(BOOST_INC) -L$(BOOST_LIB) $(LIBS)

clean:
	rm -f run.x

.PHONY=clean
