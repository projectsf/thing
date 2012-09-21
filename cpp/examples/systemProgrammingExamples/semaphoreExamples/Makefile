SOURCES=./semaphoreExample.cpp
OUTPUTNAME=./run.x
LIBS=-lpthread
SWITCHES=-Wall -g


$(OUTPUTNAME): $(SOURCES) 
	g++ -o $(OUTPUTNAME) $(SOURCES) $(LIBS) $(SWITCHES) 

clean:
	rm -f run.x

.PHONY=clean
