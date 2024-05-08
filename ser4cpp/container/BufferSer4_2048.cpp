#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "BufferSer4_2048.h"
/*
void  BufferSer4_2048_in_BufferSer4_2048Over1(BufferSer4_2048 *pBufferSer4_2048)
{
  BufferSer4_Core_in_BufferSer4_CoreOver1(&(pBufferSer4_2048->bBufferSer4_Core), pBufferSer4_2048->bytes);
}
*/

void BufferSer4_2048_in_BufferSer4_2048Over2(BufferSer4_2048 *pBufferSer4_2048, uint16_t length)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"BufferSer4_2048_in_BufferSer4_2048Over2_1"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t length="<<length<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*sizeof(BufferSer4_2048)="<<sizeof(pBufferSer4_2048->bytes)<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t bytes[SIZE_BufferSer4_2048]="<<(uint32_t)pBufferSer4_2048->bytes<<'\n';

  decrement_stack_info();
#endif
  BufferSer4_Core_in_BufferSer4_CoreOver2(&(pBufferSer4_2048->bBufferSer4_Core), pBufferSer4_2048->bytes, length);
}
/*
// initialize with the exact length and contents
void BufferSer4_2048_in_BufferSer4_2048Over3(BufferSer4_2048 *pBufferSer4_2048,  RSeq_for_Uint16_t *input)
{
  BufferSer4_Core_in_BufferSer4_CoreOver3(&(pBufferSer4_2048->bBufferSer4_Core), pBufferSer4_2048->bytes, input);
}
*/

