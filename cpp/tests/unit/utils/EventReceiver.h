#ifndef EventReceiver_H
#define EventReceiver_H

#include "StaticDataMap_for_Binary.h"
//#include "Event.h"

////struct EventReceiver : public IEventReceiver
typedef struct
{

    IEventReceiver iIEventReceiver;

    uint16_t count;
    Event_for_BinarySpec latestBinaryEvent;

////    void Update(const Event<BinarySpec>& evt)
////    {
////        ++count;
////        latestBinaryEvent = evt;
////    }

////    void Update(const Event<DoubleBitBinarySpec>& evt)
////    {
////        ++count;
////    }

////    void Update(const Event<AnalogSpec>& evt)
////    {
////        ++count;
////    }

////    void Update(const Event<CounterSpec>& evt)
////    {
////        ++count;
////    }

////    void Update(const Event<FrozenCounterSpec>& evt)
////    {
////        ++count;
////    }

////    void Update(const Event<BinaryOutputStatusSpec>& evt)
////    {
////        ++count;
////    }

////    void Update(const Event<AnalogOutputStatusSpec>& evt)
////    {
////        ++count;
////    }

////    void Update(const Event<OctetStringSpec>& evt)
////    {
////        ++count;
////    }
} EventReceiver;

void EventReceiver_in_EventReceiver(EventReceiver *pEventReceiver);
void Update_BinarySpec_in_EventReceiver(EventReceiver *pEventReceiver, Event_for_BinarySpec *pEvent_for_BinarySpec);
void Update_BinarySpec_in_EventReceiver_override(void *pIEventReceiver, Event_for_BinarySpec *pEvent_for_BinarySpec);


#endif
