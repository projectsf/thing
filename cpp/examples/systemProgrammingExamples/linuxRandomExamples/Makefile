SOURCES=./systemRandomExample.cpp 
OUTPUTNAME=./run.x
LIBS=-lpthread
SWITCHES=-Wall -g


$(OUTPUTNAME): $(SOURCES) 
	g++ -D_REENTRANT -o $(OUTPUTNAME) $(SOURCES) $(LIBS) $(SWITCHES) 

clean:
	rm -f run.x

.PHONY=clean
