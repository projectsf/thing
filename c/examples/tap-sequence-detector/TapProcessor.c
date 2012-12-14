#include <stdlib.h>
#include "TapProcessor.h"
#include "TimeHelpers.h"

static uint32_t TapProcessor_referenceSequenceSize = 0;
static uint32_t* TapProcessor_sampledSequence = NULL;
static uint32_t lastTime = 0;
static uint32_t thisTime = 0;
static uint32_t referenceDelta = 0;
static uint32_t count = 0;

static void TapProcessor_reset();
static const uint8_t* TapProcessor_referenceSequence;


void TapProcessor_initialize(const uint8_t* referenceSequence, uint32_t size)
{
	TapProcessor_referenceSequence = referenceSequence;
	TapProcessor_referenceSequenceSize = size;
	TapProcessor_sampledSequence = (uint32_t*) malloc(size * sizeof(uint32_t));
	lastTime = 0;
	thisTime = 0;
	referenceDelta = 0;
	count = 0;
	
}
void TapProcessor_reset()
{
	lastTime = 0;
	thisTime = 0;
	referenceDelta = 0;
	count = 0;
}

void TapProcessor_tapInitiated()
{
	printf("Tap initiated\n");
	if(count < TapProcessor_referenceSequenceSize)
	{
		TapProcessor_sampledSequence[count++] = getTimeInMillis();
	}
}
void TapProcessor_tapInactivated()
{
	printf("Tap inactive\n");
	//compare results
	unsigned int ii = 0;
	for(ii = 0; ii < TapProcessor_referenceSequenceSize; ++ii)
	{
		printf("Value @ %d : %d\n", ii, TapProcessor_sampledSequence[ii]);
	}

	//reset values
	TapProcessor_reset();
}

