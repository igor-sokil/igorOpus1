#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ILinkTx.h"

void BeginTransmit_in_ILinkTx(ILinkTx* pILinkTx, RSeq_for_Uint16_t* buffer, ILinkSession* context)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{BeginTransmit_in_ILinkTx1"<<'\n';
#endif
  (pILinkTx->pBeginTransmit_in_ILinkTx)(pILinkTx, buffer, context);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BeginTransmit_in_ILinkTx_"<<'\n';
  decrement_stack_info();
#endif
}

void* getParentPointer_in_ILinkTx(ILinkTx* pILinkTx)
{
  return pILinkTx->pParentPointer_in_ILinkTx;
}

void  setParentPointer_in_ILinkTx(ILinkTx* pILinkTx, void* pParentPointer)
{
  pILinkTx->pParentPointer_in_ILinkTx = pParentPointer;
}
