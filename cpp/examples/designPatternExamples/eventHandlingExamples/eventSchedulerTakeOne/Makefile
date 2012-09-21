SOURCES=./*.cpp 
OUTPUTNAME=./run.x
BOOST_INC=-I/home/maroney/builds/trunk/common/boost/boost
BOOST_LIB=-L/home/maroney/builds/trunk/host/usr/lib -Wl,-rpath,/home/maroney/builds/trunk/host/usr/lib
LIBS=-lpthread -lboost_thread-gcc-mt-1_33_1 


$(OUTPUTNAME): $(SOURCES)
	g++ -x c++ -g -o $(OUTPUTNAME) $(SOURCES) $(BOOST_INC) $(BOOST_LIB) $(BOOST_LINK_LIB) $(LIBS)

clean:
	rm -f run.x

.PHONY=clean
