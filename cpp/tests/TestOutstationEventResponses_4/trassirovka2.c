********SUITE('4ReadClass1WithSOEWithTimeoutInBetween')********
{------------1

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
apply_in_4ReadClass1WithSOEWithTimeoutInBetween

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

    {HandleNewEvents_in_OContext1

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
    }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{ClassPoll_in_APDUHexBuilders1
*uint8_t seq= 0
*PointClass_uint8_t pc= 2

{ClassTask_in_APDUHexBuilders1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6403952

    {ClassRequest_in_APDUBuilders_static1
*    **inspect_ClassField**
*    @*uint8_t bitfield= 2

        {ToByte_in_AppControlField1
*        *ret |= AppControlField_FIR_MASK
*        *ret |= AppControlField_FIN_MASK
        }ToByte_in_AppControlField_
        *uint8_t ret =192
        *uint8_t seq =0

        {SetControl_in_APDUWrapper1
@@@@        *write_uint8=6403952->192
        }SetControl_in_APDUWrapper_

        {SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6403953->1
        }SetFunction_in_APDUWrapper_

        WriteClassHeaders_in_APDUBuilders_static1

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 2
*            *qc= 6
@@@@            *write_in_UInt8_static = 6403954->60
@@@@            *write_in_UInt8_static = 6403955->2
@@@@            *write_in_UInt8_static = 6403956->6
    }ClassRequest_in_APDUBuilders_static_
}ClassTask_in_APDUHexBuilders_
}ClassPoll_in_APDUHexBuilders_

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404014<-c0
*        @*buffer->buffer_[i]= 6404015<-1
*        @*buffer->buffer_[i]= 6404016<-3c
*        @*buffer->buffer_[i]= 6404017<-2
*        @*buffer->buffer_[i]= 6404018<-6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404014<-c0
*            @*buffer->buffer_[i]= 6404015<-1
*            @*buffer->buffer_[i]= 6404016<-3c
*            @*buffer->buffer_[i]= 6404017<-2
*            @*buffer->buffer_[i]= 6404018<-6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6418027->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6404016<-3c
*                                    @*buffer->buffer_[i]= 6404017<-2
*                                    @*buffer->buffer_[i]= 6404018<-6
                                    *HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 6407392

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 6407392

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 6407392

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6402924

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6404016<-3c
*                                        @*buffer->buffer_[i]= 6404017<-2
*                                        @*buffer->buffer_[i]= 6404018<-6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6402924
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404016<-3c
*                                                @*buffer->buffer_[i]= 6404017<-2
*                                                @*buffer->buffer_[i]= 6404018<-6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6404016<-3c
*                                                    @*buffer->buffer_[i]= 6404017<-2
*                                                    @*buffer->buffer_[i]= 6404018<-6
@@@@                                                    *read_in_UInt8_static = 6404016<-60
@@@@                                                    *read_in_UInt8_static = 6404017<-2
@@@@                                                    *read_in_UInt8_static = 6404018<-6

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

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=2
*                                                        *record->gGroupVariationRecord.enumeration=3c02
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6402924
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404016<-3c
*                                                @*buffer->buffer_[i]= 6404017<-2
*                                                @*buffer->buffer_[i]= 6404018<-6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6404016<-3c
*                                                    @*buffer->buffer_[i]= 6404017<-2
*                                                    @*buffer->buffer_[i]= 6404018<-6
@@@@                                                    *read_in_UInt8_static = 6404016<-60
@@@@                                                    *read_in_UInt8_static = 6404017<-2
@@@@                                                    *read_in_UInt8_static = 6404018<-6

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

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=2
*                                                        *record->gGroupVariationRecord.enumeration=3c02
*                                                        *IAPDUHandler* pHandler=6402924
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                                            *GroupVariationType_EVENT

                                                                SelectMaxCount_in_EventBuffer1
*                                                                *uint32_t maximum= 4294967295
*                                                                *GroupVariation_uint16_t gv= 3c02
@@@@                                                                *GroupVariation_Group60Var2

                                                                    SelectByClass_EventClass_in_EventBuffer1
*                                                                    *uint32_t max= 4294967295
*                                                                    *EventClass_uint8_t clazz= 0

                                                                    SelectByClass_in_EventStorageOver2_1
*                                                                    *EventClass_uint8_t clazz= 0
*                                                                    *uint32_t max= 65535

                                                                        SelectByClass_in_EventSelection_static1
*                                                                        *uint32_t max= 65535

                                                                            Iterate_in_List_for_EventRecord1
*                                                                            *pList_for_EventRecord->head= 6407392

                                                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                                                *Node_for_EventRecord* start= 6407392

                                                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                                *Node_for_EventRecord* start= 6407392
                                                                        SelectByClass_in_EventSelection_static2

                                                                            OnSelect_in_EventClassCounters1
*                                                                    *uint32_t tmp= 1

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    *HandleRead_in_OContext5
*                                    *ParseResult_uint8_t result =0

                                        {Load_in_EventBuffer1

                                            {Write_in_EventWriting_static1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 6407392

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 6407392

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 6407392

                                                WriteSome_in_EventWriting_static1
*                                                *lists->counters.selected= 1
                                                WriteSome_in_EventWriting_static2
                                                WriteSome_in_EventWriting_static3

                                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override1

                                                        Write_for_Binary_in_ASDUEventWriteHandler_override1
*                                                        *EventBinaryVariation_uint8_t variation= 0
@@@@                                                        *EventBinaryVariation_Group2Var1

                                                            Write_for_Binary_in_EventWriters_static1

                                                                BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary1

                                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter1

                                                                        WriteHeaderWithReserve_in_HeaderWriter1
*                                                                        *qc= 40
*                                                                        *reserve= 5

                                                                        WriteHeader_in_HeaderWriter1
*                                                                        *id.group= 2
*                                                                        *id.variation= 1
*                                                                        *qc= 40
@@@@                                                                        *write_in_UInt8_static = 6418030->2
@@@@                                                                        *write_in_UInt8_static = 6418031->1
@@@@                                                                        *write_in_UInt8_static = 6418032->40

                                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_1
                                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_2
                                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter2

                                                                WriteSome_in_EventCollection_for_Binary_override1

                                                                    WriteOne_in_EventCollection_for_Binary1

                                                                        FindNextSelected_in_EventWriting_static1
                                                                        FindNextSelected_in_EventWriting_static3
                                                                    WriteOne_in_EventCollection_for_Binary2
*                                                                    **inspect_Binary**
*                                                                    @*boolean value= 1
*                                                                    @*Flags flags.value= 129
*                                                                    @*DNPTime timeDNPTime.value= 0
*                                                                    @*DNPTime timeDNPTime.quality= 0

                                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                                            **inspect_Binary**
*                                                                            @*boolean value= 1
*                                                                            @*Flags flags.value= 129
*                                                                            @*DNPTime timeDNPTime.value= 0
*                                                                            @*DNPTime timeDNPTime.quality= 0
@@@@                                                                            *write_in_UInt16_static = 6418035->0

                                                                                WriteTarget_in_Group2Var1_static1

                                                                                Write_in_Group2Var1_static1
*                                                                                *arg->flags= 129
@@@@                                                                            *write_in_UInt8_static = 6418037->129
                                                                    WriteOne_in_EventCollection_for_Binary3

                                                                    WriteOne_in_EventCollection_for_Binary1
                                                            Write_for_Binary_in_EventWriters_static2

                                                                PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary1
@@@@                                                                *write_in_UInt16_static = 6418033->1
*                                                    *(type->value).selectedVariation= 0
*                                                    *bBinary.tTypedMeasurement_for_Boolean.value= 1
*                                                    *bBinary.tTypedMeasurement_for_Boolean.mMeasurement.flags= 129
                                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override2
*                                            *uint16_t num_written =1

                                                WriteSome_in_EventWriting_static1
*                                                *lists->counters.selected= 0
*                                            *uint16_t num_written =0
                                            }Write_in_EventWriting_static1_

                                            NumSelected_in_EventStorage1
*                                            *(pEventStorage->state).counters.selected= 0
                                        }Load_in_EventBuffer_

                                        Load_in_Database1

                                        load_type_for_Analog_in_Database_static1
*                                        *map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_Binary_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_BinaryOutputStatus_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_AnalogOutputStatus_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_DoubleBitBinary_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_Counter_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 100
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext1_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
*                                    *ret |= AppControlField_CON_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =224
                                    *uint8_t seq =0

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6418026->224
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
@@@@                                    *write_uint8=6418028->128
@@@@                                    *write_uint8=6418029->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_
*                                    *BeginResponseTx_in_OContext2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-e0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    @*buffer->buffer_[i]= 6418030<-2
*                                    @*buffer->buffer_[i]= 6418031<-1
*                                    @*buffer->buffer_[i]= 6418032<-28
*                                    @*buffer->buffer_[i]= 6418033<-1
*                                    @*buffer->buffer_[i]= 6418034<-0
*                                    @*buffer->buffer_[i]= 6418035<-0
*                                    @*buffer->buffer_[i]= 6418036<-0
*                                    @*buffer->buffer_[i]= 6418037<-81
*                                    *BeginResponseTx_in_OContext3
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-e0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    @*buffer->buffer_[i]= 6418030<-2
*                                    @*buffer->buffer_[i]= 6418031<-1
*                                    @*buffer->buffer_[i]= 6418032<-28
*                                    @*buffer->buffer_[i]= 6418033<-1
*                                    @*buffer->buffer_[i]= 6418034<-0
*                                    @*buffer->buffer_[i]= 6418035<-0
*                                    @*buffer->buffer_[i]= 6418036<-0
*                                    @*buffer->buffer_[i]= 6418037<-81
*                                    *BeginResponseTx_in_OContext4
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-e0
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    @*buffer->buffer_[i]= 6418030<-2
*                                    @*buffer->buffer_[i]= 6418031<-1
*                                    @*buffer->buffer_[i]= 6418032<-28
*                                    @*buffer->buffer_[i]= 6418033<-1
*                                    @*buffer->buffer_[i]= 6418034<-0
*                                    @*buffer->buffer_[i]= 6418035<-0
*                                    @*buffer->buffer_[i]= 6418036<-0
*                                    @*buffer->buffer_[i]= 6418037<-81

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-e0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        @*buffer->buffer_[i]= 6418030<-2
*                                        @*buffer->buffer_[i]= 6418031<-1
*                                        @*buffer->buffer_[i]= 6418032<-28
*                                        @*buffer->buffer_[i]= 6418033<-1
*                                        @*buffer->buffer_[i]= 6418034<-0
*                                        @*buffer->buffer_[i]= 6418035<-0
*                                        @*buffer->buffer_[i]= 6418036<-0
*                                        @*buffer->buffer_[i]= 6418037<-81

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-e0
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        @*buffer->buffer_[i]= 6418030<-2
*                                        @*buffer->buffer_[i]= 6418031<-1
*                                        @*buffer->buffer_[i]= 6418032<-28
*                                        @*buffer->buffer_[i]= 6418033<-1
*                                        @*buffer->buffer_[i]= 6418034<-0
*                                        @*buffer->buffer_[i]= 6418035<-0
*                                        @*buffer->buffer_[i]= 6418036<-0
*                                        @*buffer->buffer_[i]= 6418037<-81
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
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *boolean ret= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_

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
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_

    }OnTxReady_in_OContext2_
}OnTxReady_in_OutstationTestObject_
}------------1
request= C0 01 3C 02 06
REQUIRE('E0 81 80 00 02 01 28 01 00 00 00 81' == t.lower->PopWriteAsHex())
temp1= E0 81 80 00 02 01 28 01 00 00 00 81
{------------2
{------------too late

    {timeout_RestartSolConfirmTimer_in_OContext1

        {OnConfirmTimeout_in_StateSolicitedConfirmWait_override1
*        *SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'solicited confirm timeout')

            {Inst_in_StateIdle_static1

                StateIdle_in_StateIdle1

                    OutstationState_in_OutstationState1
            }Inst_in_StateIdle_static_
        }OnConfirmTimeout_in_StateSolicitedConfirmWait_override_

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
    }timeout_RestartSolConfirmTimer_in_OContext_

{SolicitedConfirm_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6403968

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6403968->192
    }SetControl_in_APDUWrapper_

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6403969->0
    }SetFunction_in_APDUWrapper_
}SolicitedConfirm_in_APDUHexBuilders_
name2= C0 00

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404014<-c0
*        @*buffer->buffer_[i]= 6404015<-0

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404014<-c0
*            @*buffer->buffer_[i]= 6404015<-0
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1
*            *FunctionCode_CONFIRM

                {ProcessConfirm_in_OContext1
*                *FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, 'unexpected confirm while IDLE with sequence: %u'
*                *request.header.control.SEQ= 0
*                *((OContext*)pOContext)->unexpectedConfirm= 1

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
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_
}------------too late

{Transaction_in_OutstationTestObject1
apply_in_4ReadClass1WithSOEWithTimeoutInBetween2

    {Update_Binary_in_IUpdateHandler1

        {update_in_StaticDataMap_for_BinarySpecOver2_1
*        *iter->second.config.eEventConfig.clazz= 2
+        ++++++int16_t nnn = iter->first=0
*        **inspect_Binary**
*        @*boolean value= 0
*        @*Flags flags.value= 1
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

    {HandleNewEvents_in_OContext1

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
    }HandleNewEvents_in_OContext_
}Transaction_in_OutstationTestObject_

{ClassPoll_in_APDUHexBuilders1
*uint8_t seq= 1
*PointClass_uint8_t pc= 2

{ClassTask_in_APDUHexBuilders1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6403952

    {ClassRequest_in_APDUBuilders_static1
*    **inspect_ClassField**
*    @*uint8_t bitfield= 2

        {ToByte_in_AppControlField1
*        *ret |= AppControlField_FIR_MASK
*        *ret |= AppControlField_FIN_MASK
        }ToByte_in_AppControlField_
        *uint8_t ret =192
        *uint8_t seq =1

        {SetControl_in_APDUWrapper1
@@@@        *write_uint8=6403952->193
        }SetControl_in_APDUWrapper_

        {SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6403953->1
        }SetFunction_in_APDUWrapper_

        WriteClassHeaders_in_APDUBuilders_static1

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 2
*            *qc= 6
@@@@            *write_in_UInt8_static = 6403954->60
@@@@            *write_in_UInt8_static = 6403955->2
@@@@            *write_in_UInt8_static = 6403956->6
    }ClassRequest_in_APDUBuilders_static_
}ClassTask_in_APDUHexBuilders_
}ClassPoll_in_APDUHexBuilders_

{SendToOutstation_in_OutstationTestObject1

    {OnReceive_in_OContext1

        {ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= 6404014<-c1
*        @*buffer->buffer_[i]= 6404015<-1
*        @*buffer->buffer_[i]= 6404016<-3c
*        @*buffer->buffer_[i]= 6404017<-2
*        @*buffer->buffer_[i]= 6404018<-6

            {ParseRequest_in_APDUHeaderParser_static1
*            **inspect_RSeq**
*            @*buffer->buffer_[i]= 6404014<-c1
*            @*buffer->buffer_[i]= 6404015<-1
*            @*buffer->buffer_[i]= 6404016<-3c
*            @*buffer->buffer_[i]= 6404017<-2
*            @*buffer->buffer_[i]= 6404018<-6
            }ParseRequest_in_APDUHeaderParser_static2_

            {ProcessObjects_in_OContext1

                {ProcessRequest_in_OContext1

                    {OnReceiveSolRequest_in_OContext1

                        {ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            {OnNewReadRequest_in_StateIdle_override1

                                {RespondToReadRequest_in_OContext1

                                    {SetFunction_in_APDUWrapper1
@@@@                                    *write_uint8=6418027->129
                                    }SetFunction_in_APDUWrapper_

                                    {HandleRead_in_OContext1
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6404016<-3c
*                                    @*buffer->buffer_[i]= 6404017<-2
*                                    @*buffer->buffer_[i]= 6404018<-6
                                    *HandleRead_in_OContext2

                                        Unselect_in_EventStorage1

                                            Foreach_in_List_for_EventRecord1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 6407392

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 6407392

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 6407392

                                        ReadHandler_in_ReadHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6402924

                                        @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                        {Parse_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6404016<-3c
*                                        @*buffer->buffer_[i]= 6404017<-2
*                                        @*buffer->buffer_[i]= 6404018<-6

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6402924
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404016<-3c
*                                                @*buffer->buffer_[i]= 6404017<-2
*                                                @*buffer->buffer_[i]= 6404018<-6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6404016<-3c
*                                                    @*buffer->buffer_[i]= 6404017<-2
*                                                    @*buffer->buffer_[i]= 6404018<-6
@@@@                                                    *read_in_UInt8_static = 6404016<-60
@@@@                                                    *read_in_UInt8_static = 6404017<-2
@@@@                                                    *read_in_UInt8_static = 6404018<-6

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

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=2
*                                                        *record->gGroupVariationRecord.enumeration=3c02
*                                                        *IAPDUHandler* pHandler=0
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_

                                            @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6402924
*                                            *IWhiteList* pWhiteList=0
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6
*                                            *copy
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 6404016<-3c
*                                            @*buffer->buffer_[i]= 6404017<-2
*                                            @*buffer->buffer_[i]= 6404018<-6

                                                @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                                {ParseHeader_in_APDUParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 6404016<-3c
*                                                @*buffer->buffer_[i]= 6404017<-2
*                                                @*buffer->buffer_[i]= 6404018<-6

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 6404016<-3c
*                                                    @*buffer->buffer_[i]= 6404017<-2
*                                                    @*buffer->buffer_[i]= 6404018<-6
@@@@                                                    *read_in_UInt8_static = 6404016<-60
@@@@                                                    *read_in_UInt8_static = 6404017<-2
@@@@                                                    *read_in_UInt8_static = 6404018<-6

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

                                                    @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                    {ParseQualifier_in_APDUParser_static1
*                                                    *QualifierCode_uint8_t tmp =6
@@@@                                                    *QualifierCode_ALL_OBJECTS*

                                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                                        *record->gGroupVariationRecord.group=60
*                                                        *record->gGroupVariationRecord.variation=2
*                                                        *record->gGroupVariationRecord.enumeration=3c02
*                                                        *IAPDUHandler* pHandler=6402924
                                                        HandleAllObjectsHeader_in_APDUParser_static2

                                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                                            *GroupVariationType_EVENT

                                                                SelectMaxCount_in_EventBuffer1
*                                                                *uint32_t maximum= 4294967295
*                                                                *GroupVariation_uint16_t gv= 3c02
@@@@                                                                *GroupVariation_Group60Var2

                                                                    SelectByClass_EventClass_in_EventBuffer1
*                                                                    *uint32_t max= 4294967295
*                                                                    *EventClass_uint8_t clazz= 0

                                                                    SelectByClass_in_EventStorageOver2_1
*                                                                    *EventClass_uint8_t clazz= 0
*                                                                    *uint32_t max= 65535

                                                                        SelectByClass_in_EventSelection_static1
*                                                                        *uint32_t max= 65535

                                                                            Iterate_in_List_for_EventRecord1
*                                                                            *pList_for_EventRecord->head= 6407392

                                                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                                                *Node_for_EventRecord* start= 6407392

                                                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                                                *Node_for_EventRecord* start= 6407392
                                                                        SelectByClass_in_EventSelection_static2

                                                                            OnSelect_in_EventClassCounters1
                                                                        SelectByClass_in_EventSelection_static2

                                                                            OnSelect_in_EventClassCounters1
*                                                                    *uint32_t tmp= 2

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static1_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_
                                    *HandleRead_in_OContext5
*                                    *ParseResult_uint8_t result =0

                                        {Load_in_EventBuffer1

                                            {Write_in_EventWriting_static1

                                                Iterate_in_List_for_EventRecord1
*                                                *pList_for_EventRecord->head= 6407392

                                                    From__in__Iterator_in_List_for_EventRecord_static1
*                                                    *Node_for_EventRecord* start= 6407392

                                                    Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                    *Node_for_EventRecord* start= 6407392

                                                WriteSome_in_EventWriting_static1
*                                                *lists->counters.selected= 2
                                                WriteSome_in_EventWriting_static2
                                                WriteSome_in_EventWriting_static3

                                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override1

                                                        Write_for_Binary_in_ASDUEventWriteHandler_override1
*                                                        *EventBinaryVariation_uint8_t variation= 0
@@@@                                                        *EventBinaryVariation_Group2Var1

                                                            Write_for_Binary_in_EventWriters_static1

                                                                BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary1

                                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter1

                                                                        WriteHeaderWithReserve_in_HeaderWriter1
*                                                                        *qc= 40
*                                                                        *reserve= 5

                                                                        WriteHeader_in_HeaderWriter1
*                                                                        *id.group= 2
*                                                                        *id.variation= 1
*                                                                        *qc= 40
@@@@                                                                        *write_in_UInt8_static = 6418030->2
@@@@                                                                        *write_in_UInt8_static = 6418031->1
@@@@                                                                        *write_in_UInt8_static = 6418032->40

                                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_1
                                                                        PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2_2
                                                                    IterateOverCountWithPrefix_for_UInt16_Binary_in_HeaderWriter2

                                                                WriteSome_in_EventCollection_for_Binary_override1

                                                                    WriteOne_in_EventCollection_for_Binary1

                                                                        FindNextSelected_in_EventWriting_static1
                                                                        FindNextSelected_in_EventWriting_static3
                                                                    WriteOne_in_EventCollection_for_Binary2
*                                                                    **inspect_Binary**
*                                                                    @*boolean value= 1
*                                                                    @*Flags flags.value= 129
*                                                                    @*DNPTime timeDNPTime.value= 0
*                                                                    @*DNPTime timeDNPTime.quality= 0

                                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                                            **inspect_Binary**
*                                                                            @*boolean value= 1
*                                                                            @*Flags flags.value= 129
*                                                                            @*DNPTime timeDNPTime.value= 0
*                                                                            @*DNPTime timeDNPTime.quality= 0
@@@@                                                                            *write_in_UInt16_static = 6418035->0

                                                                                WriteTarget_in_Group2Var1_static1

                                                                                Write_in_Group2Var1_static1
*                                                                                *arg->flags= 129
@@@@                                                                            *write_in_UInt8_static = 6418037->129
                                                                    WriteOne_in_EventCollection_for_Binary3

                                                                    WriteOne_in_EventCollection_for_Binary1

                                                                        FindNextSelected_in_EventWriting_static1
                                                                        FindNextSelected_in_EventWriting_static3
                                                                    WriteOne_in_EventCollection_for_Binary2
*                                                                    **inspect_Binary**
*                                                                    @*boolean value= 0
*                                                                    @*Flags flags.value= 1
*                                                                    @*DNPTime timeDNPTime.value= 0
*                                                                    @*DNPTime timeDNPTime.quality= 0

                                                                        Write_in_BasicEventWriter_for_Binary_override1

                                                                            Write_in_PrefixedWriteIterator_for_UInt16_Binary1
*                                                                            **inspect_Binary**
*                                                                            @*boolean value= 0
*                                                                            @*Flags flags.value= 1
*                                                                            @*DNPTime timeDNPTime.value= 0
*                                                                            @*DNPTime timeDNPTime.quality= 0
@@@@                                                                            *write_in_UInt16_static = 6418038->0

                                                                                WriteTarget_in_Group2Var1_static1

                                                                                Write_in_Group2Var1_static1
*                                                                                *arg->flags= 1
@@@@                                                                            *write_in_UInt8_static = 6418040->1
                                                                    WriteOne_in_EventCollection_for_Binary3

                                                                    WriteOne_in_EventCollection_for_Binary1
                                                            Write_for_Binary_in_EventWriters_static2

                                                                PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary1
@@@@                                                                *write_in_UInt16_static = 6418033->2
*                                                    *(type->value).selectedVariation= 0
*                                                    *bBinary.tTypedMeasurement_for_Boolean.value= 1
*                                                    *bBinary.tTypedMeasurement_for_Boolean.mMeasurement.flags= 129
                                                    WriteSome_in_EventTypeImpl_TypedEventRecord_for_BinarySpec_override2
*                                            *uint16_t num_written =2

                                                WriteSome_in_EventWriting_static1
*                                                *lists->counters.selected= 0
*                                            *uint16_t num_written =0
                                            }Write_in_EventWriting_static1_

                                            NumSelected_in_EventStorage1
*                                            *(pEventStorage->state).counters.selected= 0
                                        }Load_in_EventBuffer_

                                        Load_in_Database1

                                        load_type_for_Analog_in_Database_static1
*                                        *map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_Binary_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_BinaryOutputStatus_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_AnalogOutputStatus_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_DoubleBitBinary_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_Counter_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 100
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 100
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())
                                    }HandleRead_in_OContext1_

                                    {ToByte_in_AppControlField1
*                                    *ret |= AppControlField_FIR_MASK
*                                    *ret |= AppControlField_FIN_MASK
*                                    *ret |= AppControlField_CON_MASK
                                    }ToByte_in_AppControlField_
                                    *uint8_t ret =224
                                    *uint8_t seq =1

                                    {SetControl_in_APDUWrapper1
@@@@                                    *write_uint8=6418026->225
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
@@@@                                    *write_uint8=6418028->128
@@@@                                    *write_uint8=6418029->0
                                    }SetIIN_in_APDUResponse_

                                    {BeginResponseTx_in_OContext1

                                        {CheckForBroadcastConfirmation_in_OContext1
                                        }CheckForBroadcastConfirmation_in_OContext_
*                                    *BeginResponseTx_in_OContext2
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-e1
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    @*buffer->buffer_[i]= 6418030<-2
*                                    @*buffer->buffer_[i]= 6418031<-1
*                                    @*buffer->buffer_[i]= 6418032<-28
*                                    @*buffer->buffer_[i]= 6418033<-2
*                                    @*buffer->buffer_[i]= 6418034<-0
*                                    @*buffer->buffer_[i]= 6418035<-0
*                                    @*buffer->buffer_[i]= 6418036<-0
*                                    @*buffer->buffer_[i]= 6418037<-81
*                                    @*buffer->buffer_[i]= 6418038<-0
*                                    @*buffer->buffer_[i]= 6418039<-0
*                                    @*buffer->buffer_[i]= 6418040<-1
*                                    *BeginResponseTx_in_OContext3
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-e1
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    @*buffer->buffer_[i]= 6418030<-2
*                                    @*buffer->buffer_[i]= 6418031<-1
*                                    @*buffer->buffer_[i]= 6418032<-28
*                                    @*buffer->buffer_[i]= 6418033<-2
*                                    @*buffer->buffer_[i]= 6418034<-0
*                                    @*buffer->buffer_[i]= 6418035<-0
*                                    @*buffer->buffer_[i]= 6418036<-0
*                                    @*buffer->buffer_[i]= 6418037<-81
*                                    @*buffer->buffer_[i]= 6418038<-0
*                                    @*buffer->buffer_[i]= 6418039<-0
*                                    @*buffer->buffer_[i]= 6418040<-1
*                                    *BeginResponseTx_in_OContext4
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 6418026<-e1
*                                    @*buffer->buffer_[i]= 6418027<-81
*                                    @*buffer->buffer_[i]= 6418028<-80
*                                    @*buffer->buffer_[i]= 6418029<-0
*                                    @*buffer->buffer_[i]= 6418030<-2
*                                    @*buffer->buffer_[i]= 6418031<-1
*                                    @*buffer->buffer_[i]= 6418032<-28
*                                    @*buffer->buffer_[i]= 6418033<-2
*                                    @*buffer->buffer_[i]= 6418034<-0
*                                    @*buffer->buffer_[i]= 6418035<-0
*                                    @*buffer->buffer_[i]= 6418036<-0
*                                    @*buffer->buffer_[i]= 6418037<-81
*                                    @*buffer->buffer_[i]= 6418038<-0
*                                    @*buffer->buffer_[i]= 6418039<-0
*                                    @*buffer->buffer_[i]= 6418040<-1

                                        {BeginTx_in_OContext1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-e1
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        @*buffer->buffer_[i]= 6418030<-2
*                                        @*buffer->buffer_[i]= 6418031<-1
*                                        @*buffer->buffer_[i]= 6418032<-28
*                                        @*buffer->buffer_[i]= 6418033<-2
*                                        @*buffer->buffer_[i]= 6418034<-0
*                                        @*buffer->buffer_[i]= 6418035<-0
*                                        @*buffer->buffer_[i]= 6418036<-0
*                                        @*buffer->buffer_[i]= 6418037<-81
*                                        @*buffer->buffer_[i]= 6418038<-0
*                                        @*buffer->buffer_[i]= 6418039<-0
*                                        @*buffer->buffer_[i]= 6418040<-1

{BeginTransmit_in_MockLowerLayer1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 6418026<-e1
*                                        @*buffer->buffer_[i]= 6418027<-81
*                                        @*buffer->buffer_[i]= 6418028<-80
*                                        @*buffer->buffer_[i]= 6418029<-0
*                                        @*buffer->buffer_[i]= 6418030<-2
*                                        @*buffer->buffer_[i]= 6418031<-1
*                                        @*buffer->buffer_[i]= 6418032<-28
*                                        @*buffer->buffer_[i]= 6418033<-2
*                                        @*buffer->buffer_[i]= 6418034<-0
*                                        @*buffer->buffer_[i]= 6418035<-0
*                                        @*buffer->buffer_[i]= 6418036<-0
*                                        @*buffer->buffer_[i]= 6418037<-81
*                                        @*buffer->buffer_[i]= 6418038<-0
*                                        @*buffer->buffer_[i]= 6418039<-0
*                                        @*buffer->buffer_[i]= 6418040<-1
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
*uint32_t duration= 10333
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
                    }OnReceiveSolRequest_in_OContext4_
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
*        CheckForTaskStart_in_OContext3

            {CheckForUnsolicited_in_OContext1

                {CanTransmit_in_OContext1
*                *pOContext->isOnline= 1
*                *pOContext->isTransmitting= 1
*                *boolean ret= 0
                }CanTransmit_in_OContext_
            }CheckForUnsolicited_in_OContext_
        }CheckForTaskStart_in_OContext_
    }OnReceive_in_OContext_
}SendToOutstation_in_OutstationTestObject_

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
}------------2
request2= C1 01 3C 02 06
REQUIRE('E1 81 80 00 02 01 28 02 00 00 00 81 00 00 01' == t.lower->PopWriteAsHex())
temp2= E1 81 80 00 02 01 28 02 00 00 00 81 00 00 01
