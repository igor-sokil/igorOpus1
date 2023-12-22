#ifndef OPENDNP3_Record_in_TypedCommandHeader_for_AnalogOutputInt16_H
#ifndef OPENDNP3_Record_in_TypedCommandHeader_for_AnalogOutputInt16_H
//------------------------AnalogOutputInt16----------------------------
////    struct Record : public CommandState
typedef struct
{
  CommandState cCommandState;
////        Record(const Indexed<T>& pair) : CommandState(pair.index), command(pair.value) {}

  AnalogOutputInt16 command;
} Record_in_TypedCommandHeader_for_AnalogOutputInt16;

void Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(Record_in_TypedCommandHeader_for_AnalogOutputInt16 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
    Indexed_for_AnalogOutputInt16* pair);

//Record_in_TypedCommandHeader_for_AnalogOutputInt16 WithIndex_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(AnalogOutputInt16* value, uint16_t index);

//------------------------AnalogOutputInt16----------------------------

#endif
