#include "header.h"
#include "ITaskCallback.h"

void OnDestroyed_in_ITaskCallback(ITaskCallback* pITaskCallback)
{
  (pITaskCallback->pOnDestroyed_in_ITaskCallback)(pITaskCallback);
}

void OnStart_in_ITaskCallback(ITaskCallback* pITaskCallback)
{
  (pITaskCallback->pOnStart_in_ITaskCallback)(pITaskCallback);
}

void OnComplete_in_ITaskCallback(ITaskCallback* pITaskCallback, TaskCompletion_uint8_t result)
{
  (pITaskCallback->pOnComplete_in_ITaskCallback)(pITaskCallback, result);
}

void* getParentPointer_in_ITaskCallback(ITaskCallback* pITaskCallback)
{
  return pITaskCallback->pParentPointer_in_ITaskCallback;
}
void  setParentPointer_in_ITaskCallback(ITaskCallback* pITaskCallback, void* pParentPointer)
{
  pITaskCallback->pParentPointer_in_ITaskCallback = pParentPointer;
}
