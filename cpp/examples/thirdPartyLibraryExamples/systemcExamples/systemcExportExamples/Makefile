SOURCES=./sc_main.cpp 
OUTPUTNAME=./run.x
SYSC_INCL=-I/apps/free/systemc/systemc-2.1.1/include
SWITCHES=-pg -Wall
SYSC_LIB_INCL=-L/apps/free/systemc/systemc-2.1.1/lib-linux 
SYSC_LIBS=-lsystemc | c++filt


$(OUTPUTNAME): $(SOURCES) 
	g++ -o $(OUTPUTNAME) $(SOURCES) $(SYSC_INCL) $(SWITCHES) $(SYSC_LIB_INCL) $(SYSC_LIBS)

clean:
	rm -f run.x

.PHONY=clean
