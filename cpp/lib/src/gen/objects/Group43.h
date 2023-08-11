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

#ifndef OPENDNP3_GROUP43_H
#define OPENDNP3_GROUP43_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "opendnp3/app/AnalogCommandEvent.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "AnalogCommandEvent.h"

////namespace opendnp3 {

// Analog Command Event - 32-bit
////struct Group43Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,1); }

////  Group43Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var1&);
////  static bool Write(const Group43Var1&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t status;
  int32_t value;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var1;

uint16_t Size_in_Group43Var1_static(void);

uint16_t Size_in_Group43Var1_static(void)
{
  return 5;
}

void Group43Var1_in_Group43Var1(Group43Var1 *pGroup43Var1);

GroupVariationID ID_in_Group43Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 1);
////  return GroupVariationID(43,1);
  return gGroupVariationID;
}

boolean Read_in_Group43Var1_static(RSeq_for_Uint16_t *, Group43Var1*);
boolean Write_in_Group43Var1_static(Group43Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var1_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var1_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

// Analog Command Event - 16-bit
////struct Group43Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,2); }

////  Group43Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var2&);
////  static bool Write(const Group43Var2&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t status;
  int16_t value;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var2;

uint16_t Size_in_Group43Var2_static(void);

uint16_t Size_in_Group43Var2_static(void)
{
  return 3;
}

void Group43Var2_in_Group43Var2(Group43Var2 *pGroup43Var2);

GroupVariationID ID_in_Group43Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 2);
////  return GroupVariationID(43,2);
  return gGroupVariationID;
}

boolean Read_in_Group43Var2_static(RSeq_for_Uint16_t *, Group43Var2*);
boolean Write_in_Group43Var2_static(Group43Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var2_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var2_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var2_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var2_static(),
      Size_in_Group43Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

// Analog Command Event - 32-bit With Time
////struct Group43Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,3); }

////  Group43Var3();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var3&);
////  static bool Write(const Group43Var3&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t status;
  int32_t value;
  DNPTime timeDNPTime;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var3;

uint16_t Size_in_Group43Var3_static(void);

uint16_t Size_in_Group43Var3_static(void)
{
  return 11;
}

void Group43Var3_in_Group43Var3(Group43Var3 *pGroup43Var3);

GroupVariationID ID_in_Group43Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 3);
////  return GroupVariationID(43,3);
  return gGroupVariationID;
}

boolean Read_in_Group43Var3_static(RSeq_for_Uint16_t *, Group43Var3*);
boolean Write_in_Group43Var3_static(Group43Var3*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var3_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var3_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var3_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var3_static(),
      Size_in_Group43Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

// Analog Command Event - 16-bit With Time
////struct Group43Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,4); }

////  Group43Var4();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var4&);
////  static bool Write(const Group43Var4&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t status;
  int16_t value;
  DNPTime timeDNPTime;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var4;

uint16_t Size_in_Group43Var4_static(void);

uint16_t Size_in_Group43Var4_static(void)
{
  return 9;
}

void Group43Var4_in_Group43Var4(Group43Var4 *pGroup43Var4);

GroupVariationID ID_in_Group43Var4_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 4);
////  return GroupVariationID(43,4);
  return gGroupVariationID;
}

boolean Read_in_Group43Var4_static(RSeq_for_Uint16_t *, Group43Var4*);
boolean Write_in_Group43Var4_static(Group43Var4*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var4_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var4_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var4_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var4_static(),
      Size_in_Group43Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

// Analog Command Event - Single-precision
////struct Group43Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,5); }

////  Group43Var5();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var5&);
////  static bool Write(const Group43Var5&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t status;
  float value;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var5;

uint16_t Size_in_Group43Var5_static(void);

uint16_t Size_in_Group43Var5_static(void)
{
  return 5;
}

void Group43Var5_in_Group43Var5(Group43Var5 *pGroup43Var5);

GroupVariationID ID_in_Group43Var5_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 5);
////  return GroupVariationID(43,5);
  return gGroupVariationID;
}

boolean Read_in_Group43Var5_static(RSeq_for_Uint16_t *, Group43Var5*);
boolean Write_in_Group43Var5_static(Group43Var5*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var5_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var5_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var5_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var5_static(),
      Size_in_Group43Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

// Analog Command Event - Double-precision
////struct Group43Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,6); }

////  Group43Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var6&);
////  static bool Write(const Group43Var6&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t status;
  double value;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var6;

uint16_t Size_in_Group43Var6_static(void);

uint16_t Size_in_Group43Var6_static(void)
{
  return 9;
}

void Group43Var6_in_Group43Var6(Group43Var6 *pGroup43Var6);

GroupVariationID ID_in_Group43Var6_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 6);
////  return GroupVariationID(43,6);
  return gGroupVariationID;
}

boolean Read_in_Group43Var6_static(RSeq_for_Uint16_t *, Group43Var6*);
boolean Write_in_Group43Var6_static(Group43Var6*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var6_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var6_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var6_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var6_static(),
      Size_in_Group43Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

// Analog Command Event - Single-precision With Time
////struct Group43Var7
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,7); }

////  Group43Var7();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var7&);
////  static bool Write(const Group43Var7&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t status;
  float value;
  DNPTime timeDNPTime;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var7;

uint16_t Size_in_Group43Var7_static(void);

uint16_t Size_in_Group43Var7_static(void)
{
  return 11;
}

void Group43Var7_in_Group43Var7(Group43Var7 *pGroup43Var7);

GroupVariationID ID_in_Group43Var7_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 7);
////  return GroupVariationID(43,7);
  return gGroupVariationID;
}

boolean Read_in_Group43Var7_static(RSeq_for_Uint16_t *, Group43Var7*);
boolean Write_in_Group43Var7_static(Group43Var7*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var7_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var7_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var7_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var7_static(),
      Size_in_Group43Var7_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var7_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var7_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

// Analog Command Event - Double-precision With Time
////struct Group43Var8
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(43,8); }

////  Group43Var8();

////  static size_t Size() { return 15; }
////  static bool Read(ser4cpp::rseq_t&, Group43Var8&);
////  static bool Write(const Group43Var8&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t status;
  double value;
  DNPTime timeDNPTime;

////  typedef AnalogCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogCommandEvent&);
////  static bool WriteTarget(const AnalogCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogCommandEvent> Inst() { return DNP3Serializer<AnalogCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group43Var8;

uint16_t Size_in_Group43Var8_static(void);

uint16_t Size_in_Group43Var8_static(void)
{
  return 15;
}

void Group43Var8_in_Group43Var8(Group43Var8 *pGroup43Var8);

GroupVariationID ID_in_Group43Var8_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 8);
////  return GroupVariationID(43,8);
  return gGroupVariationID;
}

boolean Read_in_Group43Var8_static(RSeq_for_Uint16_t *, Group43Var8*);
boolean Write_in_Group43Var8_static(Group43Var8*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group43Var8_static(RSeq_for_Uint16_t*, AnalogCommandEvent*);
boolean WriteTarget_in_Group43Var8_static(AnalogCommandEvent*, WSeq_for_Uint16_t*);

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var8_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var8_static(),
      Size_in_Group43Var8_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var8_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var8_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

////}

#endif
