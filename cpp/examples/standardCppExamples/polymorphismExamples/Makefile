SOURCES=./*.cpp 
OUTPUTNAME=./run.x
BOOST_INC=/apps/free/boost/boost-1.33.1
BOOST_LIB=/apps/free/local/lib

$(OUTPUTNAME): $(SOURCES)
	g++ -g -o $(OUTPUTNAME) $(SOURCES) -I$(BOOST_INC) -L$(BOOST_LIB)

clean:
	rm -f run.x

.PHONY=clean
