********SUITE('14RequestStatusOfLink')********

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
            *TimerExe4cpp *pTimerExe4cpp= 1764174404
            *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
            }cancel_in_TimerExe4cpp1_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6421888

{Start_in_MockExecutorOver2_1
*uint32_t duration= 60666
*MockExecutor *pMockExecutor= 6421888

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762689856
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421888
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
        }RestartKeepAliveTimer_in_LinkContext_
    }OnLowerLayerUp_in_LinkContext2_

{OnFrame_in_LinkLayerTest1

    {OnFrame_in_LinkLayer1

        {OnFrame_in_LinkContext1

            {RestartKeepAliveTimer_in_LinkContext1

                {cancel_in_TimerExe4cpp1
                *TimerExe4cpp *pTimerExe4cpp= 1764174404
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
*cancel_in_MockTimer_override=1762689856
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421888
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
            }RestartKeepAliveTimer_in_LinkContext_
*        *header->func= 73
@@@@        *LinkFunction_PRI_REQUEST_LINK_STATUS

            {FormatHeader_in_LinkFrame_static1

                {ControlByte_in_LinkHeader_static1
*                *boolean aIsMaster= 1
*                *boolean aFcb= 0
*                *boolean aFcvDfc= 0
*                *LinkFunction_uint8_t aFunc= 11
                }ControlByte_in_LinkHeader_static_
*                *uint8_t ret= 139
            *FormatHeader_in_LinkFrame_static2
*            *LinkHeader header.ctrl= 139
*            ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

                {Write_in_LinkHeader1
@@@@                *write_to 1764174308->5
@@@@                *write_to 1764174309->100
@@@@                *write_to 1764174310->5
@@@@                *write_in_UInt16_static = 1764174312->1024
@@@@                *write_in_UInt16_static = 1764174314->1
@@@@                *write_to 1764174311->139

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =8
@@@@                    *write_in_UInt16_static = 1764174316->63278
                    }AddCrc_in_CRC_static_
                }Write_in_LinkHeader_
            }FormatHeader_in_LinkFrame_static2_

            {QueueTransmit_in_LinkContext1

                {BeginTransmit_in_ILinkTx1

{BeginTransmit_in_LinkLayerTest1
tt= 05 64 05 8B 00 04 01 00 2E F7
}BeginTransmit_in_LinkLayerTest_
                }BeginTransmit_in_ILinkTx_
            }QueueTransmit_in_LinkContext_

            {SLLS_NotReset_in_SLLS_NotReset1

                {SecStateBase_in_SecStateBase1
                }SecStateBase_in_SecStateBase_
            }SLLS_NotReset_in_SLLS_NotReset_
        }OnFrame_in_LinkContext6_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnFrame_in_LinkLayer_
}OnFrame_in_LinkLayerTest_
REQUIRE(t.NumTotalWrites() == 1)
uint32_t temp32 = 1

    {OnTxReady_in_LinkLayer1

        {OnTxReady_in_LinkContext1

            {SLLS_NotReset_in_SLLS_NotReset1

                {SecStateBase_in_SecStateBase1
                }SecStateBase_in_SecStateBase_
            }SLLS_NotReset_in_SLLS_NotReset_
        }OnTxReady_in_LinkContext2_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnTxReady_in_LinkLayer_
std::string tmpStr =05 64 05 8B 00 04 01 00 2E F7
{LinkStatus_in_LinkHex_static1

    {FormatHeader_in_LinkFrame_static1

        {ControlByte_in_LinkHeader_static1
*        *boolean aIsMaster= 1
*        *boolean aFcb= 0
*        *boolean aFcvDfc= 0
*        *LinkFunction_uint8_t aFunc= 11
        }ControlByte_in_LinkHeader_static_
*        *uint8_t ret= 139
    *FormatHeader_in_LinkFrame_static2
*    *LinkHeader header.ctrl= 139
*    ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

        {Write_in_LinkHeader1
@@@@        *write_to 6421324->5
@@@@        *write_to 6421325->100
@@@@        *write_to 6421326->5
@@@@        *write_in_UInt16_static = 6421328->1024
@@@@        *write_in_UInt16_static = 6421330->1
@@@@        *write_to 6421327->139

            {AddCrc_in_CRC_static1
*            *uint16_t length =8
@@@@            *write_in_UInt16_static = 6421332->63278
            }AddCrc_in_CRC_static_
        }Write_in_LinkHeader_
    }FormatHeader_in_LinkFrame_static2_
}LinkStatus_in_LinkHex_static_
std::string tmpStr =05 64 05 8B 00 04 01 00 2E F7
{OnFrame_in_LinkLayerTest1

    {OnFrame_in_LinkLayer1

        {OnFrame_in_LinkContext1

            {RestartKeepAliveTimer_in_LinkContext1

                {cancel_in_TimerExe4cpp1
                *TimerExe4cpp *pTimerExe4cpp= 1764174404
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
*cancel_in_MockTimer_override=1762689856
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421888
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
            }RestartKeepAliveTimer_in_LinkContext_
*        *header->func= 64
@@@@        *LinkFunction_PRI_RESET_LINK_STATES

            {OnResetLinkStates_in_SLLS_NotReset1
*            *uint16_t source= 1024

                {QueueAck_in_LinkContext1

                    {FormatHeader_in_LinkFrame_static1

                        {ControlByte_in_LinkHeader_static1
*                        *boolean aIsMaster= 1
*                        *boolean aFcb= 0
*                        *boolean aFcvDfc= 0
*                        *LinkFunction_uint8_t aFunc= 0
                        }ControlByte_in_LinkHeader_static_
*                        *uint8_t ret= 128
                    *FormatHeader_in_LinkFrame_static2
*                    *LinkHeader header.ctrl= 128
*                    ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

                        {Write_in_LinkHeader1
@@@@                        *write_to 1764174308->5
@@@@                        *write_to 1764174309->100
@@@@                        *write_to 1764174310->5
@@@@                        *write_in_UInt16_static = 1764174312->1024
@@@@                        *write_in_UInt16_static = 1764174314->1
@@@@                        *write_to 1764174311->128

                            {AddCrc_in_CRC_static1
*                            *uint16_t length =8
@@@@                            *write_in_UInt16_static = 1764174316->51053
                            }AddCrc_in_CRC_static_
                        }Write_in_LinkHeader_
                    }FormatHeader_in_LinkFrame_static2_

                    {QueueTransmit_in_LinkContext1

                        {BeginTransmit_in_ILinkTx1

{BeginTransmit_in_LinkLayerTest1
tt= 05 64 05 80 00 04 01 00 6D C7
}BeginTransmit_in_LinkLayerTest_
                        }BeginTransmit_in_ILinkTx_
                    }QueueTransmit_in_LinkContext_
                }QueueAck_in_LinkContext_

                {SLLS_Reset_in_SLLS_Reset1

                    {SecStateBase_in_SecStateBase1
                    }SecStateBase_in_SecStateBase_
                }SLLS_Reset_in_SLLS_Reset_
            }OnResetLinkStates_in_SLLS_NotReset_
        }OnFrame_in_LinkContext6_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnFrame_in_LinkLayer_
}OnFrame_in_LinkLayerTest_
REQUIRE(t.NumTotalWrites() == 2)
uint32_t temp32 = 2

    {OnTxReady_in_LinkLayer1

        {OnTxReady_in_LinkContext1

            {SLLS_Reset_in_SLLS_Reset1

                {SecStateBase_in_SecStateBase1
                }SecStateBase_in_SecStateBase_
            }SLLS_Reset_in_SLLS_Reset_
        }OnTxReady_in_LinkContext2_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnTxReady_in_LinkLayer_

{OnFrame_in_LinkLayerTest1

    {OnFrame_in_LinkLayer1

        {OnFrame_in_LinkContext1

            {RestartKeepAliveTimer_in_LinkContext1

                {cancel_in_TimerExe4cpp1
                *TimerExe4cpp *pTimerExe4cpp= 1764174404
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
*cancel_in_MockTimer_override=1762689856
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6421888
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
            }RestartKeepAliveTimer_in_LinkContext_
*        *header->func= 73
@@@@        *LinkFunction_PRI_REQUEST_LINK_STATUS

            {FormatHeader_in_LinkFrame_static1

                {ControlByte_in_LinkHeader_static1
*                *boolean aIsMaster= 1
*                *boolean aFcb= 0
*                *boolean aFcvDfc= 0
*                *LinkFunction_uint8_t aFunc= 11
                }ControlByte_in_LinkHeader_static_
*                *uint8_t ret= 139
            *FormatHeader_in_LinkFrame_static2
*            *LinkHeader header.ctrl= 139
*            ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

                {Write_in_LinkHeader1
@@@@                *write_to 1764174308->5
@@@@                *write_to 1764174309->100
@@@@                *write_to 1764174310->5
@@@@                *write_in_UInt16_static = 1764174312->1024
@@@@                *write_in_UInt16_static = 1764174314->1
@@@@                *write_to 1764174311->139

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =8
@@@@                    *write_in_UInt16_static = 1764174316->63278
                    }AddCrc_in_CRC_static_
                }Write_in_LinkHeader_
            }FormatHeader_in_LinkFrame_static2_

            {QueueTransmit_in_LinkContext1

                {BeginTransmit_in_ILinkTx1

{BeginTransmit_in_LinkLayerTest1
tt= 05 64 05 80 00 04 01 00 6D C7
tt= 05 64 05 8B 00 04 01 00 2E F7
}BeginTransmit_in_LinkLayerTest_
                }BeginTransmit_in_ILinkTx_
            }QueueTransmit_in_LinkContext_

            {SLLS_Reset_in_SLLS_Reset1

                {SecStateBase_in_SecStateBase1
                }SecStateBase_in_SecStateBase_
            }SLLS_Reset_in_SLLS_Reset_
        }OnFrame_in_LinkContext6_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnFrame_in_LinkLayer_
}OnFrame_in_LinkLayerTest_
REQUIRE(t.NumTotalWrites() == 3)
uint32_t temp32 = 3
std::string tmpStr =05 64 05 8B 00 04 01 00 2E F7
{LinkStatus_in_LinkHex_static1

    {FormatHeader_in_LinkFrame_static1

        {ControlByte_in_LinkHeader_static1
*        *boolean aIsMaster= 1
*        *boolean aFcb= 0
*        *boolean aFcvDfc= 0
*        *LinkFunction_uint8_t aFunc= 11
        }ControlByte_in_LinkHeader_static_
*        *uint8_t ret= 139
    *FormatHeader_in_LinkFrame_static2
*    *LinkHeader header.ctrl= 139
*    ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

        {Write_in_LinkHeader1
@@@@        *write_to 6421324->5
@@@@        *write_to 6421325->100
@@@@        *write_to 6421326->5
@@@@        *write_in_UInt16_static = 6421328->1024
@@@@        *write_in_UInt16_static = 6421330->1
@@@@        *write_to 6421327->139

            {AddCrc_in_CRC_static1
*            *uint16_t length =8
@@@@            *write_in_UInt16_static = 6421332->63278
            }AddCrc_in_CRC_static_
        }Write_in_LinkHeader_
    }FormatHeader_in_LinkFrame_static2_
}LinkStatus_in_LinkHex_static_
std::string tmpStr =05 64 05 8B 00 04 01 00 2E F7
