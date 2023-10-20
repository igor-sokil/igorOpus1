#ifndef OPENDNP3_STATICWRITERS_for_OctetString_H
#define OPENDNP3_STATICWRITERS_for_OctetString_H

#include "StaticWriters.h"
#include "StaticDataMap_for_OctetString.h"
#include "RangeWriteIterator_for_OctetString.h"
//#include "StaticOctetStringVariation.h"

boolean write_some_octet_strings_for_UInt16_in_StaticWriters_static(StaticDataMap_for_OctetStringSpec& map, RangeWriteIterator_for_UInt16_OctetString* writer);
boolean write_some_octet_strings_for_UInt8_in_StaticWriters_static(StaticDataMap_for_OctetStringSpec& map, RangeWriteIterator_for_UInt8_OctetString* writer);
boolean write_octet_strings_in_StaticWriters_static(StaticDataMap_for_OctetStringSpec& map, HeaderWriter* writer);

#endif

