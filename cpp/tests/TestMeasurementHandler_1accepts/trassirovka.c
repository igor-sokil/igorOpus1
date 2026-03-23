********SUITE('1accepts')********

@@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
{Parse_in_APDUParser_static1
***inspect_RSeq**

    @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
    {ParseSinglePass_in_APDUParser_static1
*    *IAPDUHandler* pHandler=0
*    *IWhiteList* pWhiteList=6421152
*    **inspect_RSeq**
    }ParseSinglePass_in_APDUParser_static2_

    @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
    {ParseSinglePass_in_APDUParser_static1
*    *IAPDUHandler* pHandler=6421152
*    *IWhiteList* pWhiteList=0
*    **inspect_RSeq**
    }ParseSinglePass_in_APDUParser_static2_
}Parse_in_APDUParser_static_
REQUIRE(result == expectedResult)
result= 0
expectedResult= 0
REQUIRE(soe.TotalReceived() == 0)
tmp=  0
