#include "TimeHelpers.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t getTimeInMillis()
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	double timeInMillis = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	printf("tv_sec: %d, time in millis: %lf\n", timeInMillis);
	return (uint32_t)timeInMillis;
}
