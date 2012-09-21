SOURCES=./paul-example.cpp
OUTPUTNAME=./run.x
BOOST_INC=-I/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp_rootfs/usr/include
#BOOST_LIB_INCLUDE=-L/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp_rootfs/usr/lib
BOOST_LIB_INCLUDE=-L/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp_rootfs/usr/lib/libboost.a
#BOOST_LIBS=-lboost -lbz2
BOOST_LIBS=


$(OUTPUTNAME): $(SOURCES)
	g++ -g -o $(OUTPUTNAME) $(SOURCES) $(BOOST_INC) $(BOOST_LIB_INCLUDE) $(BOOST_LIBS)

clean:
	rm -f run.x

.PHONY=clean
