SOURCES=./copyConstructor.cpp
OUTPUTNAME=./run.x
CXX=distcc g++

$(OUTPUTNAME): $(SOURCES)
	$(CXX) -o $(OUTPUTNAME) $(SOURCES)

clean:
	rm -f run.x

.PHONY=clean
