SOURCES=./dynamicThreadExample.cpp 
DEPENDENCIES=./*.hpp
OUTPUTNAME=./run.x
SYSC_INCL=-I/apps/free/systemc/systemc-2.1.1/include
SWITCHES=-Wall
SYSC_LIB_INCL=-L/apps/free/systemc/systemc-2.1.1/lib-linux 
SYSC_LIBS=-lsystemc | c++filt
DEFINES=-DSC_INCLUDE_DYNAMIC_PROCESSES


$(OUTPUTNAME): $(SOURCES) $(DEPENDENCIES)
	g++ -ggdb -o $(OUTPUTNAME) $(SOURCES) $(SYSC_INCL) $(DEFINES) $(SWITCHES) $(SYSC_LIB_INCL) $(SYSC_LIBS)

clean:
	rm -f run.x

.PHONY=clean
