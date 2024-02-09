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
////#include "opendnp3/app/ClassField.h"
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "ClassField.h"

////namespace opendnp3
////{
ClassField None_in_ClassField_static(void)
{
  ClassField cClassField;
  ClassField_in_ClassFieldOver1(&cClassField);
  return cClassField;
}

ClassField AllClasses_in_ClassField_static(void)
{
  ClassField cClassField;
  ClassField_in_ClassFieldOver4(&cClassField, ALL_CLASSES_in_ClassField);
  return cClassField;
}

ClassField AllEventClasses_in_ClassField_static(void)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{AllEventClasses_in_ClassField_static1"<<'\n';
#endif
  ClassField cClassField;
////  ClassField_in_ClassFieldOver3(&cClassField, EVENT_CLASSES_in_ClassField);
//  ClassField_in_ClassFieldOver5(pClassField, false, ec == EventClass_EC1, ec == EventClass_EC2, ec == EventClass_EC3);
  ClassField_in_ClassFieldOver5(&cClassField, false, true, true, true);

#ifdef  LOG_INFO
  inspect_ClassField(&cClassField);
  std::cout<<getString_stack_info();
  std::cout<<"}AllEventClasses_in_ClassField_static_"<<'\n';
  decrement_stack_info();
#endif
  return cClassField;
}

void ClassField_in_ClassFieldOver1(ClassField *pClassField)
{
  pClassField->bitfield = 0;
}

void ClassField_in_ClassFieldOver2(ClassField *pClassField, PointClass_uint8_t pc)
{
  pClassField->bitfield = pc;
}

void ClassField_in_ClassFieldOver3(ClassField *pClassField, EventClass_uint8_t ec)
{
  ClassField_in_ClassFieldOver5(pClassField, false, ec == EventClass_EC1, ec == EventClass_EC2, ec == EventClass_EC3);
}

void ClassField_in_ClassFieldOver5(ClassField *pClassField, boolean class0, boolean class1, boolean class2, boolean class3)
{
  pClassField->bitfield = 0;
  pClassField->bitfield = class0 ? CLASS_0_in_ClassField : 0;
  pClassField->bitfield |= class1 ? CLASS_1_in_ClassField : 0;
  pClassField->bitfield |= class2 ? CLASS_2_in_ClassField : 0;
  pClassField->bitfield |= class3 ? CLASS_3_in_ClassField : 0;
}

void ClassField_in_ClassFieldOver4(ClassField *pClassField, uint8_t mask_)
{
  pClassField->bitfield = mask_ & ALL_CLASSES_in_ClassField;
}

boolean IsEmpty_in_ClassField(ClassField *pClassField)
{
  return (pClassField->bitfield == 0);
}

boolean Intersects_in_ClassField(ClassField *pClassField, ClassField *other)
{
  return (pClassField->bitfield & other->bitfield) != 0;
}

ClassField OnlyEventClasses_in_ClassField(ClassField *pClassField)
{
  ClassField cClassField;
  ClassField_in_ClassFieldOver2(&cClassField, pClassField->bitfield & EVENT_CLASSES_in_ClassField);
  return cClassField;
}

void Set_in_ClassFieldOver2(ClassField *pClassField, PointClass_uint8_t pc)
{
  pClassField->bitfield |= pc;
}

void Clear_in_ClassField(ClassField *pClassField, ClassField *field)
{
  pClassField->bitfield &= ~(int)(field->bitfield);
}

void Set_in_ClassFieldOver1(ClassField *pClassField, ClassField *field)
{
  pClassField->bitfield |= field->bitfield;
}

boolean HasEventType_in_ClassField(ClassField *pClassField, EventClass_uint8_t ec)
{
  switch (ec)
  {
  case (EventClass_EC1):
    return HasClass1_in_ClassField(pClassField);
  case (EventClass_EC2):
    return HasClass2_in_ClassField(pClassField);
  case (EventClass_EC3):
    return HasClass3_in_ClassField(pClassField);
  default:
    return false;
  }
}

boolean HasClass0_in_ClassField(ClassField *pClassField)
{
  return (pClassField->bitfield & CLASS_0_in_ClassField) != 0;
}

boolean HasClass1_in_ClassField(ClassField *pClassField)
{
  return (pClassField->bitfield & CLASS_1_in_ClassField) != 0;
}

boolean HasClass2_in_ClassField(ClassField *pClassField)
{
  return (pClassField->bitfield & CLASS_2_in_ClassField) != 0;
}

boolean HasClass3_in_ClassField(ClassField *pClassField)
{
  return (pClassField->bitfield & CLASS_3_in_ClassField) != 0;
}

boolean HasEventClass_in_ClassField(ClassField *pClassField)
{
  return (pClassField->bitfield & EVENT_CLASSES_in_ClassField) != 0;
}

boolean HasAnyClass_in_ClassField(ClassField *pClassField)
{
  return pClassField->bitfield != 0;
}

uint8_t GetBitfield_in_ClassField(ClassField *pClassField)
{
  return pClassField->bitfield;
}

////} // namespace opendnp3
