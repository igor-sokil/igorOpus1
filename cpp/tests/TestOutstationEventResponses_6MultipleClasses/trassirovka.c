********SUITE('6MultipleClasses')********

DatabaseConfig_in_DatabaseConfig1

{OutstationTestObject_in_OutstationTestObject1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}MockExecutor_in_MockExecutor_

    {OContext_in_OContext1

        EventLists_in_EventLists1
        TotalEvents_in_EventBufferConfig1
*        *pEventBufferConfig->maxBinaryEvents= 10
*        *pEventBufferConfig->maxDoubleBinaryEvents=10
*        *pEventBufferConfig->maxAnalogEvents= 10
*        *pEventBufferConfig->maxCounterEvents= 10
*        *pEventBufferConfig->maxBinaryOutputStatusEvents= 10
*        *pEventBufferConfig->maxAnalogOutputStatusEvents= 10
*        *pEventBufferConfig->maxOctetStringEvents= 10

        List_for_EventRecord_in_List_for_EventRecordOver2_1
*        *uint32_t maxSize= 80

        List_for_EventRecord_in_List_for_EventRecordOver1_1

        Database_in_Database1

        StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2_1
*        *config.size()= 100

        StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*        *config.size()= 100

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

{Transaction_in_OutstationTestObject1
{apply_in_6MultipleClasses1

    {Update_Binary_in_IUpdateHandler1

        {update_in_StaticDataMap_for_BinarySpecOver2_1
*        *iter->second.config.eEventConfig.clazz= 2
+        ++++++int16_t nnn = iter->first=0
*        **inspect_Binary**
*        @*boolean value= 1
*        @*Flags flags.value= 129
*        @*DNPTime timeDNPTime.value= 0
*        @*DNPTime timeDNPTime.quality= 0

            convert_to_event_class_in_StaticDataMap_static1
*            *PointClass_uint8_t pc= 2
*            *PointClass_Class1= 2
*            *PointClass_Class2= 4
*            *PointClass_Class3= 8
        update_in_StaticDataMap_for_BinarySpecOver2_2

            UpdateAny_BinarySpec_in_EventBuffer1

                Update_BinarySpec_in_EventUpdate_static1

                    Instance_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_static1
        }update_in_StaticDataMap_for_BinarySpecOver2__
    }Update_Binary_in_IUpdateHandler_

    {update_in_StaticDataMap_for_AnalogSpecOver2_1
*    *inspect_Analog(new_value)
*    **inspect_Analog**
*    @*boolean value= 3
*    @*Flags flags.value= 1
*    @*DNPTime timeDNPTime.value= 0
*    @*DNPTime timeDNPTime.quality= 0
*
*    *EventMode_uint8_t mode= 0
*    *EventMode_Force= 1
*    *EventMode_EventOnly= 3
    update_in_StaticDataMap_for_AnalogSpecOver2_2
*    *inspect_Analog(&old_value)
*    **inspect_Analog**
*    @*boolean value= 0
*    @*Flags flags.value= 2
*    @*DNPTime timeDNPTime.value= 0
*    @*DNPTime timeDNPTime.quality= 0

        convert_to_event_class_in_StaticDataMap_static1
*        *PointClass_uint8_t pc= 4
*        *PointClass_Class1= 2
*        *PointClass_Class2= 4
*        *PointClass_Class3= 8

        Update_AnalogSpec_in_EventUpdate_static1
        Update_AnalogSpec_in_EventUpdate_static2
*        *(typed_node->value).selectedVariation= 0

            Instance_in_EventTypeImpl_TypedEventRecord_for_AnalogSpec_static1
        }update_in_StaticDataMap_for_AnalogSpecOver22_

        {Update_for_Counter_in_Database1
*        *EventMode_uint8_t mode= 0
*        **inspect_Counter**
*        @*boolean value= 7
*        @*Flags flags.value= 1
*        @*DNPTime timeDNPTime.value= 0
*        @*DNPTime timeDNPTime.quality= 0

            {update_in_StaticDataMap_for_CounterSpecOver2_1
*            **inspect_Counter**
*            @*boolean value= 7
*            @*Flags flags.value= 1
*            @*DNPTime timeDNPTime.value= 0
*            @*DNPTime timeDNPTime.quality= 0
*
*            *EventMode_uint8_t mode= 0
*            *EventMode_Force= 1
*            *EventMode_EventOnly= 3
            update_in_StaticDataMap_for_CounterSpecOver2_2
*            *inspect_Counter(&old_value)
*            **inspect_Counter**
*            @*boolean value= 0
*            @*Flags flags.value= 2
*            @*DNPTime timeDNPTime.value= 0
*            @*DNPTime timeDNPTime.quality= 0
            update_in_StaticDataMap_for_CounterSpecOver2_3
            update_in_StaticDataMap_for_CounterSpecOver2_4

                convert_to_event_class_in_StaticDataMap_static1
*                *PointClass_uint8_t pc= 8
*                *PointClass_Class1= 2
*                *PointClass_Class2= 4
*                *PointClass_Class3= 8

                Instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_static1
            }update_in_StaticDataMap_for_CounterSpecOver2_2_
        }Update_for_Counter_in_Database_
}apply_in_6MultipleClasses_

        {HandleNewEvents_in_OContext1

            {CheckForTaskStart_in_OContext1

                {CheckForDeferredRequest_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *boolean ret= 1
                    }CanTransmit_in_OContext_
                }CheckForDeferredRequest_in_OContext_
*            CheckForTaskStart_in_OContext2

                {CheckForUnsolicitedNull_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *boolean ret= 1
                    }CanTransmit_in_OContext_

                    IsIdle_in_OutstationState1

                    IsIdle_in_StateIdle_override1
                }CheckForUnsolicitedNull_in_OContext_
*            CheckForTaskStart_in_OContext3

                {CheckForUnsolicited_in_OContext1

                    {CanTransmit_in_OContext1
*                    *pOContext->isOnline= 1
*                    *pOContext->isTransmitting= 0
*                    *boolean ret= 1
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
*            @*buffer->buffer_[i]= 6404094<-c0
*            @*buffer->buffer_[i]= 6404095<-1

                {ParseRequest_in_APDUHeaderParser_static1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= 6404094<-c0
*                @*buffer->buffer_[i]= 6404095<-1
                }ParseRequest_in_APDUHeaderParser_static2_

                {ProcessObjects_in_OContext1

                    {ProcessRequest_in_OContext1

                        {OnReceiveSolRequest_in_OContext1

                            {ProcessNewRequest_in_OContext1
@@@@                            *FunctionCode_READ

                                {OnNewReadRequest_in_StateIdle_override1

                                    {RespondToReadRequest_in_OContext1

                                        {SetFunction_in_APDUWrapper1
@@@@                                        *write_uint8=6418027->129
                                        }SetFunction_in_APDUWrapper_

                                        {HandleRead_in_OContext1
*                                        **inspect_RSeq**
                                        *HandleRead_in_OContext2

                                            Unselect_in_EventStorage1

                                                Foreach_in_List_for_EventRecord1

                                                    Iterate_in_List_for_EventRecord1
*                                                    *pList_for_EventRecord->head= 6407392

                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                        *Node_for_EventRecord* start= 6407392

                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                        *Node_for_EventRecord* start= 6407392

                                            ReadHandler_in_ReadHandler1

                                            IAPDUHandler_in_IAPDUHandler1
*                                            *pIAPDUHandler= 6403004

                                            @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                            {Parse_in_APDUParser_static1
*                                            **inspect_RSeq**

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=0
*                                                *IWhiteList* pWhiteList=6403004
*                                                **inspect_RSeq**
                                                }ParseSinglePass_in_APDUParser_static2_

                                                @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseSinglePass_in_APDUParser_static1
*                                                *IAPDUHandler* pHandler=6403004
*                                                *IWhiteList* pWhiteList=0
*                                                **inspect_RSeq**
                                                }ParseSinglePass_in_APDUParser_static2_
                                            }Parse_in_APDUParser_static_
                                        *HandleRead_in_OContext5
*                                        *ParseResult_uint8_t result =0

                                            {Load_in_EventBuffer1

                                                {Write_in_EventWriting_static1

                                                    Iterate_in_List_for_EventRecord1
*                                                    *pList_for_EventRecord->head= 6407392

                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                        *Node_for_EventRecord* start= 6407392

                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                        *Node_for_EventRecord* start= 6407392

                                                    WriteSome_in_EventWriting_static1
*                                                    *lists->counters.selected= 0
*                                                *uint16_t num_written =0
                                                }Write_in_EventWriting_static1_

                                                NumSelected_in_EventStorage1
*                                                *(pEventStorage->state).counters.selected= 0
                                            }Load_in_EventBuffer_

                                            Load_in_Database1

                                            load_type_for_Analog_in_Database_static1
*                                            *map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_Binary_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_BinaryOutputStatus_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_AnalogOutputStatus_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_DoubleBitBinary_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_Counter_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_FrozenCounter_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_OctetString_in_Database_static1
*                                            *map.map.size()= 100
*                                            *if (iter == map.end())

                                            load_type_for_TimeAndInterval_in_Database_static1
*                                            *map.map.size()= 100
                                            load_type_for_TimeAndInterval_in_Database_static2
*                                            *if (iter == map.end())
                                        }HandleRead_in_OContext1_

                                        {ToByte_in_AppControlField1
*                                        *ret |= AppControlField_FIR_MASK
*                                        *ret |= AppControlField_FIN_MASK
                                        }ToByte_in_AppControlField_
                                        *uint8_t ret =192
                                        *uint8_t seq =0

                                        {SetControl_in_APDUWrapper1
@@@@                                        *write_uint8=6418026->192
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
*                                        *uint8_t LSB=e
*                                        *uint8_t MSB=0
*                                        IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                        *uint8_t LSB=0
*                                        *uint8_t MSB=0
*                                        IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                        *uint8_t LSB=8e
*                                        *uint8_t MSB=0
                                        }GetResponseIIN_in_OContext_

                                        {SetIIN_in_APDUResponse1
@@@@                                        *write_uint8=6418028->142
@@@@                                        *write_uint8=6418029->0
                                        }SetIIN_in_APDUResponse_

                                        {BeginResponseTx_in_OContext1

                                            {CheckForBroadcastConfirmation_in_OContext1
                                            }CheckForBroadcastConfirmation_in_OContext_
*                                        *BeginResponseTx_in_OContext2
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-8e
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        *BeginResponseTx_in_OContext3
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-8e
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        *BeginResponseTx_in_OContext4
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-c0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-8e
*                                        @*buffer->buffer_[i]= 6418029<-0

                                            {BeginTx_in_OContext1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6418026<-c0
*                                            @*buffer->buffer_[i]= 6418027<-81
*                                            @*buffer->buffer_[i]= 6418028<-8e
*                                            @*buffer->buffer_[i]= 6418029<-0

{BeginTransmit_in_MockLowerLayer1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6418026<-c0
*                                            @*buffer->buffer_[i]= 6418027<-81
*                                            @*buffer->buffer_[i]= 6418028<-8e
*                                            @*buffer->buffer_[i]= 6418029<-0
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
n1= C0 01
REQUIRE('C0 81 8E 00' == t.lower->PopWriteAsHex())
temp= C0 81 8E 00
