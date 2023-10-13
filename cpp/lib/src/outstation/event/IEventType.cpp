//#include <QtWidgets>
#include "header.h"
#include "IEventType.h"

void IEventType_in_IEventType(IEventType *pIEventType, EventType_uint16_t value)
{
  pIEventType->value = value;
}

boolean IsEqual_in_IEventType(IEventType* pIEventType, EventType_uint16_t type)
{
  return type == pIEventType->value;
}

boolean IsNotEqual_in_IEventType(IEventType* pIEventType, EventType_uint16_t type)
{
  return type != pIEventType->value;
}

void SelectDefaultVariation_in_IEventType(IEventType *pIEventType, EventRecord* record)
{
  (pIEventType->pSelectDefaultVariation_in_IEventType)(pIEventType, record);
}
uint16_t WriteSome_in_IEventType(IEventType *pIEventType,
                                 Iterator_in_List_for_EventRecord* iterator,
                                 EventLists* lists,
                                 IEventWriteHandler* handler)
{
  return (pIEventType->pWriteSome_in_IEventType)(pIEventType,
         iterator,
         lists,
         handler);
}

void RemoveTypeFromStorage_in_IEventType(IEventType *pIEventType, EventRecord* record, EventLists* lists)
{
  (pIEventType->pRemoveTypeFromStorage_in_IEventType)(pIEventType, record, lists);
}

void* getParentPointer_in_IEventType(IEventType* pIEventType)
{
  return pIEventType->pParentPointer_in_IEventType;
}

void  setParentPointer_in_IEventType(IEventType* pIEventType, void* pParentPointer)
{
  pIEventType->pParentPointer_in_IEventType = pParentPointer;
}
