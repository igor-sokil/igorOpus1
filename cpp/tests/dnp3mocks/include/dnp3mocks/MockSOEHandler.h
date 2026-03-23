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
#ifndef OPENDNP3_UNITTESTS_MOCKSOEHANDLER_H
#define OPENDNP3_UNITTESTS_MOCKSOEHANDLER_H

#include "ISOEHandler.h"

#include <map>
#include <vector>

//---------------------------------Binary-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  Binary meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_Binary_in_MockSOEHandler;

void Record_for_Binary_in_MockSOEHandler_in_Record_for_Binary_in_MockSOEHandlerOver1(Record_for_Binary_in_MockSOEHandler *pRecord_for_Binary_in_MockSOEHandler);
void Record_for_Binary_in_MockSOEHandler_in_Record_for_Binary_in_MockSOEHandlerOver2(Record_for_Binary_in_MockSOEHandler *pRecord_for_Binary_in_MockSOEHandler,
    Binary* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------Binary-----------------------------------------------
//---------------------------------DoubleBitBinary-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  DoubleBitBinary meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_DoubleBitBinary_in_MockSOEHandler;

void Record_for_DoubleBitBinary_in_MockSOEHandler_in_Record_for_DoubleBitBinary_in_MockSOEHandlerOver1(Record_for_DoubleBitBinary_in_MockSOEHandler *pRecord_for_DoubleBitBinary_in_MockSOEHandler);
void Record_for_DoubleBitBinary_in_MockSOEHandler_in_Record_for_DoubleBitBinary_in_MockSOEHandlerOver2(Record_for_DoubleBitBinary_in_MockSOEHandler *pRecord_for_DoubleBitBinary_in_MockSOEHandler,
    DoubleBitBinary* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------DoubleBitBinary-----------------------------------------------
//---------------------------------Analog-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  Analog meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_Analog_in_MockSOEHandler;

void Record_for_Analog_in_MockSOEHandler_in_Record_for_Analog_in_MockSOEHandlerOver1(Record_for_Analog_in_MockSOEHandler *pRecord_for_Analog_in_MockSOEHandler);
void Record_for_Analog_in_MockSOEHandler_in_Record_for_Analog_in_MockSOEHandlerOver2(Record_for_Analog_in_MockSOEHandler *pRecord_for_Analog_in_MockSOEHandler,
    Analog* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------Analog-----------------------------------------------
//---------------------------------Counter-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  Counter meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_Counter_in_MockSOEHandler;

void Record_for_Counter_in_MockSOEHandler_in_Record_for_Counter_in_MockSOEHandlerOver1(Record_for_Counter_in_MockSOEHandler *pRecord_for_Counter_in_MockSOEHandler);
void Record_for_Counter_in_MockSOEHandler_in_Record_for_Counter_in_MockSOEHandlerOver2(Record_for_Counter_in_MockSOEHandler *pRecord_for_Counter_in_MockSOEHandler,
    Counter* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------Counter-----------------------------------------------
//---------------------------------FrozenCounter-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  FrozenCounter meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_FrozenCounter_in_MockSOEHandler;

void Record_for_FrozenCounter_in_MockSOEHandler_in_Record_for_FrozenCounter_in_MockSOEHandlerOver1(Record_for_FrozenCounter_in_MockSOEHandler *pRecord_for_FrozenCounter_in_MockSOEHandler);
void Record_for_FrozenCounter_in_MockSOEHandler_in_Record_for_FrozenCounter_in_MockSOEHandlerOver2(Record_for_FrozenCounter_in_MockSOEHandler *pRecord_for_FrozenCounter_in_MockSOEHandler,
    FrozenCounter* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------FrozenCounter-----------------------------------------------
//---------------------------------BinaryOutputStatus-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  BinaryOutputStatus meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_BinaryOutputStatus_in_MockSOEHandler;

void Record_for_BinaryOutputStatus_in_MockSOEHandler_in_Record_for_BinaryOutputStatus_in_MockSOEHandlerOver1(Record_for_BinaryOutputStatus_in_MockSOEHandler *pRecord_for_BinaryOutputStatus_in_MockSOEHandler);
void Record_for_BinaryOutputStatus_in_MockSOEHandler_in_Record_for_BinaryOutputStatus_in_MockSOEHandlerOver2(Record_for_BinaryOutputStatus_in_MockSOEHandler *pRecord_for_BinaryOutputStatus_in_MockSOEHandler,
    BinaryOutputStatus* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------BinaryOutputStatus-----------------------------------------------
//---------------------------------AnalogOutputStatus-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  AnalogOutputStatus meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_AnalogOutputStatus_in_MockSOEHandler;

void Record_for_AnalogOutputStatus_in_MockSOEHandler_in_Record_for_AnalogOutputStatus_in_MockSOEHandlerOver1(Record_for_AnalogOutputStatus_in_MockSOEHandler *pRecord_for_AnalogOutputStatus_in_MockSOEHandler);
void Record_for_AnalogOutputStatus_in_MockSOEHandler_in_Record_for_AnalogOutputStatus_in_MockSOEHandlerOver2(Record_for_AnalogOutputStatus_in_MockSOEHandler *pRecord_for_AnalogOutputStatus_in_MockSOEHandler,
    AnalogOutputStatus* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------AnalogOutputStatus-----------------------------------------------
//---------------------------------OctetString-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  OctetString meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_OctetString_in_MockSOEHandler;

void Record_for_OctetString_in_MockSOEHandler_in_Record_for_OctetString_in_MockSOEHandlerOver1(Record_for_OctetString_in_MockSOEHandler *pRecord_for_OctetString_in_MockSOEHandler);
void Record_for_OctetString_in_MockSOEHandler_in_Record_for_OctetString_in_MockSOEHandlerOver2(Record_for_OctetString_in_MockSOEHandler *pRecord_for_OctetString_in_MockSOEHandler,
    OctetString* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------OctetString-----------------------------------------------
//---------------------------------TimeAndInterval-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  TimeAndInterval meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_TimeAndInterval_in_MockSOEHandler;

void Record_for_TimeAndInterval_in_MockSOEHandler_in_Record_for_TimeAndInterval_in_MockSOEHandlerOver1(Record_for_TimeAndInterval_in_MockSOEHandler *pRecord_for_TimeAndInterval_in_MockSOEHandler);
void Record_for_TimeAndInterval_in_MockSOEHandler_in_Record_for_TimeAndInterval_in_MockSOEHandlerOver2(Record_for_TimeAndInterval_in_MockSOEHandler *pRecord_for_TimeAndInterval_in_MockSOEHandler,
    TimeAndInterval* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------TimeAndInterval-----------------------------------------------
//---------------------------------BinaryCommandEvent-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  BinaryCommandEvent meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_BinaryCommandEvent_in_MockSOEHandler;

void Record_for_BinaryCommandEvent_in_MockSOEHandler_in_Record_for_BinaryCommandEvent_in_MockSOEHandlerOver1(Record_for_BinaryCommandEvent_in_MockSOEHandler *pRecord_for_BinaryCommandEvent_in_MockSOEHandler);
void Record_for_BinaryCommandEvent_in_MockSOEHandler_in_Record_for_BinaryCommandEvent_in_MockSOEHandlerOver2(Record_for_BinaryCommandEvent_in_MockSOEHandler *pRecord_for_BinaryCommandEvent_in_MockSOEHandler,
    BinaryCommandEvent* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------BinaryCommandEvent-----------------------------------------------
//---------------------------------AnalogCommandEvent-----------------------------------------------
typedef struct
{
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

  AnalogCommandEvent meas;
  HeaderInfo info;
  uint32_t sequence;
} Record_for_AnalogCommandEvent_in_MockSOEHandler;

void Record_for_AnalogCommandEvent_in_MockSOEHandler_in_Record_for_AnalogCommandEvent_in_MockSOEHandlerOver1(Record_for_AnalogCommandEvent_in_MockSOEHandler *pRecord_for_AnalogCommandEvent_in_MockSOEHandler);
void Record_for_AnalogCommandEvent_in_MockSOEHandler_in_Record_for_AnalogCommandEvent_in_MockSOEHandlerOver2(Record_for_AnalogCommandEvent_in_MockSOEHandler *pRecord_for_AnalogCommandEvent_in_MockSOEHandler,
    AnalogCommandEvent* meas_, HeaderInfo* info_, uint32_t sequence_);

//---------------------------------AnalogCommandEvent-----------------------------------------------

// simple measurement handler for testing purposes
////class MockSOEHandler : public opendnp3::ISOEHandler
typedef struct
{

  ISOEHandler iISOEHandler;

////public:
////    template<class T> class Record
////    {
////    public:
////        Record() : sequence(0) {}

////        Record(const T& meas_, const opendnp3::HeaderInfo& info_, uint32_t sequence_)
////            : meas(meas_), info(info_), sequence(sequence_)
////        {
////        }

////        T meas;
////        opendnp3::HeaderInfo info;
////        uint32_t sequence;
////    };

////    MockSOEHandler() : soeCount(0) {}

////    void BeginFragment(const opendnp3::ResponseInfo& info) override {}

////    void EndFragment(const opendnp3::ResponseInfo& info) override {}

////    uint32_t TotalReceived() const
////    {
////        return soeCount;
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>& values) final
////    {
////        this->RecordAny(info, values, this->binarySOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>& values) final
////    {
////        this->RecordAny(info, values, this->doubleBinarySOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Analog>>& values) final
////    {
////        this->RecordAny(info, values, this->analogSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Counter>>& values) final
////    {
////        this->RecordAny(info, values, this->counterSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>& values) final
////    {
////        this->RecordAny(info, values, this->frozenCounterSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>& values) final
////    {
////        this->RecordAny(info, values, this->binaryOutputStatusSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputStatus>>& values) final
////    {
////        this->RecordAny(info, values, this->analogOutputStatusSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>& values) final
////    {
////        this->RecordAny(info, values, this->octetStringSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::TimeAndInterval>>& values) final
////    {
////        this->RecordAny(info, values, this->timeAndIntervalSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>& values) final
////    {
////        this->RecordAny(info, values, this->binaryCommandEventSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info,
////                 const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>& values) final
////    {
////        this->RecordAny(info, values, this->analogCommandEventSOE);
////    }

////    void Process(const opendnp3::HeaderInfo& info, const opendnp3::ICollection<opendnp3::DNPTime>& values) final
////    {
////        values.ForeachItem([this](const opendnp3::DNPTime& value) {
////            ++this->soeCount;
////            this->timeSOE.push_back(value);
////        });
////    }

////    void Clear()
////    {
////        soeCount = 0;
////
////        binarySOE.clear();
////        doubleBinarySOE.clear();
////        analogSOE.clear();
////        counterSOE.clear();
////        frozenCounterSOE.clear();
////        binaryOutputStatusSOE.clear();
////        analogOutputStatusSOE.clear();
////        octetStringSOE.clear();
////        timeAndIntervalSOE.clear();
////        binaryCommandEventSOE.clear();
////        analogCommandEventSOE.clear();
////        timeSOE.clear();
////    }

  std::map<uint16_t, Record_for_Binary_in_MockSOEHandler> binarySOE;
  std::map<uint16_t, Record_for_DoubleBitBinary_in_MockSOEHandler> doubleBinarySOE;
  std::map<uint16_t, Record_for_Analog_in_MockSOEHandler> analogSOE;
  std::map<uint16_t, Record_for_Counter_in_MockSOEHandler> counterSOE;
  std::map<uint16_t, Record_for_FrozenCounter_in_MockSOEHandler> frozenCounterSOE;
  std::map<uint16_t, Record_for_BinaryOutputStatus_in_MockSOEHandler> binaryOutputStatusSOE;
  std::map<uint16_t, Record_for_AnalogOutputStatus_in_MockSOEHandler> analogOutputStatusSOE;
  std::map<uint16_t, Record_for_OctetString_in_MockSOEHandler> octetStringSOE;
  std::map<uint16_t, Record_for_TimeAndInterval_in_MockSOEHandler> timeAndIntervalSOE;
  std::map<uint16_t, Record_for_BinaryCommandEvent_in_MockSOEHandler> binaryCommandEventSOE;
  std::map<uint16_t, Record_for_AnalogCommandEvent_in_MockSOEHandler> analogCommandEventSOE;
  std::vector<DNPTime> timeSOE;

////private:
  uint32_t soeCount;

////    template<class T>
////    void RecordAny(const opendnp3::HeaderInfo& info,
////                   const opendnp3::ICollection<opendnp3::Indexed<T>>& values,
////                   std::map<uint16_t, Record<T>>& records)
////    {
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

////        values.ForeachItem(process);
////    }
} MockSOEHandler;

void MockSOEHandler_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler);

void BeginFragment_in_MockSOEHandler_override(void *pISOEHandler, ResponseInfo* info);
void BeginFragment_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, ResponseInfo* info);

void EndFragment_in_MockSOEHandler_override(void *pISOEHandler, ResponseInfo* info);
void EndFragment_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, ResponseInfo* info);

uint32_t TotalReceived_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler);

void Process_Indexed_for_Binary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values);
void Process_Indexed_for_Binary_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values);

void Process_Indexed_for_DoubleBitBinary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values);
void Process_Indexed_for_DoubleBitBinary_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values);

void Process_Indexed_for_Analog_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values);
void Process_Indexed_for_Analog_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values);

void Process_Indexed_for_Counter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values);
void Process_Indexed_for_Counter_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values);

void Process_Indexed_for_FrozenCounter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values);
void Process_Indexed_for_FrozenCounter_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values);

void Process_Indexed_for_BinaryOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values);
void Process_Indexed_for_BinaryOutputStatus_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values);

void Process_Indexed_for_AnalogOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values);
void Process_Indexed_for_AnalogOutputStatus_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values);

void Process_Indexed_for_OctetString_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values);
void Process_Indexed_for_OctetString_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values);

void Process_Indexed_for_TimeAndInterval_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values);
void Process_Indexed_for_TimeAndInterval_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values);

void Process_Indexed_for_BinaryCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values);
void Process_Indexed_for_BinaryCommandEvent_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values);

void Process_Indexed_for_AnalogCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values);
void Process_Indexed_for_AnalogCommandEvent_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values);

void Process_for_DNPTime_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values);
void Process_for_DNPTime_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values);

////    template<class T>
void RecordAny_for_Binary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_Binary* values,
    std::map<uint16_t, Record_for_Binary_in_MockSOEHandler>& records);

void RecordAny_for_DoubleBitBinary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_DoubleBitBinary* values,
    std::map<uint16_t, Record_for_DoubleBitBinary_in_MockSOEHandler>& records);

void RecordAny_for_Analog_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_Analog* values,
    std::map<uint16_t, Record_for_Analog_in_MockSOEHandler>& records);

void RecordAny_for_Counter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_Counter* values,
    std::map<uint16_t, Record_for_Counter_in_MockSOEHandler>& records);

void RecordAny_for_FrozenCounter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_FrozenCounter* values,
    std::map<uint16_t, Record_for_FrozenCounter_in_MockSOEHandler>& records);

void RecordAny_for_BinaryOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_BinaryOutputStatus* values,
    std::map<uint16_t, Record_for_BinaryOutputStatus_in_MockSOEHandler>& records);

void RecordAny_for_AnalogOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_AnalogOutputStatus* values,
    std::map<uint16_t, Record_for_AnalogOutputStatus_in_MockSOEHandler>& records);

void RecordAny_for_OctetString_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_OctetString* values,
    std::map<uint16_t, Record_for_OctetString_in_MockSOEHandler>& records);

void RecordAny_for_TimeAndInterval_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_TimeAndInterval* values,
    std::map<uint16_t, Record_for_TimeAndInterval_in_MockSOEHandler>& records);

void RecordAny_for_BinaryCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_BinaryCommandEvent* values,
    std::map<uint16_t, Record_for_BinaryCommandEvent_in_MockSOEHandler>& records);

void RecordAny_for_AnalogCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_AnalogCommandEvent* values,
    std::map<uint16_t, Record_for_AnalogCommandEvent_in_MockSOEHandler>& records);

#endif
