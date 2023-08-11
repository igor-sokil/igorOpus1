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
#include "Functions.h"

////namespace opendnp3
////{
////bool Functions::IsNoAckFuncCode(FunctionCode code)
boolean IsNoAckFuncCode_in_Functions_static(FunctionCode_uint8_t code)
{
  switch (code)
  {
  case (FunctionCode_DIRECT_OPERATE_NR):
  case (FunctionCode_IMMED_FREEZE_NR):
  case (FunctionCode_FREEZE_AT_TIME_NR):
  case (FunctionCode_FREEZE_CLEAR_NR):
    return true;
  default:
    return false;
  }
}
////} // namespace opendnp3
