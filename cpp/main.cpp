#include <string>
#include <stdint.h>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;



void original()
{
	uint8_t gradient = 12;
	int32_t tempSlope = 0;
	float slope = 0.0F;
	float worstCaseSlope = 0.0F;
	tempSlope = gradient - 128; // slope readings are offset by 12.8 on L&G meter.
	slope = static_cast< float >( tempSlope );
	worstCaseSlope = ( slope / 10.0F );
	cout << "worstCaseSlope: " << worstCaseSlope << endl;
}

void fix()
{
	uint8_t gradient = 245; //-11
	int32_t tempSlope = 0;
	float slope = 0.0F;
	float worstCaseSlope = 0.0F;
	tempSlope = static_cast<int32_t>(static_cast<int8_t>(gradient));
	slope = static_cast< float >( tempSlope );
	worstCaseSlope = ( slope / 10.0F );
	cout << "worstCaseSlope: " << worstCaseSlope << endl;
}

int main()
{
	original();
	fix();
}

