SOURCES=./port_sc_main.cpp 
DEPENDENCIES=./*.hpp
OUTPUTNAME=./run.x
SYSC_INCL=-I/apps/free/systemc/systemc-2.1.1/include
SWITCHES=-Wall
SYSC_LIB_INCL=-L/apps/free/systemc/systemc-2.1.1/lib-linux 
SYSC_LIBS=-lsystemc | c++filt
BOOST_INC=-I/apps/free/boost/boost-1.33.1
BOOST_LIB_INC=-L/apps/free/local/lib


$(OUTPUTNAME): $(SOURCES) $(DEPENDENCIES)
	g++ -ggdb -o $(OUTPUTNAME) $(SOURCES) $(SYSC_INCL) $(BOOST_INC) $(SWITCHES) $(SYSC_LIB_INCL) $(BOOST_LIB_INC) $(SYSC_LIBS)

clean:
	rm -f run.x

.PHONY=clean
