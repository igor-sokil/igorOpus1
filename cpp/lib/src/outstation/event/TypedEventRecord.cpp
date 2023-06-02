
#include "header.h"
#include "TypedEventRecord.h"

//----------------------------------BinarySpec-----------------------------------------------
  void TypedEventRecord_for_BinarySpec_in_TypedEventRecord_for_BinarySpec(TypedEventRecord_for_BinarySpec *pTypedEventRecord_for_BinarySpec,
////                   const typename T::meas_t& value,
                       Binary *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_BinaryInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_BinarySpec->value = *value;
   pTypedEventRecord_for_BinarySpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_BinarySpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_BinarySpec->record = record;
}
//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
  void TypedEventRecord_for_DoubleBitBinarySpec_in_TypedEventRecord_for_DoubleBitBinarySpec(TypedEventRecord_for_DoubleBitBinarySpec *pTypedEventRecord_for_DoubleBitBinarySpec,
////                   const typename T::meas_t& value,
                       DoubleBitBinary *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_DoubleBitBinaryInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_DoubleBitBinarySpec->value = *value;
   pTypedEventRecord_for_DoubleBitBinarySpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_DoubleBitBinarySpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_DoubleBitBinarySpec->record = record;
}
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------
  void TypedEventRecord_for_AnalogSpec_in_TypedEventRecord_for_AnalogSpec(TypedEventRecord_for_AnalogSpec *pTypedEventRecord_for_AnalogSpec,
////                   const typename T::meas_t& value,
                       Analog *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_AnalogInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_AnalogSpec->value = *value;
   pTypedEventRecord_for_AnalogSpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_AnalogSpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_AnalogSpec->record = record;
}
//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------
  void TypedEventRecord_for_CounterSpec_in_TypedEventRecord_for_CounterSpec(TypedEventRecord_for_CounterSpec *pTypedEventRecord_for_CounterSpec,
////                   const typename T::meas_t& value,
                       Counter *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_CounterInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_CounterSpec->value = *value;
   pTypedEventRecord_for_CounterSpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_CounterSpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_CounterSpec->record = record;
}
//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------
  void TypedEventRecord_for_FrozenCounterSpec_in_TypedEventRecord_for_FrozenCounterSpec(TypedEventRecord_for_FrozenCounterSpec *pTypedEventRecord_for_FrozenCounterSpec,
////                   const typename T::meas_t& value,
                       FrozenCounter *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_FrozenCounterInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_FrozenCounterSpec->value = *value;
   pTypedEventRecord_for_FrozenCounterSpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_FrozenCounterSpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_FrozenCounterSpec->record = record;
}
//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
  void TypedEventRecord_for_BinaryOutputStatusSpec_in_TypedEventRecord_for_BinaryOutputStatusSpec(TypedEventRecord_for_BinaryOutputStatusSpec *pTypedEventRecord_for_BinaryOutputStatusSpec,
////                   const typename T::meas_t& value,
                       BinaryOutputStatus *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_BinaryOutputStatusInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_BinaryOutputStatusSpec->value = *value;
   pTypedEventRecord_for_BinaryOutputStatusSpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_BinaryOutputStatusSpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_BinaryOutputStatusSpec->record = record;
}
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
  void TypedEventRecord_for_AnalogOutputStatusSpec_in_TypedEventRecord_for_AnalogOutputStatusSpec(TypedEventRecord_for_AnalogOutputStatusSpec *pTypedEventRecord_for_AnalogOutputStatusSpec,
////                   const typename T::meas_t& value,
                       AnalogOutputStatus *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_AnalogOutputStatusInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_AnalogOutputStatusSpec->value = *value;
   pTypedEventRecord_for_AnalogOutputStatusSpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_AnalogOutputStatusSpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_AnalogOutputStatusSpec->record = record;
}
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------
  void TypedEventRecord_for_OctetStringSpec_in_TypedEventRecord_for_OctetStringSpec(TypedEventRecord_for_OctetStringSpec *pTypedEventRecord_for_OctetStringSpec,
////                   const typename T::meas_t& value,
                       OctetString *value,
////                   typename T::event_variation_t defaultVariation,
                       event_variation_t_in_OctetStringInfo  defaultVariation,
                   Node_for_EventRecord* record)
{
////    : value(value), defaultVariation(defaultVariation), selectedVariation(defaultVariation), record(record)
   pTypedEventRecord_for_OctetStringSpec->value = *value;
   pTypedEventRecord_for_OctetStringSpec->defaultVariation = defaultVariation;
   pTypedEventRecord_for_OctetStringSpec->selectedVariation = defaultVariation;
   pTypedEventRecord_for_OctetStringSpec->record = record;
}
//----------------------------------OctetStringSpec-----------------------------------------------


