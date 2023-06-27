#include "header.h"
#include "IEventWriteHandler.h"

//---------------------------------Analog---------------------------------
boolean Write_in_IEventWriter_for_Analog(IEventWriter_for_Analog* pIEventWriter_for_Analog, Analog* meas, uint16_t index)
{
  return (pIEventWriter_for_Analog->pWrite_in_IEventWriter_for_Analog)(pIEventWriter_for_Analog, meas, index);
}

void* getParentPointer_in_IEventWriter_for_Analog(IEventWriter_for_Analog* pIEventWriter_for_Analog)
{
  return pIEventWriter_for_Analog->pParentPointer_in_IEventWriter_for_Analog;
}
void  setParentPointer_in_IEventWriter_for_Analog(IEventWriter_for_Analog* pIEventWriter_for_Analog, void* pParentPointer)
{
  pIEventWriter_for_Analog->pParentPointer_in_IEventWriter_for_Analog = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_Analog(IEventCollection_for_Analog* pIEventCollection_for_Analog, IEventWriter_for_Analog* handler)
{
  return (pIEventCollection_for_Analog->pWriteSome_in_IEventCollection_for_Analog)(pIEventCollection_for_Analog, handler);
}

void* getParentPointer_in_IEventCollection_for_Analog(IEventCollection_for_Analog* pIEventCollection_for_Analog)
{
  return pIEventCollection_for_Analog->pParentPointer_in_IEventCollection_for_Analog;
}
void  setParentPointer_in_IEventCollection_for_Analog(IEventCollection_for_Analog* pIEventCollection_for_Analog, void* pParentPointer)
{
  pIEventCollection_for_Analog->pParentPointer_in_IEventCollection_for_Analog = pParentPointer;
}
//---------------------------------Analog---------------------------------
//---------------------------------AnalogOutputStatus---------------------------------
boolean Write_in_IEventWriter_for_AnalogOutputStatus(IEventWriter_for_AnalogOutputStatus* pIEventWriter_for_AnalogOutputStatus, AnalogOutputStatus* meas, uint16_t index)
{
  return (pIEventWriter_for_AnalogOutputStatus->pWrite_in_IEventWriter_for_AnalogOutputStatus)(pIEventWriter_for_AnalogOutputStatus, meas, index);
}

void* getParentPointer_in_IEventWriter_for_AnalogOutputStatus(IEventWriter_for_AnalogOutputStatus* pIEventWriter_for_AnalogOutputStatus)
{
  return pIEventWriter_for_AnalogOutputStatus->pParentPointer_in_IEventWriter_for_AnalogOutputStatus;
}
void  setParentPointer_in_IEventWriter_for_AnalogOutputStatus(IEventWriter_for_AnalogOutputStatus* pIEventWriter_for_AnalogOutputStatus, void* pParentPointer)
{
  pIEventWriter_for_AnalogOutputStatus->pParentPointer_in_IEventWriter_for_AnalogOutputStatus = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus* pIEventCollection_for_AnalogOutputStatus, IEventWriter_for_AnalogOutputStatus* handler)
{
  return (pIEventCollection_for_AnalogOutputStatus->pWriteSome_in_IEventCollection_for_AnalogOutputStatus)(pIEventCollection_for_AnalogOutputStatus, handler);
}

void* getParentPointer_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus* pIEventCollection_for_AnalogOutputStatus)
{
  return pIEventCollection_for_AnalogOutputStatus->pParentPointer_in_IEventCollection_for_AnalogOutputStatus;
}
void  setParentPointer_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus* pIEventCollection_for_AnalogOutputStatus, void* pParentPointer)
{
  pIEventCollection_for_AnalogOutputStatus->pParentPointer_in_IEventCollection_for_AnalogOutputStatus = pParentPointer;
}
//---------------------------------AnalogOutputStatus---------------------------------
//---------------------------------Binary---------------------------------
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
//---------------------------------Binary---------------------------------
//---------------------------------BinaryOutputStatus---------------------------------
boolean Write_in_IEventWriter_for_BinaryOutputStatus(IEventWriter_for_BinaryOutputStatus* pIEventWriter_for_BinaryOutputStatus, BinaryOutputStatus* meas, uint16_t index)
{
  return (pIEventWriter_for_BinaryOutputStatus->pWrite_in_IEventWriter_for_BinaryOutputStatus)(pIEventWriter_for_BinaryOutputStatus, meas, index);
}

void* getParentPointer_in_IEventWriter_for_BinaryOutputStatus(IEventWriter_for_BinaryOutputStatus* pIEventWriter_for_BinaryOutputStatus)
{
  return pIEventWriter_for_BinaryOutputStatus->pParentPointer_in_IEventWriter_for_BinaryOutputStatus;
}
void  setParentPointer_in_IEventWriter_for_BinaryOutputStatus(IEventWriter_for_BinaryOutputStatus* pIEventWriter_for_BinaryOutputStatus, void* pParentPointer)
{
  pIEventWriter_for_BinaryOutputStatus->pParentPointer_in_IEventWriter_for_BinaryOutputStatus = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_BinaryOutputStatus(IEventCollection_for_BinaryOutputStatus* pIEventCollection_for_BinaryOutputStatus, IEventWriter_for_BinaryOutputStatus* handler)
{
  return (pIEventCollection_for_BinaryOutputStatus->pWriteSome_in_IEventCollection_for_BinaryOutputStatus)(pIEventCollection_for_BinaryOutputStatus, handler);
}

void* getParentPointer_in_IEventCollection_for_BinaryOutputStatus(IEventCollection_for_BinaryOutputStatus* pIEventCollection_for_BinaryOutputStatus)
{
  return pIEventCollection_for_BinaryOutputStatus->pParentPointer_in_IEventCollection_for_BinaryOutputStatus;
}
void  setParentPointer_in_IEventCollection_for_BinaryOutputStatus(IEventCollection_for_BinaryOutputStatus* pIEventCollection_for_BinaryOutputStatus, void* pParentPointer)
{
  pIEventCollection_for_BinaryOutputStatus->pParentPointer_in_IEventCollection_for_BinaryOutputStatus = pParentPointer;
}
//---------------------------------BinaryOutputStatus---------------------------------
//---------------------------------Counter---------------------------------
boolean Write_in_IEventWriter_for_Counter(IEventWriter_for_Counter* pIEventWriter_for_Counter, Counter* meas, uint16_t index)
{
  return (pIEventWriter_for_Counter->pWrite_in_IEventWriter_for_Counter)(pIEventWriter_for_Counter, meas, index);
}

void* getParentPointer_in_IEventWriter_for_Counter(IEventWriter_for_Counter* pIEventWriter_for_Counter)
{
  return pIEventWriter_for_Counter->pParentPointer_in_IEventWriter_for_Counter;
}
void  setParentPointer_in_IEventWriter_for_Counter(IEventWriter_for_Counter* pIEventWriter_for_Counter, void* pParentPointer)
{
  pIEventWriter_for_Counter->pParentPointer_in_IEventWriter_for_Counter = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_Counter(IEventCollection_for_Counter* pIEventCollection_for_Counter, IEventWriter_for_Counter* handler)
{
  return (pIEventCollection_for_Counter->pWriteSome_in_IEventCollection_for_Counter)(pIEventCollection_for_Counter, handler);
}

void* getParentPointer_in_IEventCollection_for_Counter(IEventCollection_for_Counter* pIEventCollection_for_Counter)
{
  return pIEventCollection_for_Counter->pParentPointer_in_IEventCollection_for_Counter;
}
void  setParentPointer_in_IEventCollection_for_Counter(IEventCollection_for_Counter* pIEventCollection_for_Counter, void* pParentPointer)
{
  pIEventCollection_for_Counter->pParentPointer_in_IEventCollection_for_Counter = pParentPointer;
}
//---------------------------------Counter---------------------------------
//---------------------------------FrozenCounter---------------------------------
boolean Write_in_IEventWriter_for_FrozenCounter(IEventWriter_for_FrozenCounter* pIEventWriter_for_FrozenCounter, FrozenCounter* meas, uint16_t index)
{
  return (pIEventWriter_for_FrozenCounter->pWrite_in_IEventWriter_for_FrozenCounter)(pIEventWriter_for_FrozenCounter, meas, index);
}

void* getParentPointer_in_IEventWriter_for_FrozenCounter(IEventWriter_for_FrozenCounter* pIEventWriter_for_FrozenCounter)
{
  return pIEventWriter_for_FrozenCounter->pParentPointer_in_IEventWriter_for_FrozenCounter;
}
void  setParentPointer_in_IEventWriter_for_FrozenCounter(IEventWriter_for_FrozenCounter* pIEventWriter_for_FrozenCounter, void* pParentPointer)
{
  pIEventWriter_for_FrozenCounter->pParentPointer_in_IEventWriter_for_FrozenCounter = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_FrozenCounter(IEventCollection_for_FrozenCounter* pIEventCollection_for_FrozenCounter, IEventWriter_for_FrozenCounter* handler)
{
  return (pIEventCollection_for_FrozenCounter->pWriteSome_in_IEventCollection_for_FrozenCounter)(pIEventCollection_for_FrozenCounter, handler);
}

void* getParentPointer_in_IEventCollection_for_FrozenCounter(IEventCollection_for_FrozenCounter* pIEventCollection_for_FrozenCounter)
{
  return pIEventCollection_for_FrozenCounter->pParentPointer_in_IEventCollection_for_FrozenCounter;
}
void  setParentPointer_in_IEventCollection_for_FrozenCounter(IEventCollection_for_FrozenCounter* pIEventCollection_for_FrozenCounter, void* pParentPointer)
{
  pIEventCollection_for_FrozenCounter->pParentPointer_in_IEventCollection_for_FrozenCounter = pParentPointer;
}
//---------------------------------FrozenCounter---------------------------------
//---------------------------------DoubleBitBinary---------------------------------
boolean Write_in_IEventWriter_for_DoubleBitBinary(IEventWriter_for_DoubleBitBinary* pIEventWriter_for_DoubleBitBinary, DoubleBitBinary* meas, uint16_t index)
{
  return (pIEventWriter_for_DoubleBitBinary->pWrite_in_IEventWriter_for_DoubleBitBinary)(pIEventWriter_for_DoubleBitBinary, meas, index);
}

void* getParentPointer_in_IEventWriter_for_DoubleBitBinary(IEventWriter_for_DoubleBitBinary* pIEventWriter_for_DoubleBitBinary)
{
  return pIEventWriter_for_DoubleBitBinary->pParentPointer_in_IEventWriter_for_DoubleBitBinary;
}
void  setParentPointer_in_IEventWriter_for_DoubleBitBinary(IEventWriter_for_DoubleBitBinary* pIEventWriter_for_DoubleBitBinary, void* pParentPointer)
{
  pIEventWriter_for_DoubleBitBinary->pParentPointer_in_IEventWriter_for_DoubleBitBinary = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_DoubleBitBinary(IEventCollection_for_DoubleBitBinary* pIEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* handler)
{
  return (pIEventCollection_for_DoubleBitBinary->pWriteSome_in_IEventCollection_for_DoubleBitBinary)(pIEventCollection_for_DoubleBitBinary, handler);
}

void* getParentPointer_in_IEventCollection_for_DoubleBitBinary(IEventCollection_for_DoubleBitBinary* pIEventCollection_for_DoubleBitBinary)
{
  return pIEventCollection_for_DoubleBitBinary->pParentPointer_in_IEventCollection_for_DoubleBitBinary;
}
void  setParentPointer_in_IEventCollection_for_DoubleBitBinary(IEventCollection_for_DoubleBitBinary* pIEventCollection_for_DoubleBitBinary, void* pParentPointer)
{
  pIEventCollection_for_DoubleBitBinary->pParentPointer_in_IEventCollection_for_DoubleBitBinary = pParentPointer;
}
//---------------------------------DoubleBitBinary---------------------------------
//---------------------------------OctetString---------------------------------

uint16_t Write_in_IEventWriter_for_OctetString(IEventWriter_for_OctetString *pIEventWriter_for_OctetString, OctetString* meas, uint16_t index)
{
  return (pIEventWriter_for_OctetString->pWrite_in_IEventWriter_for_OctetString)(pIEventWriter_for_OctetString, meas, index);
}

void* getParentPointer_in_IEventWriter_for_OctetString(IEventWriter_for_OctetString* pIEventWriter_for_OctetString)
{
  return pIEventWriter_for_OctetString->pParentPointer_in_IEventWriter_for_OctetString;
}
void  setParentPointer_in_IEventWriter_for_OctetString(IEventWriter_for_OctetString* pIEventWriter_for_OctetString, void* pParentPointer)
{
  pIEventWriter_for_OctetString->pParentPointer_in_IEventWriter_for_OctetString = pParentPointer;
}

uint16_t WriteSome_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString* pIEventCollection_for_OctetString, IEventWriter_for_OctetString* handler)
{
  return (pIEventCollection_for_OctetString->pWriteSome_in_IEventCollection_for_OctetString)(pIEventCollection_for_OctetString, handler);
}

void* getParentPointer_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString* pIEventCollection_for_OctetString)
{
  return pIEventCollection_for_OctetString->pParentPointer_in_IEventCollection_for_OctetString;
}
void  setParentPointer_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString* pIEventCollection_for_OctetString, void* pParentPointer)
{
  pIEventCollection_for_OctetString->pParentPointer_in_IEventCollection_for_OctetString = pParentPointer;
}
//---------------------------------OctetString---------------------------------

//---------------------------------IEventWriteHandler---------------------------------
uint16_t Write_for_Binary_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
{
  return (pIEventWriteHandler->pWrite_for_Binary_in_IEventWriteHandler)(pIEventWriteHandler, variation, first, items);
}

uint16_t Write_for_DoubleBitBinary_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventDoubleBinaryVariation_uint8_t variation,
    DoubleBitBinary* first,
    IEventCollection_for_DoubleBitBinary* items)
{
  return (pIEventWriteHandler->pWrite_for_DoubleBitBinary_in_IEventWriteHandler)(pIEventWriteHandler, variation,
         first,
         items);
}

uint16_t Write_for_Counter_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventCounterVariation_uint8_t variation, Counter* first, IEventCollection_for_Counter* items)
{
  return (pIEventWriteHandler->pWrite_for_Counter_in_IEventWriteHandler)(pIEventWriteHandler, variation, first, items);
}

uint16_t Write_for_FrozenCounter_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventFrozenCounterVariation_uint8_t variation,
    FrozenCounter* first,
    IEventCollection_for_FrozenCounter* items)
{
  return (pIEventWriteHandler->pWrite_for_FrozenCounter_in_IEventWriteHandler)(pIEventWriteHandler, variation,
         first,
         items);
}

uint16_t Write_for_Analog_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items)
{
  return (pIEventWriteHandler->pWrite_for_Analog_in_IEventWriteHandler)(pIEventWriteHandler, variation, first, items);
}

uint16_t Write_for_BinaryOutputStatus_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventBinaryOutputStatusVariation_uint8_t variation,
    BinaryOutputStatus* first,
    IEventCollection_for_BinaryOutputStatus* items)
{
  return (pIEventWriteHandler->pWrite_for_BinaryOutputStatus_in_IEventWriteHandler)(pIEventWriteHandler, variation,
         first,
         items);
}

uint16_t Write_for_AnalogOutputStatus_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventAnalogOutputStatusVariation_uint8_t variation,
    AnalogOutputStatus* first,
    IEventCollection_for_AnalogOutputStatus* items)
{
  return (pIEventWriteHandler->pWrite_for_AnalogOutputStatus_in_IEventWriteHandler)(pIEventWriteHandler, variation,
         first,
         items);
}

uint16_t Write_for_OctetString_in_IEventWriteHandler(IEventWriteHandler *pIEventWriteHandler, EventOctetStringVariation_uint8_t variation,
    OctetString* first,
    IEventCollection_for_OctetString* items)
{
  return (pIEventWriteHandler->pWrite_for_OctetString_in_IEventWriteHandler)(pIEventWriteHandler, variation,
         first,
         items);
}

void* getParentPointer_in_IEventWriteHandler(IEventWriteHandler* pIEventWriteHandler)
{
  return pIEventWriteHandler->pParentPointer_in_IEventWriteHandler;
}

void  setParentPointer_in_IEventWriteHandler(IEventWriteHandler* pIEventWriteHandler, void* pParentPointer)
{
  pIEventWriteHandler->pParentPointer_in_IEventWriteHandler = pParentPointer;
}

//---------------------------------IEventWriteHandler---------------------------------
