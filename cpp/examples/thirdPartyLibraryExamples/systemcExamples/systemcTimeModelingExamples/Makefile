SOURCES=./sc_main.cpp 
DEPENDENCIES=./*.hpp
OUTPUTNAME=./run.x
SYSC_INCL=-I/apps/free/systemc/systemc-2.1.1/include
SWITCHES=-Wall
SYSC_LIB_INCL=-L/apps/free/systemc/systemc-2.1.1/lib-linux 
SYSC_LIBS=-lsystemc | c++filt
#PURIFY=purify -cache-dir=./ g++
PURIFY=


$(OUTPUTNAME): $(SOURCES) $(DEPENDENCIES)
	$(PURIFY) g++ -ggdb -o $(OUTPUTNAME) $(SOURCES) $(SYSC_INCL) $(SWITCHES) $(SYSC_LIB_INCL) $(SYSC_LIBS)

clean:
	rm -f run.x

.PHONY=clean
