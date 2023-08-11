//#include <QtWidgets>
#include "header.h"
#include "ILinkTx.h"

void BeginTransmit_in_ILinkTx(ILinkTx* pILinkTx, RSeq_for_Uint16_t* buffer, ILinkSession* context)
{
  (pILinkTx->pBeginTransmit_in_ILinkTx)(pILinkTx, buffer, context);
}

void* getParentPointer_in_ILinkTx(ILinkTx* pILinkTx)
{
  return pILinkTx->pParentPointer_in_ILinkTx;
}

void  setParentPointer_in_ILinkTx(ILinkTx* pILinkTx, void* pParentPointer)
{
  pILinkTx->pParentPointer_in_ILinkTx = pParentPointer;
}
