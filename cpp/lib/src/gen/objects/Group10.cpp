//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
//
// This file is auto-generated. Do not edit manually
//
// Copyright 2013-2022 Step Function I/O, LLC
//
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
// LLC (https://stepfunc.io) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "Group10.h"

#include "app/parsing/DNPTimeParsing.h"
#include <ser4cpp/serialization/LittleEndian.h>
#include "app/MeasurementFactory.h"
#include "app/WriteConversions.h"

using namespace ser4cpp;

namespace opendnp3 {

// ------- Group10Var2 -------

Group10Var2::Group10Var2() : flags(0)
{}

bool Group10Var2::Read(rseq_t& buffer, Group10Var2& output)
{
  return LittleEndian::read(buffer, output.flags);
}

bool Group10Var2::Write(const Group10Var2& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags);
}

bool Group10Var2::ReadTarget(rseq_t& buff, BinaryOutputStatus& output)
{
  Group10Var2 value;
  if(Read(buff, value))
  {
    output = BinaryOutputStatusFactory::From(value.flags);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group10Var2::WriteTarget(const BinaryOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group10Var2::Write(ConvertGroup10Var2::Apply(value), buff);
}


}
