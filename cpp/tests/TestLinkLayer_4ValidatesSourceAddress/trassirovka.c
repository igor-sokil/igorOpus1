********SUITE('4ValidatesSourceAddress')********

{LinkLayerTest_in_LinkLayerTest1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421888
}MockExecutor_in_MockExecutor_

{MockLinkListener_in_MockLinkListener1
}MockLinkListener_in_MockLinkListener_

{MockTransportLayer_in_MockTransportLayer1
}MockTransportLayer_in_MockTransportLayer_

{LinkLayer_in_LinkLayer1

    {LinkContext_in_LinkContext1
    LinkContext_in_LinkContext2
    LinkContext_in_LinkContext2.1
    LinkContext_in_LinkContext3

        {SLLS_NotReset_in_SLLS_NotReset1

            {SecStateBase_in_SecStateBase1
            }SecStateBase_in_SecStateBase_
        }SLLS_NotReset_in_SLLS_NotReset_
    LinkContext_in_LinkContext4
    }LinkContext_in_LinkContext_
}LinkLayer_in_LinkLayer_
}LinkLayerTest_in_LinkLayerTest_

    {OnLowerLayerUp_in_LinkContext1

        {RestartKeepAliveTimer_in_LinkContext1

            {cancel_in_TimerExe4cpp1
            *TimerExe4cpp *pTimerExe4cpp= 1764178500
            *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
            }cancel_in_TimerExe4cpp1_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6421888

{Start_in_MockExecutorOver2_1
*uint32_t duration= 60666
*MockExecutor *pMockExecutor= 6421888

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762691024
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421888
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
        }RestartKeepAliveTimer_in_LinkContext_
    }OnLowerLayerUp_in_LinkContext2_

{OnFrame_in_LinkLayerTest1

    {OnFrame_in_LinkLayer1

        {OnFrame_in_LinkContext1
*        **inspect_LinkHeaderFields**
*        @*LinkFunction_uint8_t func= 0
*        @*boolean isFromMaster= 0
*        @*boolean fcb= 0
*        @*boolean fcvdfc= 0
*        @*Addresses addresses.source= 1024
*        @*Addresses addresses.destination= 1
*        **inspect_RSeq**

            {RestartKeepAliveTimer_in_LinkContext1

                {cancel_in_TimerExe4cpp1
                *TimerExe4cpp *pTimerExe4cpp= 1764178500
                *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6421888

                    {cancel_in_ITimer1
                    *pITimer->psource_in_ITimer= 6421888

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421888
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                    }cancel_in_ITimer1
                }cancel_in_TimerExe4cpp2_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6421888

{Start_in_MockExecutorOver2_1
*uint32_t duration= 60666
*MockExecutor *pMockExecutor= 6421888

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762691024
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421888
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
            }RestartKeepAliveTimer_in_LinkContext_
*        *header->func= 0
@@@@        *LinkFunction_SEC_ACK
            ***SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Frame context not understood')***
        }OnFrame_in_LinkContext6_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnFrame_in_LinkLayer_
}OnFrame_in_LinkLayerTest_
REQUIRE(t.link.GetStatistics().numUnknownSource == 1)
t.link.GetStatistics().numUnknownSource = 0
