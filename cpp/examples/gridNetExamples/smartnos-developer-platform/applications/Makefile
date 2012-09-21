SOURCES=./main.cpp ./MeterBillingDataReader.cpp
OUTPUTNAME=./MeterBillingDataReader
LIBS=-lpthread -lsmartnosapplicationframework
INCLUDES=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/include
LIB_INCLUDES=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/lib -L../smartnosapplicationframework
#SWITCHES=-Wall -Weffc++ -Wno-comment  -Os -g
SWITCHES=-g -Wno-comment 


$(OUTPUTNAME): $(SOURCES) 
	g++ -o $(OUTPUTNAME) $(SOURCES) $(LIBS) -I$(INCLUDES) -L$(LIB_INCLUDES) $(SWITCHES)

clean:
	rm -f $(OUTPUTNAME)

.PHONY=clean
