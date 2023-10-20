#ifndef OPENDNP3_STATICWRITERS_for_FrozenCounter_H
#define OPENDNP3_STATICWRITERS_for_FrozenCounter_H

#include "StaticWriters.h"
#include "StaticDataMap_for_FrozenCounter.h"
#include "RangeWriteIterator_for_FrozenCounter.h"
#include "StaticFrozenCounterVariation.h"

//----------------------------------------LoadWithRangeIterator_FrozenCounterSpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
    RangeWriteIterator_for_UInt8_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation);

boolean LoadWithRangeIterator_FrozenCounterSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_FrozenCounterSpec& map,
    RangeWriteIterator_for_UInt16_FrozenCounter *writer, StaticFrozenCounterVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_FrozenCounterSpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group21Var------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var1_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var2_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var5_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var6_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var9_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_FrozenCounterSpec_for_Group21Var10_in_StaticWriters_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);
//----------------------------------------------Group21Var------------------------------------------

#endif

