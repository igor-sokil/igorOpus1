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
#ifndef OPENDNP3_ISTATICSELECTOR_H
#define OPENDNP3_ISTATICSELECTOR_H

////#include "app/GroupVariationRecord.h"
////#include "app/Range.h"

////#include "opendnp3/app/IINField.h"
////#include "opendnp3/app/parsing/ICollection.h"

#include "GroupVariationRecord.h"
#include "Range.h"

#include "IINField.h"
#include "ICollection.h"

////namespace opendnp3
////{

////class IStaticSelector
typedef struct
{
////public:
     IINField (*pSelectAll_in_IStaticSelector)(void*, GroupVariation_uint16_t gv);// = 0;

     IINField (*pSelectRange_in_IStaticSelector)(void*, GroupVariation_uint16_t gv,  Range* range);// = 0;

     IINField (*pSelectIndices_in_IStaticSelector)(void*, GroupVariation_uint16_t gv, ICollection_for_uint16* indices);// = 0;

     void (*pUnselect_in_IStaticSelector)(void*);// = 0;

  void* pParentPointer_in_IStaticSelector;
} IStaticSelector;

IINField SelectAll_in_IStaticSelector(IStaticSelector *, GroupVariation_uint16_t gv);
IINField SelectRange_in_IStaticSelector(IStaticSelector *, GroupVariation_uint16_t gv,  Range* range);
IINField SelectIndices_in_IStaticSelector(IStaticSelector *, GroupVariation_uint16_t gv, ICollection_for_uint16* indices);
void Unselect_in_IStaticSelector(IStaticSelector *);

void* getParentPointer_in_IStaticSelector(IStaticSelector*);
void  setParentPointer_in_IStaticSelector(IStaticSelector*, void*);

////} // namespace opendnp3

#endif
