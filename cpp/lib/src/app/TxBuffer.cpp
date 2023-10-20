#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "TxBuffer.h"

void TxBuffer_in_TxBuffer(TxBuffer *pTxBuffer, uint32_t maxTxSize)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"TxBuffer_in_TxBuffer1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxTxSize ="<<maxTxSize<<'\n';
  decrement_stack_info();
#endif
//// : buffer(maxTxSize) {}
  BufferSer4_in_BufferSer4Over2(&(pTxBuffer->buffer), maxTxSize);
  AppControlField_in_AppControlFieldOver1(&(pTxBuffer->control));
}

APDUResponse Start_in_TxBuffer(TxBuffer *pTxBuffer)
{
//    void APDUResponse_in_APDUResponse(APDUResponse *pAPDUResponse, WSeq_for_Uint16_t *buffer);
//    WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    APDUResponse response(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&(pTxBuffer->buffer));
  APDUResponse response;
  APDUResponse_in_APDUResponse(&response, &temp);
  return response;
}

void Record_in_TxBuffer(TxBuffer *pTxBuffer, AppControlField* control, RSeq_for_Uint16_t* view)
{
  pTxBuffer->control = *control;
  pTxBuffer->lastResponse = *view;
}

RSeq_for_Uint16_t* GetLastResponse_in_TxBuffer(TxBuffer *pTxBuffer)
{
  return &(pTxBuffer->lastResponse);
}

AppControlField* GetLastControl_in_TxBuffer(TxBuffer *pTxBuffer)
{
  return &(pTxBuffer->control);
}
