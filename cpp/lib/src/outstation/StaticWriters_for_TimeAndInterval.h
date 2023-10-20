#ifndef OPENDNP3_STATICWRITERS_for_TimeAndInterval_H
#define OPENDNP3_STATICWRITERS_for_TimeAndInterval_H

#include "StaticWriters.h"
#include "StaticDataMap_for_TimeAndInterval.h"
#include "RangeWriteIterator_for_TimeAndInterval.h"
#include "StaticTimeAndIntervalVariation.h"

//----------------------------------------LoadWithRangeIterator_TimeAndIntervalSpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_TimeAndIntervalSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_TimeAndIntervalSpec& map,
    RangeWriteIterator_for_UInt8_TimeAndInterval *writer, StaticTimeAndIntervalVariation_uint8_t variation);

boolean LoadWithRangeIterator_TimeAndIntervalSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_TimeAndIntervalSpec& map,
    RangeWriteIterator_for_UInt16_TimeAndInterval *writer, StaticTimeAndIntervalVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_TimeAndIntervalSpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group50Var4------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_TimeAndIntervalSpec_for_Group50Var4_in_StaticWriters_static(StaticDataMap_for_TimeAndIntervalSpec& map, HeaderWriter* writer);
//----------------------------------------------Group50Var4------------------------------------------

#endif

