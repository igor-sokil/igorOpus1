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

#ifndef OPENDNP3_GROUP22_H
#define OPENDNP3_GROUP22_H

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

// Counter Event - Any Variation
////struct Group22Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(22,0); }
////};

  GroupVariationID ID_in_Group22Var0_static(void);

  GroupVariationID ID_in_Group22Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 0);
//// return GroupVariationID(22,0);
 return gGroupVariationID;
}

// Counter Event - 32-bit With Flag
////struct Group22Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(22,1); }

////  Group22Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group22Var1&);
////  static bool Write(const Group22Var1&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group22Var1;

  uint16_t Size_in_Group22Var1_static(void);

 uint16_t Size_in_Group22Var1_static(void) 
{
 return 5; 
}

 void Group22Var1_in_Group22Var1(Group22Var1 *pGroup22Var1);

  GroupVariationID ID_in_Group22Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 1);
////  return GroupVariationID(22,1); 
 return gGroupVariationID;
}

 boolean Read_in_Group22Var1_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group22Var1_static(Group2Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group22Var1_static(RSeq_for_Uint16_t*, Counter*);
 boolean WriteTarget_in_Group22Var1_static(Counter*, WSeq_for_Uint16_t*);

 DNP3Serializer_for_Counter  Inst_in_Group22Var1_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group22Var1_static(),
                   Size_in_Group22Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group22Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group22Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Counter;
}

// Counter Event - 16-bit With Flag
////struct Group22Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(22,2); }

////  Group22Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group22Var2&);
////  static bool Write(const Group22Var2&, ser4cpp::wseq_t&);

///  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group22Var2;

  uint16_t Size_in_Group22Var2_static(void);

 uint16_t Size_in_Group22Var2_static(void) 
{
 return 3; 
}

 void Group22Var2_in_Group22Var2(Group22Var2 *pGroup22Var2);

  GroupVariationID ID_in_Group22Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 2);
////  return GroupVariationID(22,2); 
 return gGroupVariationID;
}

 boolean Read_in_Group22Var2_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group22Var2_static(Group2Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group22Var2_static(RSeq_for_Uint16_t*, Counter*);
 boolean WriteTarget_in_Group22Var2_static(Counter*, WSeq_for_Uint16_t*);

 DNP3Serializer_for_Counter  Inst_in_Group22Var2_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group22Var2_static(),
                   Size_in_Group22Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group22Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group22Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Counter;
}

// Counter Event - 32-bit With Flag and Time
////struct Group22Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(22,5); }

////  Group22Var5();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group22Var5&);
////  static bool Write(const Group22Var5&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;
  DNPTime timeDNPTime;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group22Var5;

  uint16_t Size_in_Group22Var5_static(void);

 uint16_t Size_in_Group22Var5_static(void) 
{
 return 11; 
}

 void Group22Var5_in_Group2Var5(Group22Var5 *pGroup22Var5);

  GroupVariationID ID_in_Group22Var5_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 5);
////  return GroupVariationID(22,5); 
 return gGroupVariationID;
}

 boolean Read_in_Group22Var5_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group22Var5_static(Group2Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group22Var5_static(RSeq_for_Uint16_t*, Counter*);
 boolean WriteTarget_in_Group22Var5_static(Counter*, WSeq_for_Uint16_t*);

 DNP3Serializer_for_Counter  Inst_in_Group22Var5_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group22Var5_static(),
                   Size_in_Group22Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group22Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group22Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Counter;
}

// Counter Event - 16-bit With Flag and Time
////struct Group22Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(22,6); }

////  Group22Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group22Var6&);
////  static bool Write(const Group22Var6&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;
  DNPTime timeDNPTime;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group22Var6;

  uint16_t Size_in_Group22Var6_static(void);

 uint16_t Size_in_Group22Var6_static(void) 
{
 return 9; 
}

 void Group22Var6_in_Group22Var6(Group22Var6 *pGroup22Var6);

  GroupVariationID ID_in_Group22Var6_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 6);
////  return GroupVariationID(22,6); 
 return gGroupVariationID;
}

 boolean Read_in_Group22Var6_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group22Var6_static(Group2Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group22Var6_static(RSeq_for_Uint16_t*, Counter*);
 boolean WriteTarget_in_Group22Var6_static(Counter*, WSeq_for_Uint16_t*);

 DNP3Serializer_for_Counter  Inst_in_Group22Var6_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group22Var6_static(),
                   Size_in_Group22Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group22Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group26Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Counter;
}

////}

#endif
    