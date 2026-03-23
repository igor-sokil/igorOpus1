********SUITE('3parses g2v1 w/ invalid timestamp quality')********

IAPDUHandler_in_IAPDUHandler1
**pIAPDUHandler= 6421152

    @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
    {Parse_in_APDUParser_static1
*    **inspect_RSeq**
*    *buffer->buffer_[i]=  2
*    *buffer->buffer_[i]=  2
*    *buffer->buffer_[i]=  17
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  aa
*    *buffer->buffer_[i]=  81
*    *buffer->buffer_[i]=  8
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0

        @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
        {ParseSinglePass_in_APDUParser_static1
*        *IAPDUHandler* pHandler=0
*        *IWhiteList* pWhiteList=6421152
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  aa
*        *buffer->buffer_[i]=  81
*        *buffer->buffer_[i]=  8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *copy
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  aa
*        *buffer->buffer_[i]=  81
*        *buffer->buffer_[i]=  8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  17
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  aa
*            *buffer->buffer_[i]=  81
*            *buffer->buffer_[i]=  8
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  17
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  aa
*                *buffer->buffer_[i]=  81
*                *buffer->buffer_[i]=  8
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 2
*                *uint8_t variation= 2

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 2
*                    *uint8_t variation= 2

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 2
*                        *uint8_t variation= 2
*                        *GroupVariationType_EVENT
*                    *GroupVariation_uint16_t enumeration= 202

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =23
@@@@                *QualifierCode_UINT8_CNT_UINT8_INDEX*

                    NumParser_in_NumParser1

                    ParseHeader_in_CountIndexParser_static1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  1
*                    *buffer->buffer_[i]=  aa
*                    *buffer->buffer_[i]=  81
*                    *buffer->buffer_[i]=  8
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0

                        ParseCount_in_NumParser1
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                    *record.group= 2
*                    *record.variation= 2
*                    *record.enumeration= 514
*                    *record.GetQualifierCode()= 23

                    ParseCountOfObjects_in_CountIndexParser_static1
*                    *record->gGroupVariationRecord.enumeration= 202
@@@@                    *GroupVariation_Group2Var2

                    Process_in_CountIndexParser1
                }ParseQualifier_in_APDUParser_static6_
*                *ParseResult_uint8_t tmp= 0
            }ParseHeader_in_APDUParser_static4_
*            *ParseResult_uint8_t tmp= 0
        }ParseSinglePass_in_APDUParser_static2_

        @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
        {ParseSinglePass_in_APDUParser_static1
*        *IAPDUHandler* pHandler=6421152
*        *IWhiteList* pWhiteList=0
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  aa
*        *buffer->buffer_[i]=  81
*        *buffer->buffer_[i]=  8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *copy
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  aa
*        *buffer->buffer_[i]=  81
*        *buffer->buffer_[i]=  8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  17
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  aa
*            *buffer->buffer_[i]=  81
*            *buffer->buffer_[i]=  8
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  17
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  aa
*                *buffer->buffer_[i]=  81
*                *buffer->buffer_[i]=  8
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 2
*                *uint8_t variation= 2

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 2
*                    *uint8_t variation= 2

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 2
*                        *uint8_t variation= 2
*                        *GroupVariationType_EVENT
*                    *GroupVariation_uint16_t enumeration= 202

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =23
@@@@                *QualifierCode_UINT8_CNT_UINT8_INDEX*

                    NumParser_in_NumParser1

                    ParseHeader_in_CountIndexParser_static1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  1
*                    *buffer->buffer_[i]=  aa
*                    *buffer->buffer_[i]=  81
*                    *buffer->buffer_[i]=  8
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0

                        ParseCount_in_NumParser1
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                    *record.group= 2
*                    *record.variation= 2
*                    *record.enumeration= 514
*                    *record.GetQualifierCode()= 23

                    ParseCountOfObjects_in_CountIndexParser_static1
*                    *record->gGroupVariationRecord.enumeration= 202
@@@@                    *GroupVariation_Group2Var2

                    Process_in_CountIndexParser1

                        OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler1

                        {Record_in_IAPDUHandler1
                        *Record_in_IAPDUHandler2
                        *Record_in_IAPDUHandler3

                            {OnHeaderResult_in_IAPDUHandler1
                            }OnHeaderResult_in_IAPDUHandler_
                        }Record_in_IAPDUHandler_
                }ParseQualifier_in_APDUParser_static6_
*                *ParseResult_uint8_t tmp= 0
            }ParseHeader_in_APDUParser_static4_
*            *ParseResult_uint8_t tmp= 0
        }ParseSinglePass_in_APDUParser_static2_
    }Parse_in_APDUParser_static_
REQUIRE(result == expectedResult)
result= 0
expectedResult= 0
REQUIRE(soe.TotalReceived() == 1)
tmp=  1
REQUIRE(soe.binarySOE.size() == 1)
tmp=  1
REQUIRE(record->second.meas.time.quality == TimestampQuality::SYNCHRONIZED)
tmp=  1
TimestampQuality::SYNCHRONIZED=  1
REQUIRE(record->second.meas.time.value == 8)
tmp=  8
