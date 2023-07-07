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
#ifndef OPENDNP3_READHANDLER_H
#define OPENDNP3_READHANDLER_H

////#include "app/parsing/IAPDUHandler.h"
////#include "outstation/IEventSelector.h"
////#include "outstation/IStaticSelector.h"

////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/outstation/StaticTypeBitfield.h"

#include "IAPDUHandler.h"
#include "IEventSelector.h"
#include "IStaticSelector.h"

#include "StaticTypeBitfield.h"

////namespace opendnp3
////{

////class ReadHandler final : public IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;
////public:
////    ReadHandler(IStaticSelector& staticSelector, IEventSelector& eventSelector);

////    bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override final
////    {
////        return true;
////    }

////private:
////    IINField ProcessHeader(const AllObjectsHeader& header) override;

////    IINField ProcessHeader(const RangeHeader& header) override;

////    IINField ProcessHeader(const CountHeader& header) override;

////    IINField ProcessHeader(const PrefixHeader& header, const ICollection<uint16_t>& indices) override;

  IStaticSelector* pStaticSelector;
  IEventSelector* pEventSelector;
} ReadHandler;

void  ReadHandler_in_ReadHandler(ReadHandler *pReadHandler, IStaticSelector* staticSelector, IEventSelector* eventSelector);

boolean IsAllowed_in_ReadHandler_override(void *, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc) ;

IINField ProcessHeader_AllObjectsHeader_in_ReadHandler_override(void *, AllObjectsHeader* header);

IINField ProcessHeader_RangeHeader_in_ReadHandler_override(void *, RangeHeader* header);

IINField ProcessHeader_CountHeader_in_ReadHandler_override(void *, CountHeader* header);

IINField ProcessHeader_PrefixHeader_for_uint16_in_ReadHandler_override(void *, PrefixHeader* header, ICollection_for_uint16* indices);

////} // namespace opendnp3

#endif
