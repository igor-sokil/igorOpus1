********SUITE('TestOutstationStateMachine_1Responds')********

{OutstationTestObject_in_OutstationTestObject1

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
*        *buffer->buffer_[i]=  1
*        *buffer->buffer_[i]=  1e
*        *buffer->buffer_[i]=  0
*        *buffer->buffer_[i]=  6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  1e
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
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

                                    SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6421539->129

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    *buffer->buffer_[i]=  1e
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
*                                        *pIAPDUHandler= 6410044

                                        Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  1e
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6410044
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  1e
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  1e
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  1e
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  1e
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  6
                                                ParseHeader_in_APDUParser_static2

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 30
*                                                    *uint8_t variation= 0

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 30
*                                                        *uint8_t variation= 0

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 30
*                                                            *uint8_t variation= 0
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 1e00
                                                ParseHeader_in_APDUParser_static3
                                                ParseHeader_in_APDUParser_static4

                                                ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =6
@@@@                                                *QualifierCode_ALL_OBJECTS*

                                                HandleAllObjectsHeader_in_APDUParser_static1
*                                                ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                *record->gGroupVariationRecord.group=30
*                                                *record->gGroupVariationRecord.variation=0
*                                                *record->gGroupVariationRecord.enumeration=1e00
*                                                *IAPDUHandler* pHandler=0
                                        Parse_in_APDUParser_static2

                                        ParseSinglePass_in_APDUParser_static1
*                                        *IAPDUHandler* pHandler=6410044
*                                        *IWhiteList* pWhiteList=0
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  1e
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6
*                                        *copy
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  1e
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            ParseHeader_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  1e
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  1e
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6
                                            ParseHeader_in_APDUParser_static2

                                                GetRecord_in_GroupVariationRecord_static1
*                                                *uint8_t group= 30
*                                                *uint8_t variation= 0

                                                    GetEnumAndType_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 30
*                                                    *uint8_t variation= 0

                                                        GetType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 30
*                                                        *uint8_t variation= 0
*                                                        *GroupVariationType_STATIC
*                                                    *GroupVariation_uint16_t enumeration= 1e00
                                            ParseHeader_in_APDUParser_static3
                                            ParseHeader_in_APDUParser_static4

                                            ParseQualifier_in_APDUParser_static1
*                                            *QualifierCode_uint8_t tmp =6
@@@@                                            *QualifierCode_ALL_OBJECTS*

                                            HandleAllObjectsHeader_in_APDUParser_static1
*                                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                            *record->gGroupVariationRecord.group=30
*                                            *record->gGroupVariationRecord.variation=0
*                                            *record->gGroupVariationRecord.enumeration=1e00
*                                            *IAPDUHandler* pHandler=6410044
                                            HandleAllObjectsHeader_in_APDUParser_static2

                                                OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                *GroupVariationType_STATIC

                                                    SelectAll_in_Database1
*                                                    *GroupVariation_Group30Var0

                                                Record_in_IAPDUHandler1
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
*                                        *map.size()= 1
*                                        *StaticAnalogVariation_uint8_t variation= 0

                                            get_for_AnalogSpec_in_StaticWriters_static1
*                                            *StaticAnalogVariation_uint8_t variation= 0
*                                            *StaticAnalogVariation_Group30Var1

                                            WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static1
*                                            *range.start= 0
*                                            *range.stop= 0

                                            DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog1
*                                            *id.group= 30
*                                            *id.variation= 1
*                                            *uint16_t size= 5

                                            IterateOverRange_for_UInt8_Analog_in_HeaderWriter1

                                                ID_in_DNP3Serializer_for_Analog1
*                                                *id.group= 30
*                                                *id.variation= 1

                                                WriteHeaderWithReserve_in_HeaderWriter1
*                                                *qc= 0
*                                                *reserve= 7

                                                WriteHeader_in_HeaderWriter1
*                                                *id.group= 30
*                                                *id.variation= 1
*                                                *qc= 0
@@@@                                                *write_in_UInt8_static = 6421542->30
@@@@                                                *write_in_UInt8_static = 6421543->1
@@@@                                                *write_in_UInt8_static = 6421544->0

                                                RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1
@@@@                                            *write_in_UInt8_static = 6421545->0

                                            LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1
*                                            *map.size()= 1
*                                            *for_in_8

                                            Write_in_RangeWriteIterator_for_UInt8_Analog1

                                            Apply_in_ConvertGroup30Var1_static1
*                                            *src.value= 0
*                                            *target.value= 0

                                            Write_in_Group30Var1_static
*                                            *arg->flags= 2
*                                            *arg->value= 0
@@@@                                        *write_in_UInt8_static = 6421547->2
@@@@                                        *write_in_UInt32_static = 6421548->0

                                            RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1
@@@@                                        *write_in_UInt8_static = 6421546->0
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
                                    }HandleRead_in_OContext_

                                    ToByte_in_AppControlField1
                                    ToByte_in_AppControlField2
                                    *uint8_t ret =192
                                    *uint8_t seq =0

                                    SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6421538->192

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

                                    SetIIN_in_APDUResponse1
@@@@                                    *write_uint8=6421540->128
@@@@                                    *write_uint8=6421541->0

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1e
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  2
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  c0
*                                        *buffer->buffer_[i]=  81
*                                        *buffer->buffer_[i]=  80
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  1e
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  2
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                                        }BeginTx_in_OContext_

*                                        Inst_in_StateIdle_static1

                                            StateIdle_in_StateIdle1

                                                OutstationState_in_OutstationState1
                                    }BeginResponseTx_in_OContext_
                                }RespondToReadRequest_in_OContext_
                            }OnNewReadRequest_in_StateIdle_override_
                        }ProcessNewRequest_in_OContext1_
                    }OnReceiveSolRequest_in_OContext_
                }ProcessRequest_in_OContext_
            }ProcessObjects_in_OContext_
        }ProcessMessage_in_OContext6_

        {CheckForTaskStart_in_OContext1

            {CheckForDeferredRequest_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForDeferredRequest_in_OContext_
*        CheckForTaskStart_in_OContext2

            {CheckForUnsolicitedNull_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 1E 01 00 00 00 02 00 00 00 00')
temp= C0 81 80 00 1E 01 00 00 00 02 00 00 00 00

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

                IsIdle_in_StateIdle_override1
            }CheckForUnsolicitedNull_in_OContext_
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline && !pOContext->isTransmitting= 1
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{Transaction_in_OutstationTestObject1
update_in_1Responds

    update_in_StaticDataMap_for_AnalogSpecOver2_1
*    *inspect_Analog(new_value)
*    **inspect_Analog**
*    *boolean value= 1
*    *Flags flags.value= 1
*    *DNPTime timeDNPTime.value= 6411777
*    *DNPTime timeDNPTime.quality= 120
*
*    *EventMode_uint8_t mode= 0
*    *EventMode_Force= 1
*    *EventMode_EventOnly= 3
    update_in_StaticDataMap_for_AnalogSpecOver2_2
*    *inspect_Analog(&old_value)
*    **inspect_Analog**
*    *boolean value= 0
*    *Flags flags.value= 2
*    *DNPTime timeDNPTime.value= 6411176
*    *DNPTime timeDNPTime.quality= 1

        convert_to_event_class_in_StaticDataMap_static1
*        *PointClass_uint8_t pc= 2
*        *PointClass_Class1= 2
*        *PointClass_Class2= 4
*        *PointClass_Class3= 8

        Update_AnalogSpec_in_EventUpdate_static1

        {HandleNewEvents_in_OContext1

            {CheckForTaskStart_in_OContext1

                {CheckForDeferredRequest_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_

                    IsIdle_in_OutstationState1

                    IsIdle_in_StateIdle_override1
                }CheckForUnsolicitedNull_in_OContext_
*            CheckForTaskStart_in_OContext3

                {CheckForUnsolicited_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_
                }CheckForUnsolicited_in_OContext_
            }CheckForTaskStart_in_OContext_
        }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

        {OnReceive_in_OContext1

            {ProcessMessage_in_OContext1
*            *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  1e
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6

                {ParseRequest_in_APDUHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  c0
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  1e
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  6
                }ParseRequest_in_APDUHeaderParser_static2_

                {ProcessObjects_in_OContext1

                    {ProcessRequest_in_OContext1

                        {OnReceiveSolRequest_in_OContext1
*                        *analyze this request to see how it compares to the last request
                        OnReceiveSolRequest_in_OContext2
                        OnReceiveSolRequest_in_OContext3

                            ToByte_in_AppControlField1
                            ToByte_in_AppControlField2
                            *uint8_t ret =192
                            *uint8_t seq =0

                            ToByte_in_AppControlField1
                            ToByte_in_AppControlField2
                            *uint8_t ret =192
                            *uint8_t seq =0
                        OnReceiveSolRequest_in_OContext4

                            {BeginRetransmitLastResponse_in_OContext1

                                {BeginTx_in_OContext1
*                                **inspect_RSeq**
*                                *buffer->buffer_[i]=  c0
*                                *buffer->buffer_[i]=  81
*                                *buffer->buffer_[i]=  80
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  1e
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  2
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                **inspect_RSeq**
*                                *buffer->buffer_[i]=  c0
*                                *buffer->buffer_[i]=  81
*                                *buffer->buffer_[i]=  80
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  1e
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  2
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                                }BeginTx_in_OContext_
                            }BeginRetransmitLastResponse_in_OContext_
                        }OnReceiveSolRequest_in_OContext_
                    }ProcessRequest_in_OContext_
                }ProcessObjects_in_OContext_
            }ProcessMessage_in_OContext6_

            {CheckForTaskStart_in_OContext1

                {CheckForDeferredRequest_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 0
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 0
                    }CanTransmit_in_OContext_
                }CheckForUnsolicitedNull_in_OContext_
*            CheckForTaskStart_in_OContext3

                {CheckForUnsolicited_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 0
                    }CanTransmit_in_OContext_
                }CheckForUnsolicited_in_OContext_
            }CheckForTaskStart_in_OContext_
        }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 1E 01 00 00 00 02 00 00 00 00')
temp2= C0 81 80 00 1E 01 00 00 00 02 00 00 00 00
