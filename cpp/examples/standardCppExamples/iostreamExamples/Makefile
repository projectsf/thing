SOURCES=./fileIoExample.cpp
BOOST_INC=/devel/trees/gen2/trunk/sgm-x86/target-sgm-x86-devel/include/boost-1_33_1
OUTPUTNAME=./run.x

$(OUTPUTNAME): $(SOURCES)
	g++ -I$(BOOST_INC) -o $(OUTPUTNAME) $(SOURCES)

clean:
	rm -f run.x

.PHONY=clean
