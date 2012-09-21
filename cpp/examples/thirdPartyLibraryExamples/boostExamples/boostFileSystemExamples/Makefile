SOURCES=./main.cpp 
OUTPUTNAME=./run.x
BOOST_INC=/apps/free/boost/boost-1.33.1
BOOST_LIB=/apps/free/boost/boost-1.33.1/lib
BOOST_SWITCH=-lboost_filesystem-gcc-1_33_1

$(OUTPUTNAME): $(SOURCES)
	g++ -pg -o $(OUTPUTNAME) $(SOURCES) -I$(BOOST_INC) -L$(BOOST_LIB) $(BOOST_SWITCH)

clean:
	rm -f run.x

.PHONY=clean
