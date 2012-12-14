#include "TapSimulator.h"
#include <time.h>

static void(*TapSimulator_tapInitiated)() = NULL;
static void(*TapSimulator_tapInactivated)() = NULL;
static uint8_t TapSimulator_sequenceSize = 0;


void TapSimulator_initialize(void(*tapInitiated)(), void(*tapInactivated)(), uint8_t sequenceSize)
{
	TapSimulator_tapInitiated = tapInitiated;
	TapSimulator_tapInactivated = tapInactivated;
	TapSimulator_sequenceSize = sequenceSize;
}

void TapSimulator_run()
{
	uint32_t sleepTimeMillis = 0;
	while(1)
	{
		unsigned int ii = 0;
		for (ii = 0; ii < TapSimulator_sequenceSize; ++ii)
		{
			sleepTimeMillis = rand() % 1000;
			usleep(sleepTimeMillis * 1000);
			TapSimulator_tapInitiated();
		}

		sleep(1);
		TapSimulator_tapInactivated();

		//wait for user input
	}
}




