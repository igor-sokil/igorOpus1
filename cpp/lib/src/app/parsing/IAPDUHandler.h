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
#ifndef OPENDNP3_IAPDUHANDLER_H
#define OPENDNP3_IAPDUHANDLER_H

////#include "app/GroupVariationRecord.h"
////#include "app/IINValue.h"
////#include "app/Range.h"
////#include "app/parsing/IWhiteList.h"
////#include "gen/objects/Group50.h"
////#include "gen/objects/Group51.h"
////#include "gen/objects/Group52.h"
////
////#include "opendnp3/app/AnalogCommandEvent.h"
////#include "opendnp3/app/AnalogOutput.h"
////#include "opendnp3/app/BinaryCommandEvent.h"
////#include "opendnp3/app/ControlRelayOutputBlock.h"
////#include "opendnp3/app/IINField.h"
////#include "opendnp3/app/Indexed.h"
////#include "opendnp3/app/MeasurementTypes.h"
////#include "opendnp3/app/OctetString.h"
////#include "opendnp3/app/parsing/ICollection.h"
////#include "opendnp3/gen/QualifierCode.h"

#include "GroupVariationRecord.h"
#include "IINValue.h"
#include "Range.h"
#include "IWhiteList.h"
#include "Group50.h"
#include "Group51.h"
#include "Group52.h"

#include "AnalogCommandEvent.h"
#include "AnalogOutput.h"
#include "BinaryCommandEvent.h"
#include "ControlRelayOutputBlock.h"
#include "IINField.h"
#include "Indexed.h"
#include "MeasurementTypes.h"
#include "OctetString.h"
#include "ICollection.h"
#include "QualifierCode.h"

////namespace opendnp3
////{

/**
 * Base class used to handle APDU object headers
 */
////class IAPDUHandler : public IWhiteList
typedef struct
{
  IWhiteList iIWhiteList;
////public:
////    IAPDUHandler();

  // read any accumulated errors
////    IINField Errors() const;
////
////    void OnHeader(const AllObjectsHeader& header);
////    void OnHeader(const RangeHeader& header);
////    void OnHeader(const CountHeader& header);
////
////    void OnHeader(const CountHeader& header, const ICollection<Group50Var1>& values);
////    void OnHeader(const CountHeader& header, const ICollection<Group50Var3>& values);
////    void OnHeader(const CountHeader& header, const ICollection<Group51Var1>& values);
////    void OnHeader(const CountHeader& header, const ICollection<Group51Var2>& values);
////    void OnHeader(const CountHeader& header, const ICollection<Group52Var1>& values);
////    void OnHeader(const CountHeader& header, const ICollection<Group52Var2>& values);

////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<IINValue>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<Binary>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<Counter>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<FrozenCounter>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<Analog>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<OctetString>>& values);
////    void OnHeader(const RangeHeader& header, const ICollection<Indexed<TimeAndInterval>>& values);
////
////    // events

////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<Binary>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<Counter>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<FrozenCounter>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<Analog>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<OctetString>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<TimeAndInterval>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryCommandEvent>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogCommandEvent>>& values);
////
  // adhoc read by index
////    void OnHeader(const PrefixHeader& header, const ICollection<uint16_t>& values);
////
////    // commands
////
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<ControlRelayOutputBlock>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt16>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt32>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputFloat32>>& values);
////    void OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputDouble64>>& values);
////
////protected:
////    void Reset();

////    uint32_t NumIgnoredHeaders() const
////    {
////        return numIgnoredHeaders;
////    }

////    inline uint32_t GetCurrentHeader()
////    {
////        return numTotalHeaders;
////    }

////    inline bool IsFirstHeader()
////    {
////        return numTotalHeaders == 0;
////    }

  IINField (*pProcessHeader_AllObjectsHeader_in_IAPDUHandler)(void*, AllObjectsHeader* record);
  IINField (*pProcessHeader_RangeHeader_in_IAPDUHandler)(void*, RangeHeader* header);
  IINField (*pProcessHeader_CountHeader_in_IAPDUHandler)(void*, CountHeader* header);

  IINField (*pProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler)(void*, CountHeader* header, ICollection_for_Group50Var1* values);
  IINField (*pProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler)(void*, CountHeader* header, ICollection_for_Group50Var3* values);
  IINField (*pProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler)(void*, CountHeader* header, ICollection_for_Group51Var1* values);
  IINField (*pProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler)(void*, CountHeader* header, ICollection_for_Group51Var2* values);
  IINField (*pProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler)(void*, CountHeader* header, ICollection_for_Group52Var1* values);
  IINField (*pProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler)(void*, CountHeader* header, ICollection_for_Group52Var2* values);

  IINField (*pProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_IINValue* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_Binary* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_Counter* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_Analog* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_OctetString* values);
  IINField (*pProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values);

  IINField (*pProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_Binary* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_Counter* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_Analog* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_OctetString* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values);

  // adhoc read by index
  IINField (*pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_for_uint16* values);

  IINField (*pProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler)(void*, PrefixHeader* header,
      ICollection_Indexed_for_ControlRelayOutputBlock* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values);
  IINField (*pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputDouble64* values);

////protected:
  // overridable to receive post processing events for every header
  void (*pOnHeaderResult_in_IAPDUHandler)(void*, HeaderRecord* record, IINField* result);// {}

////private:
////    inline void Record(const HeaderRecord& record, const IINField& result)
////    {
////        errors |= result;
////        ++numTotalHeaders;
////        this->OnHeaderResult(record, result);
////    }
////
////    inline IINField ProcessUnsupportedHeader()
////    {
////        ++numIgnoredHeaders;
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
////    }

  IINField errors;
  uint32_t numTotalHeaders;
  uint32_t numIgnoredHeaders;

  void* pParentPointer_in_IAPDUHandler;
} IAPDUHandler;

void* getParentPointer_in_IAPDUHandler(IAPDUHandler*);
void  setParentPointer_in_IAPDUHandler(IAPDUHandler*, void*);

void IAPDUHandler_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);

IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler*, AllObjectsHeader* record);
IINField ProcessHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header);
IINField ProcessHeader_CountHeader_in_IAPDUHandler(IAPDUHandler*, CountHeader* header);
// overridable to receive post processing events for every header
void OnHeaderResult_in_IAPDUHandler(IAPDUHandler*, HeaderRecord* record, IINField* result);// {}

IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler_override(void*, AllObjectsHeader* record);
IINField ProcessHeader_RangeHeader_in_IAPDUHandler_override(void*, RangeHeader* header);
IINField ProcessHeader_CountHeader_in_IAPDUHandler_override(void*, CountHeader* header);
void OnHeaderResult_in_IAPDUHandler_override(void*, HeaderRecord* record, IINField* result);// {}

IINField ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group50Var1* values);
IINField ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler_override(void*, CountHeader* header, ICollection_for_Group50Var1* values);
IINField ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group50Var3* values);
IINField ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler_override(void*, CountHeader* header, ICollection_for_Group50Var3* values);
IINField ProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group51Var1* values);
IINField ProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler_override(void*, CountHeader* header, ICollection_for_Group51Var1* values);
IINField ProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group51Var2* values);
IINField ProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler_override(void*, CountHeader* header, ICollection_for_Group51Var2* values);
IINField ProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group52Var1* values);
IINField ProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler_override(void*, CountHeader* header, ICollection_for_Group52Var1* values);
IINField ProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group52Var2* values);
IINField ProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler_override(void*, CountHeader* header, ICollection_for_Group52Var2* values);

IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_IINValue* values);
IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_IINValue* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_Counter* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_Counter* values);
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values);
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_Analog* values);
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_Analog* values);
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_OctetString* values);
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_OctetString* values);
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values);
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler_override(void*, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values);

//    IINField ProcessHeader_PrefixHeader_for_Binary_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_Binary* values);
//    IINField ProcessHeader_PrefixHeader_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
//    IINField ProcessHeader_PrefixHeader_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
//    IINField ProcessHeader_PrefixHeader_for_Counter_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_Counter* values);
//    IINField ProcessHeader_PrefixHeader_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values);
//    IINField ProcessHeader_PrefixHeader_for_Analog_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_Analog* values);
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
//    IINField ProcessHeader_PrefixHeader_for_OctetString_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_OctetString* values);
//    IINField ProcessHeader_PrefixHeader_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values);
//    IINField ProcessHeader_PrefixHeader_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values);
//    IINField ProcessHeader_PrefixHeader_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values);

// adhoc read by index
IINField ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_for_uint16* values);

IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_ControlRelayOutputBlock* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputDouble64* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_Analog* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputStatus* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_BinaryOutputStatus* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_Counter* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_FrozenCounter* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogCommandEvent* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_BinaryCommandEvent* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_DoubleBitBinary* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_OctetString* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler*, PrefixHeader* header,
    ICollection_Indexed_for_TimeAndInterval* values);

IINField ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler_override(void*, PrefixHeader* header, ICollection_for_uint16* values);

IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_ControlRelayOutputBlock* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler_override(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputDouble64* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputStatus* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_Analog* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_Binary* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_BinaryOutputStatus* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_Counter* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_FrozenCounter* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogCommandEvent* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_BinaryCommandEvent* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_DoubleBitBinary* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_OctetString* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler_override(void*, PrefixHeader* header,
    ICollection_Indexed_for_TimeAndInterval* values);

// read any accumulated errors
IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);

void OnHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, AllObjectsHeader* header);
void OnHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header);
void OnHeader_CountHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header);

void OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values);
void OnHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values);
void OnHeader_CountHeader_for_Group51Var1_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var1* values);
void OnHeader_CountHeader_for_Group51Var2_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var2* values);
void OnHeader_CountHeader_for_Group52Var1_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var1* values);
void OnHeader_CountHeader_for_Group52Var2_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var2* values);

void OnHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values);
void OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values);
void OnHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
void OnHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
void OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Counter* values);
void OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values);
void OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Analog* values);
void OnHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
void OnHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_OctetString* values);
void OnHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values);

// events

void OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary* values);
void OnHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
void OnHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
void OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter* values);
void OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values);
void OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog* values);
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values);
void OnHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString* values);
void OnHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values);
void OnHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values);
void OnHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values);

// adhoc read by index
void OnHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* values);

// commands

void OnHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values);
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values);
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values);
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values);
//    void OnHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputDouble64* values);

////protected:
void Reset_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);

uint32_t NumIgnoredHeaders_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
uint32_t GetCurrentHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
boolean IsFirstHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);

void Record_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, HeaderRecord* record, IINField* result);
IINField ProcessUnsupportedHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);


////    uint32_t NumIgnoredHeaders_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
////    {
////        return numIgnoredHeaders;
////    }

////    inline uint32_t GetCurrentHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
////    {
////        return numTotalHeaders;
////    }

////    inline bool IsFirstHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
////    {
////        return numTotalHeaders == 0;
////    }

////} // namespace opendnp3

#endif
