#ifndef OPENDNP3_DATABASE_FOR_ANALOG_H
#define OPENDNP3_DATABASE_FOR_ANALOG_H

#include "StaticDataMap_for_AnalogMrzs.h"////!
#include "StaticWritersMrzs.h"


boolean load_type_for_Analog_in_DatabaseMrzs_static(StaticDataMap_for_AnalogMrzs* map, HeaderWriter* writer);
IINField select_range_for_AnalogMrzs_in_Database_staticOver2(StaticDataMap_for_AnalogMrzs* map,
    Range* range, StaticAnalogVariation_uint8_t variation);

IINField select_all_StaticDataMap_for_AnalogMrzs_in_Database_staticOver2(StaticDataMap_for_AnalogMrzs* map, StaticAnalogVariation_uint8_t var);

#endif