#include <QApplication>
//#include <QtWidgets>
#include "log_info.h"
//#ifndef  LOG_INFO_INC
#include <iostream>
//#endif
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

boolean Write_in_EventWriterImpl_for_Analog_override(void *pIEventWriter_for_Analog, Analog* meas, uint16_t index)
{
  EventWriterImpl_for_Analog* parent = (EventWriterImpl_for_Analog*)getParentPointer_in_IEventWriter_for_Analog((IEventWriter_for_Analog*)pIEventWriter_for_Analog);
  return Write_in_EventWriterImpl_for_Analog(parent, meas, index);
}

boolean Write_in_EventWriterImpl_for_Analog(EventWriterImpl_for_Analog *pEventWriterImpl_for_Analog, Analog* meas, uint16_t index)
{
  UNUSED(meas);

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

boolean Write_in_EventWriterImpl_for_Binary_override(void *pIEventWriter_for_Binary, Binary* meas, uint16_t index)
{
  EventWriterImpl_for_Binary* parent = (EventWriterImpl_for_Binary*)getParentPointer_in_IEventWriter_for_Binary((IEventWriter_for_Binary*)pIEventWriter_for_Binary);
  return Write_in_EventWriterImpl_for_Binary(parent, meas, index);
}

boolean Write_in_EventWriterImpl_for_Binary(EventWriterImpl_for_Binary *pEventWriterImpl_for_Binary, Binary* meas, uint16_t index)
{
  UNUSED(meas);

  if (pEventWriterImpl_for_Binary->success)
  {
    pEventWriterImpl_for_Binary->written_indices.push_back(index);
  }
  return pEventWriterImpl_for_Binary->success;
}

void EventWriterImpl_for_Binary_in_EventWriterImpl_for_Binary(EventWriterImpl_for_Binary *pEventWriterImpl_for_Binary)
{
  pEventWriterImpl_for_Binary->success = true;

  pEventWriterImpl_for_Binary->iIEventWriter_for_Binary.pWrite_in_IEventWriter_for_Binary = Write_in_EventWriterImpl_for_Binary_override;
  setParentPointer_in_IEventWriter_for_Binary(&(pEventWriterImpl_for_Binary->iIEventWriter_for_Binary), pEventWriterImpl_for_Binary);
}

uint16_t Write_for_Analog_in_MockEventWriteHandler_override(void *pIEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items)
{
  MockEventWriteHandler* parent = (MockEventWriteHandler*) getParentPointer_in_IEventWriteHandler((IEventWriteHandler*)pIEventWriteHandler);
  return Write_for_Analog_in_MockEventWriteHandler(parent, variation, first, items);
}
uint16_t Write_for_Binary_in_MockEventWriteHandler_override(void *pIEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
{
  MockEventWriteHandler* parent = (MockEventWriteHandler*) getParentPointer_in_IEventWriteHandler((IEventWriteHandler*)pIEventWriteHandler);
  return Write_for_Binary_in_MockEventWriteHandler(parent, variation, first, items);
}

uint16_t Write_for_Analog_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items)
{
  UNUSED(first);
////        return this->WriteAny<opendnp3::AnalogInfo>(variation, items);
  return WriteAny_for_Analog_in_MockEventWriteHandler(pMockEventWriteHandler, variation, items);
}
uint16_t Write_for_Binary_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items)
{
  UNUSED(first);
////        return this->WriteAny<opendnp3::AnalogInfo>(variation, items);
  return WriteAny_for_Binary_in_MockEventWriteHandler(pMockEventWriteHandler, variation, items);
}

////template<class T>
////uint16_t MockEventWriteHandler::WriteAny(typename T::event_variation_t variation,
////                                         opendnp3::IEventCollection<typename T::meas_t>& items)
uint16_t WriteAny_for_Analog_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, IEventCollection_for_Analog* items)
{
//  qDebug()<<"";
//  qDebug()<<"WriteAny_for_Analog_in_MockEventWriteHandler1";

  UNUSED(pMockEventWriteHandler);
////    if (this->expected.empty())
  if(expected_in_MockEventWriteHandler.empty())
  {
////        throw std::logic_error("no more write events expected");
    std::cout<<"throw std::logic_error('no more write events expected')"<<'\n';
    return 0;
  }

////    const auto record = this->expected.front();
  Record_in_MockEventWriteHandler record = expected_in_MockEventWriteHandler.front();
////    this->expected.pop_front();
  expected_in_MockEventWriteHandler.pop_front();

////    if (record.type != T::EventTypeEnum)
  if (record.type != EventType_Analog)
  {
////        std::ostringstream oss;
////        oss << "Unexpected event type: " << static_cast<int>(record.type);
////        throw std::logic_error(oss.str());
    std::cout<<"oss << 'Unexpected event type: ' << static_cast<int>(record.type)"<<'\n';
    return 0;
  }

////    if (record.variation != static_cast<uint8_t>(variation))
  if (record.variation != (uint8_t)(variation))
  {
////        std::ostringstream oss;
////        oss << "Unexpected variation: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    std::cout<<"oss << 'Unexpected variation: ' << static_cast<int>(variation)"<<'\n';
    return 0;
  }

////    EventWriterImpl<typename T::meas_t> writer;
  EventWriterImpl_for_Analog  writer;
  EventWriterImpl_for_Analog_in_EventWriterImpl_for_Analog(&writer);
//uint16_t WriteSome_in_IEventCollection_for_Analog(IEventCollection_for_Analog *, IEventWriter_for_Analog* handler);
////    const uint16_t count = items.WriteSome(writer);
  uint16_t count = WriteSome_in_IEventCollection_for_Analog(items, &(writer.iIEventWriter_for_Analog));

//  qDebug()<<"WriteAny_for_Analog_in_MockEventWriteHandler count="<<count;
//  qDebug()<<"WriteAny_for_Analog_in_MockEventWriteHandler record.count="<<record.count;
  if (record.count != count)
  {
////        std::ostringstream oss;
////        oss << "Unexpected count: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    std::cout<<"oss << 'Unexpected count: ' << static_cast<int>(variation)"<<'\n';
    return 0;
  }

  return count;
}

////template<class T>
////uint16_t MockEventWriteHandler::WriteAny(typename T::event_variation_t variation,
////                                         opendnp3::IEventCollection<typename T::meas_t>& items)
uint16_t WriteAny_for_Binary_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, IEventCollection_for_Binary* items)
{
   std::cout<<'\n';
   std::cout<<"WriteAny_for_Binary_in_MockEventWriteHandler1"<<'\n';

  UNUSED(pMockEventWriteHandler);
////    if (this->expected.empty())
  if(expected_in_MockEventWriteHandler.empty())
  {
////        throw std::logic_error("no more write events expected");
     std::cout<<"throw std::logic_error('no more write events expected')"<<'\n';
    return 0;
  }

////    const auto record = this->expected.front();
  Record_in_MockEventWriteHandler record = expected_in_MockEventWriteHandler.front();
////    this->expected.pop_front();
  expected_in_MockEventWriteHandler.pop_front();

////    if (record.type != T::EventTypeEnum)
  if (record.type != EventType_Binary)
  {
////        std::ostringstream oss;
////        oss << "Unexpected event type: " << static_cast<int>(record.type);
////        throw std::logic_error(oss.str());
    std::cout<<"oss << 'Unexpected event type: ' << static_cast<int>(record.type)"<<'\n';
    return 0;
  }

////    if (record.variation != static_cast<uint8_t>(variation))
  if (record.variation != (uint8_t)(variation))
  {
////        std::ostringstream oss;
////        oss << "Unexpected variation: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
     std::cout<<"oss << 'Unexpected variation: ' << static_cast<int>(variation)";
    return 0;
  }

////    EventWriterImpl<typename T::meas_t> writer;
  EventWriterImpl_for_Binary  writer;
  EventWriterImpl_for_Binary_in_EventWriterImpl_for_Binary(&writer);
//uint16_t WriteSome_in_IEventCollection_for_Binary(IEventCollection_for_Binary *, IEventWriter_for_Binary* handler);
////    const uint16_t count = items.WriteSome(writer);
  uint16_t count = WriteSome_in_IEventCollection_for_Binary(items, &(writer.iIEventWriter_for_Binary));
//  qDebug()<<"WriteAny_for_Binary_in_MockEventWriteHandler count="<<count;
//  qDebug()<<"WriteAny_for_Binary_in_MockEventWriteHandler record.count="<<record.count;

  if (record.count != count)
  {
////        std::ostringstream oss;
////        oss << "Unexpected count: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
    std::cout<<"oss << 'Unexpected count: ' << static_cast<int>(variation)"<<'\n';
    return 0;
  }

  return count;
}

void ExpectType_for_Analog_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, uint16_t count)
{
  UNUSED(pMockEventWriteHandler);
////        expected.push_back(Record{T::EventTypeEnum, static_cast<uint8_t>(variation), count});
  Record_in_MockEventWriteHandler record = {EventType_Analog, variation, count};

  expected_in_MockEventWriteHandler.push_back(record);
//qDebug()<<"expected_in_MockEventWriteHandler.size()= "<<expected_in_MockEventWriteHandler.size();
}

void ExpectType_for_Binary_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, uint16_t count)
{
  UNUSED(pMockEventWriteHandler);
////        expected.push_back(Record{T::EventTypeEnum, static_cast<uint8_t>(variation), count});
  Record_in_MockEventWriteHandler record = {EventType_Binary, variation, count};

  expected_in_MockEventWriteHandler.push_back(record);
//qDebug()<<"expected_in_MockEventWriteHandler.size()= "<<expected_in_MockEventWriteHandler.size();
}

void Expect_for_Analog_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, uint16_t count)
{
////        this->ExpectType<opendnp3::BinaryInfo>(variation, count);
  ExpectType_for_Analog_in_MockEventWriteHandler(pMockEventWriteHandler, variation, count);
}

void Expect_for_Binary_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, uint16_t count)
{
////        this->ExpectType<opendnp3::BinaryInfo>(variation, count);
  ExpectType_for_Binary_in_MockEventWriteHandler(pMockEventWriteHandler, variation, count);
}

void AssertEmpty_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler)
{
  UNUSED(pMockEventWriteHandler);

//  uint16_t size = expected_in_MockEventWriteHandler.size();
//qDebug()<<"uint16_t size = "<<size;
////        if (!this->expected.empty())
  if(!expected_in_MockEventWriteHandler.empty())
  {
////            throw std::logic_error("more events expected");
    std::cout<<"throw std::logic_error('more events expected')"<<'\n';
  }
}
