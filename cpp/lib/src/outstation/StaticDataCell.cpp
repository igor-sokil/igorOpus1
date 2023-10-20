#include "header.h"
#include "MeasurementTypeSpecs.h"
#include "StaticDataCell.h"
//-------------------------------Binary-------------------------------------------------
void SelectedValue_for_BinarySpec_in_SelectedValue_for_BinarySpecOver1(SelectedValue_for_BinarySpec *pSelectedValue_for_BinarySpec)
{
  Binary_in_BinaryOver1(&(pSelectedValue_for_BinarySpec->value));

  pSelectedValue_for_BinarySpec->selected = false;
  pSelectedValue_for_BinarySpec->variation = 0;
}
void SelectedValue_for_BinarySpec_in_SelectedValue_for_BinarySpecOver2(SelectedValue_for_BinarySpec *pSelectedValue_for_BinarySpec,
                                          boolean selected, Binary* value, StaticBinaryVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_BinarySpec->selected = selected;
   pSelectedValue_for_BinarySpec->value = *value;
   pSelectedValue_for_BinarySpec->variation = variation;
}

void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
    BinaryConfig* config)
{
  SelectedValue_for_BinarySpec_in_SelectedValue_for_BinarySpecOver1(&(pStaticDataCell_for_Binary->selection));

  Binary_in_BinaryOver1(&(pStaticDataCell_for_Binary->value));
  pStaticDataCell_for_Binary->config = *config;
}

void  StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver2(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
    Binary* value,
    BinaryConfig* config)
{
  SelectedValue_for_BinarySpec_in_SelectedValue_for_BinarySpecOver1(&(pStaticDataCell_for_Binary->selection));
  pStaticDataCell_for_Binary->value = *value;
  pStaticDataCell_for_Binary->config = *config;
}
//-------------------------------Binary-------------------------------------------------
//-------------------------------DoubleBitBinary-------------------------------------------------
void SelectedValue_for_DoubleBitBinarySpec_in_SelectedValue_for_DoubleBitBinarySpecOver1(SelectedValue_for_DoubleBitBinarySpec *pSelectedValue_for_DoubleBitBinarySpec)
{
  DoubleBitBinary_in_DoubleBitBinaryOver1(&(pSelectedValue_for_DoubleBitBinarySpec->value));

  pSelectedValue_for_DoubleBitBinarySpec->selected = false;
  pSelectedValue_for_DoubleBitBinarySpec->variation = 0;
}
void SelectedValue_for_DoubleBitBinarySpec_in_SelectedValue_for_DoubleBitBinarySpecOver2(SelectedValue_for_DoubleBitBinarySpec *pSelectedValue_for_DoubleBitBinarySpec,
                                          boolean selected, DoubleBitBinary* value, StaticDoubleBinaryVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_DoubleBitBinarySpec->selected = selected;
   pSelectedValue_for_DoubleBitBinarySpec->value = *value;
   pSelectedValue_for_DoubleBitBinarySpec->variation = variation;
}

void StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver1(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
    DoubleBitBinaryConfig* config)
{
  SelectedValue_for_DoubleBitBinarySpec_in_SelectedValue_for_DoubleBitBinarySpecOver1(&(pStaticDataCell_for_DoubleBitBinary->selection));

  DoubleBitBinary_in_DoubleBitBinaryOver1(&(pStaticDataCell_for_DoubleBitBinary->value));
  pStaticDataCell_for_DoubleBitBinary->config = *config;
}

void  StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver2(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
    DoubleBitBinary* value,
    DoubleBitBinaryConfig* config)
{
  SelectedValue_for_DoubleBitBinarySpec_in_SelectedValue_for_DoubleBitBinarySpecOver1(&(pStaticDataCell_for_DoubleBitBinary->selection));
  pStaticDataCell_for_DoubleBitBinary->value = *value;
  pStaticDataCell_for_DoubleBitBinary->config = *config;
}
//-------------------------------DoubleBitBinary-------------------------------------------------
//-------------------------------Analog-------------------------------------------------
void SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver1(SelectedValue_for_AnalogSpec *pSelectedValue_for_AnalogSpec)
{
  Analog_in_AnalogOver1(&(pSelectedValue_for_AnalogSpec->value));

  pSelectedValue_for_AnalogSpec->selected = false;
  pSelectedValue_for_AnalogSpec->variation = 0;
}

void SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver2(SelectedValue_for_AnalogSpec *pSelectedValue_for_AnalogSpec,
                                          boolean selected, Analog* value, StaticAnalogVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_AnalogSpec->selected = selected;
   pSelectedValue_for_AnalogSpec->value = *value;
   pSelectedValue_for_AnalogSpec->variation = variation;
}

void StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
    AnalogConfig* config)
{
  SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver1(&(pStaticDataCell_for_Analog->selection));

  Analog_in_AnalogOver1(&(pStaticDataCell_for_Analog->value));
  pStaticDataCell_for_Analog->config = *config;
}

void  StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
    Analog* value,
    AnalogConfig* config)
{
  SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver1(&(pStaticDataCell_for_Analog->selection));
  pStaticDataCell_for_Analog->value = *value;
  pStaticDataCell_for_Analog->config = *config;
}
//-------------------------------Analog-------------------------------------------------
//-------------------------------Counter-------------------------------------------------
void SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver1(SelectedValue_for_CounterSpec *pSelectedValue_for_CounterSpec)
{
  Counter_in_CounterOver1(&(pSelectedValue_for_CounterSpec->value));

  pSelectedValue_for_CounterSpec->selected = false;
  pSelectedValue_for_CounterSpec->variation = 0;
}
void SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver2(SelectedValue_for_CounterSpec *pSelectedValue_for_CounterSpec,
                                          boolean selected, Counter* value, StaticCounterVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_CounterSpec->selected = selected;
   pSelectedValue_for_CounterSpec->value = *value;
   pSelectedValue_for_CounterSpec->variation = variation;
}

void StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
    CounterConfig* config)
{
  SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver1(&(pStaticDataCell_for_Counter->selection));

  Counter_in_CounterOver1(&(pStaticDataCell_for_Counter->value));
  pStaticDataCell_for_Counter->config = *config;
}

void  StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver2(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
    Counter* value,
    CounterConfig* config)
{
  SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver1(&(pStaticDataCell_for_Counter->selection));
  pStaticDataCell_for_Counter->value = *value;
  pStaticDataCell_for_Counter->config = *config;
}
//-------------------------------Counter-------------------------------------------------
//-------------------------------FrozenCounter-------------------------------------------------
void SelectedValue_for_FrozenCounterSpec_in_SelectedValue_for_FrozenCounterSpecOver1(SelectedValue_for_FrozenCounterSpec *pSelectedValue_for_FrozenCounterSpec)
{
  FrozenCounter_in_FrozenCounterOver1(&(pSelectedValue_for_FrozenCounterSpec->value));

  pSelectedValue_for_FrozenCounterSpec->selected = false;
  pSelectedValue_for_FrozenCounterSpec->variation = 0;
}
void SelectedValue_for_FrozenCounterSpec_in_SelectedValue_for_FrozenCounterSpecOver2(SelectedValue_for_FrozenCounterSpec *pSelectedValue_for_FrozenCounterSpec,
                                          boolean selected, FrozenCounter* value, StaticFrozenCounterVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_FrozenCounterSpec->selected = selected;
   pSelectedValue_for_FrozenCounterSpec->value = *value;
   pSelectedValue_for_FrozenCounterSpec->variation = variation;
}

void StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
    FrozenCounterConfig* config)
{
  SelectedValue_for_FrozenCounterSpec_in_SelectedValue_for_FrozenCounterSpecOver1(&(pStaticDataCell_for_FrozenCounter->selection));

  FrozenCounter_in_FrozenCounterOver1(&(pStaticDataCell_for_FrozenCounter->value));
  pStaticDataCell_for_FrozenCounter->config = *config;
}

void  StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver2(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
    FrozenCounter* value,
    FrozenCounterConfig* config)
{
  SelectedValue_for_FrozenCounterSpec_in_SelectedValue_for_FrozenCounterSpecOver1(&(pStaticDataCell_for_FrozenCounter->selection));
  pStaticDataCell_for_FrozenCounter->value = *value;
  pStaticDataCell_for_FrozenCounter->config = *config;
}
//-------------------------------FrozenCounter-------------------------------------------------
//-------------------------------BinaryOutputStatus-------------------------------------------------
void SelectedValue_for_BinaryOutputStatusSpec_in_SelectedValue_for_BinaryOutputStatusSpecOver1(SelectedValue_for_BinaryOutputStatusSpec *pSelectedValue_for_BinaryOutputStatusSpec)
{
  BinaryOutputStatus_in_BinaryOutputStatusOver1(&(pSelectedValue_for_BinaryOutputStatusSpec->value));

  pSelectedValue_for_BinaryOutputStatusSpec->selected = false;
  pSelectedValue_for_BinaryOutputStatusSpec->variation = 0;
}
void SelectedValue_for_BinaryOutputStatusSpec_in_SelectedValue_for_BinaryOutputStatusSpecOver2(SelectedValue_for_BinaryOutputStatusSpec *pSelectedValue_for_BinaryOutputStatusSpec,
                                          boolean selected, BinaryOutputStatus* value, StaticBinaryOutputStatusVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_BinaryOutputStatusSpec->selected = selected;
   pSelectedValue_for_BinaryOutputStatusSpec->value = *value;
   pSelectedValue_for_BinaryOutputStatusSpec->variation = variation;
}

void StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver1(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
    BOStatusConfig* config)
{
  SelectedValue_for_BinaryOutputStatusSpec_in_SelectedValue_for_BinaryOutputStatusSpecOver1(&(pStaticDataCell_for_BinaryOutputStatus->selection));

  BinaryOutputStatus_in_BinaryOutputStatusOver1(&(pStaticDataCell_for_BinaryOutputStatus->value));
  pStaticDataCell_for_BinaryOutputStatus->config = *config;
}

void  StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver2(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
    BinaryOutputStatus* value,
    BOStatusConfig* config)
{
  SelectedValue_for_BinaryOutputStatusSpec_in_SelectedValue_for_BinaryOutputStatusSpecOver1(&(pStaticDataCell_for_BinaryOutputStatus->selection));
  pStaticDataCell_for_BinaryOutputStatus->value = *value;
  pStaticDataCell_for_BinaryOutputStatus->config = *config;
}
//-------------------------------BinaryOutputStatus-------------------------------------------------
//-------------------------------AnalogOutputStatus-------------------------------------------------
void SelectedValue_for_AnalogOutputStatusSpec_in_SelectedValue_for_AnalogOutputStatusSpecOver1(SelectedValue_for_AnalogOutputStatusSpec *pSelectedValue_for_AnalogOutputStatusSpec)
{
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&(pSelectedValue_for_AnalogOutputStatusSpec->value));

  pSelectedValue_for_AnalogOutputStatusSpec->selected = false;
  pSelectedValue_for_AnalogOutputStatusSpec->variation = 0;
}

void SelectedValue_for_AnalogOutputStatusSpec_in_SelectedValue_for_AnalogOutputStatusSpecOver2(SelectedValue_for_AnalogOutputStatusSpec *pSelectedValue_for_AnalogOutputStatusSpec,
                                          boolean selected, AnalogOutputStatus* value, StaticAnalogOutputStatusVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_AnalogOutputStatusSpec->selected = selected;
   pSelectedValue_for_AnalogOutputStatusSpec->value = *value;
   pSelectedValue_for_AnalogOutputStatusSpec->variation = variation;
}

void StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver1(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
    AOStatusConfig* config)
{
  SelectedValue_for_AnalogOutputStatusSpec_in_SelectedValue_for_AnalogOutputStatusSpecOver1(&(pStaticDataCell_for_AnalogOutputStatus->selection));

  AnalogOutputStatus_in_AnalogOutputStatusOver1(&(pStaticDataCell_for_AnalogOutputStatus->value));
  pStaticDataCell_for_AnalogOutputStatus->config = *config;
}

void  StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver2(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
    AnalogOutputStatus* value,
    AOStatusConfig* config)
{
  SelectedValue_for_AnalogOutputStatusSpec_in_SelectedValue_for_AnalogOutputStatusSpecOver1(&(pStaticDataCell_for_AnalogOutputStatus->selection));
  pStaticDataCell_for_AnalogOutputStatus->value = *value;
  pStaticDataCell_for_AnalogOutputStatus->config = *config;
}
//-------------------------------AnalogOutputStatus-------------------------------------------------
//-------------------------------OctetString-------------------------------------------------
void SelectedValue_for_OctetStringSpec_in_SelectedValue_for_OctetStringSpecOver1(SelectedValue_for_OctetStringSpec *pSelectedValue_for_OctetStringSpec)
{
  OctetString_in_OctetStringOver1(&(pSelectedValue_for_OctetStringSpec->value));

  pSelectedValue_for_OctetStringSpec->selected = false;
  pSelectedValue_for_OctetStringSpec->variation = 0;
}
void SelectedValue_for_OctetStringSpec_in_SelectedValue_for_OctetStringSpecOver2(SelectedValue_for_OctetStringSpec *pSelectedValue_for_OctetStringSpec,
                                          boolean selected, OctetString* value, StaticOctetStringVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_OctetStringSpec->selected = selected;
   pSelectedValue_for_OctetStringSpec->value = *value;
   pSelectedValue_for_OctetStringSpec->variation = variation;
}

void StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver1(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString,
    OctetStringConfig* config)
{
  SelectedValue_for_OctetStringSpec_in_SelectedValue_for_OctetStringSpecOver1(&(pStaticDataCell_for_OctetString->selection));

  OctetString_in_OctetStringOver1(&(pStaticDataCell_for_OctetString->value));
  pStaticDataCell_for_OctetString->config = *config;
}

void  StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver2(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString,
    OctetString* value,
    OctetStringConfig* config)
{
  SelectedValue_for_OctetStringSpec_in_SelectedValue_for_OctetStringSpecOver1(&(pStaticDataCell_for_OctetString->selection));
  pStaticDataCell_for_OctetString->value = *value;
  pStaticDataCell_for_OctetString->config = *config;
}
//-------------------------------OctetString-------------------------------------------------
//-------------------------------TimeAndInterval-------------------------------------------------
void SelectedValue_for_TimeAndIntervalSpec_in_SelectedValue_for_TimeAndIntervalSpecOver1(SelectedValue_for_TimeAndIntervalSpec *pSelectedValue_for_TimeAndIntervalSpec)
{
  TimeAndInterval_in_TimeAndIntervalOver1(&(pSelectedValue_for_TimeAndIntervalSpec->value));

  pSelectedValue_for_TimeAndIntervalSpec->selected = false;
  pSelectedValue_for_TimeAndIntervalSpec->variation = 0;
}
void SelectedValue_for_TimeAndIntervalSpec_in_SelectedValue_for_TimeAndIntervalSpecOver2(SelectedValue_for_TimeAndIntervalSpec *pSelectedValue_for_TimeAndIntervalSpec,
                                          boolean selected, TimeAndInterval* value, StaticTimeAndIntervalVariation_uint8_t variation)
{
////        : selected(selected), value(value), variation(variation)
   pSelectedValue_for_TimeAndIntervalSpec->selected = selected;
   pSelectedValue_for_TimeAndIntervalSpec->value = *value;
   pSelectedValue_for_TimeAndIntervalSpec->variation = variation;
}

void StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver1(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
    TimeAndIntervalConfig* config)
{
  SelectedValue_for_TimeAndIntervalSpec_in_SelectedValue_for_TimeAndIntervalSpecOver1(&(pStaticDataCell_for_TimeAndInterval->selection));

  TimeAndInterval_in_TimeAndIntervalOver1(&(pStaticDataCell_for_TimeAndInterval->value));
  pStaticDataCell_for_TimeAndInterval->config = *config;
}

void  StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver2(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
    TimeAndInterval* value,
    TimeAndIntervalConfig* config)
{
  SelectedValue_for_TimeAndIntervalSpec_in_SelectedValue_for_TimeAndIntervalSpecOver1(&(pStaticDataCell_for_TimeAndInterval->selection));
  pStaticDataCell_for_TimeAndInterval->value = *value;
  pStaticDataCell_for_TimeAndInterval->config = *config;
}
//-------------------------------TimeAndInterval-------------------------------------------------
