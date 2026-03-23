********SUITE('12StateSending')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419608
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048



    {OnLowerLayerUp_in_TransportLayer1

{OnLowerLayerUp_in_MockUpperLayer1
}OnLowerLayerUp_in_MockUpperLayer_
    }OnLowerLayerUp_in_TransportLayer2_

{SendDown_in_MockUpperLayerOver1_1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=1

{SendDown_in_MockUpperLayerOver2_1

    {BeginTransmit_in_TransportLayer1

        {Configure_in_TransportTx1
        }Configure_in_TransportTx_

{Send_in_MockLinkLayer1

        {GetSegment_in_TransportTx1
*        *GetSegment_in_TransportTx2
*        *uint16_t numToSend= 1
*        *GetSegment_in_TransportTx3
*        *        **inspect_RSeq**
*        @*buffer->buffer_[i]= 11

            {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
            }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
@@@@        *write_in_UInt8_static = 6421856->192

*            *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_TX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', fir, fin, sequence.Get()
*            *FIR: 1
*            *FIN: 1
*            *SEQ: 0
*            *LEN: 1
        }GetSegment_in_TransportTx_

        {Advance_in_TransportTx1
        }Advance_in_TransportTx_
}Send_in_MockLinkLayer_
    }BeginTransmit_in_TransportLayer5_
}SendDown_in_MockUpperLayerOver2__
}SendDown_in_MockUpperLayerOver1__
REQUIRE(test.upper.SendDown('11')
boolean btmp= 1
REQUIRE('C0 11' == test.link.PopWriteAsHex())
stmp= C0 11

{SendDown_in_MockUpperLayerOver1_1

    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=1

{SendDown_in_MockUpperLayerOver2_1

    {BeginTransmit_in_TransportLayer1
*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Invalid BeginTransmit call, already transmitting')
    }BeginTransmit_in_TransportLayer3_
}SendDown_in_MockUpperLayerOver2__
}SendDown_in_MockUpperLayerOver1__
REQUIRE_FALSE(test.upper.SendDown('00'))
boolean btmp= 0

    {OnLowerLayerUp_in_TransportLayer1
*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already online')
    }OnLowerLayerUp_in_TransportLayer1_
REQUIRE_FALSE(test.transport.OnLowerLayerUp())
boolean btmp= 0

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
*        *pTransportRx->numBytesRead= 0

            {GetAvailable_in_TransportRx1
            }GetAvailable_in_TransportRx_

            {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
            }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
        }ProcessReceive_in_TransportRx6_
    }OnReceive_in_TransportLayer1_
}SendUp_in_MockLinkLayer1_
REQUIRE(test.upper.received.AsHex() == '77')
stmp= 77

    {OnTxReady_in_TransportLayer1

        {OnTxReady_in_IUpperLayer1

{OnTxReady_in_MockUpperLayer1
}OnTxReady_in_MockUpperLayer_
        }OnTxReady_in_IUpperLayer_
    }OnTxReady_in_TransportLayer3_
boolean btmp= 1
REQUIRE(test.upper.GetCounters().numTxReady == 1)
ctmp.numTxReady= 1

    {OnTxReady_in_TransportLayer1
*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Invalid send callback')
    }OnTxReady_in_TransportLayer2_
REQUIRE_FALSE(test.transport.OnTxReady())
boolean btmp= 0
