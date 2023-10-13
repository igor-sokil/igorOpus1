#ifndef OPENDNP3_STATICWRITERS_for_Binary_H
#define OPENDNP3_STATICWRITERS_for_Binary_H

#include "StaticWriters.h"
#include "StaticDataMap_for_Binary.h"
#include "RangeWriteIterator_for_Binary.h"
#include "StaticBinaryVariation.h"

//----------------------------------------LoadWithRangeIterator_BinarySpec_for_UInt---------------------------------------------------------
boolean LoadWithRangeIterator_BinarySpec_for_UInt8_in_StaticWriters(StaticDataMap_for_BinarySpec& map,
    RangeWriteIterator_for_UInt8_Binary *writer, StaticBinaryVariation_uint8_t variation);

boolean LoadWithRangeIterator_BinarySpec_for_UInt16_in_StaticWriters(StaticDataMap_for_BinarySpec& map,
    RangeWriteIterator_for_UInt16_Binary *writer, StaticBinaryVariation_uint8_t variation);

//----------------------------------------LoadWithRangeIterator_BinarySpec_for_UInt---------------------------------------------------------

boolean LoadWithBitfieldIterator_BinarySpec_for_UInt8(StaticDataMap_for_BinarySpec& map, BitfieldRangeWriteIterator_for_UInt8 *iter, StaticBinaryVariation_uint8_t variation);
boolean LoadWithBitfieldIterator_BinarySpec_for_UInt16(StaticDataMap_for_BinarySpec& map, BitfieldRangeWriteIterator_for_UInt16 *iter, StaticBinaryVariation_uint8_t variation);



#endif

