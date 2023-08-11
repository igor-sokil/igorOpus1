#include "header.h"
#include "TypedStorage.h"

//----------------------------------BinarySpec-----------------------------------------------

Node_TypedEventRecord_for_BinarySpec* Retrieve_in_TypedStorage_for_BinarySpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_BinarySpec*)(record->storage_node);
}
//----------------------------------BinarySpec-----------------------------------------------
//----------------------------------DoubleBitBinarySpec-----------------------------------------------

Node_TypedEventRecord_for_DoubleBitBinarySpec* Retrieve_in_TypedStorage_for_DoubleBitBinarySpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_DoubleBitBinarySpec*)(record->storage_node);
}
//----------------------------------DoubleBitBinarySpec-----------------------------------------------
//----------------------------------AnalogSpec-----------------------------------------------

Node_TypedEventRecord_for_AnalogSpec* Retrieve_in_TypedStorage_for_AnalogSpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_AnalogSpec*)(record->storage_node);
}
//----------------------------------AnalogSpec-----------------------------------------------
//----------------------------------CounterSpec-----------------------------------------------

Node_TypedEventRecord_for_CounterSpec* Retrieve_in_TypedStorage_for_CounterSpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_CounterSpec*)(record->storage_node);
}
//----------------------------------CounterSpec-----------------------------------------------
//----------------------------------FrozenCounterSpec-----------------------------------------------

Node_TypedEventRecord_for_FrozenCounterSpec* Retrieve_in_TypedStorage_for_FrozenCounterSpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_FrozenCounterSpec*)(record->storage_node);
}
//----------------------------------FrozenCounterSpec-----------------------------------------------
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------

Node_TypedEventRecord_for_BinaryOutputStatusSpec* Retrieve_in_TypedStorage_for_BinaryOutputStatusSpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_BinaryOutputStatusSpec*)(record->storage_node);
}
//----------------------------------BinaryOutputStatusSpec-----------------------------------------------
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------

Node_TypedEventRecord_for_AnalogOutputStatusSpec* Retrieve_in_TypedStorage_for_AnalogOutputStatusSpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_AnalogOutputStatusSpec*)(record->storage_node);
}
//----------------------------------AnalogOutputStatusSpec-----------------------------------------------
//----------------------------------OctetStringSpec-----------------------------------------------

Node_TypedEventRecord_for_OctetStringSpec* Retrieve_in_TypedStorage_for_OctetStringSpec_static(EventRecord* record)
{
  return (Node_TypedEventRecord_for_OctetStringSpec*)(record->storage_node);
}
//----------------------------------OctetStringSpec-----------------------------------------------
