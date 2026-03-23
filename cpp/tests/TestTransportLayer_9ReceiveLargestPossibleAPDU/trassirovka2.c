********SUITE('9ReceiveLargestPossibleAPDU')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419608
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=70
**sizeof(BufferSer4)=2048
**uint8_t bytes[SIZE_BufferSer4]=6419756



    {OnLowerLayerUp_in_TransportLayer1

{OnLowerLayerUp_in_MockUpperLayer1
}OnLowerLayerUp_in_MockUpperLayer_
    }OnLowerLayerUp_in_TransportLayer2_
stmp= 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45
stmp.size()= 209
packets.size()= 1


packets[i]= C0 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45

{SendUp_in_MockLinkLayer1
*SendUp_in_MockLinkLayer2
***inspect_RSeq**
*@*buffer->buffer_[i]= c0
*@*buffer->buffer_[i]= 0
*@*buffer->buffer_[i]= 1
*@*buffer->buffer_[i]= 2
*@*buffer->buffer_[i]= 3
*@*buffer->buffer_[i]= 4
*@*buffer->buffer_[i]= 5
*@*buffer->buffer_[i]= 6
*@*buffer->buffer_[i]= 7
*@*buffer->buffer_[i]= 8
*@*buffer->buffer_[i]= 9
*@*buffer->buffer_[i]= a
*@*buffer->buffer_[i]= b
*@*buffer->buffer_[i]= c
*@*buffer->buffer_[i]= d
*@*buffer->buffer_[i]= e
*@*buffer->buffer_[i]= f
*@*buffer->buffer_[i]= 10
*@*buffer->buffer_[i]= 11
*@*buffer->buffer_[i]= 12
*@*buffer->buffer_[i]= 13
*@*buffer->buffer_[i]= 14
*@*buffer->buffer_[i]= 15
*@*buffer->buffer_[i]= 16
*@*buffer->buffer_[i]= 17
*@*buffer->buffer_[i]= 18
*@*buffer->buffer_[i]= 19
*@*buffer->buffer_[i]= 1a
*@*buffer->buffer_[i]= 1b
*@*buffer->buffer_[i]= 1c
*@*buffer->buffer_[i]= 1d
*@*buffer->buffer_[i]= 1e
*@*buffer->buffer_[i]= 1f
*@*buffer->buffer_[i]= 20
*@*buffer->buffer_[i]= 21
*@*buffer->buffer_[i]= 22
*@*buffer->buffer_[i]= 23
*@*buffer->buffer_[i]= 24
*@*buffer->buffer_[i]= 25
*@*buffer->buffer_[i]= 26
*@*buffer->buffer_[i]= 27
*@*buffer->buffer_[i]= 28
*@*buffer->buffer_[i]= 29
*@*buffer->buffer_[i]= 2a
*@*buffer->buffer_[i]= 2b
*@*buffer->buffer_[i]= 2c
*@*buffer->buffer_[i]= 2d
*@*buffer->buffer_[i]= 2e
*@*buffer->buffer_[i]= 2f
*@*buffer->buffer_[i]= 30
*@*buffer->buffer_[i]= 31
*@*buffer->buffer_[i]= 32
*@*buffer->buffer_[i]= 33
*@*buffer->buffer_[i]= 34
*@*buffer->buffer_[i]= 35
*@*buffer->buffer_[i]= 36
*@*buffer->buffer_[i]= 37
*@*buffer->buffer_[i]= 38
*@*buffer->buffer_[i]= 39
*@*buffer->buffer_[i]= 3a
*@*buffer->buffer_[i]= 3b
*@*buffer->buffer_[i]= 3c
*@*buffer->buffer_[i]= 3d
*@*buffer->buffer_[i]= 3e
*@*buffer->buffer_[i]= 3f
*@*buffer->buffer_[i]= 40
*@*buffer->buffer_[i]= 41
*@*buffer->buffer_[i]= 42
*@*buffer->buffer_[i]= 43
*@*buffer->buffer_[i]= 44
*@*buffer->buffer_[i]= 45

    {OnReceive_in_TransportLayer1

        {ProcessReceive_in_TransportRx1
*        *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', header.fir, header.fin
*        *FIR: 1
*        *FIN: 1
*        *SEQ: 0
*        *LEN: 70
*        *pTransportRx->numBytesRead= 0

            {GetAvailable_in_TransportRx1
            }GetAvailable_in_TransportRx_

            {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
            }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
        }ProcessReceive_in_TransportRx6_

{Write_in_DataSink1
}Write_in_DataSink_
    }OnReceive_in_TransportLayer1_
}SendUp_in_MockLinkLayer1_

{AsHex_in_DataSink1
}AsHex_in_DataSink_
REQUIRE(test.upper.received.AsHex() == apdu)
stmp= 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 20 21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30 31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F 40 41 42 43 44 45
