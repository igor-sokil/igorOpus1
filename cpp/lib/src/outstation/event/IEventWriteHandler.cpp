#include "header.h"
#include "IEventWriteHandler.h"


//---------------------------------IEventWriter_for_Binary---------------------------------
  boolean Write_in_IEventWriter_for_Binary(IEventWriter_for_Binary* pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
  return (pIEventWriter_for_Binary->pWrite_in_IEventWriter_for_Binary)(pIEventWriter_for_Binary, meas, index);
}

  void* getParentPointer_in_IEventWriter_for_Binary(IEventWriter_for_Binary* pIEventWriter_for_Binary)
{
  return pIEventWriter_for_Binary->pParentPointer_in_IEventWriter_for_Binary;
}
  void  setParentPointer_in_IEventWriter_for_Binary(IEventWriter_for_Binary* pIEventWriter_for_Binary, void* pParentPointer)
{
  pIEventWriter_for_Binary->pParentPointer_in_IEventWriter_for_Binary = pParentPointer;
}
  uint8_t getParentType_in_IEventWriter_for_Binary(IEventWriter_for_Binary* pIEventWriter_for_Binary)
{
  return pIEventWriter_for_Binary->parentType_in_IEventWriter_for_Binary;
}
  void    setParentType_in_IEventWriter_for_Binary(IEventWriter_for_Binary* pIEventWriter_for_Binary, uint8_t parentType)
{
  pIEventWriter_for_Binary->parentType_in_IEventWriter_for_Binary = parentType;
}
//---------------------------------IEventWriter_for_Binary---------------------------------
//---------------------------------IEventCollection_for_Binary---------------------------------
  uint16_t WriteSome_in_IEventCollection_for_Binary(IEventCollection_for_Binary* pIEventCollection_for_Binary, IEventWriter_for_Binary* handler)
{
 return (pIEventCollection_for_Binary->pWriteSome_in_IEventCollection_for_Binary)(pIEventCollection_for_Binary, handler);
}

  void* getParentPointer_in_IEventCollection_for_Binary(IEventCollection_for_Binary* pIEventCollection_for_Binary)
{
  return pIEventCollection_for_Binary->pParentPointer_in_IEventCollection_for_Binary;
}
  void  setParentPointer_in_IEventCollection_for_Binary(IEventCollection_for_Binary* pIEventCollection_for_Binary, void* pParentPointer)
{
  pIEventCollection_for_Binary->pParentPointer_in_IEventCollection_for_Binary = pParentPointer;
}
  uint8_t getParentType_in_IEventCollection_for_Binary(IEventCollection_for_Binary* pIEventCollection_for_Binary)
{
  return pIEventCollection_for_Binary->parentType_in_IEventCollection_for_Binary;
}
  void    setParentType_in_IEventCollection_for_Binary(IEventCollection_for_Binary* pIEventCollection_for_Binary, uint8_t parentType)
{
  pIEventCollection_for_Binary->parentType_in_IEventCollection_for_Binary = parentType;
}
//---------------------------------IEventCollection_for_Binary---------------------------------
