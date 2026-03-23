********SUITE('1Freeze')********
{---------1

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6411720
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
*    *config.size()= 1

    StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*    *config.size()= 1

        {FrozenCounter_in_FrozenCounterOver1_1
        }FrozenCounter_in_FrozenCounterOver1__

        {FrozenCounter_in_FrozenCounterOver1_1
        }FrozenCounter_in_FrozenCounterOver1__

        {FrozenCounter_in_FrozenCounterOver1_1
        }FrozenCounter_in_FrozenCounterOver1__

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
{loadFun_in_TestFreezeOperation1

    Modify_in_Database1
**FlagsType_Counter

    {modify_in_StaticDataMap_for_CounterSpec1
*    *uint16_t start= 0
*    *uint16_t stop= 0
*    *uint8_t flags= 1
    *modify_in_StaticDataMap_for_CounterSpec2
*    **inspect_Counter**
*    *boolean value= 0
*    *Flags flags.value= 2
*    *DNPTime timeDNPTime.value= 0
*    *DNPTime timeDNPTime.quality= 0

        {update_in_StaticDataMap_for_CounterSpecOver2_1
*        **inspect_Counter**
*        *boolean value= 0
*        *Flags flags.value= 1
*        *DNPTime timeDNPTime.value= 0
*        *DNPTime timeDNPTime.quality= 0
*
*        *EventMode_uint8_t mode= 0
*        *EventMode_Force= 1
*        *EventMode_EventOnly= 3
        update_in_StaticDataMap_for_CounterSpecOver2_2
*        *inspect_Counter(&old_value)
*        **inspect_Counter**
*        *boolean value= 0
*        *Flags flags.value= 2
*        *DNPTime timeDNPTime.value= 0
*        *DNPTime timeDNPTime.quality= 0
        update_in_StaticDataMap_for_CounterSpecOver2_3
        update_in_StaticDataMap_for_CounterSpecOver2_4

            convert_to_event_class_in_StaticDataMap_static1
*            *PointClass_uint8_t pc= 2
*            *PointClass_Class1= 2
*            *PointClass_Class2= 4
*            *PointClass_Class3= 8
        }update_in_StaticDataMap_for_CounterSpecOver2_2_
    }modify_in_StaticDataMap_for_CounterSpec3_

    Modify_in_Database1
**FlagsType_FrozenCounter

    convert_to_event_class_in_StaticDataMap_static1
*    *PointClass_uint8_t pc= 2
*    *PointClass_Class1= 2
*    *PointClass_Class2= 4
*    *PointClass_Class3= 8
}loadFun_in_TestFreezeOperation_

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

{EmptyResponse_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6410605->129
    }SetFunction_in_APDUWrapper_

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6410604->192
    }SetControl_in_APDUWrapper_

    {SetIIN_in_APDUResponse1
@@@@    *write_uint8=6410606->128
@@@@    *write_uint8=6410607->0
    }SetIIN_in_APDUResponse_
}EmptyResponse_in_APDUHexBuilders_

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c0
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  14
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  14
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext8

                        {ProcessNewRequest_in_OContext1

                            {OnNewNonReadRequest_in_StateIdle_override1

                                {RespondToNonReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421379->129
                                    }SetFunction_in_APDUWrapper_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =0

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421378->192
                                    }SetControl_in_APDUWrapper_

                                    {HandleNonReadResponse_in_OContext1
*                                    *FunctionCode_uint18_t function= 7
@@@@                                    *FunctionCode_IMMED_FREEZE

                                        {HandleFreeze_in_OContext1

                                            IAPDUHandler_in_IAPDUHandler1
*                                            *pIAPDUHandler= 6409516

                                            @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                            {Parse_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  14
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=0
*                                                *IWhiteList* pWhiteList=6409516
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6
*                                                *copy
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  14
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        *buffer->buffer_[i]=  14
*                                                        *buffer->buffer_[i]=  0
*                                                        *buffer->buffer_[i]=  6

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 20
*                                                        *uint8_t variation= 0

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 20
*                                                            *uint8_t variation= 0

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 20
*                                                                *uint8_t variation= 0
*                                                                *GroupVariationType_STATIC
*                                                            *GroupVariation_uint16_t enumeration= 1400

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =6
@@@@                                                        *QualifierCode_ALL_OBJECTS*

                                                            HandleAllObjectsHeader_in_APDUParser_static1
*                                                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                            *record->gGroupVariationRecord.group=20
*                                                            *record->gGroupVariationRecord.variation=0
*                                                            *record->gGroupVariationRecord.enumeration=1400
*                                                            *IAPDUHandler* pHandler=0
                                                        }ParseQualifier_in_APDUParser_static1_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=6409516
*                                                *IWhiteList* pWhiteList=0
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6
*                                                *copy
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  14
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        *buffer->buffer_[i]=  14
*                                                        *buffer->buffer_[i]=  0
*                                                        *buffer->buffer_[i]=  6

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 20
*                                                        *uint8_t variation= 0

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 20
*                                                            *uint8_t variation= 0

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 20
*                                                                *uint8_t variation= 0
*                                                                *GroupVariationType_STATIC
*                                                            *GroupVariation_uint16_t enumeration= 1400

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =6
@@@@                                                        *QualifierCode_ALL_OBJECTS*

                                                            HandleAllObjectsHeader_in_APDUParser_static1
*                                                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                            *record->gGroupVariationRecord.group=20
*                                                            *record->gGroupVariationRecord.variation=0
*                                                            *record->gGroupVariationRecord.enumeration=1400
*                                                            *IAPDUHandler* pHandler=6409516
                                                            HandleAllObjectsHeader_in_APDUParser_static2

                                                                OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                                {ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override1

                                                                    SelectAll_in_Database1
*                                                                    *GroupVariation_Group20Var0

                                                                    {FreezeSelectedCounters_in_Database1

                                                                        {FrozenCounter_in_FrozenCounterOver4_1
                                                                        }FrozenCounter_in_FrozenCounterOver4__
*                                                                    *FreezeSelectedCounters_in_Database2
*                                                                    **inspect_FrozenCounter**
*                                                                    *boolean value= 0
*                                                                    *Flags flags.value= 1
*                                                                    *DNPTime timeDNPTime.value= 0
*                                                                    *DNPTime timeDNPTime.quality= 1
                                                                    }FreezeSelectedCounters_in_Database_
                                                                }ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override_

                                                                Record_in_IAPDUHandler1
                                                        }ParseQualifier_in_APDUParser_static1_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_
                                            }Parse_in_APDUParser_static_
                                        }HandleFreeze_in_OContext_
*                                        ParseResult_uint8_t result= 0
*                                        **inspect_IINField**
*                                        *uint8_t LSB= 0
*                                        *uint8_t MSB= 0
                                    }HandleNonReadResponse_in_OContext_

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
@@@@                                    *write_uint8=6421380->128
@@@@                                    *write_uint8=6421381->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
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
}---------1
REQUIRE(t.lower->PopWriteAsHex() == freezeResponse(0))
request= C0 07 14 00 06
response= C0 81 80 00
temp= C0 81 80 00

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

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{---------2

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c1
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  15
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c1
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  15
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext7
*                    *completely new sequence

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421379->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  15
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6
                                    HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 0

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 0

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 0
                                    HandleRead_in_OContext3
                                    HandleRead_in_OContext4

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6409612

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6409612
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6409612
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=6409612
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                            *GroupVariationType_STATIC

                                                                SelectAll_in_Database1
*                                                                *GroupVariation_Group21Var0

                                                            Record_in_IAPDUHandler1
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    HandleRead_in_OContext5
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
*                                        *map.map.size()= 1
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 1

                                            get_for_FrozenCounterSpec_in_StaticWriters_static1
*                                            *StaticFrozenCounterVariation_Group21Var5

                                            {WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1

                                                {IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1
*                                                *QualifierCode_uint8_t qc= 0
*                                                *uint8_t start= 0

                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                    *qc= 0
*                                                    *reserve= 13

                                                    WriteHeader_in_HeaderWriter1
*                                                    *id.group= 21
*                                                    *id.variation= 5
*                                                    *qc= 0
@@@@                                                    *write_in_UInt8_static = 6421382->21
@@@@                                                    *write_in_UInt8_static = 6421383->5
@@@@                                                    *write_in_UInt8_static = 6421384->0

                                                    {RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2_1
@@@@                                                    *write_in_UInt8_static = 6421385->0
                                                    }RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2__
                                                }IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1_

                                                {LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters1
*                                                *StaticFrozenCounterVariation_uint8_t variation= 2

                                                    {Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1
*                                                    **inspect_FrozenCounter**
*                                                    *boolean value= 0
*                                                    *Flags flags.value= 1
*                                                    *DNPTime timeDNPTime.value= 0
*                                                    *DNPTime timeDNPTime.quality= 1

                                                        Write_in_Group21Var5_static
*                                                        *arg->flags= 1
*                                                        *arg->value= 0
*                                                        *(arg->timeDNPTime).value= 0
@@@@                                                    *write_in_UInt8_static = 6421387->1
@@@@                                                    *write_in_UInt32_static = 6421388->0
@@@@                                                    *write_in_UInt48_static = 6421392->0
                                                    }Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1_
                                                }LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters4_

                                                RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter1
@@@@                                            *write_in_UInt8_static = 6421386->0
                                            }WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1_
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 0
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =1

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421378->193
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
@@@@                                    *write_uint8=6421380->128
@@@@                                    *write_uint8=6421381->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c1
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c1
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
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
                    }OnReceiveSolRequest_in_OContext4_
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
}---------2
request2= C1 01 15 00 06
REQUIRE(t.lower->PopWriteAsHex()== 'C1 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00'
temp2= C1 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00

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

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{---------3

{Transaction_in_OutstationTestObject1

    {Update_for_Counter_in_Database1
*    *EventMode_uint8_t mode= 0
*    **inspect_Counter**
*    *boolean value= 41
*    *Flags flags.value= 1
*    *DNPTime timeDNPTime.value= 0
*    *DNPTime timeDNPTime.quality= 0

        {update_in_StaticDataMap_for_CounterSpecOver2_1
*        **inspect_Counter**
*        *boolean value= 41
*        *Flags flags.value= 1
*        *DNPTime timeDNPTime.value= 0
*        *DNPTime timeDNPTime.quality= 0
*
*        *EventMode_uint8_t mode= 0
*        *EventMode_Force= 1
*        *EventMode_EventOnly= 3
        update_in_StaticDataMap_for_CounterSpecOver2_2
*        *inspect_Counter(&old_value)
*        **inspect_Counter**
*        *boolean value= 0
*        *Flags flags.value= 1
*        *DNPTime timeDNPTime.value= 0
*        *DNPTime timeDNPTime.quality= 0
        update_in_StaticDataMap_for_CounterSpecOver2_3
        update_in_StaticDataMap_for_CounterSpecOver2_4

            convert_to_event_class_in_StaticDataMap_static1
*            *PointClass_uint8_t pc= 2
*            *PointClass_Class1= 2
*            *PointClass_Class2= 4
*            *PointClass_Class3= 8
        }update_in_StaticDataMap_for_CounterSpecOver2_2_
    }Update_for_Counter_in_Database_

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
*        *buffer->buffer_[i]=  c2
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  15
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c2
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  15
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext7
*                    *completely new sequence

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421379->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  15
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6
                                    HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 0

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 0

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 0
                                    HandleRead_in_OContext3
                                    HandleRead_in_OContext4

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6409612

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6409612
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6409612
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=6409612
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                            *GroupVariationType_STATIC

                                                                SelectAll_in_Database1
*                                                                *GroupVariation_Group21Var0

                                                            Record_in_IAPDUHandler1
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    HandleRead_in_OContext5
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
*                                        *map.map.size()= 1
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 1

                                            get_for_FrozenCounterSpec_in_StaticWriters_static1
*                                            *StaticFrozenCounterVariation_Group21Var5

                                            {WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1

                                                {IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1
*                                                *QualifierCode_uint8_t qc= 0
*                                                *uint8_t start= 0

                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                    *qc= 0
*                                                    *reserve= 13

                                                    WriteHeader_in_HeaderWriter1
*                                                    *id.group= 21
*                                                    *id.variation= 5
*                                                    *qc= 0
@@@@                                                    *write_in_UInt8_static = 6421382->21
@@@@                                                    *write_in_UInt8_static = 6421383->5
@@@@                                                    *write_in_UInt8_static = 6421384->0

                                                    {RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2_1
@@@@                                                    *write_in_UInt8_static = 6421385->0
                                                    }RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2__
                                                }IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1_

                                                {LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters1
*                                                *StaticFrozenCounterVariation_uint8_t variation= 2

                                                    {Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1
*                                                    **inspect_FrozenCounter**
*                                                    *boolean value= 0
*                                                    *Flags flags.value= 1
*                                                    *DNPTime timeDNPTime.value= 0
*                                                    *DNPTime timeDNPTime.quality= 1

                                                        Write_in_Group21Var5_static
*                                                        *arg->flags= 1
*                                                        *arg->value= 0
*                                                        *(arg->timeDNPTime).value= 0
@@@@                                                    *write_in_UInt8_static = 6421387->1
@@@@                                                    *write_in_UInt32_static = 6421388->0
@@@@                                                    *write_in_UInt48_static = 6421392->0
                                                    }Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1_
                                                }LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters4_

                                                RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter1
@@@@                                            *write_in_UInt8_static = 6421386->0
                                            }WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1_
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 0
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =2

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421378->194
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
@@@@                                    *write_uint8=6421380->128
@@@@                                    *write_uint8=6421381->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c2
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c2
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
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
                    }OnReceiveSolRequest_in_OContext4_
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
}---------3
request3= C2 01 15 00 06
REQUIRE(t.lower->PopWriteAsHex()== 'C2 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00'
temp3= C2 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00

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

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{---------4

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c3
*        *buffer->buffer_[i]=  7
*        *buffer->buffer_[i]=  14
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c3
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  14
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext7
*                    *completely new sequence

                        {ProcessNewRequest_in_OContext1

                            {OnNewNonReadRequest_in_StateIdle_override1

                                {RespondToNonReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421379->129
                                    }SetFunction_in_APDUWrapper_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =3

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421378->195
                                    }SetControl_in_APDUWrapper_

                                    {HandleNonReadResponse_in_OContext1
*                                    *FunctionCode_uint18_t function= 7
@@@@                                    *FunctionCode_IMMED_FREEZE

                                        {HandleFreeze_in_OContext1

                                            IAPDUHandler_in_IAPDUHandler1
*                                            *pIAPDUHandler= 6409516

                                            @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                            {Parse_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  14
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=0
*                                                *IWhiteList* pWhiteList=6409516
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6
*                                                *copy
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  14
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        *buffer->buffer_[i]=  14
*                                                        *buffer->buffer_[i]=  0
*                                                        *buffer->buffer_[i]=  6

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 20
*                                                        *uint8_t variation= 0

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 20
*                                                            *uint8_t variation= 0

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 20
*                                                                *uint8_t variation= 0
*                                                                *GroupVariationType_STATIC
*                                                            *GroupVariation_uint16_t enumeration= 1400

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =6
@@@@                                                        *QualifierCode_ALL_OBJECTS*

                                                            HandleAllObjectsHeader_in_APDUParser_static1
*                                                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                            *record->gGroupVariationRecord.group=20
*                                                            *record->gGroupVariationRecord.variation=0
*                                                            *record->gGroupVariationRecord.enumeration=1400
*                                                            *IAPDUHandler* pHandler=0
                                                        }ParseQualifier_in_APDUParser_static1_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=6409516
*                                                *IWhiteList* pWhiteList=0
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6
*                                                *copy
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  14
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                    {ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  14
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        *buffer->buffer_[i]=  14
*                                                        *buffer->buffer_[i]=  0
*                                                        *buffer->buffer_[i]=  6

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 20
*                                                        *uint8_t variation= 0

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 20
*                                                            *uint8_t variation= 0

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 20
*                                                                *uint8_t variation= 0
*                                                                *GroupVariationType_STATIC
*                                                            *GroupVariation_uint16_t enumeration= 1400

                                                        @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                        {ParseQualifier_in_APDUParser_static1
*                                                        *QualifierCode_uint8_t tmp =6
@@@@                                                        *QualifierCode_ALL_OBJECTS*

                                                            HandleAllObjectsHeader_in_APDUParser_static1
*                                                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                            *record->gGroupVariationRecord.group=20
*                                                            *record->gGroupVariationRecord.variation=0
*                                                            *record->gGroupVariationRecord.enumeration=1400
*                                                            *IAPDUHandler* pHandler=6409516
                                                            HandleAllObjectsHeader_in_APDUParser_static2

                                                                OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                                {ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override1

                                                                    SelectAll_in_Database1
*                                                                    *GroupVariation_Group20Var0

                                                                    {FreezeSelectedCounters_in_Database1

                                                                        {FrozenCounter_in_FrozenCounterOver4_1
                                                                        }FrozenCounter_in_FrozenCounterOver4__
*                                                                    *FreezeSelectedCounters_in_Database2
*                                                                    **inspect_FrozenCounter**
*                                                                    *boolean value= 41
*                                                                    *Flags flags.value= 1
*                                                                    *DNPTime timeDNPTime.value= 89631424
*                                                                    *DNPTime timeDNPTime.quality= 1

                                                                        convert_to_event_class_in_StaticDataMap_static1
*                                                                        *PointClass_uint8_t pc= 2
*                                                                        *PointClass_Class1= 2
*                                                                        *PointClass_Class2= 4
*                                                                        *PointClass_Class3= 8
                                                                    }FreezeSelectedCounters_in_Database_
                                                                }ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override_

                                                                Record_in_IAPDUHandler1
                                                        }ParseQualifier_in_APDUParser_static1_
*                                                        *ParseResult_uint8_t tmp= 0
                                                    }ParseHeader_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseSinglePass_in_APDUParser_static2_
                                            }Parse_in_APDUParser_static_
                                        }HandleFreeze_in_OContext_
*                                        ParseResult_uint8_t result= 0
*                                        **inspect_IINField**
*                                        *uint8_t LSB= 0
*                                        *uint8_t MSB= 0
                                    }HandleNonReadResponse_in_OContext_

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
@@@@                                    *write_uint8=6421380->128
@@@@                                    *write_uint8=6421381->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c3
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c3
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
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
                    }OnReceiveSolRequest_in_OContext4_
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

{EmptyResponse_in_APDUHexBuilders1
*uint8_t seq= 3

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6410605->129
    }SetFunction_in_APDUWrapper_

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =3

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6410604->195
    }SetControl_in_APDUWrapper_

    {SetIIN_in_APDUResponse1
@@@@    *write_uint8=6410606->128
@@@@    *write_uint8=6410607->0
    }SetIIN_in_APDUResponse_
}EmptyResponse_in_APDUHexBuilders_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}---------4
request4= C3 07 14 00 06
response4= C3 81 80 00
temp4= C3 81 80 00

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

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{---------5

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c4
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  15
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c4
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  15
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext7
*                    *completely new sequence

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421379->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  15
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6
                                    HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 0

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 0

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 0
                                    HandleRead_in_OContext3
                                    HandleRead_in_OContext4

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6409612

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6409612
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6409612
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=6409612
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                            *GroupVariationType_STATIC

                                                                SelectAll_in_Database1
*                                                                *GroupVariation_Group21Var0

                                                            Record_in_IAPDUHandler1
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    HandleRead_in_OContext5
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
*                                        *map.map.size()= 1
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 1

                                            get_for_FrozenCounterSpec_in_StaticWriters_static1
*                                            *StaticFrozenCounterVariation_Group21Var5

                                            {WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1

                                                {IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1
*                                                *QualifierCode_uint8_t qc= 0
*                                                *uint8_t start= 0

                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                    *qc= 0
*                                                    *reserve= 13

                                                    WriteHeader_in_HeaderWriter1
*                                                    *id.group= 21
*                                                    *id.variation= 5
*                                                    *qc= 0
@@@@                                                    *write_in_UInt8_static = 6421382->21
@@@@                                                    *write_in_UInt8_static = 6421383->5
@@@@                                                    *write_in_UInt8_static = 6421384->0

                                                    {RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2_1
@@@@                                                    *write_in_UInt8_static = 6421385->0
                                                    }RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2__
                                                }IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1_

                                                {LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters1
*                                                *StaticFrozenCounterVariation_uint8_t variation= 2

                                                    {Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1
*                                                    **inspect_FrozenCounter**
*                                                    *boolean value= 41
*                                                    *Flags flags.value= 1
*                                                    *DNPTime timeDNPTime.value= 89631424
*                                                    *DNPTime timeDNPTime.quality= 1

                                                        Write_in_Group21Var5_static
*                                                        *arg->flags= 1
*                                                        *arg->value= 41
*                                                        *(arg->timeDNPTime).value= 89631424
@@@@                                                    *write_in_UInt8_static = 6421387->1
@@@@                                                    *write_in_UInt32_static = 6421388->41
@@@@                                                    *write_in_UInt48_static = 6421392->240607800000
                                                    }Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1_
                                                }LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters4_

                                                RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter1
@@@@                                            *write_in_UInt8_static = 6421386->0
                                            }WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1_
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 0
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =4

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421378->196
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
@@@@                                    *write_uint8=6421380->128
@@@@                                    *write_uint8=6421381->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c4
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  29
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  aa
*                                        *buffer->buffer_[i]=  57
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  38
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c4
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  29
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  aa
*                                        *buffer->buffer_[i]=  57
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  38
*                                        *buffer->buffer_[i]=  0
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
                    }OnReceiveSolRequest_in_OContext4_
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
}---------5
request5= C4 01 15 00 06
REQUIRE(t.lower->PopWriteAsHex()== 'C4 81 80 00 15 05 00 00 00 01 29 00 00 00 C0 AA 57 05 38 00'
temp5= C4 81 80 00 15 05 00 00 00 01 29 00 00 00 C0 AA 57 05 38 00

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

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{---------6

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        *buffer->buffer_[i]=  c5
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  15
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c5
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  15
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext7
*                    *completely new sequence

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421379->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  15
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6
                                    HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 0

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 0

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 0
                                    HandleRead_in_OContext3
                                    HandleRead_in_OContext4

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6409612

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6409612
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6409612
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  15
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  15
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  15
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 21
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 21
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 21
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1500

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=21
*                                                        *record->gGroupVariationRecord.variation=0
*                                                        *record->gGroupVariationRecord.enumeration=1500
*                                                        *IAPDUHandler* pHandler=6409612
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                            *GroupVariationType_STATIC

                                                                SelectAll_in_Database1
*                                                                *GroupVariation_Group21Var0

                                                            Record_in_IAPDUHandler1
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    HandleRead_in_OContext5
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
*                                        *map.map.size()= 1
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 1

                                            get_for_FrozenCounterSpec_in_StaticWriters_static1
*                                            *StaticFrozenCounterVariation_Group21Var5

                                            {WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1

                                                {IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1
*                                                *QualifierCode_uint8_t qc= 0
*                                                *uint8_t start= 0

                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                    *qc= 0
*                                                    *reserve= 13

                                                    WriteHeader_in_HeaderWriter1
*                                                    *id.group= 21
*                                                    *id.variation= 5
*                                                    *qc= 0
@@@@                                                    *write_in_UInt8_static = 6421382->21
@@@@                                                    *write_in_UInt8_static = 6421383->5
@@@@                                                    *write_in_UInt8_static = 6421384->0

                                                    {RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2_1
@@@@                                                    *write_in_UInt8_static = 6421385->0
                                                    }RangeWriteIterator_for_UInt8_FrozenCounter_in_RangeWriteIterator_for_UInt8_FrozenCounterOver2__
                                                }IterateOverRange_for_UInt8_FrozenCounter_in_HeaderWriter1_

                                                {LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters1
*                                                *StaticFrozenCounterVariation_uint8_t variation= 2

                                                    {Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1
*                                                    **inspect_FrozenCounter**
*                                                    *boolean value= 41
*                                                    *Flags flags.value= 1
*                                                    *DNPTime timeDNPTime.value= 89631424
*                                                    *DNPTime timeDNPTime.quality= 1

                                                        Write_in_Group21Var5_static
*                                                        *arg->flags= 1
*                                                        *arg->value= 41
*                                                        *(arg->timeDNPTime).value= 89631424
@@@@                                                    *write_in_UInt8_static = 6421387->1
@@@@                                                    *write_in_UInt32_static = 6421388->41
@@@@                                                    *write_in_UInt48_static = 6421392->240607800000
                                                    }Write_in_RangeWriteIterator_for_UInt8_FrozenCounter1_
                                                }LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters4_

                                                RangeWriteIterator_for_UInt8_FrozenCounter_destr_RangeWriteIterator_for_UInt8_FrozenCounter1
@@@@                                            *write_in_UInt8_static = 6421386->0
                                            }WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static1_
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 0
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 0
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =192
                                    *uint8_t seq =5

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421378->197
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
@@@@                                    *write_uint8=6421380->128
@@@@                                    *write_uint8=6421381->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c5
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  29
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  aa
*                                        *buffer->buffer_[i]=  57
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  38
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c5
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  15
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  29
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  aa
*                                        *buffer->buffer_[i]=  57
*                                        *buffer->buffer_[i]=  5
*                                        *buffer->buffer_[i]=  38
*                                        *buffer->buffer_[i]=  0
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
                    }OnReceiveSolRequest_in_OContext4_
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
}---------6
request6= C5 01 15 00 06
REQUIRE(t.lower->PopWriteAsHex()== 'C5 81 80 00 14 01 00 00 00 01 + expectedCounterValue + 00 00 00'
expectedCounterValue= 29
temp6= C5 81 80 00 15 05 00 00 00 01 29 00 00 00 C0 AA 57 05 38 00

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

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
