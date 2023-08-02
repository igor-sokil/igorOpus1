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
#ifndef OPENDNP3_ILINKLAYER_H
#define OPENDNP3_ILINKLAYER_H

#include "LayerInterfaces.h"
#include "ITransportSegment.h"

////#include <assert.h>

////namespace opendnp3
////{

////class ILinkLayer
typedef struct
{

////public:
////    virtual ~ILinkLayer() {}

  /// Transmit a buffer that can be iterated over in no greater than 250 byte segments
/// Передаем буфер, который можно перебирать сегментами не более 250 байт
  boolean (*pSend_in_ILinkLayer)(void*, ITransportSegment* segment);// = 0;

  void* pParentPointer_in_ILinkLayer;

} ILinkLayer;

boolean Send_in_ILinkLayer(ILinkLayer*);

void* getParentPointer_in_ILinkLayer(ILinkLayer*);
void  setParentPointer_in_ILinkLayer(ILinkLayer*, void*);

////} // namespace opendnp3

#endif
