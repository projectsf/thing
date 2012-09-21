SOURCES=./tierDataExample.cpp
OUTPUTNAME=./run.x
INCLUDE=/devel/trees/gen2/x86/trunk/target-x86-sgc-devel/bsp_rootfs/usr/include
BOOST_INC=/devel/trees/gen2/x86/trunk/target-x86-sgc-devel/bsp_rootfs/usr/include/boost-1_33_1
BOOST_LIB=/devel/trees/gen2/x86/trunk/target-x86-sgc-devel/bsp_rootfs//usr/lib
LIBS=-lpthread -lappfw
SWITCHES=-Wall -g


$(OUTPUTNAME): $(SOURCES) 
	g++ -o $(OUTPUTNAME) $(SOURCES) -I$(INCLUDE) -I$(BOOST_INC) -L$(BOOST_LIB) $(LIBS) $(SWITCHES) 

clean:
	rm -f run.x

.PHONY=clean
