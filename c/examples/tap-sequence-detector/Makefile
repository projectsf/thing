SOURCES=./main.c ./TapProcessor.c ./TapSimulator.c ./TimeHelpers.c
OUTPUTNAME=./run.x
SWITCHES=


$(OUTPUTNAME): $(SOURCES) 
	gcc -o $(OUTPUTNAME) $(SOURCES) $(LIBS) $(SWITCHES)

clean:
	rm -f run.x

.PHONY=clean
