SOURCES=./boostPropertyTreeExample.cpp 
OUTPUTNAME=./run.x
BOOST_INC=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/include
BOOST_LIB=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/lib

$(OUTPUTNAME): $(SOURCES)
	g++ -g -o $(OUTPUTNAME) $(SOURCES) -I$(BOOST_INC) -L$(BOOST_LIB) 

clean:
	rm -f run.x

.PHONY=clean
