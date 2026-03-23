********SUITE('14ClosedWhileSending')********

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
boolean btmp= 1

{OnLowerLayerDown_in_MockUpperLayer1
}OnLowerLayerDown_in_MockUpperLayer_
REQUIRE_FALSE(test.upper.IsOnline())
boolean btmp= 0
