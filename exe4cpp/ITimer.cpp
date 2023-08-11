#include "header.h"
#include "ITimer.h"

    void cancel_in_ITimer(ITimer* pITimer)
{
   (pITimer->pcancel_in_ITimer)(pITimer);
}
    uint32_t expires_at_in_ITimer(ITimer* pITimer)
{
   return (pITimer->pexpires_at_in_ITimer)(pITimer);
}

void* getParentPointer_in_ITimer(ITimer* pITimer)
{
  return pITimer->pParentPointer_in_ITimer;
}
void  setParentPointer_in_ITimer(ITimer* pITimer, void* pParentPointer)
{
  pITimer->pParentPointer_in_ITimer = pParentPointer;
}
