********SUITE('14ReadGrp22Var0')********

DatabaseConfig_in_DatabaseConfig1
OutstationTestObject_in_OutstationTestObject1

+    OContext_in_OContext1

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
*        *config.size()= 5

        StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2_1
*        *config.size()= 5

        StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*        *config.size()= 5

        DeferredRequest_in_DeferredRequest1
*        *uint32_t maxAPDUSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048

        TxBuffer_in_TxBuffer1
*        *uint32_t maxTxSize =2048

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048

        StateIdle_in_StateIdle1

        OutstationState_in_OutstationState1
LowerLayerUp_in_OutstationTestObject1

+    OnLowerLayerUp_in_OContext1

+        CheckForTaskStart_in_OContext1
+        CheckForTaskStart_in_OContext2

+            CheckForUnsolicitedNull_in_OContext1

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
+        CheckForTaskStart_in_OContext3

+            CheckForUnsolicited_in_OContext1

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
update_in_14ReadGrp22Var0

    Update_for_Counter_in_Database1
*    *EventMode_uint8_t mode= 0

        update_in_StaticDataMap_for_CounterSpecOver2_1
*        *inspect_Counter(new_value)
*        **inspect_Counter**
*        *boolean value= 0
*        *Flags flags.value= 1
*        *DNPTime timeDNPTime.value= 6411860
*        *DNPTime timeDNPTime.quality= 200
*
*        *EventMode_uint8_t mode= 0
*        *EventMode_Force= 1
*        *EventMode_EventOnly= 3
        update_in_StaticDataMap_for_CounterSpecOver2_2
*        *inspect_Counter(&old_value)
*        **inspect_Counter**
*        *boolean value= 0
*        *Flags flags.value= 2
*        *DNPTime timeDNPTime.value= 6411144
*        *DNPTime timeDNPTime.quality= 1
        update_in_StaticDataMap_for_CounterSpecOver2_3
        update_in_StaticDataMap_for_CounterSpecOver2_4

            convert_to_event_class_in_StaticDataMap_static1
*            *PointClass_uint8_t pc= 2
*            *PointClass_Class1= 2
*            *PointClass_Class2= 4
*            *PointClass_Class3= 8

            Instance_in_EventTypeImpl_TypedEventRecord_for_CounterSpec_static1

+    HandleNewEvents_in_OContext1

+        CheckForTaskStart_in_OContext1
+        CheckForTaskStart_in_OContext2

+            CheckForUnsolicitedNull_in_OContext1

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
+        CheckForTaskStart_in_OContext3

+            CheckForUnsolicited_in_OContext1

                IsIdle_in_OutstationState1

                IsIdle_in_StateIdle_override1
SendToOutstation_in_OutstationTestObject1

+    OnReceive_in_OContext1

+        ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)

            ParseRequest_in_APDUHeaderParser_static1
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  16
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  6
            ParseRequest_in_APDUHeaderParser_static3

+            ProcessObjects_in_OContext1

+                ProcessRequest_in_OContext1

+                    OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext8

+                        ProcessNewRequest_in_OContext1
@@@@                        *FunctionCode_READ

                            OnNewReadRequest_in_StateIdle_override1

+                            RespondToReadRequest_in_OContext1

+                                HandleRead_in_OContext1
*                                *buffer->buffer_[i]=  16
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  6
                                HandleRead_in_OContext2

                                    Unselect_in_EventStorage1

                                        Foreach_in_List_for_EventRecord1

                                            Iterate_in_List_for_EventRecord1
*                                            *pList_for_EventRecord->head= 6412496

                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                *Node_for_EventRecord* start= 6412496

                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                *Node_for_EventRecord* start= 6412496
                                HandleRead_in_OContext3
                                HandleRead_in_OContext4

                                    ReadHandler_in_ReadHandler1

                                    IAPDUHandler_in_IAPDUHandler1
*                                    *pIAPDUHandler= 6410044

                                    Parse_in_APDUParser_static1
*                                    *buffer->buffer_[i]=  16
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6

                                        ParseSinglePass_in_APDUParser_static1
*                                        *IAPDUHandler* pHandler=0
*                                        *IWhiteList* pWhiteList=6410044
*                                        *buffer->buffer_[i]=  16
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6
*                                        *copy
*                                        *buffer->buffer_[i]=  16
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            ParseHeader_in_APDUParser_static1
*                                            *buffer->buffer_[i]=  16
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6

                                                ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                *buffer->buffer_[i]=  16
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  6
                                            ParseHeader_in_APDUParser_static2

                                                GetRecord_in_GroupVariationRecord_static1
*                                                *uint8_t group= 22
*                                                *uint8_t variation= 0

                                                    GetEnumAndType_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 22
*                                                    *uint8_t variation= 0

                                                        GetType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 22
*                                                        *uint8_t variation= 0
*                                                        *GroupVariationType_EVENT
*                                                    *GroupVariation_uint16_t enumeration= 1600
                                            ParseHeader_in_APDUParser_static3
                                            ParseHeader_in_APDUParser_static4

                                            ParseQualifier_in_APDUParser_static1
*                                            *QualifierCode_uint8_t tmp =6
@@@@                                            *QualifierCode_ALL_OBJECTS*

                                            HandleAllObjectsHeader_in_APDUParser_static1
*                                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                            *record->gGroupVariationRecord.group=22
*                                            *record->gGroupVariationRecord.variation=0
*                                            *record->gGroupVariationRecord.enumeration=1600
*                                            *IAPDUHandler* pHandler=0
                                    Parse_in_APDUParser_static2

                                    ParseSinglePass_in_APDUParser_static1
*                                    *IAPDUHandler* pHandler=6410044
*                                    *IWhiteList* pWhiteList=0
*                                    *buffer->buffer_[i]=  16
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6
*                                    *copy
*                                    *buffer->buffer_[i]=  16
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6

                                        ParseHeader_in_APDUParser_static1
*                                        *buffer->buffer_[i]=  16
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  6

                                            ParseObjectHeader_in_ObjectHeaderParser_static1
*                                            *buffer->buffer_[i]=  16
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  6
                                        ParseHeader_in_APDUParser_static2

                                            GetRecord_in_GroupVariationRecord_static1
*                                            *uint8_t group= 22
*                                            *uint8_t variation= 0

                                                GetEnumAndType_in_GroupVariationRecord_static1
*                                                *uint8_t group= 22
*                                                *uint8_t variation= 0

                                                    GetType_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 22
*                                                    *uint8_t variation= 0
*                                                    *GroupVariationType_EVENT
*                                                *GroupVariation_uint16_t enumeration= 1600
                                        ParseHeader_in_APDUParser_static3
                                        ParseHeader_in_APDUParser_static4

                                        ParseQualifier_in_APDUParser_static1
*                                        *QualifierCode_uint8_t tmp =6
@@@@                                        *QualifierCode_ALL_OBJECTS*

                                        HandleAllObjectsHeader_in_APDUParser_static1
*                                        ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                        *record->gGroupVariationRecord.group=22
*                                        *record->gGroupVariationRecord.variation=0
*                                        *record->gGroupVariationRecord.enumeration=1600
*                                        *IAPDUHandler* pHandler=6410044
                                        HandleAllObjectsHeader_in_APDUParser_static2

                                            OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                            ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                            *(header->hHeaderRecord).gGroupVariationRecord.type= 1
@@@@                                            *GroupVariationType_EVENT

                                                SelectMaxCount_in_EventBuffer1
*                                                *uint32_t maximum= 4294967295
*                                                *GroupVariation_Group22Var0

                                                SelectByTypeGeneric_for_CounterSpec_in_EventSelection_static1

                                                    select__for__TypedEventRecord_for_CounterSpec_in_EventSelection1
*                                                    *uint32_t num_selected= 0
*                                                    *uint32_t maxEv= 65535

                                                        OnSelect_in_EventClassCounters1

                                            Record_in_IAPDUHandler1
                                HandleRead_in_OContext5
*                                *ParseResult_uint8_t result =0

                                    Load_in_EventBuffer1

                                        Write_in_EventWriting_static1

                                            Iterate_in_List_for_EventRecord1
*                                            *pList_for_EventRecord->head= 6412496

                                                From__in__Iterator_in_List_for_EventRecord_static1
*                                                *Node_for_EventRecord* start= 6412496

                                                Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord1
*                                                *Node_for_EventRecord* start= 6412496

                                            WriteSome_in_EventWriting_static1
*                                            *lists->counters.selected= 1
                                            WriteSome_in_EventWriting_static2
                                            WriteSome_in_EventWriting_static3

                                                WriteHeaderWithReserve_in_HeaderWriter1
*                                                *qc= 40
*                                                *reserve= 9

                                                WriteHeader_in_HeaderWriter1
*                                                *id.group= 22
*                                                *id.variation= 1
*                                                *qc= 40

                                                PrefixedWriteIterator_for_UInt16_Counter_in_PrefixedWriteIterator_for_UInt16_CounterOver2_1

                                                FindNextSelected_in_EventWriting_static1

                                                PrefixedWriteIterator_for_UInt16_Counter_destr_PrefixedWriteIterator_for_UInt16_Counter1
*                                        *uint16_t num_written =1

                                            WriteSome_in_EventWriting_static1
*                                            *lists->counters.selected= 0
*                                        *uint16_t num_written =0

                                            NumSelected_in_EventStorage1
*                                            *(pEventStorage->state).counters.selected= 0
*                                        *boolean tmp= 1

                                        Load_in_Database1

                                        load_type_for_Analog_in_Database_static1
*                                        *map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_Binary_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_BinaryOutputStatus_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_AnalogOutputStatus_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_DoubleBitBinary_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_Counter_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_FrozenCounter_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_OctetString_in_Database_static1
*                                        *map.map.size()= 5
*                                        *if (iter == map.end())

                                        load_type_for_TimeAndInterval_in_Database_static1
*                                        *map.map.size()= 5
                                        load_type_for_TimeAndInterval_in_Database_static2
*                                        *if (iter == map.end())

+                                    GetResponseIIN_in_OContext1
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

+                                    BeginResponseTx_in_OContext1

+                                        CheckForBroadcastConfirmation_in_OContext1

                                    StateSolicitedConfirmWait_in_StateSolicitedConfirmWait1

                                    OutstationState_in_OutstationState1

+        CheckForTaskStart_in_OContext1
+        CheckForTaskStart_in_OContext2

+            CheckForUnsolicitedNull_in_OContext1
+        CheckForTaskStart_in_OContext3

+            CheckForUnsolicited_in_OContext1
temp=     E0 81 80 00 16 01 28 01 00 00 00 01 00 00 00 00
response= E0 81 80 00 16 01 28 01 00 00 00 01 00 00 00 00
