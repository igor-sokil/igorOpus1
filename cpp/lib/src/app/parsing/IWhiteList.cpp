#include <iostream>
#include "header.h"
#include "IWhiteList.h"

boolean IsAllowed_in_IWhiteList(IWhiteList *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
std::cout<<"IsAllowed_in_IWhiteList1"<<std::endl;
  return (pIWhiteList->pIsAllowed_in_IWhiteList)(pIWhiteList, headerCount, gv, qc);
}

void* getParentPointer_in_IWhiteList(IWhiteList* pIWhiteList)
{
  return pIWhiteList->pParentPointer_in_IWhiteList;
}

void  setParentPointer_in_IWhiteList(IWhiteList* pIWhiteList, void* pParentPointer)
{
  pIWhiteList->pParentPointer_in_IWhiteList = pParentPointer;
}
