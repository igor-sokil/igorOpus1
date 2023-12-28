#include "header.h"
#include "ICommandCollection.h"

//------------------------AnalogOutputInt16-------------------------
void* Add_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16* pICommandCollection_for_AnalogOutputInt16,
    AnalogOutputInt16* command, uint16_t index)
{
  return (pICommandCollection_for_AnalogOutputInt16->pAdd_in_ICommandCollection_for_AnalogOutputInt16)(pICommandCollection_for_AnalogOutputInt16, command, index);
}

void* getParentPointer_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16* pICommandCollection_for_AnalogOutputInt16)
{
  return pICommandCollection_for_AnalogOutputInt16->pParentPointer_in_ICommandCollection_for_AnalogOutputInt16;
}
void  setParentPointer_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16* pICommandCollection_for_AnalogOutputInt16, void* pParentPointer)
{
  pICommandCollection_for_AnalogOutputInt16->pParentPointer_in_ICommandCollection_for_AnalogOutputInt16 = pParentPointer;
}
//------------------------AnalogOutputInt16-------------------------
//------------------------AnalogOutputInt32-------------------------
void* Add_in_ICommandCollection_for_AnalogOutputInt32(ICommandCollection_for_AnalogOutputInt32* pICommandCollection_for_AnalogOutputInt32,
    AnalogOutputInt32* command, uint16_t index)
{
  return (pICommandCollection_for_AnalogOutputInt32->pAdd_in_ICommandCollection_for_AnalogOutputInt32)(pICommandCollection_for_AnalogOutputInt32, command, index);
}

void* getParentPointer_in_ICommandCollection_for_AnalogOutputInt32(ICommandCollection_for_AnalogOutputInt32* pICommandCollection_for_AnalogOutputInt32)
{
  return pICommandCollection_for_AnalogOutputInt32->pParentPointer_in_ICommandCollection_for_AnalogOutputInt32;
}
void  setParentPointer_in_ICommandCollection_for_AnalogOutputInt32(ICommandCollection_for_AnalogOutputInt32* pICommandCollection_for_AnalogOutputInt32, void* pParentPointer)
{
  pICommandCollection_for_AnalogOutputInt32->pParentPointer_in_ICommandCollection_for_AnalogOutputInt32 = pParentPointer;
}
//------------------------AnalogOutputInt32-------------------------

