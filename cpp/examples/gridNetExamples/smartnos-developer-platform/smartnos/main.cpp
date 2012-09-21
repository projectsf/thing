#include "SmartNos.hpp"


int main()
{
	SmartNos smartNos;
	smartNos.start();

	//wait for SIGINT
	smartNos.stop();
}
	
