
#include "MockSOEHandler.h"
//#include "ParseResult.h"
#include "BufferHelpers.h"
#include "MeasurementHandler.h"

ParseResult_uint8_t TestObjectHeaders(std::string& objects,
                              ParseResult_uint8_t expectedResult,
                              void (*verify)(MockSOEHandler*));
