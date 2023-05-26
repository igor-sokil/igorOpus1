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
#include "AppControlField.h"

////namespace opendnp3
////{

////const AppControlField AppControlField::DEFAULT(true, true, false, false, 0);

void AppControlField_in_AppControlFieldOver2(AppControlField *pAppControlField, uint8_t byte)
{
  pAppControlField->FIR = ((byte & AppControlField_FIR_MASK) != 0);
  pAppControlField->FIN = ((byte & AppControlField_FIN_MASK) != 0);
  pAppControlField->CON = ((byte & AppControlField_CON_MASK) != 0);
  pAppControlField->UNS = ((byte & AppControlField_UNS_MASK) != 0);
  pAppControlField->SEQ = (byte &  AppControlField_SEQ_MASK);
}

AppControlField Request_in_AppControlField_static(uint8_t seq)
{
  AppControlField appControlField;
  AppControlField_in_AppControlFieldOver4(&appControlField, true, true, false, false, seq);
  return appControlField;
}

void AppControlField_in_AppControlFieldOver4(AppControlField *pAppControlField, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq)
{
  pAppControlField->FIR = fir;
  pAppControlField->FIN = fin;
  pAppControlField->CON = con;
  pAppControlField->UNS = uns;
  pAppControlField->SEQ = seq;
}

uint8_t ToByte_in_AppControlField(AppControlField *pAppControlField)
{
  uint8_t ret = 0;

  if (pAppControlField->FIR)
  {
    ret |= AppControlField_FIR_MASK;
  }
  if (pAppControlField->FIN)
  {
    ret |= AppControlField_FIN_MASK;
  }
  if (pAppControlField->CON)
  {
    ret |= AppControlField_CON_MASK;
  }
  if (pAppControlField->UNS)
  {
    ret |= AppControlField_UNS_MASK;
  }

  uint8_t seq = pAppControlField->SEQ % 16;

  return ret | seq;
}

////} // namespace opendnp3
