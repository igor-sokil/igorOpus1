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

#include "header.h"
#include "Group51.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "DNPTimeParsing.h"
//#include <ser4cpp/serialization/LittleEndian.h>

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group51Var1 -------

void Group51Var1_in_Group51Var1(Group51Var1 *pGroup51Var1)
{
  DNPTime_in_DNPTimeOver2(&(pGroup51Var1->timeDNPTime), 0);
}

boolean Read_in_Group51Var1_static(RSeq_for_Uint16_t* buffer, Group51Var1* output)
{
////  return LittleEndian::read(buffer, output.time);
    return read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

boolean Write_in_Group51Var1_static(Group51Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time);
     return  write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);////arg->value);
}

 uint16_t Size_in_Group51Var1_static(void) 
{
 return 6; 
}

  GroupVariationID ID_in_Group51Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 51, 1);
////  return GroupVariationID(51,1); 
 return gGroupVariationID;
}

// ------- Group51Var2 -------

void Group51Var2_in_Group51Var2(Group51Var2 *pGroup51Var2)
{
//// : time(0)
  DNPTime_in_DNPTimeOver2(&(pGroup51Var2->timeDNPTime), 0);
}

boolean Read_in_Group51Var2_static(RSeq_for_Uint16_t* buffer, Group51Var2* output)
{
////  return LittleEndian::read(buffer, output.time);
    return read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

boolean Write_in_Group51Var2_static(Group51Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time);
     return  write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);////arg->value);
}

 uint16_t Size_in_Group51Var2_static(void) 
{
 return 6; 
}

  GroupVariationID ID_in_Group51Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 51, 2);
////  return GroupVariationID(51,2); 
 return gGroupVariationID;
}


////}
