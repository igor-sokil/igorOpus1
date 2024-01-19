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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "AssignClassHandler.h"

////#include "app/parsing/IAPDUHandler.h"

////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/outstation/IOutstationApplication.h"
#include "IAPDUHandler.h"

//#include "opendnp3/logging/Logger.h"
#include "IOutstationApplication.h"

////namespace opendnp3
////{

//  void AssignClassHandler_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, IOutstationApplication* application, IClassAssigner* assigner);
////AssignClassHandler::AssignClassHandler(IOutstationApplication& application, IClassAssigner& assigner)
////    : classHeader(-1), clazz(PointClass::Class0), pApplication(&application), pAssigner(&assigner)
void AssignClassHandler_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, IOutstationApplication* application, IClassAssigner* assigner)
{
  IAPDUHandler_in_IAPDUHandler(&(pAssignClassHandler->iIAPDUHandler));

  pAssignClassHandler->classHeader = -1;
  pAssignClassHandler->clazz = PointClass_Class0;
  pAssignClassHandler->pApplication = application;
  pAssignClassHandler->pAssigner = assigner;

  (pAssignClassHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_AssignClassHandler_override;
  (pAssignClassHandler->iIAPDUHandler).pProcessHeader_AllObjectsHeader_in_IAPDUHandler = ProcessHeader_AllObjectsHeader_in_AssignClassHandler_override;
  (pAssignClassHandler->iIAPDUHandler).pProcessHeader_RangeHeader_in_IAPDUHandler = ProcessHeader_RangeHeader_in_AssignClassHandler_override;

  setParentPointer_in_IWhiteList(&((pAssignClassHandler->iIAPDUHandler).iIWhiteList), pAssignClassHandler);
  setParentPointer_in_IAPDUHandler(&(pAssignClassHandler->iIAPDUHandler), pAssignClassHandler);
}

// IINField ProcessHeader_AllObjectsHeader_in_AssignClassHandler_override(void *pIAPDUHandler, AllObjectsHeader* header);
////IINField AssignClassHandler::ProcessHeader(const AllObjectsHeader& header)
IINField ProcessHeader_AllObjectsHeader_in_AssignClassHandler_override(void *pIAPDUHandler, AllObjectsHeader* header)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessHeader_AllObjectsHeader_in_AssignClassHandler_override1"<<'\n';
#endif
  AssignClassHandler *parent =
    (AssignClassHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

// boolean IsExpectingAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler);
////    if (IsExpectingAssignment())
  if(IsExpectingAssignment_in_AssignClassHandler(parent))
  {
////        switch (header.enumeration)
    switch((header->hHeaderRecord).gGroupVariationRecord.enumeration)
    {
    case (GroupVariation_Group1Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group1Var0"<<'\n';
  decrement_stack_info();
#endif
//  IINField ProcessAssignAll_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz)
////            return this->ProcessAssignAll(AssignClassType::BinaryInput, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_BinaryInput, parent->clazz);
    case (GroupVariation_Group3Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group3Var0"<<'\n';
  decrement_stack_info();
#endif
////            return this->ProcessAssignAll(AssignClassType::DoubleBinaryInput, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_DoubleBinaryInput, parent->clazz);
    case (GroupVariation_Group10Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group10Var0"<<'\n';
  decrement_stack_info();
#endif
////            return this->ProcessAssignAll(AssignClassType::BinaryOutputStatus, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_BinaryOutputStatus, parent->clazz);
    case (GroupVariation_Group20Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group20Var0"<<'\n';
  decrement_stack_info();
#endif
////            return this->ProcessAssignAll(AssignClassType::Counter, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_Counter, parent->clazz);
    case (GroupVariation_Group21Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group21Var0"<<'\n';
  decrement_stack_info();
#endif
////            return this->ProcessAssignAll(AssignClassType::FrozenCounter, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_FrozenCounter, parent->clazz);
    case (GroupVariation_Group30Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group30Var0"<<'\n';
  decrement_stack_info();
#endif
////            return this->ProcessAssignAll(AssignClassType::AnalogInput, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_AnalogInput, parent->clazz);
    case (GroupVariation_Group40Var0):
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*GroupVariation_Group40Var0"<<'\n';
  decrement_stack_info();
#endif
////            return this->ProcessAssignAll(AssignClassType::AnalogOutputStatus, clazz);
      return ProcessAssignAll_in_AssignClassHandler(parent, AssignClassType_AnalogOutputStatus, parent->clazz);
    default:
    {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FUNC_NOT_SUPPORTED"<<'\n';
  decrement_stack_info();
#endif
////           return IINBit::FUNC_NOT_SUPPORTED;
      IINField iIINField;
      IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
      return iIINField;
    }
    }
  }
  else
  {
//IINField RecordClass_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, GroupVariation_uint16_t gv)
////        return this->RecordClass(header.enumeration);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return RecordClass_in_AssignClassHandler(parent, (header->hHeaderRecord).gGroupVariationRecord.enumeration);
  }
}

IINField ProcessHeader_RangeHeader_in_AssignClassHandler_override(void *pIAPDUHandler, RangeHeader* header)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<"+"<<getString_stack_info();
  std::cout<<"ProcessHeader_RangeHeader_in_AssignClassHandler_override1"<<'\n';
#endif
  AssignClassHandler *parent =
    (AssignClassHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

//boolean IsExpectingAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler)
  if (IsExpectingAssignment_in_AssignClassHandler(parent))
  {
////        switch (header.enumeration)
    switch((header->hHeaderRecord).gGroupVariationRecord.enumeration)
    {

    case (GroupVariation_Group1Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group1Var0"<<'\n';
  decrement_stack_info();
#endif
//   IINField ProcessAssignRange_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range)
////            return ProcessAssignRange(AssignClassType::BinaryInput, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_BinaryInput, parent->clazz, &(header->range));
    case (GroupVariation_Group3Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group3Var0"<<'\n';
  decrement_stack_info();
#endif
////            return ProcessAssignRange(AssignClassType::DoubleBinaryInput, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_DoubleBinaryInput, parent->clazz, &(header->range));
    case (GroupVariation_Group10Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group10Var0"<<'\n';
  decrement_stack_info();
#endif
////            return ProcessAssignRange(AssignClassType::BinaryOutputStatus, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_BinaryOutputStatus, parent->clazz, &(header->range));
    case (GroupVariation_Group20Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group20Var0"<<'\n';
  decrement_stack_info();
#endif
////            return ProcessAssignRange(AssignClassType::Counter, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_Counter, parent->clazz, &(header->range));
    case (GroupVariation_Group21Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group21Var0"<<'\n';
  decrement_stack_info();
#endif
////            return ProcessAssignRange(AssignClassType::FrozenCounter, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_FrozenCounter, parent->clazz, &(header->range));
    case (GroupVariation_Group30Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group30Var0"<<'\n';
  decrement_stack_info();
#endif
////            return ProcessAssignRange(AssignClassType::AnalogInput, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_AnalogInput, parent->clazz, &(header->range));
    case (GroupVariation_Group40Var0):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group40Var0"<<'\n';
  decrement_stack_info();
#endif
////            return ProcessAssignRange(AssignClassType::AnalogOutputStatus, clazz, header.range);
      return ProcessAssignRange_in_AssignClassHandler(parent, AssignClassType_AnalogOutputStatus, parent->clazz, &(header->range));
    default:
    {
////           return IINBit::FUNC_NOT_SUPPORTED;
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FUNC_NOT_SUPPORTED"<<'\n';
  decrement_stack_info();
#endif
      IINField iIINField;
      IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
      return iIINField;
    }
    }
  }
  else
  {
////        return IINBit::PARAM_ERROR;
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*PARAM_ERROR"<<'\n';
  decrement_stack_info();
#endif
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }
}

boolean IsExpectingAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler)
{
//    uint32_t GetCurrentHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
////    auto current = static_cast<int32_t>(this->GetCurrentHeader());
  int32_t current = (int32_t)GetCurrentHeader_in_IAPDUHandler(&(pAssignClassHandler->iIAPDUHandler));

  if (current > 0 && ((current - 1) == pAssignClassHandler->classHeader))
  {
    pAssignClassHandler->classHeader = -1;
    return true;
  }

  return false;
}

////IINField AssignClassHandler::ProcessAssignRange(AssignClassType type, PointClass clazz, const Range& range)
IINField ProcessAssignRange_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessAssignRange_in_AssignClassHandler1"<<'\n';
#endif
//Range AssignClassToRange_in_IClassAssigner(IClassAssigner *, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range);
////    auto actual = pAssigner->AssignClassToRange(type, clazz, range);
  Range actual = AssignClassToRange_in_IClassAssigner(pAssignClassHandler->pAssigner, type, clazz, range);

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range actual.start ="<<actual.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range actual.stop ="<<actual.stop<<'\n';
#endif

//   void NotifyApplicationOfAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range);
////    this->NotifyApplicationOfAssignment(type, clazz, actual);
  NotifyApplicationOfAssignment_in_AssignClassHandler(pAssignClassHandler, type, clazz, &actual);

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range actual.start ="<<actual.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range actual.stop ="<<actual.stop<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.start ="<<range->start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.stop ="<<range->stop<<'\n';
#endif

  // if the range was clipped or invalid return parameter error
//    boolean Equals_in_Range(Range *pRange, Range* other);
////    return actual.Equals(range) ? IINField() : IINBit::PARAM_ERROR;
  IINField iIINField1;
  IINField iIINField2;
  IINField_in_IINFieldOver1(&iIINField1);
  IINField_in_IINFieldOver2(&iIINField2, IINBit_PARAM_ERROR) ;
  if(Equals_in_Range(&actual, range))
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
   return iIINField1;
  }
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IINBit_PARAM_ERROR"<<'\n';
  decrement_stack_info();
#endif
  return iIINField2;
}

////IINField AssignClassHandler::ProcessAssignAll(AssignClassType type, PointClass clazz)
IINField ProcessAssignAll_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessAssignAll_in_AssignClassHandler1"<<'\n';
#endif
//Range AssignClassToAll_in_IClassAssigner(IClassAssigner *, AssignClassType_uint8_t type, PointClass_uint8_t clazz);
////    auto full = pAssigner->AssignClassToAll(type, clazz);
  Range full = AssignClassToAll_in_IClassAssigner(pAssignClassHandler->pAssigner, type, clazz);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range full.start ="<<full.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range full.stop ="<<full.stop<<'\n';
#endif

////    this->NotifyApplicationOfAssignment(type, clazz, full);
  NotifyApplicationOfAssignment_in_AssignClassHandler(pAssignClassHandler, type, clazz, &full);

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range full.start ="<<full.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Range full.stop ="<<full.stop<<'\n';
#endif

//    boolean IsValid_in_Range(Range *pRange);
////    return full.IsValid() ? IINField() : IINBit::PARAM_ERROR;
  IINField iIINField1;
  IINField iIINField2;
  IINField_in_IINFieldOver1(&iIINField1);
  IINField_in_IINFieldOver2(&iIINField2, IINBit_PARAM_ERROR);
  if(IsValid_in_Range(&full))
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
   return iIINField1;
  }
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IINBit_PARAM_ERROR"<<'\n';
  decrement_stack_info();
#endif
  return iIINField2;
}

void NotifyApplicationOfAssignment_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"NotifyApplicationOfAssignment_in_AssignClassHandler1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*AssignClassType_uint8_t type= "<<(uint16_t)type<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*PointClass_uint8_t clazz= "<<(uint16_t)clazz<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range->start= "<<range->start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range->stop= "<<range->stop<<'\n';
#endif
  if (pAssignClassHandler->pApplication && IsValid_in_Range(range))////range.IsValid())
  {
//    void RecordClassAssignment_in_IOutstationApplication(IOutstationApplication*, AssignClassType_uint8_t type, PointClass_uint8_t clazz, uint16_t start, uint16_t stop);
////        pApplication->RecordClassAssignment(type, clazz, range.start, range.stop);
    RecordClassAssignment_in_IOutstationApplication(pAssignClassHandler->pApplication, type, clazz, range->start, range->stop);
  }
}

IINField RecordClass_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, GroupVariation_uint16_t gv)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RecordClass_in_AssignClassHandler1"<<'\n';
#endif
//    uint32_t GetCurrentHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
////    classHeader = this->GetCurrentHeader();
  pAssignClassHandler->classHeader = GetCurrentHeader_in_IAPDUHandler(&(pAssignClassHandler->iIAPDUHandler));

  IINField iIINField1;
  IINField iIINField2;
  IINField_in_IINFieldOver1(&iIINField1);
  IINField_in_IINFieldOver2(&iIINField2, IINBit_PARAM_ERROR);

  switch (gv)
  {
  case (GroupVariation_Group60Var1):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group60Var1"<<'\n';
  decrement_stack_info();
#endif
    pAssignClassHandler->clazz = PointClass_Class0;
    return iIINField1;////IINField();
  case (GroupVariation_Group60Var2):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group60Var2"<<'\n';
  decrement_stack_info();
#endif
    pAssignClassHandler->clazz = PointClass_Class1;
    return iIINField1;////IINField();
  case (GroupVariation_Group60Var3):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group60Var3"<<'\n';
  decrement_stack_info();
#endif
    pAssignClassHandler->clazz = PointClass_Class2;
    return iIINField1;////IINField();
  case (GroupVariation_Group60Var4):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_Group60Var4"<<'\n';
  decrement_stack_info();
#endif
    pAssignClassHandler->clazz = PointClass_Class3;
    return iIINField1;////IINField();
  default:
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IINBit::PARAM_ERROR"<<'\n';
  decrement_stack_info();
#endif
    pAssignClassHandler->classHeader = -1;
    return iIINField2;////IINBit::PARAM_ERROR;
  }
}

////} // namespace opendnp3

//boolean IsAllowed_in_IWhiteList(IWhiteList *, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
////    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override final
boolean IsAllowed_in_AssignClassHandler_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(pIWhiteList);
  UNUSED(headerCount);
  UNUSED(gv);
  UNUSED(qc);
  return true;
}
