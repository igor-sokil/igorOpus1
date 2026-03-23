********SUITE('31ReadGrp1Var0ViaIntegrity')********

OutstationTestObject_in_OutstationTestObject1

    OContext_in_OContext1

    EventLists_in_EventLists1
    TotalEvents_in_EventBufferConfig1
*    *pEventBufferConfig->maxBinaryEvents= 0
*    *pEventBufferConfig->maxDoubleBinaryEvents=0
*    *pEventBufferConfig->maxAnalogEvents= 0
*    *pEventBufferConfig->maxCounterEvents= 0
*    *pEventBufferConfig->maxBinaryOutputStatusEvents= 0
*    *pEventBufferConfig->maxAnalogOutputStatusEvents= 0
*    *pEventBufferConfig->maxOctetStringEvents= 0

    Database_in_Database1

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

    StateIdle_in_StateIdle1
*    *IsIdle_in_StateIdle_override= 1762945424

    OutstationState_in_OutstationState1
*    *pOutstationState= 1763605216
*    *IsIdle_in_OutstationState_override= 1762945024
1stack_info_OnLowerLayerUp_in_OContext=  0
1stack_info_CheckForTaskStart_in_OContext=  0
    CheckForTaskStart_in_OContext1
2stack_info_CheckForTaskStart_in_OContext=  1
    CheckForTaskStart_in_OContext2
*    *pOContext= 6412360
*    *pOContext->state= 1763605216

        CheckForUnsolicitedNull_in_OContext1
*        *pOContext= 6412360
*        *pOContext->state= 1763605216

            IsIdle_in_OutstationState1
*            *pOutstationState= 1763605216
*            *pIsIdle_in_OutstationState= 1762945424

                IsIdle_in_StateIdle_override1
            IsIdle_in_OutstationState2
        CheckForUnsolicitedNull_in_OContext8
3stack_info_CheckForTaskStart_in_OContext=  1
    CheckForTaskStart_in_OContext3
    CheckForTaskStart_in_OContext4

        CheckForUnsolicited_in_OContext1
*        *pOContext= 6412360
*        *pOContext->state= 1763605216

            IsIdle_in_OutstationState1
*            *pOutstationState= 1763605216
*            *pIsIdle_in_OutstationState= 1762945424

                IsIdle_in_StateIdle_override1
            IsIdle_in_OutstationState2
        CheckForTaskStart_in_OContext5
4stack_info_CheckForTaskStart_in_OContext=  1
2stack_info_OnLowerLayerUp_in_OContext=  1

        SendToOutstation_in_OutstationTestObject1

        OnReceive_in_OContext1
*        *pOContext= 6412360

            ProcessMessage_in_OContext1
*            *FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)

                ParseRequest_in_APDUHeaderParser_static1
*                *buffer->buffer_[i]=  c0
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  1
*                *buffer->buffer_[i]=  0
*                *buffer->buffer_[i]=  6
                ParseRequest_in_APDUHeaderParser_static3

                ProcessObjects_in_OContext1
*                *pOContext=6412360
*                *pOContext->state=1763605216

                    ProcessRequest_in_OContext1
*                    *pOContext= 6412360

                        OnReceiveSolRequest_in_OContext1
                        OnReceiveSolRequest_in_OContext8

                        ProcessNewRequest_in_OContext1

                        OnNewReadRequest_in_StateIdle_override1

                        RespondToReadRequest_in_OContext1
*                        *pOContext= 6412360
*                    *1RespondToReadRequest_in_OContext.pOContext= 6412360
*                    *2RespondToReadRequest_in_OContext.pOContext= 6412360
*                    *3RespondToReadRequest_in_OContext.pOContext= 6412360

                        HandleRead_in_OContext1
*                        *pOContext= 6412360
*                        *buffer->buffer_[i]=  1
*                        *buffer->buffer_[i]=  0
*                        *buffer->buffer_[i]=  6
*                        *1HandleRead_in_OContext.pOContext= 6412360
*                        *2HandleRead_in_OContext.pOContext= 6412360
*                        *3HandleRead_in_OContext.pOContext= 6412360

                            ReadHandler_in_ReadHandler1

                            IAPDUHandler_in_IAPDUHandler1
*                            *pIAPDUHandler= 6410072
*                        *4HandleRead_in_OContext.pOContext= 6412360

                            Parse_in_APDUParser_static1
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  6

                                ParseSinglePass_in_APDUParser_static1
*                                *IAPDUHandler* pHandler=0
*                                *IWhiteList* pWhiteList=6410072
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  6
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  6

                                    ParseHeader_in_APDUParser_static1
*                                    *buffer->buffer_[i]=  1
*                                    *buffer->buffer_[i]=  0
*                                    *buffer->buffer_[i]=  6

                                        ParseObjectHeader_in_ObjectHeaderParser_static1

                                        GetRecord_in_GroupVariationRecord_static1
*                                        *uint8_t group= 1
*                                        *uint8_t variation= 0

                                        GetEnumAndType_in_GroupVariationRecord_static1
*                                        *uint8_t group= 1
*                                        *uint8_t variation= 0

                                            GetType_in_GroupVariationRecord_static1
*                                            *uint8_t group= 1
*                                            *uint8_t variation= 0
*                                            *GroupVariationType_STATIC
*                                        *GroupVariation_uint16_t enumeration= 100

                                    ParseQualifier_in_APDUParser_static1
*                                    *IAPDUHandler* pHandler= 0
*                                    *QualifierCode_uint8_t tmp =6
*                                    *QualifierCode_ALL_OBJECTS*

                                    HandleAllObjectsHeader_in_APDUParser_static1
*                                    ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                    *record->gGroupVariationRecord.group=1
*                                    *record->gGroupVariationRecord.variation=0
*                                    *record->gGroupVariationRecord.enumeration=256
*                                    *pHandler=0
                            Parse_in_APDUParser_static2

                            ParseSinglePass_in_APDUParser_static1
*                            *IAPDUHandler* pHandler=6410072
*                            *IWhiteList* pWhiteList=0
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  6
*                            *buffer->buffer_[i]=  1
*                            *buffer->buffer_[i]=  0
*                            *buffer->buffer_[i]=  6

                                ParseHeader_in_APDUParser_static1
*                                *buffer->buffer_[i]=  1
*                                *buffer->buffer_[i]=  0
*                                *buffer->buffer_[i]=  6

                                    ParseObjectHeader_in_ObjectHeaderParser_static1

                                    GetRecord_in_GroupVariationRecord_static1
*                                    *uint8_t group= 1
*                                    *uint8_t variation= 0

                                    GetEnumAndType_in_GroupVariationRecord_static1
*                                    *uint8_t group= 1
*                                    *uint8_t variation= 0

                                        GetType_in_GroupVariationRecord_static1
*                                        *uint8_t group= 1
*                                        *uint8_t variation= 0
*                                        *GroupVariationType_STATIC
*                                    *GroupVariation_uint16_t enumeration= 100

                                ParseQualifier_in_APDUParser_static1
*                                *IAPDUHandler* pHandler= 6410072
*                                *QualifierCode_uint8_t tmp =6
*                                *QualifierCode_ALL_OBJECTS*

                                HandleAllObjectsHeader_in_APDUParser_static1
*                                ***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***
*                                *record->gGroupVariationRecord.group=1
*                                *record->gGroupVariationRecord.variation=0
*                                *record->gGroupVariationRecord.enumeration=256
*                                *pHandler=6410072
                                HandleAllObjectsHeader_in_APDUParser_static2

                                    OnHeader_AllObjectsHeader_in_IAPDUHandler1

                                    ProcessHeader_AllObjectsHeader_in_ReadHandler_override1
*                                    *GroupVariationType_STATIC

                                    SelectAll_in_Database1
*                                    *GroupVariation_Group1Var0

                                    Record_in_IAPDUHandler1
*                        *5HandleRead_in_OContext.pOContext= 6412360
*                        *6HandleRead_in_OContext.pOContext= 6412360

                            Load_in_Database1

                            WriteHeaderWithReserve_in_HeaderWriter1
*                            *qc= 0
*                            *reserve= 3

                            WriteHeader_in_HeaderWriter1
*                            *id.group= 1
*                            *id.variation= 2
*                            *qc= 0

RangeWriteIterator_for_UInt8_Binary_in_RangeWriteIterator_for_UInt8_BinaryOver2_1
*                        *7HandleRead_in_OContext.pOContext= 6412360
*                        *8HandleRead_in_OContext.pOContext= 6412360
*                    *4RespondToReadRequest_in_OContext.pOContext= 6412360
*                    *5RespondToReadRequest_in_OContext.pOContext= 6412360

                        GetResponseIIN_in_OContext1
*                        *pOContext= 6412360
*                        *pOContext->state= 1763605216
*                    *6RespondToReadRequest_in_OContext.GetResponseIIN_in_OContext(pOContext)= 6412360

                        BeginResponseTx_in_OContext1
*                        *pOContext= 6412360

                            CheckForBroadcastConfirmation_in_OContext1

                        StateIdle_in_StateIdle1
*                        *IsIdle_in_StateIdle_override= 1762945424

                        OutstationState_in_OutstationState1
*                        *pOutstationState= 1763605216
*                        *IsIdle_in_OutstationState_override= 1762945024
1stack_info_CheckForTaskStart_in_OContext=  4
                    CheckForTaskStart_in_OContext1
2stack_info_CheckForTaskStart_in_OContext=  5
                    CheckForTaskStart_in_OContext2
*                    *pOContext= 6412360
*                    *pOContext->state= 1763605216

                        CheckForUnsolicitedNull_in_OContext1
*                        *pOContext= 6412360
*                        *pOContext->state= 1763605216
                        CheckForUnsolicitedNull_in_OContext8
3stack_info_CheckForTaskStart_in_OContext=  5
                    CheckForTaskStart_in_OContext3
                    CheckForTaskStart_in_OContext4

                        CheckForUnsolicited_in_OContext1
*                        *pOContext= 6412360
*                        *pOContext->state= 1763605216
                        CheckForTaskStart_in_OContext5
4stack_info_CheckForTaskStart_in_OContext=  5
REQUIRE(t.lower->PopWriteAsHex() == response)
response= C0 81 80 00 01 02 00 00 00 02
temp=     C0 81 80 00 01 02 00 00 00 02
