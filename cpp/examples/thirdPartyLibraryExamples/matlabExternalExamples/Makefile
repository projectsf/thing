SOURCES=./matlabExternal.cpp
DEPENDENCIES=
OUTPUTNAME=./run.x
MAT_INC=-I/apps/matlab/7.1.0_R14-SP3/extern/include
SWITCHES=-Wall
MAT_LIB_INCL=-L/apps/matlab/7.1.0_R14-SP3/bin/glnx86
LIBS=-lmat -lmx | c++filt


$(OUTPUTNAME): $(SOURCES) $(DEPENDENCIES)
	g++ -ggdb -o $(OUTPUTNAME) $(SOURCES) $(MAT_INC) $(SWITCHES) $(MAT_LIB_INCL) $(LIBS)

clean:
	rm -f run.x

.PHONY=clean
