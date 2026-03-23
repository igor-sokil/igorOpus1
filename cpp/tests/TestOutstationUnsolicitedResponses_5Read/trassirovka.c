********SUITE('2Non-read during null unsol without workaround')********
{------------1

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6411896
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
@@@@                    *write_uint8=6421886->240
                    }SetControl_in_APDUWrapper_

                    {SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=6421887->130
                    }SetFunction_in_APDUWrapper_

                    {SetIIN_in_APDUResponse1
@@@@                    *write_uint8=6421888->128
@@@@                    *write_uint8=6421889->0
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
                *pOContext= 6412536
                *&(pOContext->confirmTimer)= 6421076

                    {cancel_in_TimerExe4cpp1
                    *TimerExe4cpp *pTimerExe4cpp= 6421076
                    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6421256
                    }cancel_in_TimerExe4cpp1_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6411896

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6411896

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762681328
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6411896
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
                    }RestartUnsolConfirmTimer_in_OContext_

                    {Inst_in_StateNullUnsolicitedConfirmWait_static1

                        {StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait1

                            OutstationState_in_OutstationState1
                        }StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait_
                    }Inst_in_StateNullUnsolicitedConfirmWait_static_

                    {BeginUnsolTx_in_OContext1

                        {CheckForBroadcastConfirmation_in_OContext1
                        }CheckForBroadcastConfirmation_in_OContext_
*                    BeginUnsolTx_in_OContext2
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  f0
*                    *buffer->buffer_[i]=  82
*                    *buffer->buffer_[i]=  80
*                    *buffer->buffer_[i]=  0
*                    BeginUnsolTx_in_OContext3
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  f0
*                    *buffer->buffer_[i]=  82
*                    *buffer->buffer_[i]=  80
*                    *buffer->buffer_[i]=  0

                        {BeginTx_in_OContext1
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f0
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  80
*                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f0
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  80
*                        *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                        }BeginTx_in_OContext_
                    }BeginUnsolTx_in_OContext_
                }CheckForUnsolicitedNull_in_OContext_
*            CheckForTaskStart_in_OContext3

                {CheckForUnsolicited_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 0
                    }CanTransmit_in_OContext_
                }CheckForUnsolicited_in_OContext_
            }CheckForTaskStart_in_OContext_
        }OnLowerLayerUp_in_OContext_
}LowerLayerUp_in_OutstationTestObject_

{NullUnsolicited_in_APDUHexBuilders1
*uint8_t seq= 0

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048

        {NullUnsolicited_in_APDUBuilders_static1
*        *uint8_t seq= 0

            {ToByte_in_AppControlField1
*            *ret |= AppControlField_FIR_MASK
*            *ret |= AppControlField_FIN_MASK
*            *ret |= AppControlField_CON_MASK
*            *ret |= AppControlField_UNS_MASK
            }ToByte_in_AppControlField_
            *uint8_t ret =240
            *uint8_t seq =0

            {SetControl_in_APDUWrapper1
@@@@            *write_uint8=6411036->240
            }SetControl_in_APDUWrapper_

            {SetFunction_in_APDUWrapper1
@@@@            *write_uint8=6411037->130
            }SetFunction_in_APDUWrapper_

            {SetIIN_in_APDUResponse1
@@@@            *write_uint8=6411038->128
@@@@            *write_uint8=6411039->0
            }SetIIN_in_APDUResponse_
        }NullUnsolicited_in_APDUBuilders_static_
*        **inspect_IINField**
*        *uint8_t LSB= 128
*        *uint8_t MSB= 0
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
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_

                    IsIdle_in_OutstationState1

                    IsIdle_in_OutstationState_override1
                }CheckForUnsolicitedNull_in_OContext_
*            CheckForTaskStart_in_OContext3

                {CheckForUnsolicited_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_
*                CheckForUnsolicited_in_OContext2
                }CheckForUnsolicited_in_OContext_
            }CheckForTaskStart_in_OContext_

        }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
REQUIRE(t.lower->NumWrites() == 0)
num= 0
{------------2

{ClassPoll_in_APDUHexBuilders1
*uint8_t seq= 0
*PointClass_uint8_t pc= 2

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048

        {ToByte_in_AppControlField1
*        *ret |= AppControlField_FIR_MASK
*        *ret |= AppControlField_FIN_MASK
        }ToByte_in_AppControlField_
        *uint8_t ret =192
        *uint8_t seq =0

        {SetControl_in_APDUWrapper1
@@@@        *write_uint8=6410972->192
        }SetControl_in_APDUWrapper_

        {SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6410973->1
        }SetFunction_in_APDUWrapper_

        WriteClassHeaders_in_APDUBuilders_static1

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 2
*            *qc= 6
@@@@            *write_in_UInt8_static = 6410974->60
@@@@            *write_in_UInt8_static = 6410975->2
@@@@            *write_in_UInt8_static = 6410976->6
}ClassPoll_in_APDUHexBuilders_
clrStr= C0 01 3C 02 06

{SendToOutstation_in_OutstationTestObject1

        {OnReceive_in_OContext1

            {ProcessMessage_in_OContext1
*            *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*            **inspect_RSeq**
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  3c
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  6

                {ParseRequest_in_APDUHeaderParser_static1
*                **inspect_RSeq**
*                *buffer->buffer_[i]=  c0
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  3c
*                *buffer->buffer_[i]=  2
*                *buffer->buffer_[i]=  6
                }ParseRequest_in_APDUHeaderParser_static2_

                {ProcessObjects_in_OContext1

                    {ProcessRequest_in_OContext1

                        {OnReceiveSolRequest_in_OContext1
*                        *analyze this request to see how it compares to the last request
                        OnReceiveSolRequest_in_OContext8

                            {ProcessNewRequest_in_OContext1
@@@@                            *FunctionCode_READ

                                {OnNewReadRequest_in_StateNullUnsolicitedConfirmWait_override1
                                *(OContext*)ctx= 6412536

                                    {cancel_in_TimerExe4cpp1
                                    *TimerExe4cpp *pTimerExe4cpp= 6421076
                                    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6411896

                                        {cancel_in_ITimer1
                                        *pITimer->psource_in_ITimer= 6411896

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6411896
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                        }cancel_in_ITimer1
                                    }cancel_in_TimerExe4cpp2_

                                    {RespondToReadRequest_in_OContext1

                                        {SetFunction_in_APDUWrapper1
@@@@                                        *write_uint8=6421555->129
                                        }SetFunction_in_APDUWrapper_

                                        {HandleRead_in_OContext1
*                                        **inspect_RSeq**
*                                        *buffer->buffer_[i]=  3c
*                                        *buffer->buffer_[i]=  2
*                                        *buffer->buffer_[i]=  6
                                        HandleRead_in_OContext2

                                            Unselect_in_EventStorage1

                                                Foreach_in_List_for_EventRecord1

                                                    Iterate_in_List_for_EventRecord1
*                                                    *pList_for_EventRecord->head= 0

                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                        *Node_for_EventRecord* start= 0

                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                        *Node_for_EventRecord* start= 0
                                        HandleRead_in_OContext3
                                        HandleRead_in_OContext4

                                            ReadHandler_in_ReadHandler1

                                            IAPDUHandler_in_IAPDUHandler1
*                                            *pIAPDUHandler= 6409980

                                            Parse_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  3c
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  6

                                                ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=0
*                                                *IWhiteList* pWhiteList=6409980
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  3c
*                                                *buffer->buffer_[i]=  2
*                                                *buffer->buffer_[i]=  6
*                                                *copy
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  3c
*                                                *buffer->buffer_[i]=  2
*                                                *buffer->buffer_[i]=  6

                                                    ParseHeader_in_APDUParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  3c
*                                                    *buffer->buffer_[i]=  2
*                                                    *buffer->buffer_[i]=  6

                                                        ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                        **inspect_RSeq**
*                                                        *buffer->buffer_[i]=  3c
*                                                        *buffer->buffer_[i]=  2
*                                                        *buffer->buffer_[i]=  6
                                                    ParseHeader_in_APDUParser_static2

                                                        GetRecord_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 60
*                                                        *uint8_t variation= 2

                                                            GetEnumAndType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 60
*                                                            *uint8_t variation= 2

                                                                GetType_in_GroupVariationRecord_static1
*                                                                *uint8_t group= 60
*                                                                *uint8_t variation= 2
*                                                                *GroupVariationType_EVENT
*                                                            *GroupVariation_uint16_t enumeration= 3c02
                                                    ParseHeader_in_APDUParser_static3
                                                    ParseHeader_in_APDUParser_static4

                                                    ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                    HandleAllObjectsHeader_in_APDUParser_static1
*                                                    ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                    *record->gGroupVariationRecord.group=60
*                                                    *record->gGroupVariationRecord.variation=2
*                                                    *record->gGroupVariationRecord.enumeration=3c02
*                                                    *IAPDUHandler* pHandler=0
                                            Parse_in_APDUParser_static2

                                            ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6409980
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  3c
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  6
*                                            *copy
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  3c
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  6

                                                ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                *buffer->buffer_[i]=  3c
*                                                *buffer->buffer_[i]=  2
*                                                *buffer->buffer_[i]=  6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    *buffer->buffer_[i]=  3c
*                                                    *buffer->buffer_[i]=  2
*                                                    *buffer->buffer_[i]=  6
                                                ParseHeader_in_APDUParser_static2

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
                                                ParseHeader_in_APDUParser_static3
                                                ParseHeader_in_APDUParser_static4

                                                ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =6
@@@@                                                *QualifierCode_ALL_OBJECTS*

                                                HandleAllObjectsHeader_in_APDUParser_static1
*                                                ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                *record->gGroupVariationRecord.group=60
*                                                *record->gGroupVariationRecord.variation=2
*                                                *record->gGroupVariationRecord.enumeration=3c02
*                                                *IAPDUHandler* pHandler=6409980
                                                HandleAllObjectsHeader_in_APDUParser_static2

                                                    OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                    ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                    *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                                    *GroupVariationType_EVENT

                                                        SelectMaxCount_in_EventBuffer1
*                                                        *uint32_t maximum= 4294967295
*                                                        *GroupVariation_uint16_t gv= 3c02
@@@@                                                        *GroupVariation_Group60Var2

                                                            SelectByClass_EventClass_in_EventBuffer1
*                                                            *uint32_t max= 4294967295
*                                                            *EventClass_uint8_t clazz= 0

                                                            SelectByClass_in_EventStorageOver2_1
*                                                            *EventClass_uint8_t clazz= 0
*                                                            *uint32_t max= 65535

                                                                SelectByClass_in_EventSelection_static1
*                                                                *uint32_t max= 65535

                                                                    Iterate_in_List_for_EventRecord1
*                                                                    *pList_for_EventRecord->head= 0

                                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                                        *Node_for_EventRecord* start= 0

                                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                        *Node_for_EventRecord* start= 0
*                                                            *uint32_t tmp= 0

                                                    Record_in_IAPDUHandler1
                                        HandleRead_in_OContext5
*                                        *ParseResult_uint8_t result =0

                                            {Load_in_EventBuffer1

                                                {Write_in_EventWriting_static1

                                                    Iterate_in_List_for_EventRecord1
*                                                    *pList_for_EventRecord->head= 0

                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                        *Node_for_EventRecord* start= 0

                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                        *Node_for_EventRecord* start= 0

                                                    WriteSome_in_EventWriting_static1
*                                                    *lists->counters.selected= 0
*                                                *uint16_t num_written =0
                                                }Write_in_EventWriting_static1_

                                                NumSelected_in_EventStorage1
*                                                *(pEventStorage->state).counters.selected= 0
                                            }Load_in_EventBuffer_

                                            Load_in_Database1

                                            load_type_for_Analog_in_Database_static1
*                                            *map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_Binary_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_BinaryOutputStatus_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_AnalogOutputStatus_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_DoubleBitBinary_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_Counter_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_FrozenCounter_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_OctetString_in_Database_static1
*                                            *map.map.size()= 0
*                                            *if (iter == map.end())

                                            load_type_for_TimeAndInterval_in_Database_static1
*                                            *map.map.size()= 0
                                            load_type_for_TimeAndInterval_in_Database_static2
*                                            *if (iter == map.end())
                                        }HandleRead_in_OContext_

                                        {ToByte_in_AppControlField1
*                                        *ret |= AppControlField_FIR_MASK
*                                        *ret |= AppControlField_FIN_MASK
                                        }ToByte_in_AppControlField_
                                        *uint8_t ret =192
                                        *uint8_t seq =0

                                        {SetControl_in_APDUWrapper1
@@@@                                        *write_uint8=6421554->192
                                        }SetControl_in_APDUWrapper_

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
@@@@                                        *write_uint8=6421556->128
@@@@                                        *write_uint8=6421557->0
                                        }SetIIN_in_APDUResponse_

                                        {BeginResponseTx_in_OContext1

                                            {CheckForBroadcastConfirmation_in_OContext1
                                            }CheckForBroadcastConfirmation_in_OContext_

                                            {BeginTx_in_OContext1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  c0
*                                            *buffer->buffer_[i]=  81
*                                            *buffer->buffer_[i]=  80
*                                            *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                                            **inspect_RSeq**
*                                            *buffer->buffer_[i]=  c0
*                                            *buffer->buffer_[i]=  81
*                                            *buffer->buffer_[i]=  80
*                                            *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                                            }BeginTx_in_OContext_

                                            {Inst_in_StateIdle_static1

                                                StateIdle_in_StateIdle1

                                                    OutstationState_in_OutstationState1
                                            }Inst_in_StateIdle_static_
                                        }BeginResponseTx_in_OContext_
                                    }RespondToReadRequest_in_OContext_
                                }OnNewReadRequest_in_StateNullUnsolicitedConfirmWait_override_
                            }ProcessNewRequest_in_OContext1_
                        }OnReceiveSolRequest_in_OContext_
                    }ProcessRequest_in_OContext_
                }ProcessObjects_in_OContext_
            }ProcessMessage_in_OContext6_

            {CheckForTaskStart_in_OContext1

                {CheckForDeferredRequest_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 0
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 1
*                    *pOContext->isOnline && !pOContext->isTransmitting= 0
                    }CanTransmit_in_OContext_
                }CheckForUnsolicitedNull_in_OContext_
            }CheckForTaskStart_in_OContext_
        }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}------------2
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00')
temp2= C0 81 80 00

{OnTxReady_in_OutstationTestObject1

        {OnTxReady_in_OContext1

            {CheckForTaskStart_in_OContext1

                {CheckForDeferredRequest_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *pOContext->isOnline && !pOContext->isTransmitting= 1
                    }CanTransmit_in_OContext_

                    IsIdle_in_OutstationState1

                    IsIdle_in_StateIdle_override1

                    {GetResponseIIN_in_OContext1
*                    *LSBMask_BROADCAST = 0x01
*                    *LSBMask_CLASS1_EVENTS = 0x02
*                    *LSBMask_CLASS2_EVENTS = 0x04
*                    *LSBMask_CLASS3_EVENTS = 0x08
*                    *LSBMask_NEED_TIME = 0x10
*                    *LSBMask_LOCAL_CONTROL = 0x20
*                    *LSBMask_DEVICE_TROUBLE = 0x40
*                    *LSBMask_DEVICE_RESTART = 0x80
*
*                    *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                    *MSBMask_OBJECT_UNKNOWN = 0x02
*                    *MSBMask_PARAM_ERROR = 0x04
*                    *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                    *MSBMask_ALREADY_EXECUTING = 0x10
*                    *MSBMask_CONFIG_CORRUPT = 0x20
*                    *MSBMask_RESERVED1 = 0x40
*                    *MSBMask_RESERVED2 = 0x80
*

                        IsOverflown_in_EventBuffer1
*                        *pEventBuffer->overflow= 0
*                    IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                    *uint8_t LSB=0
*                    *uint8_t MSB=0
*                    IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                    *uint8_t LSB=0
*                    *uint8_t MSB=0
*                    IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                    *uint8_t LSB=80
*                    *uint8_t MSB=0
                    }GetResponseIIN_in_OContext_
*                CheckForUnsolicitedNull_in_OContext2
*                **inspect_IINField**
*                *uint8_t LSB= 128
*                *uint8_t MSB= 0

                    {NullUnsolicited_in_APDUBuilders_static1
*                    *uint8_t seq= 1

                        {ToByte_in_AppControlField1
*                        *ret |= AppControlField_FIR_MASK
*                        *ret |= AppControlField_FIN_MASK
*                        *ret |= AppControlField_CON_MASK
*                        *ret |= AppControlField_UNS_MASK
                        }ToByte_in_AppControlField_
                        *uint8_t ret =240
                        *uint8_t seq =1

                        {SetControl_in_APDUWrapper1
@@@@                        *write_uint8=6421886->241
                        }SetControl_in_APDUWrapper_

                        {SetFunction_in_APDUWrapper1
@@@@                        *write_uint8=6421887->130
                        }SetFunction_in_APDUWrapper_

                        {SetIIN_in_APDUResponse1
@@@@                        *write_uint8=6421888->128
@@@@                        *write_uint8=6421889->0
                        }SetIIN_in_APDUResponse_
                    }NullUnsolicited_in_APDUBuilders_static_
*                    **inspect_IINField**
*                    *uint8_t LSB= 128
*                    *uint8_t MSB= 0
*                CheckForUnsolicitedNull_in_OContext3
*                **inspect_IINField**
*                *uint8_t LSB= 128
*                *uint8_t MSB= 0

                    {RestartUnsolConfirmTimer_in_OContext1
                    *pOContext= 6412536
                    *&(pOContext->confirmTimer)= 6421076

                        {cancel_in_TimerExe4cpp1
                        *TimerExe4cpp *pTimerExe4cpp= 6421076
                        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6411896

                            {cancel_in_ITimer1
                            *pITimer->psource_in_ITimer= 6411896

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6411896
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                            }cancel_in_ITimer1
                        }cancel_in_TimerExe4cpp2_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6411896

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6411896

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762681328
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6411896
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
                    }RestartUnsolConfirmTimer_in_OContext_

                    {Inst_in_StateNullUnsolicitedConfirmWait_static1

                        {StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait1

                            OutstationState_in_OutstationState1
                        }StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait_
                    }Inst_in_StateNullUnsolicitedConfirmWait_static_

                    {BeginUnsolTx_in_OContext1

                        {CheckForBroadcastConfirmation_in_OContext1
                        }CheckForBroadcastConfirmation_in_OContext_
*                    BeginUnsolTx_in_OContext2
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  f1
*                    *buffer->buffer_[i]=  82
*                    *buffer->buffer_[i]=  80
*                    *buffer->buffer_[i]=  0
*                    BeginUnsolTx_in_OContext3
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  f1
*                    *buffer->buffer_[i]=  82
*                    *buffer->buffer_[i]=  80
*                    *buffer->buffer_[i]=  0

                        {BeginTx_in_OContext1
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f1
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  80
*                        *buffer->buffer_[i]=  0

{BeginTransmit_in_MockLowerLayer1
*                        **inspect_RSeq**
*                        *buffer->buffer_[i]=  f1
*                        *buffer->buffer_[i]=  82
*                        *buffer->buffer_[i]=  80
*                        *buffer->buffer_[i]=  0
}BeginTransmit_in_MockLowerLayer_
                        }BeginTx_in_OContext_
                    }BeginUnsolTx_in_OContext_
                }CheckForUnsolicitedNull_in_OContext_
            }CheckForTaskStart_in_OContext_

        }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
{------------3

{NullUnsolicited_in_APDUHexBuilders1
*uint8_t seq= 1

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048

        {NullUnsolicited_in_APDUBuilders_static1
*        *uint8_t seq= 1

            {ToByte_in_AppControlField1
*            *ret |= AppControlField_FIR_MASK
*            *ret |= AppControlField_FIN_MASK
*            *ret |= AppControlField_CON_MASK
*            *ret |= AppControlField_UNS_MASK
            }ToByte_in_AppControlField_
            *uint8_t ret =240
            *uint8_t seq =1

            {SetControl_in_APDUWrapper1
@@@@            *write_uint8=6411036->241
            }SetControl_in_APDUWrapper_

            {SetFunction_in_APDUWrapper1
@@@@            *write_uint8=6411037->130
            }SetFunction_in_APDUWrapper_

            {SetIIN_in_APDUResponse1
@@@@            *write_uint8=6411038->128
@@@@            *write_uint8=6411039->0
            }SetIIN_in_APDUResponse_
        }NullUnsolicited_in_APDUBuilders_static_
*        **inspect_IINField**
*        *uint8_t LSB= 128
*        *uint8_t MSB= 0
}NullUnsolicited_in_APDUHexBuilders_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}------------3
REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField(IINBit::DEVICE_RESTART)))
response= F1 82 80 00
temp3= F1 82 80 00
REQUIRE(t.NumPendingTimers() == 1)
uint16_t num3= 1
