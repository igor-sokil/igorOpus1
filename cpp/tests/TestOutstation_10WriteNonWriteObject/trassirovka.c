********SUITE('10WriteNonWriteObject')********

DatabaseConfig_in_DatabaseConfig1
OutstationTestObject_in_OutstationTestObject1

+    OContext_in_OContext1

        EventLists_in_EventLists1
        TotalEvents_in_EventBufferConfig1
*        *pEventBufferConfig->maxBinaryEvents= 0
*        *pEventBufferConfig->maxDoubleBinaryEvents=0
*        *pEventBufferConfig->maxAnalogEvents= 0
*        *pEventBufferConfig->maxCounterEvents= 0
*        *pEventBufferConfig->maxBinaryOutputStatusEvents= 0
*        *pEventBufferConfig->maxAnalogOutputStatusEvents= 0
*        *pEventBufferConfig->maxOctetStringEvents= 0

        List_for_EventRecord_in_List_for_EventRecordOver2_1
*        *uint32_t maxSize= 0

        List_for_EventRecord_in_List_for_EventRecordOver1_1

        Database_in_Database1

        StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2_1
*        *config.size()= 0

        StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2_1
*        *config.size()= 0

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
SendToOutstation_in_OutstationTestObject1

+    OnReceive_in_OContext1

+        ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)

            ParseRequest_in_APDUHeaderParser_static1
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  2
*            *buffer->buffer_[i]=  0
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  7
*            *buffer->buffer_[i]=  0
            ParseRequest_in_APDUHeaderParser_static3

+            ProcessObjects_in_OContext1

+                ProcessRequest_in_OContext1

+                    OnReceiveSolRequest_in_OContext1
*                    *analyze this request to see how it compares to the last request
                    OnReceiveSolRequest_in_OContext8

+                        ProcessNewRequest_in_OContext1

                            OnNewNonReadRequest_in_StateIdle_override1

+                            RespondToNonReadRequest_in_OContext1

                                SetFunction_in_APDUWrapper1
@@@@                                *write_uint8=6421539->129

                                SetControl_in_APDUWrapper1
@@@@                                *write_uint8=6421538->192

+                                HandleNonReadResponse_in_OContext1
*                                *FunctionCode_uint18_t function= 2
@@@@                                *FunctionCode_WRITE

+                                    HandleWrite_in_OContext1

                                        WriteHandler_in_WriteHandler1

                                        IAPDUHandler_in_IAPDUHandler1
*                                        *pIAPDUHandler= 6410000
                                    HandleWrite_in_OContext2

                                        Parse_in_APDUParser_static1
*                                        *buffer->buffer_[i]=  1
*                                        *buffer->buffer_[i]=  2
*                                        *buffer->buffer_[i]=  0
*                                        *buffer->buffer_[i]=  7
*                                        *buffer->buffer_[i]=  7
*                                        *buffer->buffer_[i]=  0

                                            ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=0
*                                            *IWhiteList* pWhiteList=6410000
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0
*                                            *copy
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0

                                                ParseHeader_in_APDUParser_static1
*                                                *buffer->buffer_[i]=  1
*                                                *buffer->buffer_[i]=  2
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    *buffer->buffer_[i]=  1
*                                                    *buffer->buffer_[i]=  2
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  0
                                                ParseHeader_in_APDUParser_static2

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 1
*                                                    *uint8_t variation= 2

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 1
*                                                        *uint8_t variation= 2

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 1
*                                                            *uint8_t variation= 2
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 102
                                                ParseHeader_in_APDUParser_static3
                                                ParseHeader_in_APDUParser_static4

                                                ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =0
@@@@                                                *QualifierCode_UINT8_START_STOP*

                                                NumParser_in_NumParser1

                                                ParseHeader_in_RangeParser_static1
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseRange_in_NumParser1
*                                                    *ParseResult_uint8_t res = 0
*                                                    *buffer->buffer_[i]=  0
*                                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                    *record.group= 1
*                                                    *record.variation= 2
*                                                    *record.enumeration= 258
*                                                    *record.GetQualifierCode()= 0
*                                                    *range.start= 7
*                                                    *range.stop= 7

                                                    ParseRangeOfObjects_in_RangeParser_static1
*                                                    *buffer->buffer_[i]=  0
*                                                    *GroupVariation_Group1Var2

                                                    FromFixedSize_for_Group1Var2_in_RangeParser_static1
*                                                    *Count_in_Range(range)= 1
*                                                    *Size_in_Group1Var2_static()= 1

                                                    Process_in_RangeParser1
*                                                    *buffer->buffer_[i]=  0
                                            Parse_in_APDUParser_static2

                                            ParseSinglePass_in_APDUParser_static1
*                                            *IAPDUHandler* pHandler=6410000
*                                            *IWhiteList* pWhiteList=0
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0
*                                            *copy
*                                            *buffer->buffer_[i]=  1
*                                            *buffer->buffer_[i]=  2
*                                            *buffer->buffer_[i]=  0
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  7
*                                            *buffer->buffer_[i]=  0

                                                ParseHeader_in_APDUParser_static1
*                                                *buffer->buffer_[i]=  1
*                                                *buffer->buffer_[i]=  2
*                                                *buffer->buffer_[i]=  0
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                    *buffer->buffer_[i]=  1
*                                                    *buffer->buffer_[i]=  2
*                                                    *buffer->buffer_[i]=  0
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  7
*                                                    *buffer->buffer_[i]=  0
                                                ParseHeader_in_APDUParser_static2

                                                    GetRecord_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 1
*                                                    *uint8_t variation= 2

                                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 1
*                                                        *uint8_t variation= 2

                                                            GetType_in_GroupVariationRecord_static1
*                                                            *uint8_t group= 1
*                                                            *uint8_t variation= 2
*                                                            *GroupVariationType_STATIC
*                                                        *GroupVariation_uint16_t enumeration= 102
                                                ParseHeader_in_APDUParser_static3
                                                ParseHeader_in_APDUParser_static4

                                                ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =0
@@@@                                                *QualifierCode_UINT8_START_STOP*

                                                NumParser_in_NumParser1

                                                ParseHeader_in_RangeParser_static1
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  7
*                                                *buffer->buffer_[i]=  0

                                                    ParseRange_in_NumParser1
*                                                    *ParseResult_uint8_t res = 0
*                                                    *buffer->buffer_[i]=  0
*                                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                    *record.group= 1
*                                                    *record.variation= 2
*                                                    *record.enumeration= 258
*                                                    *record.GetQualifierCode()= 0
*                                                    *range.start= 7
*                                                    *range.stop= 7

                                                    ParseRangeOfObjects_in_RangeParser_static1
*                                                    *buffer->buffer_[i]=  0
*                                                    *GroupVariation_Group1Var2

                                                    FromFixedSize_for_Group1Var2_in_RangeParser_static1
*                                                    *Count_in_Range(range)= 1
*                                                    *Size_in_Group1Var2_static()= 1

                                                    Process_in_RangeParser1
*                                                    *buffer->buffer_[i]=  0

                                                        OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler1

                                                        ProcessUnsupportedHeader_in_IAPDUHandler1
*                                                        *IINBit::FUNC_NOT_SUPPORTED

                                                        Record_in_IAPDUHandler1
                                            HandleWrite_in_OContext3
*                                            *ParseResult_uint8_t result =0

+                                        GetResponseIIN_in_OContext1
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

                                        SetIIN_in_APDUResponse1
@@@@                                        *write_uint8=6421540->128
@@@@                                        *write_uint8=6421541->1

+                                        BeginResponseTx_in_OContext1

+                                            CheckForBroadcastConfirmation_in_OContext1

                                        StateIdle_in_StateIdle1

                                        OutstationState_in_OutstationState1

+            CheckForTaskStart_in_OContext1
+            CheckForTaskStart_in_OContext2

+                CheckForUnsolicitedNull_in_OContext1
+            CheckForTaskStart_in_OContext3

+                CheckForUnsolicited_in_OContext1
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 01')
temp=                                C0 81 80 01
