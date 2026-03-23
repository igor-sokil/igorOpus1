********SUITE('4allows header-only final frame')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419608
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048
**uint8_t bytes[SIZE_BufferSer4]=6419756



    {OnLowerLayerUp_in_TransportLayer1

{OnLowerLayerUp_in_MockUpperLayer1
}OnLowerLayerUp_in_MockUpperLayer_
    }OnLowerLayerUp_in_TransportLayer2_

{SendUp_in_MockLinkLayer1
*SendUp_in_MockLinkLayer2
***inspect_RSeq**
*@*buffer->buffer_[i]= 41
*@*buffer->buffer_[i]= de
*@*buffer->buffer_[i]= ad
*@*buffer->buffer_[i]= be
*@*buffer->buffer_[i]= ef
*@*buffer->buffer_[i]= 88

    {OnReceive_in_TransportLayer1

        {ProcessReceive_in_TransportRx1
*        *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', header.fir, header.fin
*        *FIR: 1
*        *FIN: 0
*        *SEQ: 1
*        *LEN: 5
*        *pTransportRx->numBytesRead= 0

            {GetAvailable_in_TransportRx1
            }GetAvailable_in_TransportRx_

            {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
            }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
        }ProcessReceive_in_TransportRx7_
    }OnReceive_in_TransportLayer1_
}SendUp_in_MockLinkLayer1_

{SendUp_in_MockLinkLayer1
*SendUp_in_MockLinkLayer2
***inspect_RSeq**
*@*buffer->buffer_[i]= 2
*@*buffer->buffer_[i]= 99

    {OnReceive_in_TransportLayer1

        {ProcessReceive_in_TransportRx1
*        *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', header.fir, header.fin
*        *FIR: 0
*        *FIN: 0
*        *SEQ: 2
*        *LEN: 1
*        *pTransportRx->numBytesRead= 5

            {GetAvailable_in_TransportRx1
            }GetAvailable_in_TransportRx_

            {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
            }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
        }ProcessReceive_in_TransportRx7_
    }OnReceive_in_TransportLayer1_
}SendUp_in_MockLinkLayer1_

{SendUp_in_MockLinkLayer1
*SendUp_in_MockLinkLayer2
***inspect_RSeq**
*@*buffer->buffer_[i]= 83
*@*buffer->buffer_[i]= aa

    {OnReceive_in_TransportLayer1

        {ProcessReceive_in_TransportRx1
*        *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', header.fir, header.fin
*        *FIR: 0
*        *FIN: 1
*        *SEQ: 3
*        *LEN: 1
*        *pTransportRx->numBytesRead= 6

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
REQUIRE(test.upper.received.AsHex() == 'DE AD BE EF')
stmp= DE AD BE EF 88 99 AA
