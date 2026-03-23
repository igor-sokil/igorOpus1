********SUITE('15BroadcastRequestStatusOfLink')********

{LinkLayerTest_in_LinkLayerTest1

{MockLinkListener_in_MockLinkListener1
}MockLinkListener_in_MockLinkListener_

{MockTransportLayer_in_MockTransportLayer1
}MockTransportLayer_in_MockTransportLayer_

{LinkContext_in_LinkContext1

    {SLLS_NotReset_in_SLLS_NotReset1

        {SecStateBase_in_SecStateBase1
        }SecStateBase_in_SecStateBase_
    }SLLS_NotReset_in_SLLS_NotReset_
}LinkContext_in_LinkContext_
}LinkLayerTest_in_LinkLayerTest_

    {OnLowerLayerUp_in_LinkContext1
    }OnLowerLayerUp_in_LinkContext2_

{OnFrame_in_LinkLayerTest1

    {OnFrame_in_LinkLayer1

        {OnFrame_in_LinkContext1
*        ***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Received invalid function (%s) with broadcast destination address')***
        }OnFrame_in_LinkContext5_
    }OnFrame_in_LinkLayer_
}OnFrame_in_LinkLayerTest_
REQUIRE(t.NumTotalWrites() == 0)
uint32_t temp32 = 0
REQUIRE(t.link.GetStatistics().numUnexpectedFrame == 1)
t.link.GetStatistics().numUnexpectedFrame = 1
