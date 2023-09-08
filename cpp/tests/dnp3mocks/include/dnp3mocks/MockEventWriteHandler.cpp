#include <QApplication>
//#include <QtWidgets>
#include "header.h"
#include "MockEventWriteHandler.h"

std::deque<Record_in_MockEventWriteHandler> expected_in_MockEventWriteHandler;

void MockEventWriteHandler_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler)
{
  EventWriterImpl_for_Analog_in_EventWriterImpl_for_Analog(&(pMockEventWriteHandler->eEventWriterImpl_for_Analog));
  EventWriterImpl_for_Binary_in_EventWriterImpl_for_Binary(&(pMockEventWriteHandler->eEventWriterImpl_for_Binary));

  pMockEventWriteHandler->iIEventWriteHandler.pWrite_for_Analog_in_IEventWriteHandler = Write_for_Analog_in_MockEventWriteHandler_override;
  pMockEventWriteHandler->iIEventWriteHandler.pWrite_for_Binary_in_IEventWriteHandler = Write_for_Binary_in_MockEventWriteHandler_override;
  setParentPointer_in_IEventWriteHandler(&(pMockEventWriteHandler->iIEventWriteHandler), pMockEventWriteHandler);
}

boolean Write_in_EventWriterImpl_for_Analog_override(void *pEventWriterImpl_for_Analog, Analog* meas, uint16_t index)
{
  EventWriterImpl_for_Analog* parent = (EventWriterImpl_for_Analog*)getParentPointer_in_IEventWriter_for_Analog((EventWriterImpl_for_Analog*)pEventWriterImpl_for_Analog);
  return Write_in_EventWriterImpl_for_Analog(parent, meas, index);
}

boolean Write_in_EventWriterImpl_for_Analog(EventWriterImpl_for_Analog *pEventWriterImpl_for_Analog, Analog* meas, uint16_t index)
{
  if (pEventWriterImpl_for_Analog->success)
  {
    pEventWriterImpl_for_Analog->written_indices.push_back(index);
  }
  return pEventWriterImpl_for_Analog->success;
}

void EventWriterImpl_for_Analog_in_EventWriterImpl_for_Analog(EventWriterImpl_for_Analog *pEventWriterImpl_for_Analog)
{
  pEventWriterImpl_for_Analog->success = true;

  pEventWriterImpl_for_Analog->iIEventWriter_for_Analog.pWrite_in_IEventWriter_for_Analog = Write_in_EventWriterImpl_for_Analog_override;
  setParentPointer_in_IEventWriter_for_Analog(&(pEventWriterImpl_for_Analog->iIEventWriter_for_Analog), pEventWriterImpl_for_Analog);
}

boolean Write_in_EventWriterImpl_for_Binary_override(void *pEventWriterImpl_for_Binary, Binary* meas, uint16_t index)
{
  EventWriterImpl_for_Binary* parent = (EventWriterImpl_for_Binary*)getParentPointer_in_IEventWriter_for_Binary((EventWriterImpl_for_Binary*)pEventWriterImpl_for_Binary);
  return Write_in_EventWriterImpl_for_Binary(parent, meas, index);
}

boolean Write_in_EventWriterImpl_for_Binary(EventWriterImpl_for_Binary *pEventWriterImpl_for_Binary, Binary* meas, uint16_t index)
{
  if (pEventWriterImpl_for_Binary->success)
  {
    pEventWriterImpl_for_Binary->written_indices.push_back(index);
  }
  return pEventWriterImpl_for_Binary->success;
}

void EventWriterImpl_for_Binary_in_EventWriterImpl_for_Binary(EventWriterImpl_for_Binary *pEventWriterImpl_for_Binary)
{
  pEventWriterImpl_for_Binary->success = true;

  pEventWriterImpl_for_Binary->iIEventWriter_for_Binary.pWrite_in_IEventWriter_for_Binary
  setParentPointer_in_IEventWriter_for_Binary(&(pEventWriterImpl_for_Binary->iIEventWriter_for_Binary), pEventWriterImpl_for_Binary);
}


uint16_t Write_for_Analog_in_MockEventWriteHandler_override(void *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items)
{
  MockEventWriteHandler* parent = (MockEventWriteHandler*) getParentPointer_in_IEventWriteHandler((MockEventWriteHandler*)pMockEventWriteHandler);
  return Write_for_Analog_in_MockEventWriteHandler(parent, variation, first, items);
}
uint16_t Write_for_Binary_in_MockEventWriteHandler_override(void *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
{
  MockEventWriteHandler* parent = (MockEventWriteHandler*) getParentPointer_in_IEventWriteHandler((MockEventWriteHandler*)pMockEventWriteHandler);
  return Write_for_Binary_in_MockEventWriteHandler(parent, variation, first, items);
}

uint16_t Write_for_Analog_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items)
{
  UNUSED(first);
////        return this->WriteAny<opendnp3::AnalogInfo>(variation, items);
  return WriteAny_for_Binary_in_MockEventWriteHandler(variation, items);
}
uint16_t Write_for_Binary_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
{
  UNUSED(first);
////        return this->WriteAny<opendnp3::AnalogInfo>(variation, items);
  return WriteAny_for_Binary_in_MockEventWriteHandler(variation, items);
}



