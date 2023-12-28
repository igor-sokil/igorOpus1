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
#ifndef OPENDNP3_COMMAND_SET_H
#define OPENDNP3_COMMAND_SET_H

#include "AnalogOutput.h"
#include "ControlRelayOutputBlock.h"
#include "Indexed.h"
#include "ICommandCollection.h"
#include "ICommandHeader.h"

#include <initializer_list>
////#include <memory>
////#include <vector>

////namespace opendnp3
////{

// don't want this to be part of the public API
// не хотим, чтобы это было частью публичного API
////class ICommandHeader;

/**
 * Provides a mechanism for building a set of one or more command headers
* Предоставляет механизм для создания набора из одного или нескольких заголовков команд.
 */
////class CommandSet final
typedef struct
{
  // friend class used to hide some implementation details while keeping the headers private
// дружественный класс, используемый для скрытия некоторых деталей реализации, сохраняя при этом заголовки конфиденциальными
////    friend class CommandSetOps;

////public:
////    typedef std::vector<std::shared_ptr<ICommandHeader>> HeaderVector;
  typedef std::vector<ICommandHeader> HeaderVector;

  /// Contrsuct an empty command set
////    CommandSet() = default;

  // Put this in impl so we can hide details of ICommandHeader
// Поместите это в impl, чтобы мы могли скрыть детали ICommandHeader
////    ~CommandSet();

  /// Construct a new command set and take ownership of the headers in argument
/// Создаем новый набор команд и становимся владельцем заголовков в аргументе
////    CommandSet(CommandSet&& other);

  /// Construct a command set from a list of CROB
////    CommandSet(std::initializer_list<Indexed<ControlRelayOutputBlock>> items);

  /// Construct a command set from a list of AOInt16
////    CommandSet(std::initializer_list<Indexed<AnalogOutputInt16>> items);

  /// Construct a command set from a list of AOInt32
////    CommandSet(std::initializer_list<Indexed<AnalogOutputInt32>> items);

  /// Construct a command set from a list of AOFloat32
////    CommandSet(std::initializer_list<Indexed<AnalogOutputFloat32>> items);

  /// Construct a command set from a list of AODouble64
////    CommandSet(std::initializer_list<Indexed<AnalogOutputDouble64>> items);

  /// Convenience functions that can build an entire header in one call
/// Удобные функции, которые могут построить весь заголовок за один вызов
////    template<class T> void Add(std::initializer_list<Indexed<T>> items)
////    {
////        if (items.size() != 0)
////        {
////            auto& header = this->StartHeader<T>();
////            for (auto& command : items)
////            {
////                header.Add(command.value, command.index);
////            }
////        }
////    }

  /// Convenience functions that can build an entire header in one call
/// Удобные функции, которые могут построить весь заголовок за один вызов
////    template<class T> void Add(std::vector<Indexed<T>> items)
////    {
////        if (!items.empty())
////        {
////            auto& header = this->StartHeader<T>();
////            for (auto& command : items)
////            {
////                header.Add(command.value, command.index);
////            }
////        }
////    }

  /// Begin a header of the parameterized type
////    template<class T> ICommandCollection<T>& StartHeader();

////private:
////    template<class T> void AddAny(std::initializer_list<Indexed<T>> items);

////    ICommandCollection<ControlRelayOutputBlock>& StartHeaderCROB();
////    ICommandCollection<AnalogOutputInt32>& StartHeaderAOInt32();
////    ICommandCollection<AnalogOutputInt16>& StartHeaderAOInt16();
////    ICommandCollection<AnalogOutputFloat32>& StartHeaderAOFloat32();
////    ICommandCollection<AnalogOutputDouble64>& StartHeaderAODouble64();

////    CommandSet(const CommandSet&) = delete;
////    CommandSet& operator=(const CommandSet& other) = delete;

  HeaderVector m_headers;
} CommandSet;

/// Construct a command set from a list of AOInt16
void CommandSet_in_CommandSetOverIndexed_for_AnalogOutputInt16(CommandSet *pCommandSet, std::initializer_list<Indexed_for_AnalogOutputInt16> items);

////    template<class T> void Add(std::initializer_list<Indexed<T>> items)
//void Add_Indexed_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet, std::initializer_list<Indexed_for_AnalogOutputInt16> items);
void Add_Indexed_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet, Indexed_for_AnalogOutputInt16* command);
ICommandCollection_for_AnalogOutputInt16 StartHeader_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet);
ICommandCollection_for_AnalogOutputInt16 StartHeaderAOInt16_in_CommandSet(CommandSet *pCommandSet);

void Add_Indexed_for_AnalogOutputInt32_in_CommandSet(CommandSet *pCommandSet, Indexed_for_AnalogOutputInt32* command);
ICommandCollection_for_AnalogOutputInt32 StartHeader_for_AnalogOutputInt32_in_CommandSet(CommandSet *pCommandSet);
ICommandCollection_for_AnalogOutputInt32 StartHeaderAOInt32_in_CommandSet(CommandSet *pCommandSet);

////template<> inline ICommandCollection<ControlRelayOutputBlock>& CommandSet::StartHeader()
////{
////    return this->StartHeaderCROB();
////}

////
////template<> inline ICommandCollection<AnalogOutputInt32>& CommandSet::StartHeader()
////{
////    return this->StartHeaderAOInt32();
////}
////
////template<> inline ICommandCollection<AnalogOutputFloat32>& CommandSet::StartHeader()
////{
////    return this->StartHeaderAOFloat32();
////}
////
////template<> inline ICommandCollection<AnalogOutputDouble64>& CommandSet::StartHeader()
////{
////    return this->StartHeaderAODouble64();
////}
////
////} // namespace opendnp3

#endif
