
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
