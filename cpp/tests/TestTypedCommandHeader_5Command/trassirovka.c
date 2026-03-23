********SUITE('5Command set can be moved and written')********

{Add_Indexed_for_AnalogOutputInt16_in_CommandSet1

    {StartHeaderAOInt16_in_CommandSet1

        {TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16_1
        }TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16__
    }StartHeaderAOInt16_in_CommandSet_

    {Add_in_TypedCommandHeader_for_AnalogOutputInt16_override1

        {Add_in_TypedCommandHeader_for_AnalogOutputInt16_1
        }Add_in_TypedCommandHeader_for_AnalogOutputInt16__
    }Add_in_TypedCommandHeader_for_AnalogOutputInt16_override_
}Add_Indexed_for_AnalogOutputInt16_in_CommandSet_

    {Add_Indexed_for_AnalogOutputInt32_in_CommandSet1

        {StartHeaderAOInt32_in_CommandSet1

            {TypedCommandHeader_for_AnalogOutputInt32_in_TypedCommandHeader_for_AnalogOutputInt32_1
            }TypedCommandHeader_for_AnalogOutputInt32_in_TypedCommandHeader_for_AnalogOutputInt32__
        }StartHeaderAOInt32_in_CommandSet_

        {Add_in_TypedCommandHeader_for_AnalogOutputInt32_override1

            {Add_in_TypedCommandHeader_for_AnalogOutputInt32_1
            }Add_in_TypedCommandHeader_for_AnalogOutputInt32__
        }Add_in_TypedCommandHeader_for_AnalogOutputInt32_override_
    }Add_Indexed_for_AnalogOutputInt32_in_CommandSet_

    {Write_in_CommandSetOps_static1

        {Write_in_TypedCommandHeader_for_AnalogOutputInt16_1

            IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter1

                WriteHeaderWithReserve_in_HeaderWriter1
*                *qc= 40
*                *reserve= 7

                WriteHeader_in_HeaderWriter1
*                *id.group= 41
*                *id.variation= 2
*                *qc= 40
@@@@                *write_in_UInt8_static = 6421694->41
@@@@                *write_in_UInt8_static = 6421695->2
@@@@                *write_in_UInt8_static = 6421696->40

                {PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2_1
                }PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16Over2__
*        *Write_in_TypedCommandHeader_for_AnalogOutputInt16_3
*        *Write_in_TypedCommandHeader_for_AnalogOutputInt16_4

            {Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1
@@@@            *write_in_UInt16_static = 6421699->10
@@@@            *write_in_UInt16_static = 6421701->7
@@@@            *write_in_UInt8_static = 6421703->0
            }Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_1_

            PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt161
@@@@        *write_in_UInt16_static = 6421697->1
        }Write_in_TypedCommandHeader_for_AnalogOutputInt16_5_

        {Write_in_TypedCommandHeader_for_AnalogOutputInt32_1

            IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt32_in_HeaderWriter1

                WriteHeaderWithReserve_in_HeaderWriter1
*                *qc= 40
*                *reserve= 9

                WriteHeader_in_HeaderWriter1
*                *id.group= 41
*                *id.variation= 1
*                *qc= 40
@@@@                *write_in_UInt8_static = 6421704->41
@@@@                *write_in_UInt8_static = 6421705->1
@@@@                *write_in_UInt8_static = 6421706->40

                PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt32Over2_1
*        *Write_in_TypedCommandHeader_for_AnalogOutputInt32_3
*        *Write_in_TypedCommandHeader_for_AnalogOutputInt32_4
@@@@        *write_in_UInt16_static = 6421709->11
@@@@        *write_in_UInt32_static = 6421711->8
@@@@        *write_in_UInt8_static = 6421715->0

            PrefixedWriteIterator_for_UInt16_AnalogOutputInt32_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt321
@@@@        *write_in_UInt16_static = 6421707->1
        }Write_in_TypedCommandHeader_for_AnalogOutputInt32_5_
    }Write_in_CommandSetOps_static2_
REQUIRE(CommandSetOps::Write(commands, writer, mode))
boolean temp= 1
str= 01 00 29 02 28 01 00 0A 00 07 00 00 29 01 28 01 00 0B 00 08 00 00 00 00
REQUIRE(WriteToHex(commands2, IndexQualifierMode::always_two_bytes)== '29 02 28 01 00 0A 00 07 00 00 29 01 28 01 00 0B 00 08 00 00 00 00')
std::string str =                                                01 00 29 02 28 01 00 0A 00 07 00 00 29 01 28 01 00 0B 00 08 00 00 00 00
