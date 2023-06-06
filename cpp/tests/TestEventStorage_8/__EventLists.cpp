
#include "header.h"
#include "EventLists.h"

void __EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config);
void __List_for_EventRecord_in_List_for_EventRecordOver2(List_for_EventRecord *pList_for_EventRecord, uint32_t maxSize);
void __EventClassCounters_in_EventClassCounters(EventClassCounters *pEventClassCounters);
uint32_t __TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig);

void __EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config)
{
     __EventClassCounters_in_EventClassCounters(&(pEventLists->counters));
//   uint32_t TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig);
//    pEventLists->events = TotalEvents_in_EventBufferConfig(config);//(config.TotalEvents()),
     __List_for_EventRecord_in_List_for_EventRecordOver2(&(pEventLists->events), __TotalEvents_in_EventBufferConfig(config));
}
