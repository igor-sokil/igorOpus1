********SUITE('7WriteIIN')********

DatabaseConfig_in_DatabaseConfig1

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6405064
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

        {Database_in_Database1

            StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1
*            *config.size()= 0

                {StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver1

                    {Range_in_RangeOver1_1
                    }Range_in_RangeOver1__
                }StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver_

            StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2_1

                {StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1_1

                    {Range_in_RangeOver1_1
                    }Range_in_RangeOver1__
                *pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs= 0
                *pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.begin= 6413992
                *pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.end= 6413992
                }StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1__
            *StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2_2
*            *pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs= 0

            StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__

            StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*            *config.size()= 0

                {Range_in_RangeOver1_1
                }Range_in_RangeOver1__
        }Database_in_Database_

        DeferredRequest_in_DeferredRequest1
*        *uint32_t maxAPDUSize =292

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=292
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6415886

        {OutstationSolState_in_OutstationSolState1

            TxBuffer_in_TxBuffer1
*            *uint32_t maxTxSize =292

            BufferSer4_in_BufferSer4Over2_1
*            *uint16_t length=292
*            *sizeof(BufferSer4)=2048
*            *uint8_t bytes[SIZE_BufferSer4]=6418026
        }OutstationSolState_in_OutstationSolState_

        {OutstationUnsolState_in_OutstationUnsolState1

            TxBuffer_in_TxBuffer1
*            *uint32_t maxTxSize =292

            BufferSer4_in_BufferSer4Over2_1
*            *uint16_t length=292
*            *sizeof(BufferSer4)=2048
*            *uint8_t bytes[SIZE_BufferSer4]=6420114
        }OutstationUnsolState_in_OutstationUnsolState_

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
*                *boolean ret= 1
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *boolean ret= 1
                }CanTransmit_in_OContext_

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *boolean ret= 1
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnLowerLayerUp_in_OContext_
}LowerLayerUp_in_OutstationTestObject_

{ClearRestartIIN_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6402528

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6402529->2
    }SetFunction_in_APDUWrapper_

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6402528->192
    }SetControl_in_APDUWrapper_

    WriteHeaderWithReserve_in_HeaderWriter1
*    *qc= 0
*    *reserve= 3

    WriteHeader_in_HeaderWriter1
*    *id.group= 80
*    *id.variation= 1
*    *qc= 0
@@@@    *write_in_UInt8_static = 6402530->80
@@@@    *write_in_UInt8_static = 6402531->1
@@@@    *write_in_UInt8_static = 6402532->0

    BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8_1
@@@@    *write_in_UInt8_static = 6402533->7

    Write_in_BitfieldRangeWriteIterator_for_UInt8_1
@@@@*write_uint8=6402535->0

    BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8_1
@@@@*write_in_UInt8_static = 6402534->7
}ClearRestartIIN_in_APDUHexBuilders_
ClearRestartIIN_in_APDUHexBuilders str= C0 02 50 01 00 07 07 00

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6402526<-c0
*        @*buffer->buffer_[i]= 6402527<-2
*        @*buffer->buffer_[i]= 6402528<-50
*        @*buffer->buffer_[i]= 6402529<-1
*        @*buffer->buffer_[i]= 6402530<-0
*        @*buffer->buffer_[i]= 6402531<-7
*        @*buffer->buffer_[i]= 6402532<-7
*        @*buffer->buffer_[i]= 6402533<-0

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6402526<-c0
*            @*buffer->buffer_[i]= 6402527<-2
*            @*buffer->buffer_[i]= 6402528<-50
*            @*buffer->buffer_[i]= 6402529<-1
*            @*buffer->buffer_[i]= 6402530<-0
*            @*buffer->buffer_[i]= 6402531<-7
*            @*buffer->buffer_[i]= 6402532<-7
*            @*buffer->buffer_[i]= 6402533<-0
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1

                        {ProcessNewRequest_in_OContext1

                            {OnNewNonReadRequest_in_StateIdle_override1

                                {RespondToNonReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6418027->129
                                    }SetFunction_in_APDUWrapper_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =0

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6418026->192
                                    }SetControl_in_APDUWrapper_

                                    {HandleNonReadResponse_in_OContext1
*                                    *FunctionCode_uint18_t function= 2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6402528<-50
*                                    @*buffer->buffer_[i]= 6402529<-1
*                                    @*buffer->buffer_[i]= 6402530<-0
*                                    @*buffer->buffer_[i]= 6402531<-7
*                                    @*buffer->buffer_[i]= 6402532<-7
*                                    @*buffer->buffer_[i]= 6402533<-0
@@@@                                    *FunctionCode_WRITE

                                        {HandleWrite_in_OContext1

                                            WriteHandler_in_WriteHandler1

                                            IAPDUHandler_in_IAPDUHandler1
*                                            *pIAPDUHandler= 6401312
                                        *HandleWrite_in_OContext2

                                            @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                            {Parse_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6402528<-50
*                                            @*buffer->buffer_[i]= 6402529<-1
*                                            @*buffer->buffer_[i]= 6402530<-0
*                                            @*buffer->buffer_[i]= 6402531<-7
*                                            @*buffer->buffer_[i]= 6402532<-7
*                                            @*buffer->buffer_[i]= 6402533<-0

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=0
*                                                *IWhiteList* pWhiteList=6401312
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6402528<-50
*                                                @*buffer->buffer_[i]= 6402529<-1
*                                                @*buffer->buffer_[i]= 6402530<-0
*                                                @*buffer->buffer_[i]= 6402531<-7
*                                                @*buffer->buffer_[i]= 6402532<-7
*                                                @*buffer->buffer_[i]= 6402533<-0
*                                                *copy
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6402528<-50
*                                                @*buffer->buffer_[i]= 6402529<-1
*                                                @*buffer->buffer_[i]= 6402530<-0
*                                                @*buffer->buffer_[i]= 6402531<-7
*                                                @*buffer->buffer_[i]= 6402532<-7
*                                                @*buffer->buffer_[i]= 6402533<-0

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6402528<-50
*                                                    @*buffer->buffer_[i]= 6402529<-1
*                                                    @*buffer->buffer_[i]= 6402530<-0
*                                                    @*buffer->buffer_[i]= 6402531<-7
*                                                    @*buffer->buffer_[i]= 6402532<-7
*                                                    @*buffer->buffer_[i]= 6402533<-0

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 6402528<-50
*                                                        @*buffer->buffer_[i]= 6402529<-1
*                                                        @*buffer->buffer_[i]= 6402530<-0
*                                                        @*buffer->buffer_[i]= 6402531<-7
*                                                        @*buffer->buffer_[i]= 6402532<-7
*                                                        @*buffer->buffer_[i]= 6402533<-0
@@@@                                                        *read_in_UInt8_static = 6402528<-80
@@@@                                                        *read_in_UInt8_static = 6402529<-1
@@@@                                                        *read_in_UInt8_static = 6402530<-0

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 80
*                                                        *uint8_t variation= 1

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 80
*                                                            *uint8_t variation= 1

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 80
*                                                                *uint8_t variation= 1
*                                                                *GroupVariationType_OTHER
*                                                            *GroupVariation_uint16_t enumeration= 5001

                                                        {IsAllowed_in_WriteHandler_override1
                                                        }IsAllowed_in_WriteHandler_override_

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =0
@@@@                                                        *QualifierCode_UINT8_START_STOP*

                                                            NumParser_in_NumParser1

                                                            {ParseHeader_in_RangeParser_static1
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6402531<-7
*                                                            @*buffer->buffer_[i]= 6402532<-7
*                                                            @*buffer->buffer_[i]= 6402533<-0

                                                                {ParseRange_in_NumParser1
@@@@                                                                *read_in_UInt8_static = 6402531<-7
@@@@                                                                *read_in_UInt8_static = 6402532<-7
                                                                }ParseRange_in_NumParser2_
*                                                            *ParseResult_uint8_t res = 0
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6402533<-0
*                                                            *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                            *record.group= 80
*                                                            *record.variation= 1
*                                                            *record.enumeration= 20481
*                                                            *record.GetQualifierCode()= 0
*                                                            *range.start= 7
*                                                            *range.stop= 7

                                                                {ParseRangeOfObjects_in_RangeParser_static1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6402533<-0
*                                                                *GroupVariation_Group80Var1

                                                                {Process_in_RangeParser1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6402533<-0
                                                                }Process_in_RangeParser2_
                                                            }ParseHeader_in_RangeParser_static2_
                                                        }ParseQualifier_in_APDUParser_static4_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=6401312
*                                                *IWhiteList* pWhiteList=0
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6402528<-50
*                                                @*buffer->buffer_[i]= 6402529<-1
*                                                @*buffer->buffer_[i]= 6402530<-0
*                                                @*buffer->buffer_[i]= 6402531<-7
*                                                @*buffer->buffer_[i]= 6402532<-7
*                                                @*buffer->buffer_[i]= 6402533<-0
*                                                *copy
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6402528<-50
*                                                @*buffer->buffer_[i]= 6402529<-1
*                                                @*buffer->buffer_[i]= 6402530<-0
*                                                @*buffer->buffer_[i]= 6402531<-7
*                                                @*buffer->buffer_[i]= 6402532<-7
*                                                @*buffer->buffer_[i]= 6402533<-0

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6402528<-50
*                                                    @*buffer->buffer_[i]= 6402529<-1
*                                                    @*buffer->buffer_[i]= 6402530<-0
*                                                    @*buffer->buffer_[i]= 6402531<-7
*                                                    @*buffer->buffer_[i]= 6402532<-7
*                                                    @*buffer->buffer_[i]= 6402533<-0

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 6402528<-50
*                                                        @*buffer->buffer_[i]= 6402529<-1
*                                                        @*buffer->buffer_[i]= 6402530<-0
*                                                        @*buffer->buffer_[i]= 6402531<-7
*                                                        @*buffer->buffer_[i]= 6402532<-7
*                                                        @*buffer->buffer_[i]= 6402533<-0
@@@@                                                        *read_in_UInt8_static = 6402528<-80
@@@@                                                        *read_in_UInt8_static = 6402529<-1
@@@@                                                        *read_in_UInt8_static = 6402530<-0

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 80
*                                                        *uint8_t variation= 1

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 80
*                                                            *uint8_t variation= 1

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 80
*                                                                *uint8_t variation= 1
*                                                                *GroupVariationType_OTHER
*                                                            *GroupVariation_uint16_t enumeration= 5001

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =0
@@@@                                                        *QualifierCode_UINT8_START_STOP*

                                                            NumParser_in_NumParser1

                                                            {ParseHeader_in_RangeParser_static1
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6402531<-7
*                                                            @*buffer->buffer_[i]= 6402532<-7
*                                                            @*buffer->buffer_[i]= 6402533<-0

                                                                {ParseRange_in_NumParser1
@@@@                                                                *read_in_UInt8_static = 6402531<-7
@@@@                                                                *read_in_UInt8_static = 6402532<-7
                                                                }ParseRange_in_NumParser2_
*                                                            *ParseResult_uint8_t res = 0
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6402533<-0
*                                                            *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                            *record.group= 80
*                                                            *record.variation= 1
*                                                            *record.enumeration= 20481
*                                                            *record.GetQualifierCode()= 0
*                                                            *range.start= 7
*                                                            *range.stop= 7

                                                                {ParseRangeOfObjects_in_RangeParser_static1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6402533<-0
*                                                                *GroupVariation_Group80Var1

                                                                {Process_in_RangeParser1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6402533<-0

                                                                    {InvokeRangeBitfieldType_for_IINValue_in_RangeParser_static1
*                                                                    **inspect_RSeq**
*                                                                    @*buffer->buffer_[i]= 6402533<-0

                                                                        {OnHeader_RangeHeader_for_IINValue_in_IAPDUHandler1

                                                                            {ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override1
                                                                            *ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override2a

                                                                                {Foreach_in_BufferedCollection_Indexed_for_IINValue1
                                                                                *pBufferedCollection_Indexed_for_IINValue->COUNT= 1
*                                                                                **inspect_RSeq**
*                                                                                @*buffer->buffer_[i]= 6402533<-0

                                                                                    {readInvokeRangeBitfieldType_for_IINValue_in_RangeParser1
                                                                                    *uint32_t pos= 0
*                                                                                    **inspect_RSeq**
*                                                                                    @*buffer->buffer_[i]= 6402533<-0

                                                                                        {GetBit_in_DoubleBit_static1
                                                                                        *uint32_t position= 0
                                                                                        }GetBit_in_DoubleBit_static_
                                                                                        *boolean tmp= 0
                                                                                    }readInvokeRangeBitfieldType_for_IINValue_in_RangeParser_
                                                                                }Foreach_in_BufferedCollection_Indexed_for_IINValue_
                                                                            *ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override2
                                                                            *ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override3
                                                                            *ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override4
                                                                            }ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override5_

                                                                            {Record_in_IAPDUHandler1
                                                                            *Record_in_IAPDUHandler2
                                                                            *Record_in_IAPDUHandler3

                                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                                }OnHeaderResult_in_IAPDUHandler_
                                                                            }Record_in_IAPDUHandler_
                                                                        }OnHeader_RangeHeader_for_IINValue_in_IAPDUHandler_
                                                                    }InvokeRangeBitfieldType_for_IINValue_in_RangeParser_static_
                                                                    *&(collection.iICollection_Indexed_for_IINValue)= 6400260
                                                                }Process_in_RangeParser2_
                                                            }ParseHeader_in_RangeParser_static2_
                                                        }ParseQualifier_in_APDUParser_static4_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_
                                            }Parse_in_APDUParser_static_
                                        *HandleWrite_in_OContext3
*                                        *ParseResult_uint8_t result =0
                                        }HandleWrite_in_OContext_
                                    }HandleNonReadResponse_in_OContext1_

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
*                                    *uint8_t LSB=0
*                                    *uint8_t MSB=0
                                    }GetResponseIIN_in_OContext_

                                    {SetIIN_in_APDUResponse1
@@@@                                    *write_uint8=6418028->0
@@@@                                    *write_uint8=6418029->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_
*                                    *BeginResponseTx_in_OContext2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-0
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    *BeginResponseTx_in_OContext3
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-0
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    *BeginResponseTx_in_OContext4
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-0
*                                    @*buffer->buffer_[i]= 6418029<-0

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-0
*                                        @*buffer->buffer_[i]= 6418029<-0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-0
*                                        @*buffer->buffer_[i]= 6418029<-0
}BeginTransmit_in_MockLowerLayer_
                                        }BeginTx_in_OContext_

                                        {Inst_in_StateIdle_static1

                                            StateIdle_in_StateIdle1

                                                OutstationState_in_OutstationState1
                                        }Inst_in_StateIdle_static_
                                    }BeginResponseTx_in_OContext_
                                }RespondToNonReadRequest_in_OContext_
                            }OnNewNonReadRequest_in_StateIdle_override_
                        }ProcessNewRequest_in_OContext2_
                    }OnReceiveSolRequest_in_OContext5_
                }ProcessRequest_in_OContext_
            }ProcessObjects_in_OContext5_
        }ProcessMessage_in_OContext6_

        {CheckForTaskStart_in_OContext1

            {CheckForDeferredRequest_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *boolean ret= 0
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *boolean ret= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *boolean ret= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0))
temp= C0 81 00 00

{EmptyResponse_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6402528

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6402529->129
    }SetFunction_in_APDUWrapper_

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6402528->192
    }SetControl_in_APDUWrapper_

    {SetIIN_in_APDUResponse1
@@@@    *write_uint8=6402530->0
@@@@    *write_uint8=6402531->0
    }SetIIN_in_APDUResponse_
}EmptyResponse_in_APDUHexBuilders_
str= C0 81 00 00
