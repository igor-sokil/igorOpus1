********SUITE('25ReadClass0MultiFragAnalog')********
1stack_info=  -1
2stack_info=  -1
3stack_info=  -1

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
*    *config.size()= 8

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
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6415886

    {OutstationSolState_in_OutstationSolState1

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =20

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=20
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6418026
    }OutstationSolState_in_OutstationSolState_

    {OutstationUnsolState_in_OutstationUnsolState1

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =20

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=20
*        *sizeof(BufferSer4)=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6420114
    }OutstationUnsolState_in_OutstationUnsolState_

    {Inst_in_StateIdle_static1

        StateIdle_in_StateIdle1

            OutstationState_in_OutstationState1
    }Inst_in_StateIdle_static_
}OContext_in_OContext_
}OutstationTestObject_in_OutstationTestObject_
4stack_info=  0

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
5stack_info=  0

{Transaction_in_OutstationTestObject1

    update_in_StaticDataMap_for_AnalogSpecOver2_1
*    *inspect_Analog(new_value)
*    **inspect_Analog**
*    @*boolean value= 0
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
*        *PointClass_uint8_t pc= 2
*        *PointClass_Class1= 2
*        *PointClass_Class2= 4
*        *PointClass_Class3= 8

        Update_AnalogSpec_in_EventUpdate_static1

        update_in_StaticDataMap_for_AnalogSpecOver2_1
*        *inspect_Analog(new_value)
*        **inspect_Analog**
*        @*boolean value= 0
*        @*Flags flags.value= 1
*        @*DNPTime timeDNPTime.value= 0
*        @*DNPTime timeDNPTime.quality= 0
*
*        *EventMode_uint8_t mode= 0
*        *EventMode_Force= 1
*        *EventMode_EventOnly= 3
        update_in_StaticDataMap_for_AnalogSpecOver2_2
*        *inspect_Analog(&old_value)
*        **inspect_Analog**
*        @*boolean value= 0
*        @*Flags flags.value= 2
*        @*DNPTime timeDNPTime.value= 0
*        @*DNPTime timeDNPTime.quality= 0

            convert_to_event_class_in_StaticDataMap_static1
*            *PointClass_uint8_t pc= 2
*            *PointClass_Class1= 2
*            *PointClass_Class2= 4
*            *PointClass_Class3= 8

            Update_AnalogSpec_in_EventUpdate_static1

            update_in_StaticDataMap_for_AnalogSpecOver2_1
*            *inspect_Analog(new_value)
*            **inspect_Analog**
*            @*boolean value= 0
*            @*Flags flags.value= 1
*            @*DNPTime timeDNPTime.value= 0
*            @*DNPTime timeDNPTime.quality= 0
*
*            *EventMode_uint8_t mode= 0
*            *EventMode_Force= 1
*            *EventMode_EventOnly= 3
            update_in_StaticDataMap_for_AnalogSpecOver2_2
*            *inspect_Analog(&old_value)
*            **inspect_Analog**
*            @*boolean value= 0
*            @*Flags flags.value= 2
*            @*DNPTime timeDNPTime.value= 0
*            @*DNPTime timeDNPTime.quality= 0

                convert_to_event_class_in_StaticDataMap_static1
*                *PointClass_uint8_t pc= 2
*                *PointClass_Class1= 2
*                *PointClass_Class2= 4
*                *PointClass_Class3= 8

                Update_AnalogSpec_in_EventUpdate_static1

                update_in_StaticDataMap_for_AnalogSpecOver2_1
*                *inspect_Analog(new_value)
*                **inspect_Analog**
*                @*boolean value= 0
*                @*Flags flags.value= 1
*                @*DNPTime timeDNPTime.value= 0
*                @*DNPTime timeDNPTime.quality= 0
*
*                *EventMode_uint8_t mode= 0
*                *EventMode_Force= 1
*                *EventMode_EventOnly= 3
                update_in_StaticDataMap_for_AnalogSpecOver2_2
*                *inspect_Analog(&old_value)
*                **inspect_Analog**
*                @*boolean value= 0
*                @*Flags flags.value= 2
*                @*DNPTime timeDNPTime.value= 0
*                @*DNPTime timeDNPTime.quality= 0

                    convert_to_event_class_in_StaticDataMap_static1
*                    *PointClass_uint8_t pc= 2
*                    *PointClass_Class1= 2
*                    *PointClass_Class2= 4
*                    *PointClass_Class3= 8

                    Update_AnalogSpec_in_EventUpdate_static1

                    update_in_StaticDataMap_for_AnalogSpecOver2_1
*                    *inspect_Analog(new_value)
*                    **inspect_Analog**
*                    @*boolean value= 0
*                    @*Flags flags.value= 1
*                    @*DNPTime timeDNPTime.value= 0
*                    @*DNPTime timeDNPTime.quality= 0
*
*                    *EventMode_uint8_t mode= 0
*                    *EventMode_Force= 1
*                    *EventMode_EventOnly= 3
                    update_in_StaticDataMap_for_AnalogSpecOver2_2
*                    *inspect_Analog(&old_value)
*                    **inspect_Analog**
*                    @*boolean value= 0
*                    @*Flags flags.value= 2
*                    @*DNPTime timeDNPTime.value= 0
*                    @*DNPTime timeDNPTime.quality= 0

                        convert_to_event_class_in_StaticDataMap_static1
*                        *PointClass_uint8_t pc= 2
*                        *PointClass_Class1= 2
*                        *PointClass_Class2= 4
*                        *PointClass_Class3= 8

                        Update_AnalogSpec_in_EventUpdate_static1

                        update_in_StaticDataMap_for_AnalogSpecOver2_1
*                        *inspect_Analog(new_value)
*                        **inspect_Analog**
*                        @*boolean value= 0
*                        @*Flags flags.value= 1
*                        @*DNPTime timeDNPTime.value= 0
*                        @*DNPTime timeDNPTime.quality= 0
*
*                        *EventMode_uint8_t mode= 0
*                        *EventMode_Force= 1
*                        *EventMode_EventOnly= 3
                        update_in_StaticDataMap_for_AnalogSpecOver2_2
*                        *inspect_Analog(&old_value)
*                        **inspect_Analog**
*                        @*boolean value= 0
*                        @*Flags flags.value= 2
*                        @*DNPTime timeDNPTime.value= 0
*                        @*DNPTime timeDNPTime.quality= 0

                            convert_to_event_class_in_StaticDataMap_static1
*                            *PointClass_uint8_t pc= 2
*                            *PointClass_Class1= 2
*                            *PointClass_Class2= 4
*                            *PointClass_Class3= 8

                            Update_AnalogSpec_in_EventUpdate_static1

                            update_in_StaticDataMap_for_AnalogSpecOver2_1
*                            *inspect_Analog(new_value)
*                            **inspect_Analog**
*                            @*boolean value= 0
*                            @*Flags flags.value= 1
*                            @*DNPTime timeDNPTime.value= 0
*                            @*DNPTime timeDNPTime.quality= 0
*
*                            *EventMode_uint8_t mode= 0
*                            *EventMode_Force= 1
*                            *EventMode_EventOnly= 3
                            update_in_StaticDataMap_for_AnalogSpecOver2_2
*                            *inspect_Analog(&old_value)
*                            **inspect_Analog**
*                            @*boolean value= 0
*                            @*Flags flags.value= 2
*                            @*DNPTime timeDNPTime.value= 0
*                            @*DNPTime timeDNPTime.quality= 0

                                convert_to_event_class_in_StaticDataMap_static1
*                                *PointClass_uint8_t pc= 2
*                                *PointClass_Class1= 2
*                                *PointClass_Class2= 4
*                                *PointClass_Class3= 8

                                Update_AnalogSpec_in_EventUpdate_static1

                                update_in_StaticDataMap_for_AnalogSpecOver2_1
*                                *inspect_Analog(new_value)
*                                **inspect_Analog**
*                                @*boolean value= 0
*                                @*Flags flags.value= 1
*                                @*DNPTime timeDNPTime.value= 0
*                                @*DNPTime timeDNPTime.quality= 0
*
*                                *EventMode_uint8_t mode= 0
*                                *EventMode_Force= 1
*                                *EventMode_EventOnly= 3
                                update_in_StaticDataMap_for_AnalogSpecOver2_2
*                                *inspect_Analog(&old_value)
*                                **inspect_Analog**
*                                @*boolean value= 0
*                                @*Flags flags.value= 2
*                                @*DNPTime timeDNPTime.value= 0
*                                @*DNPTime timeDNPTime.quality= 0

                                    convert_to_event_class_in_StaticDataMap_static1
*                                    *PointClass_uint8_t pc= 2
*                                    *PointClass_Class1= 2
*                                    *PointClass_Class2= 4
*                                    *PointClass_Class3= 8

                                    Update_AnalogSpec_in_EventUpdate_static1

                                    {HandleNewEvents_in_OContext1

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_

                                                IsIdle_in_OutstationState1

                                                IsIdle_in_StateIdle_override1
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_
                                    }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

                                    {OnReceive_in_OContext1

                                        {ProcessMessage_in_OContext1
*                                        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6403918<-c0
*                                        @*buffer->buffer_[i]= 6403919<-1
*                                        @*buffer->buffer_[i]= 6403920<-3c
*                                        @*buffer->buffer_[i]= 6403921<-1
*                                        @*buffer->buffer_[i]= 6403922<-6

                                            {ParseRequest_in_APDUHeaderParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6403918<-c0
*                                            @*buffer->buffer_[i]= 6403919<-1
*                                            @*buffer->buffer_[i]= 6403920<-3c
*                                            @*buffer->buffer_[i]= 6403921<-1
*                                            @*buffer->buffer_[i]= 6403922<-6
                                            }ParseRequest_in_APDUHeaderParser_static2_

                                            {ProcessObjects_in_OContext1

                                                {ProcessRequest_in_OContext1

                                                    {OnReceiveSolRequest_in_OContext1

                                                        {ProcessNewRequest_in_OContext1
@@@@                                                        *FunctionCode_READ

                                                            {OnNewReadRequest_in_StateIdle_override1

                                                                {RespondToReadRequest_in_OContext1

                                                                    {SetFunction_in_APDUWrapper1
@@@@                                                                    *write_uint8=6418027->129
                                                                    }SetFunction_in_APDUWrapper_

                                                                    {HandleRead_in_OContext1
*                                                                    **inspect_RSeq**
*                                                                    @*buffer->buffer_[i]= 6403920<-3c
*                                                                    @*buffer->buffer_[i]= 6403921<-1
*                                                                    @*buffer->buffer_[i]= 6403922<-6
                                                                    *HandleRead_in_OContext2

                                                                        Unselect_in_EventStorage1

                                                                            Foreach_in_List_for_EventRecord1

                                                                                Iterate_in_List_for_EventRecord1
*                                                                                *pList_for_EventRecord->head= 0

                                                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                                                    *Node_for_EventRecord* start= 0

                                                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                                    *Node_for_EventRecord* start= 0

                                                                        ReadHandler_in_ReadHandler1

                                                                        IAPDUHandler_in_IAPDUHandler1
*                                                                        *pIAPDUHandler= 6402828

                                                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                                                        {Parse_in_APDUParser_static1
*                                                                        **inspect_RSeq**
*                                                                        @*buffer->buffer_[i]= 6403920<-3c
*                                                                        @*buffer->buffer_[i]= 6403921<-1
*                                                                        @*buffer->buffer_[i]= 6403922<-6

                                                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                                            {ParseSinglePass_in_APDUParser_static1
*                                                                            *IAPDUHandler* pHandler=0
*                                                                            *IWhiteList* pWhiteList=6402828
*                                                                            **inspect_RSeq**
*                                                                            @*buffer->buffer_[i]= 6403920<-3c
*                                                                            @*buffer->buffer_[i]= 6403921<-1
*                                                                            @*buffer->buffer_[i]= 6403922<-6
*                                                                            *copy
*                                                                            **inspect_RSeq**
*                                                                            @*buffer->buffer_[i]= 6403920<-3c
*                                                                            @*buffer->buffer_[i]= 6403921<-1
*                                                                            @*buffer->buffer_[i]= 6403922<-6

                                                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                                                {ParseHeader_in_APDUParser_static1
*                                                                                **inspect_RSeq**
*                                                                                @*buffer->buffer_[i]= 6403920<-3c
*                                                                                @*buffer->buffer_[i]= 6403921<-1
*                                                                                @*buffer->buffer_[i]= 6403922<-6

                                                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                                                    **inspect_RSeq**
*                                                                                    @*buffer->buffer_[i]= 6403920<-3c
*                                                                                    @*buffer->buffer_[i]= 6403921<-1
*                                                                                    @*buffer->buffer_[i]= 6403922<-6
@@@@                                                                                    *read_in_UInt8_static = 6403920<-60
@@@@                                                                                    *read_in_UInt8_static = 6403921<-1
@@@@                                                                                    *read_in_UInt8_static = 6403922<-6

                                                                                    GetRecord_in_GroupVariationRecord_static1
*                                                                                    *uint8_t group= 60
*                                                                                    *uint8_t variation= 1

                                                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                                                        *uint8_t group= 60
*                                                                                        *uint8_t variation= 1

                                                                                            GetType_in_GroupVariationRecord_static1
*                                                                                            *uint8_t group= 60
*                                                                                            *uint8_t variation= 1
*                                                                                            *GroupVariationType_STATIC
*                                                                                        *GroupVariation_uint16_t enumeration= 3c01

                                                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                                                    {ParseQualifier_in_APDUParser_static1
*                                                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                                                    *QualifierCode_ALL_OBJECTS*

                                                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                                                        *record->gGroupVariationRecord.group=60
*                                                                                        *record->gGroupVariationRecord.variation=1
*                                                                                        *record->gGroupVariationRecord.enumeration=3c01
*                                                                                        *IAPDUHandler* pHandler=0
                                                                                    }ParseQualifier_in_APDUParser_static1_
*                                                                                    *ParseResult_uint8_t tmp= 0
                                                                                }ParseHeader_in_APDUParser_static4_
*                                                                                *ParseResult_uint8_t tmp= 0
                                                                            }ParseSinglePass_in_APDUParser_static2_

                                                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                                            {ParseSinglePass_in_APDUParser_static1
*                                                                            *IAPDUHandler* pHandler=6402828
*                                                                            *IWhiteList* pWhiteList=0
*                                                                            **inspect_RSeq**
*                                                                            @*buffer->buffer_[i]= 6403920<-3c
*                                                                            @*buffer->buffer_[i]= 6403921<-1
*                                                                            @*buffer->buffer_[i]= 6403922<-6
*                                                                            *copy
*                                                                            **inspect_RSeq**
*                                                                            @*buffer->buffer_[i]= 6403920<-3c
*                                                                            @*buffer->buffer_[i]= 6403921<-1
*                                                                            @*buffer->buffer_[i]= 6403922<-6

                                                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                                                {ParseHeader_in_APDUParser_static1
*                                                                                **inspect_RSeq**
*                                                                                @*buffer->buffer_[i]= 6403920<-3c
*                                                                                @*buffer->buffer_[i]= 6403921<-1
*                                                                                @*buffer->buffer_[i]= 6403922<-6

                                                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                                                    **inspect_RSeq**
*                                                                                    @*buffer->buffer_[i]= 6403920<-3c
*                                                                                    @*buffer->buffer_[i]= 6403921<-1
*                                                                                    @*buffer->buffer_[i]= 6403922<-6
@@@@                                                                                    *read_in_UInt8_static = 6403920<-60
@@@@                                                                                    *read_in_UInt8_static = 6403921<-1
@@@@                                                                                    *read_in_UInt8_static = 6403922<-6

                                                                                    GetRecord_in_GroupVariationRecord_static1
*                                                                                    *uint8_t group= 60
*                                                                                    *uint8_t variation= 1

                                                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                                                        *uint8_t group= 60
*                                                                                        *uint8_t variation= 1

                                                                                            GetType_in_GroupVariationRecord_static1
*                                                                                            *uint8_t group= 60
*                                                                                            *uint8_t variation= 1
*                                                                                            *GroupVariationType_STATIC
*                                                                                        *GroupVariation_uint16_t enumeration= 3c01

                                                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                                                    {ParseQualifier_in_APDUParser_static1
*                                                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                                                    *QualifierCode_ALL_OBJECTS*

                                                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                                                        *record->gGroupVariationRecord.group=60
*                                                                                        *record->gGroupVariationRecord.variation=1
*                                                                                        *record->gGroupVariationRecord.enumeration=3c01
*                                                                                        *IAPDUHandler* pHandler=6402828
                                                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 0
@@@@                                                                                            *GroupVariationType_STATIC

                                                                                                SelectAll_in_Database1
*                                                                                                *GroupVariation_Group60Var1

                                                                                                select_all_in_StaticDataMap_for_BinarySpecOver3_1
                                                                                                select_all_in_StaticDataMap_for_BinarySpecOver3_2

                                                                                            {Record_in_IAPDUHandler1
                                                                                            *Record_in_IAPDUHandler2
                                                                                            *Record_in_IAPDUHandler3

                                                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                                                }OnHeaderResult_in_IAPDUHandler_
                                                                                            }Record_in_IAPDUHandler_
                                                                                    }ParseQualifier_in_APDUParser_static1_
*                                                                                    *ParseResult_uint8_t tmp= 0
                                                                                }ParseHeader_in_APDUParser_static4_
*                                                                                *ParseResult_uint8_t tmp= 0
                                                                            }ParseSinglePass_in_APDUParser_static2_
                                                                        }Parse_in_APDUParser_static_
                                                                    *HandleRead_in_OContext5
*                                                                    *ParseResult_uint8_t result =0

                                                                        {Load_in_EventBuffer1

                                                                            {Write_in_EventWriting_static1

                                                                                Iterate_in_List_for_EventRecord1
*                                                                                *pList_for_EventRecord->head= 0

                                                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                                                    *Node_for_EventRecord* start= 0

                                                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                                    *Node_for_EventRecord* start= 0

                                                                                WriteSome_in_EventWriting_static1
*                                                                                *lists->counters.selected= 0
*                                                                            *uint16_t num_written =0
                                                                            }Write_in_EventWriting_static1_

                                                                            NumSelected_in_EventStorage1
*                                                                            *(pEventStorage->state).counters.selected= 0
                                                                        }Load_in_EventBuffer_

                                                                        Load_in_Database1

                                                                        load_type_for_Analog_in_Database_static1
*                                                                        *map.size()= 8
*                                                                        *StaticAnalogVariation_uint8_t variation= 0

                                                                            get_for_AnalogSpec_in_StaticWriters_static1
*                                                                            *StaticAnalogVariation_uint8_t variation= 0
*                                                                            *StaticAnalogVariation_Group30Var1

                                                                            WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static1
*                                                                            *range.start= 0
*                                                                            *range.stop= 7

                                                                            DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog1
*                                                                            *id.group= 30
*                                                                            *id.variation= 1
*                                                                            *uint16_t size= 5

                                                                            IterateOverRange_for_UInt8_Analog_in_HeaderWriter1

                                                                                ID_in_DNP3Serializer_for_Analog1
*                                                                                *id.group= 30
*                                                                                *id.variation= 1

                                                                                WriteHeaderWithReserve_in_HeaderWriter1
*                                                                                *qc= 0
*                                                                                *reserve= 7

                                                                                WriteHeader_in_HeaderWriter1
*                                                                                *id.group= 30
*                                                                                *id.variation= 1
*                                                                                *qc= 0
@@@@                                                                                *write_in_UInt8_static = 6418030->30
@@@@                                                                                *write_in_UInt8_static = 6418031->1
@@@@                                                                                *write_in_UInt8_static = 6418032->0

                                                                                RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1
@@@@                                                                            *write_in_UInt8_static = 6418033->0

                                                                            LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1
*                                                                            *map.size()= 8
*                                                                            *for_in_8

                                                                            Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                            Apply_in_ConvertGroup30Var1_static1
*                                                                            *src.value= 0
*                                                                            *target.value= 0

                                                                            Write_in_Group30Var1_static
*                                                                            *arg->flags= 1
*                                                                            *arg->value= 0
@@@@                                                                        *write_in_UInt8_static = 6418035->1
@@@@                                                                        *write_in_UInt32_static = 6418036->0
*                                                                            *for_in_8

                                                                            Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                            Apply_in_ConvertGroup30Var1_static1
*                                                                            *src.value= 0
*                                                                            *target.value= 0

                                                                            Write_in_Group30Var1_static
*                                                                            *arg->flags= 1
*                                                                            *arg->value= 0
@@@@                                                                        *write_in_UInt8_static = 6418040->1
@@@@                                                                        *write_in_UInt32_static = 6418041->0
*                                                                            *for_in_8

                                                                            Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                            RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1
@@@@                                                                        *write_in_UInt8_static = 6418034->1
*                                                                        *if (!get_for_AnalogSpec_in_StaticWriters_static(variation)(map, writer))
                                                                    }HandleRead_in_OContext1_

                                                                    {ToByte_in_AppControlField1
*                                                                    *ret |= AppControlField_FIR_MASK
*                                                                    *ret |= AppControlField_CON_MASK
                                                                    }ToByte_in_AppControlField_
                                                                    *uint8_t ret =160
                                                                    *uint8_t seq =0

                                                                    {SetControl_in_APDUWrapper1
@@@@                                                                    *write_uint8=6418026->160
                                                                    }SetControl_in_APDUWrapper_

                                                                    {GetResponseIIN_in_OContext1
*                                                                    *LSBMask_BROADCAST = 0x01
*                                                                    *LSBMask_CLASS1_EVENTS = 0x02
*                                                                    *LSBMask_CLASS2_EVENTS = 0x04
*                                                                    *LSBMask_CLASS3_EVENTS = 0x08
*                                                                    *LSBMask_NEED_TIME = 0x10
*                                                                    *LSBMask_LOCAL_CONTROL = 0x20
*                                                                    *LSBMask_DEVICE_TROUBLE = 0x40
*                                                                    *LSBMask_DEVICE_RESTART = 0x80
*
*                                                                    *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                                                    *MSBMask_OBJECT_UNKNOWN = 0x02
*                                                                    *MSBMask_PARAM_ERROR = 0x04
*                                                                    *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                                                    *MSBMask_ALREADY_EXECUTING = 0x10
*                                                                    *MSBMask_CONFIG_CORRUPT = 0x20
*                                                                    *MSBMask_RESERVED1 = 0x40
*                                                                    *MSBMask_RESERVED2 = 0x80
*

                                                                        IsOverflown_in_EventBuffer1
*                                                                        *pEventBuffer->overflow= 0
*                                                                    IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                                                    *uint8_t LSB=0
*                                                                    *uint8_t MSB=0
*                                                                    IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                                                    *uint8_t LSB=0
*                                                                    *uint8_t MSB=0
*                                                                    IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                                                    *uint8_t LSB=80
*                                                                    *uint8_t MSB=0
                                                                    }GetResponseIIN_in_OContext_

                                                                    {SetIIN_in_APDUResponse1
@@@@                                                                    *write_uint8=6418028->128
@@@@                                                                    *write_uint8=6418029->0
                                                                    }SetIIN_in_APDUResponse_

                                                                    {BeginResponseTx_in_OContext1

                                                                        {CheckForBroadcastConfirmation_in_OContext1
                                                                        }CheckForBroadcastConfirmation_in_OContext_
*                                                                    *BeginResponseTx_in_OContext2
*                                                                    **inspect_RSeq**
*                                                                    @*buffer->buffer_[i]= 6418026<-a0
*                                                                    @*buffer->buffer_[i]= 6418027<-81
*                                                                    @*buffer->buffer_[i]= 6418028<-80
*                                                                    @*buffer->buffer_[i]= 6418029<-0
*                                                                    @*buffer->buffer_[i]= 6418030<-1e
*                                                                    @*buffer->buffer_[i]= 6418031<-1
*                                                                    @*buffer->buffer_[i]= 6418032<-0
*                                                                    @*buffer->buffer_[i]= 6418033<-0
*                                                                    @*buffer->buffer_[i]= 6418034<-1
*                                                                    @*buffer->buffer_[i]= 6418035<-1
*                                                                    @*buffer->buffer_[i]= 6418036<-0
*                                                                    @*buffer->buffer_[i]= 6418037<-0
*                                                                    @*buffer->buffer_[i]= 6418038<-0
*                                                                    @*buffer->buffer_[i]= 6418039<-0
*                                                                    @*buffer->buffer_[i]= 6418040<-1
*                                                                    @*buffer->buffer_[i]= 6418041<-0
*                                                                    @*buffer->buffer_[i]= 6418042<-0
*                                                                    @*buffer->buffer_[i]= 6418043<-0
*                                                                    @*buffer->buffer_[i]= 6418044<-0
*                                                                    *BeginResponseTx_in_OContext3
*                                                                    **inspect_RSeq**
*                                                                    @*buffer->buffer_[i]= 6418026<-a0
*                                                                    @*buffer->buffer_[i]= 6418027<-81
*                                                                    @*buffer->buffer_[i]= 6418028<-80
*                                                                    @*buffer->buffer_[i]= 6418029<-0
*                                                                    @*buffer->buffer_[i]= 6418030<-1e
*                                                                    @*buffer->buffer_[i]= 6418031<-1
*                                                                    @*buffer->buffer_[i]= 6418032<-0
*                                                                    @*buffer->buffer_[i]= 6418033<-0
*                                                                    @*buffer->buffer_[i]= 6418034<-1
*                                                                    @*buffer->buffer_[i]= 6418035<-1
*                                                                    @*buffer->buffer_[i]= 6418036<-0
*                                                                    @*buffer->buffer_[i]= 6418037<-0
*                                                                    @*buffer->buffer_[i]= 6418038<-0
*                                                                    @*buffer->buffer_[i]= 6418039<-0
*                                                                    @*buffer->buffer_[i]= 6418040<-1
*                                                                    @*buffer->buffer_[i]= 6418041<-0
*                                                                    @*buffer->buffer_[i]= 6418042<-0
*                                                                    @*buffer->buffer_[i]= 6418043<-0
*                                                                    @*buffer->buffer_[i]= 6418044<-0
*                                                                    *BeginResponseTx_in_OContext4
*                                                                    **inspect_RSeq**
*                                                                    @*buffer->buffer_[i]= 6418026<-a0
*                                                                    @*buffer->buffer_[i]= 6418027<-81
*                                                                    @*buffer->buffer_[i]= 6418028<-80
*                                                                    @*buffer->buffer_[i]= 6418029<-0
*                                                                    @*buffer->buffer_[i]= 6418030<-1e
*                                                                    @*buffer->buffer_[i]= 6418031<-1
*                                                                    @*buffer->buffer_[i]= 6418032<-0
*                                                                    @*buffer->buffer_[i]= 6418033<-0
*                                                                    @*buffer->buffer_[i]= 6418034<-1
*                                                                    @*buffer->buffer_[i]= 6418035<-1
*                                                                    @*buffer->buffer_[i]= 6418036<-0
*                                                                    @*buffer->buffer_[i]= 6418037<-0
*                                                                    @*buffer->buffer_[i]= 6418038<-0
*                                                                    @*buffer->buffer_[i]= 6418039<-0
*                                                                    @*buffer->buffer_[i]= 6418040<-1
*                                                                    @*buffer->buffer_[i]= 6418041<-0
*                                                                    @*buffer->buffer_[i]= 6418042<-0
*                                                                    @*buffer->buffer_[i]= 6418043<-0
*                                                                    @*buffer->buffer_[i]= 6418044<-0

                                                                        {BeginTx_in_OContext1
*                                                                        **inspect_RSeq**
*                                                                        @*buffer->buffer_[i]= 6418026<-a0
*                                                                        @*buffer->buffer_[i]= 6418027<-81
*                                                                        @*buffer->buffer_[i]= 6418028<-80
*                                                                        @*buffer->buffer_[i]= 6418029<-0
*                                                                        @*buffer->buffer_[i]= 6418030<-1e
*                                                                        @*buffer->buffer_[i]= 6418031<-1
*                                                                        @*buffer->buffer_[i]= 6418032<-0
*                                                                        @*buffer->buffer_[i]= 6418033<-0
*                                                                        @*buffer->buffer_[i]= 6418034<-1
*                                                                        @*buffer->buffer_[i]= 6418035<-1
*                                                                        @*buffer->buffer_[i]= 6418036<-0
*                                                                        @*buffer->buffer_[i]= 6418037<-0
*                                                                        @*buffer->buffer_[i]= 6418038<-0
*                                                                        @*buffer->buffer_[i]= 6418039<-0
*                                                                        @*buffer->buffer_[i]= 6418040<-1
*                                                                        @*buffer->buffer_[i]= 6418041<-0
*                                                                        @*buffer->buffer_[i]= 6418042<-0
*                                                                        @*buffer->buffer_[i]= 6418043<-0
*                                                                        @*buffer->buffer_[i]= 6418044<-0

{BeginTransmit_in_MockLowerLayer1
*                                                                        **inspect_RSeq**
*                                                                        @*buffer->buffer_[i]= 6418026<-a0
*                                                                        @*buffer->buffer_[i]= 6418027<-81
*                                                                        @*buffer->buffer_[i]= 6418028<-80
*                                                                        @*buffer->buffer_[i]= 6418029<-0
*                                                                        @*buffer->buffer_[i]= 6418030<-1e
*                                                                        @*buffer->buffer_[i]= 6418031<-1
*                                                                        @*buffer->buffer_[i]= 6418032<-0
*                                                                        @*buffer->buffer_[i]= 6418033<-0
*                                                                        @*buffer->buffer_[i]= 6418034<-1
*                                                                        @*buffer->buffer_[i]= 6418035<-1
*                                                                        @*buffer->buffer_[i]= 6418036<-0
*                                                                        @*buffer->buffer_[i]= 6418037<-0
*                                                                        @*buffer->buffer_[i]= 6418038<-0
*                                                                        @*buffer->buffer_[i]= 6418039<-0
*                                                                        @*buffer->buffer_[i]= 6418040<-1
*                                                                        @*buffer->buffer_[i]= 6418041<-0
*                                                                        @*buffer->buffer_[i]= 6418042<-0
*                                                                        @*buffer->buffer_[i]= 6418043<-0
*                                                                        @*buffer->buffer_[i]= 6418044<-0
}BeginTransmit_in_MockLowerLayer_
                                                                        }BeginTx_in_OContext_

                                                                        {RestartSolConfirmTimer_in_OContext1

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
                                                                        }RestartSolConfirmTimer_in_OContext_

                                                                        {Inst_in_StateSolicitedConfirmWait_static1

                                                                            StateSolicitedConfirmWait_in_StateSolicitedConfirmWait1

                                                                                OutstationState_in_OutstationState1
                                                                        }Inst_in_StateSolicitedConfirmWait_static_
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
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_
                                    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == 'A0 81 80 00 1E 01 00 00 01 01 00 00 00 00 01 00 00 00 00')
temp= A0 81 80 00 1E 01 00 00 01 01 00 00 00 00 01 00 00 00 00

{OnTxReady_in_OutstationTestObject1

                                    {OnTxReady_in_OContext1

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_

                                                IsIdle_in_OutstationState1

                                                IsIdle_in_OutstationState_override1
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_

                                    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

                                    {OnReceive_in_OContext1

                                        {ProcessMessage_in_OContext1
*                                        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6403918<-c0
*                                        @*buffer->buffer_[i]= 6403919<-0

                                            {ParseRequest_in_APDUHeaderParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6403918<-c0
*                                            @*buffer->buffer_[i]= 6403919<-0
                                            }ParseRequest_in_APDUHeaderParser_static2_

                                            {ProcessObjects_in_OContext1
*                                            *FunctionCode_CONFIRM

                                                {ProcessConfirm_in_OContext1

                                                    {OnConfirm_in_StateSolicitedConfirmWait_override1

                                                        {cancel_in_TimerExe4cpp1
                                                        *TimerExe4cpp *pTimerExe4cpp= 6415796
                                                        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6406616

                                                            {cancel_in_ITimer1
                                                            *pITimer->psource_in_ITimer= 6406616

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                                            }cancel_in_ITimer1
                                                        }cancel_in_TimerExe4cpp2_

                                                        RemoveAll_in_List_for_EventRecord1

                                                            Iterate_in_List_for_EventRecord1
*                                                            *pList_for_EventRecord->head= 0

                                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                                *Node_for_EventRecord* start= 0

                                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                *Node_for_EventRecord* start= 0

                                                        HasAnySelection_in_Database1

                                                        {ContinueMultiFragResponse_in_OContext1

                                                            {SetFunction_in_APDUWrapper1
@@@@                                                            *write_uint8=6418027->129
                                                            }SetFunction_in_APDUWrapper_

                                                            {Load_in_EventBuffer1

                                                                {Write_in_EventWriting_static1

                                                                    Iterate_in_List_for_EventRecord1
*                                                                    *pList_for_EventRecord->head= 0

                                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                                        *Node_for_EventRecord* start= 0

                                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                        *Node_for_EventRecord* start= 0

                                                                    WriteSome_in_EventWriting_static1
*                                                                    *lists->counters.selected= 0
*                                                                *uint16_t num_written =0
                                                                }Write_in_EventWriting_static1_

                                                                NumSelected_in_EventStorage1
*                                                                *(pEventStorage->state).counters.selected= 0
                                                            }Load_in_EventBuffer_

                                                            Load_in_Database1

                                                            load_type_for_Analog_in_Database_static1
*                                                            *map.size()= 8
*                                                            *StaticAnalogVariation_uint8_t variation= 0

                                                                get_for_AnalogSpec_in_StaticWriters_static1
*                                                                *StaticAnalogVariation_uint8_t variation= 0
*                                                                *StaticAnalogVariation_Group30Var1

                                                                WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static1
*                                                                *range.start= 2
*                                                                *range.stop= 7

                                                                DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog1
*                                                                *id.group= 30
*                                                                *id.variation= 1
*                                                                *uint16_t size= 5

                                                                IterateOverRange_for_UInt8_Analog_in_HeaderWriter1

                                                                    ID_in_DNP3Serializer_for_Analog1
*                                                                    *id.group= 30
*                                                                    *id.variation= 1

                                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                                    *qc= 0
*                                                                    *reserve= 7

                                                                    WriteHeader_in_HeaderWriter1
*                                                                    *id.group= 30
*                                                                    *id.variation= 1
*                                                                    *qc= 0
@@@@                                                                    *write_in_UInt8_static = 6418030->30
@@@@                                                                    *write_in_UInt8_static = 6418031->1
@@@@                                                                    *write_in_UInt8_static = 6418032->0

                                                                    RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1
@@@@                                                                *write_in_UInt8_static = 6418033->2

                                                                LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1
*                                                                *map.size()= 8
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                Apply_in_ConvertGroup30Var1_static1
*                                                                *src.value= 0
*                                                                *target.value= 0

                                                                Write_in_Group30Var1_static
*                                                                *arg->flags= 1
*                                                                *arg->value= 0
@@@@                                                            *write_in_UInt8_static = 6418035->1
@@@@                                                            *write_in_UInt32_static = 6418036->0
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                Apply_in_ConvertGroup30Var1_static1
*                                                                *src.value= 0
*                                                                *target.value= 0

                                                                Write_in_Group30Var1_static
*                                                                *arg->flags= 1
*                                                                *arg->value= 0
@@@@                                                            *write_in_UInt8_static = 6418040->1
@@@@                                                            *write_in_UInt32_static = 6418041->0
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1
@@@@                                                            *write_in_UInt8_static = 6418034->3
*                                                            *if (!get_for_AnalogSpec_in_StaticWriters_static(variation)(map, writer))

                                                            {ToByte_in_AppControlField1
*                                                            *ret |= AppControlField_CON_MASK
                                                            }ToByte_in_AppControlField_
                                                            *uint8_t ret =32
                                                            *uint8_t seq =1

                                                            {SetControl_in_APDUWrapper1
@@@@                                                            *write_uint8=6418026->33
                                                            }SetControl_in_APDUWrapper_

                                                            {GetResponseIIN_in_OContext1
*                                                            *LSBMask_BROADCAST = 0x01
*                                                            *LSBMask_CLASS1_EVENTS = 0x02
*                                                            *LSBMask_CLASS2_EVENTS = 0x04
*                                                            *LSBMask_CLASS3_EVENTS = 0x08
*                                                            *LSBMask_NEED_TIME = 0x10
*                                                            *LSBMask_LOCAL_CONTROL = 0x20
*                                                            *LSBMask_DEVICE_TROUBLE = 0x40
*                                                            *LSBMask_DEVICE_RESTART = 0x80
*
*                                                            *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                                            *MSBMask_OBJECT_UNKNOWN = 0x02
*                                                            *MSBMask_PARAM_ERROR = 0x04
*                                                            *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                                            *MSBMask_ALREADY_EXECUTING = 0x10
*                                                            *MSBMask_CONFIG_CORRUPT = 0x20
*                                                            *MSBMask_RESERVED1 = 0x40
*                                                            *MSBMask_RESERVED2 = 0x80
*

                                                                IsOverflown_in_EventBuffer1
*                                                                *pEventBuffer->overflow= 0
*                                                            IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                                            *uint8_t LSB=0
*                                                            *uint8_t MSB=0
*                                                            IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                                            *uint8_t LSB=0
*                                                            *uint8_t MSB=0
*                                                            IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                                            *uint8_t LSB=80
*                                                            *uint8_t MSB=0
                                                            }GetResponseIIN_in_OContext_

                                                            {SetIIN_in_APDUResponse1
@@@@                                                            *write_uint8=6418028->128
@@@@                                                            *write_uint8=6418029->0
                                                            }SetIIN_in_APDUResponse_

                                                            {BeginResponseTx_in_OContext1

                                                                {CheckForBroadcastConfirmation_in_OContext1
                                                                }CheckForBroadcastConfirmation_in_OContext_
*                                                            *BeginResponseTx_in_OContext2
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-21
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-2
*                                                            @*buffer->buffer_[i]= 6418034<-3
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0
*                                                            *BeginResponseTx_in_OContext3
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-21
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-2
*                                                            @*buffer->buffer_[i]= 6418034<-3
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0
*                                                            *BeginResponseTx_in_OContext4
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-21
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-2
*                                                            @*buffer->buffer_[i]= 6418034<-3
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0

                                                                {BeginTx_in_OContext1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6418026<-21
*                                                                @*buffer->buffer_[i]= 6418027<-81
*                                                                @*buffer->buffer_[i]= 6418028<-80
*                                                                @*buffer->buffer_[i]= 6418029<-0
*                                                                @*buffer->buffer_[i]= 6418030<-1e
*                                                                @*buffer->buffer_[i]= 6418031<-1
*                                                                @*buffer->buffer_[i]= 6418032<-0
*                                                                @*buffer->buffer_[i]= 6418033<-2
*                                                                @*buffer->buffer_[i]= 6418034<-3
*                                                                @*buffer->buffer_[i]= 6418035<-1
*                                                                @*buffer->buffer_[i]= 6418036<-0
*                                                                @*buffer->buffer_[i]= 6418037<-0
*                                                                @*buffer->buffer_[i]= 6418038<-0
*                                                                @*buffer->buffer_[i]= 6418039<-0
*                                                                @*buffer->buffer_[i]= 6418040<-1
*                                                                @*buffer->buffer_[i]= 6418041<-0
*                                                                @*buffer->buffer_[i]= 6418042<-0
*                                                                @*buffer->buffer_[i]= 6418043<-0
*                                                                @*buffer->buffer_[i]= 6418044<-0

{BeginTransmit_in_MockLowerLayer1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6418026<-21
*                                                                @*buffer->buffer_[i]= 6418027<-81
*                                                                @*buffer->buffer_[i]= 6418028<-80
*                                                                @*buffer->buffer_[i]= 6418029<-0
*                                                                @*buffer->buffer_[i]= 6418030<-1e
*                                                                @*buffer->buffer_[i]= 6418031<-1
*                                                                @*buffer->buffer_[i]= 6418032<-0
*                                                                @*buffer->buffer_[i]= 6418033<-2
*                                                                @*buffer->buffer_[i]= 6418034<-3
*                                                                @*buffer->buffer_[i]= 6418035<-1
*                                                                @*buffer->buffer_[i]= 6418036<-0
*                                                                @*buffer->buffer_[i]= 6418037<-0
*                                                                @*buffer->buffer_[i]= 6418038<-0
*                                                                @*buffer->buffer_[i]= 6418039<-0
*                                                                @*buffer->buffer_[i]= 6418040<-1
*                                                                @*buffer->buffer_[i]= 6418041<-0
*                                                                @*buffer->buffer_[i]= 6418042<-0
*                                                                @*buffer->buffer_[i]= 6418043<-0
*                                                                @*buffer->buffer_[i]= 6418044<-0
}BeginTransmit_in_MockLowerLayer_
                                                                }BeginTx_in_OContext_

                                                                {RestartSolConfirmTimer_in_OContext1

                                                                    {cancel_in_TimerExe4cpp1
                                                                    *TimerExe4cpp *pTimerExe4cpp= 6415796
                                                                    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6406616

                                                                        {cancel_in_ITimer1
                                                                        *pITimer->psource_in_ITimer= 6406616

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                                                        }cancel_in_ITimer1
                                                                    }cancel_in_TimerExe4cpp2_

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
                                                                }RestartSolConfirmTimer_in_OContext_

                                                                {Inst_in_StateSolicitedConfirmWait_static1

                                                                    StateSolicitedConfirmWait_in_StateSolicitedConfirmWait1

                                                                        OutstationState_in_OutstationState1
                                                                }Inst_in_StateSolicitedConfirmWait_static_
                                                            }BeginResponseTx_in_OContext_
                                                        }ContinueMultiFragResponse_in_OContext_
                                                    }OnConfirm_in_StateSolicitedConfirmWait_override3_
                                                }ProcessConfirm_in_OContext_
                                            }ProcessObjects_in_OContext4_
                                        }ProcessMessage_in_OContext6_

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_
                                    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == '21 81 80 00 1E 01 00 02 03 01 00 00 00 00 01 00 00 00 00')
temp1= 21 81 80 00 1E 01 00 02 03 01 00 00 00 00 01 00 00 00 00

{OnTxReady_in_OutstationTestObject1

                                    {OnTxReady_in_OContext1

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_

                                                IsIdle_in_OutstationState1

                                                IsIdle_in_OutstationState_override1
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_

                                    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

                                    {OnReceive_in_OContext1

                                        {ProcessMessage_in_OContext1
*                                        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6403918<-c1
*                                        @*buffer->buffer_[i]= 6403919<-0

                                            {ParseRequest_in_APDUHeaderParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6403918<-c1
*                                            @*buffer->buffer_[i]= 6403919<-0
                                            }ParseRequest_in_APDUHeaderParser_static2_

                                            {ProcessObjects_in_OContext1
*                                            *FunctionCode_CONFIRM

                                                {ProcessConfirm_in_OContext1

                                                    {OnConfirm_in_StateSolicitedConfirmWait_override1

                                                        {cancel_in_TimerExe4cpp1
                                                        *TimerExe4cpp *pTimerExe4cpp= 6415796
                                                        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6406616

                                                            {cancel_in_ITimer1
                                                            *pITimer->psource_in_ITimer= 6406616

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                                            }cancel_in_ITimer1
                                                        }cancel_in_TimerExe4cpp2_

                                                        RemoveAll_in_List_for_EventRecord1

                                                            Iterate_in_List_for_EventRecord1
*                                                            *pList_for_EventRecord->head= 0

                                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                                *Node_for_EventRecord* start= 0

                                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                *Node_for_EventRecord* start= 0

                                                        HasAnySelection_in_Database1

                                                        {ContinueMultiFragResponse_in_OContext1

                                                            {SetFunction_in_APDUWrapper1
@@@@                                                            *write_uint8=6418027->129
                                                            }SetFunction_in_APDUWrapper_

                                                            {Load_in_EventBuffer1

                                                                {Write_in_EventWriting_static1

                                                                    Iterate_in_List_for_EventRecord1
*                                                                    *pList_for_EventRecord->head= 0

                                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                                        *Node_for_EventRecord* start= 0

                                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                        *Node_for_EventRecord* start= 0

                                                                    WriteSome_in_EventWriting_static1
*                                                                    *lists->counters.selected= 0
*                                                                *uint16_t num_written =0
                                                                }Write_in_EventWriting_static1_

                                                                NumSelected_in_EventStorage1
*                                                                *(pEventStorage->state).counters.selected= 0
                                                            }Load_in_EventBuffer_

                                                            Load_in_Database1

                                                            load_type_for_Analog_in_Database_static1
*                                                            *map.size()= 8
*                                                            *StaticAnalogVariation_uint8_t variation= 0

                                                                get_for_AnalogSpec_in_StaticWriters_static1
*                                                                *StaticAnalogVariation_uint8_t variation= 0
*                                                                *StaticAnalogVariation_Group30Var1

                                                                WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static1
*                                                                *range.start= 4
*                                                                *range.stop= 7

                                                                DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog1
*                                                                *id.group= 30
*                                                                *id.variation= 1
*                                                                *uint16_t size= 5

                                                                IterateOverRange_for_UInt8_Analog_in_HeaderWriter1

                                                                    ID_in_DNP3Serializer_for_Analog1
*                                                                    *id.group= 30
*                                                                    *id.variation= 1

                                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                                    *qc= 0
*                                                                    *reserve= 7

                                                                    WriteHeader_in_HeaderWriter1
*                                                                    *id.group= 30
*                                                                    *id.variation= 1
*                                                                    *qc= 0
@@@@                                                                    *write_in_UInt8_static = 6418030->30
@@@@                                                                    *write_in_UInt8_static = 6418031->1
@@@@                                                                    *write_in_UInt8_static = 6418032->0

                                                                    RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1
@@@@                                                                *write_in_UInt8_static = 6418033->4

                                                                LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1
*                                                                *map.size()= 8
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                Apply_in_ConvertGroup30Var1_static1
*                                                                *src.value= 0
*                                                                *target.value= 0

                                                                Write_in_Group30Var1_static
*                                                                *arg->flags= 1
*                                                                *arg->value= 0
@@@@                                                            *write_in_UInt8_static = 6418035->1
@@@@                                                            *write_in_UInt32_static = 6418036->0
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                Apply_in_ConvertGroup30Var1_static1
*                                                                *src.value= 0
*                                                                *target.value= 0

                                                                Write_in_Group30Var1_static
*                                                                *arg->flags= 1
*                                                                *arg->value= 0
@@@@                                                            *write_in_UInt8_static = 6418040->1
@@@@                                                            *write_in_UInt32_static = 6418041->0
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1
@@@@                                                            *write_in_UInt8_static = 6418034->5
*                                                            *if (!get_for_AnalogSpec_in_StaticWriters_static(variation)(map, writer))

                                                            {ToByte_in_AppControlField1
*                                                            *ret |= AppControlField_CON_MASK
                                                            }ToByte_in_AppControlField_
                                                            *uint8_t ret =32
                                                            *uint8_t seq =2

                                                            {SetControl_in_APDUWrapper1
@@@@                                                            *write_uint8=6418026->34
                                                            }SetControl_in_APDUWrapper_

                                                            {GetResponseIIN_in_OContext1
*                                                            *LSBMask_BROADCAST = 0x01
*                                                            *LSBMask_CLASS1_EVENTS = 0x02
*                                                            *LSBMask_CLASS2_EVENTS = 0x04
*                                                            *LSBMask_CLASS3_EVENTS = 0x08
*                                                            *LSBMask_NEED_TIME = 0x10
*                                                            *LSBMask_LOCAL_CONTROL = 0x20
*                                                            *LSBMask_DEVICE_TROUBLE = 0x40
*                                                            *LSBMask_DEVICE_RESTART = 0x80
*
*                                                            *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                                            *MSBMask_OBJECT_UNKNOWN = 0x02
*                                                            *MSBMask_PARAM_ERROR = 0x04
*                                                            *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                                            *MSBMask_ALREADY_EXECUTING = 0x10
*                                                            *MSBMask_CONFIG_CORRUPT = 0x20
*                                                            *MSBMask_RESERVED1 = 0x40
*                                                            *MSBMask_RESERVED2 = 0x80
*

                                                                IsOverflown_in_EventBuffer1
*                                                                *pEventBuffer->overflow= 0
*                                                            IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                                            *uint8_t LSB=0
*                                                            *uint8_t MSB=0
*                                                            IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                                            *uint8_t LSB=0
*                                                            *uint8_t MSB=0
*                                                            IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                                            *uint8_t LSB=80
*                                                            *uint8_t MSB=0
                                                            }GetResponseIIN_in_OContext_

                                                            {SetIIN_in_APDUResponse1
@@@@                                                            *write_uint8=6418028->128
@@@@                                                            *write_uint8=6418029->0
                                                            }SetIIN_in_APDUResponse_

                                                            {BeginResponseTx_in_OContext1

                                                                {CheckForBroadcastConfirmation_in_OContext1
                                                                }CheckForBroadcastConfirmation_in_OContext_
*                                                            *BeginResponseTx_in_OContext2
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-22
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-4
*                                                            @*buffer->buffer_[i]= 6418034<-5
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0
*                                                            *BeginResponseTx_in_OContext3
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-22
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-4
*                                                            @*buffer->buffer_[i]= 6418034<-5
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0
*                                                            *BeginResponseTx_in_OContext4
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-22
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-4
*                                                            @*buffer->buffer_[i]= 6418034<-5
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0

                                                                {BeginTx_in_OContext1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6418026<-22
*                                                                @*buffer->buffer_[i]= 6418027<-81
*                                                                @*buffer->buffer_[i]= 6418028<-80
*                                                                @*buffer->buffer_[i]= 6418029<-0
*                                                                @*buffer->buffer_[i]= 6418030<-1e
*                                                                @*buffer->buffer_[i]= 6418031<-1
*                                                                @*buffer->buffer_[i]= 6418032<-0
*                                                                @*buffer->buffer_[i]= 6418033<-4
*                                                                @*buffer->buffer_[i]= 6418034<-5
*                                                                @*buffer->buffer_[i]= 6418035<-1
*                                                                @*buffer->buffer_[i]= 6418036<-0
*                                                                @*buffer->buffer_[i]= 6418037<-0
*                                                                @*buffer->buffer_[i]= 6418038<-0
*                                                                @*buffer->buffer_[i]= 6418039<-0
*                                                                @*buffer->buffer_[i]= 6418040<-1
*                                                                @*buffer->buffer_[i]= 6418041<-0
*                                                                @*buffer->buffer_[i]= 6418042<-0
*                                                                @*buffer->buffer_[i]= 6418043<-0
*                                                                @*buffer->buffer_[i]= 6418044<-0

{BeginTransmit_in_MockLowerLayer1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6418026<-22
*                                                                @*buffer->buffer_[i]= 6418027<-81
*                                                                @*buffer->buffer_[i]= 6418028<-80
*                                                                @*buffer->buffer_[i]= 6418029<-0
*                                                                @*buffer->buffer_[i]= 6418030<-1e
*                                                                @*buffer->buffer_[i]= 6418031<-1
*                                                                @*buffer->buffer_[i]= 6418032<-0
*                                                                @*buffer->buffer_[i]= 6418033<-4
*                                                                @*buffer->buffer_[i]= 6418034<-5
*                                                                @*buffer->buffer_[i]= 6418035<-1
*                                                                @*buffer->buffer_[i]= 6418036<-0
*                                                                @*buffer->buffer_[i]= 6418037<-0
*                                                                @*buffer->buffer_[i]= 6418038<-0
*                                                                @*buffer->buffer_[i]= 6418039<-0
*                                                                @*buffer->buffer_[i]= 6418040<-1
*                                                                @*buffer->buffer_[i]= 6418041<-0
*                                                                @*buffer->buffer_[i]= 6418042<-0
*                                                                @*buffer->buffer_[i]= 6418043<-0
*                                                                @*buffer->buffer_[i]= 6418044<-0
}BeginTransmit_in_MockLowerLayer_
                                                                }BeginTx_in_OContext_

                                                                {RestartSolConfirmTimer_in_OContext1

                                                                    {cancel_in_TimerExe4cpp1
                                                                    *TimerExe4cpp *pTimerExe4cpp= 6415796
                                                                    *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6406616

                                                                        {cancel_in_ITimer1
                                                                        *pITimer->psource_in_ITimer= 6406616

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                                                        }cancel_in_ITimer1
                                                                    }cancel_in_TimerExe4cpp2_

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
                                                                }RestartSolConfirmTimer_in_OContext_

                                                                {Inst_in_StateSolicitedConfirmWait_static1

                                                                    StateSolicitedConfirmWait_in_StateSolicitedConfirmWait1

                                                                        OutstationState_in_OutstationState1
                                                                }Inst_in_StateSolicitedConfirmWait_static_
                                                            }BeginResponseTx_in_OContext_
                                                        }ContinueMultiFragResponse_in_OContext_
                                                    }OnConfirm_in_StateSolicitedConfirmWait_override3_
                                                }ProcessConfirm_in_OContext_
                                            }ProcessObjects_in_OContext4_
                                        }ProcessMessage_in_OContext6_

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_
                                    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == '22 81 80 00 1E 01 00 04 05 01 00 00 00 00 01 00 00 00 00')
temp2= 22 81 80 00 1E 01 00 04 05 01 00 00 00 00 01 00 00 00 00

{OnTxReady_in_OutstationTestObject1

                                    {OnTxReady_in_OContext1

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_

                                                IsIdle_in_OutstationState1

                                                IsIdle_in_OutstationState_override1
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_

                                    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

                                    {OnReceive_in_OContext1

                                        {ProcessMessage_in_OContext1
*                                        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6403918<-c2
*                                        @*buffer->buffer_[i]= 6403919<-0

                                            {ParseRequest_in_APDUHeaderParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6403918<-c2
*                                            @*buffer->buffer_[i]= 6403919<-0
                                            }ParseRequest_in_APDUHeaderParser_static2_

                                            {ProcessObjects_in_OContext1
*                                            *FunctionCode_CONFIRM

                                                {ProcessConfirm_in_OContext1

                                                    {OnConfirm_in_StateSolicitedConfirmWait_override1

                                                        {cancel_in_TimerExe4cpp1
                                                        *TimerExe4cpp *pTimerExe4cpp= 6415796
                                                        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6406616

                                                            {cancel_in_ITimer1
                                                            *pITimer->psource_in_ITimer= 6406616

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6406616
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                                            }cancel_in_ITimer1
                                                        }cancel_in_TimerExe4cpp2_

                                                        RemoveAll_in_List_for_EventRecord1

                                                            Iterate_in_List_for_EventRecord1
*                                                            *pList_for_EventRecord->head= 0

                                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                                *Node_for_EventRecord* start= 0

                                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                *Node_for_EventRecord* start= 0

                                                        HasAnySelection_in_Database1

                                                        {ContinueMultiFragResponse_in_OContext1

                                                            {SetFunction_in_APDUWrapper1
@@@@                                                            *write_uint8=6418027->129
                                                            }SetFunction_in_APDUWrapper_

                                                            {Load_in_EventBuffer1

                                                                {Write_in_EventWriting_static1

                                                                    Iterate_in_List_for_EventRecord1
*                                                                    *pList_for_EventRecord->head= 0

                                                                        From__in__Iterator_in_List_for_EventRecord_static1
*                                                                        *Node_for_EventRecord* start= 0

                                                                        Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                        *Node_for_EventRecord* start= 0

                                                                    WriteSome_in_EventWriting_static1
*                                                                    *lists->counters.selected= 0
*                                                                *uint16_t num_written =0
                                                                }Write_in_EventWriting_static1_

                                                                NumSelected_in_EventStorage1
*                                                                *(pEventStorage->state).counters.selected= 0
                                                            }Load_in_EventBuffer_

                                                            Load_in_Database1

                                                            load_type_for_Analog_in_Database_static1
*                                                            *map.size()= 8
*                                                            *StaticAnalogVariation_uint8_t variation= 0

                                                                get_for_AnalogSpec_in_StaticWriters_static1
*                                                                *StaticAnalogVariation_uint8_t variation= 0
*                                                                *StaticAnalogVariation_Group30Var1

                                                                WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static1
*                                                                *range.start= 6
*                                                                *range.stop= 7

                                                                DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog1
*                                                                *id.group= 30
*                                                                *id.variation= 1
*                                                                *uint16_t size= 5

                                                                IterateOverRange_for_UInt8_Analog_in_HeaderWriter1

                                                                    ID_in_DNP3Serializer_for_Analog1
*                                                                    *id.group= 30
*                                                                    *id.variation= 1

                                                                    WriteHeaderWithReserve_in_HeaderWriter1
*                                                                    *qc= 0
*                                                                    *reserve= 7

                                                                    WriteHeader_in_HeaderWriter1
*                                                                    *id.group= 30
*                                                                    *id.variation= 1
*                                                                    *qc= 0
@@@@                                                                    *write_in_UInt8_static = 6418030->30
@@@@                                                                    *write_in_UInt8_static = 6418031->1
@@@@                                                                    *write_in_UInt8_static = 6418032->0

                                                                    RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1
@@@@                                                                *write_in_UInt8_static = 6418033->6

                                                                LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters1
*                                                                *map.size()= 8
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                Apply_in_ConvertGroup30Var1_static1
*                                                                *src.value= 0
*                                                                *target.value= 0

                                                                Write_in_Group30Var1_static
*                                                                *arg->flags= 1
*                                                                *arg->value= 0
@@@@                                                            *write_in_UInt8_static = 6418035->1
@@@@                                                            *write_in_UInt32_static = 6418036->0
*                                                                *for_in_8

                                                                Write_in_RangeWriteIterator_for_UInt8_Analog1

                                                                Apply_in_ConvertGroup30Var1_static1
*                                                                *src.value= 0
*                                                                *target.value= 0

                                                                Write_in_Group30Var1_static
*                                                                *arg->flags= 1
*                                                                *arg->value= 0
@@@@                                                            *write_in_UInt8_static = 6418040->1
@@@@                                                            *write_in_UInt32_static = 6418041->0

                                                                RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1
@@@@                                                            *write_in_UInt8_static = 6418034->7
*                                                            *if (iter == map.end())

                                                            load_type_for_Binary_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_BinaryOutputStatus_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_AnalogOutputStatus_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_DoubleBitBinary_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_Counter_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_FrozenCounter_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_OctetString_in_Database_static1
*                                                            *map.map.size()= 0
*                                                            *if (iter == map.end())

                                                            load_type_for_TimeAndInterval_in_Database_static1
*                                                            *map.map.size()= 0
                                                            load_type_for_TimeAndInterval_in_Database_static2
*                                                            *if (iter == map.end())

                                                            {ToByte_in_AppControlField1
*                                                            *ret |= AppControlField_FIN_MASK
                                                            }ToByte_in_AppControlField_
                                                            *uint8_t ret =64
                                                            *uint8_t seq =3

                                                            {SetControl_in_APDUWrapper1
@@@@                                                            *write_uint8=6418026->67
                                                            }SetControl_in_APDUWrapper_

                                                            {GetResponseIIN_in_OContext1
*                                                            *LSBMask_BROADCAST = 0x01
*                                                            *LSBMask_CLASS1_EVENTS = 0x02
*                                                            *LSBMask_CLASS2_EVENTS = 0x04
*                                                            *LSBMask_CLASS3_EVENTS = 0x08
*                                                            *LSBMask_NEED_TIME = 0x10
*                                                            *LSBMask_LOCAL_CONTROL = 0x20
*                                                            *LSBMask_DEVICE_TROUBLE = 0x40
*                                                            *LSBMask_DEVICE_RESTART = 0x80
*
*                                                            *MSBMask_FUNC_NOT_SUPPORTED = 0x01
*                                                            *MSBMask_OBJECT_UNKNOWN = 0x02
*                                                            *MSBMask_PARAM_ERROR = 0x04
*                                                            *MSBMask_EVENT_BUFFER_OVERFLOW = 0x08
*                                                            *MSBMask_ALREADY_EXECUTING = 0x10
*                                                            *MSBMask_CONFIG_CORRUPT = 0x20
*                                                            *MSBMask_RESERVED1 = 0x40
*                                                            *MSBMask_RESERVED2 = 0x80
*

                                                                IsOverflown_in_EventBuffer1
*                                                                *pEventBuffer->overflow= 0
*                                                            IINField temp1 = GetDynamicIIN_in_OContext(pOContext)
*                                                            *uint8_t LSB=0
*                                                            *uint8_t MSB=0
*                                                            IINField temp3 = ToIIN_in_ApplicationIIN(&temp)
*                                                            *uint8_t LSB=0
*                                                            *uint8_t MSB=0
*                                                            IINField temp4 = operatorOR_in_IINField(&temp2, &temp3)
*                                                            *uint8_t LSB=80
*                                                            *uint8_t MSB=0
                                                            }GetResponseIIN_in_OContext_

                                                            {SetIIN_in_APDUResponse1
@@@@                                                            *write_uint8=6418028->128
@@@@                                                            *write_uint8=6418029->0
                                                            }SetIIN_in_APDUResponse_

                                                            {BeginResponseTx_in_OContext1

                                                                {CheckForBroadcastConfirmation_in_OContext1
                                                                }CheckForBroadcastConfirmation_in_OContext_
*                                                            *BeginResponseTx_in_OContext2
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-43
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-6
*                                                            @*buffer->buffer_[i]= 6418034<-7
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0
*                                                            *BeginResponseTx_in_OContext3
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-43
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-6
*                                                            @*buffer->buffer_[i]= 6418034<-7
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0
*                                                            *BeginResponseTx_in_OContext4
*                                                            **inspect_RSeq**
*                                                            @*buffer->buffer_[i]= 6418026<-43
*                                                            @*buffer->buffer_[i]= 6418027<-81
*                                                            @*buffer->buffer_[i]= 6418028<-80
*                                                            @*buffer->buffer_[i]= 6418029<-0
*                                                            @*buffer->buffer_[i]= 6418030<-1e
*                                                            @*buffer->buffer_[i]= 6418031<-1
*                                                            @*buffer->buffer_[i]= 6418032<-0
*                                                            @*buffer->buffer_[i]= 6418033<-6
*                                                            @*buffer->buffer_[i]= 6418034<-7
*                                                            @*buffer->buffer_[i]= 6418035<-1
*                                                            @*buffer->buffer_[i]= 6418036<-0
*                                                            @*buffer->buffer_[i]= 6418037<-0
*                                                            @*buffer->buffer_[i]= 6418038<-0
*                                                            @*buffer->buffer_[i]= 6418039<-0
*                                                            @*buffer->buffer_[i]= 6418040<-1
*                                                            @*buffer->buffer_[i]= 6418041<-0
*                                                            @*buffer->buffer_[i]= 6418042<-0
*                                                            @*buffer->buffer_[i]= 6418043<-0
*                                                            @*buffer->buffer_[i]= 6418044<-0

                                                                {BeginTx_in_OContext1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6418026<-43
*                                                                @*buffer->buffer_[i]= 6418027<-81
*                                                                @*buffer->buffer_[i]= 6418028<-80
*                                                                @*buffer->buffer_[i]= 6418029<-0
*                                                                @*buffer->buffer_[i]= 6418030<-1e
*                                                                @*buffer->buffer_[i]= 6418031<-1
*                                                                @*buffer->buffer_[i]= 6418032<-0
*                                                                @*buffer->buffer_[i]= 6418033<-6
*                                                                @*buffer->buffer_[i]= 6418034<-7
*                                                                @*buffer->buffer_[i]= 6418035<-1
*                                                                @*buffer->buffer_[i]= 6418036<-0
*                                                                @*buffer->buffer_[i]= 6418037<-0
*                                                                @*buffer->buffer_[i]= 6418038<-0
*                                                                @*buffer->buffer_[i]= 6418039<-0
*                                                                @*buffer->buffer_[i]= 6418040<-1
*                                                                @*buffer->buffer_[i]= 6418041<-0
*                                                                @*buffer->buffer_[i]= 6418042<-0
*                                                                @*buffer->buffer_[i]= 6418043<-0
*                                                                @*buffer->buffer_[i]= 6418044<-0

{BeginTransmit_in_MockLowerLayer1
*                                                                **inspect_RSeq**
*                                                                @*buffer->buffer_[i]= 6418026<-43
*                                                                @*buffer->buffer_[i]= 6418027<-81
*                                                                @*buffer->buffer_[i]= 6418028<-80
*                                                                @*buffer->buffer_[i]= 6418029<-0
*                                                                @*buffer->buffer_[i]= 6418030<-1e
*                                                                @*buffer->buffer_[i]= 6418031<-1
*                                                                @*buffer->buffer_[i]= 6418032<-0
*                                                                @*buffer->buffer_[i]= 6418033<-6
*                                                                @*buffer->buffer_[i]= 6418034<-7
*                                                                @*buffer->buffer_[i]= 6418035<-1
*                                                                @*buffer->buffer_[i]= 6418036<-0
*                                                                @*buffer->buffer_[i]= 6418037<-0
*                                                                @*buffer->buffer_[i]= 6418038<-0
*                                                                @*buffer->buffer_[i]= 6418039<-0
*                                                                @*buffer->buffer_[i]= 6418040<-1
*                                                                @*buffer->buffer_[i]= 6418041<-0
*                                                                @*buffer->buffer_[i]= 6418042<-0
*                                                                @*buffer->buffer_[i]= 6418043<-0
*                                                                @*buffer->buffer_[i]= 6418044<-0
}BeginTransmit_in_MockLowerLayer_
                                                                }BeginTx_in_OContext_

                                                                {Inst_in_StateIdle_static1

                                                                    StateIdle_in_StateIdle1

                                                                        OutstationState_in_OutstationState1
                                                                }Inst_in_StateIdle_static_
                                                            }BeginResponseTx_in_OContext_
                                                        }ContinueMultiFragResponse_in_OContext_
                                                    }OnConfirm_in_StateSolicitedConfirmWait_override3_
                                                }ProcessConfirm_in_OContext_
                                            }ProcessObjects_in_OContext4_
                                        }ProcessMessage_in_OContext6_

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 1
*                                                *boolean ret= 0
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_
                                    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
REQUIRE(t.lower->PopWriteAsHex() == '43 81 80 00 1E 01 00 06 07 01 00 00 00 00 01 00 00 00 00')
temp3= 43 81 80 00 1E 01 00 06 07 01 00 00 00 00 01 00 00 00 00

{OnTxReady_in_OutstationTestObject1

                                    {OnTxReady_in_OContext1

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_

                                                IsIdle_in_OutstationState1

                                                IsIdle_in_StateIdle_override1
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_

                                    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_

{SendToOutstation_in_OutstationTestObject1

                                    {OnReceive_in_OContext1

                                        {ProcessMessage_in_OContext1
*                                        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6403918<-c3
*                                        @*buffer->buffer_[i]= 6403919<-0

                                            {ParseRequest_in_APDUHeaderParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6403918<-c3
*                                            @*buffer->buffer_[i]= 6403919<-0
                                            }ParseRequest_in_APDUHeaderParser_static2_

                                            {ProcessObjects_in_OContext1
*                                            *FunctionCode_CONFIRM

                                                {ProcessConfirm_in_OContext1
*                                                *FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, 'unexpected confirm while IDLE with sequence: %u'

                                                    {Inst_in_StateIdle_static1

                                                        StateIdle_in_StateIdle1

                                                            OutstationState_in_OutstationState1
                                                    }Inst_in_StateIdle_static_
                                                }ProcessConfirm_in_OContext_
                                            }ProcessObjects_in_OContext4_
                                        }ProcessMessage_in_OContext6_

                                        {CheckForTaskStart_in_OContext1

                                            {CheckForDeferredRequest_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForDeferredRequest_in_OContext_
*                                        CheckForTaskStart_in_OContext2

                                            {CheckForUnsolicitedNull_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_

                                                IsIdle_in_OutstationState1

                                                IsIdle_in_StateIdle_override1
                                            }CheckForUnsolicitedNull_in_OContext_
*                                        CheckForTaskStart_in_OContext3

                                            {CheckForUnsolicited_in_OContext1

                                                {CanTransmit_in_OContext1
*                                                *pOContext->isOnline= 1
*                                                *pOContext->isTransmitting= 0
*                                                *boolean ret= 1
                                                }CanTransmit_in_OContext_
                                            }CheckForUnsolicited_in_OContext_
                                        }CheckForTaskStart_in_OContext_
                                    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer1_
REQUIRE(t.lower->PopWriteAsHex().empty())
temp4=
