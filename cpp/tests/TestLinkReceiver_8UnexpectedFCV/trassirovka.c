********SUITE('8UnexpectedFCV')********

{WriteData_in_LinkParserTestOver2_1

{WriteBuff_in_LinkLayerParser1
}WriteBuff_in_LinkLayerParser_

    {OnRead_in_LinkLayerParser1

        {ParseUntilComplete_in_LinkLayerParser1
*        *State_LinkLayerParser_uint8_t lastState =0

            {ReadHeader_in_LinkLayerParser1

                {ValidateHeaderParameters_in_LinkLayerParser1

                    {ValidateFunctionCode_in_LinkLayerParser1
*                    ***FORMAT_LOG_BLOCK(logger, flags::WARN, 'Bad FCV for FUNCTION: %s',***
                    }ValidateFunctionCode_in_LinkLayerParser2_
                }ValidateHeaderParameters_in_LinkLayerParser2_
            }ReadHeader_in_LinkLayerParser1_
        }ParseUntilComplete_in_LinkLayerParser_
*        *pLinkLayerParser->state =0
    }OnRead_in_LinkLayerParser_
}WriteData_in_LinkParserTestOver2__
REQUIRE(t.sink.m_num_frames == 0)
t.sink.m_num_frames=  0
REQUIRE(t.parser.Statistics().numBadFCV == 1)
t.parser.Statistics().numBadFCV=  1
