CC = g++
INCLUDES=-I. -I/devel/trees/gen2/x86/trunk/target-x86-sgr-devel/bsp_rootfs/usr/include
LIBRARIES=-L /opts/tools/lib -lgsoap++ -L/devel/trees/gen2/x86/trunk/target-x86-sgr-devel/bsp_rootfs/usr/lib

hanClient:
	$(CC) hanClient.cpp jetlunC.cpp jetlunJetlunHanProxy.cpp $(INCLUDES) $(LIBRARIES)
