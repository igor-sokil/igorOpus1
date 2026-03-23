********SUITE('1notifies application of state changes')********

{MockExecutor_in_MockExecutor1
*MockExecutor *pMockExecutor= 6421512
}MockExecutor_in_MockExecutor_

BufferSer4_in_BufferSer4Over2_1
**uint16_t length=2048
**uint8_t bytes[SIZE_BufferSer4]=1764126934
-----REQUIRE(t.application->stateChanges.empty())
boolean btemp= 1
    {OnLowerLayerUp_in_MContext1
        {Initialize_in_MasterTasks1
        }Initialize_in_MasterTasks_

OnOpen_in_MockMasterApplication1
    }OnLowerLayerUp_in_MContext2_
-----REQUIRE(t.application->stateChanges.size() == 1)
boolean btemp= 1
-----REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::OPEN))
State_in_MockMasterApplication_OPEN= 0
uint8_t dtemp= 0
    {OnLowerLayerDown_in_MContext1

        {cancel_in_TimerExe4cpp1
        *TimerExe4cpp *pTimerExe4cpp= 1764126836
        *pTimerExe4cpp->timerExe4cpp.psource_in_ITimer= 0
        }cancel_in_TimerExe4cpp1_

OnClose_in_MockMasterApplication1
    }OnLowerLayerDown_in_MContext2_
-----REQUIRE(t.application->stateChanges.size() == 1)
boolean btemp= 1
-----REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::CLOSED))
State_in_MockMasterApplication_CLOSED= 1
uint8_t dtemp= 1
