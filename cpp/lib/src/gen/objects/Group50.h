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

#ifndef OPENDNP3_GROUP50_H
#define OPENDNP3_GROUP50_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "app/MeasurementTypeSpecs.h"
#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "MeasurementTypeSpecs.h"


////namespace opendnp3 {

// Time and Date - Absolute Time
////struct Group50Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(50,1); }

////  Group50Var1();

////  static size_t Size() { return 6; }
////  static bool Read(ser4cpp::rseq_t&, Group50Var1&);
////  static bool Write(const Group50Var1&, ser4cpp::wseq_t&);

  DNPTime timeDNPTime;
} Group50Var1;

uint16_t Size_in_Group50Var1_static(void);
void Group50Var1_in_Group50Var1(Group50Var1 *pGroup50Var1);
GroupVariationID ID_in_Group50Var1_static(void);

boolean Read_in_Group50Var1_static(RSeq_for_Uint16_t *, Group50Var1*);
boolean Write_in_Group50Var1_static(Group50Var1*, WSeq_for_Uint16_t*);

// Time and Date - Absolute Time at last recorded time
////struct Group50Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(50,3); }

////  Group50Var3();

////  static size_t Size() { return 6; }
////  static bool Read(ser4cpp::rseq_t&, Group50Var3&);
////  static bool Write(const Group50Var3&, ser4cpp::wseq_t&);

  DNPTime timeDNPTime;
} Group50Var3;

uint16_t Size_in_Group50Var3_static(void);
void Group50Var3_in_Group50Var3(Group50Var3 *pGroup50Var3);
GroupVariationID ID_in_Group50Var3_static(void);

boolean Read_in_Group50Var3_static(RSeq_for_Uint16_t *, Group50Var3*);
boolean Write_in_Group50Var3_static(Group50Var3*, WSeq_for_Uint16_t*);

// Time and Date - Indexed absolute time and long interval
////struct Group50Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(50,4); }

////  Group50Var4();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group50Var4&);
////  static bool Write(const Group50Var4&, ser4cpp::wseq_t&);

  DNPTime timeDNPTime;
  uint32_t interval;
  uint8_t units;

////  typedef TimeAndInterval Target;
////  typedef TimeAndIntervalSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, TimeAndInterval&);
////  static bool WriteTarget(const TimeAndInterval&, ser4cpp::wseq_t&);
////  static DNP3Serializer<TimeAndInterval> Inst() { return DNP3Serializer<TimeAndInterval>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticTimeAndIntervalVariation svariation = StaticTimeAndIntervalVariation::Group50Var4;
} Group50Var4;

uint16_t Size_in_Group50Var4_static(void);
void Group50Var4_in_Group50Var4(Group50Var4 *pGroup50Var4);
GroupVariationID ID_in_Group50Var4_static(void);

boolean Read_in_Group50Var4_static(RSeq_for_Uint16_t *, Group50Var4*);
boolean Write_in_Group50Var4_static(Group50Var4*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group50Var4_static(RSeq_for_Uint16_t*, TimeAndInterval*);
boolean WriteTarget_in_Group50Var4_static(TimeAndInterval*, WSeq_for_Uint16_t*);
DNP3Serializer_for_TimeAndInterval  Inst_in_Group50Var4_static(void);

const StaticTimeAndIntervalVariation_uint8_t svariation_in_Group50Var4 = StaticTimeAndIntervalVariation_Group50Var4;

////}

#endif
