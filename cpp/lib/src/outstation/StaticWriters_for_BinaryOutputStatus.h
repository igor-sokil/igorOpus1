#ifndef OPENDNP3_STATICWRITERS_for_BinaryOutputStatus_H
#define OPENDNP3_STATICWRITERS_for_BinaryOutputStatus_H

#include "StaticWriters.h"
#include "StaticDataMap_for_BinaryOutputStatus.h"
#include "RangeWriteIterator_for_BinaryOutputStatus.h"
#include "StaticBinaryOutputStatusVariation.h"

//----------------------------------------LoadWithRangeIterator_BinaryOutputStatusSpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_BinaryOutputStatusSpec_for_UInt8_in_StaticWriters(StaticDataMap_for_BinaryOutputStatusSpec& map,
    RangeWriteIterator_for_UInt8_BinaryOutputStatus *writer, StaticBinaryOutputStatusVariation_uint8_t variation);

boolean LoadWithRangeIterator_BinaryOutputStatusSpec_for_UInt16_in_StaticWriters(StaticDataMap_for_BinaryOutputStatusSpec& map,
    RangeWriteIterator_for_UInt16_BinaryOutputStatus *writer, StaticBinaryOutputStatusVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_BinaryOutputStatusSpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group10Var------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_BinaryOutputStatusSpec_for_Group10Var2_in_StaticWriters_static(StaticDataMap_for_BinaryOutputStatusSpec& map, HeaderWriter* writer);
//----------------------------------------------Group10Var------------------------------------------

#endif

