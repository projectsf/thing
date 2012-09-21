SOURCES=./toneGenerator.cpp 
DEPENDENCIES=
OUTPUTNAME=./run.x
SYSC_INCL=-I/apps/free/systemc/systemc-2.1.1/include
SWITCHES=-Wall -DSC_INCLUDE_FX
SYSC_LIB_INCL=-L/apps/free/systemc/systemc-2.1.1/lib-linux 
SYSC_LIBS=-lsystemc | c++filt

$(OUTPUTNAME): $(SOURCES) $(DEPENDENCIES)
	g++ -o $(OUTPUTNAME) $(SOURCES) $(SYSC_INCL) $(SWITCHES) $(SYSC_LIB_INCL) $(SYSC_LIBS) 
debug:
	g++ -ggdb -o $(OUTPUTNAME) $(SOURCES) $(SYSC_INCL) $(SWITCHES) $(SYSC_LIB_INCL) $(SYSC_LIBS) 

clean:
	rm -f run.x

.PHONY=clean
