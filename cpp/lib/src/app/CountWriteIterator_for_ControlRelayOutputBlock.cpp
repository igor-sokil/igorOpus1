#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CountWriteIterator_for_ControlRelayOutputBlock.h"
#include "SerializationTemplates.h"
#include <string.h>
//-------------------Uint8---------------------------------------------------

CountWriteIterator_for_UInt8_ControlRelayOutputBlock Null_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlock_static(void)
{
  CountWriteIterator_for_UInt8_ControlRelayOutputBlock cCountWriteIterator_for_UInt8_ControlRelayOutputBlock;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt8_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlockOver1(&cCountWriteIterator_for_UInt8_ControlRelayOutputBlock);
  return cCountWriteIterator_for_UInt8_ControlRelayOutputBlock;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt8_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlockOver1(CountWriteIterator_for_UInt8_ControlRelayOutputBlock *pCountWriteIterator_for_UInt8_ControlRelayOutputBlock)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlockOver1_1"<<'\n';
  decrement_stack_info();
#endif
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->count = 0;
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->isValid = false;
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt8_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlockOver2(CountWriteIterator_for_UInt8_ControlRelayOutputBlock *pCountWriteIterator_for_UInt8_ControlRelayOutputBlock,
    Serializer_for_ControlRelayOutputBlock *serializer, WSeq_for_Uint16_t *position)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlockOver2_2"<<'\n';
  decrement_stack_info();
#endif

  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->count = 0;
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->serializer = *serializer;
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->pPosition->hHasLength))////position.length()
      >= size_in_UInt8;////CountType::size),
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->countPosition = *position;
  pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->pPosition = position;

  if (pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt8);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt8_ControlRelayOutputBlock_destr_CountWriteIterator_for_UInt8_ControlRelayOutputBlock(CountWriteIterator_for_UInt8_ControlRelayOutputBlock *pCountWriteIterator_for_UInt8_ControlRelayOutputBlock)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<'\n';
  std::cout<<"CountWriteIterator_for_UInt8_ControlRelayOutputBlock_destr_CountWriteIterator_for_UInt8_ControlRelayOutputBlock1"<<'\n';
  decrement_stack_info();
#endif
  if (pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt8_static(&(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->countPosition), pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlock(CountWriteIterator_for_UInt8_ControlRelayOutputBlock *pCountWriteIterator_for_UInt8_ControlRelayOutputBlock, ControlRelayOutputBlock *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->isValid && (get_size_in_Serializer_for_ControlRelayOutputBlock(&(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->pPosition->hHasLength))
                                                                       ) &&
      (pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->count < max_value_in_UInt8))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_ControlRelayOutputBlock(&(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->serializer), value, pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->pPosition);
    ++(pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt8_ControlRelayOutputBlock(CountWriteIterator_for_UInt8_ControlRelayOutputBlock *pCountWriteIterator_for_UInt8_ControlRelayOutputBlock)
{
  return pCountWriteIterator_for_UInt8_ControlRelayOutputBlock->isValid;
}
//-------------------Uint8---------------------------------------------------
//-------------------Uint16---------------------------------------------------
CountWriteIterator_for_UInt16_ControlRelayOutputBlock Null_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlock_static(void)
{
  CountWriteIterator_for_UInt16_ControlRelayOutputBlock cCountWriteIterator_for_UInt16_ControlRelayOutputBlock;
////    return CountWriteIterator();
  CountWriteIterator_for_UInt16_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlockOver1(&cCountWriteIterator_for_UInt16_ControlRelayOutputBlock);
  return cCountWriteIterator_for_UInt16_ControlRelayOutputBlock;
}

////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
void CountWriteIterator_for_UInt16_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlockOver1(CountWriteIterator_for_UInt16_ControlRelayOutputBlock *pCountWriteIterator_for_UInt16_ControlRelayOutputBlock)
{
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->count = 0;
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid = false;
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition = NULL;
}

////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
void CountWriteIterator_for_UInt16_ControlRelayOutputBlock_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlockOver2(CountWriteIterator_for_UInt16_ControlRelayOutputBlock *pCountWriteIterator_for_UInt16_ControlRelayOutputBlock,
    Serializer_for_ControlRelayOutputBlock *serializer, WSeq_for_Uint16_t *position)
{

  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->count = 0;
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->serializer = *serializer;
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid = length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition->hHasLength))////position.length()
      >= size_in_UInt16;////CountType::size),
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->countPosition = *position;
  pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition = position;

  if (pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid)
  {
//        position.advance(CountType::size);
    advance_in_WSeq_for_Uint16_t(position, size_in_UInt16);
  }
}

////    ~CountWriteIterator()
void CountWriteIterator_for_UInt16_ControlRelayOutputBlock_destr_CountWriteIterator_for_UInt16_ControlRelayOutputBlock(CountWriteIterator_for_UInt16_ControlRelayOutputBlock *pCountWriteIterator_for_UInt16_ControlRelayOutputBlock)
{
  if (pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid)
  {
////        CountType::write_to(countPosition, count);
    write_to_in_UInt16_static(&(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->countPosition), pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->count);
  }
}

boolean Write_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlock(CountWriteIterator_for_UInt16_ControlRelayOutputBlock *pCountWriteIterator_for_UInt16_ControlRelayOutputBlock, ControlRelayOutputBlock *value)////const WriteType& value)
{
////    if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
  if(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid && (get_size_in_Serializer_for_ControlRelayOutputBlock(&(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->serializer)) <=
      length_in_HasLength_for_Uint16_t(&(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition->hHasLength))
                                                                        ) &&
      (pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->count < max_value_in_UInt16))
  {
////        serializer.write(value, *this->pPosition);
    write_in_Serializer_for_ControlRelayOutputBlock(&(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->serializer), value, pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->pPosition);
    ++(pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->count);
    return true;
  }
  else
  {
    return false;
  }
}

boolean IsValid_in_CountWriteIterator_for_UInt16_ControlRelayOutputBlock(CountWriteIterator_for_UInt16_ControlRelayOutputBlock *pCountWriteIterator_for_UInt16_ControlRelayOutputBlock)
{
  return pCountWriteIterator_for_UInt16_ControlRelayOutputBlock->isValid;
}
//-------------------Uint16---------------------------------------------------
