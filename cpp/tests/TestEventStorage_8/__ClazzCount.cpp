#include "header.h"
#include "ClazzCount.h"

void __EventClassCounters_in_EventClassCounters(EventClassCounters *pEventClassCounters);
void __ClazzCount_in_ClazzCount(ClazzCount* pClazzCount);
uint32_t __Get_in_ClazzCount(ClazzCount *pClazzCount, EventClass_uint8_t clazz);

void __EventClassCounters_in_EventClassCounters(EventClassCounters *pEventClassCounters)
{
  pEventClassCounters->selected = 0;
  __ClazzCount_in_ClazzCount(&(pEventClassCounters->total));
  __ClazzCount_in_ClazzCount(&(pEventClassCounters->written));
}

void __ClazzCount_in_ClazzCount(ClazzCount* pClazzCount)
{
  pClazzCount->num_class_1 = 0;
  pClazzCount->num_class_2 = 0;
  pClazzCount->num_class_3 = 0;
}

uint32_t __Get_in_ClazzCount(ClazzCount *pClazzCount, EventClass_uint8_t clazz)
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
