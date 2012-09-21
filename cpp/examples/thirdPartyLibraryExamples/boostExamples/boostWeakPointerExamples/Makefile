SOURCES=./boostWeakPointerExample.cpp
OUTPUTNAME=./run.x
LIBS=-lpthread 
BOOST_INC=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/include
BOOST_LIB=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/lib
#SWITCHES=-Wall -Weffc++ -Wno-comment  -Os -g
SWITCHES=-Wno-comment 


$(OUTPUTNAME): $(SOURCES) 
	g++ -o $(OUTPUTNAME) $(SOURCES) $(LIBS) -I$(BOOST_INC) -L$(BOOST_LIB) $(SWITCHES)

clean:
	rm -f run.x

.PHONY=clean
