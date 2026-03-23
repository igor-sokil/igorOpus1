********SUITE('2IntegrityOnStartup')********

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
            }GetDisableUnsolTask_in_MasterTasks_static2_
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
        }Initialize_in_MasterTasks_

OnOpen_in_MockMasterApplication1
    }OnLowerLayerUp_in_MContext2_

    {CheckForTaskRun_in_MasterSchedulerBackend1

        {cancel_in_TimerExe4cpp1
        *TimerExe4cpp *pTimerExe4cpp= 1764174380
        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
        }cancel_in_TimerExe4cpp1_
    *CheckForTaskRun_in_MasterSchedulerBackend3
*    *pMasterSchedulerBackend->tasks.size()= 5
    *CheckForTaskRun_in_MasterSchedulerBackend4

        {Run_in_MContext1
*        *pMContext->activeTask= 0
*        *pMContext->tstate= 0
*        *TaskState_in_MContext_IDLE= 0
        *FORMAT_LOG_BLOCK(logger, flags::INFO, 'Begining task: %s', this->activeTask->Name())
        Name_in_IMasterTask(pMContext->activeTask)= StartupIntegrityPoll

            {ResumeActiveTask_in_MContext1

                {BuildRequest_in_StartupIntegrityPoll1

                    {ClassRequest_in_APDUBuilders_static1
*                    **inspect_ClassField**
*                    @*uint8_t bitfield= 15

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
@@@@                        *write_uint8=1764167927->1
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

                            WriteHeader_in_HeaderWriter1
*                            *id.group= 60
*                            *id.variation= 1
*                            *qc= 6
@@@@                            *write_in_UInt8_static = 1764167937->60
@@@@                            *write_in_UInt8_static = 1764167938->1
@@@@                            *write_in_UInt8_static = 1764167939->6
                    }ClassRequest_in_APDUBuilders_static_

                    {SetFunction_in_APDUWrapper1
@@@@                    *write_uint8=1764167927->1
                    }SetFunction_in_APDUWrapper_

                    {ToByte_in_AppControlField1
*                    *ret |= AppControlField_FIR_MASK
*                    *ret |= AppControlField_FIN_MASK
                    }ToByte_in_AppControlField_
                    *uint8_t ret =192
                    *uint8_t seq =0

                    {SetControl_in_APDUWrapper1
@@@@                    *write_uint8=1764167926->192
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
***inspect_ClassField**
*@*uint8_t bitfield= 15

{IntegrityPoll_in_APDUHexBuilders1

{ClassTask_in_APDUHexBuilders1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6419136

    {ClassRequest_in_APDUBuilders_static1
*    **inspect_ClassField**
*    @*uint8_t bitfield= 15

        {ToByte_in_AppControlField1
*        *ret |= AppControlField_FIR_MASK
*        *ret |= AppControlField_FIN_MASK
        }ToByte_in_AppControlField_
        *uint8_t ret =192
        *uint8_t seq =0

        {SetControl_in_APDUWrapper1
@@@@        *write_uint8=6419136->192
        }SetControl_in_APDUWrapper_

        {SetFunction_in_APDUWrapper1
@@@@        *write_uint8=6419137->1
        }SetFunction_in_APDUWrapper_

        WriteClassHeaders_in_APDUBuilders_static1

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 2
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419138->60
@@@@            *write_in_UInt8_static = 6419139->2
@@@@            *write_in_UInt8_static = 6419140->6

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 3
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419141->60
@@@@            *write_in_UInt8_static = 6419142->3
@@@@            *write_in_UInt8_static = 6419143->6

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 4
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419144->60
@@@@            *write_in_UInt8_static = 6419145->4
@@@@            *write_in_UInt8_static = 6419146->6

            WriteHeader_in_HeaderWriter1
*            *id.group= 60
*            *id.variation= 1
*            *qc= 6
@@@@            *write_in_UInt8_static = 6419147->60
@@@@            *write_in_UInt8_static = 6419148->1
@@@@            *write_in_UInt8_static = 6419149->6
    }ClassRequest_in_APDUBuilders_static_
}ClassTask_in_APDUHexBuilders_

}IntegrityPoll_in_APDUHexBuilders_
stmp= C0 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06

{PopWriteAsHex_in_MockLowerLayer1
}PopWriteAsHex_in_MockLowerLayer2_
popstr= C0 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06
