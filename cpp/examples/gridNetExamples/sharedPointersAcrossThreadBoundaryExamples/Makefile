SOURCES=./Producer.cpp ./Consumer.cpp ./Event.cpp ./ConcreteEvent.cpp  ./main.cpp
OUTPUTNAME=./run.x
INCLUDE=/home/maroney/builds/trunk/host/usr/include
BOOST_INC=/home/maroney/builds/trunk/host/usr/include/boost-1_33_1
BOOST_LIB=/home/maroney/builds/trunk/host/usr/lib
LIBS=-lpthread -lappfw
SWITCHES=-Wall -g


$(OUTPUTNAME): $(SOURCES) ./Producer.h ./Consumer.h ./TestChannel.h ./Event.h ./ConcreteEvent.h
	g++ -o $(OUTPUTNAME) $(SOURCES) -I$(INCLUDE) -I$(BOOST_INC) -L$(BOOST_LIB) $(LIBS) $(SWITCHES) 

clean:
	rm -f run.x

.PHONY=clean
