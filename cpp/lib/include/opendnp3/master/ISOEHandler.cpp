#include "header.h"
#include "ISOEHandler.h"

void BeginFragment_in_ISOEHandler(ISOEHandler* pISOEHandler, ResponseInfo* info)
{
  (pISOEHandler->pBeginFragment_in_ISOEHandler)(pISOEHandler, info);
}
void EndFragment_in_ISOEHandler(ISOEHandler* pISOEHandler, ResponseInfo* info)
{
  (pISOEHandler->pEndFragment_in_ISOEHandler)(pISOEHandler, info);
}

void Process_Indexed_for_Binary_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values)
{
  (pISOEHandler->pProcess_Indexed_for_Binary_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_DoubleBitBinary_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values)
{
  (pISOEHandler->pProcess_Indexed_for_DoubleBitBinary_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_Analog_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values)
{
  (pISOEHandler->pProcess_Indexed_for_Analog_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_Counter_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values)
{
  (pISOEHandler->pProcess_Indexed_for_Counter_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_FrozenCounter_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values)
{
  (pISOEHandler->pProcess_Indexed_for_FrozenCounter_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_BinaryOutputStatus_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values)
{
  (pISOEHandler->pProcess_Indexed_for_BinaryOutputStatus_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_AnalogOutputStatus_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values)
{
  (pISOEHandler->pProcess_Indexed_for_AnalogOutputStatus_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_OctetString_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values)
{
  (pISOEHandler->pProcess_Indexed_for_OctetString_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_TimeAndInterval_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values)
{
  (pISOEHandler->pProcess_Indexed_for_TimeAndInterval_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_BinaryCommandEvent_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values)
{
  (pISOEHandler->pProcess_Indexed_for_BinaryCommandEvent_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_Indexed_for_AnalogCommandEvent_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values)
{
  (pISOEHandler->pProcess_Indexed_for_AnalogCommandEvent_in_ISOEHandler)(pISOEHandler, info, values);
}
void Process_for_DNPTime_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values)
{
  (pISOEHandler->pProcess_for_DNPTime_in_ISOEHandler)(pISOEHandler, info, values);
}

void* getParentPointer_in_ISOEHandler(ISOEHandler* pISOEHandler)
{
  return pISOEHandler->pParentPointer_in_ISOEHandler;
}
void  setParentPointer_in_ISOEHandler(ISOEHandler* pISOEHandler, void* pParentPointer)
{
  pISOEHandler->pParentPointer_in_ISOEHandler = pParentPointer;
}
