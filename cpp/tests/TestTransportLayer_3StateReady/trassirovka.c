********SUITE('3StateReady')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421360
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048



    {OnLowerLayerUp_in_TransportLayer1

{OnLowerLayerUp_in_MockUpperLayer1
}OnLowerLayerUp_in_MockUpperLayer_
    }OnLowerLayerUp_in_TransportLayer2_
REQUIRE(test.upper.IsOnline())
boolean btmp= 1

{OnLowerLayerDown_in_MockUpperLayer1
}OnLowerLayerDown_in_MockUpperLayer_
REQUIRE_FALSE(test.upper.IsOnline())
boolean btmp= 0

    {OnLowerLayerUp_in_TransportLayer1

{OnLowerLayerUp_in_MockUpperLayer1
}OnLowerLayerUp_in_MockUpperLayer_
    }OnLowerLayerUp_in_TransportLayer2_
REQUIRE(test.upper.IsOnline())
boolean btmp= 1

    {OnLowerLayerUp_in_TransportLayer1
*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already online')
    }OnLowerLayerUp_in_TransportLayer1_
REQUIRE_FALSE(test.transport.OnLowerLayerUp())
boolean btmp= 0

    {OnTxReady_in_TransportLayer1
*    *SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Invalid send callback')
    }OnTxReady_in_TransportLayer2_
REQUIRE_FALSE(test.transport.OnTxReady())
boolean btmp= 0
