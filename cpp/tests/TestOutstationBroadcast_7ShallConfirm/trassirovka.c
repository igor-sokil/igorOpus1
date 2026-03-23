********SUITE('7ShallConfirm: Unsolicited responses should clear BROADCAST when confirm is received')********
{+++++++++++7ShallConfirm1

{OutstationTestObject_in_OutstationTestObject1

{OContext_in_OContext1

    EventLists_in_EventLists1
    TotalEvents_in_EventBufferConfig1
*    *pEventBufferConfig->maxBinaryEvents= 10
*    *pEventBufferConfig->maxDoubleBinaryEvents=10
*    *pEventBufferConfig->maxAnalogEvents= 10
*    *pEventBufferConfig->maxCounterEvents= 10
*    *pEventBufferConfig->maxBinaryOutputStatusEvents= 10
*    *pEventBufferConfig->maxAnalogOutputStatusEvents= 10
*    *pEventBufferConfig->maxOctetStringEvents= 10

    List_for_EventRecord_in_List_for_EventRecordOver2_1
*    *uint32_t maxSize= 80

    List_for_EventRecord_in_List_for_EventRecordOver1_1

    Database_in_Database1

    StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*    *config.size()= 1

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

                    ToByte_in_AppControlField1
                    ToByte_in_AppControlField2
                    *uint8_t ret =240
                    *uint8_t seq =0

                    SetControl_in_APDUWrapper1
@@@@                    *write_uint8=6421870->240

                    SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=6421871->130

                    SetIIN_in_APDUResponse1
@@@@                    *write_uint8=6421872->128
@@@@                    *write_uint8=6421873->0
                }NullUnsolicited_in_APDUBuilders_static_
*                **inspect_IINField**
*                *uint8_t LSB= 128
*                *uint8_t MSB= 0
*            CheckForUnsolicitedNull_in_OContext3
*            **inspect_IINField**
*            *uint8_t LSB= 128
*            *uint8_t MSB= 0

*                Inst_in_StateUnsolicitedConfirmWait_static1

                    StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait1

                        OutstationState_in_OutstationState1

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
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnLowerLayerUp_in_OContext_
}LowerLayerUp_in_OutstationTestObject_

{OnTxReady_in_OutstationTestObject1

    {OnTxReady_in_OContext1

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

                IsIdle_in_OutstationState_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
*            CheckForUnsolicited_in_OContext2
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{NullUnsolicited_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    {NullUnsolicited_in_APDUBuilders_static1
*    *uint8_t seq= 0

        ToByte_in_AppControlField1
        ToByte_in_AppControlField2
        *uint8_t ret =240
        *uint8_t seq =0

        SetControl_in_APDUWrapper1
@@@@        *write_uint8=6410972->240

        SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6410973->130

        SetIIN_in_APDUResponse1
@@@@        *write_uint8=6410974->128
@@@@        *write_uint8=6410975->0
    }NullUnsolicited_in_APDUBuilders_static_
*    **inspect_IINField**
*    *uint8_t LSB= 128
*    *uint8_t MSB= 0
}NullUnsolicited_in_APDUHexBuilders_
}----------7ShallConfirm1

{PopWriteAsHex_in_MockLowerLayer1
***inspect_RSeq**
**buffer->buffer_[i]=  f0
**buffer->buffer_[i]=  82
**buffer->buffer_[i]=  80
**buffer->buffer_[i]=  0
}PopWriteAsHex_in_MockLowerLayer_
 REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0))
response= F0 82 80 00
temp1= F0 82 80 00
{+++++++++++7ShallConfirm2
{+++++++++++t.SendToOutstation(hex::UnsolConfirm(0))

{UnsolConfirm_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    ToByte_in_AppControlField1
    ToByte_in_AppControlField2
    *uint8_t ret =208
    *uint8_t seq =0

    SetControl_in_APDUWrapper1
@@@@    *write_uint8=6410924->208

    SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6410925->0
}UnsolConfirm_in_APDUHexBuilders_
unconstr= D0 00

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  d0
*        *buffer->buffer_[i]=  0

            ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  d0
*            *buffer->buffer_[i]=  0
            ParseRequest_in_APDUHeaderParser_static3

            {ProcessObjects_in_OContext1
*            *FunctionCode_CONFIRM

                {ProcessConfirm_in_OContext1

                    {OnConfirm_in_StateUnsolicitedConfirmWait_override1
                    OnConfirm_in_StateUnsolicitedConfirmWait_override2
                    OnConfirm_in_StateUnsolicitedConfirmWait_override3
                    OnConfirm_in_StateUnsolicitedConfirmWait_override4

*                        Inst_in_StateIdle_static1

                            StateIdle_in_StateIdle1

                                OutstationState_in_OutstationState1
                    }OnConfirm_in_StateUnsolicitedConfirmWait_override3_
                }ProcessConfirm_in_OContext_
            }ProcessObjects_in_OContext_
        }ProcessMessage_in_OContext_

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
*            CheckForUnsolicited_in_OContext2
*            CheckForUnsolicited_in_OContext3
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_
}----------t.SendToOutstation(hex::UnsolConfirm(0))
{+++++++++++t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1))

{ClearRestartIIN_in_APDUHexBuilders1
*uint8_t seq= 1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6410973->2

    ToByte_in_AppControlField1
    ToByte_in_AppControlField2
    *uint8_t ret =192
    *uint8_t seq =1

    SetControl_in_APDUWrapper1
@@@@    *write_uint8=6410972->193

    WriteHeaderWithReserve_in_HeaderWriter1
*    *qc= 0
*    *reserve= 3

    WriteHeader_in_HeaderWriter1
*    *id.group= 80
*    *id.variation= 1
*    *qc= 0
@@@@    *write_in_UInt8_static = 6410974->80
@@@@    *write_in_UInt8_static = 6410975->1
@@@@    *write_in_UInt8_static = 6410976->0

    BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8_1
@@@@    *write_in_UInt8_static = 6410977->7

    Write_in_BitfieldRangeWriteIterator_for_UInt8_1
@@@@*write_uint8=6410979->0

    BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8_1
@@@@*write_in_UInt8_static = 6410978->7
}ClearRestartIIN_in_APDUHexBuilders_
clrStr= C1 02 50 01 00 07 07 00

{BroadcastToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c1
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  50
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  0

            ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c1
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  50
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  0
            ParseRequest_in_APDUHeaderParser_static3

            {ProcessObjects_in_OContext1

                {ProcessBroadcastRequest_in_OContext1
@@@@                *FunctionCode_WRITE

                    {HandleWrite_in_OContext1

                        WriteHandler_in_WriteHandler1

                        IAPDUHandler_in_IAPDUHandler1
*                        *pIAPDUHandler= 6410288
                    HandleWrite_in_OContext2

                        Parse_in_APDUParser_static1
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  50
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  7
*                        *buffer->buffer_[i]=  7
*                        *buffer->buffer_[i]=  0

                            ParseSinglePass_in_APDUParser_static1
*                            *IAPDUHandler* pHandler=0
*                            *IWhiteList* pWhiteList=6410288
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  50
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  0
*                            *copy
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  50
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  0

                                ParseHeader_in_APDUParser_static1
*                                **inspect_RSeq**
*                                *buffer->buffer_[i]=  50
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  0

                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  50
*                                    *buffer->buffer_[i]=  1
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  7
*                                    *buffer->buffer_[i]=  7
*                                    *buffer->buffer_[i]=  0
                                ParseHeader_in_APDUParser_static2

                                    GetRecord_in_GroupVariationRecord_static1
*                                    *uint8_t group= 80
*                                    *uint8_t variation= 1

                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                        *uint8_t group= 80
*                                        *uint8_t variation= 1

                                            GetType_in_GroupVariationRecord_static1
*                                            *uint8_t group= 80
*                                            *uint8_t variation= 1
*                                            *GroupVariationType_OTHER
*                                        *GroupVariation_uint16_t enumeration= 5001
                                ParseHeader_in_APDUParser_static3
                                ParseHeader_in_APDUParser_static4

                                ParseQualifier_in_APDUParser_static1
*                                *QualifierCode_uint8_t tmp =0
@@@@                                *QualifierCode_UINT8_START_STOP*

                                NumParser_in_NumParser1

                                ParseHeader_in_RangeParser_static1
*                                **inspect_RSeq**
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  0

                                    ParseRange_in_NumParser1
*                                    *ParseResult_uint8_t res = 0
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  0
*                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                    *record.group= 80
*                                    *record.variation= 1
*                                    *record.enumeration= 20481
*                                    *record.GetQualifierCode()= 0
*                                    *range.start= 7
*                                    *range.stop= 7

                                    ParseRangeOfObjects_in_RangeParser_static1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  0
*                                    *GroupVariation_Group80Var1

                                    Process_in_RangeParser1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  0
                            Parse_in_APDUParser_static2

                            ParseSinglePass_in_APDUParser_static1
*                            *IAPDUHandler* pHandler=6410288
*                            *IWhiteList* pWhiteList=0
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  50
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  0
*                            *copy
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  50
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  7
*                            *buffer->buffer_[i]=  0

                                ParseHeader_in_APDUParser_static1
*                                **inspect_RSeq**
*                                *buffer->buffer_[i]=  50
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  0

                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  50
*                                    *buffer->buffer_[i]=  1
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  7
*                                    *buffer->buffer_[i]=  7
*                                    *buffer->buffer_[i]=  0
                                ParseHeader_in_APDUParser_static2

                                    GetRecord_in_GroupVariationRecord_static1
*                                    *uint8_t group= 80
*                                    *uint8_t variation= 1

                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                        *uint8_t group= 80
*                                        *uint8_t variation= 1

                                            GetType_in_GroupVariationRecord_static1
*                                            *uint8_t group= 80
*                                            *uint8_t variation= 1
*                                            *GroupVariationType_OTHER
*                                        *GroupVariation_uint16_t enumeration= 5001
                                ParseHeader_in_APDUParser_static3
                                ParseHeader_in_APDUParser_static4

                                ParseQualifier_in_APDUParser_static1
*                                *QualifierCode_uint8_t tmp =0
@@@@                                *QualifierCode_UINT8_START_STOP*

                                NumParser_in_NumParser1

                                ParseHeader_in_RangeParser_static1
*                                **inspect_RSeq**
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  7
*                                *buffer->buffer_[i]=  0

                                    ParseRange_in_NumParser1
*                                    *ParseResult_uint8_t res = 0
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  0
*                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                    *record.group= 80
*                                    *record.variation= 1
*                                    *record.enumeration= 20481
*                                    *record.GetQualifierCode()= 0
*                                    *range.start= 7
*                                    *range.stop= 7

                                    ParseRangeOfObjects_in_RangeParser_static1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  0
*                                    *GroupVariation_Group80Var1

                                    Process_in_RangeParser1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  0

                                        OnHeader_RangeHeader_for_IINValue_in_IAPDUHandler1

                                        ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override1

                                            *123                                        *IINBit_DEVICE_RESTART

                                        Record_in_IAPDUHandler1
                            HandleWrite_in_OContext3
*                            *ParseResult_uint8_t result =0
                            }HandleWrite_in_OContext_
                        }ProcessBroadcastRequest_in_OContext_
                    }ProcessObjects_in_OContext_
                }ProcessMessage_in_OContext_

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_StateIdle_override1
                    }CheckForUnsolicitedNull_in_OContext_
                }CheckForTaskStart_in_OContext_
            }OnReceive_in_OContext_
}BroadcastToOutstation_in_OutstationTestObject_
}----------t.BroadcastToOutstation(LinkBroadcastAddress::ShallConfirm, hex::ClearRestartIIN(1))

{HasNoData_in_MockLowerLayer1
}HasNoData_in_MockLowerLayer_
}----------7ShallConfirm2
REQUIRE(t.lower->HasNoData())
btemp= 1
{+++++++++++7ShallConfirm3

{Transaction_in_OutstationTestObject1
apply_in_7ShallConfirm

            {Update_Binary_in_IUpdateHandler1

                {update_in_StaticDataMap_for_BinarySpecOver2_1
*                *iter->second.config.eEventConfig.clazz= 2
+                ++++++int16_t nnn = iter->first=0
*                **inspect_Binary**
*                *boolean value= 1
*                *Flags flags.value= 129
*                *DNPTime timeDNPTime.value= 6411521
*                *DNPTime timeDNPTime.quality= 25

                    convert_to_event_class_in_StaticDataMap_static1
*                    *PointClass_uint8_t pc= 2
*                    *PointClass_Class1= 2
*                    *PointClass_Class2= 4
*                    *PointClass_Class3= 8
                update_in_StaticDataMap_for_BinarySpecOver2_2

                    UpdateAny_BinarySpec_in_EventBuffer1

                        Update_BinarySpec_in_EventUpdate_static1

                            Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static1
                }update_in_StaticDataMap_for_BinarySpecOver2__
            }Update_Binary_in_IUpdateHandler_

            {HandleNewEvents_in_OContext1

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_StateIdle_override1
                    }CheckForUnsolicitedNull_in_OContext_
*                CheckForTaskStart_in_OContext3

                    {CheckForUnsolicited_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
*                    CheckForUnsolicited_in_OContext2
*                    CheckForUnsolicited_in_OContext3
*                    {CheckForUnsolicited_in_OContext4
*                    {CheckForUnsolicited_in_OContext5

                        Unselect_in_EventStorage1

                            Foreach_in_List_for_EventRecord1

                                Iterate_in_List_for_EventRecord1
*                                *pList_for_EventRecord->head= 6412672

                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                    *Node_for_EventRecord* start= 6412672

                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                    *Node_for_EventRecord* start= 6412672
*                    }CheckForUnsolicited_in_OContext5_
*                    {CheckForUnsolicited_in_OContext6

                        SelectByClass_in_EventSelection_static1
*                        *uint32_t max= 65535

                            Iterate_in_List_for_EventRecord1
*                            *pList_for_EventRecord->head= 6412672

                                From__in__Iterator_in_List_for_EventRecord_static1
*                                *Node_for_EventRecord* start= 6412672

                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                *Node_for_EventRecord* start= 6412672
                        SelectByClass_in_EventSelection_static2

                            OnSelect_in_EventClassCounters1

                        {Load_in_EventBuffer1

                            {Write_in_EventWriting_static1

                                Iterate_in_List_for_EventRecord1
*                                *pList_for_EventRecord->head= 6412672

                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                    *Node_for_EventRecord* start= 6412672

                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                    *Node_for_EventRecord* start= 6412672

                                WriteSome_in_EventWriting_static1
*                                *lists->counters.selected= 1
                                WriteSome_in_EventWriting_static2
                                WriteSome_in_EventWriting_static3

                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override1

                                        Write_for_Binary_in_ASDUEventWriteHandler_override1
*                                        *EventBinaryVariation_uint8_t variation= 0
@@@@                                        *EventBinaryVariation_Group2Var1

                                            Write_for_Binary_in_EventWriters_static1

                                                BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary1

                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter1

                                                        WriteHeaderWithReserve_in_HeaderWriter1
*                                                        *qc= 40
*                                                        *reserve= 5

                                                        WriteHeader_in_HeaderWriter1
*                                                        *id.group= 2
*                                                        *id.variation= 1
*                                                        *qc= 40
@@@@                                                        *write_in_UInt8_static = 6421874->2
@@@@                                                        *write_in_UInt8_static = 6421875->1
@@@@                                                        *write_in_UInt8_static = 6421876->40

                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_1
                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_2
                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter2

                                                WriteSome_in_EventCollection_for_Binary_override1

                                                    WriteOne_in_EventCollection_for_Binary1

                                                        FindNextSelected_in_EventWriting_static1
                                                        FindNextSelected_in_EventWriting_static3
                                                    WriteOne_in_EventCollection_for_Binary2
*                                                    **inspect_Binary**
*                                                    *boolean value= 1
*                                                    *Flags flags.value= 129
*                                                    *DNPTime timeDNPTime.value= 6411521
*                                                    *DNPTime timeDNPTime.quality= 25

                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                            **inspect_Binary**
*                                                            *boolean value= 1
*                                                            *Flags flags.value= 129
*                                                            *DNPTime timeDNPTime.value= 6411521
*                                                            *DNPTime timeDNPTime.quality= 25
@@@@                                                            *write_in_UInt16_static = 6421879->0

                                                                WriteTarget_in_Group2Var1_static1

                                                                Write_in_Group2Var1_static1
*                                                                *arg->flags= 129
@@@@                                                            *write_in_UInt8_static = 6421881->129
                                                    WriteOne_in_EventCollection_for_Binary3

                                                    WriteOne_in_EventCollection_for_Binary1
                                            Write_for_Binary_in_EventWriters_static2

                                                PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary1
@@@@                                                *write_in_UInt16_static = 6421877->1
*                                    *(type->value).selectedVariation= 0
*                                    *bBinary.tTypedMeasurement_for_Boolean.value= 1
*                                    *bBinary.tTypedMeasurement_for_Boolean.mMeasurement.flags= 129
                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override2
*                            *uint16_t num_written =1

                                WriteSome_in_EventWriting_static1
*                                *lists->counters.selected= 0
*                            *uint16_t num_written =0
                            }Write_in_EventWriting_static1_

                            NumSelected_in_EventStorage1
*                            *(pEventStorage->state).counters.selected= 0
                        }Load_in_EventBuffer_
*                    }CheckForUnsolicited_in_OContext6_

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

                        {NullUnsolicited_in_APDUBuilders_static1
*                        *uint8_t seq= 1

                            ToByte_in_AppControlField1
                            ToByte_in_AppControlField2
                            *uint8_t ret =240
                            *uint8_t seq =1

                            SetControl_in_APDUWrapper1
@@@@                            *write_uint8=6421870->241

                            SetFunction_in_APDUWrapper1
@@@@                            *write_uint8=6421871->130

                            SetIIN_in_APDUResponse1
@@@@                            *write_uint8=6421872->0
@@@@                            *write_uint8=6421873->0
                        }NullUnsolicited_in_APDUBuilders_static_
*                        **inspect_IINField**
*                        *uint8_t LSB= 0
*                        *uint8_t MSB= 0

*                        Inst_in_StateUnsolicitedConfirmWait_static1

                            StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait1

                                OutstationState_in_OutstationState1

                        {BeginUnsolTx_in_OContext1

                            {CheckForBroadcastConfirmation_in_OContext1
*                            CheckForBroadcastConfirmation_in_OContext2
*                            **inspect_IINField**
*                            *uint8_t LSB= 1
*                            *uint8_t MSB= 0
*                            CheckForBroadcastConfirmation_in_OContext3
*                            **inspect_IINField**
*                            *uint8_t LSB= 1
*                            *uint8_t MSB= 0

                                SetIIN_in_APDUResponse1
@@@@                                *write_uint8=6421872->1
@@@@                                *write_uint8=6421873->0
*                            CheckForBroadcastConfirmation_in_OContext4
*                            **inspect_IINField**
*                            *uint8_t LSB= 1
*                            *uint8_t MSB= 0
*                            CheckForBroadcastConfirmation_in_OContext6

                                ToByte_in_AppControlField1
                                ToByte_in_AppControlField2
                                *uint8_t ret =240
                                *uint8_t seq =1

                                SetControl_in_APDUWrapper1
@@@@                                *write_uint8=6421870->241
                            }CheckForBroadcastConfirmation_in_OContext_
*                        BeginUnsolTx_in_OContext2
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f1
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  28
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  81
*                        BeginUnsolTx_in_OContext3
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f1
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  28
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  81

                            {BeginTx_in_OContext1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f1
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  28
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  81

{BeginTransmit_in_MockLowerLayer1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f1
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  28
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  81
}BeginTransmit_in_MockLowerLayer_
                            }BeginTx_in_OContext_
                        }BeginUnsolTx_in_OContext_
*                    }CheckForUnsolicited_in_OContext4_
                    }CheckForUnsolicited_in_OContext_
                }CheckForTaskStart_in_OContext_
            }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  f1
*        *buffer->buffer_[i]=  82
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  28
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  81
}PopWriteAsHex_in_MockLowerLayer_

{OnTxReady_in_OutstationTestObject1

            {OnTxReady_in_OContext1

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_OutstationState_override1
                    }CheckForUnsolicitedNull_in_OContext_
                }CheckForTaskStart_in_OContext_

            }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
}----------7ShallConfirm3
 REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F1 82 01 00')
temp2= F1 82 01 00 02 01 28 01 00 00 00 81
{+++++++++++7ShallConfirm4

{Transaction_in_OutstationTestObject1
apply_in_7ShallConfirm2

            {Update_Binary_in_IUpdateHandler1

                {update_in_StaticDataMap_for_BinarySpecOver2_1
*                *iter->second.config.eEventConfig.clazz= 2
+                ++++++int16_t nnn = iter->first=0
*                **inspect_Binary**
*                *boolean value= 0
*                *Flags flags.value= 1
*                *DNPTime timeDNPTime.value= 6411521
*                *DNPTime timeDNPTime.quality= 25

                    convert_to_event_class_in_StaticDataMap_static1
*                    *PointClass_uint8_t pc= 2
*                    *PointClass_Class1= 2
*                    *PointClass_Class2= 4
*                    *PointClass_Class3= 8
                update_in_StaticDataMap_for_BinarySpecOver2_2

                    UpdateAny_BinarySpec_in_EventBuffer1

                        Update_BinarySpec_in_EventUpdate_static1

                            Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static1
                }update_in_StaticDataMap_for_BinarySpecOver2__
            }Update_Binary_in_IUpdateHandler_

            {HandleNewEvents_in_OContext1

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_OutstationState_override1
                    }CheckForUnsolicitedNull_in_OContext_
*                CheckForTaskStart_in_OContext3

                    {CheckForUnsolicited_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
*                    CheckForUnsolicited_in_OContext2
*                    CheckForUnsolicited_in_OContext3
*                    {CheckForUnsolicited_in_OContext4
*                    {CheckForUnsolicited_in_OContext5

                        Unselect_in_EventStorage1

                            Foreach_in_List_for_EventRecord1

                                Iterate_in_List_for_EventRecord1
*                                *pList_for_EventRecord->head= 6412672

                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                    *Node_for_EventRecord* start= 6412672

                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                    *Node_for_EventRecord* start= 6412672
*                    }CheckForUnsolicited_in_OContext5_
*                    {CheckForUnsolicited_in_OContext6

                        SelectByClass_in_EventSelection_static1
*                        *uint32_t max= 65535

                            Iterate_in_List_for_EventRecord1
*                            *pList_for_EventRecord->head= 6412672

                                From__in__Iterator_in_List_for_EventRecord_static1
*                                *Node_for_EventRecord* start= 6412672

                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                *Node_for_EventRecord* start= 6412672
                        SelectByClass_in_EventSelection_static2

                            OnSelect_in_EventClassCounters1
                        SelectByClass_in_EventSelection_static2

                            OnSelect_in_EventClassCounters1

                        {Load_in_EventBuffer1

                            {Write_in_EventWriting_static1

                                Iterate_in_List_for_EventRecord1
*                                *pList_for_EventRecord->head= 6412672

                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                    *Node_for_EventRecord* start= 6412672

                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                    *Node_for_EventRecord* start= 6412672

                                WriteSome_in_EventWriting_static1
*                                *lists->counters.selected= 2
                                WriteSome_in_EventWriting_static2
                                WriteSome_in_EventWriting_static3

                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override1

                                        Write_for_Binary_in_ASDUEventWriteHandler_override1
*                                        *EventBinaryVariation_uint8_t variation= 0
@@@@                                        *EventBinaryVariation_Group2Var1

                                            Write_for_Binary_in_EventWriters_static1

                                                BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary1

                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter1

                                                        WriteHeaderWithReserve_in_HeaderWriter1
*                                                        *qc= 40
*                                                        *reserve= 5

                                                        WriteHeader_in_HeaderWriter1
*                                                        *id.group= 2
*                                                        *id.variation= 1
*                                                        *qc= 40
@@@@                                                        *write_in_UInt8_static = 6421874->2
@@@@                                                        *write_in_UInt8_static = 6421875->1
@@@@                                                        *write_in_UInt8_static = 6421876->40

                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_1
                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_2
                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter2

                                                WriteSome_in_EventCollection_for_Binary_override1

                                                    WriteOne_in_EventCollection_for_Binary1

                                                        FindNextSelected_in_EventWriting_static1
                                                        FindNextSelected_in_EventWriting_static3
                                                    WriteOne_in_EventCollection_for_Binary2
*                                                    **inspect_Binary**
*                                                    *boolean value= 1
*                                                    *Flags flags.value= 129
*                                                    *DNPTime timeDNPTime.value= 6411521
*                                                    *DNPTime timeDNPTime.quality= 25

                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                            **inspect_Binary**
*                                                            *boolean value= 1
*                                                            *Flags flags.value= 129
*                                                            *DNPTime timeDNPTime.value= 6411521
*                                                            *DNPTime timeDNPTime.quality= 25
@@@@                                                            *write_in_UInt16_static = 6421879->0

                                                                WriteTarget_in_Group2Var1_static1

                                                                Write_in_Group2Var1_static1
*                                                                *arg->flags= 129
@@@@                                                            *write_in_UInt8_static = 6421881->129
                                                    WriteOne_in_EventCollection_for_Binary3

                                                    WriteOne_in_EventCollection_for_Binary1

                                                        FindNextSelected_in_EventWriting_static1
                                                        FindNextSelected_in_EventWriting_static3
                                                    WriteOne_in_EventCollection_for_Binary2
*                                                    **inspect_Binary**
*                                                    *boolean value= 0
*                                                    *Flags flags.value= 1
*                                                    *DNPTime timeDNPTime.value= 6411521
*                                                    *DNPTime timeDNPTime.quality= 25

                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                            **inspect_Binary**
*                                                            *boolean value= 0
*                                                            *Flags flags.value= 1
*                                                            *DNPTime timeDNPTime.value= 6411521
*                                                            *DNPTime timeDNPTime.quality= 25
@@@@                                                            *write_in_UInt16_static = 6421882->0

                                                                WriteTarget_in_Group2Var1_static1

                                                                Write_in_Group2Var1_static1
*                                                                *arg->flags= 1
@@@@                                                            *write_in_UInt8_static = 6421884->1
                                                    WriteOne_in_EventCollection_for_Binary3

                                                    WriteOne_in_EventCollection_for_Binary1
                                            Write_for_Binary_in_EventWriters_static2

                                                PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary1
@@@@                                                *write_in_UInt16_static = 6421877->2
*                                    *(type->value).selectedVariation= 0
*                                    *bBinary.tTypedMeasurement_for_Boolean.value= 1
*                                    *bBinary.tTypedMeasurement_for_Boolean.mMeasurement.flags= 129
                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override2
*                            *uint16_t num_written =2

                                WriteSome_in_EventWriting_static1
*                                *lists->counters.selected= 0
*                            *uint16_t num_written =0
                            }Write_in_EventWriting_static1_

                            NumSelected_in_EventStorage1
*                            *(pEventStorage->state).counters.selected= 0
                        }Load_in_EventBuffer_
*                    }CheckForUnsolicited_in_OContext6_

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

                        {NullUnsolicited_in_APDUBuilders_static1
*                        *uint8_t seq= 2

                            ToByte_in_AppControlField1
                            ToByte_in_AppControlField2
                            *uint8_t ret =240
                            *uint8_t seq =2

                            SetControl_in_APDUWrapper1
@@@@                            *write_uint8=6421870->242

                            SetFunction_in_APDUWrapper1
@@@@                            *write_uint8=6421871->130

                            SetIIN_in_APDUResponse1
@@@@                            *write_uint8=6421872->0
@@@@                            *write_uint8=6421873->0
                        }NullUnsolicited_in_APDUBuilders_static_
*                        **inspect_IINField**
*                        *uint8_t LSB= 0
*                        *uint8_t MSB= 0

*                        Inst_in_StateUnsolicitedConfirmWait_static1

                            StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait1

                                OutstationState_in_OutstationState1

                        {BeginUnsolTx_in_OContext1

                            {CheckForBroadcastConfirmation_in_OContext1
*                            CheckForBroadcastConfirmation_in_OContext2
*                            **inspect_IINField**
*                            *uint8_t LSB= 1
*                            *uint8_t MSB= 0
*                            CheckForBroadcastConfirmation_in_OContext3
*                            **inspect_IINField**
*                            *uint8_t LSB= 1
*                            *uint8_t MSB= 0

                                SetIIN_in_APDUResponse1
@@@@                                *write_uint8=6421872->1
@@@@                                *write_uint8=6421873->0
*                            CheckForBroadcastConfirmation_in_OContext4
*                            **inspect_IINField**
*                            *uint8_t LSB= 1
*                            *uint8_t MSB= 0
*                            CheckForBroadcastConfirmation_in_OContext6

                                ToByte_in_AppControlField1
                                ToByte_in_AppControlField2
                                *uint8_t ret =240
                                *uint8_t seq =2

                                SetControl_in_APDUWrapper1
@@@@                                *write_uint8=6421870->242
                            }CheckForBroadcastConfirmation_in_OContext_
*                        BeginUnsolTx_in_OContext2
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f2
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  28
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  81
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  1
*                        BeginUnsolTx_in_OContext3
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f2
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  28
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  81
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  1

                            {BeginTx_in_OContext1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f2
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  28
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  81
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  1

{BeginTransmit_in_MockLowerLayer1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f2
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  28
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  81
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  1
}BeginTransmit_in_MockLowerLayer_
                            }BeginTx_in_OContext_
                        }BeginUnsolTx_in_OContext_
*                    }CheckForUnsolicited_in_OContext4_
                    }CheckForUnsolicited_in_OContext_
                }CheckForTaskStart_in_OContext_
            }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  f2
*        *buffer->buffer_[i]=  82
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  28
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  81
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  1
}PopWriteAsHex_in_MockLowerLayer_

{OnTxReady_in_OutstationTestObject1

            {OnTxReady_in_OContext1

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_OutstationState_override1
                    }CheckForUnsolicitedNull_in_OContext_
                }CheckForTaskStart_in_OContext_

            }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
}----------7ShallConfirm4
 REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F2 82 01 00')
temp3= F2 82 01 00 02 01 28 02 00 00 00 81 00 00 01
{+++++++++++7ShallConfirm5

{UnsolConfirm_in_APDUHexBuilders1
*uint8_t seq= 2

            BufferSer4_in_BufferSer4Over2_1
*            *uint16_t length=2048

            ToByte_in_AppControlField1
            ToByte_in_AppControlField2
            *uint8_t ret =208
            *uint8_t seq =2

            SetControl_in_APDUWrapper1
@@@@            *write_uint8=6410924->210

            SetFunction_in_APDUWrapper1
@@@@            *write_uint8=6410925->0
}UnsolConfirm_in_APDUHexBuilders_
unconstr2= D2 00

{SendToOutstation_in_OutstationTestObject1

            {OnReceive_in_OContext1

                {ProcessMessage_in_OContext1
*                *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  d2
*                *buffer->buffer_[i]=  0

                    ParseRequest_in_APDUHeaderParser_static1
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  d2
*                    *buffer->buffer_[i]=  0
                    ParseRequest_in_APDUHeaderParser_static3

                    {ProcessObjects_in_OContext1
*                    *FunctionCode_CONFIRM

                        {ProcessConfirm_in_OContext1

                            {OnConfirm_in_StateUnsolicitedConfirmWait_override1
                            OnConfirm_in_StateUnsolicitedConfirmWait_override2
                            OnConfirm_in_StateUnsolicitedConfirmWait_override3
                            OnConfirm_in_StateUnsolicitedConfirmWait_override4
                            OnConfirm_in_StateUnsolicitedConfirmWait_override5

                                RemoveAll_in_List_for_EventRecord1

                                    Iterate_in_List_for_EventRecord1
*                                    *pList_for_EventRecord->head= 6412672

                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                        *Node_for_EventRecord* start= 6412672

                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                        *Node_for_EventRecord* start= 6412672

*                                Inst_in_StateIdle_static1

                                    StateIdle_in_StateIdle1

                                        OutstationState_in_OutstationState1
                            }OnConfirm_in_StateUnsolicitedConfirmWait_override3_
                        }ProcessConfirm_in_OContext_
                    }ProcessObjects_in_OContext_
                }ProcessMessage_in_OContext_

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_StateIdle_override1
                    }CheckForUnsolicitedNull_in_OContext_
*                CheckForTaskStart_in_OContext3

                    {CheckForUnsolicited_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
*                    CheckForUnsolicited_in_OContext2
*                    CheckForUnsolicited_in_OContext3
                    }CheckForUnsolicited_in_OContext_
                }CheckForTaskStart_in_OContext_
            }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{Transaction_in_OutstationTestObject1
apply_in_7ShallConfirm

            {Update_Binary_in_IUpdateHandler1

                {update_in_StaticDataMap_for_BinarySpecOver2_1
*                *iter->second.config.eEventConfig.clazz= 2
+                ++++++int16_t nnn = iter->first=0
*                **inspect_Binary**
*                *boolean value= 1
*                *Flags flags.value= 129
*                *DNPTime timeDNPTime.value= 6411521
*                *DNPTime timeDNPTime.quality= 68

                    convert_to_event_class_in_StaticDataMap_static1
*                    *PointClass_uint8_t pc= 2
*                    *PointClass_Class1= 2
*                    *PointClass_Class2= 4
*                    *PointClass_Class3= 8
                update_in_StaticDataMap_for_BinarySpecOver2_2

                    UpdateAny_BinarySpec_in_EventBuffer1

                        Update_BinarySpec_in_EventUpdate_static1

                            Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static1
                }update_in_StaticDataMap_for_BinarySpecOver2__
            }Update_Binary_in_IUpdateHandler_

            {HandleNewEvents_in_OContext1

                {CheckForTaskStart_in_OContext1

                    {CheckForDeferredRequest_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
                    }CheckForDeferredRequest_in_OContext_
*                CheckForTaskStart_in_OContext2

                    {CheckForUnsolicitedNull_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_

                        IsIdle_in_OutstationState1

                        IsIdle_in_StateIdle_override1
                    }CheckForUnsolicitedNull_in_OContext_
*                CheckForTaskStart_in_OContext3

                    {CheckForUnsolicited_in_OContext1

                        {CanTransmit_in_OContext1
*                        *pOContext->isOnline && !pOContext->isTransmitting= 1
                        }CanTransmit_in_OContext_
*                    CheckForUnsolicited_in_OContext2
*                    CheckForUnsolicited_in_OContext3
*                    {CheckForUnsolicited_in_OContext4
*                    {CheckForUnsolicited_in_OContext5

                        Unselect_in_EventStorage1

                            Foreach_in_List_for_EventRecord1

                                Iterate_in_List_for_EventRecord1
*                                *pList_for_EventRecord->head= 6412692

                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                    *Node_for_EventRecord* start= 6412692

                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                    *Node_for_EventRecord* start= 6412692
*                    }CheckForUnsolicited_in_OContext5_
*                    {CheckForUnsolicited_in_OContext6

                        SelectByClass_in_EventSelection_static1
*                        *uint32_t max= 65535

                            Iterate_in_List_for_EventRecord1
*                            *pList_for_EventRecord->head= 6412692

                                From__in__Iterator_in_List_for_EventRecord_static1
*                                *Node_for_EventRecord* start= 6412692

                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                *Node_for_EventRecord* start= 6412692
                        SelectByClass_in_EventSelection_static2

                            OnSelect_in_EventClassCounters1

                        {Load_in_EventBuffer1

                            {Write_in_EventWriting_static1

                                Iterate_in_List_for_EventRecord1
*                                *pList_for_EventRecord->head= 6412692

                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                    *Node_for_EventRecord* start= 6412692

                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                    *Node_for_EventRecord* start= 6412692

                                WriteSome_in_EventWriting_static1
*                                *lists->counters.selected= 1
                                WriteSome_in_EventWriting_static2
                                WriteSome_in_EventWriting_static3

                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override1

                                        Write_for_Binary_in_ASDUEventWriteHandler_override1
*                                        *EventBinaryVariation_uint8_t variation= 0
@@@@                                        *EventBinaryVariation_Group2Var1

                                            Write_for_Binary_in_EventWriters_static1

                                                BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary1

                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter1

                                                        WriteHeaderWithReserve_in_HeaderWriter1
*                                                        *qc= 40
*                                                        *reserve= 5

                                                        WriteHeader_in_HeaderWriter1
*                                                        *id.group= 2
*                                                        *id.variation= 1
*                                                        *qc= 40
@@@@                                                        *write_in_UInt8_static = 6421874->2
@@@@                                                        *write_in_UInt8_static = 6421875->1
@@@@                                                        *write_in_UInt8_static = 6421876->40

                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_1
                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_2
                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter2

                                                WriteSome_in_EventCollection_for_Binary_override1

                                                    WriteOne_in_EventCollection_for_Binary1

                                                        FindNextSelected_in_EventWriting_static1
                                                        FindNextSelected_in_EventWriting_static3
                                                    WriteOne_in_EventCollection_for_Binary2
*                                                    **inspect_Binary**
*                                                    *boolean value= 1
*                                                    *Flags flags.value= 129
*                                                    *DNPTime timeDNPTime.value= 6411521
*                                                    *DNPTime timeDNPTime.quality= 68

                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                            **inspect_Binary**
*                                                            *boolean value= 1
*                                                            *Flags flags.value= 129
*                                                            *DNPTime timeDNPTime.value= 6411521
*                                                            *DNPTime timeDNPTime.quality= 68
@@@@                                                            *write_in_UInt16_static = 6421879->0

                                                                WriteTarget_in_Group2Var1_static1

                                                                Write_in_Group2Var1_static1
*                                                                *arg->flags= 129
@@@@                                                            *write_in_UInt8_static = 6421881->129
                                                    WriteOne_in_EventCollection_for_Binary3

                                                    WriteOne_in_EventCollection_for_Binary1
                                            Write_for_Binary_in_EventWriters_static2

                                                PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary1
@@@@                                                *write_in_UInt16_static = 6421877->1
*                                    *(type->value).selectedVariation= 0
*                                    *bBinary.tTypedMeasurement_for_Boolean.value= 1
*                                    *bBinary.tTypedMeasurement_for_Boolean.mMeasurement.flags= 129
                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override2
*                            *uint16_t num_written =1

                                WriteSome_in_EventWriting_static1
*                                *lists->counters.selected= 0
*                            *uint16_t num_written =0
                            }Write_in_EventWriting_static1_

                            NumSelected_in_EventStorage1
*                            *(pEventStorage->state).counters.selected= 0
                        }Load_in_EventBuffer_
*                    }CheckForUnsolicited_in_OContext6_

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

                        {NullUnsolicited_in_APDUBuilders_static1
*                        *uint8_t seq= 3

                            ToByte_in_AppControlField1
                            ToByte_in_AppControlField2
                            *uint8_t ret =240
                            *uint8_t seq =3

                            SetControl_in_APDUWrapper1
@@@@                            *write_uint8=6421870->243

                            SetFunction_in_APDUWrapper1
@@@@                            *write_uint8=6421871->130

                            SetIIN_in_APDUResponse1
@@@@                            *write_uint8=6421872->0
@@@@                            *write_uint8=6421873->0
                        }NullUnsolicited_in_APDUBuilders_static_
*                        **inspect_IINField**
*                        *uint8_t LSB= 0
*                        *uint8_t MSB= 0

*                        Inst_in_StateUnsolicitedConfirmWait_static1

                            StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait1

                                OutstationState_in_OutstationState1

                        {BeginUnsolTx_in_OContext1

                            {CheckForBroadcastConfirmation_in_OContext1
                            }CheckForBroadcastConfirmation_in_OContext_
*                        BeginUnsolTx_in_OContext2
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f3
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  28
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  81
*                        BeginUnsolTx_in_OContext3
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f3
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  2
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  28
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  81

                            {BeginTx_in_OContext1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f3
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  28
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  81

{BeginTransmit_in_MockLowerLayer1
*                            **inspect_RSeq**
*                            *buffer->buffer_[i]=  f3
*                            *buffer->buffer_[i]=  82
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  2
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  28
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  81
}BeginTransmit_in_MockLowerLayer_
                            }BeginTx_in_OContext_
                        }BeginUnsolTx_in_OContext_
*                    }CheckForUnsolicited_in_OContext4_
                    }CheckForUnsolicited_in_OContext_
                }CheckForTaskStart_in_OContext_
            }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  f3
*        *buffer->buffer_[i]=  82
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  2
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  28
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  81
}PopWriteAsHex_in_MockLowerLayer_
}----------7ShallConfirm5
 REQUIRE(t.lower->PopWriteAsHex().substr(0, 11) == 'F3 82 00 00')
temp4= F3 82 00 00 02 01 28 01 00 00 00 81
