********SUITE('3Formats one-byte qualifier properly if enough space is available')********

{TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16_1
}TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16__

    {Add_in_TypedCommandHeader_for_AnalogOutputInt16_1
    }Add_in_TypedCommandHeader_for_AnalogOutputInt16__

    {Add_in_TypedCommandHeader_for_AnalogOutputInt16_1
    }Add_in_TypedCommandHeader_for_AnalogOutputInt16__

    {Write_in_TypedCommandHeader_for_AnalogOutputInt16_1

        IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter1

            WriteHeaderWithReserve_in_HeaderWriter1
*            *qc= 23
*            *reserve= 5

            WriteHeader_in_HeaderWriter1
*            *id.group= 41
*            *id.variation= 2
*            *qc= 23
@@@@            *write_in_UInt8_static = 6421902->41
@@@@            *write_in_UInt8_static = 6421903->2
@@@@            *write_in_UInt8_static = 6421904->23

            PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16Over2_1
*    *Write_in_TypedCommandHeader_for_AnalogOutputInt16_2
*    *Write_in_TypedCommandHeader_for_AnalogOutputInt16_3
@@@@    *write_in_UInt8_static = 6421906->10
@@@@    *write_in_UInt16_static = 6421907->7
@@@@    *write_in_UInt8_static = 6421909->0
*    *Write_in_TypedCommandHeader_for_AnalogOutputInt16_3
@@@@    *write_in_UInt8_static = 6421910->11
@@@@    *write_in_UInt16_static = 6421911->8
@@@@    *write_in_UInt8_static = 6421913->0

        PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt161
@@@@    *write_in_UInt8_static = 6421905->2
    }Write_in_TypedCommandHeader_for_AnalogOutputInt16_3_
REQUIRE(header.Write(writer, IndexQualifierMode::allow_one_byte))
boolean btemp =1
str= 02 00 29 02 17 02 0A 07 00 00 0B 08 00 00
REQUIRE(hex == '29 02 17 02 0A 07 00 00 0B 08 00 00')
