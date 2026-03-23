********SUITE('2ApplicationIINBits')********

DatabaseConfig_in_DatabaseConfig1

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
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
*        *config.size()= 0

        StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*        *config.size()= 0

        DeferredRequest_in_DeferredRequest1
*        *uint32_t maxAPDUSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6415886

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6418026

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6420114

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

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404094<-c0
*        @*buffer->buffer_[i]= 6404095<-1

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404094<-c0
*            @*buffer->buffer_[i]= 6404095<-1
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
@@@@                                    *write_uint8=6418027->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
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
*                                        *pIAPDUHandler= 6403004

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6403004
*                                            **inspect_RSeq**
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6403004
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
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
*                                        *map.map.size()= 0
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
@@@@                                    *write_uint8=6418026->192
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
*                                    *uint8_t LSB=70
*                                    *uint8_t MSB=20
*                                    IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                    *uint8_t LSB=f0
*                                    *uint8_t MSB=20
                                    }GetResponseIIN_in_OContext_

                                    {SetIIN_in_APDUResponse1
@@@@                                    *write_uint8=6418028->240
@@@@                                    *write_uint8=6418029->32
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_
*                                    *BeginResponseTx_in_OContext2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-f0
*                                    @*buffer->buffer_[i]= 6418029<-20
*                                    *BeginResponseTx_in_OContext3
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-f0
*                                    @*buffer->buffer_[i]= 6418029<-20
*                                    *BeginResponseTx_in_OContext4
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-f0
*                                    @*buffer->buffer_[i]= 6418029<-20

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-f0
*                                        @*buffer->buffer_[i]= 6418029<-20

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-f0
*                                        @*buffer->buffer_[i]= 6418029<-20
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
            }ProcessObjects_in_OContext5_
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
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 F0 20')
temp= C0 81 F0 20
{LowerLayerDown_in_OutstationTestObject1

    {Inst_in_StateIdle_static1

        StateIdle_in_StateIdle1

            OutstationState_in_OutstationState1
    }Inst_in_StateIdle_static_

    Unselect_in_EventStorage1

        Foreach_in_List_for_EventRecord1

            Iterate_in_List_for_EventRecord1
*            *pList_for_EventRecord->head= 0

                From__in__Iterator_in_List_for_EventRecord_static1
*                *Node_for_EventRecord* start= 0

                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                *Node_for_EventRecord* start= 0

    {cancel_in_TimerExe4cpp1
    *TimerExe4cpp *pTimerExe4cpp= 6415796
    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6415888
    }cancel_in_TimerExe4cpp1_
}LowerLayerDown_in_OutstationTestObject_

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

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404094<-c0
*        @*buffer->buffer_[i]= 6404095<-1

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404094<-c0
*            @*buffer->buffer_[i]= 6404095<-1
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
@@@@                                    *write_uint8=6418027->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
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
*                                        *pIAPDUHandler= 6403004

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6403004
*                                            **inspect_RSeq**
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6403004
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
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
*                                        *map.map.size()= 0
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
@@@@                                    *write_uint8=6418026->192
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
*                                    *uint8_t LSB=70
*                                    *uint8_t MSB=20
*                                    IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                    *uint8_t LSB=f0
*                                    *uint8_t MSB=20
                                    }GetResponseIIN_in_OContext_

                                    {SetIIN_in_APDUResponse1
@@@@                                    *write_uint8=6418028->240
@@@@                                    *write_uint8=6418029->32
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_
*                                    *BeginResponseTx_in_OContext2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-f0
*                                    @*buffer->buffer_[i]= 6418029<-20
*                                    *BeginResponseTx_in_OContext3
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-f0
*                                    @*buffer->buffer_[i]= 6418029<-20
*                                    *BeginResponseTx_in_OContext4
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-f0
*                                    @*buffer->buffer_[i]= 6418029<-20

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-f0
*                                        @*buffer->buffer_[i]= 6418029<-20

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-f0
*                                        @*buffer->buffer_[i]= 6418029<-20
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
            }ProcessObjects_in_OContext5_
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
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 F0 20')
temp2= C0 81 F0 20