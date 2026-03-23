********SUITE('18SendUnconfirmed')********

{LinkLayerTest_in_LinkLayerTest1

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

{MockLinkListener_in_MockLinkListener1
}MockLinkListener_in_MockLinkListener_

{MockTransportLayer_in_MockTransportLayer1
}MockTransportLayer_in_MockTransportLayer_
}LinkLayerTest_in_LinkLayerTest_

    {OnLowerLayerUp_in_LinkContext1
    }OnLowerLayerUp_in_LinkContext2_

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=250

    {Send_in_LinkLayer1

        {SetTxSegment_in_LinkContext1
        }SetTxSegment_in_LinkContext3_

        {TryStartTransmission_in_LinkContext1

            {FormatHeader_in_LinkFrame_static1
            ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***
                {Write_in_LinkHeader1
@@@@                *write_in_UInt16_static = 1763836004->0
@@@@                *write_in_UInt16_static = 1763836006->0

                    {AddCrc_in_CRC_static1
*                    *uint16_t length =8
@@@@                    *write_in_UInt16_static = 1763836008->15543
                    }AddCrc_in_CRC_static_
                }Write_in_LinkHeader_
            }FormatHeader_in_LinkFrame_static2_

            {WriteUserData_in_LinkFrame_static1
*            *uint16_t length= 250

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836026->4332
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836044->807
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836062->14202
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836080->9393
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836098->24512
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836116->19467
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836134->30806
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836152->27549
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836170->36532
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836188->40319
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836206->43298
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836224->47849
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836242->49560
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836260->53843
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =16
@@@@                *write_in_UInt16_static = 1763836278->58894
                }AddCrc_in_CRC_static_

                {AddCrc_in_CRC_static1
*                *uint16_t length =10
@@@@                *write_in_UInt16_static = 1763836290->41180
                }AddCrc_in_CRC_static_
            }WriteUserData_in_LinkFrame_static_

            {QueueTransmit_in_LinkContext1

                {BeginTransmit_in_ILinkTx1

{BeginTransmit_in_LinkLayerTest1

}BeginTransmit_in_LinkLayerTest_
                }BeginTransmit_in_ILinkTx_
            }QueueTransmit_in_LinkContext_
        }TryStartTransmission_in_LinkContext_
    }Send_in_LinkLayer2_
REQUIRE(t.NumTotalWrites() == 1)
temp1=  1

    {OnTxReady_in_LinkLayer1

        {OnTxReady_in_LinkContext1
        }OnTxReady_in_LinkContext2_

        {TryStartTransmission_in_LinkContext1
        }TryStartTransmission_in_LinkContext_
    }OnTxReady_in_LinkLayer_
REQUIRE(t.exe->run_many() > 0)
tmp=  1
REQUIRE(t.upper->GetCounters().numTxReady == 1)
cnttemp.numTxReady=  0
REQUIRE(t.NumTotalWrites() == 1)
num=  1
