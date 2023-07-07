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
#include "header.h"
#include "ReadHandler.h"

////namespace opendnp3
////{

void ReadHandler_in_ReadHandler(ReadHandler *pReadHandler, IStaticSelector* staticSelector, IEventSelector* eventSelector)
{
  pReadHandler->pStaticSelector = staticSelector;
  pReadHandler->pEventSelector  = eventSelector;

  (pReadHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_ReadHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_AllObjectsHeader_in_IAPDUHandler = ProcessHeader_AllObjectsHeader_in_ReadHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_RangeHeader_in_IAPDUHandler = ProcessHeader_RangeHeader_in_ReadHandler_override;

  (pReadHandler->iIAPDUHandler).pProcessHeader_CountHeader_in_IAPDUHandler = ProcessHeader_CountHeader_in_ReadHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler = ProcessHeader_PrefixHeader_for_uint16_in_ReadHandler_override;

  setParentPointer_in_IWhiteList(&((pReadHandler->iIAPDUHandler).iIWhiteList), pReadHandler);
  setParentPointer_in_IAPDUHandler(&(pReadHandler->iIAPDUHandler), pReadHandler);
}

IINField ProcessHeader_AllObjectsHeader_in_ReadHandler_override(void *pIAPDUHandler, AllObjectsHeader* header)
{
  ReadHandler *parent =
    (ReadHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    switch (header->hHeaderRecord.type)
  switch((header->hHeaderRecord).gGroupVariationRecord.type)
  {
  case (GroupVariationType_STATIC):
//IINField SelectAll_in_IStaticSelector(IStaticSelector *, GroupVariation_uint16_t gv);
////        return pStaticSelector->SelectAll(header.enumeration);
    return SelectAll_in_IStaticSelector(parent->pStaticSelector, (header->hHeaderRecord).gGroupVariationRecord.enumeration);
  case (GroupVariationType_EVENT):
//IINField SelectAll_in_IEventSelector(IEventSelector *, GroupVariation_uint16_t gv);
    ////    return pEventSelector->SelectAll(header.enumeration);
    return SelectAll_in_IEventSelector(parent->pEventSelector, (header->hHeaderRecord).gGroupVariationRecord.enumeration);
  default:
  {
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
  }
}

IINField ProcessHeader_RangeHeader_in_ReadHandler_override(void* pIAPDUHandler, RangeHeader* header)
{
  ReadHandler *parent =
    (ReadHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
//IINField SelectRange_in_IStaticSelector(IStaticSelector *, GroupVariation_uint16_t gv,  Range* range);
////    return pStaticSelector->SelectRange(header.enumeration, header.range);
  return SelectRange_in_IStaticSelector(parent->pStaticSelector, (header->hHeaderRecord).gGroupVariationRecord.enumeration, &(header->range));
}

IINField ProcessHeader_CountHeader_in_ReadHandler_override(void* pIAPDUHandler, CountHeader* header)
{
  ReadHandler *parent =
    (ReadHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
//IINField SelectCount_in_IEventSelector(IEventSelector *, GroupVariation_uint16_t gv, uint16_t count);
////    return pEventSelector->SelectCount(header.enumeration, header.count);
  return SelectCount_in_IEventSelector(parent->pEventSelector, (header->hHeaderRecord).gGroupVariationRecord.enumeration, header->count);
}

IINField ProcessHeader_PrefixHeader_for_uint16_in_ReadHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* indices)
{
  ReadHandler *parent =
    (ReadHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
//IINField SelectIndices_in_IStaticSelector(IStaticSelector *, GroupVariation_uint16_t gv, ICollection_for_uint16* indices);
////    return pStaticSelector->SelectIndices(header.enumeration, indices);
  return SelectIndices_in_IStaticSelector(parent->pStaticSelector, (header->hHeaderRecord).gGroupVariationRecord.enumeration, indices);
}

////} // namespace opendnp3

boolean IsAllowed_in_ReadHandler_override(void *v, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
UNUSED(v);
UNUSED(headerCount);
UNUSED(gv);
UNUSED(qc);
  return true;
}
