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
#ifndef OPENDNP3_IEVENTSELECTOR_H
#define OPENDNP3_IEVENTSELECTOR_H

////#include "app/GroupVariationRecord.h"

////#include "opendnp3/app/IINField.h"

#include "GroupVariationRecord.h"

#include "IINField.h"

////namespace opendnp3
////{

////class IEventSelector
typedef struct
{
////public:
     IINField (*pSelectAll_in_IEventSelector)(void*, GroupVariation_uint8_t gv);// = 0;

     IINField (*pSelectCount_in_IEventSelector)(void*, GroupVariation_uint8_t gv, uint16_t count);// = 0;
} IEventSelector;

////} // namespace opendnp3

#endif
