
{MockFrameSink_in_MockFrameSink1

}MockFrameSink_in_MockFrameSink_

{WriteData_in_LinkParserTestOver3_1

{WriteBuff_in_LinkLayerParser1
}WriteBuff_in_LinkLayerParser_

    {OnRead_in_LinkLayerParser1
*    *uint16_t numBytes= 12
*    *Complete_State_LinkLayerParser= 3

        {AdvanceWrite_in_ShiftableBuffer1
*        *uint16_t aNumBytes= 12
        }AdvanceWrite_in_ShiftableBuffer_

        {ParseUntilComplete_in_LinkLayerParser1
*        *State_LinkLayerParser_uint8_t lastState =0

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                    }NumBytesRead_in_ShiftableBuffer_

                    {Sync_in_ShiftableBuffer1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
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
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                    }NumBytesRead_in_ShiftableBuffer_

                    {ReadHeader_in_LinkLayerParser1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                        }NumBytesRead_in_ShiftableBuffer_
                    ***SIMPLE_LOG_BLOCK(logger, flags::WARN, 'CRC failure in header')***
                    }ReadHeader_in_LinkLayerParser2_
                }ParseHeader_in_LinkLayerParser2_
            }ParseOneStep_in_LinkLayerParser2_

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 1
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 11
                    }NumBytesRead_in_ShiftableBuffer_

                    {Sync_in_ShiftableBuffer1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 1
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 11
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 1
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 11
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 2
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 2
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
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 2
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_

                    {ReadHeader_in_LinkLayerParser1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 2
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 2
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
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 2
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                    }NumBytesRead_in_ShiftableBuffer_

                    {ValidateBody_in_LinkLayerParser1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 12
*                        *pShiftableBuffer->readPos= 2
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_
*                    **inspect_RSeq**
*                    *buffer->buffer_[i]=  5
*                    *buffer->buffer_[i]=  64
*                    *buffer->buffer_[i]=  5
*                    *buffer->buffer_[i]=  c0
*                    *buffer->buffer_[i]=  1
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  0
*                    *buffer->buffer_[i]=  4
*                    *buffer->buffer_[i]=  e9
*                    *buffer->buffer_[i]=  21
*                    ***FORMAT_HEX_BLOCK(logger, flags::LINK_RX_HEX, buffer.ReadBuffer().take(frameSize), 10, 18)***
                    }ValidateBody_in_LinkLayerParser1_

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 2
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
*        **inspect_RSeq**

}OnFrame_in_MockFrameSink_
        }PushFrame_in_LinkLayerParser_

        {ParseUntilComplete_in_LinkLayerParser1
*        *State_LinkLayerParser_uint8_t lastState =0

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 12
*                    *pShiftableBuffer->readPos= 12
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 0
                    }NumBytesRead_in_ShiftableBuffer_
                }ParseSync_in_LinkLayerParser2_
            }ParseOneStep_in_LinkLayerParser1_
*            *State_LinkLayerParser_uint8_t tmp= 0
        }ParseUntilComplete_in_LinkLayerParser_
*        *pLinkLayerParser->state =0

        {NumBytesRead_in_ShiftableBuffer1
*        *pShiftableBuffer->writePos= 12
*        *pShiftableBuffer->readPos= 12
*        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 0
        }NumBytesRead_in_ShiftableBuffer_
    }OnRead_in_LinkLayerParser_
}WriteData_in_LinkParserTestOver3__
REQUIRE(t.sink.m_num_frames == 1)
t.sink.m_num_frames=  1

REQUIRE(t.parser.Statistics().numHeaderCrcError == 1)
t.parser.Statistics().numHeaderCrcError=  1

REQUIRE(t.sink.CheckLast(LinkFunction::PRI_RESET_LINK_STATES, true, 1, 1024))
t.sink.CheckLast(LinkFunction::PRI_RESET_LINK_STATES, true, 1, 1024)=  1

