********SUITE('1ClosedState')********

{LinkLayerTest_in_LinkLayerTest1

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6419800
}MockExecutor_in_MockExecutor_

{MockLinkListener_in_MockLinkListener1
}MockLinkListener_in_MockLinkListener_

{MockTransportLayer_in_MockTransportLayer1
}MockTransportLayer_in_MockTransportLayer_

{LinkLayer_in_LinkLayer1

    {LinkContext_in_LinkContext1
    LinkContext_in_LinkContext2
    LinkContext_in_LinkContext2.1
    LinkContext_in_LinkContext3

        {SLLS_NotReset_in_SLLS_NotReset1

            {SecStateBase_in_SecStateBase1
            }SecStateBase_in_SecStateBase_
        }SLLS_NotReset_in_SLLS_NotReset_
    LinkContext_in_LinkContext4
    }LinkContext_in_LinkContext_
}LinkLayer_in_LinkLayer_
}LinkLayerTest_in_LinkLayerTest_

    {Send_in_LinkLayer1
    }Send_in_LinkLayer1_
REQUIRE_FALSE(t.upper->SendDown(segment))
boolean tempBool=  0

    {OnLowerLayerDown_in_LinkContext1
*    ***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already online')***
    }OnLowerLayerDown_in_LinkContext1_
REQUIRE_FALSE(t.link.OnLowerLayerDown())
boolean tempBool=  0

{OnFrame_in_LinkLayerTest1

    {OnFrame_in_LinkLayer1

        {OnFrame_in_LinkContext1
*        ***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer is not online')***
        }OnFrame_in_LinkContext1_
    }OnFrame_in_LinkLayer_
}OnFrame_in_LinkLayerTest_
REQUIRE_FALSE(t.OnFrame(LinkFunction::SEC_ACK, false, false, false, 1, 2))
boolean tempBool=  0
