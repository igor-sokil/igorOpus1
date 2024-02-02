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
#ifndef OPENDNP3_TYPED_COMMAND_HEADER_H
#define OPENDNP3_TYPED_COMMAND_HEADER_H

#include "HeaderWriter.h"
#include "ICommandHeader.h"

#include "Indexed.h"
#include "ICollection.h"
#include "CommandPointState.h"
#include "CommandStatus.h"
#include "ICommandCollection.h"
#include "PrefixedWriteIterator_for_AnalogOutputInt16.h"
#include "HeaderWriter_for_Analog.h"
//#include "QualifierCode.h"

////#include <algorithm>
////#include <vector>

////namespace opendnp3
////{

//------------------------AnalogOutputInt16----------------------------
////    struct Record : public CommandState
typedef struct
{
  CommandState cCommandState;
//void CommandState_in_CommandState(CommandState *pCommandState, uint16_t index_);
////        Record(const Indexed<T>& pair) : CommandState(pair.index), command(pair.value) {}

  AnalogOutputInt16 command;
} Record_in_TypedCommandHeader_for_AnalogOutputInt16;

void Record_in_TypedCommandHeader_for_AnalogOutputInt16_in_Record_in_TypedCommandHeader_for_AnalogOutputInt16(Record_in_TypedCommandHeader_for_AnalogOutputInt16 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt16,
    Indexed_for_AnalogOutputInt16* pair);

////template<class T> class TypedCommandHeader final : public ICommandHeader, public ICommandCollection<T>
typedef struct
{
  ICommandHeader iICommandHeader;
  ICommandCollection_for_AnalogOutputInt16 iICommandCollection_for_AnalogOutputInt16;
////    struct Record : public CommandState
////    {
////        Record(const Indexed<T>& pair) : CommandState(pair.index), command(pair.value) {}

////        T command;
////    };

////public:
////    TypedCommandHeader(const DNP3Serializer<T>& serializer) : serializer(serializer) {}

  // --- Implement ICommandCollection ---

////    virtual ICommandCollection<T>& Add(const T& command, uint16_t index) override;

  // --- Implement ICommandHeader ----

////    virtual bool AreAllSelected() const override;

////    virtual bool Write(HeaderWriter&, IndexQualifierMode mode) override;

////    virtual void ApplySelectResponse(QualifierCode code, const ICollection<Indexed<T>>& commands) override;

////    virtual void ApplyOperateResponse(QualifierCode code, const ICollection<Indexed<T>>& commands) override;

  // --- Implement ICollection<Indexed<CommandResponse>> ----

////    virtual size_t Count() const override;

////    virtual void Foreach(IVisitor<CommandState>& visitor) const override;

////private:
////    QualifierCode ExpectedQualfier() const
////    {
////        return this->use_single_byte_index ? QualifierCode::UINT8_CNT_UINT8_INDEX
////                                           : QualifierCode::UINT16_CNT_UINT16_INDEX;
////    }

  boolean use_single_byte_index;/// = true;
  DNP3Serializer_for_AnalogOutputInt16 serializer;
  std::vector<Record_in_TypedCommandHeader_for_AnalogOutputInt16> records;
//  std::vector<Indexed_for_AnalogOutputInt16> records;
} TypedCommandHeader_for_AnalogOutputInt16;

void TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16,
    DNP3Serializer_for_AnalogOutputInt16* serializer);

void* Add_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16* pTypedCommandHeader_for_AnalogOutputInt16,
    AnalogOutputInt16* command, uint16_t index);
void* Add_in_TypedCommandHeader_for_AnalogOutputInt16_override(void* pICommandCollection_for_AnalogOutputInt16,
    AnalogOutputInt16* command, uint16_t index);

boolean Write_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16* pTypedCommandHeader_for_AnalogOutputInt16,
    HeaderWriter*, IndexQualifierMode_uint8_t mode);
boolean Write_in_TypedCommandHeader_for_AnalogOutputInt16_override(void* pICommandHeader,
    HeaderWriter*, IndexQualifierMode_uint8_t mode);

uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16);
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16, IVisitor__for__CommandState* visitor);
uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt16_override(void *pICollection_for_CommandState);
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt16_override(void *pICollection_for_CommandState, IVisitor__for__CommandState* visitor);
//------------------------AnalogOutputInt16----------------------------
//------------------------AnalogOutputInt32----------------------------
////    struct Record : public CommandState
typedef struct
{
  CommandState cCommandState;
//void CommandState_in_CommandState(CommandState *pCommandState, uint16_t index_);
////        Record(const Indexed<T>& pair) : CommandState(pair.index), command(pair.value) {}

  AnalogOutputInt32 command;
} Record_in_TypedCommandHeader_for_AnalogOutputInt32;

void Record_in_TypedCommandHeader_for_AnalogOutputInt32_in_Record_in_TypedCommandHeader_for_AnalogOutputInt32(Record_in_TypedCommandHeader_for_AnalogOutputInt32 *pRecord_in_TypedCommandHeader_for_AnalogOutputInt32,
    Indexed_for_AnalogOutputInt32* pair);
////template<class T> class TypedCommandHeader final : public ICommandHeader, public ICommandCollection<T>
typedef struct
{
  ICommandHeader iICommandHeader;
  ICommandCollection_for_AnalogOutputInt32 iICommandCollection_for_AnalogOutputInt32;
////    struct Record : public CommandState
////    {
////        Record(const Indexed<T>& pair) : CommandState(pair.index), command(pair.value) {}

////        T command;
////    };

////public:
////    TypedCommandHeader(const DNP3Serializer<T>& serializer) : serializer(serializer) {}

  // --- Implement ICommandCollection ---

////    virtual ICommandCollection<T>& Add(const T& command, uint16_t index) override;

  // --- Implement ICommandHeader ----

////    virtual bool AreAllSelected() const override;

////    virtual bool Write(HeaderWriter&, IndexQualifierMode mode) override;

////    virtual void ApplySelectResponse(QualifierCode code, const ICollection<Indexed<T>>& commands) override;

////    virtual void ApplyOperateResponse(QualifierCode code, const ICollection<Indexed<T>>& commands) override;

  // --- Implement ICollection<Indexed<CommandResponse>> ----

////    virtual size_t Count() const override;

////    virtual void Foreach(IVisitor<CommandState>& visitor) const override;

////private:
////    QualifierCode ExpectedQualfier() const
////    {
////        return this->use_single_byte_index ? QualifierCode::UINT8_CNT_UINT8_INDEX
////                                           : QualifierCode::UINT16_CNT_UINT16_INDEX;
////    }

  boolean use_single_byte_index;/// = true;
  DNP3Serializer_for_AnalogOutputInt32 serializer;
  std::vector<Record_in_TypedCommandHeader_for_AnalogOutputInt32> records;
//  std::vector<Indexed_for_AnalogOutputInt32> records;
} TypedCommandHeader_for_AnalogOutputInt32;

void TypedCommandHeader_for_AnalogOutputInt32_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32 *pTypedCommandHeader_for_AnalogOutputInt32,
    DNP3Serializer_for_AnalogOutputInt32* serializer);

void* Add_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32* pTypedCommandHeader_for_AnalogOutputInt32,
    AnalogOutputInt32* command, uint16_t index);
void* Add_in_TypedCommandHeader_for_AnalogOutputInt32_override(void* pICommandCollection_for_AnalogOutputInt32,
    AnalogOutputInt32* command, uint16_t index);

boolean Write_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32* pTypedCommandHeader_for_AnalogOutputInt32,
    HeaderWriter*, IndexQualifierMode_uint8_t mode);
boolean Write_in_TypedCommandHeader_for_AnalogOutputInt32_override(void* pICommandHeader,
    HeaderWriter*, IndexQualifierMode_uint8_t mode);

uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32 *pTypedCommandHeader_for_AnalogOutputInt32);
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt32(TypedCommandHeader_for_AnalogOutputInt32 *pTypedCommandHeader_for_AnalogOutputInt32, IVisitor__for__CommandState* visitor);
uint16_t Count_in_TypedCommandHeader_for_AnalogOutputInt32_override(void *pICollection_for_CommandState);
void Foreach_in_TypedCommandHeader_for_AnalogOutputInt32_override(void *pICollection_for_CommandState, IVisitor__for__CommandState* visitor);
//------------------------AnalogOutputInt32----------------------------

////template<class T> bool TypedCommandHeader<T>::AreAllSelected() const
////{
////    return std::all_of(this->records.begin(), this->records.end(),
////                       [](const Record& rec) -> bool { return rec.state == CommandPointState::SELECT_SUCCESS; });
////}

////template<class T>
////void TypedCommandHeader<T>::ApplySelectResponse(QualifierCode code, const ICollection<Indexed<T>>& commands)
////{
////    if (code != this->ExpectedQualfier())
////    {
////        return;
////    }
////
////    if (commands.Count() > this->records.size())
////    {
////        return;
////    }
////
////    uint32_t index = 0;
////
////    auto visit = [&](const Indexed<T> item) -> void {
////        auto& rec = this->records[index];
////        ++index;
////
////        if (item.index != rec.index)
////        {
////            return;
////        }
////
////        if (!item.value.ValuesEqual(rec.command))
////        {
////            rec.state = CommandPointState::SELECT_MISMATCH;
////            return;
////        }
////
////        if (item.value.status != CommandStatus::SUCCESS)
////        {
////            rec.state = CommandPointState::SELECT_FAIL;
////            rec.status = item.value.status;
////            return;
////        }
////
////        if (rec.state == CommandPointState::INIT)
////        {
////            rec.state = CommandPointState::SELECT_SUCCESS;
////        }
////    };
////
////    commands.ForeachItem(visit);
////}

////template<class T>
////void TypedCommandHeader<T>::ApplyOperateResponse(QualifierCode code, const ICollection<Indexed<T>>& commands)
////{
////    if (code != this->ExpectedQualfier())
////    {
////        return;
////    }
////
////    if (commands.Count() > this->records.size())
////    {
////        return;
////    }

////    uint32_t index = 0;
////
////    auto visit = [&](const Indexed<T> item) {
////        auto& rec = this->records[index];
////        ++index;
////
////        if (item.index != rec.index)
////        {
////            return;
////        }
////
////        if (!item.value.ValuesEqual(rec.command))
////        {
////            rec.state = CommandPointState::OPERATE_FAIL;
////            return;
////        }
////
////        rec.state = CommandPointState::SUCCESS;
////        rec.status = item.value.status;
////    };
////
////    commands.ForeachItem(visit);
////}
////


////} // namespace opendnp3

#endif
