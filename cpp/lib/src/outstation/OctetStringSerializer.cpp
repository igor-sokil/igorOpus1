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
#include "OctetStringSerializer.h"
#include <string.h>

//-----------------------------DNP3Serializer_for_OctetString-------------------------------------------
////    DNP3Serializer(GroupVariationID id,
////                   size_t size,
////                   typename Serializer<T>::read_func_t read_func,
////                   typename Serializer<T>::write_func_t write_func)
////        : Serializer<T>(size, read_func, write_func), id(id)
void DNP3Serializer_for_OctetString_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString,
    GroupVariationID id,
    uint16_t size,
////                   typename Serializer<T>::read_func_t read_func,
    read_func_t_in_Serializer_for_OctetString read_func,
////                   typename Serializer<T>::write_func_t write_func)
    write_func_t_in_Serializer_for_OctetString write_func)
{
//   void Serializer_for_OctetString_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString,
//                                               uint16_t size,
//                                               read_func_t_in_Serializer_for_OctetString read_func,
//                                               write_func_t_in_Serializer_for_OctetString write_func);
  Serializer_for_OctetString_in_Serializer_for_OctetString(&(pDNP3Serializer_for_OctetString->sSerializer_for_OctetString),
      size,
      read_func,
      write_func
                                                          );
  pDNP3Serializer_for_OctetString->id = id;

}

////    GroupVariationID ID() const
////    {
////        return id;
////    }
    GroupVariationID ID_in_DNP3Serializer_for_OctetString(DNP3Serializer_for_OctetString *pDNP3Serializer_for_OctetString) 
{
    return pDNP3Serializer_for_OctetString->id;
}

////namespace opendnp3
////{
////OctetStringSerializer::OctetStringSerializer(bool isEvent, uint8_t size)
void OctetStringSerializer_in_OctetStringSerializer(OctetStringSerializer *pOctetStringSerializer, boolean isEvent, uint8_t size)
{
////    : DNP3Serializer(GroupVariationID(isEvent ? 111 : 110, size),
////                     size,
////                     nullptr, // won't be used for reading
////                     &OctetStringSerializer::Write)
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, isEvent ? 111 : 110, size);

  DNP3Serializer_for_OctetString_in_DNP3Serializer_for_OctetString(&(pOctetStringSerializer->dDNP3Serializer_for_OctetString),
      gGroupVariationID,
      size,
////                   typename Serializer<T>::read_func_t read_func,
      NULL,// read_func_t_in_Serializer_for_Binary,
////                   typename Serializer<T>::write_func_t write_func)
////                    write_func_t_in_Serializer_for_OctetString write_func);//write_func_t_in_Serializer_for_Binary);
      Write_in_OctetStringSerializer_static);
//  boolean Write_in_OctetStringSerializer_static(OctetString* value, WSeq_for_Uint16_t* buffer);
//   typedef boolean (*write_func_t_in_Serializer_for_OctetString)(OctetString *value, WSeq_for_Uint16_t *buffer);
}

////bool OctetStringSerializer::Write(const OctetString& value, ser4cpp::wseq_t& buffer)
boolean Write_in_OctetStringSerializer_static(OctetString* value, WSeq_for_Uint16_t* buffer)
{
//   uint16_t Size_in_OctetData(OctetData *pOctetData);
////    if (value.Size() > buffer.length())
//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
  if(Size_in_OctetData(&(value->oOctetData)) > length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)))
  {
    return false;
  }
//   Buffer  ToBuffer_in_OctetData(OctetData *pOctetData);
////    const auto value_buffer = value.ToBuffer();
  Buffer value_buffer = ToBuffer_in_OctetData(&(value->oOctetData));
//    void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(RSeq_for_Uint16_t *pRSeq, uint8_t * buffer, uint16_t length);
////    const ser4cpp::rseq_t slice(value_buffer.data, value_buffer.length);
  RSeq_for_Uint16_t slice;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&slice, value_buffer.data, value_buffer.length);
//    RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////    buffer.copy_from(slice);
  copy_from_in_WSeq_for_Uint16_t(buffer, &slice);
  return true;
}
//-----------------------------DNP3Serializer_for_OctetString-------------------------------------------
////}; // namespace opendnp3
