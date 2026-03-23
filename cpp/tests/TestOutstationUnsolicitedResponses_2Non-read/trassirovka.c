********SUITE('2Non-read during null unsol without workaround')********
{------------1

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6411880
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
*            *uint8_t LSB= 128
*            *uint8_t MSB= 0

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
@@@@                    *write_uint8=6421870->240
                    }SetControl_in_APDUWrapper_

                    {SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=6421871->130
                    }SetFunction_in_APDUWrapper_

                    {SetIIN_in_APDUResponse1
@@@@                    *write_uint8=6421872->128
@@@@                    *write_uint8=6421873->0
                    }SetIIN_in_APDUResponse_
                }NullUnsolicited_in_APDUBuilders_static_
*                **inspect_IINField**
*                *uint8_t LSB= 128
*                *uint8_t MSB= 0
*            CheckForUnsolicitedNull_in_OContext3
*            **inspect_IINField**
*            *uint8_t LSB= 128
*            *uint8_t MSB= 0

                {RestartUnsolConfirmTimer_in_OContext1
                *pOContext= 6412520
                *&(pOContext->confirmTimer)= 6421060

                    {cancel_in_TimerExe4cpp1
                    *TimerExe4cpp *pTimerExe4cpp= 6421060
                    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
                    }cancel_in_TimerExe4cpp1_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6411880

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6411880

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762681328
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6411880
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
*                *buffer->buffer_[i]=  f0
*                *buffer->buffer_[i]=  82
*                *buffer->buffer_[i]=  80
*                *buffer->buffer_[i]=  0
*                BeginUnsolTx_in_OContext3
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  f0
*                *buffer->buffer_[i]=  82
*                *buffer->buffer_[i]=  80
*                *buffer->buffer_[i]=  0

                    {BeginTx_in_OContext1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  f0
*                    *buffer->buffer_[i]=  82
*                    *buffer->buffer_[i]=  80
*                    *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  f0
*                    *buffer->buffer_[i]=  82
*                    *buffer->buffer_[i]=  80
*                    *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                    }BeginTx_in_OContext_
                }BeginUnsolTx_in_OContext_
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
    }OnLowerLayerUp_in_OContext_
}LowerLayerUp_in_OutstationTestObject_

{NullUnsolicited_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    {NullUnsolicited_in_APDUBuilders_static1
*    *uint8_t seq= 0

        {ToByte_in_AppControlField1
*        *ret |= AppControlField_FIR_MASK
*        *ret |= AppControlField_FIN_MASK
*        *ret |= AppControlField_CON_MASK
*        *ret |= AppControlField_UNS_MASK
        }ToByte_in_AppControlField_
        *uint8_t ret =240
        *uint8_t seq =0

        {SetControl_in_APDUWrapper1
@@@@        *write_uint8=6410988->240
        }SetControl_in_APDUWrapper_

        {SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6410989->130
        }SetFunction_in_APDUWrapper_

        {SetIIN_in_APDUResponse1
@@@@        *write_uint8=6410990->128
@@@@        *write_uint8=6410991->0
        }SetIIN_in_APDUResponse_
    }NullUnsolicited_in_APDUBuilders_static_
*    **inspect_IINField**
*    *uint8_t LSB= 128
*    *uint8_t MSB= 0
}NullUnsolicited_in_APDUHexBuilders_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}------------1
respond= F0 82 80 00
REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)))
temp1= F0 82 80 00

{OnTxReady_in_OutstationTestObject1

    {OnTxReady_in_OContext1

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

                IsIdle_in_OutstationState_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 0
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
*            CheckForUnsolicited_in_OContext2
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
REQUIRE(t.lower->NumWrites() == 0)
num= 0
{------------2

{ClearRestartIIN_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6410989->2
    }SetFunction_in_APDUWrapper_

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6410988->192
    }SetControl_in_APDUWrapper_

    WriteHeaderWithReserve_in_HeaderWriter1
*    *qc= 0
*    *reserve= 3

    WriteHeader_in_HeaderWriter1
*    *id.group= 80
*    *id.variation= 1
*    *qc= 0
@@@@    *write_in_UInt8_static = 6410990->80
@@@@    *write_in_UInt8_static = 6410991->1
@@@@    *write_in_UInt8_static = 6410992->0

    BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8_1
@@@@    *write_in_UInt8_static = 6410993->7

    Write_in_BitfieldRangeWriteIterator_for_UInt8_1
@@@@*write_uint8=6410995->0

    BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8_1
@@@@*write_in_UInt8_static = 6410994->7
}ClearRestartIIN_in_APDUHexBuilders_
clrStr= C0 02 50 01 00 07 07 00

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c0
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  50
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  0

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  50
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  0
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext8

                        {ProcessNewRequest_in_OContext1

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
*                                *FunctionCode_uint18_t function= 2
@@@@                                *FunctionCode_WRITE

                                    {HandleWrite_in_OContext1

                                        WriteHandler_in_WriteHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6409872
                                    HandleWrite_in_OContext2

                                        Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  50
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  7
*                                        *buffer->buffer_[i]=  7
*                                        *buffer->buffer_[i]=  0

                                            ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6409872
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  50
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  50
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0

                                                ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  50
*                                                *buffer->buffer_[i]=  1
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  50
*                                                    *buffer->buffer_[i]=  1
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  0
                                                ParseHeader_in_APDUParser_static2

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 80
*                                                    *uint8_t variation= 1

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 80
*                                                        *uint8_t variation= 1

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 80
*                                                            *uint8_t variation= 1
*                                                            *GroupVariationType_OTHER
*                                                        *GroupVariation_uint16_t enumeration= 5001
                                                ParseHeader_in_APDUParser_static3
                                                ParseHeader_in_APDUParser_static4

                                                ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =0
@@@@                                                *QualifierCode_UINT8_START_STOP*

                                                NumParser_in_NumParser1

                                                ParseHeader_in_RangeParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseRange_in_NumParser1
*                                                    *ParseResult_uint8_t res = 0
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  0
*                                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                    *record.group= 80
*                                                    *record.variation= 1
*                                                    *record.enumeration= 20481
*                                                    *record.GetQualifierCode()= 0
*                                                    *range.start= 7
*                                                    *range.stop= 7

                                                    ParseRangeOfObjects_in_RangeParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  0
*                                                    *GroupVariation_Group80Var1

                                                    Process_in_RangeParser1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  0
                                            Parse_in_APDUParser_static2

                                            ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6409872
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  50
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  50
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0

                                                ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  50
*                                                *buffer->buffer_[i]=  1
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  50
*                                                    *buffer->buffer_[i]=  1
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  0
                                                ParseHeader_in_APDUParser_static2

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 80
*                                                    *uint8_t variation= 1

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 80
*                                                        *uint8_t variation= 1

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 80
*                                                            *uint8_t variation= 1
*                                                            *GroupVariationType_OTHER
*                                                        *GroupVariation_uint16_t enumeration= 5001
                                                ParseHeader_in_APDUParser_static3
                                                ParseHeader_in_APDUParser_static4

                                                ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =0
@@@@                                                *QualifierCode_UINT8_START_STOP*

                                                NumParser_in_NumParser1

                                                ParseHeader_in_RangeParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseRange_in_NumParser1
*                                                    *ParseResult_uint8_t res = 0
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  0
*                                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                    *record.group= 80
*                                                    *record.variation= 1
*                                                    *record.enumeration= 20481
*                                                    *record.GetQualifierCode()= 0
*                                                    *range.start= 7
*                                                    *range.stop= 7

                                                    ParseRangeOfObjects_in_RangeParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  0
*                                                    *GroupVariation_Group80Var1

                                                    Process_in_RangeParser1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  0

                                                        OnHeader_RangeHeader_for_IINValue_in_IAPDUHandler1

                                                        ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override1

                                                            *123                                                        *IINBit_DEVICE_RESTART

                                                        Record_in_IAPDUHandler1
                                            HandleWrite_in_OContext3
*                                            *ParseResult_uint8_t result =0
                                            }HandleWrite_in_OContext_
                                        }HandleNonReadResponse_in_OContext_

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
*                                        *uint8_t LSB=0
*                                        *uint8_t MSB=0
                                        }GetResponseIIN_in_OContext_

                                        {SetIIN_in_APDUResponse1
@@@@                                        *write_uint8=6421540->0
@@@@                                        *write_uint8=6421541->0
                                        }SetIIN_in_APDUResponse_

                                        {BeginResponseTx_in_OContext1

                                            {CheckForBroadcastConfirmation_in_OContext1
                                            }CheckForBroadcastConfirmation_in_OContext_

                                            {BeginTx_in_OContext1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  c0
*                                            *buffer->buffer_[i]=  81
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  c0
*                                            *buffer->buffer_[i]=  81
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  0
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
                    }ProcessObjects_in_OContext_
                }ProcessMessage_in_OContext6_

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline= 1
*                        *pOContext->isTransmitting= 1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 0
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline= 1
*                        *pOContext->isTransmitting= 1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 0
                        }CanTransmit_in_OContext_
                    }CheckForUnsolicitedNull_in_OContext_
                }CheckForTaskStart_in_OContext_
            }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{EmptyResponse_in_APDUHexBuilders1
*uint8_t seq= 0

            BufferSer4_in_BufferSer4Over2_1
*            *uint16_t length=2048

            {SetFunction_in_APDUWrapper1
@@@@            *write_uint8=6410989->129
            }SetFunction_in_APDUWrapper_

            {ToByte_in_AppControlField1
*            *ret |= AppControlField_FIR_MASK
*            *ret |= AppControlField_FIN_MASK
            }ToByte_in_AppControlField_
            *uint8_t ret =192
            *uint8_t seq =0

            {SetControl_in_APDUWrapper1
@@@@            *write_uint8=6410988->192
            }SetControl_in_APDUWrapper_

            {SetIIN_in_APDUResponse1
@@@@            *write_uint8=6410990->0
@@@@            *write_uint8=6410991->0
            }SetIIN_in_APDUResponse_
}EmptyResponse_in_APDUHexBuilders_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}------------2
REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0))
emptyStr= C0 81 00 00
temp2= C0 81 00 00

{OnTxReady_in_OutstationTestObject1

            {OnTxReady_in_OContext1

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline= 1
*                        *pOContext->isTransmitting= 0
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline= 1
*                        *pOContext->isTransmitting= 0
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_OutstationState_override1
                    }CheckForUnsolicitedNull_in_OContext_
                }CheckForTaskStart_in_OContext_

            }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{------------timeout_RestartUnsolConfirmTimer_in_OContext

            {timeout_RestartUnsolConfirmTimer_in_OContext1

                {OnConfirmTimeout_in_StateUnsolicitedConfirmWait_override1
*                *SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'unsolicited confirm timeout')

                    {Inst_in_StateIdle_static1

                        StateIdle_in_StateIdle1

                            OutstationState_in_OutstationState1
                    }Inst_in_StateIdle_static_
                }OnConfirmTimeout_in_StateUnsolicitedConfirmWait_override2_

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline= 1
*                        *pOContext->isTransmitting= 0
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline= 1
*                        *pOContext->isTransmitting= 0
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_StateIdle_override1

                        {GetResponseIIN_in_OContext1
*                        *LSBMask_BROADCAST = 0x01
*                        *LSBMask_CLASS1_EVENTS = 0x02
*                        *LSBMask_CLASS2_EVENTS = 0x04
*                        *LSBMask_CLASS3_EVENTS = 0x08
*                        *LSBMask_NEED_TIME = 0x10
*                        *LSBMask_LOCAL_CONTROL = 0x20
*                        *LSBMask_DEVICE_TROUBLE = 0x40
*                        *LSBMask_DEVICE_RESTART = 0x80
*
*                        *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                        *MSBMask_OBJECT_UNKNOWN = 0x02
*                        *MSBMask_PARAM_ERROR = 0x04
*                        *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                        *MSBMask_ALREADY_EXECUTING = 0x10
*                        *MSBMask_CONFIG_CORRUPT = 0x20
*                        *MSBMask_RESERVED1 = 0x40
*                        *MSBMask_RESERVED2 = 0x80
*

                            IsOverflown_in_EventBuffer1
*                            *pEventBuffer->overflow= 0
*                        IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                        *uint8_t LSB=0
*                        *uint8_t MSB=0
*                        IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                        *uint8_t LSB=0
*                        *uint8_t MSB=0
*                        IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                        *uint8_t LSB=0
*                        *uint8_t MSB=0
                        }GetResponseIIN_in_OContext_
*                    CheckForUnsolicitedNull_in_OContext2
*                    **inspect_IINField**
*                    *uint8_t LSB= 0
*                    *uint8_t MSB= 0

                        {NullUnsolicited_in_APDUBuilders_static1
*                        *uint8_t seq= 1

                            {ToByte_in_AppControlField1
*                            *ret |= AppControlField_FIR_MASK
*                            *ret |= AppControlField_FIN_MASK
*                            *ret |= AppControlField_CON_MASK
*                            *ret |= AppControlField_UNS_MASK
                            }ToByte_in_AppControlField_
                            *uint8_t ret =240
                            *uint8_t seq =1

                            {SetControl_in_APDUWrapper1
@@@@                            *write_uint8=6421870->241
                            }SetControl_in_APDUWrapper_

                            {SetFunction_in_APDUWrapper1
@@@@                            *write_uint8=6421871->130
                            }SetFunction_in_APDUWrapper_

                            {SetIIN_in_APDUResponse1
@@@@                            *write_uint8=6421872->0
@@@@                            *write_uint8=6421873->0
                            }SetIIN_in_APDUResponse_
                        }NullUnsolicited_in_APDUBuilders_static_
*                        **inspect_IINField**
*                        *uint8_t LSB= 0
*                        *uint8_t MSB= 0
*                    CheckForUnsolicitedNull_in_OContext3
*                    **inspect_IINField**
*                    *uint8_t LSB= 0
*                    *uint8_t MSB= 0

                        {RestartUnsolConfirmTimer_in_OContext1
                        *pOContext= 6412520
                        *&(pOContext->confirmTimer)= 6421060

                            {cancel_in_TimerExe4cpp1
                            *TimerExe4cpp *pTimerExe4cpp= 6421060
                            *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6411880

                                {cancel_in_ITimer1
                                *pITimer->psource_in_ITimer= 6411880

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6411880
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                }cancel_in_ITimer1
                            }cancel_in_TimerExe4cpp2_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6411880

{Start_in_MockExecutorOver2_1
*uint32_t duration= 10333
*MockExecutor *pMockExecutor= 6411880

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762681328
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6411880
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
*                        BeginUnsolTx_in_OContext2
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f1
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        BeginUnsolTx_in_OContext3
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f1
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0

                            {BeginTx_in_OContext1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f1
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f1
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                            }BeginTx_in_OContext_
                        }BeginUnsolTx_in_OContext_
                    }CheckForUnsolicitedNull_in_OContext_
                }CheckForTaskStart_in_OContext_
            }timeout_RestartUnsolConfirmTimer_in_OContext_
}------------timeout_RestartUnsolConfirmTimer_in_OContext
{------------3

{NullUnsolicited_in_APDUHexBuilders1
*uint8_t seq= 1

            BufferSer4_in_BufferSer4Over2_1
*            *uint16_t length=2048

            {NullUnsolicited_in_APDUBuilders_static1
*            *uint8_t seq= 1

                {ToByte_in_AppControlField1
*                *ret |= AppControlField_FIR_MASK
*                *ret |= AppControlField_FIN_MASK
*                *ret |= AppControlField_CON_MASK
*                *ret |= AppControlField_UNS_MASK
                }ToByte_in_AppControlField_
                *uint8_t ret =240
                *uint8_t seq =1

                {SetControl_in_APDUWrapper1
@@@@                *write_uint8=6410988->241
                }SetControl_in_APDUWrapper_

                {SetFunction_in_APDUWrapper1
@@@@                *write_uint8=6410989->130
                }SetFunction_in_APDUWrapper_

                {SetIIN_in_APDUResponse1
@@@@                *write_uint8=6410990->0
@@@@                *write_uint8=6410991->0
                }SetIIN_in_APDUResponse_
            }NullUnsolicited_in_APDUBuilders_static_
*            **inspect_IINField**
*            *uint8_t LSB= 0
*            *uint8_t MSB= 0
}NullUnsolicited_in_APDUHexBuilders_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}------------3
REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()))
respond3= F1 82 00 00
temp3= F1 82 00 00
REQUIRE(t.NumPendingTimers() == 1)
num3= 1
