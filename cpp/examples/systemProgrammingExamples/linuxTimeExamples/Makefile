SOURCES=./deviceLocalTimeExample.cpp
OUTPUTNAME=./run.x
BOOST_INC=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp_rootfs/usr/include
BOOST_LIB=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp_rootfs/usr/lib
LIBS=
SWITCHES=-Wall -g


$(OUTPUTNAME): $(SOURCES) 
	g++ -o $(OUTPUTNAME) $(SOURCES) $(LIBS) $(SWITCHES) -I$(BOOST_INC) -L$(BOOST_LIB)

clean:
	rm -f run.x

.PHONY=clean
