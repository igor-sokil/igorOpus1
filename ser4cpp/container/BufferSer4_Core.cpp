#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "BufferSer4_Core.h"

void  BufferSer4_Core_in_BufferSer4_CoreOver1(BufferSer4_Core *pBufferSer4_Core, uint8_t *bytes)
{
// : HasLength(0)
  pBufferSer4_Core->bytes = bytes;
  (pBufferSer4_Core->hHasLength_for_Uint16_t).m_length = 0;
}

////    ~BufferSer4_Core() = default;

void BufferSer4_Core_in_BufferSer4_CoreOver2(BufferSer4_Core *pBufferSer4_Core, uint8_t *bytes, uint16_t length)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"BufferSer4_Core_in_BufferSer4_CoreOver2_1"<<'\n';
/*
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t length="<<length<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*sizeof(BufferSer4_Core)="<<sizeof(pBufferSer4_Core->bytes)<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t bytes[SIZE_BufferSer4_Core]="<<(uint32_t)pBufferSer4_Core->bytes<<'\n';
*/
  decrement_stack_info();
#endif
////        HasLength(length),
////        bytes(std::make_unique<uint8_t[]>(length))
  pBufferSer4_Core->bytes = bytes;
  (pBufferSer4_Core->hHasLength_for_Uint16_t).m_length = length;
}
////    BufferSer4_Core(BufferSer4_Core&&) = default;
////    BufferSer4_Core& operator=(BufferSer4_Core&&) = default;

// initialize with the exact length and contents
void BufferSer4_Core_in_BufferSer4_CoreOver3(BufferSer4_Core *pBufferSer4_Core, uint8_t *bytes,  RSeq_for_Uint16_t *input)
{
  pBufferSer4_Core->bytes = bytes;
//// : BufferSer4_Core(input.length())
  BufferSer4_Core_in_BufferSer4_CoreOver2(pBufferSer4_Core, bytes, length_in_HasLength_for_Uint16_t(&(input->hHasLength)));//uint16_t length);
////    this->as_wslice().copy_from(input);
  WSeq_for_Uint16_t temp1 = as_wslice_in_BufferSer4_Core(pBufferSer4_Core);
  copy_from_in_WSeq_for_Uint16_t(&temp1, input);
}

RSeq_for_Uint16_t as_rslice_in_BufferSer4_Core(BufferSer4_Core *pBufferSer4_Core)
{
////    return rseq_t(this->bytes.get(), this->length());
  RSeq_for_Uint16_t rRSeq_for_Uint16_t;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t, pBufferSer4_Core->bytes,
      length_in_HasLength_for_Uint16_t(&(pBufferSer4_Core->hHasLength_for_Uint16_t)));//uint16_t length);
  return rRSeq_for_Uint16_t;
}

WSeq_for_Uint16_t as_wslice_in_BufferSer4_Core(BufferSer4_Core *pBufferSer4_Core)
{
////    return wseq_t(this->bytes.get(), this->length());
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pBufferSer4_Core->bytes,
      length_in_HasLength_for_Uint16_t(&(pBufferSer4_Core->hHasLength_for_Uint16_t)));//uint16_t length);
  return wWSeq_for_Uint16_t;
}
