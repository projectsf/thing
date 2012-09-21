#include <string>
#include <boost/regex.hpp>
int main()
{
    //uint8_t applicationVersion = extattr::basic::APPLICATION_VERSION;
    //uint8_t hwVersion = extattr::basic::HW_VERSION;
    //std::string manufacturerName(extattr::basic::MANUFACTURER_NAME);
    //std::string modelIdentifier(extattr::basic::MODEL_IDENTIFIER);

    uint8_t applicationVersion = 0;
    uint8_t hwVersion = 0;
    std::string manufacturerName("blah");
    std::string modelIdentifier("blah");
	

    //logDebug("bootedSsid = " << bootedSsid);
    //logDebug("WOW");
    try
    {
        boost::regex pattern("[0-9]");
    }
    catch (...)
    {
        //logError("regex threw exception");
    }
    
    //logDebug("FOO");
    /*

    // :TODO: make this work!
    try
    {
        //logDebug("BAR");
        boost::iterator_range<std::string::iterator> dateCode = boost::algorithm::find_regex(bootedSsid, pattern);
        //logDebug("BAZ");
        //logDebug("dateCode = " << dateCode);
    }
    catch (...)
    {
        logError("DateCode format doesn't exist in SSID");
    }
    */
    //std::string dateCode = boost::algorithm::find_regex(bootedSsid, boost::regex("[0-9]{8}"));
}
