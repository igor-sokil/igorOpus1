********SUITE('27TimeAndIntervalViaIntegrity')********

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048
**uint8_t bytes[SIZE_BufferSer4]=6419952

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6419952->192
    }SetControl_in_APDUWrapper_

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6419953->1
    }SetFunction_in_APDUWrapper_

    WriteClassHeaders_in_APDUBuilders_static1

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 2
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419954->60
@@@@        *write_in_UInt8_static = 6419955->2
@@@@        *write_in_UInt8_static = 6419956->6

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 3
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419957->60
@@@@        *write_in_UInt8_static = 6419958->3
@@@@        *write_in_UInt8_static = 6419959->6

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 4
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419960->60
@@@@        *write_in_UInt8_static = 6419961->4
@@@@        *write_in_UInt8_static = 6419962->6

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 1
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419963->60
@@@@        *write_in_UInt8_static = 6419964->1
@@@@        *write_in_UInt8_static = 6419965->6

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406472
}MockExecutor_in_MockExecutor_

    {OContext_in_OContext1

        EventLists_in_EventLists1
        TotalEvents_in_EventBufferConfig1
*        *pEventBufferConfig->maxBinaryEvents= 0
*        *pEventBufferConfig->maxDoubleBinaryEvents=0
*        *pEventBufferConfig->maxAnalogEvents= 0
*        *pEventBufferConfig->maxCounterEvents= 0
*        *pEventBufferConfig->maxBinaryOutputStatusEvents= 0
*        *pEventBufferConfig->maxAnalogOutputStatusEvents= 0
*        *pEventBufferConfig->maxOctetStringEvents= 0

        List_for_EventRecord_in_List_for_EventRecordOver2_1
*        *uint32_t maxSize= 0

        List_for_EventRecord_in_List_for_EventRecordOver1_1

        Database_in_Database1

        StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2_1
*        *config.size()= 1

        StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*        *config.size()= 0

        DeferredRequest_in_DeferredRequest1
*        *uint32_t maxAPDUSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6415742

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6417882

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6419970

        {Inst_in_StateIdle_static1

            StateIdle_in_StateIdle1

                OutstationState_in_OutstationState1
        }Inst_in_StateIdle_static_
    }OContext_in_OContext_
}OutstationTestObject_in_OutstationTestObject_

{LowerLayerUp_in_OutstationTestObject1

    {OnLowerLayerUp_in_OContext1

        {CheckForTaskStart_in_OContext1

            {CheckForDeferredRequest_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnLowerLayerUp_in_OContext_
}LowerLayerUp_in_OutstationTestObject_

{Transaction_in_OutstationTestObject1

    {HandleNewEvents_in_OContext1

        {CheckForTaskStart_in_OContext1

            {CheckForDeferredRequest_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= c0
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 3c
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 6
*        @*buffer->buffer_[i]= 3c
*        @*buffer->buffer_[i]= 3
*        @*buffer->buffer_[i]= 6
*        @*buffer->buffer_[i]= 3c
*        @*buffer->buffer_[i]= 4
*        @*buffer->buffer_[i]= 6
*        @*buffer->buffer_[i]= 3c
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= c0
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 3c
*            @*buffer->buffer_[i]= 2
*            @*buffer->buffer_[i]= 6
*            @*buffer->buffer_[i]= 3c
*            @*buffer->buffer_[i]= 3
*            @*buffer->buffer_[i]= 6
*            @*buffer->buffer_[i]= 3c
*            @*buffer->buffer_[i]= 4
*            @*buffer->buffer_[i]= 6
*            @*buffer->buffer_[i]= 3c
*            @*buffer->buffer_[i]= 1
*            @*buffer->buffer_[i]= 6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext8

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6417883->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 3c
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 6
*                                    @*buffer->buffer_[i]= 3c
*                                    @*buffer->buffer_[i]= 3
*                                    @*buffer->buffer_[i]= 6
*                                    @*buffer->buffer_[i]= 3c
*                                    @*buffer->buffer_[i]= 4
*                                    @*buffer->buffer_[i]= 6
*                                    @*buffer->buffer_[i]= 3c
*                                    @*buffer->buffer_[i]= 1
*                                    @*buffer->buffer_[i]= 6
                                    *HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 0

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 0

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 0

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6402972

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 3c
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 6
*                                        @*buffer->buffer_[i]= 3c
*                                        @*buffer->buffer_[i]= 3
*                                        @*buffer->buffer_[i]= 6
*                                        @*buffer->buffer_[i]= 3c
*                                        @*buffer->buffer_[i]= 4
*                                        @*buffer->buffer_[i]= 6
*                                        @*buffer->buffer_[i]= 3c
*                                        @*buffer->buffer_[i]= 1
*                                        @*buffer->buffer_[i]= 6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6402972
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 3
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 3
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 3
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 4
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 2
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 3
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 4
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404064<-60
@@@@                                                    *read_in_UInt8_static = 6404065<-2
@@@@                                                    *read_in_UInt8_static = 6404066<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 2

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 2

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 2
*                                                            *GroupVariationType_EVENT
*                                                        *GroupVariation_uint16_t enumeration= 3c02

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=2
*                                                        *record->gGroupVariationRecord.enumeration=3c02
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 3
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 3
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 4
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 3
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 4
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404067<-60
@@@@                                                    *read_in_UInt8_static = 6404068<-3
@@@@                                                    *read_in_UInt8_static = 6404069<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 3

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 3

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 3
*                                                            *GroupVariationType_EVENT
*                                                        *GroupVariation_uint16_t enumeration= 3c03

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=3
*                                                        *record->gGroupVariationRecord.enumeration=3c03
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 4
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 4
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404070<-60
@@@@                                                    *read_in_UInt8_static = 6404071<-4
@@@@                                                    *read_in_UInt8_static = 6404072<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 4

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 4

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 4
*                                                            *GroupVariationType_EVENT
*                                                        *GroupVariation_uint16_t enumeration= 3c04

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=4
*                                                        *record->gGroupVariationRecord.enumeration=3c04
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404073<-60
@@@@                                                    *read_in_UInt8_static = 6404074<-1
@@@@                                                    *read_in_UInt8_static = 6404075<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 1

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 1

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 1
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 3c01

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=1
*                                                        *record->gGroupVariationRecord.enumeration=3c01
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6402972
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 3
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 3
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 3
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 4
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 2
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 3
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 4
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404064<-60
@@@@                                                    *read_in_UInt8_static = 6404065<-2
@@@@                                                    *read_in_UInt8_static = 6404066<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 2

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 2

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 2
*                                                            *GroupVariationType_EVENT
*                                                        *GroupVariation_uint16_t enumeration= 3c02

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=2
*                                                        *record->gGroupVariationRecord.enumeration=3c02
*                                                        *IAPDUHandler* pHandler=6402972
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                                            *GroupVariationType_EVENT

                                                                SelectMaxCount_in_EventBuffer1
*                                                                *uint32_t maximum= 4294967295
*                                                                *GroupVariation_uint16_t gv= 3c02
@@@@                                                                *GroupVariation_Group60Var2

                                                                    SelectByClass_EventClass_in_EventBuffer1
*                                                                    *uint32_t max= 4294967295
*                                                                    *EventClass_uint8_t clazz= 0

                                                                    SelectByClass_in_EventStorageOver2_1
*                                                                    *EventClass_uint8_t clazz= 0
*                                                                    *uint32_t max= 65535

                                                                        SelectByClass_in_EventSelection_static1
*                                                                        *uint32_t max= 65535

                                                                            Iterate_in_List_for_EventRecord1
*                                                                            *pList_for_EventRecord->head= 0

                                                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                                                *Node_for_EventRecord* start= 0

                                                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                                *Node_for_EventRecord* start= 0
*                                                                    *uint32_t tmp= 0

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 3
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 3
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 4
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 3
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 4
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404067<-60
@@@@                                                    *read_in_UInt8_static = 6404068<-3
@@@@                                                    *read_in_UInt8_static = 6404069<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 3

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 3

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 3
*                                                            *GroupVariationType_EVENT
*                                                        *GroupVariation_uint16_t enumeration= 3c03

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=3
*                                                        *record->gGroupVariationRecord.enumeration=3c03
*                                                        *IAPDUHandler* pHandler=6402972
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                                            *GroupVariationType_EVENT

                                                                SelectMaxCount_in_EventBuffer1
*                                                                *uint32_t maximum= 4294967295
*                                                                *GroupVariation_uint16_t gv= 3c03
*                                                                *GroupVariation_Group60Var3

                                                                SelectByClass_EventClass_in_EventBuffer1
*                                                                *uint32_t max= 4294967295
*                                                                *EventClass_uint8_t clazz= 1

                                                                SelectByClass_in_EventStorageOver2_1
*                                                                *EventClass_uint8_t clazz= 1
*                                                                *uint32_t max= 65535

                                                                    SelectByClass_in_EventSelection_static1
*                                                                    *uint32_t max= 65535

                                                                        Iterate_in_List_for_EventRecord1
*                                                                        *pList_for_EventRecord->head= 0

                                                                            From__in__Iterator_in_List_for_EventRecord_static1
*                                                                            *Node_for_EventRecord* start= 0

                                                                            Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                            *Node_for_EventRecord* start= 0
*                                                                *uint32_t tmp= 0

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 4
*                                            @*buffer->buffer_[i]= 6
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 4
*                                                @*buffer->buffer_[i]= 6
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 4
*                                                    @*buffer->buffer_[i]= 6
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404070<-60
@@@@                                                    *read_in_UInt8_static = 6404071<-4
@@@@                                                    *read_in_UInt8_static = 6404072<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 4

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 4

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 4
*                                                            *GroupVariationType_EVENT
*                                                        *GroupVariation_uint16_t enumeration= 3c04

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=4
*                                                        *record->gGroupVariationRecord.enumeration=3c04
*                                                        *IAPDUHandler* pHandler=6402972
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                                            *GroupVariationType_EVENT

                                                                SelectMaxCount_in_EventBuffer1
*                                                                *uint32_t maximum= 4294967295
*                                                                *GroupVariation_uint16_t gv= 3c04
*                                                                *GroupVariation_Group60Var4

                                                                SelectByClass_EventClass_in_EventBuffer1
*                                                                *uint32_t max= 4294967295
*                                                                *EventClass_uint8_t clazz= 2

                                                                SelectByClass_in_EventStorageOver2_1
*                                                                *EventClass_uint8_t clazz= 2
*                                                                *uint32_t max= 65535

                                                                    SelectByClass_in_EventSelection_static1
*                                                                    *uint32_t max= 65535

                                                                        Iterate_in_List_for_EventRecord1
*                                                                        *pList_for_EventRecord->head= 0

                                                                            From__in__Iterator_in_List_for_EventRecord_static1
*                                                                            *Node_for_EventRecord* start= 0

                                                                            Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                            *Node_for_EventRecord* start= 0
*                                                                *uint32_t tmp= 0

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 3c
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 3c
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 3c
*                                                    @*buffer->buffer_[i]= 1
*                                                    @*buffer->buffer_[i]= 6
@@@@                                                    *read_in_UInt8_static = 6404073<-60
@@@@                                                    *read_in_UInt8_static = 6404074<-1
@@@@                                                    *read_in_UInt8_static = 6404075<-6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 60
*                                                    *uint8_t variation= 1

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 1

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 1
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 3c01

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=1
*                                                        *record->gGroupVariationRecord.enumeration=3c01
*                                                        *IAPDUHandler* pHandler=6402972
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                            *GroupVariationType_STATIC

                                                                SelectAll_in_Database1
*                                                                *GroupVariation_Group60Var1

                                                                select_all_in_StaticDataMap_for_BinarySpecOver3_1
                                                                select_all_in_StaticDataMap_for_BinarySpecOver3_2

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    *HandleRead_in_OContext5
*                                    *ParseResult_uint8_t result =0

                                        {Load_in_EventBuffer1

                                            {Write_in_EventWriting_static1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 0

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 0

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 0

                                                WriteSome_in_EventWriting_static1
*                                                *lists->counters.selected= 0
*                                            *uint16_t num_written =0
                                            }Write_in_EventWriting_static1_

                                            NumSelected_in_EventStorage1
*                                            *(pEventStorage->state).counters.selected= 0
                                        }Load_in_EventBuffer_

                                        Load_in_Database1

                                        load_type_for_Analog_in_Database_static1
*                                        *map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_Binary_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_BinaryOutputStatus_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_AnalogOutputStatus_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_DoubleBitBinary_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_Counter_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 1

                                            get_for_TimeAndIntervalSpec_in_StaticWriters_static1
*                                            *WriteWithSerializer_TimeAndIntervalSpec_for_Group50Var4_in_StaticWriters_static

                                            WriteHeaderWithReserve_in_HeaderWriter1
*                                            *qc= 0
*                                            *reserve= 13

                                            WriteHeader_in_HeaderWriter1
*                                            *id.group= 50
*                                            *id.variation= 4
*                                            *qc= 0
@@@@                                            *write_in_UInt8_static = 6417886->50
@@@@                                            *write_in_UInt8_static = 6417887->4
@@@@                                            *write_in_UInt8_static = 6417888->0

                                            RangeWriteIterator_for_UInt8_TimeAndInterval_in_RangeWriteIterator_for_UInt8_TimeAndIntervalOver2_1
@@@@                                        *write_in_UInt8_static = 6417889->0
@@@@                                        *write_in_UInt48_static = 6417891->9
@@@@                                        *write_in_UInt32_static = 6417897->3
@@@@                                        *write_in_UInt8_static = 6417901->5

                                            RangeWriteIterator_for_UInt8_TimeAndInterval_destr_RangeWriteIterator_for_UInt8_TimeAndInterval1
@@@@                                        *write_in_UInt8_static = 6417890->0
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext1_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =0

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6417882->192
                                    }SetControl_in_APDUWrapper_

                                    {GetResponseIIN_in_OContext1
*                                    *LSBMask_BROADCAST = 0x01
*                                    *LSBMask_CLASS1_EVENTS = 0x02
*                                    *LSBMask_CLASS2_EVENTS = 0x04
*                                    *LSBMask_CLASS3_EVENTS = 0x08
*                                    *LSBMask_NEED_TIME = 0x10
*                                    *LSBMask_LOCAL_CONTROL = 0x20
*                                    *LSBMask_DEVICE_TROUBLE = 0x40
*                                    *LSBMask_DEVICE_RESTART = 0x80
*
*                                    *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                    *MSBMask_OBJECT_UNKNOWN = 0x02
*                                    *MSBMask_PARAM_ERROR = 0x04
*                                    *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                    *MSBMask_ALREADY_EXECUTING = 0x10
*                                    *MSBMask_CONFIG_CORRUPT = 0x20
*                                    *MSBMask_RESERVED1 = 0x40
*                                    *MSBMask_RESERVED2 = 0x80
*

                                        IsOverflown_in_EventBuffer1
*                                        *pEventBuffer->overflow= 0
*                                    IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                    *uint8_t LSB=0
*                                    *uint8_t MSB=0
*                                    IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                    *uint8_t LSB=0
*                                    *uint8_t MSB=0
*                                    IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                    *uint8_t LSB=80
*                                    *uint8_t MSB=0
                                    }GetResponseIIN_in_OContext_

                                    {SetIIN_in_APDUResponse1
@@@@                                    *write_uint8=6417884->128
@@@@                                    *write_uint8=6417885->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_
*                                    *BeginResponseTx_in_OContext2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= c0
*                                    @*buffer->buffer_[i]= 81
*                                    @*buffer->buffer_[i]= 80
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 32
*                                    @*buffer->buffer_[i]= 4
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 9
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 3
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 5
*                                    *BeginResponseTx_in_OContext3
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= c0
*                                    @*buffer->buffer_[i]= 81
*                                    @*buffer->buffer_[i]= 80
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 32
*                                    @*buffer->buffer_[i]= 4
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 9
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 3
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 5
*                                    *BeginResponseTx_in_OContext4
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= c0
*                                    @*buffer->buffer_[i]= 81
*                                    @*buffer->buffer_[i]= 80
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 32
*                                    @*buffer->buffer_[i]= 4
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 9
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 3
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 5

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= c0
*                                        @*buffer->buffer_[i]= 81
*                                        @*buffer->buffer_[i]= 80
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 32
*                                        @*buffer->buffer_[i]= 4
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 9
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 3
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 5

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= c0
*                                        @*buffer->buffer_[i]= 81
*                                        @*buffer->buffer_[i]= 80
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 32
*                                        @*buffer->buffer_[i]= 4
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 9
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 3
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 5
}BeginTransmit_in_MockLowerLayer_
                                        }BeginTx_in_OContext_

                                        {Inst_in_StateIdle_static1

                                            StateIdle_in_StateIdle1

                                                OutstationState_in_OutstationState1
                                        }Inst_in_StateIdle_static_
                                    }BeginResponseTx_in_OContext_
                                }RespondToReadRequest_in_OContext_
                            }OnNewReadRequest_in_StateIdle_override_
                        }ProcessNewRequest_in_OContext1_
                    }OnReceiveSolRequest_in_OContext5_
                }ProcessRequest_in_OContext_
            }ProcessObjects_in_OContext_
        }ProcessMessage_in_OContext6_

        {CheckForTaskStart_in_OContext1

            {CheckForDeferredRequest_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 32 04 00 00 00 09 00 00 00 00 00 03 00 00 00 05')
temp=                                C0 81 80 00 32 04 00 00 00 09 00 00 00 00 00 03 00 00 00 05
stmp= C0 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06
