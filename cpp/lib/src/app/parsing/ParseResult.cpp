#include "header.h"
#include "ParseResult.h"

boolean IsSuccess_in_ParseResult(ParseResult_uint8_t result)
{
    return result == ParseResult_OK;
}
boolean IsFailure_in_ParseResult(ParseResult_uint8_t result)
{
    return result != ParseResult_OK;
}
