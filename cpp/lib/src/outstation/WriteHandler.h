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
#ifndef OPENDNP3_WRITEHANDLER_H
#define OPENDNP3_WRITEHANDLER_H

////#include "app/parsing/IAPDUHandler.h"
////#include "outstation/TimeSyncState.h"

////#include "opendnp3/app/IINField.h"
////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/outstation/IOutstationApplication.h"
////#include "opendnp3/util/Timestamp.h"

#include "IAPDUHandler.h"
#include "TimeSyncState.h"

#include "IINField.h"
//#include "opendnp3/logging/Logger.h"
#include "IOutstationApplication.h"
#include "Timestamp.h"

////namespace opendnp3
////{

////class WriteHandler final : public IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;
////public:
////    WriteHandler(IOutstationApplication& application,
////                 TimeSyncState& timeSyncState,
////                 AppSeqNum seq,
////                 Timestamp now,
////                 IINField* pWriteIIN);

////    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override
////    {
////        return true;
////    }

////private:
////    virtual IINField ProcessHeader(const RangeHeader& header, const ICollection<Indexed<IINValue>>& values) override;
////
////    virtual IINField ProcessHeader(const CountHeader& header, const ICollection<Group50Var1>& values) override;

////    virtual IINField ProcessHeader(const CountHeader& header, const ICollection<Group50Var3>& values) override;

////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<TimeAndInterval>>& values) override;

  IOutstationApplication* application;
  TimeSyncState* timeSyncState;
  AppSeqNum seq;
  Timestamp now;
  IINField* writeIIN;

  boolean wroteTime;// = false;
  boolean wroteIIN;// = false;
} WriteHandler;

void WriteHandler_in_WriteHandler(WriteHandler *pWriteHandler,
                                  IOutstationApplication* application, TimeSyncState* timeSyncState, AppSeqNum seq, Timestamp now, IINField* writeIIN);

IINField ProcessHeader_RangeHeader_for_IINValue_in_WriteHandler_override(void *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values);
IINField ProcessHeader_CountHeader_for_Group50Var1_in_WriteHandler_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values);
IINField ProcessHeader_CountHeader_for_Group50Var3_in_WriteHandler_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values);
IINField ProcessHeader_PrefixHeader_for_TimeAndInterval_in_WriteHandler_override(void* pIAPDUHandler, PrefixHeader* header,
    ICollection_Indexed_for_TimeAndInterval* values);
boolean IsAllowed_in_WriteHandler_override(void* pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

////} // namespace opendnp3

#endif
