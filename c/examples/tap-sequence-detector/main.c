#include <stdio.h> 
#include <stdint.h>
#include "TapSimulator.h"
#include "TapProcessor.h"


int main()
{
	uint8_t sequenceSize = 5;
	uint8_t sequence[5] = {4,2,4,2,4}; //in units of 16th notes 

	TapSimulator_initialize(TapProcessor_tapInitiated, TapProcessor_tapInactivated, sequenceSize);
	TapProcessor_initialize(sequence, sequenceSize);

	//this is another thread (asynchronous to main)
	TapSimulator_run();

	while(1)
	{
	}
}
