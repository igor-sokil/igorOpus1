********SUITE('6AbsenceOfData')********

{MockFrameSink_in_MockFrameSink1

}MockFrameSink_in_MockFrameSink_

{WriteData_in_LinkParserTestOver2_1

{WriteBuff_in_LinkLayerParser1
}WriteBuff_in_LinkLayerParser_

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
@@@@                    *read_from_in_UInt16_static = 6421892<-1024
@@@@                    *read_from_in_UInt16_static = 6421894<-1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 10
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_
@@@@                    *read_from_in_UInt16_static = 6421896<-16742

                        {ValidateHeaderParameters_in_LinkLayerParser1

                            {ValidateFunctionCode_in_LinkLayerParser1
                            }ValidateFunctionCode_in_LinkLayerParser5_
*                        ***FORMAT_LOG_BLOCK(logger, flags::ERR, 'User data with no payload. FUNCTION: %s',***
*                        *LinkFunction_uint8_t func= 67
                        }ValidateHeaderParameters_in_LinkLayerParser3_
                    }ReadHeader_in_LinkLayerParser1_
                }ParseHeader_in_LinkLayerParser2_
            }ParseOneStep_in_LinkLayerParser2_

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 10
*                    *pShiftableBuffer->readPos= 1
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 9
                    }NumBytesRead_in_ShiftableBuffer_
                }ParseSync_in_LinkLayerParser2_
            }ParseOneStep_in_LinkLayerParser1_
*            *State_LinkLayerParser_uint8_t tmp= 0
        }ParseUntilComplete_in_LinkLayerParser_
*        *pLinkLayerParser->state =0

        {NumBytesRead_in_ShiftableBuffer1
*        *pShiftableBuffer->writePos= 10
*        *pShiftableBuffer->readPos= 1
*        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 9
        }NumBytesRead_in_ShiftableBuffer_
    }OnRead_in_LinkLayerParser_
}WriteData_in_LinkParserTestOver2__
REQUIRE(t.sink.m_num_frames == 0)
t.sink.m_num_frames=  0
REQUIRE(t.parser.Statistics().numBadLength == 1)
t.parser.Statistics().numBadLength=  1
