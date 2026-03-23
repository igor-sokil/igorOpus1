********SUITE('6parses g2v3 w/ unsynchronized CTO')********

IAPDUHandler_in_IAPDUHandler1
**pIAPDUHandler= 6421152

    @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
    {Parse_in_APDUParser_static1
*    **inspect_RSeq**
*    @*buffer->buffer_[i]= 33
*    @*buffer->buffer_[i]= 2
*    @*buffer->buffer_[i]= 7
*    @*buffer->buffer_[i]= 1
*    @*buffer->buffer_[i]= 7
*    @*buffer->buffer_[i]= 0
*    @*buffer->buffer_[i]= 0
*    @*buffer->buffer_[i]= 0
*    @*buffer->buffer_[i]= 0
*    @*buffer->buffer_[i]= 0
*    @*buffer->buffer_[i]= 2
*    @*buffer->buffer_[i]= 3
*    @*buffer->buffer_[i]= 17
*    @*buffer->buffer_[i]= 1
*    @*buffer->buffer_[i]= 8
*    @*buffer->buffer_[i]= 81
*    @*buffer->buffer_[i]= 1
*    @*buffer->buffer_[i]= 0

        @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
        {ParseSinglePass_in_APDUParser_static1
*        *IAPDUHandler* pHandler=0
*        *IWhiteList* pWhiteList=6421152
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 33
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 17
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 8
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 0
*        *copy
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 33
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 17
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 8
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 0

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 33
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 7
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 7
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 3
*            @*buffer->buffer_[i]= 17
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 8
*            @*buffer->buffer_[i]= 81
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 33
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 7
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 7
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 3
*                @*buffer->buffer_[i]= 17
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 8
*                @*buffer->buffer_[i]= 81
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 0
@@@@                *read_in_UInt8_static = 6421440<-51
@@@@                *read_in_UInt8_static = 6421441<-2
@@@@                *read_in_UInt8_static = 6421442<-7

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 51
*                *uint8_t variation= 2

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 51
*                    *uint8_t variation= 2

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 51
*                        *uint8_t variation= 2
*                        *GroupVariationType_OTHER
*                    *GroupVariation_uint16_t enumeration= 3302

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =7
@@@@                *QualifierCode_UINT8_CNT*

                    NumParser_in_NumParser1

                    {ParseHeader_in_CountParser_static1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 7
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 2
*                    @*buffer->buffer_[i]= 3
*                    @*buffer->buffer_[i]= 17
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 8
*                    @*buffer->buffer_[i]= 81
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 0

                        ParseCount_in_NumParser1
@@@@                        *read_in_UInt8_static = 6421443<-1
*                    *ParseHeader_in_CountParser_static2
*                    *ParseResult_uint8_t result =0
*                    *uint16_t count =1
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u]', record.group, record.variation
*                    *record.group= 51
*                    *record.variation= 2
*                    *IAPDUHandler* pHandler =0

                        {ParseCountOfObjects_in_CountParser_static1
@@@@                        *GroupVariation_Group51Var2

                            Process_in_CountParser1
                        }ParseCountOfObjects_in_CountParser_static4_
*                    *ParseHeader_in_CountParser_static3
*                    *ParseResult_uint8_t temp =0
                    }ParseHeader_in_CountParser_static1_
                }ParseQualifier_in_APDUParser_static2_
*                *ParseResult_uint8_t tmp= 0
            }ParseHeader_in_APDUParser_static4_
*            *ParseResult_uint8_t tmp= 0
*        *copy
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 17
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 8
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 0

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 3
*            @*buffer->buffer_[i]= 17
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 8
*            @*buffer->buffer_[i]= 81
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 3
*                @*buffer->buffer_[i]= 17
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 8
*                @*buffer->buffer_[i]= 81
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 0
@@@@                *read_in_UInt8_static = 6421450<-2
@@@@                *read_in_UInt8_static = 6421451<-3
@@@@                *read_in_UInt8_static = 6421452<-23

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 2
*                *uint8_t variation= 3

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 2
*                    *uint8_t variation= 3

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 2
*                        *uint8_t variation= 3
*                        *GroupVariationType_EVENT
*                    *GroupVariation_uint16_t enumeration= 203

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =23
@@@@                *QualifierCode_UINT8_CNT_UINT8_INDEX*

                    NumParser_in_NumParser1

                    ParseHeader_in_CountIndexParser_static1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 8
*                    @*buffer->buffer_[i]= 81
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 0

                        ParseCount_in_NumParser1
@@@@                        *read_in_UInt8_static = 6421453<-1
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                    *record.group= 2
*                    *record.variation= 3
*                    *record.enumeration= 515
*                    *record.GetQualifierCode()= 23

                    ParseCountOfObjects_in_CountIndexParser_static1
*                    *record->gGroupVariationRecord.enumeration= 203
@@@@                    *GroupVariation_Group2Var3

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
*        @*buffer->buffer_[i]= 33
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 17
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 8
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 0
*        *copy
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 33
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 7
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 17
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 8
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 0

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 33
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 7
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 7
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 0
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 3
*            @*buffer->buffer_[i]= 17
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 8
*            @*buffer->buffer_[i]= 81
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 33
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 7
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 7
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 0
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 3
*                @*buffer->buffer_[i]= 17
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 8
*                @*buffer->buffer_[i]= 81
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 0
@@@@                *read_in_UInt8_static = 6421440<-51
@@@@                *read_in_UInt8_static = 6421441<-2
@@@@                *read_in_UInt8_static = 6421442<-7

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 51
*                *uint8_t variation= 2

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 51
*                    *uint8_t variation= 2

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 51
*                        *uint8_t variation= 2
*                        *GroupVariationType_OTHER
*                    *GroupVariation_uint16_t enumeration= 3302

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =7
@@@@                *QualifierCode_UINT8_CNT*

                    NumParser_in_NumParser1

                    {ParseHeader_in_CountParser_static1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 7
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 0
*                    @*buffer->buffer_[i]= 2
*                    @*buffer->buffer_[i]= 3
*                    @*buffer->buffer_[i]= 17
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 8
*                    @*buffer->buffer_[i]= 81
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 0

                        ParseCount_in_NumParser1
@@@@                        *read_in_UInt8_static = 6421443<-1
*                    *ParseHeader_in_CountParser_static2
*                    *ParseResult_uint8_t result =0
*                    *uint16_t count =1
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u]', record.group, record.variation
*                    *record.group= 51
*                    *record.variation= 2
*                    *IAPDUHandler* pHandler =6421152

                        {ParseCountOfObjects_in_CountParser_static1
@@@@                        *GroupVariation_Group51Var2

                            Process_in_CountParser1

                                OnHeader_CountHeader_for_Group51Var2_in_IAPDUHandler1

                                    {Record_in_IAPDUHandler1
                                    *Record_in_IAPDUHandler2
                                    *Record_in_IAPDUHandler3

                                        {OnHeaderResult_in_IAPDUHandler1
                                        }OnHeaderResult_in_IAPDUHandler_
                                    }Record_in_IAPDUHandler_
                                OnHeader_CountHeader_for_Group51Var2_in_IAPDUHandler_
                        }ParseCountOfObjects_in_CountParser_static4_
*                    *ParseHeader_in_CountParser_static3
*                    *ParseResult_uint8_t temp =0
                    }ParseHeader_in_CountParser_static1_
                }ParseQualifier_in_APDUParser_static2_
*                *ParseResult_uint8_t tmp= 0
            }ParseHeader_in_APDUParser_static4_
*            *ParseResult_uint8_t tmp= 0
*        *copy
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 17
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 8
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 0

            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
            {ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 3
*            @*buffer->buffer_[i]= 17
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 8
*            @*buffer->buffer_[i]= 81
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 3
*                @*buffer->buffer_[i]= 17
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 8
*                @*buffer->buffer_[i]= 81
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 0
@@@@                *read_in_UInt8_static = 6421450<-2
@@@@                *read_in_UInt8_static = 6421451<-3
@@@@                *read_in_UInt8_static = 6421452<-23

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 2
*                *uint8_t variation= 3

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 2
*                    *uint8_t variation= 3

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 2
*                        *uint8_t variation= 3
*                        *GroupVariationType_EVENT
*                    *GroupVariation_uint16_t enumeration= 203

                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                {ParseQualifier_in_APDUParser_static1
*                *QualifierCode_uint8_t tmp =23
@@@@                *QualifierCode_UINT8_CNT_UINT8_INDEX*

                    NumParser_in_NumParser1

                    ParseHeader_in_CountIndexParser_static1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 8
*                    @*buffer->buffer_[i]= 81
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 0

                        ParseCount_in_NumParser1
@@@@                        *read_in_UInt8_static = 6421453<-1
*                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                    *record.group= 2
*                    *record.variation= 3
*                    *record.enumeration= 515
*                    *record.GetQualifierCode()= 23

                    ParseCountOfObjects_in_CountIndexParser_static1
*                    *record->gGroupVariationRecord.enumeration= 203
@@@@                    *GroupVariation_Group2Var3

                    Process_in_CountIndexParser1

                        OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler1

                        {ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler1

                            {ProcessWithCTO_for_Binary_in_MeasurementHandler1
                            *ProcessWithCTO_for_Binary_in_MeasurementHandler2
*                            **inspect_DNPTime**
*                            @*uint64_t value= 7
*                            @*TimestampQuality_uint8_t quality= 2

                                {LoadValues_for_Binary_in_MeasurementHandler1

{RecordAny_for_Binary_in_MockSOEHandler1
@@@@                                *read_in_UInt8_static = 6421454<-8
@@@@                                *read_in_UInt8_static = 6421455<-129
@@@@                                *read_from_in_UInt16_static = 6421456<-1

                                    {transform_Indexed_for_Binary_in_MeasurementHandler1
*                                    **inspect_Indexed_for_Binary**
*                                    @*uint16_t index= 8
*                                    **inspect_Binary**
*                                    @*boolean value= 1
*                                    @*Flags flags.value= 129
*                                    @*DNPTime timeDNPTime.value= 1
*                                    @*DNPTime timeDNPTime.quality= 1
                                    *transform_Indexed_for_Binary_in_MeasurementHandler2
*                                    **inspect_DNPTime**
*                                    @*uint64_t value= 7
*                                    @*TimestampQuality_uint8_t quality= 2
*                                    **inspect_Indexed_for_Binary**
*                                    @*uint16_t index= 8
*                                    **inspect_Binary**
*                                    @*boolean value= 1
*                                    @*Flags flags.value= 129
*                                    @*DNPTime timeDNPTime.value= 8
*                                    @*DNPTime timeDNPTime.quality= 2
                                    }transform_Indexed_for_Binary_in_MeasurementHandler_

{process_for_Binary_in_MockSOEHandler1

}process_for_Binary_in_MockSOEHandler_
}RecordAny_for_Binary_in_MockSOEHandler_
                                }LoadValues_for_Binary_in_MeasurementHandler_
                            }ProcessWithCTO_for_Binary_in_MeasurementHandler2_
                        }ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler1_

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
REQUIRE(record->second.meas.time.quality == TimestampQuality::UNSYNCHRONIZED)
tmp=  2
TimestampQuality::UNSYNCHRONIZED=  2
REQUIRE(record->second.meas.time.value == 8)
tmp=  8
