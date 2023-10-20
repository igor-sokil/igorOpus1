#ifndef OPENDNP3_STATICDATAMAP_H
#define OPENDNP3_STATICDATAMAP_H

#include "PointClass.h"
#include "StaticDataMap_for_TimeAndInterval.h"

boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);

boolean update_in_StaticDataMap_for_TimeAndIntervalSpecOver1(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec,
    TimeAndInterval* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver);

StaticBinaryVariation_uint8_t check_for_promotion_for_BinarySpec_static(Binary* value, StaticBinaryVariation_uint8_t variation);

#endif
