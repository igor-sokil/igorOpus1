#include "header.h"
#include "CountWriteIterator_for_AnalogOutputStatus.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint8---------------------------------------------------

CountWriteIterator_for_UInt8_AnalogOutputStatus Null_in_CountWriteIterator_for_UInt8_AnalogOutputStatus_static(void)
{
  CountWriteIterator_for_UInt8_AnalogOutputStatus cCountWriteIterator_for_UInt8_AnalogOutputStatus;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_AnalogOutputStatus_in_CountWriteIterator_for_UInt8_AnalogOutputStatusOver1(&cCountWriteIterator_for_UInt8_AnalogOutputStatus);
  return cCountWriteIterator_for_UInt8_AnalogOutputStatus;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_AnalogOutputStatus_in_CountWriteIterator_for_UInt8_AnalogOutputStatusOver1(CountWriteIterator_for_UInt8_AnalogOutputStatus *pCountWriteIterator_for_UInt8_AnalogOutputStatus)
{
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->count = 0;
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->isValid = false;
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_AnalogOutputStatus_in_CountWriteIterator_for_UInt8_AnalogOutputStatusOver2(CountWriteIterator_for_UInt8_AnalogOutputStatus *pCountWriteIterator_for_UInt8_AnalogOutputStatus,
    Serializer_for_AnalogOutputStatus *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt8_AnalogOutputStatus->count = 0;
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->serializer = *serializer;
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_AnalogOutputStatus->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->countPosition = *position;
  pCountWriteIterator_for_UInt8_AnalogOutputStatus->pPosition = position;

  if (pCountWriteIterator_for_UInt8_AnalogOutputStatus->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_AnalogOutputStatus_destr_CountWriteIterator_for_UInt8_AnalogOutputStatus(CountWriteIterator_for_UInt8_AnalogOutputStatus *pCountWriteIterator_for_UInt8_AnalogOutputStatus)
{
  if (pCountWriteIterator_for_UInt8_AnalogOutputStatus->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_AnalogOutputStatus->countPosition), pCountWriteIterator_for_UInt8_AnalogOutputStatus->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_AnalogOutputStatus(CountWriteIterator_for_UInt8_AnalogOutputStatus *pCountWriteIterator_for_UInt8_AnalogOutputStatus, AnalogOutputStatus *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_AnalogOutputStatus->isValid && (get_size_in_Serializer_for_AnalogOutputStatus(&(pCountWriteIterator_for_UInt8_AnalogOutputStatus->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_AnalogOutputStatus->pPosition->hHasLength))
                                                                  ) &&
      (pCountWriteIterator_for_UInt8_AnalogOutputStatus->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_AnalogOutputStatus(&(pCountWriteIterator_for_UInt8_AnalogOutputStatus->serializer), value, pCountWriteIterator_for_UInt8_AnalogOutputStatus->pPosition);
    ++(pCountWriteIterator_for_UInt8_AnalogOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_AnalogOutputStatus(CountWriteIterator_for_UInt8_AnalogOutputStatus *pCountWriteIterator_for_UInt8_AnalogOutputStatus)
{
  return pCountWriteIterator_for_UInt8_AnalogOutputStatus->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
CountWriteIterator_for_UInt16_AnalogOutputStatus Null_in_CountWriteIterator_for_UInt16_AnalogOutputStatus_static(void)
{
  CountWriteIterator_for_UInt16_AnalogOutputStatus cCountWriteIterator_for_UInt16_AnalogOutputStatus;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt16_AnalogOutputStatus_in_CountWriteIterator_for_UInt16_AnalogOutputStatusOver1(&cCountWriteIterator_for_UInt16_AnalogOutputStatus);
  return cCountWriteIterator_for_UInt16_AnalogOutputStatus;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt16_AnalogOutputStatus_in_CountWriteIterator_for_UInt16_AnalogOutputStatusOver1(CountWriteIterator_for_UInt16_AnalogOutputStatus *pCountWriteIterator_for_UInt16_AnalogOutputStatus)
{
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->count = 0;
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->isValid = false;
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt16_AnalogOutputStatus_in_CountWriteIterator_for_UInt16_AnalogOutputStatusOver2(CountWriteIterator_for_UInt16_AnalogOutputStatus *pCountWriteIterator_for_UInt16_AnalogOutputStatus,
    Serializer_for_AnalogOutputStatus *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt16_AnalogOutputStatus->count = 0;
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->serializer = *serializer;
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_AnalogOutputStatus->pPosition->hHasLength))////position.length()
      >= size_in_UInt16;////CountType::size),
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->countPosition = *position;
  pCountWriteIterator_for_UInt16_AnalogOutputStatus->pPosition = position;

  if (pCountWriteIterator_for_UInt16_AnalogOutputStatus->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt16_AnalogOutputStatus_destr_CountWriteIterator_for_UInt16_AnalogOutputStatus(CountWriteIterator_for_UInt16_AnalogOutputStatus *pCountWriteIterator_for_UInt16_AnalogOutputStatus)
{
  if (pCountWriteIterator_for_UInt16_AnalogOutputStatus->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pCountWriteIterator_for_UInt16_AnalogOutputStatus->countPosition), pCountWriteIterator_for_UInt16_AnalogOutputStatus->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt16_AnalogOutputStatus(CountWriteIterator_for_UInt16_AnalogOutputStatus *pCountWriteIterator_for_UInt16_AnalogOutputStatus, AnalogOutputStatus *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt16_AnalogOutputStatus->isValid && (get_size_in_Serializer_for_AnalogOutputStatus(&(pCountWriteIterator_for_UInt16_AnalogOutputStatus->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_AnalogOutputStatus->pPosition->hHasLength))
                                                                   ) &&
      (pCountWriteIterator_for_UInt16_AnalogOutputStatus->count < max_value_in_UInt16))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_AnalogOutputStatus(&(pCountWriteIterator_for_UInt16_AnalogOutputStatus->serializer), value, pCountWriteIterator_for_UInt16_AnalogOutputStatus->pPosition);
    ++(pCountWriteIterator_for_UInt16_AnalogOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt16_AnalogOutputStatus(CountWriteIterator_for_UInt16_AnalogOutputStatus *pCountWriteIterator_for_UInt16_AnalogOutputStatus)
{
  return pCountWriteIterator_for_UInt16_AnalogOutputStatus->isValid;
}
//-------------------Uint16---------------------------------------------------
