#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "IUpdateHandler.h"

void* getParentPointer_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler)
{
  return pIUpdateHandler->pParentPointer_in_IUpdateHandler;
}
void  setParentPointer_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, void* pParentPointer)
{
  pIUpdateHandler->pParentPointer_in_IUpdateHandler = pParentPointer;
}

boolean Update_Binary_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, Binary* meas, uint16_t index, EventMode_uint8_t mode)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Update_Binary_in_IUpdateHandler1"<<'\n';
#endif
 boolean tmp = (pIUpdateHandler->pUpdate_Binary_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Update_Binary_in_IUpdateHandler_"<<'\n';
  decrement_stack_info();
#endif
 return tmp;
}

boolean Update_DoubleBitBinary_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pUpdate_DoubleBitBinary_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);
}
boolean Update_Analog_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, Analog* meas, uint16_t index, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pUpdate_Analog_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);
}
boolean Update_Counter_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, Counter* meas, uint16_t index, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pUpdate_Counter_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);
}
boolean FreezeCounter_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, uint16_t index, boolean clear, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pFreezeCounter_in_IUpdateHandler)(pIUpdateHandler, index, clear, mode);
}
boolean Update_BinaryOutputStatus_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pUpdate_BinaryOutputStatus_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);
}
boolean Update_AnalogOutputStatus_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pUpdate_AnalogOutputStatus_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);
}
boolean Update_OctetString_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, OctetString* meas, uint16_t index, EventMode_uint8_t mode)
{
  return (pIUpdateHandler->pUpdate_OctetString_in_IUpdateHandler)(pIUpdateHandler, meas, index, mode);
}
boolean Update_TimeAndInterval_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, TimeAndInterval* meas, uint16_t index)
{
  return (pIUpdateHandler->pUpdate_TimeAndInterval_in_IUpdateHandler)(pIUpdateHandler, meas, index);
}
boolean Modify_in_IUpdateHandler(IUpdateHandler* pIUpdateHandler, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags)
{
 return (pIUpdateHandler->pModify_in_IUpdateHandler)(pIUpdateHandler, type, start, stop, flags);
}

