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
#ifndef OPENDNP3_ICOMMAND_COLLECTION_H
#define OPENDNP3_ICOMMAND_COLLECTION_H

////#include <cstdint>

////namespace opendnp3
/////{

/// A collection type for command to which the user can add by type and index
/// Тип коллекции для команды, в которую пользователь может добавлять по типу и индексу
////template<class T> class ICommandCollection
//------------------------AnalogOutputInt16-------------------------
typedef struct
{
////public:
  void* (*pAdd_in_ICommandCollection_for_AnalogOutputInt16)(void *, AnalogOutputInt16* command, uint16_t index);// = 0;

  void* pParentPointer_in_ICommandCollection_for_AnalogOutputInt16;

} ICommandCollection_for_AnalogOutputInt16;

void* Add_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16* pICommandCollection_for_AnalogOutputInt16,
    AnalogOutputInt16* command, uint16_t index);

void* getParentPointer_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16*);
void  setParentPointer_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16*, void*);
//------------------------AnalogOutputInt16-------------------------


////} // namespace opendnp3

#endif
