#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CountWriteIterator_for_BinaryOutputStatus.h"
#include "SerializationTemplates.h"
#include <string.h>

//-------------------Uint8---------------------------------------------------
CountWriteIterator_for_UInt8_BinaryOutputStatus Null_in_CountWriteIterator_for_UInt8_BinaryOutputStatus_static(void)
{
  CountWriteIterator_for_UInt8_BinaryOutputStatus cCountWriteIterator_for_UInt8_BinaryOutputStatus;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_BinaryOutputStatus_in_CountWriteIterator_for_UInt8_BinaryOutputStatusOver1(&cCountWriteIterator_for_UInt8_BinaryOutputStatus);
  return cCountWriteIterator_for_UInt8_BinaryOutputStatus;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_BinaryOutputStatus_in_CountWriteIterator_for_UInt8_BinaryOutputStatusOver1(CountWriteIterator_for_UInt8_BinaryOutputStatus *pCountWriteIterator_for_UInt8_BinaryOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_BinaryOutputStatus_in_CountWriteIterator_for_UInt8_BinaryOutputStatusOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->count = 0;
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->isValid = false;
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_BinaryOutputStatus_in_CountWriteIterator_for_UInt8_BinaryOutputStatusOver2(CountWriteIterator_for_UInt8_BinaryOutputStatus *pCountWriteIterator_for_UInt8_BinaryOutputStatus,
    Serializer_for_BinaryOutputStatus *serializer, WSeq_for_Uint16_t *position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_BinaryOutputStatus_in_CountWriteIterator_for_UInt8_BinaryOutputStatusOver2_1"<<'\n';
  decrement_stack_info();
#endif

  pCountWriteIterator_for_UInt8_BinaryOutputStatus->count = 0;
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->serializer = *serializer;
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_BinaryOutputStatus->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->countPosition = *position;
  pCountWriteIterator_for_UInt8_BinaryOutputStatus->pPosition = position;

  if (pCountWriteIterator_for_UInt8_BinaryOutputStatus->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_BinaryOutputStatus_destr_CountWriteIterator_for_UInt8_BinaryOutputStatus(CountWriteIterator_for_UInt8_BinaryOutputStatus *pCountWriteIterator_for_UInt8_BinaryOutputStatus)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<""<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_BinaryOutputStatus_destr_CountWriteIterator_for_UInt8_BinaryOutputStatus1"<<'\n';
  decrement_stack_info();
#endif
  if (pCountWriteIterator_for_UInt8_BinaryOutputStatus->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_BinaryOutputStatus->countPosition), pCountWriteIterator_for_UInt8_BinaryOutputStatus->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_BinaryOutputStatus(CountWriteIterator_for_UInt8_BinaryOutputStatus *pCountWriteIterator_for_UInt8_BinaryOutputStatus, BinaryOutputStatus *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_BinaryOutputStatus->isValid && (get_size_in_Serializer_for_BinaryOutputStatus(&(pCountWriteIterator_for_UInt8_BinaryOutputStatus->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_BinaryOutputStatus->pPosition->hHasLength))
                                                                  ) &&
      (pCountWriteIterator_for_UInt8_BinaryOutputStatus->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_BinaryOutputStatus(&(pCountWriteIterator_for_UInt8_BinaryOutputStatus->serializer), value, pCountWriteIterator_for_UInt8_BinaryOutputStatus->pPosition);
    ++(pCountWriteIterator_for_UInt8_BinaryOutputStatus->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_BinaryOutputStatus(CountWriteIterator_for_UInt8_BinaryOutputStatus *pCountWriteIterator_for_UInt8_BinaryOutputStatus)
{
  return pCountWriteIterator_for_UInt8_BinaryOutputStatus->isValid;
}
//-------------------Uint8---------------------------------------------------
