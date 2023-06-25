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
#ifndef OPENDNP3_IEVENTWRITEHANDLER_H
#define OPENDNP3_IEVENTWRITEHANDLER_H

////#include "opendnp3/app/MeasurementTypes.h"
////#include "opendnp3/app/OctetString.h"
////#include "opendnp3/gen/EventAnalogOutputStatusVariation.h"
////#include "opendnp3/gen/EventAnalogVariation.h"
////#include "opendnp3/gen/EventBinaryOutputStatusVariation.h"
////#include "opendnp3/gen/EventBinaryVariation.h"
////#include "opendnp3/gen/EventCounterVariation.h"
////#include "opendnp3/gen/EventDoubleBinaryVariation.h"
////#include "opendnp3/gen/EventFrozenCounterVariation.h"
////#include "opendnp3/gen/EventOctetStringVariation.h"

#include "MeasurementTypes.h"
#include "OctetString.h"
#include "EventAnalogOutputStatusVariation.h"
#include "EventAnalogVariation.h"
#include "EventBinaryOutputStatusVariation.h"
#include "EventBinaryVariation.h"
#include "EventCounterVariation.h"
#include "EventDoubleBinaryVariation.h"
#include "EventFrozenCounterVariation.h"
#include "EventOctetStringVariation.h"

//#include "EventCollection.h"

////namespace opendnp3
////{
////
////template<class T> class IEventWriter
////{
////public:
////  virtual bool Write(const T& meas, uint16_t index) = 0;
////};
////
////template<class T> class IEventCollection
////{
////public:
////  virtual uint16_t WriteSome(IEventWriter<T>& handler) = 0;
////};

//----------------------------------------------Binary---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_Binary)(void*, Binary* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_Binary;
} IEventWriter_for_Binary;
boolean Write_in_IEventWriter_for_Binary(IEventWriter_for_Binary*, Binary* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_Binary(IEventWriter_for_Binary*);
void  setParentPointer_in_IEventWriter_for_Binary(IEventWriter_for_Binary*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_Binary)(void *, IEventWriter_for_Binary* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_Binary;
} IEventCollection_for_Binary;
uint16_t WriteSome_in_IEventCollection_for_Binary(IEventCollection_for_Binary *, IEventWriter_for_Binary* handler);
void* getParentPointer_in_IEventCollection_for_Binary(IEventCollection_for_Binary*);
void  setParentPointer_in_IEventCollection_for_Binary(IEventCollection_for_Binary*, void*);
//----------------------------------------------Binary---------------------------------------------
//----------------------------------------------DoubleBitBinary---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_DoubleBitBinary)(void*, DoubleBitBinary* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_DoubleBitBinary;
} IEventWriter_for_DoubleBitBinary;
boolean Write_in_IEventWriter_for_DoubleBitBinary(IEventWriter_for_DoubleBitBinary*, DoubleBitBinary* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_DoubleBitBinary(IEventWriter_for_DoubleBitBinary*);
void  setParentPointer_in_IEventWriter_for_DoubleBitBinary(IEventWriter_for_DoubleBitBinary*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_DoubleBitBinary)(void *, IEventWriter_for_DoubleBitBinary* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_DoubleBitBinary;
} IEventCollection_for_DoubleBitBinary;
uint16_t WriteSome_in_IEventCollection_for_DoubleBitBinary(IEventCollection_for_DoubleBitBinary *, IEventWriter_for_DoubleBitBinary* handler);
void* getParentPointer_in_IEventCollection_for_DoubleBitBinary(IEventCollection_for_DoubleBitBinary*);
void  setParentPointer_in_IEventCollection_for_DoubleBitBinary(IEventCollection_for_DoubleBitBinary*, void*);
//----------------------------------------------DoubleBitBinary---------------------------------------------
//----------------------------------------------FrozenCounter---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_FrozenCounter)(void*, FrozenCounter* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_FrozenCounter;
} IEventWriter_for_FrozenCounter;
boolean Write_in_IEventWriter_for_FrozenCounter(IEventWriter_for_FrozenCounter*, FrozenCounter* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_FrozenCounter(IEventWriter_for_FrozenCounter*);
void  setParentPointer_in_IEventWriter_for_FrozenCounter(IEventWriter_for_FrozenCounter*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_FrozenCounter)(void *, IEventWriter_for_FrozenCounter* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_FrozenCounter;
} IEventCollection_for_FrozenCounter;
uint16_t WriteSome_in_IEventCollection_for_FrozenCounter(IEventCollection_for_FrozenCounter *, IEventWriter_for_FrozenCounter* handler);
void* getParentPointer_in_IEventCollection_for_FrozenCounter(IEventCollection_for_FrozenCounter*);
void  setParentPointer_in_IEventCollection_for_FrozenCounter(IEventCollection_for_FrozenCounter*, void*);
//----------------------------------------------FrozenCounter---------------------------------------------
//----------------------------------------------Counter---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_Counter)(void*, Counter* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_Counter;
} IEventWriter_for_Counter;
boolean Write_in_IEventWriter_for_Counter(IEventWriter_for_Counter*, Counter* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_Counter(IEventWriter_for_Counter*);
void  setParentPointer_in_IEventWriter_for_Counter(IEventWriter_for_Counter*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_Counter)(void *, IEventWriter_for_Counter* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_Counter;
} IEventCollection_for_Counter;
uint16_t WriteSome_in_IEventCollection_for_Counter(IEventCollection_for_Counter *, IEventWriter_for_Counter* handler);
void* getParentPointer_in_IEventCollection_for_Counter(IEventCollection_for_Counter*);
void  setParentPointer_in_IEventCollection_for_Counter(IEventCollection_for_Counter*, void*);
//----------------------------------------------Counter---------------------------------------------
//----------------------------------------------BinaryOutputStatus---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_BinaryOutputStatus)(void*, BinaryOutputStatus* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_BinaryOutputStatus;
} IEventWriter_for_BinaryOutputStatus;
boolean Write_in_IEventWriter_for_BinaryOutputStatus(IEventWriter_for_BinaryOutputStatus*, BinaryOutputStatus* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_BinaryOutputStatus(IEventWriter_for_BinaryOutputStatus*);
void  setParentPointer_in_IEventWriter_for_BinaryOutputStatus(IEventWriter_for_BinaryOutputStatus*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_BinaryOutputStatus)(void *, IEventWriter_for_BinaryOutputStatus* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_BinaryOutputStatus;
} IEventCollection_for_BinaryOutputStatus;
uint16_t WriteSome_in_IEventCollection_for_BinaryOutputStatus(IEventCollection_for_BinaryOutputStatus *, IEventWriter_for_BinaryOutputStatus* handler);
void* getParentPointer_in_IEventCollection_for_BinaryOutputStatus(IEventCollection_for_BinaryOutputStatus*);
void  setParentPointer_in_IEventCollection_for_BinaryOutputStatus(IEventCollection_for_BinaryOutputStatus*, void*);
//----------------------------------------------BinaryOutputStatus---------------------------------------------
//----------------------------------------------AnalogOutputStatus---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_AnalogOutputStatus)(void*, AnalogOutputStatus* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_AnalogOutputStatus;
} IEventWriter_for_AnalogOutputStatus;
boolean Write_in_IEventWriter_for_AnalogOutputStatus(IEventWriter_for_AnalogOutputStatus*, AnalogOutputStatus* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_AnalogOutputStatus(IEventWriter_for_AnalogOutputStatus*);
void  setParentPointer_in_IEventWriter_for_AnalogOutputStatus(IEventWriter_for_AnalogOutputStatus*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_AnalogOutputStatus)(void *, IEventWriter_for_AnalogOutputStatus* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_AnalogOutputStatus;
} IEventCollection_for_AnalogOutputStatus;
uint16_t WriteSome_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus *, IEventWriter_for_AnalogOutputStatus* handler);
void* getParentPointer_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus*);
void  setParentPointer_in_IEventCollection_for_AnalogOutputStatus(IEventCollection_for_AnalogOutputStatus*, void*);
//----------------------------------------------AnalogOutputStatus---------------------------------------------
//----------------------------------------------Analog---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_Analog)(void*, Analog* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_Analog;
} IEventWriter_for_Analog;
boolean Write_in_IEventWriter_for_Analog(IEventWriter_for_Analog*, Analog* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_Analog(IEventWriter_for_Analog*);
void  setParentPointer_in_IEventWriter_for_Analog(IEventWriter_for_Analog*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_Analog)(void *, IEventWriter_for_Analog* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_Analog;
} IEventCollection_for_Analog;
uint16_t WriteSome_in_IEventCollection_for_Analog(IEventCollection_for_Analog *, IEventWriter_for_Analog* handler);
void* getParentPointer_in_IEventCollection_for_Analog(IEventCollection_for_Analog*);
void  setParentPointer_in_IEventCollection_for_Analog(IEventCollection_for_Analog*, void*);
//----------------------------------------------Analog---------------------------------------------
//----------------------------------------------OctetString---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
  boolean (*pWrite_in_IEventWriter_for_OctetString)(void*, OctetString* meas, uint16_t index);// = 0;

  void* pParentPointer_in_IEventWriter_for_OctetString;

} IEventWriter_for_OctetString;
uint16_t Write_in_IEventWriter_for_OctetString(IEventWriter_for_OctetString *, OctetString* meas, uint16_t index);
void* getParentPointer_in_IEventWriter_for_OctetString(IEventWriter_for_OctetString*);
void  setParentPointer_in_IEventWriter_for_OctetString(IEventWriter_for_OctetString*, void*);

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_OctetString)(void *, IEventWriter_for_OctetString* handler);//// = 0;

  void* pParentPointer_in_IEventCollection_for_OctetString;

} IEventCollection_for_OctetString;
uint16_t WriteSome_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString *, IEventWriter_for_OctetString* handler);
void* getParentPointer_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString*);
void  setParentPointer_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString*, void*);

//----------------------------------------------OctetString---------------------------------------------
////class IEventWriteHandler
typedef struct
{
////public:
////  virtual
  uint16_t (*pWrite_for_Binary_in_IEventWriteHandler)(void *, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);//// = 0;

////  virtual
  uint16_t (*pWrite_for_DoubleBinary_in_IEventWriteHandler)(void *, EventDoubleBinaryVariation_uint8_t variation,
      DoubleBitBinary* first,
      IEventCollection_for_DoubleBitBinary* items);
////    = 0;
////  virtual
  uint16_t (*pWrite_for_Counter_in_IEventWriteHandler)(void *, EventCounterVariation_uint8_t variation, Counter* first, IEventCollection_for_Counter* items);//// = 0;
////  virtual
  uint16_t (*pWrite_for_FrozenCounter_in_IEventWriteHandler)(void *, EventFrozenCounterVariation_uint8_t variation,
      FrozenCounter* first,
      IEventCollection_for_FrozenCounter* items);
////    = 0;
////  virtual
  uint16_t (*pWrite_for_Analog_in_IEventWriteHandler)(void *, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);//// = 0;
////  virtual
  uint16_t (*pWrite_for_BinaryOutputStatus_in_IEventWriteHandler)(void *, EventBinaryOutputStatusVariation_uint8_t variation,
      BinaryOutputStatus* first,
      IEventCollection_for_BinaryOutputStatus* items);
////    = 0;
////  virtual
  uint16_t (*pWrite_for_AnalogOutputStatus_in_IEventWriteHandler)(void *, EventAnalogOutputStatusVariation_uint8_t variation,
      AnalogOutputStatus* first,
      IEventCollection_for_AnalogOutputStatus* items);
////    = 0;
////  virtual
  uint16_t (*pWrite_for_OctetString_in_IEventWriteHandler)(void *, EventOctetStringVariation_uint8_t variation,
      OctetString* first,
      IEventCollection_for_OctetString* items);
////    = 0;

  void* pParentPointer_in_IEventWriteHandler;
} IEventWriteHandler;

uint16_t Write_for_Binary_in_IEventWriteHandler(IEventWriteHandler *, EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);

uint16_t Write_for_DoubleBinary_in_IEventWriteHandler(IEventWriteHandler *, EventDoubleBinaryVariation_uint8_t variation,
    DoubleBitBinary* first,
    IEventCollection_for_DoubleBitBinary* items);

uint16_t Write_for_Counter_in_IEventWriteHandler(IEventWriteHandler *, EventCounterVariation_uint8_t variation, Counter* first, IEventCollection_for_Counter* items);

uint16_t Write_for_FrozenCounter_in_IEventWriteHandler(IEventWriteHandler *, EventFrozenCounterVariation_uint8_t variation,
    FrozenCounter* first,
    IEventCollection_for_FrozenCounter* items);

uint16_t Write_for_Analog_in_IEventWriteHandler(IEventWriteHandler *, EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);

uint16_t Write_for_BinaryOutputStatus_in_IEventWriteHandler(IEventWriteHandler *, EventBinaryOutputStatusVariation_uint8_t variation,
    BinaryOutputStatus* first,
    IEventCollection_for_BinaryOutputStatus* items);

uint16_t Write_for_AnalogOutputStatus_in_IEventWriteHandler(IEventWriteHandler *, EventAnalogOutputStatusVariation_uint8_t variation,
    AnalogOutputStatus* first,
    IEventCollection_for_AnalogOutputStatus* items);

uint16_t Write_for_OctetString_in_IEventWriteHandler(IEventWriteHandler *, EventOctetStringVariation_uint8_t variation,
    OctetString* first,
    IEventCollection_for_OctetString* items);

void* getParentPointer_in_IEventWriteHandler(IEventWriteHandler*);
void  setParentPointer_in_IEventWriteHandler(IEventWriteHandler*, void*);

////} // namespace opendnp3

#endif
