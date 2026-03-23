********SUITE('5ConfirmedUserData')********

{FormatHeader_in_LinkFrame_static1

    {ControlByte_in_LinkHeader_static1
*    *boolean aIsMaster= 1
*    *boolean aFcb= 1
*    *boolean aFcvDfc= 1
*    *LinkFunction_uint8_t aFunc= 67
    }ControlByte_in_LinkHeader_static_
*    *uint8_t ret= 243
*FormatHeader_in_LinkFrame_static2
**LinkHeader header.ctrl= 243
****FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***

    {Write_in_LinkHeader1
@@@@    *write_to 6419626->5
@@@@    *write_to 6419627->100
@@@@    *write_to 6419628->28
@@@@    *write_in_UInt16_static = 6419630->1
@@@@    *write_in_UInt16_static = 6419632->1024
@@@@    *write_to 6419629->243

        {AddCrc_in_CRC_static1
*        *uint16_t length =8
@@@@        *write_in_UInt16_static = 6419634->41430
        }AddCrc_in_CRC_static_
    }Write_in_LinkHeader_
}FormatHeader_in_LinkFrame_static2_

    {WriteUserData_in_LinkFrame_static1
*    *uint16_t length= 23

        {AddCrc_in_CRC_static1
*        *uint16_t length =16
@@@@        *write_in_UInt16_static = 6419652->34706
        }AddCrc_in_CRC_static_

        {AddCrc_in_CRC_static1
*        *uint16_t length =7
@@@@        *write_in_UInt16_static = 6419661->21245
        }AddCrc_in_CRC_static_
    }WriteUserData_in_LinkFrame_static_
REQUIRE(hex == '05 64 14 F3 01 00 00 04 0A 3B C0 C3 01 3C 02 06 3C 03 06 3C 04 06 3C 01 06 9A 12')
stemp= 05 64 1C F3 01 00 00 04 D6 A1 C7 C6 83 90 00 78 01 5B 01 0C 00 03 00 00 00 00 92 87 92 87 00 04 01 73 74 FD 52
