#ifndef OPENDNP3_STATICWRITERS_for_DoubleBitBinary_H
#define OPENDNP3_STATICWRITERS_for_DoubleBitBinary_H

#include "StaticWriters.h"
#include "StaticDataMap_for_DoubleBitBinary.h"
#include "RangeWriteIterator_for_DoubleBitBinary.h"
#include "StaticDoubleBinaryVariation.h"

//----------------------------------------LoadWithRangeIterator_DoubleBitBinarySpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_DoubleBitBinarySpec_for_UInt8_in_StaticWriters(StaticDataMap_for_DoubleBitBinarySpec& map,
    RangeWriteIterator_for_UInt8_DoubleBitBinary *writer, StaticDoubleBinaryVariation_uint8_t variation);

boolean LoadWithRangeIterator_DoubleBitBinarySpec_for_UInt16_in_StaticWriters(StaticDataMap_for_DoubleBitBinarySpec& map,
    RangeWriteIterator_for_UInt16_DoubleBitBinary *writer, StaticDoubleBinaryVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_DoubleBitBinarySpec_for_UInt---------------------------------------------------------
//----------------------------------------------Group3Var2------------------------------------------

////template<class Spec, class Serializer> bool WriteWithSerializer(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean WriteWithSerializer_DoubleBitBinarySpec_for_Group3Var2_in_StaticWriters_static(StaticDataMap_for_DoubleBitBinarySpec& map, HeaderWriter* writer);
//----------------------------------------------Group3Var2------------------------------------------

#endif

