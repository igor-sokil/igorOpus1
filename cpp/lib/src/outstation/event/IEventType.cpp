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
