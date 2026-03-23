********SUITE('23Group12Var1WithIndexSizesLatchOn')********

IAPDUHandler_in_IAPDUHandler1
**pIAPDUHandler= 6421604

    Parse_in_APDUParser_static1
*    **inspect_RSeq**
*    *buffer->buffer_[i]=  c
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  17
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  9
*    *buffer->buffer_[i]=  3
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  64
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  c8
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0

        ParseSinglePass_in_APDUParser_static1
*        *IAPDUHandler* pHandler=0
*        *IWhiteList* pWhiteList=6421604
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  9
*        *buffer->buffer_[i]=  3
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  64
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  c8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *copy
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  9
*        *buffer->buffer_[i]=  3
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  64
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  c8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0

            ParseHeader_in_APDUParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  17
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  9
*            *buffer->buffer_[i]=  3
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  64
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  c8
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0

                ParseObjectHeader_in_ObjectHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  c
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  17
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  9
*                *buffer->buffer_[i]=  3
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  64
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  c8
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
            ParseHeader_in_APDUParser_static2

                GetRecord_in_GroupVariationRecord_static1
*                *uint8_t group= 12
*                *uint8_t variation= 1

                    GetEnumAndType_in_GroupVariationRecord_static1
*                    *uint8_t group= 12
*                    *uint8_t variation= 1

                        GetType_in_GroupVariationRecord_static1
*                        *uint8_t group= 12
*                        *uint8_t variation= 1
*                        *GroupVariationType_OTHER
*                    *GroupVariation_uint16_t enumeration= c01
            ParseHeader_in_APDUParser_static3
            ParseHeader_in_APDUParser_static4

            ParseQualifier_in_APDUParser_static1
*            *QualifierCode_uint8_t tmp =23
@@@@            *QualifierCode_UINT8_CNT_UINT8_INDEX*

            NumParser_in_NumParser1

            ParseHeader_in_CountIndexParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  9
*            *buffer->buffer_[i]=  3
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  64
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  c8
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0

                ParseCount_in_NumParser1
*            *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*            *record.group= 12
*            *record.variation= 1
*            *record.enumeration= 3073
*            *record.GetQualifierCode()= 23

            ParseCountOfObjects_in_CountIndexParser_static1
*            *record->gGroupVariationRecord.enumeration= c01
@@@@            *GroupVariation_Group12Var1

            Process_in_CountIndexParser1
    Parse_in_APDUParser_static2

    ParseSinglePass_in_APDUParser_static1
*    *IAPDUHandler* pHandler=6421604
*    *IWhiteList* pWhiteList=0
*    **inspect_RSeq**
*    *buffer->buffer_[i]=  c
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  17
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  9
*    *buffer->buffer_[i]=  3
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  64
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  c8
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *copy
*    **inspect_RSeq**
*    *buffer->buffer_[i]=  c
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  17
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  9
*    *buffer->buffer_[i]=  3
*    *buffer->buffer_[i]=  1
*    *buffer->buffer_[i]=  64
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  c8
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0
*    *buffer->buffer_[i]=  0

        ParseHeader_in_APDUParser_static1
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  17
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  9
*        *buffer->buffer_[i]=  3
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  64
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  c8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0

            ParseObjectHeader_in_ObjectHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  17
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  9
*            *buffer->buffer_[i]=  3
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  64
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  c8
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
        ParseHeader_in_APDUParser_static2

            GetRecord_in_GroupVariationRecord_static1
*            *uint8_t group= 12
*            *uint8_t variation= 1

                GetEnumAndType_in_GroupVariationRecord_static1
*                *uint8_t group= 12
*                *uint8_t variation= 1

                    GetType_in_GroupVariationRecord_static1
*                    *uint8_t group= 12
*                    *uint8_t variation= 1
*                    *GroupVariationType_OTHER
*                *GroupVariation_uint16_t enumeration= c01
        ParseHeader_in_APDUParser_static3
        ParseHeader_in_APDUParser_static4

        ParseQualifier_in_APDUParser_static1
*        *QualifierCode_uint8_t tmp =23
@@@@        *QualifierCode_UINT8_CNT_UINT8_INDEX*

        NumParser_in_NumParser1

        ParseHeader_in_CountIndexParser_static1
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  9
*        *buffer->buffer_[i]=  3
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  64
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  c8
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0

            ParseCount_in_NumParser1
*        *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*        *record.group= 12
*        *record.variation= 1
*        *record.enumeration= 3073
*        *record.GetQualifierCode()= 23

        ParseCountOfObjects_in_CountIndexParser_static1
*        *record->gGroupVariationRecord.enumeration= c01
@@@@        *GroupVariation_Group12Var1

        Process_in_CountIndexParser1

            InvokeCountOf_for_Group12Var1_in_CountIndexParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  9
*            *buffer->buffer_[i]=  3
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  64
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  c8
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  0

                OnHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler1

                readInvokeCountOf_for_ControlRelayOutputBlock_in_CountIndexParser1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  9
*                *buffer->buffer_[i]=  3
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  64
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  c8
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  0

                Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver1_1

                ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1_1
*            *pControlRelayOutputBlock->rawCode =3

                Read_in_Group12Var1_static1
*                *crob->rawCode= 0
*                *crob->count= 0
*                *crob->onTimeMS= 0
*                *crob->offTimeMS= 0
*                *crob->status= 0

                From_in_ControlRelayOutputBlock_static1

                ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2_1
*                *pControlRelayOutputBlock->rawCode =3

add_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler1

                Record_in_IAPDUHandler1

OnHeaderResult_in_MockApduHeaderHandler1
mock.records.size()=1
REQUIRE(1 == mock.crobRequests.size())
uint16_t size = 1

ControlRelayOutputBlock crob(OperationType::LATCH_ON, TripCloseCode::NUL, false, 1, 100, 200)
REQUIRE((value == mock.crobRequests[0]))
value.index=  9

    ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1_1
**pControlRelayOutputBlock->rawCode =3
value.opType== crob.opType -> true
value.tcc== crob.tcc -> true
value.clear== crob.clear -> true
value.count== crob.count -> true
value.onTime== crob.onTime -> true
value.offTime== crob.offTime -> true
TestComplex('0C 01 17 01 09 03 01 64 00 00 00 C8 00 00 00 00', ParseResult::OK, 1, [](MockApduHeaderHandler& mock)
ParseResult_uint8_t result=  0
