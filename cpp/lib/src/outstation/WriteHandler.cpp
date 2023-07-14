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
#include "header.h"
#include "WriteHandler.h"

////#include "logging/LogMacros.h"

////namespace opendnp3
////{

void WriteHandler_in_WriteHandler(WriteHandler *pWriteHandler,
    IOutstationApplication* application, TimeSyncState* timeSyncState, AppSeqNum seq, Timestamp now, IINField* writeIIN)
{
    pWriteHandler->application = application;
    pWriteHandler->timeSyncState = timeSyncState;
    pWriteHandler->seq = seq;
    pWriteHandler->now = now;
    pWriteHandler->writeIIN = writeIIN;

    pWriteHandler->wroteTime = false;
    pWriteHandler->wroteIIN = false;

  (pWriteHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_WriteHandler_override;
  (pWriteHandler->iIAPDUHandler).pProcessHeader_RangeHeader_for_IINValue_in_IAPDUHandler = 
                                 ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override;
  (pWriteHandler->iIAPDUHandler).pProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler = 
                                 ProcessHeader_CountHeader_for_Group50Var1_in_WriteHandler_override;
  (pWriteHandler->iIAPDUHandler).pProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler = 
                                 ProcessHeader_CountHeader_for_Group50Var3_in_WriteHandler_override;
  (pWriteHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_TimeAndInterval_in_IAPDUHandler =
                                 ProcessHeader_PrefixHeader_for_TimeAndInterval_in_WriteHandler_override;

  setParentPointer_in_IWhiteList(&((pWriteHandler->iIAPDUHandler).iIWhiteList), pWriteHandler);
  setParentPointer_in_IAPDUHandler(&(pWriteHandler->iIAPDUHandler), pWriteHandler);
}

IINField ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override(void *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values)
{
UNUSED(header);
  WriteHandler *parent =
    (WriteHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

    Indexed_for_IINValue pair;
    Indexed_for_IINValue_in_Indexed_for_IINValueOver1(&pair);

////    if (!values.ReadOnlyValue(pair))
    if (!ReadOnlyValue_in_ICollection_Indexed_for_IINValue(values, &pair))
    {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
    }

    if (parent->wroteIIN)
    {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
    }

////    if (pair.index != static_cast<uint16_t>(IINBit::DEVICE_RESTART))
    if (pair.index != (uint16_t)(IINBit_DEVICE_RESTART))
    {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
    }

    if (pair.value.value)
    {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
    }

    parent->wroteIIN = true;
//    void ClearBit_in_IINField(IINField *, IINBit_uint8_t bit);
////    parent->writeIIN->ClearBit(IINBit::DEVICE_RESTART);
    ClearBit_in_IINField(parent->writeIIN, IINBit_DEVICE_RESTART);
////    return IINField();
    IINField iIINField;
    IINField_in_IINFieldOver1(&iIINField);
    return iIINField;
}

IINField ProcessHeader_CountHeader_for_Group50Var1_in_WriteHandler_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values)
{
UNUSED(header);
  WriteHandler *parent =
    (WriteHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

    if (parent->wroteTime)
{
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
}

//    boolean SupportsWriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication*);
////    if (!application->SupportsWriteAbsoluteTime())
    if (!SupportsWriteAbsoluteTime_in_IOutstationApplication(parent->application))
{
////        return IINBit::FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
}

    Group50Var1 value;
    Group50Var1_in_Group50Var1(&value);

//boolean ReadOnlyValue_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* value);
////    if (!values.ReadOnlyValue(value))
      if (!ReadOnlyValue_in_ICollection_for_Group50Var1(values, &value))
{
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
}

    parent->wroteTime = true;
//void UTCTimestamp_in_UTCTimestampOver2(UTCTimestamp *pUTCTimestamp, uint64_t msSinceEpoch);
//    boolean WriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication*, UTCTimestamp* timestamp);
////    return application->WriteAbsoluteTime(UTCTimestamp(value.time.value)) ? IINField::Empty() : IINBit::PARAM_ERROR;
    UTCTimestamp uUTCTimestamp;
    UTCTimestamp_in_UTCTimestampOver2(&uUTCTimestamp, value.timeDNPTime.value);
    IINField iIINField1;
    IINField_in_IINFieldOver2(&iIINField1, IINBit_PARAM_ERROR);
//   IINField Empty_in_IINField_static(void);
   return WriteAbsoluteTime_in_IOutstationApplication(parent->application, &uUTCTimestamp) ?
                            Empty_in_IINField_static() :
                            iIINField1;
}

IINField ProcessHeader_CountHeader_for_Group50Var3_in_WriteHandler_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values)
{
UNUSED(header);
  WriteHandler *parent =
    (WriteHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

    if (parent->wroteTime)
{
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
}

//    boolean SupportsWriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication*);
////    if (!application->SupportsWriteAbsoluteTime())
        if (!SupportsWriteAbsoluteTime_in_IOutstationApplication(parent->application))
{
////        return IINBit::FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
}

    Group50Var3 value;
    Group50Var3_in_Group50Var3(&value);

////    if (!values.ReadOnlyValue(value))
////        return IINBit::PARAM_ERROR;
      if (!ReadOnlyValue_in_ICollection_for_Group50Var3(values, &value))
{
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
}

//boolean CalcTimeDifference_in_TimeSyncState(TimeSyncState *pTimeSyncState, AppSeqNum* seq, Timestamp* now);
////    if (!this->timeSyncState->CalcTimeDifference(this->seq, this->now))
    if (!CalcTimeDifference_in_TimeSyncState(parent->timeSyncState, &(parent->seq), &(parent->now)))
{
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
}

//TimeDuration GetDifference_in_TimeSyncState(TimeSyncState *pTimeSyncState);
////    const UTCTimestamp time(
////        value.time.value
////        + std::chrono::duration_cast<std::chrono::milliseconds>(this->timeSyncState->GetDifference().value).count());
    UTCTimestamp timeUTCTimestamp;
    UTCTimestamp_in_UTCTimestampOver2(&timeUTCTimestamp, value.timeDNPTime.value
//        + std::chrono::duration_cast<std::chrono::milliseconds>////(this->timeSyncState->GetDifference().value).count());
          + (GetDifference_in_TimeSyncState(parent->timeSyncState).duration_value));

    parent->wroteTime = true;
////    return application->WriteAbsoluteTime(time) ? IINField::Empty() : IINBit::PARAM_ERROR;
    IINField iIINField1;
    IINField_in_IINFieldOver2(&iIINField1, IINBit_PARAM_ERROR);
//   IINField Empty_in_IINField_static(void);
   return WriteAbsoluteTime_in_IOutstationApplication(parent->application, &timeUTCTimestamp) ?
                            Empty_in_IINField_static() :
                            iIINField1;
}

IINField ProcessHeader_PrefixHeader_for_TimeAndInterval_in_WriteHandler_override(void* pIAPDUHandler, PrefixHeader* header,
                                     ICollection_Indexed_for_TimeAndInterval* values)
{
UNUSED(header);
  WriteHandler *parent =
    (WriteHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

//    boolean SupportsWriteTimeAndInterval_in_IOutstationApplication(IOutstationApplication*);
////    if (!application->SupportsWriteTimeAndInterval())
    if (!SupportsWriteTimeAndInterval_in_IOutstationApplication(parent->application))
    {
////        return IINBit::FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
    }

//    boolean WriteTimeAndInterval_in_IOutstationApplication(IOutstationApplication*, ICollection_Indexed_for_TimeAndInterval* values);
////    return application->WriteTimeAndInterval(values) ? IINField::Empty() : IINBit::PARAM_ERROR;
    IINField iIINField1;
    IINField_in_IINFieldOver2(&iIINField1, IINBit_PARAM_ERROR);
//   IINField Empty_in_IINField_static(void);
      return WriteTimeAndInterval_in_IOutstationApplication(parent->application, values) ?
                                     Empty_in_IINField_static() :
                                     iIINField1;
}

////} // namespace opendnp3

boolean IsAllowed_in_WriteHandler_override(void* pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
UNUSED(pIWhiteList);
UNUSED(headerCount);
UNUSED(gv);
UNUSED(qc);
        return true;
}
