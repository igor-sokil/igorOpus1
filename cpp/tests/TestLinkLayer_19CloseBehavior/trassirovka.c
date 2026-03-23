********SUITE('19CloseBehavior')********

{LinkLayerTest_in_LinkLayerTest1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419800
}MockExecutor_in_MockExecutor_

{MockLinkListener_in_MockLinkListener1
}MockLinkListener_in_MockLinkListener_

{MockTransportLayer_in_MockTransportLayer1
}MockTransportLayer_in_MockTransportLayer_

{LinkLayer_in_LinkLayer1

    {LinkContext_in_LinkContext1

        {SLLS_NotReset_in_SLLS_NotReset1

            {SecStateBase_in_SecStateBase1
            }SecStateBase_in_SecStateBase_
        }SLLS_NotReset_in_SLLS_NotReset_
    }LinkContext_in_LinkContext_
}LinkLayer_in_LinkLayer_

{SetLinkLayer_in_MockTransportLayer1
}SetLinkLayer_in_MockTransportLayer_
}LinkLayerTest_in_LinkLayerTest_

    {OnLowerLayerUp_in_LinkContext1

        {RestartKeepAliveTimer_in_LinkContext1

            {cancel_in_TimerExe4cpp1
            *TimerExe4cpp *pTimerExe4cpp= 1764186692
            *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
            }cancel_in_TimerExe4cpp1_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6419800

{Start_in_MockExecutorOver2_1
*uint32_t duration= 60666
*MockExecutor *pMockExecutor= 6419800

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762691024
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6419800
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
        }RestartKeepAliveTimer_in_LinkContext_
    }OnLowerLayerUp_in_LinkContext2_

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=250
*    *sizeof(BufferSer4)=2048
*    *uint8_t bytes[SIZE_BufferSer4]=6417552

    {Send_in_LinkLayer1

        {SetTxSegment_in_LinkContext1
        }SetTxSegment_in_LinkContext3_

        {TryStartTransmission_in_LinkContext1
*        *pLinkContext->keepAliveTimeout= 0
*        *pLinkContext->pSegments= 6420108

            {FormatPrimaryBufferWithUnconfirmed_in_LinkContext1

                {FormatHeader_in_LinkFrame_static1

                    {ControlByte_in_LinkHeader_static1
*                    *boolean aIsMaster= 1
*                    *boolean aFcb= 0
*                    *boolean aFcvDfc= 0
*                    *LinkFunction_uint8_t aFunc= 68
                    }ControlByte_in_LinkHeader_static_
*                    *uint8_t ret= 196
                *FormatHeader_in_LinkFrame_static2
*                *LinkHeader header.ctrl= 196
*                ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

                    {Write_in_LinkHeader1
@@@@                    *write_to 1764186304->5
@@@@                    *write_to 1764186305->100
@@@@                    *write_to 1764186306->255
@@@@                    *write_in_UInt16_static = 1764186308->0
@@@@                    *write_in_UInt16_static = 1764186310->0
@@@@                    *write_to 1764186307->196

                        {AddCrc_in_CRC_static1
*                        *uint16_t length =8
@@@@                        *write_in_UInt16_static = 1764186312->15543
                        }AddCrc_in_CRC_static_
                    }Write_in_LinkHeader_
                }FormatHeader_in_LinkFrame_static2_

                {WriteUserData_in_LinkFrame_static1
*                *uint16_t length= 250

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186330->4332
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186348->807
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186366->14202
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186384->9393
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186402->24512
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186420->19467
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186438->30806
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186456->27549
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186474->36532
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186492->40319
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186510->43298
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186528->47849
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186546->49560
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186564->53843
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186582->58894
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =10
@@@@                    *write_in_UInt16_static = 1764186594->41180
                    }AddCrc_in_CRC_static_
                }WriteUserData_in_LinkFrame_static_
            }FormatPrimaryBufferWithUnconfirmed_in_LinkContext_

            {QueueTransmit_in_LinkContext1

                {BeginTransmit_in_ILinkTx1

{BeginTransmit_in_LinkLayerTest1
FinalDestination_in_LinkLayerTest:
tt= 05 64 FF C4 00 00 00 00 B7 3C 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F EC 10 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 27 03 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 7A 37 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F B1 24 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F C0 5F 50 51 52 53 54 55 56 57 58 59 5A 5B 5C 5D 5E 5F 0B 4C 60 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 56 78 70 71 72 73 74 75 76 77 78 79 7A 7B 7C 7D 7E 7F 9D 6B 80 81 82 83 84 85 86 87 88 89 8A 8B 8C 8D 8E 8F B4 8E 90 91 92 93 94 95 96 97 98 99 9A 9B 9C 9D 9E 9F 7F 9D A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF 22 A9 B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF E9 BA C0 C1 C2 C3 C4 C5 C6 C7 C8 C9 CA CB CC CD CE CF 98 C1 D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 DA DB DC DD DE DF 53 D2 E0 E1 E2 E3 E4 E5 E6 E7 E8 E9 EA EB EC ED EE EF 0E E6 F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 DC A0
}BeginTransmit_in_LinkLayerTest_
                }BeginTransmit_in_ILinkTx_
            }QueueTransmit_in_LinkContext_
        }TryStartTransmission_in_LinkContext_
    }Send_in_LinkLayer2_

    {OnTxReady_in_LinkLayer1

        {OnTxReady_in_LinkContext1
        }OnTxReady_in_LinkContext2_
*    *OnTxReady_in_LinkLayer2
*    boolean ret= 1

        {TryStartTransmission_in_LinkContext1
*        *pLinkContext->keepAliveTimeout= 0
*        *pLinkContext->pSegments= 0
        }TryStartTransmission_in_LinkContext_
    }OnTxReady_in_LinkLayer_
REQUIRE(t.exe->run_many() > 0)
tmp=  1

    {OnLowerLayerDown_in_LinkContext1

        {cancel_in_TimerExe4cpp1
        *TimerExe4cpp *pTimerExe4cpp= 1764186676
        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
        }cancel_in_TimerExe4cpp1_

        {cancel_in_TimerExe4cpp1
        *TimerExe4cpp *pTimerExe4cpp= 1764186692
        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6419800

            {cancel_in_ITimer1
            *pITimer->psource_in_ITimer= 6419800

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419800
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
            }cancel_in_ITimer1
        }cancel_in_TimerExe4cpp2_

        {SLLS_NotReset_in_SLLS_NotReset1

            {SecStateBase_in_SecStateBase1
            }SecStateBase_in_SecStateBase_
        }SLLS_NotReset_in_SLLS_NotReset_
    }OnLowerLayerDown_in_LinkContext2_
REQUIRE_FALSE(t.upper->IsOnline())
tt=  0

    {OnLowerLayerUp_in_LinkContext1

        {RestartKeepAliveTimer_in_LinkContext1

            {cancel_in_TimerExe4cpp1
            *TimerExe4cpp *pTimerExe4cpp= 1764186692
            *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 6419800

                {cancel_in_ITimer1
                *pITimer->psource_in_ITimer= 6419800

{cancel_in_MockTimer_override1

{cancel_in_MockTimer1

{cancel_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419800
}cancel_in_MockExecutor_
}cancel_in_MockTimer_
}cancel_in_MockTimer_override_
                }cancel_in_ITimer1
            }cancel_in_TimerExe4cpp2_

{Start_in_MockExecutor_override1
*MockExecutor *pMockExecutor= 6419800

{Start_in_MockExecutorOver2_1
*uint32_t duration= 60666
*MockExecutor *pMockExecutor= 6419800

{MockTimer_in_MockTimer1
*cancel_in_MockTimer_override=1762691024
}MockTimer_in_MockTimer_
*tTimerExe4cpp.iITimer.psource_in_ITimer=6419800
}Start_in_MockExecutorOver2__
}Start_in_MockExecutor_override_
        }RestartKeepAliveTimer_in_LinkContext_
    }OnLowerLayerUp_in_LinkContext2_
REQUIRE(t.upper->IsOnline())
tt=  1

    {Send_in_LinkLayer1

        {SetTxSegment_in_LinkContext1
        }SetTxSegment_in_LinkContext3_

        {TryStartTransmission_in_LinkContext1
*        *pLinkContext->keepAliveTimeout= 0
*        *pLinkContext->pSegments= 6420108

            {FormatPrimaryBufferWithUnconfirmed_in_LinkContext1

                {FormatHeader_in_LinkFrame_static1

                    {ControlByte_in_LinkHeader_static1
*                    *boolean aIsMaster= 1
*                    *boolean aFcb= 0
*                    *boolean aFcvDfc= 0
*                    *LinkFunction_uint8_t aFunc= 68
                    }ControlByte_in_LinkHeader_static_
*                    *uint8_t ret= 196
                *FormatHeader_in_LinkFrame_static2
*                *LinkHeader header.ctrl= 196
*                ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

                    {Write_in_LinkHeader1
@@@@                    *write_to 1764186304->5
@@@@                    *write_to 1764186305->100
@@@@                    *write_to 1764186306->255
@@@@                    *write_in_UInt16_static = 1764186308->0
@@@@                    *write_in_UInt16_static = 1764186310->0
@@@@                    *write_to 1764186307->196

                        {AddCrc_in_CRC_static1
*                        *uint16_t length =8
@@@@                        *write_in_UInt16_static = 1764186312->15543
                        }AddCrc_in_CRC_static_
                    }Write_in_LinkHeader_
                }FormatHeader_in_LinkFrame_static2_

                {WriteUserData_in_LinkFrame_static1
*                *uint16_t length= 250

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186330->4332
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186348->807
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186366->14202
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186384->9393
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186402->24512
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186420->19467
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186438->30806
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186456->27549
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186474->36532
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186492->40319
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186510->43298
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186528->47849
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186546->49560
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186564->53843
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =16
@@@@                    *write_in_UInt16_static = 1764186582->58894
                    }AddCrc_in_CRC_static_

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =10
@@@@                    *write_in_UInt16_static = 1764186594->41180
                    }AddCrc_in_CRC_static_
                }WriteUserData_in_LinkFrame_static_
            }FormatPrimaryBufferWithUnconfirmed_in_LinkContext_

            {QueueTransmit_in_LinkContext1

                {BeginTransmit_in_ILinkTx1

{BeginTransmit_in_LinkLayerTest1
FinalDestination_in_LinkLayerTest:
tt= 05 64 FF C4 00 00 00 00 B7 3C 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F EC 10 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 27 03 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 7A 37 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F B1 24 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F C0 5F 50 51 52 53 54 55 56 57 58 59 5A 5B 5C 5D 5E 5F 0B 4C 60 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 56 78 70 71 72 73 74 75 76 77 78 79 7A 7B 7C 7D 7E 7F 9D 6B 80 81 82 83 84 85 86 87 88 89 8A 8B 8C 8D 8E 8F B4 8E 90 91 92 93 94 95 96 97 98 99 9A 9B 9C 9D 9E 9F 7F 9D A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF 22 A9 B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF E9 BA C0 C1 C2 C3 C4 C5 C6 C7 C8 C9 CA CB CC CD CE CF 98 C1 D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 DA DB DC DD DE DF 53 D2 E0 E1 E2 E3 E4 E5 E6 E7 E8 E9 EA EB EC ED EE EF 0E E6 F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 DC A0
tt= 05 64 FF C4 00 00 00 00 B7 3C 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F EC 10 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 27 03 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 7A 37 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F B1 24 40 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F C0 5F 50 51 52 53 54 55 56 57 58 59 5A 5B 5C 5D 5E 5F 0B 4C 60 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 56 78 70 71 72 73 74 75 76 77 78 79 7A 7B 7C 7D 7E 7F 9D 6B 80 81 82 83 84 85 86 87 88 89 8A 8B 8C 8D 8E 8F B4 8E 90 91 92 93 94 95 96 97 98 99 9A 9B 9C 9D 9E 9F 7F 9D A0 A1 A2 A3 A4 A5 A6 A7 A8 A9 AA AB AC AD AE AF 22 A9 B0 B1 B2 B3 B4 B5 B6 B7 B8 B9 BA BB BC BD BE BF E9 BA C0 C1 C2 C3 C4 C5 C6 C7 C8 C9 CA CB CC CD CE CF 98 C1 D0 D1 D2 D3 D4 D5 D6 D7 D8 D9 DA DB DC DD DE DF 53 D2 E0 E1 E2 E3 E4 E5 E6 E7 E8 E9 EA EB EC ED EE EF 0E E6 F0 F1 F2 F3 F4 F5 F6 F7 F8 F9 DC A0
}BeginTransmit_in_LinkLayerTest_
                }BeginTransmit_in_ILinkTx_
            }QueueTransmit_in_LinkContext_
        }TryStartTransmission_in_LinkContext_
    }Send_in_LinkLayer2_
REQUIRE(t.NumTotalWrites() == 2)
num=  2
