/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef OPENDNP3_UNITTESTS_MOCK_EVENT_WRITE_HANDLER_H
#define OPENDNP3_UNITTESTS_MOCK_EVENT_WRITE_HANDLER_H

////#include <opendnp3/app/EventType.h>
////#include <opendnp3/app/MeasurementInfo.h>

////#include <outstation/event/IEventWriteHandler.h>

////#include <deque>
////#include <sstream>
////#include <vector>
#include "EventType.h"
#include "MeasurementInfo.h"

#include "IEventWriteHandler.h"

#include <deque>
#include <vector>

//    struct Record
typedef struct
{
  EventType_uint16_t type;
  uint8_t variation;
  uint16_t count;
} Record_in_MockEventWriteHandler;

////    template<class T> class EventWriterImpl : public opendnp3::IEventWriter<T>
typedef struct
{
  IEventWriter_for_Analog iIEventWriter_for_Analog;
////    public:
  boolean success;//// = true;
  std::vector<uint16_t> written_indices;

////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            if (success)
////            {
////                written_indices.push_back(index);
////            }
////            return success;
////        }
} EventWriterImpl_for_Analog;
void EventWriterImpl_for_Analog_in_EventWriterImpl_for_Analog(EventWriterImpl_for_Analog *pEventWriterImpl_for_Analog);

boolean Write_in_EventWriterImpl_for_Analog(EventWriterImpl_for_Analog *pEventWriterImpl_for_Analog, Analog* meas, uint16_t index);
boolean Write_in_EventWriterImpl_for_Analog_override(void *pEventWriterImpl_for_Analog, Analog* meas, uint16_t index);

typedef struct
{
  IEventWriter_for_Binary iIEventWriter_for_Binary;
////    public:
  boolean success;//// = true;
  std::vector<uint16_t> written_indices;

////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            if (success)
////            {
////                written_indices.push_back(index);
////            }
////            return success;
////        }
} EventWriterImpl_for_Binary;
void EventWriterImpl_for_Binary_in_EventWriterImpl_for_Binary(EventWriterImpl_for_Binary *pEventWriterImpl_for_Binary);

boolean Write_in_EventWriterImpl_for_Binary(EventWriterImpl_for_Binary *pEventWriterImpl_for_Binary, Binary* meas, uint16_t index);
boolean Write_in_EventWriterImpl_for_Binary_override(void *pEventWriterImpl_for_Binary, Binary* meas, uint16_t index);

////class MockEventWriteHandler final : public opendnp3::IEventWriteHandler
typedef struct
{
  IEventWriteHandler iIEventWriteHandler;
  EventWriterImpl_for_Analog  eEventWriterImpl_for_Analog;
  EventWriterImpl_for_Binary  eEventWriterImpl_for_Binary;

////private:

////public:
////    void Expect(opendnp3::EventBinaryVariation variation, uint16_t count)
////    {
////        this->ExpectType<opendnp3::BinaryInfo>(variation, count);
////    }

////    void Expect(opendnp3::EventDoubleBinaryVariation variation, uint16_t count)
////    {
////        this->ExpectType<opendnp3::DoubleBitBinaryInfo>(variation, count);
////    }

////    void Expect(opendnp3::EventCounterVariation variation, uint16_t count)
////    {
////        this->ExpectType<opendnp3::CounterInfo>(variation, count);
////    }

////    void Expect(opendnp3::EventAnalogVariation variation, uint16_t count)
////    {
////        this->ExpectType<opendnp3::AnalogInfo>(variation, count);
////    }

////    void AssertEmpty()
////    {
////        if (!this->expected.empty())
////        {
////            throw std::logic_error("more events expected");
////        }
////    }

//  uint16_t (*pWrite_for_Binary_in_IEventWriteHandler)(void *, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);//// = 0;
////    virtual uint16_t Write(opendnp3::EventBinaryVariation variation,
////                           const opendnp3::Binary& first,
////                           opendnp3::IEventCollection<opendnp3::Binary>& items) override
////    {
////        return this->WriteAny<opendnp3::BinaryInfo>(variation, items);
////    }

////    virtual uint16_t Write(opendnp3::EventDoubleBinaryVariation variation,
////                           const opendnp3::DoubleBitBinary& first,
////                           opendnp3::IEventCollection<opendnp3::DoubleBitBinary>& items) override
////    {
////        return this->WriteAny<opendnp3::DoubleBitBinaryInfo>(variation, items);
////    }

////    virtual uint16_t Write(opendnp3::EventCounterVariation variation,
////                           const opendnp3::Counter& first,
////                           opendnp3::IEventCollection<opendnp3::Counter>& items) override
////    {
////        return this->WriteAny<opendnp3::CounterInfo>(variation, items);
////    }

////    virtual uint16_t Write(opendnp3::EventFrozenCounterVariation variation,
////                           const opendnp3::FrozenCounter& first,
////                           opendnp3::IEventCollection<opendnp3::FrozenCounter>& items) override
////    {
////        return this->WriteAny<opendnp3::FrozenCounterInfo>(variation, items);
////    }

//  uint16_t (*pWrite_for_Analog_in_IEventWriteHandler)(void *, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);//// = 0;
////    virtual uint16_t Write(opendnp3::EventAnalogVariation variation,
////                           const opendnp3::Analog& first,
////                           opendnp3::IEventCollection<opendnp3::Analog>& items) override
////    {
////        return this->WriteAny<opendnp3::AnalogInfo>(variation, items);
////    }

////    virtual uint16_t Write(opendnp3::EventBinaryOutputStatusVariation variation,
////                           const opendnp3::BinaryOutputStatus& first,
////                           opendnp3::IEventCollection<opendnp3::BinaryOutputStatus>& items) override
////    {
////        return this->WriteAny<opendnp3::BinaryOutputStatusInfo>(variation, items);
////    }

////    virtual uint16_t Write(opendnp3::EventAnalogOutputStatusVariation variation,
////                           const opendnp3::AnalogOutputStatus& first,
////                           opendnp3::IEventCollection<opendnp3::AnalogOutputStatus>& items) override
////    {
////        return this->WriteAny<opendnp3::AnalogOutputStatusInfo>(variation, items);
////    }

////    virtual uint16_t Write(opendnp3::EventOctetStringVariation variation,
////                           const opendnp3::OctetString& first,
////                           opendnp3::IEventCollection<opendnp3::OctetString>& items) override
////    {
////        return this->WriteAny<opendnp3::OctetStringInfo>(variation, items);
////    }

////private:
////    template<class T> void ExpectType(typename T::event_variation_t variation, uint16_t count)
////    {
////        expected.push_back(Record{T::EventTypeEnum, static_cast<uint8_t>(variation), count});
////    }
////
////    template<class T>
////    uint16_t WriteAny(typename T::event_variation_t variation, opendnp3::IEventCollection<typename T::meas_t>& items);
} MockEventWriteHandler;

void MockEventWriteHandler_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler);

////    virtual uint16_t Write(opendnp3::EventAnalogVariation variation,
////                           const opendnp3::Analog& first,
////                           opendnp3::IEventCollection<opendnp3::Analog>& items) override
uint16_t Write_for_Analog_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);
uint16_t Write_for_Analog_in_MockEventWriteHandler_override(void *pMockEventWriteHandler, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);

uint16_t Write_for_Binary_in_MockEventWriteHandler(MockEventWriteHandler *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);
uint16_t Write_for_Binary_in_MockEventWriteHandler_override(void *pMockEventWriteHandler, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);

////template<class T>
////uint16_t MockEventWriteHandler::WriteAny(typename T::event_variation_t variation,
////                                         opendnp3::IEventCollection<typename T::meas_t>& items)
////{
////    if (this->expected.empty())
////    {
////        throw std::logic_error("no more write events expected");
////    }

////    const auto record = this->expected.front();
////    this->expected.pop_front();
////
////    if (record.type != T::EventTypeEnum)
////    {
////        std::ostringstream oss;
////        oss << "Unexpected event type: " << static_cast<int>(record.type);
////        throw std::logic_error(oss.str());
////    }

////    if (record.variation != static_cast<uint8_t>(variation))
////    {
////        std::ostringstream oss;
////        oss << "Unexpected variation: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
////    }
////
////    EventWriterImpl<typename T::meas_t> writer;
////    const uint16_t count = items.WriteSome(writer);
////
////    if (record.count != count)
////    {
////        std::ostringstream oss;
////        oss << "Unexpected count: " << static_cast<int>(variation);
////        throw std::logic_error(oss.str());
////    }

////    return count;
////}

#endif
