
#include "header.h"
#include "EventLists.h"

void __EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config);
void __List_for_EventRecord_in_List_for_EventRecordOver2(List_for_EventRecord *pList_for_EventRecord, uint32_t maxSize);
void __EventClassCounters_in_EventClassCounters(EventClassCounters *pEventClassCounters);
uint32_t __TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig);
boolean __IsAnyTypeFull_in_EventLists(EventLists *pEventLists);
boolean __IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec);
/*
void __EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config)
{
     __EventClassCounters_in_EventClassCounters(&(pEventLists->counters));
//   uint32_t TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig);
//    pEventLists->events = TotalEvents_in_EventBufferConfig(config);//(config.TotalEvents()),
     __List_for_EventRecord_in_List_for_EventRecordOver2(&(pEventLists->events), __TotalEvents_in_EventBufferConfig(config));
}
*/
boolean __IsAnyTypeFull_in_EventLists(EventLists *pEventLists) 
{
return //IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinarySpec(&(pEventLists->binary)) ||
//IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_DoubleBitBinarySpec(&(pEventLists->doubleBinary)) ||
////    return this->binary.IsFullAndCapacityNotZero() || this->doubleBinary.IsFullAndCapacityNotZero()
////        || this->counter.IsFullAndCapacityNotZero() || this->frozenCounter.IsFullAndCapacityNotZero()
//IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_CounterSpec(&(pEventLists->counter)) ||
//IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_FrozenCounterSpec(&(pEventLists->frozenCounter)) ||
////        || this->analog.IsFullAndCapacityNotZero() || this->binaryOutputStatus.IsFullAndCapacityNotZero()
////        || this->analogOutputStatus.IsFullAndCapacityNotZero() || this->octetString.IsFullAndCapacityNotZero();
__IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(&(pEventLists->analog));// ||
//IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(&(pEventLists->analogOutputStatus));
}
