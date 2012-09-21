SOURCES=ApplicationMessage.cpp ClientSubscriptionMessage.cpp MeteringServiceClient.cpp SmartNosClient.cpp SmartNosApplication.cpp ApplicationEnforcementScheduler.cpp SmartNosPolicyApplication.cpp DomainSocket.cpp DomainServerSocket.cpp DomainClientSocket.cpp
LIBRARYNAME=./libsmartnosapplicationframework.so
SHAREDOBJECTNAME=./smartnosapplicationframework.so
LIBS=-lpthread 
BOOST_INC=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/include
BOOST_LIB=/devel/trees/gen2/trunk/slc-x86/target-x86-slc-devel/bsp-rootfs/usr/lib
#SWITCHES=-Wall -Weffc++ -Wno-comment  -Os -g
SWITCHES=-g -Wno-comment 


$(LIBRARYNAME): $(SOURCES) 
	#g++ -fPIC -c $(SOURCES) $(LIBS) -I$(BOOST_INC) -L$(BOOST_LIB) $(SWITCHES)
	g++ -c $(SOURCES) $(LIBS) -I$(BOOST_INC) -L$(BOOST_LIB) $(SWITCHES)
	g++ -shared -o $(LIBRARYNAME) *.o
	rm -f *.o
	rm -f *.gch

clean:
	rm -f *.o
	rm -f *.so
	rm -f *.gch
