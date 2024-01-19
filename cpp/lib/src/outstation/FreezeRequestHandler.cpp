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
/////#include "outstation/FreezeRequestHandler.h"

/////#include "gen/objects/Group12.h"
/////#include "gen/objects/Group41.h"

////#include <ser4cpp/serialization/LittleEndian.h>
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "FreezeRequestHandler.h"

////namespace opendnp3
////{

////FreezeRequestHandler::FreezeRequestHandler(bool clear, Database& database) : clear(clear), database(database) {}
void FreezeRequestHandler_in_FreezeRequestHandler(FreezeRequestHandler *pFreezeRequestHandler, boolean clear, Database* database)
{
  IAPDUHandler_in_IAPDUHandler(&(pFreezeRequestHandler->iIAPDUHandler));

  pFreezeRequestHandler->clear = clear;
  pFreezeRequestHandler->database = database;
  
  (pFreezeRequestHandler->iIAPDUHandler).pProcessHeader_AllObjectsHeader_in_IAPDUHandler = ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override;
  (pFreezeRequestHandler->iIAPDUHandler).pProcessHeader_RangeHeader_in_IAPDUHandler = ProcessHeader_RangeHeader_in_FreezeRequestHandler_override;
  
  (pFreezeRequestHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_FreezeRequestHandler_override;

  setParentPointer_in_IWhiteList(&((pFreezeRequestHandler->iIAPDUHandler).iIWhiteList), pFreezeRequestHandler);
  setParentPointer_in_IAPDUHandler(&(pFreezeRequestHandler->iIAPDUHandler), pFreezeRequestHandler);
}

//     boolean (*pIsAllowed_in_IWhiteList)(void*, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
////bool FreezeRequestHandler::IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc)
boolean IsAllowed_in_FreezeRequestHandler_override(void* v, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(v);
  UNUSED(headerCount);
  if (gv != GroupVariation_Group20Var0)
    return false;

  switch (qc)
  {
  case QualifierCode_ALL_OBJECTS:
  case QualifierCode_UINT8_START_STOP:
  case QualifierCode_UINT16_START_STOP:
    return true;
  default:
    return false;
  }
}

////IINField FreezeRequestHandler::ProcessHeader(const AllObjectsHeader& record)
IINField ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override(void *pIAPDUHandler, AllObjectsHeader* record)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override1"<<'\n';
#endif

  FreezeRequestHandler* parent = (FreezeRequestHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
//    IINField SelectAll_in_Database(Database *pDatabase, GroupVariation_uint16_t gv);
////    this->database.SelectAll(record.enumeration);
    SelectAll_in_Database(parent->database, record->hHeaderRecord.gGroupVariationRecord.enumeration);
////    this->database.FreezeSelectedCounters(clear);
    FreezeSelectedCounters_in_Database(parent->database, parent->clear, EventMode_Detect);// = EventMode::Detect);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessHeader_AllObjectsHeader_in_FreezeRequestHandler_override_"<<'\n';
  decrement_stack_info();
#endif
///    return IINField::Empty();
   return Empty_in_IINField_static();
}

////IINField FreezeRequestHandler::ProcessHeader(const RangeHeader& header)
IINField ProcessHeader_RangeHeader_in_FreezeRequestHandler_override(void *pIAPDUHandler, RangeHeader* header)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessHeader_RangeHeader_in_FreezeRequestHandler_override1"<<'\n';
#endif

  FreezeRequestHandler* parent = (FreezeRequestHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
//    IINField SelectRange_in_Database(Database *pDatabase, GroupVariation_uint16_t gv, Range* range);
////    this->database.SelectRange(header.enumeration, header.range);
  SelectRange_in_Database(parent->database, header->hHeaderRecord.gGroupVariationRecord.enumeration, &(header->range));
////    this->database.FreezeSelectedCounters(clear);
    FreezeSelectedCounters_in_Database(parent->database, parent->clear, EventMode_Detect);// = EventMode::Detect);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessHeader_RangeHeader_in_FreezeRequestHandler_override_"<<'\n';
  decrement_stack_info();
#endif
////    return IINField::Empty();
   return Empty_in_IINField_static();
}

////} // namespace opendnp3
