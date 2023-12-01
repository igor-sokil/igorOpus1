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
#include "QualityFlags.h"

////namespace opendnp3
////{

////namespace flags
////{
boolean GetBinaryValue_in_QualityFlagsOver1(Flags flags)
{
  return (flags.value & ((BinaryQuality_uint8_t)BinaryQuality_STATE)) != 0;
}

Flags GetBinaryFlags_in_QualityFlagsOver2(Flags flags, boolean value)
{
  Flags fFlags1;
  Flags_In_FlagsOver2(&fFlags1,
                      flags.value | ((BinaryQuality_uint8_t)BinaryQuality_STATE)
                     );
  Flags fFlags2;
  Flags_In_FlagsOver2(&fFlags2,
                      flags.value & (~((BinaryQuality_uint8_t)BinaryQuality_STATE))
                     );
////        return (value) ? Flags(flags.value | static_cast<uint8_t>(BinaryQuality::STATE))
////                       : Flags(flags.value & (~static_cast<uint8_t>(BinaryQuality::STATE)));
  return (value) ? fFlags1 : fFlags2;
}

////} // namespace flags

////} // namespace opendnp3
