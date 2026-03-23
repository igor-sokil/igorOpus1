********SUITE('2ResetLinks')********

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048
**uint8_t bytes[SIZE_BufferSer4]=6420142

    {FormatHeader_in_LinkFrame_static1

        {ControlByte_in_LinkHeader_static1
*        *boolean aIsMaster= 1
*        *boolean aFcb= 0
*        *boolean aFcvDfc= 0
*        *LinkFunction_uint8_t aFunc= 64
        }ControlByte_in_LinkHeader_static_
*        *uint8_t ret= 192
    *FormatHeader_in_LinkFrame_static2
*    *LinkHeader header.ctrl= 192
*    ***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

        {Write_in_LinkHeader1
@@@@        *write_to 6420142->5
@@@@        *write_to 6420143->100
@@@@        *write_to 6420144->5
@@@@        *write_in_UInt16_static = 6420146->1
@@@@        *write_in_UInt16_static = 6420148->1024
@@@@        *write_to 6420145->192

            {AddCrc_in_CRC_static1
*            *uint16_t length =8
@@@@            *write_in_UInt16_static = 6420150->8681
            }AddCrc_in_CRC_static_
        }Write_in_LinkHeader_
    }FormatHeader_in_LinkFrame_static2_
REQUIRE(HexConversions::to_hex(wrapper) == '05 64 05 C0 01 00 00 04 E9 21')
rseq.buffer_[0]=  5 64 5 c0 1 0 0 4 e9 21
