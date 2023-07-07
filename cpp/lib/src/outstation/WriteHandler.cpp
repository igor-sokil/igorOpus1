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
#include "WriteHandler.h"

#include "logging/LogMacros.h"

namespace opendnp3
{

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
}

IINField ProcessHeader_RangeHeader_in_WriteHandler_override(void *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values)
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

IINField WriteHandler::ProcessHeader(const CountHeader* header, ICollection_for_Group50Var1* values)
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

    if (!values.ReadOnlyValue(value))
{
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
}

    parent->wroteTime = true;
//void UTCTimestamp_in_UTCTimestampOver2(UTCTimestamp *pUTCTimestamp, uint64_t msSinceEpoch);
////    return application->WriteAbsoluteTime(UTCTimestamp(value.time.value)) ? IINField::Empty() : IINBit::PARAM_ERROR;
}

IINField WriteHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group50Var3>& values)
{
    if (this->wroteTime)
        return IINBit::PARAM_ERROR;

    if (!application->SupportsWriteAbsoluteTime())
        return IINBit::FUNC_NOT_SUPPORTED;

    Group50Var3 value;
    if (!values.ReadOnlyValue(value))
        return IINBit::PARAM_ERROR;

    if (!this->timeSyncState->CalcTimeDifference(this->seq, this->now))
        return IINBit::PARAM_ERROR;

    const UTCTimestamp time(
        value.time.value
        + std::chrono::duration_cast<std::chrono::milliseconds>(this->timeSyncState->GetDifference().value).count());

    this->wroteTime = true;
    return application->WriteAbsoluteTime(time) ? IINField::Empty() : IINBit::PARAM_ERROR;
}

IINField WriteHandler::ProcessHeader(const PrefixHeader& /*header*/,
                                     const ICollection<Indexed<TimeAndInterval>>& values)
{
    if (!application->SupportsWriteTimeAndInterval())
    {
        return IINBit::FUNC_NOT_SUPPORTED;
    }

    return application->WriteTimeAndInterval(values) ? IINField::Empty() : IINBit::PARAM_ERROR;
}

} // namespace opendnp3
