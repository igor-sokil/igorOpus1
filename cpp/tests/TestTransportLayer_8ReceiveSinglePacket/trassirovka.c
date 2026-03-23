********SUITE('8ReceiveSinglePacket')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421360
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048



    {OnLowerLayerUp_in_TransportLayer1

{OnLowerLayerUp_in_MockUpperLayer1
}OnLowerLayerUp_in_MockUpperLayer_
    }OnLowerLayerUp_in_TransportLayer2_

{SendUp_in_MockLinkLayer1
*SendUp_in_MockLinkLayer2
***inspect_RSeq**
*@*buffer->buffer_[i]= c0
*@*buffer->buffer_[i]= 77

    {OnReceive_in_TransportLayer1

        {ProcessReceive_in_TransportRx1
*        *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', header.fir, header.fin
*        *FIR: 1
*        *FIN: 1
*        *SEQ: 0
*        *LEN: 1

            {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
            }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
        }ProcessReceive_in_TransportRx6_
*    *OnReceive_in_TransportLayer2
*    **inspect_RSeq**
*    @*buffer->buffer_[i]= 77
*    *OnReceive_in_TransportLayer3
    }OnReceive_in_TransportLayer1_
}SendUp_in_MockLinkLayer1_
REQUIRE(test.upper.received.AsHex() == '77')
stmp= 77
