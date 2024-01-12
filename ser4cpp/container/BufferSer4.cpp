#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "BufferSer4.h"

void  BufferSer4_in_BufferSer4Over1(BufferSer4 *pBufferSer4)
{
// : HasLength(0)
  (pBufferSer4->hHasLength_for_Uint16_t).m_length = 0;
}

////    ~BufferSer4() = default;

void BufferSer4_in_BufferSer4Over2(BufferSer4 *pBufferSer4, uint16_t length)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"BufferSer4_in_BufferSer4Over2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t length="<<length<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t bytes[SIZE_BufferSer4]="<<(uint32_t)pBufferSer4->bytes<<'\n';
  decrement_stack_info();
#endif
////        HasLength(length),
////        bytes(std::make_unique<uint8_t[]>(length))
  (pBufferSer4->hHasLength_for_Uint16_t).m_length = length;
}

////    BufferSer4(BufferSer4&&) = default;
////    BufferSer4& operator=(BufferSer4&&) = default;

// initialize with the exact length and contents
void BufferSer4_in_BufferSer4Over3(BufferSer4 *pBufferSer4,  RSeq_for_Uint16_t *input)
{
//// : BufferSer4(input.length())
  BufferSer4_in_BufferSer4Over2(pBufferSer4, length_in_HasLength_for_Uint16_t(&(input->hHasLength)));//uint16_t length);
////    this->as_wslice().copy_from(input);
  WSeq_for_Uint16_t temp1 = as_wslice_in_BufferSer4(pBufferSer4);
  copy_from_in_WSeq_for_Uint16_t(&temp1, input);
}

RSeq_for_Uint16_t as_rslice_in_BufferSer4(BufferSer4 *pBufferSer4)
{
////    return rseq_t(this->bytes.get(), this->length());
  RSeq_for_Uint16_t rRSeq_for_Uint16_t;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t, pBufferSer4->bytes,
      length_in_HasLength_for_Uint16_t(&(pBufferSer4->hHasLength_for_Uint16_t)));//uint16_t length);
  return rRSeq_for_Uint16_t;
}

WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4)
{
////    return wseq_t(this->bytes.get(), this->length());
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pBufferSer4->bytes,
      length_in_HasLength_for_Uint16_t(&(pBufferSer4->hHasLength_for_Uint16_t)));//uint16_t length);
  return wWSeq_for_Uint16_t;
}
