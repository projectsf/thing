SOURCES=./src/Thing.java ./src/CommandProcessor.java
OUTPUTNAME=./Thing


$(OUTPUTNAME): $(SOURCES) 
	gcj --main=Thing -o $(OUTPUTNAME) $(SOURCES)  -v

clean:
	rm -f $(OUTPUTNAME)

.PHONY=clean
