SOURCES=./src/ThingLogger.java ./src/Thing.java ./src/CommandProcessor.java ./src/CommandListener.java ./src/CommandFactory.java ./src/Command.java ./src/MoveServoCommand.java
OUTPUTNAME=./Thing


$(OUTPUTNAME): $(SOURCES) 
	gcj --main=Thing -o $(OUTPUTNAME) $(SOURCES)  -v

clean:
	rm -f $(OUTPUTNAME)

.PHONY=clean
