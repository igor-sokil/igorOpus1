********SUITE('30TestTimeAndIntervalWrite')********

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}MockExecutor_in_MockExecutor_

{OContext_in_OContext1

    EventLists_in_EventLists1
    TotalEvents_in_EventBufferConfig1
*    *pEventBufferConfig->maxBinaryEvents= 0
*    *pEventBufferConfig->maxDoubleBinaryEvents=0
*    *pEventBufferConfig->maxAnalogEvents= 0
*    *pEventBufferConfig->maxCounterEvents= 0
*    *pEventBufferConfig->maxBinaryOutputStatusEvents= 0
*    *pEventBufferConfig->maxAnalogOutputStatusEvents= 0
*    *pEventBufferConfig->maxOctetStringEvents= 0

    List_for_EventRecord_in_List_for_EventRecordOver2_1
*    *uint32_t maxSize= 0

    List_for_EventRecord_in_List_for_EventRecordOver1_1

    Database_in_Database1

    StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2_1
*    *config.size()= 0

    StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2_1
*    *config.size()= 1

    StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*    *config.size()= 0

    DeferredRequest_in_DeferredRequest1
*    *uint32_t maxAPDUSize =292

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=292
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6415886

    {OutstationSolState_in_OutstationSolState1

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =292

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=292
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6418026
    }OutstationSolState_in_OutstationSolState_

    {OutstationUnsolState_in_OutstationUnsolState1

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =292

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=292
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6420114
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

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404110<-c0
*        @*buffer->buffer_[i]= 6404111<-2
*        @*buffer->buffer_[i]= 6404112<-32
*        @*buffer->buffer_[i]= 6404113<-4
*        @*buffer->buffer_[i]= 6404114<-28
*        @*buffer->buffer_[i]= 6404115<-1
*        @*buffer->buffer_[i]= 6404116<-0
*        @*buffer->buffer_[i]= 6404117<-7
*        @*buffer->buffer_[i]= 6404118<-0
*        @*buffer->buffer_[i]= 6404119<-9
*        @*buffer->buffer_[i]= 6404120<-0
*        @*buffer->buffer_[i]= 6404121<-0
*        @*buffer->buffer_[i]= 6404122<-0
*        @*buffer->buffer_[i]= 6404123<-0
*        @*buffer->buffer_[i]= 6404124<-0
*        @*buffer->buffer_[i]= 6404125<-3
*        @*buffer->buffer_[i]= 6404126<-0
*        @*buffer->buffer_[i]= 6404127<-0
*        @*buffer->buffer_[i]= 6404128<-0
*        @*buffer->buffer_[i]= 6404129<-5

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404110<-c0
*            @*buffer->buffer_[i]= 6404111<-2
*            @*buffer->buffer_[i]= 6404112<-32
*            @*buffer->buffer_[i]= 6404113<-4
*            @*buffer->buffer_[i]= 6404114<-28
*            @*buffer->buffer_[i]= 6404115<-1
*            @*buffer->buffer_[i]= 6404116<-0
*            @*buffer->buffer_[i]= 6404117<-7
*            @*buffer->buffer_[i]= 6404118<-0
*            @*buffer->buffer_[i]= 6404119<-9
*            @*buffer->buffer_[i]= 6404120<-0
*            @*buffer->buffer_[i]= 6404121<-0
*            @*buffer->buffer_[i]= 6404122<-0
*            @*buffer->buffer_[i]= 6404123<-0
*            @*buffer->buffer_[i]= 6404124<-0
*            @*buffer->buffer_[i]= 6404125<-3
*            @*buffer->buffer_[i]= 6404126<-0
*            @*buffer->buffer_[i]= 6404127<-0
*            @*buffer->buffer_[i]= 6404128<-0
*            @*buffer->buffer_[i]= 6404129<-5
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
*                                    @*buffer->buffer_[i]= 6404112<-32
*                                    @*buffer->buffer_[i]= 6404113<-4
*                                    @*buffer->buffer_[i]= 6404114<-28
*                                    @*buffer->buffer_[i]= 6404115<-1
*                                    @*buffer->buffer_[i]= 6404116<-0
*                                    @*buffer->buffer_[i]= 6404117<-7
*                                    @*buffer->buffer_[i]= 6404118<-0
*                                    @*buffer->buffer_[i]= 6404119<-9
*                                    @*buffer->buffer_[i]= 6404120<-0
*                                    @*buffer->buffer_[i]= 6404121<-0
*                                    @*buffer->buffer_[i]= 6404122<-0
*                                    @*buffer->buffer_[i]= 6404123<-0
*                                    @*buffer->buffer_[i]= 6404124<-0
*                                    @*buffer->buffer_[i]= 6404125<-3
*                                    @*buffer->buffer_[i]= 6404126<-0
*                                    @*buffer->buffer_[i]= 6404127<-0
*                                    @*buffer->buffer_[i]= 6404128<-0
*                                    @*buffer->buffer_[i]= 6404129<-5
@@@@                                    *FunctionCode_WRITE

                                        {HandleWrite_in_OContext1

                                            WriteHandler_in_WriteHandler1

                                            IAPDUHandler_in_IAPDUHandler1
*                                            *pIAPDUHandler= 6402896
                                        *HandleWrite_in_OContext2

                                            @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                            {Parse_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404112<-32
*                                            @*buffer->buffer_[i]= 6404113<-4
*                                            @*buffer->buffer_[i]= 6404114<-28
*                                            @*buffer->buffer_[i]= 6404115<-1
*                                            @*buffer->buffer_[i]= 6404116<-0
*                                            @*buffer->buffer_[i]= 6404117<-7
*                                            @*buffer->buffer_[i]= 6404118<-0
*                                            @*buffer->buffer_[i]= 6404119<-9
*                                            @*buffer->buffer_[i]= 6404120<-0
*                                            @*buffer->buffer_[i]= 6404121<-0
*                                            @*buffer->buffer_[i]= 6404122<-0
*                                            @*buffer->buffer_[i]= 6404123<-0
*                                            @*buffer->buffer_[i]= 6404124<-0
*                                            @*buffer->buffer_[i]= 6404125<-3
*                                            @*buffer->buffer_[i]= 6404126<-0
*                                            @*buffer->buffer_[i]= 6404127<-0
*                                            @*buffer->buffer_[i]= 6404128<-0
*                                            @*buffer->buffer_[i]= 6404129<-5

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=0
*                                                *IWhiteList* pWhiteList=6402896
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404112<-32
*                                                @*buffer->buffer_[i]= 6404113<-4
*                                                @*buffer->buffer_[i]= 6404114<-28
*                                                @*buffer->buffer_[i]= 6404115<-1
*                                                @*buffer->buffer_[i]= 6404116<-0
*                                                @*buffer->buffer_[i]= 6404117<-7
*                                                @*buffer->buffer_[i]= 6404118<-0
*                                                @*buffer->buffer_[i]= 6404119<-9
*                                                @*buffer->buffer_[i]= 6404120<-0
*                                                @*buffer->buffer_[i]= 6404121<-0
*                                                @*buffer->buffer_[i]= 6404122<-0
*                                                @*buffer->buffer_[i]= 6404123<-0
*                                                @*buffer->buffer_[i]= 6404124<-0
*                                                @*buffer->buffer_[i]= 6404125<-3
*                                                @*buffer->buffer_[i]= 6404126<-0
*                                                @*buffer->buffer_[i]= 6404127<-0
*                                                @*buffer->buffer_[i]= 6404128<-0
*                                                @*buffer->buffer_[i]= 6404129<-5
*                                                *copy
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404112<-32
*                                                @*buffer->buffer_[i]= 6404113<-4
*                                                @*buffer->buffer_[i]= 6404114<-28
*                                                @*buffer->buffer_[i]= 6404115<-1
*                                                @*buffer->buffer_[i]= 6404116<-0
*                                                @*buffer->buffer_[i]= 6404117<-7
*                                                @*buffer->buffer_[i]= 6404118<-0
*                                                @*buffer->buffer_[i]= 6404119<-9
*                                                @*buffer->buffer_[i]= 6404120<-0
*                                                @*buffer->buffer_[i]= 6404121<-0
*                                                @*buffer->buffer_[i]= 6404122<-0
*                                                @*buffer->buffer_[i]= 6404123<-0
*                                                @*buffer->buffer_[i]= 6404124<-0
*                                                @*buffer->buffer_[i]= 6404125<-3
*                                                @*buffer->buffer_[i]= 6404126<-0
*                                                @*buffer->buffer_[i]= 6404127<-0
*                                                @*buffer->buffer_[i]= 6404128<-0
*                                                @*buffer->buffer_[i]= 6404129<-5

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6404112<-32
*                                                    @*buffer->buffer_[i]= 6404113<-4
*                                                    @*buffer->buffer_[i]= 6404114<-28
*                                                    @*buffer->buffer_[i]= 6404115<-1
*                                                    @*buffer->buffer_[i]= 6404116<-0
*                                                    @*buffer->buffer_[i]= 6404117<-7
*                                                    @*buffer->buffer_[i]= 6404118<-0
*                                                    @*buffer->buffer_[i]= 6404119<-9
*                                                    @*buffer->buffer_[i]= 6404120<-0
*                                                    @*buffer->buffer_[i]= 6404121<-0
*                                                    @*buffer->buffer_[i]= 6404122<-0
*                                                    @*buffer->buffer_[i]= 6404123<-0
*                                                    @*buffer->buffer_[i]= 6404124<-0
*                                                    @*buffer->buffer_[i]= 6404125<-3
*                                                    @*buffer->buffer_[i]= 6404126<-0
*                                                    @*buffer->buffer_[i]= 6404127<-0
*                                                    @*buffer->buffer_[i]= 6404128<-0
*                                                    @*buffer->buffer_[i]= 6404129<-5

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 6404112<-32
*                                                        @*buffer->buffer_[i]= 6404113<-4
*                                                        @*buffer->buffer_[i]= 6404114<-28
*                                                        @*buffer->buffer_[i]= 6404115<-1
*                                                        @*buffer->buffer_[i]= 6404116<-0
*                                                        @*buffer->buffer_[i]= 6404117<-7
*                                                        @*buffer->buffer_[i]= 6404118<-0
*                                                        @*buffer->buffer_[i]= 6404119<-9
*                                                        @*buffer->buffer_[i]= 6404120<-0
*                                                        @*buffer->buffer_[i]= 6404121<-0
*                                                        @*buffer->buffer_[i]= 6404122<-0
*                                                        @*buffer->buffer_[i]= 6404123<-0
*                                                        @*buffer->buffer_[i]= 6404124<-0
*                                                        @*buffer->buffer_[i]= 6404125<-3
*                                                        @*buffer->buffer_[i]= 6404126<-0
*                                                        @*buffer->buffer_[i]= 6404127<-0
*                                                        @*buffer->buffer_[i]= 6404128<-0
*                                                        @*buffer->buffer_[i]= 6404129<-5
@@@@                                                        *read_in_UInt8_static = 6404112<-50
@@@@                                                        *read_in_UInt8_static = 6404113<-4
@@@@                                                        *read_in_UInt8_static = 6404114<-40

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 50
*                                                        *uint8_t variation= 4

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 50
*                                                            *uint8_t variation= 4

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 50
*                                                                *uint8_t variation= 4
*                                                                *GroupVariationType_STATIC
*                                                            *GroupVariation_uint16_t enumeration= 3204

                                                        {IsAllowed_in_WriteHandler_override1
                                                        }IsAllowed_in_WriteHandler_override_

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =40
@@@@                                                        *QualifierCode_UINT16_CNT_UINT16_INDEX*

                                                            NumParser_in_NumParser1

                                                            ParseHeader_in_CountIndexParser_static1
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6404115<-1
*                                                            @*buffer->buffer_[i]= 6404116<-0
*                                                            @*buffer->buffer_[i]= 6404117<-7
*                                                            @*buffer->buffer_[i]= 6404118<-0
*                                                            @*buffer->buffer_[i]= 6404119<-9
*                                                            @*buffer->buffer_[i]= 6404120<-0
*                                                            @*buffer->buffer_[i]= 6404121<-0
*                                                            @*buffer->buffer_[i]= 6404122<-0
*                                                            @*buffer->buffer_[i]= 6404123<-0
*                                                            @*buffer->buffer_[i]= 6404124<-0
*                                                            @*buffer->buffer_[i]= 6404125<-3
*                                                            @*buffer->buffer_[i]= 6404126<-0
*                                                            @*buffer->buffer_[i]= 6404127<-0
*                                                            @*buffer->buffer_[i]= 6404128<-0
*                                                            @*buffer->buffer_[i]= 6404129<-5

                                                                ParseCount_in_NumParser1
@@@@                                                                *read_from_in_UInt16_static = 6404115<-1
*                                                            *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                            *record.group= 50
*                                                            *record.variation= 4
*                                                            *record.enumeration= 12804
*                                                            *record.GetQualifierCode()= 40

                                                            ParseCountOfObjects_in_CountIndexParser_static1
*                                                            *record->gGroupVariationRecord.enumeration= 3204
*                                                            *GroupVariation_Group50Var4

                                                            Process_in_CountIndexParser1
                                                        }ParseQualifier_in_APDUParser_static7_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=6402896
*                                                *IWhiteList* pWhiteList=0
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404112<-32
*                                                @*buffer->buffer_[i]= 6404113<-4
*                                                @*buffer->buffer_[i]= 6404114<-28
*                                                @*buffer->buffer_[i]= 6404115<-1
*                                                @*buffer->buffer_[i]= 6404116<-0
*                                                @*buffer->buffer_[i]= 6404117<-7
*                                                @*buffer->buffer_[i]= 6404118<-0
*                                                @*buffer->buffer_[i]= 6404119<-9
*                                                @*buffer->buffer_[i]= 6404120<-0
*                                                @*buffer->buffer_[i]= 6404121<-0
*                                                @*buffer->buffer_[i]= 6404122<-0
*                                                @*buffer->buffer_[i]= 6404123<-0
*                                                @*buffer->buffer_[i]= 6404124<-0
*                                                @*buffer->buffer_[i]= 6404125<-3
*                                                @*buffer->buffer_[i]= 6404126<-0
*                                                @*buffer->buffer_[i]= 6404127<-0
*                                                @*buffer->buffer_[i]= 6404128<-0
*                                                @*buffer->buffer_[i]= 6404129<-5
*                                                *copy
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404112<-32
*                                                @*buffer->buffer_[i]= 6404113<-4
*                                                @*buffer->buffer_[i]= 6404114<-28
*                                                @*buffer->buffer_[i]= 6404115<-1
*                                                @*buffer->buffer_[i]= 6404116<-0
*                                                @*buffer->buffer_[i]= 6404117<-7
*                                                @*buffer->buffer_[i]= 6404118<-0
*                                                @*buffer->buffer_[i]= 6404119<-9
*                                                @*buffer->buffer_[i]= 6404120<-0
*                                                @*buffer->buffer_[i]= 6404121<-0
*                                                @*buffer->buffer_[i]= 6404122<-0
*                                                @*buffer->buffer_[i]= 6404123<-0
*                                                @*buffer->buffer_[i]= 6404124<-0
*                                                @*buffer->buffer_[i]= 6404125<-3
*                                                @*buffer->buffer_[i]= 6404126<-0
*                                                @*buffer->buffer_[i]= 6404127<-0
*                                                @*buffer->buffer_[i]= 6404128<-0
*                                                @*buffer->buffer_[i]= 6404129<-5

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6404112<-32
*                                                    @*buffer->buffer_[i]= 6404113<-4
*                                                    @*buffer->buffer_[i]= 6404114<-28
*                                                    @*buffer->buffer_[i]= 6404115<-1
*                                                    @*buffer->buffer_[i]= 6404116<-0
*                                                    @*buffer->buffer_[i]= 6404117<-7
*                                                    @*buffer->buffer_[i]= 6404118<-0
*                                                    @*buffer->buffer_[i]= 6404119<-9
*                                                    @*buffer->buffer_[i]= 6404120<-0
*                                                    @*buffer->buffer_[i]= 6404121<-0
*                                                    @*buffer->buffer_[i]= 6404122<-0
*                                                    @*buffer->buffer_[i]= 6404123<-0
*                                                    @*buffer->buffer_[i]= 6404124<-0
*                                                    @*buffer->buffer_[i]= 6404125<-3
*                                                    @*buffer->buffer_[i]= 6404126<-0
*                                                    @*buffer->buffer_[i]= 6404127<-0
*                                                    @*buffer->buffer_[i]= 6404128<-0
*                                                    @*buffer->buffer_[i]= 6404129<-5

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 6404112<-32
*                                                        @*buffer->buffer_[i]= 6404113<-4
*                                                        @*buffer->buffer_[i]= 6404114<-28
*                                                        @*buffer->buffer_[i]= 6404115<-1
*                                                        @*buffer->buffer_[i]= 6404116<-0
*                                                        @*buffer->buffer_[i]= 6404117<-7
*                                                        @*buffer->buffer_[i]= 6404118<-0
*                                                        @*buffer->buffer_[i]= 6404119<-9
*                                                        @*buffer->buffer_[i]= 6404120<-0
*                                                        @*buffer->buffer_[i]= 6404121<-0
*                                                        @*buffer->buffer_[i]= 6404122<-0
*                                                        @*buffer->buffer_[i]= 6404123<-0
*                                                        @*buffer->buffer_[i]= 6404124<-0
*                                                        @*buffer->buffer_[i]= 6404125<-3
*                                                        @*buffer->buffer_[i]= 6404126<-0
*                                                        @*buffer->buffer_[i]= 6404127<-0
*                                                        @*buffer->buffer_[i]= 6404128<-0
*                                                        @*buffer->buffer_[i]= 6404129<-5
@@@@                                                        *read_in_UInt8_static = 6404112<-50
@@@@                                                        *read_in_UInt8_static = 6404113<-4
@@@@                                                        *read_in_UInt8_static = 6404114<-40

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 50
*                                                        *uint8_t variation= 4

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 50
*                                                            *uint8_t variation= 4

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 50
*                                                                *uint8_t variation= 4
*                                                                *GroupVariationType_STATIC
*                                                            *GroupVariation_uint16_t enumeration= 3204

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =40
@@@@                                                        *QualifierCode_UINT16_CNT_UINT16_INDEX*

                                                            NumParser_in_NumParser1

                                                            ParseHeader_in_CountIndexParser_static1
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6404115<-1
*                                                            @*buffer->buffer_[i]= 6404116<-0
*                                                            @*buffer->buffer_[i]= 6404117<-7
*                                                            @*buffer->buffer_[i]= 6404118<-0
*                                                            @*buffer->buffer_[i]= 6404119<-9
*                                                            @*buffer->buffer_[i]= 6404120<-0
*                                                            @*buffer->buffer_[i]= 6404121<-0
*                                                            @*buffer->buffer_[i]= 6404122<-0
*                                                            @*buffer->buffer_[i]= 6404123<-0
*                                                            @*buffer->buffer_[i]= 6404124<-0
*                                                            @*buffer->buffer_[i]= 6404125<-3
*                                                            @*buffer->buffer_[i]= 6404126<-0
*                                                            @*buffer->buffer_[i]= 6404127<-0
*                                                            @*buffer->buffer_[i]= 6404128<-0
*                                                            @*buffer->buffer_[i]= 6404129<-5

                                                                ParseCount_in_NumParser1
@@@@                                                                *read_from_in_UInt16_static = 6404115<-1
*                                                            *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                            *record.group= 50
*                                                            *record.variation= 4
*                                                            *record.enumeration= 12804
*                                                            *record.GetQualifierCode()= 40

                                                            ParseCountOfObjects_in_CountIndexParser_static1
*                                                            *record->gGroupVariationRecord.enumeration= 3204
*                                                            *GroupVariation_Group50Var4

                                                            Process_in_CountIndexParser1

                                                                OnHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler1

                                                                ProcessHeader_PrefixHeader_for_TimeAndInterval_in_WriteHandler_override1
@@@@                                                                *read_from_in_UInt16_static = 6404117<-7
@@@@                                                                *read_from_in_UInt32_static = 6404125<-3
@@@@                                                                *read_in_UInt8_static = 6404129<-5

{__push_in_MockOutstationApplication1
}__push_in_MockOutstationApplication_

                                                                    {Record_in_IAPDUHandler1
                                                                    *Record_in_IAPDUHandler2
                                                                    *Record_in_IAPDUHandler3

                                                                        {OnHeaderResult_in_IAPDUHandler1
                                                                        }OnHeaderResult_in_IAPDUHandler_
                                                                    }Record_in_IAPDUHandler_
                                                            }ParseQualifier_in_APDUParser_static7_
*                                                            *ParseResult_uint8_t tmp= 0
                                                        }ParseHeader_in_APDUParser_static4_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseSinglePass_in_APDUParser_static2_
                                                }Parse_in_APDUParser_static_
                                            *HandleWrite_in_OContext3
*                                            *ParseResult_uint8_t result =0
                                            }HandleWrite_in_OContext_
                                        }HandleNonReadResponse_in_OContext1_

                                        {GetResponseIIN_in_OContext1
*                                        *LSBMask_BROADCAST = 0x01
*                                        *LSBMask_CLASS1_EVENTS = 0x02
*                                        *LSBMask_CLASS2_EVENTS = 0x04
*                                        *LSBMask_CLASS3_EVENTS = 0x08
*                                        *LSBMask_NEED_TIME = 0x10
*                                        *LSBMask_LOCAL_CONTROL = 0x20
*                                        *LSBMask_DEVICE_TROUBLE = 0x40
*                                        *LSBMask_DEVICE_RESTART = 0x80
*
*                                        *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                        *MSBMask_OBJECT_UNKNOWN = 0x02
*                                        *MSBMask_PARAM_ERROR = 0x04
*                                        *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                        *MSBMask_ALREADY_EXECUTING = 0x10
*                                        *MSBMask_CONFIG_CORRUPT = 0x20
*                                        *MSBMask_RESERVED1 = 0x40
*                                        *MSBMask_RESERVED2 = 0x80
*

                                            IsOverflown_in_EventBuffer1
*                                            *pEventBuffer->overflow= 0
*                                        IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                        *uint8_t LSB=0
*                                        *uint8_t MSB=0
*                                        IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                        *uint8_t LSB=0
*                                        *uint8_t MSB=0
*                                        IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                        *uint8_t LSB=80
*                                        *uint8_t MSB=0
                                        }GetResponseIIN_in_OContext_

                                        {SetIIN_in_APDUResponse1
@@@@                                        *write_uint8=6418028->128
@@@@                                        *write_uint8=6418029->0
                                        }SetIIN_in_APDUResponse_

                                        {BeginResponseTx_in_OContext1

                                            {CheckForBroadcastConfirmation_in_OContext1
                                            }CheckForBroadcastConfirmation_in_OContext_
*                                        *BeginResponseTx_in_OContext2
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        *BeginResponseTx_in_OContext3
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        *BeginResponseTx_in_OContext4
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0

                                            {BeginTx_in_OContext1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6418026<-c0
*                                            @*buffer->buffer_[i]= 6418027<-81
*                                            @*buffer->buffer_[i]= 6418028<-80
*                                            @*buffer->buffer_[i]= 6418029<-0

{BeginTransmit_in_MockLowerLayer1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6418026<-c0
*                                            @*buffer->buffer_[i]= 6418027<-81
*                                            @*buffer->buffer_[i]= 6418028<-80
*                                            @*buffer->buffer_[i]= 6418029<-0
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
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 1
*                    *boolean ret= 0
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 1
*                    *boolean ret= 0
                    }CanTransmit_in_OContext_
                }CheckForUnsolicitedNull_in_OContext_
*            CheckForTaskStart_in_OContext3

                {CheckForUnsolicited_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 1
*                    *boolean ret= 0
                    }CanTransmit_in_OContext_
                }CheckForUnsolicited_in_OContext_
            }CheckForTaskStart_in_OContext_
        }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00')
temp= C0 81 80 00
