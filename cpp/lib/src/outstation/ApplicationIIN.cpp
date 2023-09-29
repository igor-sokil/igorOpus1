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
////#include "opendnp3/outstation/ApplicationIIN.h"
#include "header.h"
#include "ApplicationIIN.h"

////namespace opendnp3
////{

IINField ToIIN_in_ApplicationIIN(ApplicationIIN *pApplicationIIN)
{
  IINField ret;
  IINField_in_IINFieldOver1(&ret);
//    void SetBitToValue_in_IINField(IINField *, IINBit_uint8_t bit, boolean value);
  SetBitToValue_in_IINField(&ret, IINBit_NEED_TIME, pApplicationIIN->needTime);
  SetBitToValue_in_IINField(&ret, IINBit_LOCAL_CONTROL, pApplicationIIN->localControl);
  SetBitToValue_in_IINField(&ret, IINBit_CONFIG_CORRUPT, pApplicationIIN->configCorrupt);
  SetBitToValue_in_IINField(&ret, IINBit_DEVICE_TROUBLE, pApplicationIIN->deviceTrouble);
  SetBitToValue_in_IINField(&ret, IINBit_EVENT_BUFFER_OVERFLOW, pApplicationIIN->eventBufferOverflow);
  return ret;
}

void ApplicationIIN_in_ApplicationIIN(ApplicationIIN *pApplicationIIN)
{
  pApplicationIIN->needTime = false;
  pApplicationIIN->localControl = false;
  pApplicationIIN->configCorrupt = false;
  pApplicationIIN->deviceTrouble = false;
  pApplicationIIN->eventBufferOverflow = false;
}
////} // namespace opendnp3
