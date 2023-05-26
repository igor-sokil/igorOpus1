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
#ifndef OPENDNP3_APDUWRAPPER_H
#define OPENDNP3_APDUWRAPPER_H

////#include "app/AppControlField.h"
////#include "app/HeaderWriter.h"

////#include "opendnp3/gen/FunctionCode.h"

#include "AppControlField.h"
#include "HeaderWriter.h"

#include "FunctionCode.h"

#include "RSeq.h"
#include "WSeq.h"
////#include <ser4cpp/container/SequenceTypes.h>

////namespace opendnp3
////{
#define APDUEquality_uint8_t  uint8_t
enum APDUEquality
{
    APDUEquality_FULL_EQUALITY,
    APDUEquality_OBJECT_HEADERS_EQUAL,
    APDUEquality_NONE
};

// This class is used to write to an underlying buffer
////class APDUWrapper
typedef struct
{
////public:
////    APDUWrapper();

////    explicit APDUWrapper(const ser4cpp::wseq_t& buffer);

////    bool IsValid() const;

////    void SetFunction(FunctionCode_uint8_t code);
////    FunctionCode GetFunction() const;

////    AppControlField GetControl() const;
////    void SetControl(AppControlField control);

////    size_t Size() const;

////    ser4cpp::rseq_t ToRSeq() const;

////    HeaderWriter GetWriter();

////    size_t Remaining() const;

////protected:
    boolean valid;
////    ser4cpp::wseq_t buffer;
////    ser4cpp::wseq_t remaining;
    WSeq_for_Uint16_t buffer;
    WSeq_for_Uint16_t remaining;
} APDUWrapper;

  void APDUWrapper_in_APDUWrapperOver1(APDUWrapper *pAPDUWrapper);
  void APDUWrapper_in_APDUWrapperOver2(APDUWrapper *pAPDUWrapper, WSeq_for_Uint16_t *buffer);
  boolean IsValid_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
  void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
  FunctionCode_uint8_t GetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
  AppControlField GetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
  uint16_t Size_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
  RSeq_for_Uint16_t ToRSeq_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    HeaderWriter GetWriter();
  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
  uint16_t Remaining_in_APDUWrapper(APDUWrapper *pAPDUWrapper);

////} // namespace opendnp3

#endif
