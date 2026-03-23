********SUITE('2parses g50v1 correctly')********

IAPDUHandler_in_IAPDUHandler1
**pIAPDUHandler= 6421152

    @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
    {Parse_in_APDUParser_static1
*    **inspect_RSeq**
*    *buffer->buffer_[i]=  32
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  7
*    *buffer->buffer_[i]=  2
*    *buffer->buffer_[i]=  ab
*    *buffer->buffer_[i]=  ab
*    *buffer->buffer_[i]=  ab
*    *buffer->buffer_[i]=  ab
*    *buffer->buffer_[i]=  ab
*    *buffer->buffer_[i]=  ab
*    *buffer->buffer_[i]=  bc
*    *buffer->buffer_[i]=  bc
*    *buffer->buffer_[i]=  bc
*    *buffer->buffer_[i]=  bc
*    *buffer->buffer_[i]=  bc
*    *buffer->buffer_[i]=  bc

        @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
        {ParseSinglePass_in_APDUParser_static1
*        *IAPDUHandler* pHandler=0
*        *IWhiteList* pWhiteList=6421152
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  32
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *copy
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  32
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  32
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  32
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  7
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 50
*                *uint8_t variation= 1

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 50
*                    *uint8_t variation= 1

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 50
*                        *uint8_t variation= 1
*                        *GroupVariationType_OTHER
*                    *GroupVariation_uint16_t enumeration= 3201

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =7
@@@@                *QualifierCode_UINT8_CNT*

                    NumParser_in_NumParser1

                    {ParseHeader_in_CountParser_static1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  2
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc

                        ParseCount_in_NumParser1
*                    *ParseHeader_in_CountParser_static2
*                    *ParseResult_uint8_t result =0
*                    *uint16_t count =2
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u]', record.group, record.variation
*                    *record.group= 50
*                    *record.variation= 1
*                    *IAPDUHandler* pHandler =0

                        {ParseCountOfObjects_in_CountParser_static1
@@@@                        *GroupVariation_Group50Var1

                            {From_for_Group50Var1_in_CountParser_static1
                            }From_for_Group50Var1_in_CountParser_static_

                            Process_in_CountParser1
                        }ParseCountOfObjects_in_CountParser_static1_
*                    *ParseHeader_in_CountParser_static3
*                    *ParseResult_uint8_t temp =0
                    }ParseHeader_in_CountParser_static1_
                }ParseQualifier_in_APDUParser_static2_
*                *ParseResult_uint8_t tmp= 0
            }ParseHeader_in_APDUParser_static4_
*            *ParseResult_uint8_t tmp= 0
        }ParseSinglePass_in_APDUParser_static2_

        @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
        {ParseSinglePass_in_APDUParser_static1
*        *IAPDUHandler* pHandler=6421152
*        *IWhiteList* pWhiteList=0
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  32
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *copy
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  32
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  ab
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc
*        *buffer->buffer_[i]=  bc

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  32
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  ab
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc
*            *buffer->buffer_[i]=  bc

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  32
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  7
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  ab
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc
*                *buffer->buffer_[i]=  bc

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 50
*                *uint8_t variation= 1

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 50
*                    *uint8_t variation= 1

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 50
*                        *uint8_t variation= 1
*                        *GroupVariationType_OTHER
*                    *GroupVariation_uint16_t enumeration= 3201

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =7
@@@@                *QualifierCode_UINT8_CNT*

                    NumParser_in_NumParser1

                    {ParseHeader_in_CountParser_static1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  2
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  ab
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc
*                    *buffer->buffer_[i]=  bc

                        ParseCount_in_NumParser1
*                    *ParseHeader_in_CountParser_static2
*                    *ParseResult_uint8_t result =0
*                    *uint16_t count =2
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u]', record.group, record.variation
*                    *record.group= 50
*                    *record.variation= 1
*                    *IAPDUHandler* pHandler =6421152

                        {ParseCountOfObjects_in_CountParser_static1
@@@@                        *GroupVariation_Group50Var1

                            {From_for_Group50Var1_in_CountParser_static1
                            }From_for_Group50Var1_in_CountParser_static_

                            Process_in_CountParser1

                                {InvokeCountOf_for_Group50Var1_in_CountParser_static1

                                    {OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler1

                                        {ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler1

{Process_for_DNPTime_in_MockSOEHandler1

fun_for_DNPTime_in_MockSOEHandler1

fun_for_DNPTime_in_MockSOEHandler1
}Process_for_DNPTime_in_MockSOEHandler_
                                        }ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler_

                                        {Record_in_IAPDUHandler1
                                        *Record_in_IAPDUHandler2
                                        *Record_in_IAPDUHandler3

                                            {OnHeaderResult_in_IAPDUHandler1
                                            }OnHeaderResult_in_IAPDUHandler_
                                        }Record_in_IAPDUHandler_
                                    }OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler_
                                }InvokeCountOf_for_Group50Var1_in_CountParser_static_
                        }ParseCountOfObjects_in_CountParser_static1_
*                    *ParseHeader_in_CountParser_static3
*                    *ParseResult_uint8_t temp =0
                    }ParseHeader_in_CountParser_static1_
                }ParseQualifier_in_APDUParser_static2_
*                *ParseResult_uint8_t tmp= 0
            }ParseHeader_in_APDUParser_static4_
*            *ParseResult_uint8_t tmp= 0
        }ParseSinglePass_in_APDUParser_static2_
    }Parse_in_APDUParser_static_
REQUIRE(result == expectedResult)
result= 0
expectedResult= 0
REQUIRE(soe.TotalReceived() == 2)
tmp=  2
REQUIRE(soe.timeSOE.size() == 2)
tmp=  2
REQUIRE(soe.timeSOE[0].value == 0xABABABABABAB)
uint64_t dDNPTime1= abababababab
REQUIRE(soe.timeSOE[1].value == 0xBCBCBCBCBCBC)
uint64_t dDNPTime2= bcbcbcbcbcbc
