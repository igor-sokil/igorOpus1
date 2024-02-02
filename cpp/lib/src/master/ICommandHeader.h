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
#ifndef OPENDNP3_ICOMMAND_HEADER_H
#define OPENDNP3_ICOMMAND_HEADER_H

////#include "opendnp3/app/AnalogOutput.h"
////#include "opendnp3/app/ControlRelayOutputBlock.h"
////#include "opendnp3/app/Indexed.h"
////#include "opendnp3/app/parsing/ICollection.h"
////#include "opendnp3/gen/IndexQualifierMode.h"
////#include "opendnp3/master/CommandPointResult.h"
////#include "opendnp3/master/HeaderInfo.h"

#include "AnalogOutput.h"
#include "ControlRelayOutputBlock.h"
#include "Indexed.h"
#include "ICollection.h"
#include "IndexQualifierMode.h"
#include "CommandPointResult.h"
#include "HeaderInfo.h"
#include "CommandState.h"
#include "QualifierCode.h"
#include "HeaderWriter.h"

////namespace opendnp3
////{

////class HeaderWriter;

/**
 * Represents an object header of command objects (CROB or AO)
* Представляет заголовок объекта командных объектов (CROB или AO).
 */
////class ICommandHeader : public ICollection<CommandState>
typedef struct
{

  ICollection_for_CommandState iICollection_for_CommandState;
////public:
////    virtual ~ICommandHeader() {}

  /// Write all of the headers to an ASDU
/// Записываем все заголовки в ASDU
  boolean (*pWrite_in_ICommandHeader)(void *, HeaderWriter*, IndexQualifierMode_uint8_t mode);// = 0;

  /// Ask if all of the individual commands have been selected
/// Спросим, все ли отдельные команды выбраны
  boolean (*pAreAllSelected_in_ICommandHeader)(void *);// const = 0;

  // --- each overriden classs will only override one of these ---
// --- каждый переопределенный класс переопределяет только один из них ---

  void (*pApplySelectResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands);
////    {
////    }
  void (*pApplySelectResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands);// {}
  void (*pApplySelectResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands);// {}
  void (*pApplySelectResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands);// {}
////    virtual void ApplySelectResponse(QualifierCode code, const ICollection<Indexed<AnalogOutputDouble64>>& commands) {}

  // --- each overriden classs will only override one of these ---
// --- каждый переопределенный класс переопределяет только один из них ---
  void (*pApplyOperateResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands);
////    {
////    }
  void (*pApplyOperateResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands);// {}
  void (*pApplyOperateResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands);// {}
  void (*pApplyOperateResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader)(void *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands);// {}
////    virtual void ApplyOperateResponse(QualifierCode code, const ICollection<Indexed<AnalogOutputDouble64>>& commands) {}

  void* pParentPointer_in_ICommandHeader;
} ICommandHeader;

boolean Write_in_ICommandHeader(ICommandHeader *, HeaderWriter*, IndexQualifierMode_uint8_t mode);

boolean AreAllSelected_in_ICommandHeader(ICommandHeader *);

void ApplySelectResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands);
////    {
////    }
void ApplySelectResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands);
void ApplySelectResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands);
void ApplySelectResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands);

void ApplyOperateResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands);
////    {
////    }
void ApplyOperateResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands);
void ApplyOperateResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands);
void ApplyOperateResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands);

void* getParentPointer_in_ICommandHeader(ICommandHeader*);
void  setParentPointer_in_ICommandHeader(ICommandHeader*, void*);


////} // namespace opendnp3

#endif
