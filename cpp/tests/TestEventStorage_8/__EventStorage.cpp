#include "header.h"
#include "EventStorage.h"

#include "EventSelection.h"
#include "EventUpdate.h"
#include "EventWriting.h"

void __EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config);
void __EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config);
uint32_t __NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz);
uint32_t __Get_in_ClazzCount(ClazzCount *pClazzCount, EventClass_uint8_t clazz);

void __EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config)
{
 ////: state(config) {}
  __EventLists_in_EventLists(&(pEventStorage->state), config);
}

uint32_t __NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz)
{
////  return this->state.counters.total.Get(clazz) - this->state.counters.written.Get(clazz);
  return __Get_in_ClazzCount(&((pEventStorage->state).counters.total), clazz) -
         __Get_in_ClazzCount(&((pEventStorage->state).counters.written), clazz);
}
