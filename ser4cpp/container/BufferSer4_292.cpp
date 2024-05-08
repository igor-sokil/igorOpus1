#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "BufferSer4_292.h"
/*
void  BufferSer4_292_in_BufferSer4_292Over1(BufferSer4_292 *pBufferSer4_292)
{
  BufferSer4_Core_in_BufferSer4_CoreOver1(&(pBufferSer4_292->bBufferSer4_Core), pBufferSer4_292->bytes);
}
*/
////    ~BufferSer4_Core() = default;

void BufferSer4_292_in_BufferSer4_292Over2(BufferSer4_292 *pBufferSer4_292, uint16_t length)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"BufferSer4_292_in_BufferSer4_292Over2_1"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t length="<<length<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*sizeof(BufferSer4_292)="<<sizeof(pBufferSer4_292->bytes)<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t bytes[SIZE_BufferSer4_292]="<<(uint32_t)pBufferSer4_292->bytes<<'\n';

  decrement_stack_info();
#endif
  BufferSer4_Core_in_BufferSer4_CoreOver2(&(pBufferSer4_292->bBufferSer4_Core), pBufferSer4_292->bytes, length);
}
/*
// initialize with the exact length and contents
void BufferSer4_292_in_BufferSer4_292Over3(BufferSer4_292 *pBufferSer4_292,  RSeq_for_Uint16_t *input)
{
  BufferSer4_Core_in_BufferSer4_CoreOver3(&(pBufferSer4_292->bBufferSer4_Core), pBufferSer4_292->bytes, input);
}
*/
