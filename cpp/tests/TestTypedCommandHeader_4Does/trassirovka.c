********SUITE('4Does not format if insufficient space')********

{TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16_1
}TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16__

    {Add_in_TypedCommandHeader_for_AnalogOutputInt16_1
    }Add_in_TypedCommandHeader_for_AnalogOutputInt16__

    {Add_in_TypedCommandHeader_for_AnalogOutputInt16_1
    }Add_in_TypedCommandHeader_for_AnalogOutputInt16__

    {Write_in_TypedCommandHeader_for_AnalogOutputInt16_1

        IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter1

            WriteHeaderWithReserve_in_HeaderWriter1
*            *qc= 40
*            *reserve= 7

            WriteHeader_in_HeaderWriter1
*            *id.group= 41
*            *id.variation= 2
*            *qc= 40
@@@@            *write_in_UInt8_static = 6421902->41
@@@@            *write_in_UInt8_static = 6421903->2
@@@@            *write_in_UInt8_static = 6421904->40

            {PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2_1
            }PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2__
*    *Write_in_TypedCommandHeader_for_AnalogOutputInt16_3
*    *Write_in_TypedCommandHeader_for_AnalogOutputInt16_4

        {Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1
@@@@        *write_in_UInt16_static = 6421907->10
@@@@        *write_in_UInt16_static = 6421909->7
@@@@        *write_in_UInt8_static = 6421911->0
        }Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1_
*    *Write_in_TypedCommandHeader_for_AnalogOutputInt16_4

        {Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1
        }Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_2_
    }Write_in_TypedCommandHeader_for_AnalogOutputInt16_4_
REQUIRE_FALSE(header.Write(writer, IndexQualifierMode::always_two_bytes))
boolean btemp =0
