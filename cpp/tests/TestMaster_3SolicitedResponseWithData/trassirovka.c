********SUITE('3SolicitedResponseWithData')********

{MasterTestFixture_in_MasterTestFixture1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421512
}MockExecutor_in_MockExecutor_

{MasterSchedulerBackend_in_MasterSchedulerBackend1
}MasterSchedulerBackend_in_MasterSchedulerBackend_

    {MContext_in_MContext1

        {MasterTasks_in_MasterTasks1
        }MasterTasks_in_MasterTasks_

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *uint8_t bytes[SIZE_BufferSer4]=1764151542
    }MContext_in_MContext_

}MasterTestFixture_in_MasterTestFixture_

    {OnLowerLayerUp_in_MContext1
        {Initialize_in_MasterTasks1
        *Initialize_in_MasterTasks2

            {Add_in_MasterSchedulerBackend1

                {Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2_1
                }Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2__

                {PostCheckForTaskRun_in_MasterSchedulerBackend1
                *PostCheckForTaskRun_in_MasterSchedulerBackend2
                }PostCheckForTaskRun_in_MasterSchedulerBackend_
            }Add_in_MasterSchedulerBackend2_
        *Initialize_in_MasterTasks2

            {Add_in_MasterSchedulerBackend1

                {Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2_1
                }Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2__

                {PostCheckForTaskRun_in_MasterSchedulerBackend1
                }PostCheckForTaskRun_in_MasterSchedulerBackend_
            }Add_in_MasterSchedulerBackend2_
        *Initialize_in_MasterTasks2

            {Add_in_MasterSchedulerBackend1

                {Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2_1
                }Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2__

                {PostCheckForTaskRun_in_MasterSchedulerBackend1
                }PostCheckForTaskRun_in_MasterSchedulerBackend_
            }Add_in_MasterSchedulerBackend2_
        *Initialize_in_MasterTasks2

            {Add_in_MasterSchedulerBackend1

                {Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2_1
                }Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2__

                {PostCheckForTaskRun_in_MasterSchedulerBackend1
                }PostCheckForTaskRun_in_MasterSchedulerBackend_
            }Add_in_MasterSchedulerBackend2_
        }Initialize_in_MasterTasks_

OnOpen_in_MockMasterApplication1
    }OnLowerLayerUp_in_MContext2_

    {CheckForTaskRun_in_MasterSchedulerBackend1

        {cancel_in_TimerExe4cpp1
        *TimerExe4cpp *pTimerExe4cpp= 1764157996
        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
        }cancel_in_TimerExe4cpp1_
    *CheckForTaskRun_in_MasterSchedulerBackend3
*    *pMasterSchedulerBackend->tasks.size()= 4
    *CheckForTaskRun_in_MasterSchedulerBackend4

        {Run_in_MContext1
        *FORMAT_LOG_BLOCK(logger, flags::INFO, 'Begining task: %s', this->activeTask->Name())

            {ResumeActiveTask_in_MContext1

                {BuildRequest_in_StartupIntegrityPoll1

                    {ToByte_in_AppControlField1
*                    *ret |= AppControlField_FIR_MASK
*                    *ret |= AppControlField_FIN_MASK
                    }ToByte_in_AppControlField_
                    *uint8_t ret =192
                    *uint8_t seq =0

                    {SetControl_in_APDUWrapper1
@@@@                    *write_uint8=1764151542->192
                    }SetControl_in_APDUWrapper_

                    {SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=1764151543->1
                    }SetFunction_in_APDUWrapper_

                    WriteClassHeaders_in_APDUBuilders_static1

                        WriteHeader_in_HeaderWriter1
*                        *id.group= 60
*                        *id.variation= 2
*                        *qc= 6
@@@@                        *write_in_UInt8_static = 1764151544->60
@@@@                        *write_in_UInt8_static = 1764151545->2
@@@@                        *write_in_UInt8_static = 1764151546->6

                        WriteHeader_in_HeaderWriter1
*                        *id.group= 60
*                        *id.variation= 3
*                        *qc= 6
@@@@                        *write_in_UInt8_static = 1764151547->60
@@@@                        *write_in_UInt8_static = 1764151548->3
@@@@                        *write_in_UInt8_static = 1764151549->6

                        WriteHeader_in_HeaderWriter1
*                        *id.group= 60
*                        *id.variation= 4
*                        *qc= 6
@@@@                        *write_in_UInt8_static = 1764151550->60
@@@@                        *write_in_UInt8_static = 1764151551->4
@@@@                        *write_in_UInt8_static = 1764151552->6

                        WriteHeader_in_HeaderWriter1
*                        *id.group= 60
*                        *id.variation= 1
*                        *qc= 6
@@@@                        *write_in_UInt8_static = 1764151553->60
@@@@                        *write_in_UInt8_static = 1764151554->1
@@@@                        *write_in_UInt8_static = 1764151555->6

                    {SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=1764151543->1
                    }SetFunction_in_APDUWrapper_

                    {ToByte_in_AppControlField1
*                    *ret |= AppControlField_FIR_MASK
*                    *ret |= AppControlField_FIN_MASK
                    }ToByte_in_AppControlField_
                    *uint8_t ret =192
                    *uint8_t seq =0

                    {SetControl_in_APDUWrapper1
@@@@                    *write_uint8=1764151542->192
                    }SetControl_in_APDUWrapper_
                }BuildRequest_in_StartupIntegrityPoll_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6421512

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6421512

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762687312
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421512
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_

                {Transmit_in_MContext1

{BeginTransmit_in_MockLowerLayer1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= c0
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 6
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 3
*                @*buffer->buffer_[i]= 6
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 4
*                @*buffer->buffer_[i]= 6
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 1
*                @*buffer->buffer_[i]= 6
}BeginTransmit_in_MockLowerLayer_
                }Transmit_in_MContext_
            }ResumeActiveTask_in_MContext2_
        }Run_in_MContext2_
    }CheckForTaskRun_in_MasterSchedulerBackend3_

{IntegrityPoll_in_APDUHexBuilders1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6419056

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6419056->192
    }SetControl_in_APDUWrapper_

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6419057->1
    }SetFunction_in_APDUWrapper_

    WriteClassHeaders_in_APDUBuilders_static1

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 2
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419058->60
@@@@        *write_in_UInt8_static = 6419059->2
@@@@        *write_in_UInt8_static = 6419060->6

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 3
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419061->60
@@@@        *write_in_UInt8_static = 6419062->3
@@@@        *write_in_UInt8_static = 6419063->6

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 4
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419064->60
@@@@        *write_in_UInt8_static = 6419065->4
@@@@        *write_in_UInt8_static = 6419066->6

        WriteHeader_in_HeaderWriter1
*        *id.group= 60
*        *id.variation= 1
*        *qc= 6
@@@@        *write_in_UInt8_static = 6419067->60
@@@@        *write_in_UInt8_static = 6419068->1
@@@@        *write_in_UInt8_static = 6419069->6

}IntegrityPoll_in_APDUHexBuilders_
stmp= C0 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
popstr= C0 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06

    {OnTxReady_in_MContext1

        {OnTransmitComplete_in_MContext1
        }OnTransmitComplete_in_MContext2_

        {CheckConfirmTransmit_in_MContext1
*        *pMContext->isSending= 0
*        *pMContext->confirmQueue.empty()= 1
        }CheckConfirmTransmit_in_MContext1_
    }OnTxReady_in_MContext2_

    {OnReceive_in_MContext1

        ParseResponse_in_APDUHeaderParser_static1
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= c0
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 1
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 2
*        @*buffer->buffer_[i]= 81

            {OnParsedHeader_in_MContext1

                {ProcessAPDU_in_MContext1

                    {ProcessResponse_in_MContext1

                        {OnResponseEvent_in_MContext1

                            {OnResponse_WaitForResponse_in_MContext1

                                {cancel_in_TimerExe4cpp1
                                *TimerExe4cpp *pTimerExe4cpp= 1764151444
                                *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6421512

                                    {cancel_in_ITimer1
                                    *pITimer->psource_in_ITimer= 6421512

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421512
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                                    }cancel_in_ITimer1
                                }cancel_in_TimerExe4cpp2_

                                IAPDUHandler_in_IAPDUHandler1
*                                *pIAPDUHandler= 6418144

                                @@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)
                                {Parse_in_APDUParser_static1
*                                **inspect_RSeq**
*                                @*buffer->buffer_[i]= 1
*                                @*buffer->buffer_[i]= 2
*                                @*buffer->buffer_[i]= 0
*                                @*buffer->buffer_[i]= 2
*                                @*buffer->buffer_[i]= 2
*                                @*buffer->buffer_[i]= 81

                                    @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                    {ParseSinglePass_in_APDUParser_static1
*                                    *IAPDUHandler* pHandler=0
*                                    *IWhiteList* pWhiteList=6418144
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 1
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 81
*                                    *copy
*                                    **inspect_RSeq**
*                                    @*buffer->buffer_[i]= 1
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 0
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 2
*                                    @*buffer->buffer_[i]= 81

                                        @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                        {ParseHeader_in_APDUParser_static1
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 1
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 81

                                            ParseObjectHeader_in_ObjectHeaderParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 0
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 81
@@@@                                            *read_in_UInt8_static = 6419122<-1
@@@@                                            *read_in_UInt8_static = 6419123<-2
@@@@                                            *read_in_UInt8_static = 6419124<-0

                                            GetRecord_in_GroupVariationRecord_static1
*                                            *uint8_t group= 1
*                                            *uint8_t variation= 2

                                                GetEnumAndType_in_GroupVariationRecord_static1
*                                                *uint8_t group= 1
*                                                *uint8_t variation= 2

                                                    GetType_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 1
*                                                    *uint8_t variation= 2
*                                                    *GroupVariationType_STATIC
*                                                *GroupVariation_uint16_t enumeration= 102

                                            @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                            {ParseQualifier_in_APDUParser_static1
*                                            *QualifierCode_uint8_t tmp =0
@@@@                                            *QualifierCode_UINT8_START_STOP*

                                                NumParser_in_NumParser1

                                                ParseHeader_in_RangeParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 81

                                                    ParseRange_in_NumParser1
@@@@                                                    *read_in_UInt8_static = 6419125<-2
@@@@                                                    *read_in_UInt8_static = 6419126<-2
*                                                    *ParseResult_uint8_t res = 0
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 81
*                                                    *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                    *record.group= 1
*                                                    *record.variation= 2
*                                                    *record.enumeration= 258
*                                                    *record.GetQualifierCode()= 0
*                                                    *range.start= 2
*                                                    *range.stop= 2

                                                    ParseRangeOfObjects_in_RangeParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 81
*                                                    *GroupVariation_Group1Var2

                                                    FromFixedSize_for_Group1Var2_in_RangeParser_static1
*                                                    *Count_in_Range(range)= 1
*                                                    *Size_in_Group1Var2_static()= 1

                                                    Process_in_RangeParser1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 81
                                                }ParseQualifier_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseHeader_in_APDUParser_static4_
*                                            *ParseResult_uint8_t tmp= 0
                                        }ParseSinglePass_in_APDUParser_static2_

                                        @@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                        {ParseSinglePass_in_APDUParser_static1
*                                        *IAPDUHandler* pHandler=6418144
*                                        *IWhiteList* pWhiteList=0
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 1
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 81
*                                        *copy
*                                        **inspect_RSeq**
*                                        @*buffer->buffer_[i]= 1
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 0
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 2
*                                        @*buffer->buffer_[i]= 81

                                            @@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)
                                            {ParseHeader_in_APDUParser_static1
*                                            **inspect_RSeq**
*                                            @*buffer->buffer_[i]= 1
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 0
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 2
*                                            @*buffer->buffer_[i]= 81

                                                ParseObjectHeader_in_ObjectHeaderParser_static1
*                                                **inspect_RSeq**
*                                                @*buffer->buffer_[i]= 1
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 0
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 2
*                                                @*buffer->buffer_[i]= 81
@@@@                                                *read_in_UInt8_static = 6419122<-1
@@@@                                                *read_in_UInt8_static = 6419123<-2
@@@@                                                *read_in_UInt8_static = 6419124<-0

                                                GetRecord_in_GroupVariationRecord_static1
*                                                *uint8_t group= 1
*                                                *uint8_t variation= 2

                                                    GetEnumAndType_in_GroupVariationRecord_static1
*                                                    *uint8_t group= 1
*                                                    *uint8_t variation= 2

                                                        GetType_in_GroupVariationRecord_static1
*                                                        *uint8_t group= 1
*                                                        *uint8_t variation= 2
*                                                        *GroupVariationType_STATIC
*                                                    *GroupVariation_uint16_t enumeration= 102

                                                @@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)
                                                {ParseQualifier_in_APDUParser_static1
*                                                *QualifierCode_uint8_t tmp =0
@@@@                                                *QualifierCode_UINT8_START_STOP*

                                                    NumParser_in_NumParser1

                                                    ParseHeader_in_RangeParser_static1
*                                                    **inspect_RSeq**
*                                                    @*buffer->buffer_[i]= 2
*                                                    @*buffer->buffer_[i]= 2
*                                                    @*buffer->buffer_[i]= 81

                                                        ParseRange_in_NumParser1
@@@@                                                        *read_in_UInt8_static = 6419125<-2
@@@@                                                        *read_in_UInt8_static = 6419126<-2
*                                                        *ParseResult_uint8_t res = 0
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 81
*                                                        *FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*
*                                                        *record.group= 1
*                                                        *record.variation= 2
*                                                        *record.enumeration= 258
*                                                        *record.GetQualifierCode()= 0
*                                                        *range.start= 2
*                                                        *range.stop= 2

                                                        ParseRangeOfObjects_in_RangeParser_static1
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 81
*                                                        *GroupVariation_Group1Var2

                                                        FromFixedSize_for_Group1Var2_in_RangeParser_static1
*                                                        *Count_in_Range(range)= 1
*                                                        *Size_in_Group1Var2_static()= 1

                                                        Process_in_RangeParser1
*                                                        **inspect_RSeq**
*                                                        @*buffer->buffer_[i]= 81

                                                            OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler1

                                                            {LoadValues_for_Binary_in_MeasurementHandler1

{RecordAny_for_Binary_in_MockSOEHandler1
@@@@                                                            *read_in_UInt8_static = 6419127<-129

{process_for_Binary_in_MockSOEHandler1
*pair->index= 2

}process_for_Binary_in_MockSOEHandler_
}RecordAny_for_Binary_in_MockSOEHandler_
                                                            }LoadValues_for_Binary_in_MeasurementHandler_

                                                            {Record_in_IAPDUHandler1
                                                            *Record_in_IAPDUHandler2
                                                            *Record_in_IAPDUHandler3

                                                                {OnHeaderResult_in_IAPDUHandler1
                                                                }OnHeaderResult_in_IAPDUHandler_
                                                            }Record_in_IAPDUHandler_
                                                    }ParseQualifier_in_APDUParser_static4_
*                                                    *ParseResult_uint8_t tmp= 0
                                                }ParseHeader_in_APDUParser_static4_
*                                                *ParseResult_uint8_t tmp= 0
                                            }ParseSinglePass_in_APDUParser_static2_
                                        }Parse_in_APDUParser_static_

                                        {Add_in_MasterSchedulerBackend1

                                            {Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2_1
                                            }Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2__

                                            {PostCheckForTaskRun_in_MasterSchedulerBackend1
                                            *PostCheckForTaskRun_in_MasterSchedulerBackend2
                                            }PostCheckForTaskRun_in_MasterSchedulerBackend_
                                        }Add_in_MasterSchedulerBackend2_

                                        {PostCheckForTaskRun_in_MasterSchedulerBackend1
                                        }PostCheckForTaskRun_in_MasterSchedulerBackend_
                                    }OnResponse_WaitForResponse_in_MContext4_
                                }OnResponseEvent_in_MContext1_
                                }ProcessResponse_in_MContext_
                                }ProcessAPDU_in_MContext_
                            }OnParsedHeader_in_MContext_
                        }OnReceive_in_MContext5_
----REQUIRE(t.meas->TotalReceived() == 1)
dtmp= 1
----REQUIRE((Binary(true, Flags(0x01)) == t.meas->binarySOE[2].meas))
*                    **inspect_Binary**
*                    @*boolean value= 1
*                    @*Flags flags.value= 129
*                    @*DNPTime timeDNPTime.value= 0
*                    @*DNPTime timeDNPTime.quality= 0
