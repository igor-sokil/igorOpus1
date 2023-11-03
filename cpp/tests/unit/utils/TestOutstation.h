#include "OutstationTestObject.h"
#include "DatabaseHelpers.h"
#include "OutstationConfig.h"

void NewTestStaticRead(std::string& request, std::string& response);
void TestTimeAndIntervalRead(std::string& request);

void TestStaticType_for_Analog(OutstationConfig* config,
                    DatabaseConfig* database,
                    double value,
                    std::string& rsp);
void TestStaticAnalog(StaticAnalogVariation_uint8_t variation, double value, std::string& response);
void TestStaticBinaryOutputStatus_for_boolean(boolean value, std::string& response);

void TestStaticAnalogOutputStatus(StaticAnalogOutputStatusVariation_uint8_t variation, double value, std::string& response);
void TestStaticType_for_AnalogOutputStatus(OutstationConfig* config,
                    DatabaseConfig* database,
                    double value,
                    std::string& rsp);
