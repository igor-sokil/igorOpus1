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
#include "EventWriters_for_OctetString.h"
#include "OctetStringSerializer.h"
#include "PrefixedWriteIterator_for_OctetString.h"
#include "HeaderWriter_for_OctetString.h"

////namespace opendnp3
////{

////class OctetStringEventWriter : public IEventWriter<OctetString>
typedef struct
{
    IEventWriter_for_OctetString iIEventWriter_for_OctetString;
    OctetStringSerializer serializer;
////    PrefixedWriteIterator<ser4cpp::UInt16, OctetString> iterator;
    PrefixedWriteIterator_for_UInt16_OctetString iterator;

////public:
////    OctetStringEventWriter(HeaderWriter& writer, uint8_t size)
////        : serializer(true, size),
////          iterator(
////              writer.IterateOverCountWithPrefix<ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX, serializer))
////    {
////    }

////    bool Write(const OctetString& meas, uint16_t index) override
////    {
////        if (meas.Size() != this->serializer.get_size())
////            return false;

////        return iterator.Write(meas, index);
////    }
} OctetStringEventWriter;

    boolean Write_in_OctetStringEventWriter_for_OctetString_override(void *pIEventWriter_for_OctetString, OctetString* meas, uint16_t index)
    {
//   uint16_t Size_in_OctetData(OctetData *pOctetData);
//   uint16_t get_size_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString);
////        if (meas.Size() != this->serializer.get_size())
    OctetStringEventWriter* tempOctetStringEventWriter = (OctetStringEventWriter*) getParentPointer_in_IEventWriter_for_OctetString((IEventWriter_for_OctetString*) pIEventWriter_for_OctetString);
    OctetStringSerializer* tempSerializer = &(tempOctetStringEventWriter->serializer);
    PrefixedWriteIterator_for_UInt16_OctetString* tempIterator = &(tempOctetStringEventWriter->iterator);

   if(Size_in_OctetData(&(meas->oOctetData)) != get_size_in_Serializer_for_OctetString(&(
                                                tempSerializer->
                                                dDNP3Serializer_for_OctetString.sSerializer_for_OctetString))
                                                )
            return false;

//    boolean Write_in_PrefixedWriteIterator_for_UInt16_OctetString(PrefixedWriteIterator_for_UInt16_OctetString *pPrefixedWriteIterator_for_UInt16_OctetString,
//                                                                  OctetString* value, uint16_t index);
////        return iterator.Write(meas, index);
    return Write_in_PrefixedWriteIterator_for_UInt16_OctetString(tempIterator,
                                                                  meas, index);
    }

  void  OctetStringEventWriter_in_OctetStringEventWriter(OctetStringEventWriter *pOctetStringEventWriter, HeaderWriter* writer, uint8_t size)
{
//  boolean (*pWrite_in_IEventWriter_for_OctetString)(void*, OctetString* meas, uint16_t index);// = 0;
  (pOctetStringEventWriter->iIEventWriter_for_OctetString).pWrite_in_IEventWriter_for_OctetString = Write_in_OctetStringEventWriter_for_OctetString_override;
  setParentPointer_in_IEventWriter_for_OctetString(&(pOctetStringEventWriter->iIEventWriter_for_OctetString), pOctetStringEventWriter);

//void OctetStringSerializer_in_OctetStringSerializer(OctetStringSerializer *pOctetStringSerializer, boolean isEvent, uint8_t size);
////        : serializer(true, size),
 OctetStringSerializer_in_OctetStringSerializer(&(pOctetStringEventWriter->serializer), true, size);

//  PrefixedWriteIterator_for_UInt16_OctetString IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, DNP3Serializer_for_OctetString* serializer);
////          iterator(
////              writer.IterateOverCountWithPrefix<ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX, serializer))
  PrefixedWriteIterator_for_UInt16_OctetString temp = IterateOverCountWithPrefix_for_UInt16_OctetString_in_HeaderWriter(writer,
    QualifierCode_UINT16_CNT_UINT16_INDEX, &((pOctetStringEventWriter->serializer).dDNP3Serializer_for_OctetString));
  pOctetStringEventWriter->iterator = temp;
}

////uint16_t EventWriters::Write(uint8_t firstSize, HeaderWriter& writer, IEventCollection<OctetString>& items)
  uint16_t Write_in_EventWriters_static(uint8_t firstSize, HeaderWriter* writer, IEventCollection_for_OctetString* items)
{
//  void  OctetStringEventWriter_in_OctetStringEventWriter(OctetStringEventWriter *pOctetStringEventWriter, HeaderWriter* writer, uint8_t size)
////    OctetStringEventWriter handler(writer, firstSize);
    OctetStringEventWriter handler;
    OctetStringEventWriter_in_OctetStringEventWriter(&handler, writer, firstSize);
//  uint16_t WriteSome_in_IEventCollection_for_OctetString(IEventCollection_for_OctetString *, IEventWriter_for_OctetString* handler);
////    return items.WriteSome(handler);
  return WriteSome_in_IEventCollection_for_OctetString(items, &(handler.iIEventWriter_for_OctetString));
}

////} // namespace opendnp3
