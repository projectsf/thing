#include <string>

class MeteringServiceClient
{
	public :
		MeteringServiceClient();
		void getBillingData(std::string& billingData);

	private :
		const std::string billingDataFileName;
};

