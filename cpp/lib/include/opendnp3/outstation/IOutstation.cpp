#include "header.h"
#include "IOutstation.h"

    void SetRestartIIN_in_IOutstation(IOutstation* pIOutstation)
{
 (pIOutstation->pSetRestartIIN_in_IOutstation)(pIOutstation);
}
    void Apply_in_IOutstation(IOutstation* pIOutstation, Updates* updates)
{
 (pIOutstation->pApply_in_IOutstation)(pIOutstation, updates);
}

void* getParentPointer_in_IOutstation(IOutstation* pIOutstation)
{
  return pIOutstation->pParentPointer_in_IOutstation;
}

void  setParentPointer_in_IOutstation(IOutstation* pIOutstation, void* pParentPointer)
{
  pIOutstation->pParentPointer_in_IOutstation = pParentPointer;
}
