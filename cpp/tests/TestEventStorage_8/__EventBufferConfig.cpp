#include "header.h"
#include "EventBufferConfig.h"

EventBufferConfig __AllTypes_in_EventBufferConfig_static(uint16_t sizes);
void __EventBufferConfig_in_EventBufferConfigOver2(EventBufferConfig *pEventBufferConfig,
                                     uint16_t maxBinaryEvents,
                                     uint16_t maxDoubleBinaryEvents,
                                     uint16_t maxAnalogEvents,
                                     uint16_t maxCounterEvents,
                                     uint16_t maxFrozenCounterEvents,
                                     uint16_t maxBinaryOutputStatusEvents,
                                     uint16_t maxAnalogOutputStatusEvents,
                                     uint16_t maxOctetStringEvents);
uint32_t __TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig);

EventBufferConfig __AllTypes_in_EventBufferConfig_static(uint16_t sizes)
{
    EventBufferConfig eEventBufferConfig;
    __EventBufferConfig_in_EventBufferConfigOver2(&eEventBufferConfig, sizes, sizes, sizes, sizes, sizes, sizes, sizes, sizes);
////    return EventBufferConfig(sizes, sizes, sizes, sizes, sizes, sizes, sizes, sizes);
    return eEventBufferConfig;
}

void __EventBufferConfig_in_EventBufferConfigOver2(EventBufferConfig *pEventBufferConfig,
                                     uint16_t maxBinaryEvents,
                                     uint16_t maxDoubleBinaryEvents,
                                     uint16_t maxAnalogEvents,
                                     uint16_t maxCounterEvents,
                                     uint16_t maxFrozenCounterEvents,
                                     uint16_t maxBinaryOutputStatusEvents,
                                     uint16_t maxAnalogOutputStatusEvents,
                                     uint16_t maxOctetStringEvents)
{
      pEventBufferConfig->maxBinaryEvents = maxBinaryEvents;
      pEventBufferConfig->maxDoubleBinaryEvents = maxDoubleBinaryEvents;
      pEventBufferConfig->maxAnalogEvents = maxAnalogEvents;
      pEventBufferConfig->maxCounterEvents = maxCounterEvents;
      pEventBufferConfig->maxFrozenCounterEvents = maxFrozenCounterEvents;
      pEventBufferConfig->maxBinaryOutputStatusEvents = maxBinaryOutputStatusEvents;
      pEventBufferConfig->maxAnalogOutputStatusEvents = maxAnalogOutputStatusEvents;
      pEventBufferConfig->maxOctetStringEvents = maxOctetStringEvents;
}

uint32_t __TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig) 
{
    return pEventBufferConfig->maxBinaryEvents + pEventBufferConfig->maxDoubleBinaryEvents +
           pEventBufferConfig->maxAnalogEvents + pEventBufferConfig->maxCounterEvents + 
           pEventBufferConfig->maxFrozenCounterEvents +
           pEventBufferConfig->maxBinaryOutputStatusEvents + pEventBufferConfig->maxAnalogOutputStatusEvents +
           pEventBufferConfig->maxOctetStringEvents;
}
