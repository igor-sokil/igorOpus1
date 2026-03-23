********SUITE('3SolicitedResponseWithData')********

{AllEventClasses_in_ClassField_static1
***inspect_ClassField**
*@*uint8_t bitfield= 14
}AllEventClasses_in_ClassField_static_

{MasterTestFixture_in_MasterTestFixture1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421512
}MockExecutor_in_MockExecutor_

    {MasterSchedulerBackend_in_MasterSchedulerBackend1
    }MasterSchedulerBackend_in_MasterSchedulerBackend_

    {MContext_in_MContext1

        {MasterTasks_in_MasterTasks1

            {GetDisableUnsolTask_in_MasterTasks_static1

                {DisableUnsolicitedTask_in_DisableUnsolicitedTask1
                }DisableUnsolicitedTask_in_DisableUnsolicitedTask_
            }GetDisableUnsolTask_in_MasterTasks_static1_
        }MasterTasks_in_MasterTasks_

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *uint8_t bytes[SIZE_BufferSer4]=1764167926
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
        *TimerExe4cpp *pTimerExe4cpp= 1764174380
        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
        }cancel_in_TimerExe4cpp1_
    *CheckForTaskRun_in_MasterSchedulerBackend3
*    *pMasterSchedulerBackend->tasks.size()= 6
    *CheckForTaskRun_in_MasterSchedulerBackend4

        {Run_in_MContext1
*        *pMContext->activeTask= 0
*        *pMContext->tstate= 0
*        *TaskState_in_MContext_IDLE= 0
        *FORMAT_LOG_BLOCK(logger, flags::INFO, 'Begining task: %s', this->activeTask->Name())
        Name_in_IMasterTask(pMContext->activeTask)= DisableUnsolicitedTask

            {ResumeActiveTask_in_MContext1

                {BuildRequest_in_DisableUnsolicitedTask1

                    {AllEventClasses_in_ClassField_static1
*                    **inspect_ClassField**
*                    @*uint8_t bitfield= 14
                    }AllEventClasses_in_ClassField_static_

                    {ClassRequest_in_APDUBuilders_static1
*                    **inspect_ClassField**
*                    @*uint8_t bitfield= 14

                        {ToByte_in_AppControlField1
*                        *ret |= AppControlField_FIR_MASK
*                        *ret |= AppControlField_FIN_MASK
                        }ToByte_in_AppControlField_
                        *uint8_t ret =192
                        *uint8_t seq =0

                        {SetControl_in_APDUWrapper1
@@@@                        *write_uint8=1764167926->192
                        }SetControl_in_APDUWrapper_

                        {SetFunction_in_APDUWrapper1
@@@@                        *write_uint8=1764167927->21
                        }SetFunction_in_APDUWrapper_

                        WriteClassHeaders_in_APDUBuilders_static1

                            WriteHeader_in_HeaderWriter1
*                            *id.group= 60
*                            *id.variation= 2
*                            *qc= 6
@@@@                            *write_in_UInt8_static = 1764167928->60
@@@@                            *write_in_UInt8_static = 1764167929->2
@@@@                            *write_in_UInt8_static = 1764167930->6

                            WriteHeader_in_HeaderWriter1
*                            *id.group= 60
*                            *id.variation= 3
*                            *qc= 6
@@@@                            *write_in_UInt8_static = 1764167931->60
@@@@                            *write_in_UInt8_static = 1764167932->3
@@@@                            *write_in_UInt8_static = 1764167933->6

                            WriteHeader_in_HeaderWriter1
*                            *id.group= 60
*                            *id.variation= 4
*                            *qc= 6
@@@@                            *write_in_UInt8_static = 1764167934->60
@@@@                            *write_in_UInt8_static = 1764167935->4
@@@@                            *write_in_UInt8_static = 1764167936->6
                    }ClassRequest_in_APDUBuilders_static_
                }BuildRequest_in_DisableUnsolicitedTask_

                {StartResponseTimer_in_MContext1

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6421512

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6421512

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762687680
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421512
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
                }StartResponseTimer_in_MContext_

                {Transmit_in_MContext1

{BeginTransmit_in_MockLowerLayer1
*                **inspect_RSeq**
*                @*buffer->buffer_[i]= c0
*                @*buffer->buffer_[i]= 15
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 2
*                @*buffer->buffer_[i]= 6
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 3
*                @*buffer->buffer_[i]= 6
*                @*buffer->buffer_[i]= 3c
*                @*buffer->buffer_[i]= 4
*                @*buffer->buffer_[i]= 6
}BeginTransmit_in_MockLowerLayer_
                }Transmit_in_MContext_
            }ResumeActiveTask_in_MContext2_
        }Run_in_MContext2_
    }CheckForTaskRun_in_MasterSchedulerBackend3_

    {AllEventClasses_in_ClassField_static1
*    **inspect_ClassField**
*    @*uint8_t bitfield= 14
    }AllEventClasses_in_ClassField_static_
***inspect_ClassField**
*@*uint8_t bitfield= 14

{ClassTask_in_APDUHexBuilders1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6419120

    {ClassRequest_in_APDUBuilders_static1
*    **inspect_ClassField**
*    @*uint8_t bitfield= 14

        {ToByte_in_AppControlField1
*        *ret |= AppControlField_FIR_MASK
*        *ret |= AppControlField_FIN_MASK
        }ToByte_in_AppControlField_
        *uint8_t ret =192
        *uint8_t seq =0

        {SetControl_in_APDUWrapper1
@@@@        *write_uint8=6419120->192
        }SetControl_in_APDUWrapper_

        {SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6419121->21
        }SetFunction_in_APDUWrapper_

        WriteClassHeaders_in_APDUBuilders_static1

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 2
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419122->60
@@@@            *write_in_UInt8_static = 6419123->2
@@@@            *write_in_UInt8_static = 6419124->6

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 3
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419125->60
@@@@            *write_in_UInt8_static = 6419126->3
@@@@            *write_in_UInt8_static = 6419127->6

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 4
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419128->60
@@@@            *write_in_UInt8_static = 6419129->4
@@@@            *write_in_UInt8_static = 6419130->6
    }ClassRequest_in_APDUBuilders_static_
}ClassTask_in_APDUHexBuilders_
stmp= C0 15 3C 02 06 3C 03 06 3C 04 06

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
popstr= C0 15 3C 02 06 3C 03 06 3C 04 06

    {OnTxReady_in_MContext1

        {OnTransmitComplete_in_MContext1
        }OnTransmitComplete_in_MContext2_

        {CheckConfirmTransmit_in_MContext1
*        *pMContext->isSending= 0
*        *pMContext->confirmQueue.empty()= 1
        }CheckConfirmTransmit_in_MContext1_
    }OnTxReady_in_MContext2_

{EmptyResponse_in_APDUHexBuilders1
*uint8_t seq= 0

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6419136

    {SetFunction_in_APDUWrapper1
@@@@    *write_uint8=6419137->129
    }SetFunction_in_APDUWrapper_

    {ToByte_in_AppControlField1
*    *ret |= AppControlField_FIR_MASK
*    *ret |= AppControlField_FIN_MASK
    }ToByte_in_AppControlField_
    *uint8_t ret =192
    *uint8_t seq =0

    {SetControl_in_APDUWrapper1
@@@@    *write_uint8=6419136->192
    }SetControl_in_APDUWrapper_

    {SetIIN_in_APDUResponse1
@@@@    *write_uint8=6419138->0
@@@@    *write_uint8=6419139->0
    }SetIIN_in_APDUResponse_
}EmptyResponse_in_APDUHexBuilders_
----SendToMaster_in_MasterTestFixture

    {OnReceive_in_MContext1

        ParseResponse_in_APDUHeaderParser_static1
*        **inspect_RSeq**
*        @*buffer->buffer_[i]= c0
*        @*buffer->buffer_[i]= 81
*        @*buffer->buffer_[i]= 0
*        @*buffer->buffer_[i]= 0

            {OnParsedHeader_in_MContext1

                {ProcessAPDU_in_MContext1
*                *header->aAPDUHeader.function= 129
*                **inspect_RSeq**
*                @@@@FunctionCode_RESPONSE

                    {ProcessResponse_in_MContext1
*                    **inspect_IINField**
*                    @*uint8_t LSB= 0
*                    @*uint8_t MSB= 0

                        {OnResponseEvent_in_MContext1
*                        *pMContext->tstate= 2
*                        @@@@TaskState_in_MContext_WAIT_FOR_RESPONSE

                            {OnResponse_WaitForResponse_in_MContext1

                                {cancel_in_TimerExe4cpp1
                                *TimerExe4cpp *pTimerExe4cpp= 1764167828
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

                                {OnResponse_in_IMasterTask1
                                Name_in_IMasterTask(pIMasterTask)= DisableUnsolicitedTask

                                    {ProcessResponse_in_DisableUnsolicitedTask1
*                                    *ResponseResult_in_IMasterTask_uint8_t tmp=1
*                                    *ResponseResult_in_IMasterTask_OK_FINAL=1
*                                    *ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE=0
                                    }ProcessResponse_in_DisableUnsolicitedTask_
                                *OnResponse_in_IMasterTask2
                                }OnResponse_in_IMasterTask_
                            *OnResponse_WaitForResponse_in_MContext3

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

                        {ProcessIIN_in_MContext1
*                        **inspect_IINField**
*                        @*uint8_t LSB= 0
*                        @*uint8_t MSB= 0
                        }ProcessIIN_in_MContext_
                    }ProcessResponse_in_MContext_
                }ProcessAPDU_in_MContext_
            }OnParsedHeader_in_MContext_
        }OnReceive_in_MContext5_
emptyStr= C0 81 00 00

        {CheckForTaskRun_in_MasterSchedulerBackend1

            {cancel_in_TimerExe4cpp1
            *TimerExe4cpp *pTimerExe4cpp= 1764174380
            *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
            }cancel_in_TimerExe4cpp1_
        *CheckForTaskRun_in_MasterSchedulerBackend3
*        *pMasterSchedulerBackend->tasks.size()= 7
        *CheckForTaskRun_in_MasterSchedulerBackend4

            {Run_in_MContext1
*            *pMContext->activeTask= 0
*            *pMContext->tstate= 0
*            *TaskState_in_MContext_IDLE= 0
            *FORMAT_LOG_BLOCK(logger, flags::INFO, 'Begining task: %s', this->activeTask->Name())
            Name_in_IMasterTask(pMContext->activeTask)= StartupIntegrityPoll

                {ResumeActiveTask_in_MContext1

                    {BuildRequest_in_StartupIntegrityPoll1

                        {ClassRequest_in_APDUBuilders_static1
*                        **inspect_ClassField**
*                        @*uint8_t bitfield= 15

                            {ToByte_in_AppControlField1
*                            *ret |= AppControlField_FIR_MASK
*                            *ret |= AppControlField_FIN_MASK
                            }ToByte_in_AppControlField_
                            *uint8_t ret =192
                            *uint8_t seq =1

                            {SetControl_in_APDUWrapper1
@@@@                            *write_uint8=1764167926->193
                            }SetControl_in_APDUWrapper_

                            {SetFunction_in_APDUWrapper1
@@@@                            *write_uint8=1764167927->1
                            }SetFunction_in_APDUWrapper_

                            WriteClassHeaders_in_APDUBuilders_static1

                                WriteHeader_in_HeaderWriter1
*                                *id.group= 60
*                                *id.variation= 2
*                                *qc= 6
@@@@                                *write_in_UInt8_static = 1764167928->60
@@@@                                *write_in_UInt8_static = 1764167929->2
@@@@                                *write_in_UInt8_static = 1764167930->6

                                WriteHeader_in_HeaderWriter1
*                                *id.group= 60
*                                *id.variation= 3
*                                *qc= 6
@@@@                                *write_in_UInt8_static = 1764167931->60
@@@@                                *write_in_UInt8_static = 1764167932->3
@@@@                                *write_in_UInt8_static = 1764167933->6

                                WriteHeader_in_HeaderWriter1
*                                *id.group= 60
*                                *id.variation= 4
*                                *qc= 6
@@@@                                *write_in_UInt8_static = 1764167934->60
@@@@                                *write_in_UInt8_static = 1764167935->4
@@@@                                *write_in_UInt8_static = 1764167936->6

                                WriteHeader_in_HeaderWriter1
*                                *id.group= 60
*                                *id.variation= 1
*                                *qc= 6
@@@@                                *write_in_UInt8_static = 1764167937->60
@@@@                                *write_in_UInt8_static = 1764167938->1
@@@@                                *write_in_UInt8_static = 1764167939->6
                        }ClassRequest_in_APDUBuilders_static_

                        {SetFunction_in_APDUWrapper1
@@@@                        *write_uint8=1764167927->1
                        }SetFunction_in_APDUWrapper_

                        {ToByte_in_AppControlField1
*                        *ret |= AppControlField_FIR_MASK
*                        *ret |= AppControlField_FIN_MASK
                        }ToByte_in_AppControlField_
                        *uint8_t ret =192
                        *uint8_t seq =1

                        {SetControl_in_APDUWrapper1
@@@@                        *write_uint8=1764167926->193
                        }SetControl_in_APDUWrapper_
                    }BuildRequest_in_StartupIntegrityPoll_

                    {StartResponseTimer_in_MContext1

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6421512

{Start_in_MockExecutorOver2_1
*uint32_t duration= 5333
*MockExecutor *pMockExecutor= 6421512

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762687680
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421512
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
                    }StartResponseTimer_in_MContext_

                    {Transmit_in_MContext1

{BeginTransmit_in_MockLowerLayer1
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= c1
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 3c
*                    @*buffer->buffer_[i]= 2
*                    @*buffer->buffer_[i]= 6
*                    @*buffer->buffer_[i]= 3c
*                    @*buffer->buffer_[i]= 3
*                    @*buffer->buffer_[i]= 6
*                    @*buffer->buffer_[i]= 3c
*                    @*buffer->buffer_[i]= 4
*                    @*buffer->buffer_[i]= 6
*                    @*buffer->buffer_[i]= 3c
*                    @*buffer->buffer_[i]= 1
*                    @*buffer->buffer_[i]= 6
}BeginTransmit_in_MockLowerLayer_
                    }Transmit_in_MContext_
                }ResumeActiveTask_in_MContext2_
            }Run_in_MContext2_
        }CheckForTaskRun_in_MasterSchedulerBackend3_
*    **inspect_ClassField**
*    @*uint8_t bitfield= 15

{IntegrityPoll_in_APDUHexBuilders1

{ClassTask_in_APDUHexBuilders1

        BufferSer4_in_BufferSer4Over2_1
*        *uint16_t length=2048
*        *uint8_t bytes[SIZE_BufferSer4]=6419072

        {ClassRequest_in_APDUBuilders_static1
*        **inspect_ClassField**
*        @*uint8_t bitfield= 15

            {ToByte_in_AppControlField1
*            *ret |= AppControlField_FIR_MASK
*            *ret |= AppControlField_FIN_MASK
            }ToByte_in_AppControlField_
            *uint8_t ret =192
            *uint8_t seq =1

            {SetControl_in_APDUWrapper1
@@@@            *write_uint8=6419072->193
            }SetControl_in_APDUWrapper_

            {SetFunction_in_APDUWrapper1
@@@@            *write_uint8=6419073->1
            }SetFunction_in_APDUWrapper_

            WriteClassHeaders_in_APDUBuilders_static1

                WriteHeader_in_HeaderWriter1
*                *id.group= 60
*                *id.variation= 2
*                *qc= 6
@@@@                *write_in_UInt8_static = 6419074->60
@@@@                *write_in_UInt8_static = 6419075->2
@@@@                *write_in_UInt8_static = 6419076->6

                WriteHeader_in_HeaderWriter1
*                *id.group= 60
*                *id.variation= 3
*                *qc= 6
@@@@                *write_in_UInt8_static = 6419077->60
@@@@                *write_in_UInt8_static = 6419078->3
@@@@                *write_in_UInt8_static = 6419079->6

                WriteHeader_in_HeaderWriter1
*                *id.group= 60
*                *id.variation= 4
*                *qc= 6
@@@@                *write_in_UInt8_static = 6419080->60
@@@@                *write_in_UInt8_static = 6419081->4
@@@@                *write_in_UInt8_static = 6419082->6

                WriteHeader_in_HeaderWriter1
*                *id.group= 60
*                *id.variation= 1
*                *qc= 6
@@@@                *write_in_UInt8_static = 6419083->60
@@@@                *write_in_UInt8_static = 6419084->1
@@@@                *write_in_UInt8_static = 6419085->6
        }ClassRequest_in_APDUBuilders_static_
}ClassTask_in_APDUHexBuilders_

}IntegrityPoll_in_APDUHexBuilders_
stmp= C1 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
popstr= C1 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06
