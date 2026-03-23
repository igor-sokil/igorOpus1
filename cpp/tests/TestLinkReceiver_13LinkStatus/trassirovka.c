********SUITE('13LinkStatus')********

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=292

    {FormatHeader_in_LinkFrame_static1

        {ControlByte_in_LinkHeader_static1
*        *boolean aIsMaster= 1
*        *boolean aFcb= 0
*        *boolean aFcvDfc= 1
*        *LinkFunction_uint8_t aFunc= 11
        }ControlByte_in_LinkHeader_static_
*        *uint8_t ret= 155
    *FormatHeader_in_LinkFrame_static2
*    *LinkHeader header.ctrl= 155
*    ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

        {Write_in_LinkHeader1
@@@@        *write_to 6421454->5
@@@@        *write_to 6421455->100
@@@@        *write_to 6421456->5
@@@@        *write_in_UInt16_static = 6421458->1
@@@@        *write_in_UInt16_static = 6421460->2
@@@@        *write_to 6421457->155

            {AddCrc_in_CRC_static1
*            *uint16_t length =8
@@@@            *write_in_UInt16_static = 6421462->18719
            }AddCrc_in_CRC_static_
        }Write_in_LinkHeader_
    }FormatHeader_in_LinkFrame_static2_
***inspect_RSeq**
**buffer->buffer_[i]=  5
**buffer->buffer_[i]=  64
**buffer->buffer_[i]=  5
**buffer->buffer_[i]=  9b
**buffer->buffer_[i]=  1
**buffer->buffer_[i]=  0
**buffer->buffer_[i]=  2
**buffer->buffer_[i]=  0
**buffer->buffer_[i]=  1f
**buffer->buffer_[i]=  49

{MockFrameSink_in_MockFrameSink1

}MockFrameSink_in_MockFrameSink_

{WriteData_in_LinkParserTestOver1_1

    {WriteBuff_in_LinkLayerParser1
    }WriteBuff_in_LinkLayerParser_

    {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
    }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_

    {OnRead_in_LinkLayerParser1
*    *uint16_t numBytes= 10
*    *Complete_State_LinkLayerParser= 3

        {AdvanceWrite_in_ShiftableBuffer1
*        *uint16_t aNumBytes= 10
        }AdvanceWrite_in_ShiftableBuffer_

        {ParseUntilComplete_in_LinkLayerParser1
*        *State_LinkLayerParser_uint8_t lastState =0

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_

                    {Sync_in_ShiftableBuffer1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 10
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 10
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_
                    }Sync_in_ShiftableBuffer1_
                *ParseSync_in_LinkLayerParser2
*                *boolean synced= 1
                }ParseSync_in_LinkLayerParser1_
            }ParseOneStep_in_LinkLayerParser1_
*            *State_LinkLayerParser_uint8_t tmp= 1

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 1
@@@@            *ReadHeader_State_LinkLayerParser

                {ParseHeader_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_

                    {ReadHeader_in_LinkLayerParser1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 10
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 10
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {ValidateHeaderParameters_in_LinkLayerParser1

                            {ValidateFunctionCode_in_LinkLayerParser1
                            }ValidateFunctionCode_in_LinkLayerParser5_
                        }ValidateHeaderParameters_in_LinkLayerParser5_
                    }ReadHeader_in_LinkLayerParser1_
                }ParseHeader_in_LinkLayerParser1_
            }ParseOneStep_in_LinkLayerParser2_

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 2
@@@@            *ReadBody_State_LinkLayerParser

                {ParseBody_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_
                    ***FORMAT_HEX_BLOCK(logger, flags::LINK_RX_HEX, buffer.ReadBuffer().take(frameSize), 10, 18)***

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_
                }ParseBody_in_LinkLayerParser2_
            }ParseOneStep_in_LinkLayerParser3_

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 3
            }ParseOneStep_in_LinkLayerParser4_
        }ParseUntilComplete_in_LinkLayerParser_
*        *pLinkLayerParser->state =3

        {PushFrame_in_LinkLayerParser1

{OnFrame_in_MockFrameSink1

}OnFrame_in_MockFrameSink_
        }PushFrame_in_LinkLayerParser_

        {ParseUntilComplete_in_LinkLayerParser1
*        *State_LinkLayerParser_uint8_t lastState =0

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 10
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 0
                    }NumBytesRead_in_ShiftableBuffer_
                }ParseSync_in_LinkLayerParser2_
            }ParseOneStep_in_LinkLayerParser1_
*            *State_LinkLayerParser_uint8_t tmp= 0
        }ParseUntilComplete_in_LinkLayerParser_
*        *pLinkLayerParser->state =0

        {NumBytesRead_in_ShiftableBuffer1
*        *pShiftableBuffer->writePos= 10
*        *pShiftableBuffer->readPos= 10
*        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 0
        }NumBytesRead_in_ShiftableBuffer_
    }OnRead_in_LinkLayerParser_
}WriteData_in_LinkParserTestOver1__
REQUIRE(t.sink.m_num_frames == 1)
t.sink.m_num_frames=  1
REQUIRE(t.sink.CheckLastWithDFC(LinkFunction::SEC_LINK_STATUS, true, true, 1, 2))
tmp=  1
