#ifndef OPENDNP3_STATICWRITERS_for_Counter_H
#define OPENDNP3_STATICWRITERS_for_Counter_H

#include "StaticWriters.h"
#include "StaticDataMap_for_Counter.h"
#include "RangeWriteIterator_for_Counter.h"
#include "StaticCounterVariation.h"

//----------------------------------------LoadWithRangeIterator_CounterSpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_CounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
    RangeWriteIterator_for_UInt8_Counter *writer, StaticCounterVariation_uint8_t variation);

boolean LoadWithRangeIterator_CounterSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_CounterSpec& map,
    RangeWriteIterator_for_UInt16_Counter *writer, StaticCounterVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_CounterSpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group20Var------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_CounterSpec_for_Group20Var1_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_CounterSpec_for_Group20Var2_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_CounterSpec_for_Group20Var5_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_CounterSpec_for_Group20Var6_in_StaticWriters_static(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer);
//----------------------------------------------Group20Var------------------------------------------

#endif

