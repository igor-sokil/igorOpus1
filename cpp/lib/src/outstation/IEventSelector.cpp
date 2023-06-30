#include "header.h"
#include "IEventSelector.h"

IINField SelectAll_in_IEventSelector(IEventSelector *pIEventSelector, GroupVariation_uint16_t gv)
{
  return (pIEventSelector->pSelectAll_in_IEventSelector)(pIEventSelector,gv);
}
IINField SelectCount_in_IEventSelector(IEventSelector *pIEventSelector, GroupVariation_uint16_t gv, uint16_t count)
{
  return (pIEventSelector->pSelectCount_in_IEventSelector)(pIEventSelector, gv,  count);
}

void* getParentPointer_in_IEventSelector(IEventSelector* pIEventSelector)
{
  return pIEventSelector->pParentPointer_in_IEventSelector;
}

void  setParentPointer_in_IEventSelector(IEventSelector* pIEventSelector, void* pParentPointer)
{
  pIEventSelector->pParentPointer_in_IEventSelector = pParentPointer;
}
