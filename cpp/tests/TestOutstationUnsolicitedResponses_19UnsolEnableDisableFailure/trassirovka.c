********SUITE('19UnsolEnableDisableFailure')********

{OutstationTestObject_in_OutstationTestObject1

{OContext_in_OContext1

    EventLists_in_EventLists1
    TotalEvents_in_EventBufferConfig1
*    *pEventBufferConfig->maxBinaryEvents= 5
*    *pEventBufferConfig->maxDoubleBinaryEvents=0
*    *pEventBufferConfig->maxAnalogEvents= 0
*    *pEventBufferConfig->maxCounterEvents= 0
*    *pEventBufferConfig->maxBinaryOutputStatusEvents= 0
*    *pEventBufferConfig->maxAnalogOutputStatusEvents= 0
*    *pEventBufferConfig->maxOctetStringEvents= 0

    List_for_EventRecord_in_List_for_EventRecordOver2_1
*    *uint32_t maxSize= 5

    List_for_EventRecord_in_List_for_EventRecordOver1_1

    Database_in_Database1

    StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*    *config.size()= 5

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
*    *config.size()= 0

    StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*    *config.size()= 0

    DeferredRequest_in_DeferredRequest1
*    *uint32_t maxAPDUSize =2048

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    TxBuffer_in_TxBuffer1
*    *uint32_t maxTxSize =2048

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    TxBuffer_in_TxBuffer1
*    *uint32_t maxTxSize =2048

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

*    Inst_in_StateIdle_static1

        StateIdle_in_StateIdle1

            OutstationState_in_OutstationState1
}OContext_in_OContext_
}OutstationTestObject_in_OutstationTestObject_

{LowerLayerUp_in_OutstationTestObject1

    {OnLowerLayerUp_in_OContext1

        {CheckForTaskStart_in_OContext1

            {CheckForDeferredRequest_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
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
*        *buffer->buffer_[i]=  c0
*        *buffer->buffer_[i]=  14
*        *buffer->buffer_[i]=  3c
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  14
*            *buffer->buffer_[i]=  3c
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext8

                        {ProcessNewRequest_in_OContext1

                            OnNewNonReadRequest_in_StateIdle_override1

                            {RespondToNonReadRequest_in_OContext1

                                {SetFunction_in_APDUWrapper1
@@@@                                *write_uint8=6421539->129
                                }SetFunction_in_APDUWrapper_

                                {ToByte_in_AppControlField1
*                                *ret |= AppControlField_FIR_MASK
*                                *ret |= AppControlField_FIN_MASK
                                }ToByte_in_AppControlField_
                                *uint8_t ret =192
                                *uint8_t seq =0

                                {SetControl_in_APDUWrapper1
@@@@                                *write_uint8=6421538->192
                                }SetControl_in_APDUWrapper_

                                {HandleNonReadResponse_in_OContext1
*                                *FunctionCode_uint18_t function= 20
@@@@                                *FunctionCode_ENABLE_UNSOLICITED
*                                *IINBit_FUNC_NOT_SUPPORTED
                                }HandleNonReadResponse_in_OContext_

                                {GetResponseIIN_in_OContext1
*                                *LSBMask_BROADCAST = 0x01
*                                *LSBMask_CLASS1_EVENTS = 0x02
*                                *LSBMask_CLASS2_EVENTS = 0x04
*                                *LSBMask_CLASS3_EVENTS = 0x08
*                                *LSBMask_NEED_TIME = 0x10
*                                *LSBMask_LOCAL_CONTROL = 0x20
*                                *LSBMask_DEVICE_TROUBLE = 0x40
*                                *LSBMask_DEVICE_RESTART = 0x80
*
*                                *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                *MSBMask_OBJECT_UNKNOWN = 0x02
*                                *MSBMask_PARAM_ERROR = 0x04
*                                *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                *MSBMask_ALREADY_EXECUTING = 0x10
*                                *MSBMask_CONFIG_CORRUPT = 0x20
*                                *MSBMask_RESERVED1 = 0x40
*                                *MSBMask_RESERVED2 = 0x80
*

                                    IsOverflown_in_EventBuffer1
*                                    *pEventBuffer->overflow= 0
*                                IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                *uint8_t LSB=0
*                                *uint8_t MSB=0
*                                IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                *uint8_t LSB=0
*                                *uint8_t MSB=0
*                                IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                *uint8_t LSB=80
*                                *uint8_t MSB=0
                                }GetResponseIIN_in_OContext_

                                {SetIIN_in_APDUResponse1
@@@@                                *write_uint8=6421540->128
@@@@                                *write_uint8=6421541->1
                                }SetIIN_in_APDUResponse_

                                {BeginResponseTx_in_OContext1

                                    {CheckForBroadcastConfirmation_in_OContext1
                                    }CheckForBroadcastConfirmation_in_OContext_

                                    {BeginTx_in_OContext1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  c0
*                                    *buffer->buffer_[i]=  81
*                                    *buffer->buffer_[i]=  80
*                                    *buffer->buffer_[i]=  1

{BeginTransmit_in_MockLowerLayer1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  c0
*                                    *buffer->buffer_[i]=  81
*                                    *buffer->buffer_[i]=  80
*                                    *buffer->buffer_[i]=  1
}BeginTransmit_in_MockLowerLayer_
                                    }BeginTx_in_OContext_

*                                    Inst_in_StateIdle_static1

                                        StateIdle_in_StateIdle1

                                            OutstationState_in_OutstationState1
                                }BeginResponseTx_in_OContext_
                            }RespondToNonReadRequest_in_OContext_
                    }ProcessNewRequest_in_OContext2_
                }OnReceiveSolRequest_in_OContext_
            }ProcessRequest_in_OContext_
        }ProcessObjects_in_OContext_
    }ProcessMessage_in_OContext6_

    {CheckForTaskStart_in_OContext1

        {CheckForDeferredRequest_in_OContext1

            {CanTransmit_in_OContext1
*            *pOContext->isOnline && !pOContext->isTransmitting= 0
            }CanTransmit_in_OContext_
        }CheckForDeferredRequest_in_OContext_
*    CheckForTaskStart_in_OContext2

        {CheckForUnsolicitedNull_in_OContext1

            {CanTransmit_in_OContext1
*            *pOContext->isOnline && !pOContext->isTransmitting= 0
            }CanTransmit_in_OContext_
        }CheckForUnsolicitedNull_in_OContext_
*    CheckForTaskStart_in_OContext3

        {CheckForUnsolicited_in_OContext1

            {CanTransmit_in_OContext1
*            *pOContext->isOnline && !pOContext->isTransmitting= 0
            }CanTransmit_in_OContext_
        }CheckForUnsolicited_in_OContext_
    }CheckForTaskStart_in_OContext_
}OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 01')
temp1= C0 81 80 01
