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
#ifndef OPENDNP3_UNITTESTS_MOCK_APDU_HEADER_HANDLER_H
#define OPENDNP3_UNITTESTS_MOCK_APDU_HEADER_HANDLER_H

////#include <app/parsing/IAPDUHandler.h>
#include "IAPDUHandler.h"

#include <vector>

////class MockApduHeaderHandler : public opendnp3::IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;

////public:
////    bool IsAllowed(uint32_t headerCount, opendnp3::GroupVariation gv, opendnp3::QualifierCode qc) final
////    {
////        return true;
////    }

////    void OnHeaderResult(const opendnp3::HeaderRecord& record, const opendnp3::IINField& result) final
////    {
////        records.push_back(record);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::IINValue>>& values) final
////    {
////        return ProcessAny(header, values, iinBits);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>& values) final
////    {
////        return ProcessAny(header, values, staticBinaries);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::RangeHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>& values) final
////    {
////        return ProcessAny(header, values, staticDoubleBinaries);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::RangeHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>& values) final
////    {
////        return ProcessAny(header, values, staticControlStatii);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Counter>>& values) final
////    {
////        return ProcessAny(header, values, staticCounters);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::RangeHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>& values) final
////    {
////        return ProcessAny(header, values, staticFrozenCounters);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Analog>>& values) final
////    {
////        return ProcessAny(header, values, eventAnalogs);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::RangeHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputStatus>>& values) final
////    {
////        return ProcessAny(header, values, staticSetpointStatii);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::RangeHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>& values) final
////    {
////        return ProcessAny(header, values, rangedOctets);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>& values) final
////    {
////        return this->ProcessAny(header, values, eventBinaries);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>& values) final
////    {
////        return this->ProcessAny(header, values, eventDoubleBinaries);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Counter>>& values) final
////    {
////        return this->ProcessAny(header, values, eventCounters);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>& values) final
////    {
////        return this->ProcessAny(header, values, eventFrozenCounters);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Analog>>& values) final
////    {
////        return this->ProcessAny(header, values, eventAnalogs);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>& values) final
////    {
////        return this->ProcessAny(header, values, indexPrefixedOctets);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>& values) final
////    {
////        return this->ProcessAny(header, values, binaryCommandEvents);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>& values) final
////    {
////        return this->ProcessAny(header, values, analogCommandEvents);
////    }

////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<uint16_t>& values) final
////    {
////        return this->ProcessAny(header, values, indices);
////    }

  /// --- controls ----

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::ControlRelayOutputBlock>>& meas) final
////    {
////        return this->ProcessAny(header, meas, crobRequests);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputInt16>>& meas) final
////    {
////        return this->ProcessAny(header, meas, aoInt16Requests);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputInt32>>& meas) final
////    {
////        return this->ProcessAny(header, meas, aoInt32Requests);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputFloat32>>& meas) final
////    {
////        return this->ProcessAny(header, meas, aoFloat32Requests);
////    }

////    opendnp3::IINField ProcessHeader(
////        const opendnp3::PrefixHeader& header,
////        const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputDouble64>>& meas) final
////    {
////        return this->ProcessAny(header, meas, aoDouble64Requests);
////    }

  std::vector<HeaderRecord> records;

  std::vector<Indexed_for_IINValue> iinBits;

  std::vector<Indexed_for_Binary> eventBinaries;
  std::vector<Indexed_for_Binary> staticBinaries;

  std::vector<Indexed_for_DoubleBitBinary> eventDoubleBinaries;
  std::vector<Indexed_for_DoubleBitBinary> staticDoubleBinaries;

  std::vector<Indexed_for_BinaryOutputStatus> staticControlStatii;

  std::vector<Indexed_for_Counter> eventCounters;
  std::vector<Indexed_for_Counter> staticCounters;

  std::vector<Indexed_for_FrozenCounter> eventFrozenCounters;
  std::vector<Indexed_for_FrozenCounter> staticFrozenCounters;

  std::vector<Indexed_for_Analog> eventAnalogs;
  std::vector<Indexed_for_Analog> staticAnalogs;

  std::vector<Indexed_for_AnalogOutputStatus> staticSetpointStatii;

  std::vector<Indexed_for_ControlRelayOutputBlock> crobRequests;

  std::vector<Indexed_for_AnalogOutputInt16> aoInt16Requests;
  std::vector<Indexed_for_AnalogOutputInt32> aoInt32Requests;
  std::vector<Indexed_for_AnalogOutputFloat32> aoFloat32Requests;
  std::vector<Indexed_for_AnalogOutputDouble64> aoDouble64Requests;

  std::vector<Indexed_for_OctetString> indexPrefixedOctets;
  std::vector<Indexed_for_OctetString> rangedOctets;

  std::vector<Indexed_for_BinaryCommandEvent> binaryCommandEvents;

  std::vector<Indexed_for_AnalogCommandEvent> analogCommandEvents;

  std::vector<uint16_t> indices;

////private:
////    template<class T>
////    opendnp3::IINField ProcessAny(const opendnp3::HeaderRecord& record,
////                                  const opendnp3::ICollection<T>& meas,
////                                  std::vector<T>& items)
////    {
////        auto add = [&items](const T& v) { items.push_back(v); };
////        meas.ForeachItem(add);
////        return opendnp3::IINField::Empty();
////    }
} MockApduHeaderHandler;

void MockApduHeaderHandler_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler);
////    opendnp3::IINField ProcessAny(const opendnp3::HeaderRecord& record,
////                                  const opendnp3::ICollection<T>& meas,
////                                  std::vector<T>& items)

IINField ProcessAny_for_uint16_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_for_uint16* meas,
    std::vector<uint16_t>* items);
IINField ProcessAny_Indexed_for_IINValue_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_IINValue* meas,
    std::vector<Indexed_for_IINValue>* items);
IINField ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_Binary* meas,
    std::vector<Indexed_for_Binary>* items);
IINField ProcessAny_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_BinaryOutputStatus* meas,
    std::vector<Indexed_for_BinaryOutputStatus>* items);
IINField ProcessAny_Indexed_for_OctetString_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_OctetString* meas,
    std::vector<Indexed_for_OctetString>* items);

boolean IsAllowed_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
boolean IsAllowed_in_MockApduHeaderHandler_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

void OnHeaderResult_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, HeaderRecord* record, IINField* result);
void OnHeaderResult_in_MockApduHeaderHandler_override(void *pIAPDUHandler, HeaderRecord* record, IINField* result);

IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_Binary* values);

IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_BinaryOutputStatus* values);
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_BinaryOutputStatus* values);

IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_IINValue* values);
IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_IINValue* values);

IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_OctetString* values);
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_OctetString* values);

#endif
