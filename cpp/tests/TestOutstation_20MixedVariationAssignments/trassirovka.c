********SUITE('20MixedVariationAssignments')********

OContext_in_OContext1
    TotalEvents_in_EventBufferConfig1
*    *pEventBufferConfig->maxBinaryEvents= 0
*    *pEventBufferConfig->maxDoubleBinaryEvents=0
*    *pEventBufferConfig->maxAnalogEvents= 0
*    *pEventBufferConfig->maxCounterEvents= 0
*    *pEventBufferConfig->maxBinaryOutputStatusEvents= 0
*    *pEventBufferConfig->maxAnalogOutputStatusEvents= 0
*    *pEventBufferConfig->maxOctetStringEvents= 0

    Database_in_Database1

    StateIdle_in_StateIdle1

    OnReceive_in_OContext1

        ProcessMessage_in_OContext1
*        *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)

            ParseRequest_in_APDUHeaderParser_static1
*            *buffer->buffer_[i]=  c0
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  3c
*            *buffer->buffer_[i]=  1
*            *buffer->buffer_[i]=  6
            ParseRequest_in_APDUHeaderParser_static3

            ProcessObjects_in_OContext1

                ProcessRequest_in_OContext1

                    OnReceiveSolRequest_in_OContext1
                    OnReceiveSolRequest_in_OContext8

                    ProcessNewRequest_in_OContext1

                    OnNewReadRequest_in_StateIdle_override1

                    RespondToReadRequest_in_OContext1

                    HandleRead_in_OContext1
*                    *buffer->buffer_[i]=  3c
*                    *buffer->buffer_[i]=  1
*                    *buffer->buffer_[i]=  6
                        ReadHandler_in_ReadHandler1
                        IAPDUHandler_in_IAPDUHandler1
*                        *pIAPDUHandler= 6410248

                        Parse_in_APDUParser_static1
*                        *buffer->buffer_[i]=  3c
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  6

                            ParseSinglePass_in_APDUParser_static1
*                            *IAPDUHandler* pHandler=0
*                            *IWhiteList* pWhiteList=6410248
*                            *buffer->buffer_[i]=  3c
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  6
*                            *buffer->buffer_[i]=  3c
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  6

                                ParseHeader_in_APDUParser_static1
*                                *buffer->buffer_[i]=  3c
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  6

                                    ParseObjectHeader_in_ObjectHeaderParser_static1

                                    GetRecord_in_GroupVariationRecord_static1
*                                    *uint8_t group= 60
*                                    *uint8_t variation= 1

                                    GetEnumAndType_in_GroupVariationRecord_static1
*                                    *uint8_t group= 60
*                                    *uint8_t variation= 1

                                    GetType_in_GroupVariationRecord_static1
*                                    *uint8_t group= 60
*                                    *uint8_t variation= 1
*                                    *GroupVariationType_STATIC

                                ParseQualifier_in_APDUParser_static1
*                                *IAPDUHandler* pHandler= 0
*                                *QualifierCode_uint8_t tmp =6
*                                *QualifierCode_ALL_OBJECTS*

                                HandleAllObjectsHeader_in_APDUParser_static1
*                                ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                *record->gGroupVariationRecord.group=60
*                                *record->gGroupVariationRecord.variation=1
*                                *record->gGroupVariationRecord.enumeration=15361
*                                *pHandler=0
*                            *ParseResult_uint8_t result =0
                        Parse_in_APDUParser_static2
*                        *ParseResult_uint8_t result =0

                        ParseSinglePass_in_APDUParser_static1
*                        *IAPDUHandler* pHandler=6410248
*                        *IWhiteList* pWhiteList=0
*                        *buffer->buffer_[i]=  3c
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  6
*                        *buffer->buffer_[i]=  3c
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  6

                            ParseHeader_in_APDUParser_static1
*                            *buffer->buffer_[i]=  3c
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  6

                                ParseObjectHeader_in_ObjectHeaderParser_static1

                                GetRecord_in_GroupVariationRecord_static1
*                                *uint8_t group= 60
*                                *uint8_t variation= 1

                                GetEnumAndType_in_GroupVariationRecord_static1
*                                *uint8_t group= 60
*                                *uint8_t variation= 1

                                GetType_in_GroupVariationRecord_static1
*                                *uint8_t group= 60
*                                *uint8_t variation= 1
*                                *GroupVariationType_STATIC

                            ParseQualifier_in_APDUParser_static1
*                            *IAPDUHandler* pHandler= 6410248
*                            *QualifierCode_uint8_t tmp =6
*                            *QualifierCode_ALL_OBJECTS*

                            HandleAllObjectsHeader_in_APDUParser_static1
*                            ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                            *record->gGroupVariationRecord.group=60
*                            *record->gGroupVariationRecord.variation=1
*                            *record->gGroupVariationRecord.enumeration=15361
*                            *pHandler=6410248
                            HandleAllObjectsHeader_in_APDUParser_static2

                                OnHeader_AllObjectsHeader_in_IAPDUHandler1
                                ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                *GroupVariationType_STATIC

                                SelectAll_in_Database1
*                                *GroupVariation_Group60Var1

select_all_in_StaticDataMap_for_AnalogSpecOver3_1
iter___
iter___
map.size=  2

                                Record_in_IAPDUHandler1
*                        *ParseResult_uint8_t result =0

                        get_for_AnalogSpec_in_StaticWriters_static1
*                        *StaticAnalogVariation_Group30Var1

                        WriteHeader_in_HeaderWriter1
*                        *id.group= 30
*                        *id.variation= 1
*                        *qc= 0

                        RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1

                        Apply_in_ConvertGroup30Var1_static1
*                        *src.value= 0
*                        *target.value= 0

                        Write_in_Group30Var1_static
*                        *arg->flags= 2
*                        *arg->value= 0

                        RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1

                        get_for_AnalogSpec_in_StaticWriters_static1
*                        *StaticAnalogVariation_Group30Var2

                        WriteHeader_in_HeaderWriter1
*                        *id.group= 1e
*                        *id.variation= 2
*                        *qc= 0

                        RangeWriteIterator_for_UInt8_Analog_in_RangeWriteIterator_for_UInt8_AnalogOver2_1

                        Write_in_Group30Var2_static
*                        *arg->flags= 2
*                        *arg->value= 0

                        RangeWriteIterator_for_UInt8_Analog_destr_RangeWriteIterator_for_UInt8_Analog1

                        GetResponseIIN_in_OContext1
                        BeginResponseTx_in_OContext1

                            CheckForBroadcastConfirmation_in_OContext1

                        StateIdle_in_StateIdle1
REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 1E 01 00 00 00 02 00 00 00 00 1E 02 00 01 01 02 00 00')
temp= C0 81 80 00 1E 01 00 00 00 02 00 00 00 00 1E 02 00 01 01 02 00 00
