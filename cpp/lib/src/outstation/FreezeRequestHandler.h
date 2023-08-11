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
#ifndef OPENDNP3_FREEZEREQUESTHANDLER_H
#define OPENDNP3_FREEZEREQUESTHANDLER_H

////#include "app/parsing/IAPDUHandler.h"
////#include "outstation/Database.h"

#include "IAPDUHandler.h"
#include "Database.h"

////namespace opendnp3
////{

////class FreezeRequestHandler final : public IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;
/////public:
////    FreezeRequestHandler(bool clear, Database& database);

////    bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) final;

////private:
////    IINField ProcessHeader(const AllObjectsHeader& record) final;
////    IINField ProcessHeader(const RangeHeader& header) final;

  boolean clear;
  Database* database;
} FreezeRequestHandler;

void FreezeRequestHandler_in_FreezeRequestHandler(FreezeRequestHandler *pFreezeRequestHandler, boolean clear, Database* database);

////    bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) final;
boolean IsAllowed_in_FreezeRequestHandler_override(void*, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
//     boolean (*pIsAllowed_in_IWhiteList)(void*, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

////private:
IINField ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override(void *, AllObjectsHeader* record);
IINField ProcessHeader_RangeHeader_in_FreezeRequestHandler_override(void *, RangeHeader* header);

////} // namespace opendnp3

#endif
