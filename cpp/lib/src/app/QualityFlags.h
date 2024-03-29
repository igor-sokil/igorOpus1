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
#ifndef OPENDNP3_QUALITYFLAGS_H
#define OPENDNP3_QUALITYFLAGS_H

////#include "opendnp3/app/Flags.h"
#include "Flags.h"

////#include <cstdint>

////namespace opendnp3
////{

////namespace flags
////{

////    const Flags ONLINE(0x01);
////    const Flags RESTART(0x02);

#define  Flags_ONLINE  0x01
#define  Flags_RESTART 0x02

boolean GetBinaryValue_in_QualityFlagsOver1(Flags fFlags);

Flags   GetBinaryFlags_in_QualityFlagsOver2(Flags fFlags, boolean value);

////} // namespace flags

////} // namespace opendnp3

#endif
