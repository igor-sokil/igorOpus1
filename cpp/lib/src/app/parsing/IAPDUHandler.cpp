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
MYTODO
#include "IAPDUHandler.h"

////namespace opendnp3
////{

void IAPDUHandler_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
 pIAPDUHandler->numTotalHeaders = 0;
 pIAPDUHandler->numIgnoredHeaders = 0;
}

void IAPDUHandler::Reset()
{
    numTotalHeaders = 0;
    numIgnoredHeaders = 0;
    errors.Clear();
}

IINField IAPDUHandler::Errors() const
{
    return errors;
}

void IAPDUHandler::OnHeader(const AllObjectsHeader& header)
{
    Record(header, this->ProcessHeader(header));
}

void IAPDUHandler::OnHeader(const RangeHeader& header)
{
    Record(header, this->ProcessHeader(header));
}

void IAPDUHandler::OnHeader(const CountHeader& header)
{
    Record(header, this->ProcessHeader(header));
}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group50Var1>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group50Var3>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group51Var1>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group51Var2>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group52Var1>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group52Var2>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<IINValue>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<Binary>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<Counter>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<Analog>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<OctetString>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<TimeAndInterval>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

// --- index prefixes ----

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<Binary>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<Counter>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<Analog>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<OctetString>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<TimeAndInterval>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryCommandEvent>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogCommandEvent>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<uint16_t>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

// --- controls ----

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<ControlRelayOutputBlock>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt16>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt32>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputFloat32>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputDouble64>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////IINField IAPDUHandler::ProcessHeader(const AllObjectsHeader& /*record*/)
    IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler*, AllObjectsHeader* record)
{
    return ProcessUnsupportedHeader();
}

    IINField ProcessHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header);
////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/)
////{
////    return ProcessUnsupportedHeader();
////}

    IINField ProcessHeader_CountHeader_in_IAPDUHandler(IAPDUHandler*, CountHeader* header);
////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/)
////{
////    return ProcessUnsupportedHeader();
////}

/// ---- counts -----

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group50Var1>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group50Var3>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group51Var1>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group51Var2>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group52Var1>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group52Var2>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

/// ---- ranges -----

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<IINValue>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<Binary>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<DoubleBitBinary>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<BinaryOutputStatus>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<Counter>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<FrozenCounter>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<Analog>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputStatus>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<OctetString>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<TimeAndInterval>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

/// ---- index prefixes -----

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<Indexed<Counter>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<FrozenCounter>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<Indexed<Binary>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<BinaryOutputStatus>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<DoubleBitBinary>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<Indexed<Analog>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputStatus>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<OctetString>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<TimeAndInterval>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<BinaryCommandEvent>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogCommandEvent>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<uint16_t>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

//// --- controls ----

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<ControlRelayOutputBlock>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputInt16>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputInt32>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputFloat32>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputDouble64>>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////} // namespace opendnp3

    IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, AllObjectsHeader* record)
{
 return (pIAPDUHandler->pProcessHeader_AllObjectsHeader_in_IAPDUHandler)(pIAPDUHandler, record);
}
    IINField ProcessHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_in_IAPDUHandler)(pIAPDUHandler, header)
}
    IINField ProcessHeader_CountHeader_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header)
{
 return (pIAPDUHandler->pProcessHeader_CountHeader_in_IAPDUHandler)(pIAPDUHandler, header);
}

//    IINField ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var1* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var2* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var1* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var2* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

//    IINField ProcessHeader_RangeHeader_for_IINValue_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_IINValue_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_Binary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_Binary_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_DoubleBitBinary_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_BinaryOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_Counter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Counter* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_Counter_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_FrozenCounter_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_Analog_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Analog* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_Analog_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_AnalogOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_OctetString_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_OctetString* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_OctetString_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_RangeHeader_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
//{
// return (pIAPDUHandler->pProcessHeader_RangeHeader_for_TimeAndInterval_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

//    IINField ProcessHeader_PrefixHeader_for_Binary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_Binary_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_BinaryOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_DoubleBitBinary_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_Counter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_Counter_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_FrozenCounter_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_Analog_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_Analog_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_OctetString_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_OctetString_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_TimeAndInterval_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_BinaryCommandEvent_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogCommandEvent_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

    // adhoc read by index
//    IINField ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

//    IINField ProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header,
//                            ICollection_Indexed_for_ControlRelayOutputBlock* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header,
//                                   ICollection_Indexed_for_AnalogOutputDouble64* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

    // overridable to receive post processing events for every header
    void OnHeaderResult_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, HeaderRecord* record, IINField* result)// {}
{
 return (pIAPDUHandler->pOnHeaderResult_in_IAPDUHandler)(pIAPDUHandler, record, result);
}

void* getParentPointer_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler)
{
  return pIAPDUHandler->pParentPointer_in_IAPDUHandler;
}

void  setParentPointer_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, void* pParentPointer)
{
  pIAPDUHandler->pParentPointer_in_IAPDUHandler = pParentPointer;
}

    uint32_t NumIgnoredHeaders_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
    {
        return pIAPDUHandler->numIgnoredHeaders;
    }

     uint32_t GetCurrentHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
    {
        return pIAPDUHandler->numTotalHeaders;
    }

     boolean IsFirstHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
    {
        return pIAPDUHandler->numTotalHeaders == 0;
    }

    void Record_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, HeaderRecord* record, IINField* result)
    {
        pIAPDUHandler->errors |= result;
        ++(pIAPDUHandler->numTotalHeaders);
//    void OnHeaderResult_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, HeaderRecord* record, IINField* result)// {}
////        this->OnHeaderResult(record, result);
    OnHeaderResult_in_IAPDUHandler(pIAPDUHandler, record, result);
    }

   void OnHeaderResult_in_IAPDUHandler(void* pIAPDUHandler, HeaderRecord* record, IINField* result)
{
UNUSED(pIAPDUHandler);
UNUSED(record);
UNUSED(result);
}

    IINField ProcessUnsupportedHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
    {
        ++(pIAPDUHandler->numIgnoredHeaders);
//   void IINField_in_IINFieldOver2(IINField *pIINField, IINBit_uint8_t bit);
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
        IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
      return iIINField;
    }
