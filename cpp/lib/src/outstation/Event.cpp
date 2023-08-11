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
void Event_for_BinarySpec_in_Event_for_BinarySpecOver1(Event_for_BinarySpec *pEvent_for_BinarySpec)
{
  Evented_in_EventedOver1(&(pEvent_for_BinarySpec->eEvented));
  Binary_in_BinaryOver1(&(pEvent_for_BinarySpec->value));
  pEvent_for_BinarySpec->variation = 0;
}

void Event_for_BinarySpec_in_Event_for_BinarySpecOver2(Event_for_BinarySpec *pEvent_for_BinarySpec,
    Binary* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_BinaryInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_BinarySpec->eEvented), index, clazz);
  (pEvent_for_BinarySpec->value) = *value;
  (pEvent_for_BinarySpec->variation) = variation;
}

//--------------------------------BinarySpec-------------------------
//--------------------------------DoubleBitBinarySpec-------------------------
void Event_for_DoubleBitBinarySpec_in_Event_for_DoubleBitBinarySpecOver1(Event_for_DoubleBitBinarySpec *pEvent_for_DoubleBitBinarySpec)
{
  Evented_in_EventedOver1(&(pEvent_for_DoubleBitBinarySpec->eEvented));
  DoubleBitBinary_in_DoubleBitBinaryOver1(&(pEvent_for_DoubleBitBinarySpec->value));
  pEvent_for_DoubleBitBinarySpec->variation = 0;
}

void Event_for_DoubleBitBinarySpec_in_Event_for_DoubleBitBinarySpecOver2(Event_for_DoubleBitBinarySpec *pEvent_for_DoubleBitBinarySpec,
    DoubleBitBinary* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_DoubleBitBinaryInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_DoubleBitBinarySpec->eEvented), index, clazz);
  (pEvent_for_DoubleBitBinarySpec->value) = *value;
  (pEvent_for_DoubleBitBinarySpec->variation) = variation;
}

//--------------------------------DoubleBitBinarySpec-------------------------
//--------------------------------AnalogSpec-------------------------
void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver1(Event_for_AnalogSpec *pEvent_for_AnalogSpec)
{
  Evented_in_EventedOver1(&(pEvent_for_AnalogSpec->eEvented));
  Analog_in_AnalogOver1(&(pEvent_for_AnalogSpec->value));
  pEvent_for_AnalogSpec->variation = 0;
}

void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(Event_for_AnalogSpec *pEvent_for_AnalogSpec,
    Analog* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_AnalogInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_AnalogSpec->eEvented), index, clazz);
  (pEvent_for_AnalogSpec->value) = *value;
  (pEvent_for_AnalogSpec->variation) = variation;
}

//--------------------------------AnalogSpec-------------------------
//--------------------------------CounterSpec-------------------------
void Event_for_CounterSpec_in_Event_for_CounterSpecOver1(Event_for_CounterSpec *pEvent_for_CounterSpec)
{
  Evented_in_EventedOver1(&(pEvent_for_CounterSpec->eEvented));
  Counter_in_CounterOver1(&(pEvent_for_CounterSpec->value));
  pEvent_for_CounterSpec->variation = 0;
}

void Event_for_CounterSpec_in_Event_for_CounterSpecOver2(Event_for_CounterSpec *pEvent_for_CounterSpec,
    Counter* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_CounterInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_CounterSpec->eEvented), index, clazz);
  (pEvent_for_CounterSpec->value) = *value;
  (pEvent_for_CounterSpec->variation) = variation;
}

//--------------------------------CounterSpec-------------------------
//--------------------------------FrozenCounterSpec-------------------------
void Event_for_FrozenCounterSpec_in_Event_for_FrozenCounterSpecOver1(Event_for_FrozenCounterSpec *pEvent_for_FrozenCounterSpec)
{
  Evented_in_EventedOver1(&(pEvent_for_FrozenCounterSpec->eEvented));
  FrozenCounter_in_FrozenCounterOver1(&(pEvent_for_FrozenCounterSpec->value));
  pEvent_for_FrozenCounterSpec->variation = 0;
}

void Event_for_FrozenCounterSpec_in_Event_for_FrozenCounterSpecOver2(Event_for_FrozenCounterSpec *pEvent_for_FrozenCounterSpec,
    FrozenCounter* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_FrozenCounterInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_FrozenCounterSpec->eEvented), index, clazz);
  (pEvent_for_FrozenCounterSpec->value) = *value;
  (pEvent_for_FrozenCounterSpec->variation) = variation;
}

//--------------------------------FrozenCounterSpec-------------------------
//--------------------------------BinaryOutputStatusSpec-------------------------
void Event_for_BinaryOutputStatusSpec_in_Event_for_BinaryOutputStatusSpecOver1(Event_for_BinaryOutputStatusSpec *pEvent_for_BinaryOutputStatusSpec)
{
  Evented_in_EventedOver1(&(pEvent_for_BinaryOutputStatusSpec->eEvented));
  BinaryOutputStatus_in_BinaryOutputStatusOver1(&(pEvent_for_BinaryOutputStatusSpec->value));
  pEvent_for_BinaryOutputStatusSpec->variation = 0;
}

void Event_for_BinaryOutputStatusSpec_in_Event_for_BinaryOutputStatusSpecOver2(Event_for_BinaryOutputStatusSpec *pEvent_for_BinaryOutputStatusSpec,
    BinaryOutputStatus* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_BinaryOutputStatusInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_BinaryOutputStatusSpec->eEvented), index, clazz);
  (pEvent_for_BinaryOutputStatusSpec->value) = *value;
  (pEvent_for_BinaryOutputStatusSpec->variation) = variation;
}

//--------------------------------BinaryOutputStatusSpec-------------------------
//--------------------------------AnalogOutputStatusSpec-------------------------
void Event_for_AnalogOutputStatusSpec_in_Event_for_AnalogOutputStatusSpecOver1(Event_for_AnalogOutputStatusSpec *pEvent_for_AnalogOutputStatusSpec)
{
  Evented_in_EventedOver1(&(pEvent_for_AnalogOutputStatusSpec->eEvented));
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&(pEvent_for_AnalogOutputStatusSpec->value));
  pEvent_for_AnalogOutputStatusSpec->variation = 0;
}

void Event_for_AnalogOutputStatusSpec_in_Event_for_AnalogOutputStatusSpecOver2(Event_for_AnalogOutputStatusSpec *pEvent_for_AnalogOutputStatusSpec,
    AnalogOutputStatus* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_AnalogOutputStatusInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_AnalogOutputStatusSpec->eEvented), index, clazz);
  (pEvent_for_AnalogOutputStatusSpec->value) = *value;
  (pEvent_for_AnalogOutputStatusSpec->variation) = variation;
}

//--------------------------------AnalogOutputStatusSpec-------------------------
//--------------------------------OctetStringSpec-------------------------
void Event_for_OctetStringSpec_in_Event_for_OctetStringSpecOver1(Event_for_OctetStringSpec *pEvent_for_OctetStringSpec)
{
  Evented_in_EventedOver1(&(pEvent_for_OctetStringSpec->eEvented));
  OctetString_in_OctetStringOver1(&(pEvent_for_OctetStringSpec->value));
  pEvent_for_OctetStringSpec->variation = 0;
}

void Event_for_OctetStringSpec_in_Event_for_OctetStringSpecOver2(Event_for_OctetStringSpec *pEvent_for_OctetStringSpec,
    OctetString* value, uint16_t index,
    EventClass_uint8_t clazz,
    event_variation_t_in_OctetStringInfo variation)
{
////        : Evented(index, clazz), value(value), variation(variation)
  Evented_in_EventedOver2(&(pEvent_for_OctetStringSpec->eEvented), index, clazz);
  (pEvent_for_OctetStringSpec->value) = *value;
  (pEvent_for_OctetStringSpec->variation) = variation;
}

//--------------------------------OctetStringSpec-------------------------
