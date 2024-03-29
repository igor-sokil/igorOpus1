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
#ifndef OPENDNP3_ASSIGNCLASSHANDLER_H
#define OPENDNP3_ASSIGNCLASSHANDLER_H

////#include "app/parsing/IAPDUHandler.h"
////#include "outstation/IClassAssigner.h"

////#include "opendnp3/gen/AssignClassType.h"
////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/outstation/IOutstationApplication.h"

////#include <exe4cpp/IExecutor.h>

#include "IAPDUHandler.h"
#include "IClassAssigner.h"

#include "AssignClassType.h"
//#include "opendnp3/logging/Logger.h"
#include "IOutstationApplication.h"

//#include <exe4cpp/IExecutor.h>

////namespace opendnp3
////{

////class AssignClassHandler : public IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;
////public:
////    AssignClassHandler(IOutstationApplication& application, IClassAssigner& assigner);

//boolean IsAllowed_in_IWhiteList(IWhiteList *, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
////    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override final
////    {
////        return true;
////    }

////private:
////    virtual IINField ProcessHeader(const AllObjectsHeader& header) override final;

////    virtual IINField ProcessHeader(const RangeHeader& header) override final;

////    IINField RecordClass(GroupVariation gv);

////    bool IsExpectingAssignment();

////    IINField ProcessAssignAll(AssignClassType type, PointClass clazz);

////    IINField ProcessAssignRange(AssignClassType type, PointClass clazz, const Range& range);

////    void NotifyApplicationOfAssignment(AssignClassType type, PointClass clazz, const Range& range);

  int32_t classHeader;
  PointClass_uint8_t clazz;

  IOutstationApplication* pApplication;
  IClassAssigner* pAssigner;
} AssignClassHandler;

void AssignClassHandler_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, IOutstationApplication* application, IClassAssigner* assigner);
boolean IsAllowed_in_AssignClassHandler_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

//    IINField (*pProcessHeader_AllObjectsHeader_in_IAPDUHandler)(void*, AllObjectsHeader* record);
//    IINField (*pProcessHeader_RangeHeader_in_IAPDUHandler)(void*, RangeHeader* header);
IINField ProcessHeader_AllObjectsHeader_in_AssignClassHandler_override(void *pIAPDUHandler, AllObjectsHeader* header);

IINField ProcessHeader_RangeHeader_in_AssignClassHandler_override(void *pIAPDUHandler, RangeHeader* header);

boolean IsExpectingAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler);
IINField ProcessAssignAll_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz);

IINField ProcessAssignRange_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range);
void NotifyApplicationOfAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range);
IINField RecordClass_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, GroupVariation_uint16_t gv);


////} // namespace opendnp3

#endif
