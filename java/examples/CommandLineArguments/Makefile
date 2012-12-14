SOURCES=./src/cat.java
OUTPUTNAME=./run.x
#SWITCHES=-Wno-comment -DPRINT_ONE -DPRINT_TWO 


$(OUTPUTNAME): $(SOURCES) 
	gcj --main=cat -o $(OUTPUTNAME) $(SOURCES)  -v

clean:
	rm -f run.x

.PHONY=clean
