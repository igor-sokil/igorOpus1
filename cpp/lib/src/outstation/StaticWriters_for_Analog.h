#ifndef OPENDNP3_STATICWRITERS_for_Analog_H
#define OPENDNP3_STATICWRITERS_for_Analog_H

#include "StaticWriters.h"
#include "StaticDataMap_for_Analog.h"
#include "RangeWriteIterator_for_Analog.h"
#include "StaticAnalogVariation.h"

//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_AnalogSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
    RangeWriteIterator_for_UInt8_Analog *writer, StaticAnalogVariation_uint8_t variation);

boolean LoadWithRangeIterator_AnalogSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_AnalogSpec& map,
    RangeWriteIterator_for_UInt16_Analog *writer, StaticAnalogVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_AnalogSpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group30Var------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_AnalogSpec_for_Group30Var1_in_StaticWriters_static(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer);
boolean WriteWithSerializer_AnalogSpec_for_Group30Var2_in_StaticWriters_static(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer);
//----------------------------------------------Group30Var------------------------------------------

#endif

