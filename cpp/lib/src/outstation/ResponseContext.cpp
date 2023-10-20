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
//#include <QtWidgets>
#include "header.h"
#include "ResponseContext.h"

////namespace opendnp3
////{

void ResponseContext_in_ResponseContext(ResponseContext *pResponseContext, IResponseLoader* staticLoader, IResponseLoader* eventLoader)
{
  pResponseContext->fragmentCount = 0;
  pResponseContext->pStaticLoader = staticLoader;
  pResponseContext->pEventLoader = eventLoader;
}

boolean HasSelection_in_ResponseContext(ResponseContext *pResponseContext)
{
//boolean HasAnySelection_in_IResponseLoader(IResponseLoader *);
////    return pStaticLoader->HasAnySelection() || pEventLoader->HasAnySelection();
  return HasAnySelection_in_IResponseLoader(pResponseContext->pStaticLoader) ||
         HasAnySelection_in_IResponseLoader(pResponseContext->pEventLoader);
}

void Reset_in_ResponseContext(ResponseContext *pResponseContext)
{
  pResponseContext->fragmentCount = 0;
}

AppControlField LoadResponse_in_ResponseContext(ResponseContext *pResponseContext, HeaderWriter* writer)
{
  boolean fir = pResponseContext->fragmentCount == 0;
  ++(pResponseContext->fragmentCount);

//    uint16_t Remaining_in_HeaderWriter(HeaderWriter *pHeaderWriter);
////    auto startingSize = writer.Remaining();
  uint16_t startingSize = Remaining_in_HeaderWriter(writer);
//boolean Load_in_IResponseLoader(IResponseLoader *, HeaderWriter* writer);
////    bool notFull = pEventLoader->Load(writer);
  boolean notFull = Load_in_IResponseLoader(pResponseContext->pEventLoader, writer);

//    uint16_t Remaining_in_HeaderWriter(HeaderWriter *pHeaderWriter);
////    bool someEventsWritten = writer.Remaining() < startingSize;
  boolean someEventsWritten = Remaining_in_HeaderWriter(writer) < startingSize;

  if (notFull)
  {
////        auto fin = pStaticLoader->Load(writer);
    boolean fin = Load_in_IResponseLoader(pResponseContext->pStaticLoader, writer);
    boolean con = !fin || someEventsWritten;
//  void AppControlField_in_AppControlFieldOver3(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns);
////        return AppControlField(fir, fin, con, false);
    AppControlField aAppControlField;
    AppControlField_in_AppControlFieldOver3(&aAppControlField, fir, fin, con, false);
    return aAppControlField;
  }

////    return AppControlField(fir, false, true, false);
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver3(&aAppControlField, fir, false, true, false);
  return aAppControlField;
}

////} // namespace opendnp3
