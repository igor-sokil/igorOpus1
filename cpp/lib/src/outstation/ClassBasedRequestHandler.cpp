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
#include "ClassBasedRequestHandler.h"

////namespace opendnp3
////{

////IINField ClassBasedRequestHandler::ProcessHeader(const AllObjectsHeader& header)
IINField ProcessHeader_AllObjectsHeader_in_ClassBasedRequestHandler_override(void* pIAPDUHandler, AllObjectsHeader* record)
{
   ClassBasedRequestHandler* parent = (ClassBasedRequestHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);

////    switch (header.enumeration)
       switch((record->hHeaderRecord).gGroupVariationRecord.enumeration)
    {
    case (GroupVariation_Group60Var2):
//  void Set_in_ClassFieldOver2(ClassField *pClassField, PointClass_uint8_t pc);
///        classField.Set(PointClass::Class1);
   Set_in_ClassFieldOver2(&(parent->classField), PointClass_Class1);
//   IINField Empty_in_IINField_static(void);
////        return IINField::Empty();
     return Empty_in_IINField_static();
    case (GroupVariation_Group60Var3):
////        classField.Set(PointClass::Class2);
   Set_in_ClassFieldOver2(&(parent->classField), PointClass_Class2);
////        return IINField::Empty();
     return Empty_in_IINField_static();
    case (GroupVariation_Group60Var4):
////        classField.Set(PointClass::Class3);
   Set_in_ClassFieldOver2(&(parent->classField), PointClass_Class3);
////        return IINField::Empty();
     return Empty_in_IINField_static();
    default:
{
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
  return iIINField;
}
    }
}

////} // namespace opendnp3

void ClassBasedRequestHandler_in_ClassBasedRequestHandler(ClassBasedRequestHandler *pClassBasedRequestHandler)
{
//     boolean (*pIsAllowed_in_IWhiteList)(void*, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
 (pClassBasedRequestHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_ClassBasedRequestHandler_override;
//    IINField (*pProcessHeader_AllObjectsHeader_in_IAPDUHandler)(void*, AllObjectsHeader* record);
 (pClassBasedRequestHandler->iIAPDUHandler).pProcessHeader_AllObjectsHeader_in_IAPDUHandler = ProcessHeader_AllObjectsHeader_in_ClassBasedRequestHandler_override;

 setParentPointer_in_IAPDUHandler(&(pClassBasedRequestHandler->iIAPDUHandler), pClassBasedRequestHandler);
 setParentPointer_in_IWhiteList(&((pClassBasedRequestHandler->iIAPDUHandler).iIWhiteList), pClassBasedRequestHandler);
}

boolean IsAllowed_in_ClassBasedRequestHandler_override(void* pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
UNUSED(pIWhiteList);
UNUSED(headerCount);
UNUSED(gv);
UNUSED(qc);
        return true;
}

ClassField GetClassField_in_ClassBasedRequestHandler(ClassBasedRequestHandler *pClassBasedRequestHandler)
    {
        return pClassBasedRequestHandler->classField;
    }
