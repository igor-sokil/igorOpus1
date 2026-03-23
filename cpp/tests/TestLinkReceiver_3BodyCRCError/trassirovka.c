********SUITE('3BodyCRCError')********

{MockFrameSink_in_MockFrameSink1

}MockFrameSink_in_MockFrameSink_

{WriteData_in_LinkParserTestOver3_1

{WriteBuff_in_LinkLayerParser1
}WriteBuff_in_LinkLayerParser_

    {OnRead_in_LinkLayerParser1
*    *uint16_t numBytes= 27
*    *Complete_State_LinkLayerParser= 3

        {AdvanceWrite_in_ShiftableBuffer1
*        *uint16_t aNumBytes= 27
        }AdvanceWrite_in_ShiftableBuffer_

        {ParseUntilComplete_in_LinkLayerParser1
*        *State_LinkLayerParser_uint8_t lastState =0

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 27
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                    }NumBytesRead_in_ShiftableBuffer_

                    {Sync_in_ShiftableBuffer1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
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
*                    *pShiftableBuffer->writePos= 27
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                    }NumBytesRead_in_ShiftableBuffer_

                    {ReadHeader_in_LinkLayerParser1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                        }NumBytesRead_in_ShiftableBuffer_
@@@@                    *read_from_in_UInt16_static = 6421892<-1
@@@@                    *read_from_in_UInt16_static = 6421894<-1024

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                        }NumBytesRead_in_ShiftableBuffer_
@@@@                    *read_from_in_UInt16_static = 6421896<-15114

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
*                    *pShiftableBuffer->writePos= 27
*                    *pShiftableBuffer->readPos= 0
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                    }NumBytesRead_in_ShiftableBuffer_

                    {ValidateBody_in_LinkLayerParser1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 0
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 27
                        }NumBytesRead_in_ShiftableBuffer_
*                    **inspect_RSeq**
*                    @*buffer->buffer_[i]= 6421888<-5
*                    @*buffer->buffer_[i]= 6421889<-64
*                    @*buffer->buffer_[i]= 6421890<-14
*                    @*buffer->buffer_[i]= 6421891<-f3
*                    @*buffer->buffer_[i]= 6421892<-1
*                    @*buffer->buffer_[i]= 6421893<-0
*                    @*buffer->buffer_[i]= 6421894<-0
*                    @*buffer->buffer_[i]= 6421895<-4
*                    @*buffer->buffer_[i]= 6421896<-a
*                    @*buffer->buffer_[i]= 6421897<-3b
*                    @*buffer->buffer_[i]= 6421898<-c0
*                    @*buffer->buffer_[i]= 6421899<-c3
*                    @*buffer->buffer_[i]= 6421900<-1
*                    @*buffer->buffer_[i]= 6421901<-3c
*                    @*buffer->buffer_[i]= 6421902<-2
*                    @*buffer->buffer_[i]= 6421903<-6
*                    @*buffer->buffer_[i]= 6421904<-3c
*                    @*buffer->buffer_[i]= 6421905<-3
*                    @*buffer->buffer_[i]= 6421906<-6
*                    @*buffer->buffer_[i]= 6421907<-3c
*                    @*buffer->buffer_[i]= 6421908<-4
*                    @*buffer->buffer_[i]= 6421909<-6
*                    @*buffer->buffer_[i]= 6421910<-3c
*                    @*buffer->buffer_[i]= 6421911<-1
*                    @*buffer->buffer_[i]= 6421912<-6
*                    @*buffer->buffer_[i]= 6421913<-9a
*                    @*buffer->buffer_[i]= 6421914<-11
@@@@                    *read_from_in_UInt16_static = 6421913<-4506
*                    ***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'CRC failure in body')***
                    }ValidateBody_in_LinkLayerParser2_
                }ParseBody_in_LinkLayerParser3_
            }ParseOneStep_in_LinkLayerParser3_

            {ParseOneStep_in_LinkLayerParser1
*            *pLinkLayerParser->state= 0
@@@@            *FindSync_State_LinkLayerParser

                {ParseSync_in_LinkLayerParser1

                    {NumBytesRead_in_ShiftableBuffer1
*                    *pShiftableBuffer->writePos= 27
*                    *pShiftableBuffer->readPos= 1
*                    *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 26
                    }NumBytesRead_in_ShiftableBuffer_

                    {Sync_in_ShiftableBuffer1

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 1
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 26
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 1
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 26
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 2
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 25
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 2
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 25
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 3
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 24
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 3
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 24
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 4
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 23
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 4
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 23
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 5
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 22
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 5
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 22
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 6
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 21
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 6
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 21
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 7
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 20
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 7
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 20
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 8
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 19
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 8
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 19
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 9
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 18
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 9
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 18
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 10
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 17
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 10
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 17
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 11
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 16
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 11
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 16
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 12
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 15
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 12
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 15
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 13
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 14
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 13
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 14
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 14
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 13
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 14
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 13
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 15
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 15
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 12
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 16
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 11
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 16
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 11
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 17
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 17
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 10
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 18
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 9
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 18
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 9
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 19
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 8
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 19
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 8
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 20
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 7
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 20
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 7
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 21
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 6
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 21
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 6
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 22
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 5
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 22
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 5
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 23
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 4
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 23
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 4
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 24
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 3
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 24
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 3
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 25
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 2
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 25
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 2
                        }NumBytesRead_in_ShiftableBuffer_

                        {NumBytesRead_in_ShiftableBuffer1
*                        *pShiftableBuffer->writePos= 27
*                        *pShiftableBuffer->readPos= 26
*                        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 1
                        }NumBytesRead_in_ShiftableBuffer_
                    }Sync_in_ShiftableBuffer2_
                *ParseSync_in_LinkLayerParser2
*                *boolean synced= 0
                }ParseSync_in_LinkLayerParser1_
            }ParseOneStep_in_LinkLayerParser1_
*            *State_LinkLayerParser_uint8_t tmp= 0
        }ParseUntilComplete_in_LinkLayerParser_
*        *pLinkLayerParser->state =0

        {NumBytesRead_in_ShiftableBuffer1
*        *pShiftableBuffer->writePos= 27
*        *pShiftableBuffer->readPos= 26
*        *return pShiftableBuffer->writePos - pShiftableBuffer->readPos= 1
        }NumBytesRead_in_ShiftableBuffer_
    }OnRead_in_LinkLayerParser_
}WriteData_in_LinkParserTestOver3__
REQUIRE(t.sink.m_num_frames == 0)
t.sink.m_num_frames=  0
REQUIRE(t.parser.Statistics().numHeaderCrcError == 1)
t.parser.Statistics().numBodyCrcError=  1
