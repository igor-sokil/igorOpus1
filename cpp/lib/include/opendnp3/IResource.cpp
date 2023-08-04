#include "header.h"
#include "IResource.h"

void Shutdown_in_IResource(IResource* pIResource)
{
  (pIResource->pShutdown_in_IResource)(pIResource);
}

void* getParentPointer_in_IResource(IResource* pIResource)
{
  return pIResource->pParentPointer_in_IResource;
}
void  setParentPointer_in_IResource(IResource* pIResource, void* pParentPointer)
{
  pIResource->pParentPointer_in_IResource = pParentPointer;
}
