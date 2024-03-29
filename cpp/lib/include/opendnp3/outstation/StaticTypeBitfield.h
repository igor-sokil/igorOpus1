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
#ifndef OPENDNP3_STATICTYPEBITFIELD_H
#define OPENDNP3_STATICTYPEBITFIELD_H

////#include "opendnp3/gen/StaticTypeBitmask.h"

#include "StaticTypeBitmask.h"

////#include <cstdint>

////namespace opendnp3
////{

/**
 * A bitfield that describes a subset of all static types, e.g. { Binary, Analog } or {Analog, Counter, FrozenCounter }
 */
////struct StaticTypeBitField
typedef struct
{
////    StaticTypeBitField() : mask(0) {}

////    StaticTypeBitField(uint16_t mask) : mask(mask) {}

////    static StaticTypeBitField AllTypes()
////    {
////        return StaticTypeBitField(~0);
////    }

////    bool IsSet(StaticTypeBitmask type) const
////    {
////        return (mask & static_cast<uint16_t>(type)) != 0;
////    }

////    StaticTypeBitField Except(StaticTypeBitmask type) const
////    {
////        return StaticTypeBitField(mask & ~static_cast<uint16_t>(type));
////    }

////private:
  uint16_t mask;
} StaticTypeBitField;

void StaticTypeBitField_in_StaticTypeBitFieldOver1(StaticTypeBitField *pStaticTypeBitField);
void StaticTypeBitField_in_StaticTypeBitFieldOver2(StaticTypeBitField *pStaticTypeBitField, uint16_t mask);
StaticTypeBitField AllTypes_in_StaticTypeBitField_static(void);
boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type);
StaticTypeBitField Except_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type);

////} // namespace opendnp3

#endif
