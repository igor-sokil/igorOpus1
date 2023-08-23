#include <QtWidgets>
#include "header.h"
#include "IResponseLoader.h"

boolean HasAnySelection_in_IResponseLoader(IResponseLoader *pIResponseLoader)
{
  return (pIResponseLoader->pHasAnySelection_in_IResponseLoader)(pIResponseLoader);
}
boolean Load_in_IResponseLoader(IResponseLoader *pIResponseLoader, HeaderWriter* writer)
{
qDebug()<<"pIResponseLoader  "<<(uint32_t)pIResponseLoader;
qDebug()<<"Load_in_IResponseLoader  "<<(uint32_t)pIResponseLoader->pLoad_in_IResponseLoader;
  return (pIResponseLoader->pLoad_in_IResponseLoader)(pIResponseLoader, writer);
}

void* getParentPointer_in_IResponseLoader(IResponseLoader* pIResponseLoader)
{
  return pIResponseLoader->pParentPointer_in_IResponseLoader;
}

void  setParentPointer_in_IResponseLoader(IResponseLoader* pIResponseLoader, void* pParentPointer)
{
  pIResponseLoader->pParentPointer_in_IResponseLoader = pParentPointer;
}
