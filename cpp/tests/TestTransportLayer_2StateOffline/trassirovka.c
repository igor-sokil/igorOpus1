********SUITE('1RepeatSendsDoNotLogOrChangeStatistics')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421360
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048



    BufferSer4_in_BufferSer4Over2_1
*    *uint16_t length=1

*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer offline')
REQUIRE_FALSE(test.upper.SendDown('00'))
boolean btmp= 0

*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer offline')
REQUIRE_FALSE(test.link.SendUp(''))
boolean btmp= 0

*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer offline')
REQUIRE_FALSE(test.transport.OnTxReady())
boolean btmp= 0

*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already offline')
REQUIRE_FALSE(test.transport.OnLowerLayerDown())
boolean btmp= 0
