#ifndef OPENDNP3_STATICWRITERS_for_AnalogOutputStatus_H
#define OPENDNP3_STATICWRITERS_for_AnalogOutputStatus_H

#include "StaticWriters.h"
#include "StaticDataMap_for_AnalogOutputStatus.h"
#include "RangeWriteIterator_for_AnalogOutputStatus.h"
#include "StaticAnalogOutputStatusVariation.h"

//----------------------------------------LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
    RangeWriteIterator_for_UInt8_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation);

boolean LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_AnalogOutputStatusSpec& map,
    RangeWriteIterator_for_UInt16_AnalogOutputStatus *writer, StaticAnalogOutputStatusVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_AnalogOutputStatusSpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group40Var------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var1_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var2_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var3_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer);
//boolean WriteWithSerializer_AnalogOutputStatusSpec_for_Group40Var4_in_StaticWriters_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer);
//----------------------------------------------Group40Var------------------------------------------

#endif

