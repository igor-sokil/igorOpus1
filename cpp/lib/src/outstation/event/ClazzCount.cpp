#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ClazzCount.h"

void Reset_in_ClazzCount(ClazzCount *pClazzCount)
{
  pClazzCount->num_class_1 = 0;
  pClazzCount->num_class_2 = 0;
  pClazzCount->num_class_3 = 0;
}

uint32_t Get_in_ClazzCount(ClazzCount *pClazzCount, EventClass_uint8_t clazz)
{
  switch (clazz)
  {
  case (EventClass_EC1):
    return pClazzCount->num_class_1;
  case (EventClass_EC2):
    return pClazzCount->num_class_2;
    break;
  default:
    return pClazzCount->num_class_3;
  }
}

void Increment_in_ClazzCount(ClazzCount *pClazzCount, EventClass_uint8_t clazz)
{
  switch (clazz)
  {
  case (EventClass_EC1):
    ++(pClazzCount->num_class_1);
    break;
  case (EventClass_EC2):
    ++(pClazzCount->num_class_2);
    break;
  default:
    ++(pClazzCount->num_class_3);
    break;
  }
}

void Decrement_in_ClazzCount(ClazzCount *pClazzCount, EventClass_uint8_t clazz)
{
  switch (clazz)
  {
  case (EventClass_EC1):
    --(pClazzCount->num_class_1);
    break;
  case (EventClass_EC2):
    --(pClazzCount->num_class_2);
    break;
  default:
    --(pClazzCount->num_class_3);
    break;
  }
}

boolean Any_in_ClazzCount(ClazzCount *pClazzCount)
{
  return (pClazzCount->num_class_1 > 0) || (pClazzCount->num_class_2 > 0) || (pClazzCount->num_class_3 > 0);
}

void ClazzCount_in_ClazzCount(ClazzCount* pClazzCount)
{
  pClazzCount->num_class_1 = 0;
  pClazzCount->num_class_2 = 0;
  pClazzCount->num_class_3 = 0;
}

void EventClassCounters_in_EventClassCounters(EventClassCounters *pEventClassCounters)
{
  pEventClassCounters->selected = 0;
  ClazzCount_in_ClazzCount(&(pEventClassCounters->total));
  ClazzCount_in_ClazzCount(&(pEventClassCounters->written));
}

void OnAdd_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz)
{
////        (pEventClassCounters->total).Increment(clazz);
  Increment_in_ClazzCount(&(pEventClassCounters->total), clazz);
}

void OnSelect_in_EventClassCounters(EventClassCounters *pEventClassCounters)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnSelect_in_EventClassCounters1"<<'\n';
  decrement_stack_info();
#endif
  ++(pEventClassCounters->selected);
}

void OnWrite_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz)
{
  // only selected events are written
////        --selected;
  --(pEventClassCounters->selected);
////        this->written.Increment(clazz);
  Increment_in_ClazzCount(&(pEventClassCounters->written), clazz);
}

void ResetOnFail_in_EventClassCounters(EventClassCounters *pEventClassCounters)
{
  pEventClassCounters->selected = 0;
////        this->written.Reset();
  Reset_in_ClazzCount(&(pEventClassCounters->written));
}

void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state)
{
  switch (state)
  {
  case (EventState_selected):
////            --selected;
    --(pEventClassCounters->selected);
    break;
  case (EventState_written):
////            this->written.Decrement(clazz);
    Decrement_in_ClazzCount(&(pEventClassCounters->written), clazz);
    break;
  default:
    break;
  }

////        this->total.Decrement(clazz);
  Decrement_in_ClazzCount(&(pEventClassCounters->total), clazz);
}
