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
////#include "opendnp3/master/HeaderTypes.h"

////#include "app/HeaderWriter.h"

#include "header.h"
#include "HeaderTypes.h"

////namespace opendnp3
////{

////Header Header::AllObjects(uint8_t group, uint8_t variation)
Header AllObjects_in_Header_static(uint8_t group, uint8_t variation)
{
////    return Header(group, variation);
  Header hHeader;
  Header_in_HeaderOver2(&hHeader, group, variation);
  return hHeader;
}

////Header Header::From(PointClass pc)
Header From_in_Header_static(PointClass_uint8_t pc)
{
  switch (pc)
  {
  case (PointClass_Class0):
////        return Header::AllObjects(60, 1);
    return AllObjects_in_Header_static(60, 1);

  case (PointClass_Class1):
////        return Header::AllObjects(60, 2);
    return AllObjects_in_Header_static(60, 2);

  case (PointClass_Class2):
////        return Header::AllObjects(60, 3);
    return AllObjects_in_Header_static(60, 3);

  default:
////        return Header::AllObjects(60, 4);
    return AllObjects_in_Header_static(60, 4);

  }
}

////Header Header::Range8(uint8_t group, uint8_t variation, uint8_t start, uint8_t stop)
Header Range8_in_Header_static(uint8_t group, uint8_t variation, uint8_t start, uint8_t stop)
{
//  void Header_in_HeaderOver3(Header *pHeader, uint8_t group, uint8_t var, uint8_t start, uint8_t stop);
////  return Header(group, variation, start, stop);
  Header hHeader;
  Header_in_HeaderOver3(&hHeader, group, variation, start, stop);
  return hHeader;
}

////Header Header::Range16(uint8_t group, uint8_t variation, uint16_t start, uint16_t stop)
Header Range16_in_Header_static(uint8_t group, uint8_t variation, uint16_t start, uint16_t stop)
{
//  void Header_in_HeaderOver4(Header *pHeader, uint8_t group, uint8_t var, uint16_t start, uint16_t stop);
////  return Header(group, variation, start, stop);
  Header hHeader;
  Header_in_HeaderOver4(&hHeader, group, variation, start, stop);
  return hHeader;
}

////Header Header::Count8(uint8_t group, uint8_t variation, uint8_t count)
Header Count8_in_Header_static(uint8_t group, uint8_t variation, uint8_t count)
{
//  void Header_in_HeaderOver5(Header *pHeader, uint8_t group, uint8_t var, uint8_t count);
////  return Header(group, variation, count);
  Header hHeader;
  Header_in_HeaderOver5(&hHeader, group, variation, count);
  return hHeader;
}

////Header Header::Count16(uint8_t group, uint8_t variation, uint16_t count)
Header Count16_in_Header_static(uint8_t group, uint8_t variation, uint16_t count)
{
//  void Header_in_HeaderOver6(Header *pHeader, uint8_t group, uint8_t var, uint16_t count);
////  return Header(group, variation, count);
  Header hHeader;
  Header_in_HeaderOver6(&hHeader, group, variation, count);
  return hHeader;
}

////Header::Header(uint8_t group, uint8_t var) : id(group, var), type(HeaderType::AllObjects) {}
void Header_in_HeaderOver2(Header *pHeader, uint8_t group, uint8_t var)
{
  GroupVariationID_in_GroupVariationIDOver2(&(pHeader->id), group, var);
  pHeader->type = HeaderType_AllObjects;
}

////Header::Header(uint8_t group, uint8_t var, uint8_t start, uint8_t stop) : id(group, var), type(HeaderType::Ranged8)
void Header_in_HeaderOver3(Header *pHeader, uint8_t group, uint8_t var, uint8_t start, uint8_t stop)
{
  GroupVariationID_in_GroupVariationIDOver2(&(pHeader->id), group, var);
  pHeader->value.range8 = {start, stop};
  pHeader->type = HeaderType_Ranged8;
}

////Header::Header(uint8_t group, uint8_t var, uint16_t start, uint16_t stop) : id(group, var), type(HeaderType::Ranged16)
void Header_in_HeaderOver4(Header *pHeader, uint8_t group, uint8_t var, uint16_t start, uint16_t stop)
{
  GroupVariationID_in_GroupVariationIDOver2(&(pHeader->id), group, var);
  pHeader->value.range16 = {start, stop};
  pHeader->type = HeaderType_Ranged16;
}

////Header::Header(uint8_t group, uint8_t var, uint8_t count) : id(group, var), type(HeaderType::LimitedCount8)
void Header_in_HeaderOver5(Header *pHeader, uint8_t group, uint8_t var, uint8_t count)
{
  GroupVariationID_in_GroupVariationIDOver2(&(pHeader->id), group, var);
  pHeader->value.count8.value = count;
  pHeader->type = HeaderType_LimitedCount8;
}

////Header::Header(uint8_t group, uint8_t var, uint16_t count) : id(group, var), type(HeaderType::LimitedCount16)
void Header_in_HeaderOver6(Header *pHeader, uint8_t group, uint8_t var, uint16_t count)
{
  GroupVariationID_in_GroupVariationIDOver2(&(pHeader->id), group, var);
  pHeader->value.count16.value = count;
  pHeader->type = HeaderType_LimitedCount16;
}

////bool Header::WriteTo(HeaderWriter& writer) const
boolean WriteTo_in_Header(Header *pHeader, HeaderWriter* writer)
{
  switch (pHeader->type)
  {
  case (HeaderType_AllObjects):
////        return writer.WriteHeader(id, QualifierCode::ALL_OBJECTS);
    return WriteHeader_in_HeaderWriter(writer, pHeader->id, QualifierCode_ALL_OBJECTS);

  case (HeaderType_Ranged8):
////        return writer.WriteRangeHeader<ser4cpp::UInt8>(QualifierCode::UINT8_START_STOP, id, value.range8.start,
////                                                       value.range8.stop);
    return WriteRangeHeader_for_UInt8_in_HeaderWriter(writer, QualifierCode_UINT8_START_STOP,
           pHeader->id,
           pHeader->value.range8.start,
           pHeader->value.range8.stop);

  case (HeaderType_Ranged16):
////        return writer.WriteRangeHeader<ser4cpp::UInt16>(QualifierCode::UINT16_START_STOP, id, value.range16.start,
////                                                        value.range16.stop);
    return WriteRangeHeader_for_UInt16_in_HeaderWriter(writer, QualifierCode_UINT16_START_STOP,
           pHeader->id,
           pHeader->value.range16.start,
           pHeader->value.range16.stop);

  case (HeaderType_LimitedCount8):
////        return writer.WriteCountHeader<ser4cpp::UInt8>(QualifierCode::UINT8_CNT, id, value.count8.value);
    return WriteCountHeader_for_UInt8_in_HeaderWriter(writer, QualifierCode_UINT8_CNT,
           pHeader->id, pHeader->value.count8.value);


  case (HeaderType_LimitedCount16):
////        return writer.WriteCountHeader<ser4cpp::UInt16>(QualifierCode::UINT16_CNT, id, value.count16.value);
    return WriteCountHeader_for_UInt16_in_HeaderWriter(writer, QualifierCode_UINT16_CNT,
           pHeader->id, pHeader->value.count16.value);

  default:
    return false;
  }
}
////} // namespace opendnp3
void Header_in_HeaderOver1(Header *pHeader)
{
  pHeader->type = HeaderType_AllObjects;
}
