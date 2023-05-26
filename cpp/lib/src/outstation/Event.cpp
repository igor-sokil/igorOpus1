#include "header.h"
#include "Event.h"

   void Evented_in_EventedOver2(Evented *pEvented, uint16_t index, EventClass_uint8_t clazz)
{
  pEvented->index = index;
  pEvented->clazz = clazz;
}

   void Evented_in_EventedOver1(Evented *pEvented)
{
  pEvented->index = 0;
  pEvented->clazz = EventClass_EC1;
}

//--------------------------------BinarySpec-------------------------
   void Event_for_BinarySpec_in_Event_for_BinarySpec(Event_for_BinarySpec *pEvent_for_BinarySpec,
                                                  Binary* value, uint16_t index,
                                                  EventClass_uint8_t clazz,
                                                  event_variation_t_in_BinaryInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
    Evented_in_EventedOver2(&(pEvent_for_BinarySpec->eEvented), index, clazz);
  (pEvent_for_BinarySpec->bBinary) = *value;
  (pEvent_for_BinarySpec->variation) = variation;
    }

//--------------------------------BinarySpec-------------------------
