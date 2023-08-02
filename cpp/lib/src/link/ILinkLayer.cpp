#include "header.h"
#include "ILinkLayer.h"

boolean Send_in_ILinkLayer(ILinkLayer* pILinkLayer, ITransportSegment* segment)
{
  return (pILinkLayer->pSend_in_ILinkLayer)(pILinkLayer, segment);
}

void* getParentPointer_in_ILinkLayer(ILinkLayer* pILinkLayer)
{
  return pILinkLayer->pParentPointer_in_ILinkLayer;
}
void  setParentPointer_in_ILinkLayer(ILinkLayer* pILinkLayer, void* pParentPointer)
{
  pILinkLayer->pParentPointer_in_ILinkLayer = pParentPointer;
}
