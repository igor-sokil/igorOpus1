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
 boolean (*pWrite_in_IEventWriter_for_Binary)(Binary* meas, uint16_t index);// = 0;
} IEventWriter_for_Binary;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_Binary)(/*EventCollection_for_Binary*/void *pEventCollection_for_Binary, IEventWriter_for_Binary* handler);//// = 0;
} IEventCollection_for_Binary;
//----------------------------------------------Binary---------------------------------------------
//----------------------------------------------DoubleBitBinary---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_DoubleBitBinary)(DoubleBitBinary* meas, uint16_t index);// = 0;
} IEventWriter_for_DoubleBitBinary;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_DoubleBitBinary)(/*EventCollection_for_DoubleBitBinary*/void *pEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* handler);//// = 0;
} IEventCollection_for_DoubleBitBinary;
//----------------------------------------------DoubleBitBinary---------------------------------------------
//----------------------------------------------FrozenCounter---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_FrozenCounter)(FrozenCounter* meas, uint16_t index);// = 0;
} IEventWriter_for_FrozenCounter;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_FrozenCounter)(/*EventCollection_for_FrozenCounter*/void *pEventCollection_for_FrozenCounter, IEventWriter_for_FrozenCounter* handler);//// = 0;
} IEventCollection_for_FrozenCounter;
//----------------------------------------------FrozenCounter---------------------------------------------
//----------------------------------------------Counter---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_Counter)(Counter* meas, uint16_t index);// = 0;
} IEventWriter_for_Counter;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_Counter)(/*EventCollection_for_Counter*/void *pEventCollection_for_Counter, IEventWriter_for_Counter* handler);//// = 0;
} IEventCollection_for_Counter;
//----------------------------------------------Counter---------------------------------------------
//----------------------------------------------BinaryOutputStatus---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_BinaryOutputStatus)(BinaryOutputStatus* meas, uint16_t index);// = 0;
} IEventWriter_for_BinaryOutputStatus;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_BinaryOutputStatus)(/*EventCollection_for_BinaryOutputStatus*/void *pEventCollection_for_BinaryOutputStatus, IEventWriter_for_BinaryOutputStatus* handler);//// = 0;
} IEventCollection_for_BinaryOutputStatus;
//----------------------------------------------BinaryOutputStatus---------------------------------------------
//----------------------------------------------AnalogOutputStatus---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_AnalogOutputStatus)(AnalogOutputStatus* meas, uint16_t index);// = 0;
} IEventWriter_for_AnalogOutputStatus;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_AnalogOutputStatus)(/*EventCollection_for_AnalogOutputStatus*/void *pEventCollection_for_AnalogOutputStatus, IEventWriter_for_AnalogOutputStatus* handler);//// = 0;
} IEventCollection_for_AnalogOutputStatus;
//----------------------------------------------AnalogOutputStatus---------------------------------------------
//----------------------------------------------Analog---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_Analog)(Analog* meas, uint16_t index);// = 0;
} IEventWriter_for_Analog;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_Analog)(/*EventCollection_for_Analog*/void *pEventCollection_for_Analog, IEventWriter_for_Analog* handler);//// = 0;
} IEventCollection_for_Analog;
//----------------------------------------------Analog---------------------------------------------
//----------------------------------------------OctetString---------------------------------------------
////template<class T> class IEventWriter
typedef struct
{
////public:
////  virtual
 boolean (*pWrite_in_IEventWriter_for_OctetString)(OctetString* meas, uint16_t index);// = 0;
} IEventWriter_for_OctetString;

////template<class T> class IEventCollection
typedef struct
{
////public:
////  virtual
  uint16_t (*pWriteSome_in_IEventCollection_for_OctetString)(/*EventCollection_for_OctetString*/void *pEventCollection_for_OctetString, IEventWriter_for_OctetString* handler);//// = 0;
} IEventCollection_for_OctetString;
//----------------------------------------------OctetString---------------------------------------------
////class IEventWriteHandler
typedef struct
{
////public:
////  virtual
     uint16_t (*pWrite_in_IEventWriteHandlerOver1)(EventBinaryVariation_uint8_t variation, Binary* first, IEventCollection_for_Binary* items);//// = 0;

////  virtual 
      uint16_t (*pWrite_in_IEventWriteHandlerOver2)(EventDoubleBinaryVariation_uint8_t variation,
                         DoubleBitBinary* first,
                         IEventCollection_for_DoubleBitBinary* items);
////    = 0;
////  virtual 
     uint16_t (*pWrite_in_IEventWriteHandlerOver3)(EventCounterVariation_uint8_t variation, Counter* first, IEventCollection_for_Counter* items);//// = 0;
////  virtual 
   uint16_t (*pWrite_in_IEventWriteHandlerOver4)(EventFrozenCounterVariation_uint8_t variation,
                         FrozenCounter* first,
                         IEventCollection_for_FrozenCounter* items);
////    = 0;
////  virtual 
  uint16_t (*pWrite_in_IEventWriteHandlerOver5)(EventAnalogVariation_uint8_t variation, Analog* first, IEventCollection_for_Analog* items);//// = 0;
////  virtual
  uint16_t (*pWrite_in_IEventWriteHandlerOver6)(EventBinaryOutputStatusVariation_uint8_t variation,
                         BinaryOutputStatus* first,
                         IEventCollection_for_BinaryOutputStatus* items);
////    = 0;
////  virtual 
  uint16_t (*pWrite_in_IEventWriteHandlerOver7)(EventAnalogOutputStatusVariation_uint8_t variation,
                         AnalogOutputStatus* first,
                         IEventCollection_for_AnalogOutputStatus* items);
////    = 0;
////  virtual 
   uint16_t (*pWrite_in_IEventWriteHandlerOver8)(EventOctetStringVariation_uint8_t variation,
                         OctetString* first,
                         IEventCollection_for_OctetString* items);
////    = 0;
} IEventWriteHandler;
////} // namespace opendnp3

#endif
