#include "header.h"
#include "EventCells.h"
///*
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
    Analog* newValue)
{
  UNUSED(config):
//    boolean IsEvent_in_AnalogSpec_static(Analog *old_value,
//                                         Analog *new_value,
//                                         AnalogConfig_for_EventConfig_for_AnalogInfo *config);////const config_t& config)
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
    Analog* newValue)
{
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
  return IsEvent_in_AnalogSpec_static(&((pSimpleEventCell_for_Analog->eEventCellBase_for_Analog).lastEvent),
         new_value,
         NULL);////const config_t& config)
}

//---------------------------------Analog---------------------------------------
//*/
