#include "header.h"
#include "IEventReceiver.h"

void Update_BinarySpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_BinarySpec* evt)
{
  (pIEventReceiver->pUpdate_BinarySpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_DoubleBitBinarySpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_DoubleBitBinarySpec* evt)
{
  (pIEventReceiver->pUpdate_DoubleBitBinarySpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_AnalogSpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_AnalogSpec* evt)
{
  (pIEventReceiver->pUpdate_AnalogSpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_CounterSpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_CounterSpec* evt)
{
  (pIEventReceiver->pUpdate_CounterSpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_FrozenCounterSpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_FrozenCounterSpec* evt)
{
  (pIEventReceiver->pUpdate_FrozenCounterSpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_BinaryOutputStatusSpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_BinaryOutputStatusSpec* evt)
{
  (pIEventReceiver->pUpdate_BinaryOutputStatusSpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_AnalogOutputStatusSpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_AnalogOutputStatusSpec* evt)
{
  (pIEventReceiver->pUpdate_AnalogOutputStatusSpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void Update_OctetStringSpec_in_IEventReceiver(IEventReceiver *pIEventReceiver, Event_for_OctetStringSpec* evt)
{
  (pIEventReceiver->pUpdate_OctetStringSpec_in_IEventReceiver)(pIEventReceiver, evt);
}

void* getParentPointer_in_IEventReceiver(IEventReceiver* pIEventReceiver)
{
  return pIEventReceiver->pParentPointer_in_IEventReceiver;
}

void  setParentPointer_in_IEventReceiver(IEventReceiver* pIEventReceiver, void* pParentPointer)
{
  pIEventReceiver->pParentPointer_in_IEventReceiver = pParentPointer;
}
