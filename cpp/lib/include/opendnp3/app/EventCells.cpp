#include "header.h"
#include "EventCells.h"
#include "MeasurementTypeSpecs.h"
#include <string.h>
//---------------------------------Analog---------------------------------------
void SetEventValue_in_EventCellBase_for_Analog(EventCellBase_for_Analog *pEventCellBase_for_Analog, Analog* value)
{
  pEventCellBase_for_Analog->lastEvent = *value;
}

void EventCellBase_for_Analog_in_EventCellBase_for_Analog(EventCellBase_for_Analog *pEventCellBase_for_Analog)
{
  pEventCellBase_for_Analog->clazz = PointClass_Class1;
  Analog_in_AnalogOver1(&(pEventCellBase_for_Analog->lastEvent));
  pEventCellBase_for_Analog->evariation = 0;
}

void SimpleEventCell_for_Analog_in_SimpleEventCell_for_Analog(SimpleEventCell_for_Analog *pSimpleEventCell_for_Analog)
{
  EventCellBase_for_Analog_in_EventCellBase_for_Analog(&(pSimpleEventCell_for_Analog->eEventCellBase_for_Analog));
}

boolean IsEvent_in_SimpleEventCell_for_Analog(SimpleEventCell_for_Analog *pSimpleEventCell_for_Analog,
    AnalogConfig *config,
    Analog* new_value)
{
  UNUSED(config);
//boolean IsEvent_in_SimpleEventCell_for_Analog(SimpleEventCell_for_Analog *pSimpleEventCell_for_Analog,
//    AnalogConfig *config,
//    Analog* newValue);
////        return Spec::IsEvent(this->lastEvent, newValue);
    return IsEvent_in_AnalogSpec_static(&((pSimpleEventCell_for_Analog->eEventCellBase_for_Analog).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_Analog_in_DeadbandEventCell_for_Analog(DeadbandEventCell_for_Analog *pDeadbandEventCell_for_Analog)
{
  SimpleEventCell_for_Analog_in_SimpleEventCell_for_Analog(&(pDeadbandEventCell_for_Analog->sSimpleEventCell_for_Analog));
}

boolean IsEvent_in_DeadbandEventCell_for_Analog(DeadbandEventCell_for_Analog *pDeadbandEventCell_for_Analog,
    AnalogConfig *config,
    Analog* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_AnalogSpec_static(&((pDeadbandEventCell_for_Analog->sSimpleEventCell_for_Analog.eEventCellBase_for_Analog).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------Analog---------------------------------------
//---------------------------------Binary---------------------------------------
void SetEventValue_in_EventCellBase_for_Binary(EventCellBase_for_Binary *pEventCellBase_for_Binary, Binary* value)
{
  pEventCellBase_for_Binary->lastEvent = *value;
}

void EventCellBase_for_Binary_in_EventCellBase_for_Binary(EventCellBase_for_Binary *pEventCellBase_for_Binary)
{
  pEventCellBase_for_Binary->clazz = PointClass_Class1;
  Binary_in_BinaryOver1(&(pEventCellBase_for_Binary->lastEvent));
  pEventCellBase_for_Binary->evariation = 0;
}

void SimpleEventCell_for_Binary_in_SimpleEventCell_for_Binary(SimpleEventCell_for_Binary *pSimpleEventCell_for_Binary)
{
  EventCellBase_for_Binary_in_EventCellBase_for_Binary(&(pSimpleEventCell_for_Binary->eEventCellBase_for_Binary));
}

boolean IsEvent_in_SimpleEventCell_for_Binary(SimpleEventCell_for_Binary *pSimpleEventCell_for_Binary,
    BinaryConfig *config,
    Binary* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_BinarySpec_static(Binary *old_value,
//                                         Binary *new_value,
//                                         BinaryConfig_for_EventConfig_for_BinaryInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_BinarySpec_static(&((pSimpleEventCell_for_Binary->eEventCellBase_for_Binary).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_Binary_in_DeadbandEventCell_for_Binary(DeadbandEventCell_for_Binary *pDeadbandEventCell_for_Binary)
{
  SimpleEventCell_for_Binary_in_SimpleEventCell_for_Binary(&(pDeadbandEventCell_for_Binary->sSimpleEventCell_for_Binary));
}

boolean IsEvent_in_DeadbandEventCell_for_Binary(DeadbandEventCell_for_Binary *pDeadbandEventCell_for_Binary,
    BinaryConfig *config,
    Binary* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_BinarySpec_static(&((pDeadbandEventCell_for_Binary->sSimpleEventCell_for_Binary.eEventCellBase_for_Binary).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------Binary---------------------------------------
//---------------------------------DoubleBitBinary---------------------------------------
void SetEventValue_in_EventCellBase_for_DoubleBitBinary(EventCellBase_for_DoubleBitBinary *pEventCellBase_for_DoubleBitBinary, DoubleBitBinary* value)
{
  pEventCellBase_for_DoubleBitBinary->lastEvent = *value;
}

void EventCellBase_for_DoubleBitBinary_in_EventCellBase_for_DoubleBitBinary(EventCellBase_for_DoubleBitBinary *pEventCellBase_for_DoubleBitBinary)
{
  pEventCellBase_for_DoubleBitBinary->clazz = PointClass_Class1;
  DoubleBitBinary_in_DoubleBitBinaryOver1(&(pEventCellBase_for_DoubleBitBinary->lastEvent));
  pEventCellBase_for_DoubleBitBinary->evariation = 0;
}

void SimpleEventCell_for_DoubleBitBinary_in_SimpleEventCell_for_DoubleBitBinary(SimpleEventCell_for_DoubleBitBinary *pSimpleEventCell_for_DoubleBitBinary)
{
  EventCellBase_for_DoubleBitBinary_in_EventCellBase_for_DoubleBitBinary(&(pSimpleEventCell_for_DoubleBitBinary->eEventCellBase_for_DoubleBitBinary));
}

boolean IsEvent_in_SimpleEventCell_for_DoubleBitBinary(SimpleEventCell_for_DoubleBitBinary *pSimpleEventCell_for_DoubleBitBinary,
    DoubleBitBinaryConfig *config,
    DoubleBitBinary* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_DoubleBitBinarySpec_static(DoubleBitBinary *old_value,
//                                         DoubleBitBinary *new_value,
//                                         DoubleBitBinaryConfig_for_EventConfig_for_DoubleBitBinaryInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_DoubleBitBinarySpec_static(&((pSimpleEventCell_for_DoubleBitBinary->eEventCellBase_for_DoubleBitBinary).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_DoubleBitBinary_in_DeadbandEventCell_for_DoubleBitBinary(DeadbandEventCell_for_DoubleBitBinary *pDeadbandEventCell_for_DoubleBitBinary)
{
  SimpleEventCell_for_DoubleBitBinary_in_SimpleEventCell_for_DoubleBitBinary(&(pDeadbandEventCell_for_DoubleBitBinary->sSimpleEventCell_for_DoubleBitBinary));
}

boolean IsEvent_in_DeadbandEventCell_for_DoubleBitBinary(DeadbandEventCell_for_DoubleBitBinary *pDeadbandEventCell_for_DoubleBitBinary,
    DoubleBitBinaryConfig *config,
    DoubleBitBinary* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_DoubleBitBinarySpec_static(&((pDeadbandEventCell_for_DoubleBitBinary->sSimpleEventCell_for_DoubleBitBinary.eEventCellBase_for_DoubleBitBinary).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------DoubleBitBinary---------------------------------------
//---------------------------------Counter---------------------------------------
void SetEventValue_in_EventCellBase_for_Counter(EventCellBase_for_Counter *pEventCellBase_for_Counter, Counter* value)
{
  pEventCellBase_for_Counter->lastEvent = *value;
}

void EventCellBase_for_Counter_in_EventCellBase_for_Counter(EventCellBase_for_Counter *pEventCellBase_for_Counter)
{
  pEventCellBase_for_Counter->clazz = PointClass_Class1;
  Counter_in_CounterOver1(&(pEventCellBase_for_Counter->lastEvent));
  pEventCellBase_for_Counter->evariation = 0;
}

void SimpleEventCell_for_Counter_in_SimpleEventCell_for_Counter(SimpleEventCell_for_Counter *pSimpleEventCell_for_Counter)
{
  EventCellBase_for_Counter_in_EventCellBase_for_Counter(&(pSimpleEventCell_for_Counter->eEventCellBase_for_Counter));
}

boolean IsEvent_in_SimpleEventCell_for_Counter(SimpleEventCell_for_Counter *pSimpleEventCell_for_Counter,
    CounterConfig *config,
    Counter* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_CounterSpec_static(Counter *old_value,
//                                         Counter *new_value,
//                                         CounterConfig_for_EventConfig_for_CounterInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_CounterSpec_static(&((pSimpleEventCell_for_Counter->eEventCellBase_for_Counter).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_Counter_in_DeadbandEventCell_for_Counter(DeadbandEventCell_for_Counter *pDeadbandEventCell_for_Counter)
{
  SimpleEventCell_for_Counter_in_SimpleEventCell_for_Counter(&(pDeadbandEventCell_for_Counter->sSimpleEventCell_for_Counter));
}

boolean IsEvent_in_DeadbandEventCell_for_Counter(DeadbandEventCell_for_Counter *pDeadbandEventCell_for_Counter,
    CounterConfig *config,
    Counter* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_CounterSpec_static(&((pDeadbandEventCell_for_Counter->sSimpleEventCell_for_Counter.eEventCellBase_for_Counter).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------Counter---------------------------------------
//---------------------------------FrozenCounter---------------------------------------
void SetEventValue_in_EventCellBase_for_FrozenCounter(EventCellBase_for_FrozenCounter *pEventCellBase_for_FrozenCounter, FrozenCounter* value)
{
  pEventCellBase_for_FrozenCounter->lastEvent = *value;
}

void EventCellBase_for_FrozenCounter_in_EventCellBase_for_FrozenCounter(EventCellBase_for_FrozenCounter *pEventCellBase_for_FrozenCounter)
{
  pEventCellBase_for_FrozenCounter->clazz = PointClass_Class1;
  FrozenCounter_in_FrozenCounterOver1(&(pEventCellBase_for_FrozenCounter->lastEvent));
  pEventCellBase_for_FrozenCounter->evariation = 0;
}

void SimpleEventCell_for_FrozenCounter_in_SimpleEventCell_for_FrozenCounter(SimpleEventCell_for_FrozenCounter *pSimpleEventCell_for_FrozenCounter)
{
  EventCellBase_for_FrozenCounter_in_EventCellBase_for_FrozenCounter(&(pSimpleEventCell_for_FrozenCounter->eEventCellBase_for_FrozenCounter));
}

boolean IsEvent_in_SimpleEventCell_for_FrozenCounter(SimpleEventCell_for_FrozenCounter *pSimpleEventCell_for_FrozenCounter,
    FrozenCounterConfig *config,
    FrozenCounter* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_FrozenCounterSpec_static(FrozenCounter *old_value,
//                                         FrozenCounter *new_value,
//                                         FrozenCounterConfig_for_EventConfig_for_FrozenCounterInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_FrozenCounterSpec_static(&((pSimpleEventCell_for_FrozenCounter->eEventCellBase_for_FrozenCounter).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_FrozenCounter_in_DeadbandEventCell_for_FrozenCounter(DeadbandEventCell_for_FrozenCounter *pDeadbandEventCell_for_FrozenCounter)
{
  SimpleEventCell_for_FrozenCounter_in_SimpleEventCell_for_FrozenCounter(&(pDeadbandEventCell_for_FrozenCounter->sSimpleEventCell_for_FrozenCounter));
}

boolean IsEvent_in_DeadbandEventCell_for_FrozenCounter(DeadbandEventCell_for_FrozenCounter *pDeadbandEventCell_for_FrozenCounter,
    FrozenCounterConfig *config,
    FrozenCounter* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_FrozenCounterSpec_static(&((pDeadbandEventCell_for_FrozenCounter->sSimpleEventCell_for_FrozenCounter.eEventCellBase_for_FrozenCounter).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------FrozenCounter---------------------------------------
//---------------------------------BinaryOutputStatus---------------------------------------
void SetEventValue_in_EventCellBase_for_BinaryOutputStatus(EventCellBase_for_BinaryOutputStatus *pEventCellBase_for_BinaryOutputStatus, BinaryOutputStatus* value)
{
  pEventCellBase_for_BinaryOutputStatus->lastEvent = *value;
}

void EventCellBase_for_BinaryOutputStatus_in_EventCellBase_for_BinaryOutputStatus(EventCellBase_for_BinaryOutputStatus *pEventCellBase_for_BinaryOutputStatus)
{
  pEventCellBase_for_BinaryOutputStatus->clazz = PointClass_Class1;
  BinaryOutputStatus_in_BinaryOutputStatusOver1(&(pEventCellBase_for_BinaryOutputStatus->lastEvent));
  pEventCellBase_for_BinaryOutputStatus->evariation = 0;
}

void SimpleEventCell_for_BinaryOutputStatus_in_SimpleEventCell_for_BinaryOutputStatus(SimpleEventCell_for_BinaryOutputStatus *pSimpleEventCell_for_BinaryOutputStatus)
{
  EventCellBase_for_BinaryOutputStatus_in_EventCellBase_for_BinaryOutputStatus(&(pSimpleEventCell_for_BinaryOutputStatus->eEventCellBase_for_BinaryOutputStatus));
}

boolean IsEvent_in_SimpleEventCell_for_BinaryOutputStatus(SimpleEventCell_for_BinaryOutputStatus *pSimpleEventCell_for_BinaryOutputStatus,
    BOStatusConfig *config,
    BinaryOutputStatus* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_BinaryOutputStatusSpec_static(BinaryOutputStatus *old_value,
//                                         BinaryOutputStatus *new_value,
//                                         BinaryOutputStatusConfig_for_EventConfig_for_BinaryOutputStatusInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_BinaryOutputStatusSpec_static(&((pSimpleEventCell_for_BinaryOutputStatus->eEventCellBase_for_BinaryOutputStatus).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_BinaryOutputStatus_in_DeadbandEventCell_for_BinaryOutputStatus(DeadbandEventCell_for_BinaryOutputStatus *pDeadbandEventCell_for_BinaryOutputStatus)
{
  SimpleEventCell_for_BinaryOutputStatus_in_SimpleEventCell_for_BinaryOutputStatus(&(pDeadbandEventCell_for_BinaryOutputStatus->sSimpleEventCell_for_BinaryOutputStatus));
}

boolean IsEvent_in_DeadbandEventCell_for_BinaryOutputStatus(DeadbandEventCell_for_BinaryOutputStatus *pDeadbandEventCell_for_BinaryOutputStatus,
    BOStatusConfig *config,
    BinaryOutputStatus* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_BinaryOutputStatusSpec_static(&((pDeadbandEventCell_for_BinaryOutputStatus->sSimpleEventCell_for_BinaryOutputStatus.eEventCellBase_for_BinaryOutputStatus).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------BinaryOutputStatus---------------------------------------
//---------------------------------AnalogOutputStatus---------------------------------------
void SetEventValue_in_EventCellBase_for_AnalogOutputStatus(EventCellBase_for_AnalogOutputStatus *pEventCellBase_for_AnalogOutputStatus, AnalogOutputStatus* value)
{
  pEventCellBase_for_AnalogOutputStatus->lastEvent = *value;
}

void EventCellBase_for_AnalogOutputStatus_in_EventCellBase_for_AnalogOutputStatus(EventCellBase_for_AnalogOutputStatus *pEventCellBase_for_AnalogOutputStatus)
{
  pEventCellBase_for_AnalogOutputStatus->clazz = PointClass_Class1;
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&(pEventCellBase_for_AnalogOutputStatus->lastEvent));
  pEventCellBase_for_AnalogOutputStatus->evariation = 0;
}

void SimpleEventCell_for_AnalogOutputStatus_in_SimpleEventCell_for_AnalogOutputStatus(SimpleEventCell_for_AnalogOutputStatus *pSimpleEventCell_for_AnalogOutputStatus)
{
  EventCellBase_for_AnalogOutputStatus_in_EventCellBase_for_AnalogOutputStatus(&(pSimpleEventCell_for_AnalogOutputStatus->eEventCellBase_for_AnalogOutputStatus));
}

boolean IsEvent_in_SimpleEventCell_for_AnalogOutputStatus(SimpleEventCell_for_AnalogOutputStatus *pSimpleEventCell_for_AnalogOutputStatus,
    AOStatusConfig *config,
    AnalogOutputStatus* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_AnalogOutputStatusSpec_static(AnalogOutputStatus *old_value,
//                                         AnalogOutputStatus *new_value,
//                                         AnalogOutputStatusConfig_for_EventConfig_for_AnalogOutputStatusInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_AnalogOutputStatusSpec_static(&((pSimpleEventCell_for_AnalogOutputStatus->eEventCellBase_for_AnalogOutputStatus).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_AnalogOutputStatus_in_DeadbandEventCell_for_AnalogOutputStatus(DeadbandEventCell_for_AnalogOutputStatus *pDeadbandEventCell_for_AnalogOutputStatus)
{
  SimpleEventCell_for_AnalogOutputStatus_in_SimpleEventCell_for_AnalogOutputStatus(&(pDeadbandEventCell_for_AnalogOutputStatus->sSimpleEventCell_for_AnalogOutputStatus));
}

boolean IsEvent_in_DeadbandEventCell_for_AnalogOutputStatus(DeadbandEventCell_for_AnalogOutputStatus *pDeadbandEventCell_for_AnalogOutputStatus,
    AOStatusConfig *config,
    AnalogOutputStatus* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_AnalogOutputStatusSpec_static(&((pDeadbandEventCell_for_AnalogOutputStatus->sSimpleEventCell_for_AnalogOutputStatus.eEventCellBase_for_AnalogOutputStatus).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------AnalogOutputStatus---------------------------------------
//---------------------------------OctetString---------------------------------------
void SetEventValue_in_EventCellBase_for_OctetString(EventCellBase_for_OctetString *pEventCellBase_for_OctetString, OctetString* value)
{
  pEventCellBase_for_OctetString->lastEvent = *value;
}

void EventCellBase_for_OctetString_in_EventCellBase_for_OctetString(EventCellBase_for_OctetString *pEventCellBase_for_OctetString)
{
  pEventCellBase_for_OctetString->clazz = PointClass_Class1;
  OctetString_in_OctetStringOver1(&(pEventCellBase_for_OctetString->lastEvent));
  pEventCellBase_for_OctetString->evariation = 0;
}

void SimpleEventCell_for_OctetString_in_SimpleEventCell_for_OctetString(SimpleEventCell_for_OctetString *pSimpleEventCell_for_OctetString)
{
  EventCellBase_for_OctetString_in_EventCellBase_for_OctetString(&(pSimpleEventCell_for_OctetString->eEventCellBase_for_OctetString));
}

boolean IsEvent_in_SimpleEventCell_for_OctetString(SimpleEventCell_for_OctetString *pSimpleEventCell_for_OctetString,
    OctetStringConfig *config,
    OctetString* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_OctetStringSpec_static(OctetString *old_value,
//                                         OctetString *new_value,
//                                         OctetStringConfig_for_EventConfig_for_OctetStringInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_OctetStringSpec_static(&((pSimpleEventCell_for_OctetString->eEventCellBase_for_OctetString).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}

void DeadbandEventCell_for_OctetString_in_DeadbandEventCell_for_OctetString(DeadbandEventCell_for_OctetString *pDeadbandEventCell_for_OctetString)
{
  SimpleEventCell_for_OctetString_in_SimpleEventCell_for_OctetString(&(pDeadbandEventCell_for_OctetString->sSimpleEventCell_for_OctetString));
}

boolean IsEvent_in_DeadbandEventCell_for_OctetString(DeadbandEventCell_for_OctetString *pDeadbandEventCell_for_OctetString,
    OctetStringConfig *config,
    OctetString* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_OctetStringSpec_static(&((pDeadbandEventCell_for_OctetString->sSimpleEventCell_for_OctetString.eEventCellBase_for_OctetString).lastEvent),
                                      new_value,
                                      config);
}
//---------------------------------OctetString---------------------------------------
//---------------------------------TimeAndInterval---------------------------------------
void SetEventValue_in_EventCellBase_for_TimeAndInterval(EventCellBase_for_TimeAndInterval *pEventCellBase_for_TimeAndInterval, TimeAndInterval* value)
{
  pEventCellBase_for_TimeAndInterval->lastEvent = *value;
}

void EventCellBase_for_TimeAndInterval_in_EventCellBase_for_TimeAndInterval(EventCellBase_for_TimeAndInterval *pEventCellBase_for_TimeAndInterval)
{
  pEventCellBase_for_TimeAndInterval->clazz = PointClass_Class1;
  TimeAndInterval_in_TimeAndIntervalOver1(&(pEventCellBase_for_TimeAndInterval->lastEvent));
//  pEventCellBase_for_TimeAndInterval->evariation = 0;
}

void SimpleEventCell_for_TimeAndInterval_in_SimpleEventCell_for_TimeAndInterval(SimpleEventCell_for_TimeAndInterval *pSimpleEventCell_for_TimeAndInterval)
{
  EventCellBase_for_TimeAndInterval_in_EventCellBase_for_TimeAndInterval(&(pSimpleEventCell_for_TimeAndInterval->eEventCellBase_for_TimeAndInterval));
}
/*
boolean IsEvent_in_SimpleEventCell_for_TimeAndInterval(SimpleEventCell_for_TimeAndInterval *pSimpleEventCell_for_TimeAndInterval,
    TimeAndIntervalConfig *config,
    TimeAndInterval* new_value)
{
  UNUSED(config);
//    boolean IsEvent_in_TimeAndIntervalSpec_static(TimeAndInterval *old_value,
//                                         TimeAndInterval *new_value,
//                                         TimeAndIntervalConfig_for_EventConfig_for_TimeAndIntervalInfo *config);////const config_t& config)
////        return Spec::IsEvent(this->lastEvent, new_Value);
    return IsEvent_in_TimeAndIntervalSpec_static(&((pSimpleEventCell_for_TimeAndInterval->eEventCellBase_for_TimeAndInterval).lastEvent),
                                        new_value,
                                        NULL);////const config_t& config)
}
*/
void DeadbandEventCell_for_TimeAndInterval_in_DeadbandEventCell_for_TimeAndInterval(DeadbandEventCell_for_TimeAndInterval *pDeadbandEventCell_for_TimeAndInterval)
{
  SimpleEventCell_for_TimeAndInterval_in_SimpleEventCell_for_TimeAndInterval(&(pDeadbandEventCell_for_TimeAndInterval->sSimpleEventCell_for_TimeAndInterval));
}
/*
boolean IsEvent_in_DeadbandEventCell_for_TimeAndInterval(DeadbandEventCell_for_TimeAndInterval *pDeadbandEventCell_for_TimeAndInterval,
    TimeAndIntervalConfig *config,
    TimeAndInterval* new_value)
{
////        return Spec::IsEvent(this->lastEvent, new_Value, config.deadband);
  return IsEvent_in_TimeAndInterval_static(&((pDeadbandEventCell_for_TimeAndInterval->sSimpleEventCell_for_TimeAndInterval.eEventCellBase_for_TimeAndInterval).lastEvent),
                                      new_value,
                                      config);
}
*/
//---------------------------------TimeAndInterval---------------------------------------
