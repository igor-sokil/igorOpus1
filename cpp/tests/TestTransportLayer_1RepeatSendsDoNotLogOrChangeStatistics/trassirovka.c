********SUITE('1RepeatSendsDoNotLogOrChangeStatistics')********

{Configure_in_TransportTx1
}Configure_in_TransportTx_

    {GetSegment_in_TransportTx1
*    *GetSegment_in_TransportTx2
*    *uint16_t numToSend= 3
*    *GetSegment_in_TransportTx3
*    *    **inspect_RSeq**
*    @*buffer->buffer_[i]= 12
*    @*buffer->buffer_[i]= 34
*    @*buffer->buffer_[i]= 56

        {transfer_fromMemcpy_in_WSeq_for_Uint16_t1
        }transfer_fromMemcpy_in_WSeq_for_Uint16_t2_
@@@@    *write_in_UInt8_static = 6419880->192

*        *FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_TX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', fir, fin, sequence.Get()
*        *FIR: 1
*        *FIN: 1
*        *SEQ: 0
*        *LEN: 3
    }GetSegment_in_TransportTx2_
str= C0 12 34 56
REQUIRE('C0 12 34 56' == HexConversions::to_hex(segment1))
REQUIRE(tx.Statistics().numTransportTx == 1)
tx.Statistics().numTransportTx= 1

    {GetSegment_in_TransportTx1
    }GetSegment_in_TransportTx1_
str2= C0 12 34 56
REQUIRE('C0 12 34 56' == HexConversions::to_hex(segment2))
REQUIRE(tx.Statistics().numTransportTx == 1)
tx.Statistics().numTransportTx= 1
