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
#ifndef OPENDNP3_CLASSFIELD_H
#define OPENDNP3_CLASSFIELD_H

////#include "opendnp3/app/EventType.h"
////#include "opendnp3/gen/PointClass.h"
#include "EventType.h"
#include "PointClass.h"

////#include <cstdint>

////namespace opendnp3
////{

/**
 * Specifies a set of event classes e.g. some subset of {0, 1, 2, 3}
 */
////class ClassField
typedef struct
{
////public:
////    ClassField();

////    explicit ClassField(PointClass pc);

////    explicit ClassField(EventClass ec);

////    explicit ClassField(uint8_t mask_);

////    ClassField(bool class0, bool class1, bool class2, bool class3);

////    bool IsEmpty() const;

////    bool Intersects(const ClassField& other) const;

////    uint8_t GetBitfield() const
////    {
////        return bitfield;
////    };

////    ClassField OnlyEventClasses() const;

////    void Clear(const ClassField& field);

////    void Set(const ClassField& field);

////    void Set(PointClass pc);

////    static const uint8_t CLASS_0 = static_cast<uint8_t>(PointClass::Class0);
////    static const uint8_t CLASS_1 = static_cast<uint8_t>(PointClass::Class1);
////    static const uint8_t CLASS_2 = static_cast<uint8_t>(PointClass::Class2);
////    static const uint8_t CLASS_3 = static_cast<uint8_t>(PointClass::Class3);
////    static const uint8_t EVENT_CLASSES = CLASS_1 | CLASS_2 | CLASS_3;
////    static const uint8_t ALL_CLASSES = EVENT_CLASSES | CLASS_0;

////    bool HasEventType(EventClass ec) const;

////    bool HasClass0() const;
////    bool HasClass1() const;
////    bool HasClass2() const;
////    bool HasClass3() const;

////    bool HasEventClass() const;
////    bool HasAnyClass() const;

////    static ClassField None();
////    static ClassField AllClasses();
////    static ClassField AllEventClasses();

////private:
////    uint8_t bitfield;
  uint8_t bitfield;
} ClassField;

void ClassField_in_ClassFieldOver1(ClassField *pClassField);

void ClassField_in_ClassFieldOver2(ClassField *pClassField, PointClass_uint8_t pc);

void ClassField_in_ClassFieldOver3(ClassField *pClassField, EventClass_uint8_t ec);

void ClassField_in_ClassFieldOver4(ClassField *pClassField, uint8_t mask_);

void ClassField_in_ClassFieldOver5(ClassField *pClassField, boolean class0, boolean class1, boolean class2, boolean class3);

boolean IsEmpty_in_ClassField(ClassField *pClassField);

boolean Intersects_in_ClassField(ClassField *pClassField, ClassField *other);

uint8_t GetBitfield_in_ClassField(ClassField *pClassField);

ClassField OnlyEventClasses_in_ClassField(ClassField *pClassField);

void Clear_in_ClassField(ClassField *pClassField, ClassField *field);

void Set_in_ClassFieldOver1(ClassField *pClassField, ClassField *field);

void Set_in_ClassFieldOver2(ClassField *pClassField, PointClass_uint8_t pc);

const uint8_t CLASS_0_in_ClassField = PointClass_Class0;
const uint8_t CLASS_1_in_ClassField = PointClass_Class1;
const uint8_t CLASS_2_in_ClassField = PointClass_Class2;
const uint8_t CLASS_3_in_ClassField = PointClass_Class3;
const uint8_t EVENT_CLASSES_in_ClassField = /*CLASS_1_in_ClassField*/PointClass_Class1 |
    /*CLASS_2_in_ClassField*/PointClass_Class2 |
    /*CLASS_3_in_ClassField*/PointClass_Class3;
const uint8_t ALL_CLASSES_in_ClassField = //EVENT_CLASSES_in_ClassField | CLASS_0_in_ClassField;
  /*CLASS_1_in_ClassField*/PointClass_Class1 |
  /*CLASS_2_in_ClassField*/PointClass_Class2 |
  /*CLASS_3_in_ClassField*/PointClass_Class3 |
  PointClass_Class0;
boolean HasEventType_in_ClassField(ClassField *pClassField, EventClass_uint8_t ec);

boolean HasClass0_in_ClassField(ClassField *pClassField);
boolean HasClass1_in_ClassField(ClassField *pClassField);
boolean HasClass2_in_ClassField(ClassField *pClassField);
boolean HasClass3_in_ClassField(ClassField *pClassField);

boolean HasEventClass_in_ClassField(ClassField *pClassField);
boolean HasAnyClass_in_ClassField(ClassField *pClassField);

ClassField  None_in_ClassField_static(void);
ClassField  AllClasses_in_ClassField_static(void);
ClassField  AllEventClasses_in_ClassField_static(void);

////} // namespace opendnp3

#endif
