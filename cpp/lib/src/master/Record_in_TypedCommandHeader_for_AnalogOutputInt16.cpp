#include "header.h"
#include "Record_in_TypedCommandHeader_for_AnalogOutputInt16.h"

void Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(Record_in_TypedCommandHeader_for_AnalogOutputInt16 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
    Indexed_for_AnalogOutputInt16* pair)
{
////        Record(const Indexed<T>& pair) : CommandState(pair.index), command(pair.value) {}
  CommandState_in_CommandState(&(pRecord_in_TypedCommandHeader_for_AnalogOutputInt16->cCommandState), pair->index);
  pRecord_in_TypedCommandHeader_for_AnalogOutputInt16->command = pair->value;
}

//Record_in_TypedCommandHeader_for_AnalogOutputInt16 WithIndex_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(AnalogOutputInt16* value, uint16_t index)
//{
//}

