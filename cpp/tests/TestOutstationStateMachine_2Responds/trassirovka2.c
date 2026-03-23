********SUITE('2Responds to non-READ request while waiting for unsolicited confirm')********

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
*    *config.size()= 1

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
*pOContext->unexpectedConfirm= 0
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

                {GetResponseIIN_in_OContext1
*                *LSBMask_BROADCAST = 0x01
*                *LSBMask_CLASS1_EVENTS = 0x02
*                *LSBMask_CLASS2_EVENTS = 0x04
*                *LSBMask_CLASS3_EVENTS = 0x08
*                *LSBMask_NEED_TIME = 0x10
*                *LSBMask_LOCAL_CONTROL = 0x20
*                *LSBMask_DEVICE_TROUBLE = 0x40
*                *LSBMask_DEVICE_RESTART = 0x80
*
*                *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                *MSBMask_OBJECT_UNKNOWN = 0x02
*                *MSBMask_PARAM_ERROR = 0x04
*                *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                *MSBMask_ALREADY_EXECUTING = 0x10
*                *MSBMask_CONFIG_CORRUPT = 0x20
*                *MSBMask_RESERVED1 = 0x40
*                *MSBMask_RESERVED2 = 0x80
*

                    IsOverflown_in_EventBuffer1
*                    *pEventBuffer->overflow= 0
*                IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                *uint8_t LSB=0
*                *uint8_t MSB=0
*                IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                *uint8_t LSB=0
*                *uint8_t MSB=0
*                IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                *uint8_t LSB=80
*                *uint8_t MSB=0
                }GetResponseIIN_in_OContext_
*            CheckForUnsolicitedNull_in_OContext2
*            **inspect_IINField**
*            @*uint8_t LSB= 128
*            @*uint8_t MSB= 0

                {NullUnsolicited_in_APDUBuilders_static1
*                *uint8_t seq= 0

                    {ToByte_in_AppControlField1
*                    *ret |= AppControlField_FIR_MASK
*                    *ret |= AppControlField_FIN_MASK
*                    *ret |= AppControlField_CON_MASK
*                    *ret |= AppControlField_UNS_MASK
                    }ToByte_in_AppControlField_
                    *uint8_t ret =240
                    *uint8_t seq =0

                    {SetControl_in_APDUWrapper1
@@@@                    *write_uint8=6420114->240
                    }SetControl_in_APDUWrapper_

                    {SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=6420115->130
                    }SetFunction_in_APDUWrapper_

                    {SetIIN_in_APDUResponse1
@@@@                    *write_uint8=6420116->128
@@@@                    *write_uint8=6420117->0
                    }SetIIN_in_APDUResponse_
                }NullUnsolicited_in_APDUBuilders_static_
*                **inspect_IINField**
*                @*uint8_t LSB= 128
*                @*uint8_t MSB= 0
*            CheckForUnsolicitedNull_in_OContext3
*            **inspect_IINField**
*            @*uint8_t LSB= 128
*            @*uint8_t MSB= 0

                {RestartUnsolConfirmTimer_in_OContext1
                *pOContext= 6407256
                *&(pOContext->confirmTimer)= 6415796

                    {cancel_in_TimerExe4cpp1
                    *TimerExe4cpp *pTimerExe4cpp= 6415796
                    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6415888
                    }cancel_in_TimerExe4cpp1_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6406616

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6406616

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762691024
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6406616
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
                }RestartUnsolConfirmTimer_in_OContext_

                {Inst_in_StateUnsolicitedConfirmWait_static1

                    StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait1

                        OutstationState_in_OutstationState1
                }Inst_in_StateUnsolicitedConfirmWait_static_

                {BeginUnsolTx_in_OContext1

                    {CheckForBroadcastConfirmation_in_OContext1
                    }CheckForBroadcastConfirmation_in_OContext_
*                BeginUnsolTx_in_OContext2
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 6420114<-f0
*                @*buffer->buffer_[i]= 6420115<-82
*                @*buffer->buffer_[i]= 6420116<-80
*                @*buffer->buffer_[i]= 6420117<-0
*                BeginUnsolTx_in_OContext3
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 6420114<-f0
*                @*buffer->buffer_[i]= 6420115<-82
*                @*buffer->buffer_[i]= 6420116<-80
*                @*buffer->buffer_[i]= 6420117<-0

                    {BeginTx_in_OContext1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 6420114<-f0
*                    @*buffer->buffer_[i]= 6420115<-82
*                    @*buffer->buffer_[i]= 6420116<-80
*                    @*buffer->buffer_[i]= 6420117<-0

{BeginTransmit_in_MockLowerLayer1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 6420114<-f0
*                    @*buffer->buffer_[i]= 6420115<-82
*                    @*buffer->buffer_[i]= 6420116<-80
*                    @*buffer->buffer_[i]= 6420117<-0
}BeginTransmit_in_MockLowerLayer_
                    }BeginTx_in_OContext_
                }BeginUnsolTx_in_OContext_
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
    }OnLowerLayerUp_in_OContext_
}LowerLayerUp_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'F0 82 80 00')
temp= F0 82 80 00

{OnTxReady_in_OutstationTestObject1

    {OnTxReady_in_OContext1

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

                IsIdle_in_OutstationState_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *boolean ret= 1
                }CanTransmit_in_OContext_
*            *CheckForUnsolicited_in_OContext2
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404062<-c0
*        @*buffer->buffer_[i]= 6404063<-2

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404062<-c0
*            @*buffer->buffer_[i]= 6404063<-2
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1

                        {ProcessNewRequest_in_OContext1

                            {RespondToNonReadRequest_in_OContext1

                                {SetFunction_in_APDUWrapper1
@@@@                                *write_uint8=6418027->129
                                }SetFunction_in_APDUWrapper_

                                {ToByte_in_AppControlField1
*                                *ret |= AppControlField_FIR_MASK
*                                *ret |= AppControlField_FIN_MASK
                                }ToByte_in_AppControlField_
                                *uint8_t ret =192
                                *uint8_t seq =0

                                {SetControl_in_APDUWrapper1
@@@@                                *write_uint8=6418026->192
                                }SetControl_in_APDUWrapper_

                                {HandleNonReadResponse_in_OContext1
*                                *FunctionCode_uint18_t function= 2
*                                **inspect_RSeq**
@@@@                                *FunctionCode_WRITE

                                    {HandleWrite_in_OContext1

                                        WriteHandler_in_WriteHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6402896
                                    *HandleWrite_in_OContext2

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6402896
*                                            **inspect_RSeq**
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6402896
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    *HandleWrite_in_OContext3
*                                    *ParseResult_uint8_t result =0
                                    }HandleWrite_in_OContext_
                                }HandleNonReadResponse_in_OContext1_

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
@@@@                                *write_uint8=6418028->128
@@@@                                *write_uint8=6418029->0
                                }SetIIN_in_APDUResponse_

                                {BeginResponseTx_in_OContext1

                                    {CheckForBroadcastConfirmation_in_OContext1
                                    }CheckForBroadcastConfirmation_in_OContext_
*                                *BeginResponseTx_in_OContext2
*                                **inspect_RSeq**
*                                @*buffer->buffer_[i]= 6418026<-c0
*                                @*buffer->buffer_[i]= 6418027<-81
*                                @*buffer->buffer_[i]= 6418028<-80
*                                @*buffer->buffer_[i]= 6418029<-0
*                                *BeginResponseTx_in_OContext3
*                                **inspect_RSeq**
*                                @*buffer->buffer_[i]= 6418026<-c0
*                                @*buffer->buffer_[i]= 6418027<-81
*                                @*buffer->buffer_[i]= 6418028<-80
*                                @*buffer->buffer_[i]= 6418029<-0
*                                *BeginResponseTx_in_OContext4
*                                **inspect_RSeq**
*                                @*buffer->buffer_[i]= 6418026<-c0
*                                @*buffer->buffer_[i]= 6418027<-81
*                                @*buffer->buffer_[i]= 6418028<-80
*                                @*buffer->buffer_[i]= 6418029<-0

                                    {BeginTx_in_OContext1
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0

{BeginTransmit_in_MockLowerLayer1
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-c0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
}BeginTransmit_in_MockLowerLayer_
                                    }BeginTx_in_OContext_

                                    {Inst_in_StateIdle_static1

                                        StateIdle_in_StateIdle1

                                            OutstationState_in_OutstationState1
                                    }Inst_in_StateIdle_static_
                                }BeginResponseTx_in_OContext_
                            }RespondToNonReadRequest_in_OContext_
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
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00')
temp2= C0 81 80 00

{OnTxReady_in_OutstationTestObject1

    {OnTxReady_in_OContext1

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

                IsIdle_in_OutstationState_override1
            }CheckForUnsolicitedNull_in_OContext_
        }CheckForTaskStart_in_OContext_

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer1_
REQUIRE(t.lower->PopWriteAsHex().empty())
temp3=
