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
#ifndef OPENDNP3_MEASUREMENTHANDLER_H
#define OPENDNP3_MEASUREMENTHANDLER_H

#include "APDUHeader.h"
#include "Collections.h"
#include "IAPDUHandler.h"
#include "ParseResult.h"
////#include "logging/LogMacros.h"

#include "Attributes.h"
////#include "opendnp3/logging/LogLevels.h"
////#include "opendnp3/logging/Logger.h"
#include "ISOEHandler.h"

////namespace opendnp3
////{

/**
 * Dedicated class for processing response data in the master.
* Выделенный класс для обработки данных ответа в мастере.
 */
////class MeasurementHandler final : public IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;
////public:
  /**
   * Static helper function for interpreting a response as a measurement response
   */
////    static ParseResult ProcessMeasurements(ResponseInfo info,
////                                           const ser4cpp::rseq_t& objects,
////                                           Logger& logger,
////                                           ISOEHandler* pHandler);

  // TODO
////    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override
////    {
////        return true;
////    };

  /**
   * Creates a new ResponseLoader instance.
   *
   * @param logger	the Logger that the loader should use for message reporting
   */
////    MeasurementHandler(ResponseInfo info, const Logger& logger, ISOEHandler* pSOEHandler);

////    ~MeasurementHandler();

////private:
  ResponseInfo info;
////    Logger logger;

////    static TimestampQuality ModeFromType(GroupVariation gv);

////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group50Var1>& values) override;

  // Handle the CTO objects
////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group51Var1>& values) override;
////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group51Var2>& values) override;

////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Binary>>& values) override;

////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Counter>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<FrozenCounter>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Analog>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<OctetString>>& values) override;
////    IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<TimeAndInterval>>& values) override;

////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Binary>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Counter>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<FrozenCounter>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Analog>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<OctetString>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryCommandEvent>>& values) override;
////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogCommandEvent>>& values) override;

////    template<class Target, class Source>
////    IINField LoadValuesWithTransformTo(const HeaderRecord& record, const ICollection<Indexed<Source>>& values)
////    {
////        auto transform = [](const Indexed<Source>& input) -> Indexed<Target> { return Convert<Source, Target>(input); };

////        auto collection = Map<Indexed<Source>, Indexed<Target>>(values, transform);

////        return this->LoadValues(record, ModeFromType(record.enumeration), collection);
////    }

////    template<class T>
////    IINField LoadValues(const HeaderRecord& record, TimestampQuality tsquality, const ICollection<Indexed<T>>& values)
////    {
////        this->CheckForTxStart();
////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
////        this->pSOEHandler->Process(info, values);
////        return IINField();
////    }

////    template<class T> IINField ProcessWithCTO(const HeaderRecord& record, const ICollection<Indexed<T>>& values);

  boolean txInitiated;
  ISOEHandler* pSOEHandler;

  DNPTime commonTimeOccurence;

////    void CheckForTxStart();

////    template<class T, class U> static Indexed<U> Convert(const Indexed<T>& input)
////    {
////        return WithIndex(Convert(input.value), input.index);
////    }
} MeasurementHandler;

void MeasurementHandler_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, ResponseInfo info, ISOEHandler* pSOEHandler);

void CheckForTxStart_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler);

ParseResult_uint8_t ProcessMeasurements_in_MeasurementHandler_static(ResponseInfo info,
    RSeq_for_Uint16_t* objects,
////                                           Logger& logger,
    ISOEHandler* pHandler);
TimestampQuality_uint8_t ModeFromType_in_MeasurementHandler_static(GroupVariation_uint16_t gv);

boolean IsAllowed_in_MeasurementHandler_override(void *v, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

IINField ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler_override(void*, CountHeader* header, ICollection_for_Group50Var1* values);
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler_override(void*, CountHeader* header, ICollection_for_Group51Var1* values);
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler_override(void*, CountHeader* header, ICollection_for_Group51Var2* values);

IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary * values);
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values);
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_Counter * values);
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_FrozenCounter * values);
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_Analog * values);
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values);
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_OctetString * values);
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval * values);

IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_Binary * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_Counter * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_Analog * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_OctetString * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MeasurementHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent * values);

IINField ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group50Var1* values);
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group51Var1* values);
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group51Var2* values);

IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary * values);
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values);
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Counter * values);
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter * values);
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Analog * values);
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values);
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_OctetString * values);
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval * values);

IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Binary * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Counter * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Analog * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent * values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent * values);

IINField LoadValues_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Binary* values);
IINField LoadValues_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_DoubleBitBinary* values);
IINField LoadValues_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_BinaryOutputStatus* values);
IINField LoadValues_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Counter* values);
IINField LoadValues_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_FrozenCounter* values);
IINField LoadValues_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_OctetString* values);
IINField LoadValues_for_BinaryCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_BinaryCommandEvent* values);
IINField LoadValues_for_AnalogCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_AnalogCommandEvent* values);
IINField LoadValues_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Analog* values);
IINField LoadValues_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_AnalogOutputStatus* values);
IINField LoadValues_for_TimeAndInterval_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_TimeAndInterval* values);

IINField ProcessWithCTO_for_Binary_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, HeaderRecord* record, ICollection_Indexed_for_Binary* values);
IINField ProcessWithCTO_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, HeaderRecord* record, ICollection_Indexed_for_DoubleBitBinary* values);



////} // namespace opendnp3

#endif
