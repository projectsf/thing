SOURCES=./src/thing/main/*.java ./src/thing/common/*.java ./src/thing/servo/*.java
CLASSES=./src/thing/main/*.class ./src/thing/common/*.class ./src/thing/servo/*.class
OUTPUTNAME=./Thing

$(CLASSES): $(SOURCES) Makefile
	echo "building classes"
	gcj --classpath=./src/thing/common $(SOURCES)  -v -C

install: $(CLASSES) 
	echo "building executable"
	gcj --main=Thing -o $(OUTPUTNAME) --classpath=./class $(CLASSES) -v 

clean:
	rm -f $(CLASSES)
	rm -f $(OUTPUTNAME)

.PHONY=clean
