
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "EventReceiver.h"

void EventReceiver_in_EventReceiver(EventReceiver *pEventReceiver)
{
 pEventReceiver->count = 0;

 pEventReceiver->iIEventReceiver.pUpdate_BinarySpec_in_IEventReceiver = Update_BinarySpec_in_EventReceiver_override;

 setParentPointer_in_IEventReceiver(&(pEventReceiver->iIEventReceiver), pEventReceiver);
}

void Update_BinarySpec_in_EventReceiver_override(void *pIEventReceiver, Event_for_BinarySpec *pEvent_for_BinarySpec)
{
 EventReceiver *parent = (EventReceiver*) getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);
 Update_BinarySpec_in_EventReceiver(parent, pEvent_for_BinarySpec);
}

void Update_BinarySpec_in_EventReceiver(EventReceiver *pEventReceiver, Event_for_BinarySpec *evt)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Update_BinarySpec_in_EventReceiver1"<<'\n';
  decrement_stack_info();
#endif
////        ++count;
  ++(pEventReceiver->count);
////        latestBinaryEvent = evt;
  pEventReceiver->latestBinaryEvent = *evt;
}
