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
#ifndef OPENDNP3_EVENTWRITERS_for_Binary_H
#define OPENDNP3_EVENTWRITERS_for_Binary_H

#include "IEventWriteHandler.h"
#include "HeaderWriter.h"
#include "PrefixedWriteIterator_for_Binary.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

////class EventWriters
////typedef struct
////{
////
////public:
////    template<class T>
////    static uint16_t Write(HeaderWriter& writer, IEventCollection<T>& items, const DNP3Serializer<T>& serializer)
////    {
////        BasicEventWriter<T> handler(writer, serializer);
////        return items.WriteSome(handler);
////    }
////
////    template<class T>
////    static uint16_t WriteWithCTO(const DNPTime& cto,
////                                 HeaderWriter& writer,
////                                 IEventCollection<T>& items,
////                                 const DNP3Serializer<T>& serializer)
////    {
////        if (cto.quality == TimestampQuality::SYNCHRONIZED)
////        {
////            Group51Var1 value;
////            value.time = cto;
////            CTOEventWriter<T, Group51Var1> handler(value, writer, serializer);
////            return items.WriteSome(handler);
////        }
////        else
////        {
////            Group51Var2 value;
////            value.time = cto;
////            CTOEventWriter<T, Group51Var2> handler(value, writer, serializer);
////            return items.WriteSome(handler);
////        }
////    }
////
////    static uint16_t Write(uint8_t firstSize, HeaderWriter& writer, IEventCollection<OctetString>& items);
////
////private:
////    template<class T> class BasicEventWriter final : public IEventWriter<T>
////    {
////        PrefixedWriteIterator<ser4cpp::UInt16, T> iterator;
////
////    public:
////        BasicEventWriter(HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : iterator(writer.IterateOverCountWithPrefix<ser4cpp::UInt16, T>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                             serializer))
////        {
////        }
////
////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            return iterator.IsValid() ? iterator.Write(meas, index) : false;
////        }
////    };
////
////    template<class T, class U> class CTOEventWriter final : public IEventWriter<T>
////    {
////        const DNPTime cto;
////        PrefixedWriteIterator<ser4cpp::UInt16, T> iterator;
////
////    public:
////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
////        {
////        }
////
////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            if (!this->iterator.IsValid())
////                return false;
////
////            // Check that the quality of the measurement fits with the CTO variation
////            if (this->cto.quality == TimestampQuality::SYNCHRONIZED)
////            {
////                if (meas.time.quality != TimestampQuality::SYNCHRONIZED)
////                    return false;
////            }
////            else
////            {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
////                    return false;
////            }
////
////            // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
////                return false;
////
////            const auto diff = meas.time.value - this->cto.value;
////
////            // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
////                return false;
////
////            auto copy = meas;
////            copy.time = DNPTime(diff);
////
////            return this->iterator.Write(copy, index);
////        }
////    };
////} EventWriters;
////
////////} // namespace opendnp3

uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer);
uint16_t WriteWithCTO_for_Binary_in_EventWriters_static(DNPTime* cto,
    HeaderWriter* writer,
    IEventCollection_for_Binary* items,
    DNP3Serializer_for_Binary* serializer);


////    template<class T>
////
////    static uint16_t Write(uint8_t firstSize, HeaderWriter& writer, IEventCollection<OctetString>& items);
////
////private:
////    template<class T> class BasicEventWriter final : public IEventWriter<T>
typedef struct
{
  IEventWriter_for_Binary iIEventWriter_for_Binary;
  PrefixedWriteIterator_for_UInt16_Binary iterator;

} BasicEventWriter_for_Binary;

void BasicEventWriter_for_Binary_in_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary,
    HeaderWriter* writer, DNP3Serializer_for_Binary* serializer);
void BasicEventWriter_for_Binary_destr_BasicEventWriter_for_Binary(BasicEventWriter_for_Binary *pBasicEventWriter_for_Binary);
boolean Write_in_BasicEventWriter_for_Binary_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index);

////    template<class T, class U> class CTOEventWriter final : public IEventWriter<T>
typedef struct
{
  IEventWriter_for_Binary iIEventWriter_for_Binary;
  DNPTime cto;
////        PrefixedWriteIterator<ser4cpp::UInt16, T> iterator;
  PrefixedWriteIterator_for_UInt16_Binary iterator;

////    public:
////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
////        {
////        }
////
////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            if (!this->iterator.IsValid())
////                return false;
////
  // Check that the quality of the measurement fits with the CTO variation
////            if (this->cto.quality == TimestampQuality::SYNCHRONIZED)
////            {
////                if (meas.time.quality != TimestampQuality::SYNCHRONIZED)
////                    return false;
////            }
////            else
////            {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
////                    return false;
////            }
////
////            // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
////                return false;
////
////            const auto diff = meas.time.value - this->cto.value;

  // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
////                return false;
////
////            auto copy = meas;
////            copy.time = DNPTime(diff);
////
////            return this->iterator.Write(copy, index);
////        }
} CTOEventWriter_for_Binary_Group51Var1;

void CTOEventWriter_for_Binary_Group51Var1_in_CTOEventWriter_for_Binary_Group51Var1(CTOEventWriter_for_Binary_Group51Var1 *pCTOEventWriter_for_Binary_Group51Var1,
    Group51Var1* cto,
    HeaderWriter* writer,
    DNP3Serializer_for_Binary* serializer);
boolean Write_in_CTOEventWriter_for_Binary_Group51Var1_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index);

////    template<class T, class U> class CTOEventWriter final : public IEventWriter<T>
typedef struct
{
  IEventWriter_for_Binary iIEventWriter_for_Binary;
  DNPTime cto;
////        PrefixedWriteIterator<ser4cpp::UInt16, T> iterator;
  PrefixedWriteIterator_for_UInt16_Binary iterator;

////    public:
////        CTOEventWriter(const U& cto, HeaderWriter& writer, const DNP3Serializer<T>& serializer)
////            : cto(cto.time),
////              iterator(writer.IterateOverCountWithPrefixAndCTO<ser4cpp::UInt16, T, U>(
////                  QualifierCode::UINT16_CNT_UINT16_INDEX, serializer, cto))
////        {
////        }
////
////        virtual bool Write(const T& meas, uint16_t index) override
////        {
////            if (!this->iterator.IsValid())
////                return false;
////
  // Check that the quality of the measurement fits with the CTO variation
////            if (this->cto.quality == TimestampQuality::SYNCHRONIZED)
////            {
////                if (meas.time.quality != TimestampQuality::SYNCHRONIZED)
////                    return false;
////            }
////            else
////            {
////                if (meas.time.quality == TimestampQuality::SYNCHRONIZED)
////                    return false;
////            }
////
////            // can't encode timestamps that go backwards
////            if (meas.time.value < this->cto.value)
////                return false;
////
////            const auto diff = meas.time.value - this->cto.value;

  // can't encode timestamps where the diff is greater than uint16_t
////            if (diff > ser4cpp::UInt16::max_value)
////                return false;
////
////            auto copy = meas;
////            copy.time = DNPTime(diff);
////
////            return this->iterator.Write(copy, index);
////        }
} CTOEventWriter_for_Binary_Group51Var2;

void CTOEventWriter_for_Binary_Group51Var2_in_CTOEventWriter_for_Binary_Group51Var2(CTOEventWriter_for_Binary_Group51Var2 *pCTOEventWriter_for_Binary_Group51Var2,
    Group51Var2* cto,
    HeaderWriter* writer,
    DNP3Serializer_for_Binary* serializer);
boolean Write_in_CTOEventWriter_for_Binary_Group51Var2_override(void* pIEventWriter_for_Binary, Binary* meas, uint16_t index);


#endif
