
//#include "log_info.h"
//#ifdef  LOG_INFO
//#include <iostream>
//#endif
#include "header.h"
#include "LayerInterfaces.h"
#include <string.h>

boolean OnLowerLayerUp_in_IUpDown(IUpDown *pIUpDown)
{
  return (pIUpDown->pOnLowerLayerUp_in_IUpDown)(pIUpDown);
}
boolean OnLowerLayerDown_in_IUpDown(IUpDown *pIUpDown)
{
  return (pIUpDown->pOnLowerLayerDown_in_IUpDown)(pIUpDown);
}

void* getParentPointer_in_IUpDown(IUpDown* pIUpDown)
{
  return pIUpDown->pParentPointer_in_IUpDown;
}
void  setParentPointer_in_IUpDown(IUpDown* pIUpDown, void* pParentPointer)
{
  pIUpDown->pParentPointer_in_IUpDown = pParentPointer;
}

boolean OnReceive_in_IUpperLayer(IUpperLayer *pIUpperLayer, Message* message)
{
  return (pIUpperLayer->pOnReceive_in_IUpperLayer)(pIUpperLayer, message);
}
boolean OnTxReady_in_IUpperLayer(IUpperLayer *pIUpperLayer)
{
  return (pIUpperLayer->pOnTxReady_in_IUpperLayer)(pIUpperLayer);
}

void* getParentPointer_in_IUpperLayer(IUpperLayer* pIUpperLayer)
{
  return pIUpperLayer->pParentPointer_in_IUpperLayer;
}
void  setParentPointer_in_IUpperLayer(IUpperLayer* pIUpperLayer, void* pParentPointer)
{
  pIUpperLayer->pParentPointer_in_IUpperLayer = pParentPointer;
}

boolean BeginTransmit_in_ILowerLayer(ILowerLayer *pILowerLayer, Message* message)
{
  return (pILowerLayer->pBeginTransmit_in_ILowerLayer)(pILowerLayer, message);
}

void* getParentPointer_in_ILowerLayer(ILowerLayer* pILowerLayer)
{
  return pILowerLayer->pParentPointer_in_ILowerLayer;
}
void  setParentPointer_in_ILowerLayer(ILowerLayer* pILowerLayer, void* pParentPointer)
{
  pILowerLayer->pParentPointer_in_ILowerLayer = pParentPointer;
}

void HasLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer)
{
  pHasLowerLayer->pLowerLayer = NULL;
}

void SetLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer, ILowerLayer* lowerLayer)
{
////        assert(!pLowerLayer);
//LOG_INFO  if(pHasLowerLayer->pLowerLayer) std::cout<<"assert(!pLowerLayer)"<<'\n';
  pHasLowerLayer->pLowerLayer = lowerLayer;
}

void HasUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer)
{
  pHasUpperLayer->pUpperLayer = NULL;
}

void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer)
{
////        assert(!pUpperLayer);
//LOG_INFO  if(pHasUpperLayer->pUpperLayer) std::cout<<"assert(!pUpperLayer)"<<'\n';
  pHasUpperLayer->pUpperLayer = upperLayer;
}
