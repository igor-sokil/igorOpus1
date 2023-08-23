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
//#include <QtWidgets>
#include "header.h"
#include "APDUBuilders.h"

////#include "gen/objects/Group60.h"

////#include "opendnp3/app/IINField.h"

////#include <ser4cpp/serialization/LittleEndian.h>

#include "Group60.h"

#include "IINField.h"

////namespace opendnp3
/////{
////namespace build
////{

void ReadIntegrity_in_APDUBuilders_static(APDURequest* request, ClassField* classes, uint8_t seq)
{
  ClassRequest_in_APDUBuilders_static(request, FunctionCode_READ, classes, seq);
}

void ReadAllObjects_in_APDUBuilders_static(APDURequest* request, GroupVariationID gvId, uint8_t seq)
{
//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
//  void AppControlField_in_AppControlFieldOver4(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq);
////        request.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), aAppControlField);
//  void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////        request.SetFunction(FunctionCode::READ);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_READ);
//  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////        auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));
//    boolean WriteHeader_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc);
////        writer.WriteHeader(gvId, QualifierCode::ALL_OBJECTS);
  WriteHeader_in_HeaderWriter(&writer, gvId, QualifierCode_ALL_OBJECTS);
}

void ClassRequest_in_APDUBuilders_static(APDURequest* request, FunctionCode_uint8_t fc,  ClassField* classes, uint8_t seq)
{
///        request.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), aAppControlField);
////        request.SetFunction(fc);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), fc);
////        auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));
//    bool WriteClassHeaders_in_APDUBuilders_static(HeaderWriter& writer, const ClassField& classes)
////        WriteClassHeaders(writer, classes);
  WriteClassHeaders_in_APDUBuilders_static(&writer, classes);
}

bool WriteClassHeaders_in_APDUBuilders_static(HeaderWriter* writer, ClassField* classes)
{
//  boolean HasClass1_in_ClassField(ClassField *pClassField);
////        if (classes.HasClass1())
  if(HasClass1_in_ClassField(classes))
  {
//   GroupVariationID ID_in_Group60Var2_static(void);
////            if (!writer.WriteHeader(Group60Var2::ID(), QualifierCode::ALL_OBJECTS))
    if(!WriteHeader_in_HeaderWriter(writer, ID_in_Group60Var2_static(), QualifierCode_ALL_OBJECTS))
    {
      return false;
    }
  }
////        if (classes.HasClass2())
  if(HasClass2_in_ClassField(classes))
  {
////            if (!writer.WriteHeader(Group60Var3::ID(), QualifierCode::ALL_OBJECTS))
    if(!WriteHeader_in_HeaderWriter(writer, ID_in_Group60Var3_static(), QualifierCode_ALL_OBJECTS))
    {
      return false;
    }
  }
////        if (classes.HasClass3())
  if(HasClass3_in_ClassField(classes))
  {
////            if (!writer.WriteHeader(Group60Var4::ID(), QualifierCode::ALL_OBJECTS))
    if(!WriteHeader_in_HeaderWriter(writer, ID_in_Group60Var4_static(), QualifierCode_ALL_OBJECTS))
    {
      return false;
    }
  }
////        if (classes.HasClass0())
  if(HasClass0_in_ClassField(classes))
  {
////            if (!writer.WriteHeader(Group60Var1::ID(), QualifierCode::ALL_OBJECTS))
    if(!WriteHeader_in_HeaderWriter(writer, ID_in_Group60Var1_static(), QualifierCode_ALL_OBJECTS))
    {
      return false;
    }
  }

  return true;
}

void DisableUnsolicited_in_APDUBuilders_static(APDURequest* request, uint8_t seq)
{
//  ClassField  AllEventClasses_in_ClassField_static(void);
  ClassField temp = AllEventClasses_in_ClassField_static();
  ClassRequest_in_APDUBuilders_static(request, FunctionCode_DISABLE_UNSOLICITED, &temp, seq);
}

////    void EnableUnsolicited(APDURequest& request, const ClassField& classes, uint8_t seq)
void EnableUnsolicited_in_APDUBuilders_static(APDURequest* request, ClassField* classes, uint8_t seq)
{
  ClassRequest_in_APDUBuilders_static(request, FunctionCode_ENABLE_UNSOLICITED, classes, seq);
}

void ClearRestartIIN_in_APDUBuilders_static(APDURequest* request, uint8_t seq)
{
//  void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////        request.SetFunction(FunctionCode::WRITE);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_WRITE);

//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
//  void AppControlField_in_AppControlFieldOver4(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq);
////        request.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), aAppControlField);

//  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////        auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));

//    BitfieldRangeWriteIterator_for_UInt8 IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//                                                                    GroupVariationID id,
//                                                                    QualifierCode_uint8_t qc,
//                                                                    uint8_t start);
//    void GroupVariationID_in_GroupVariationIDOver2(GroupVariationID *pGroupVariationID, uint8_t aGroup, uint8_t aVariation);
////        auto iter = writer.IterateOverSingleBitfield<ser4cpp::UInt8>(
////            GroupVariationID(80, 1), QualifierCode::UINT8_START_STOP, static_cast<uint8_t>(IINBit::DEVICE_RESTART));
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 80, 1);
  BitfieldRangeWriteIterator_for_UInt8 iter = IterateOverSingleBitfield_for_UInt8_in_HeaderWriter(&writer,
      gGroupVariationID,
      QualifierCode_UINT8_START_STOP,
      IINBit_DEVICE_RESTART);
//    boolean Write_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8, boolean value);
////        iter.Write(false);
  Write_in_BitfieldRangeWriteIterator_for_UInt8(&iter, false);
  BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8(&iter);
}

void MeasureDelay_in_APDUBuilders_static(APDURequest* request, uint8_t seq)
{
//  void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////        request.SetFunction(FunctionCode::DELAY_MEASURE);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_DELAY_MEASURE);
//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
//  AppControlField Request_in_AppControlField_static(uint8_t seq);
////        request.SetControl(AppControlField::Request(seq));
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));
}

void RecordCurrentTime_in_APDUBuilders_static(APDURequest* request, uint8_t seq)
{
////        request.SetFunction(FunctionCode::RECORD_CURRENT_TIME);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_RECORD_CURRENT_TIME);
////        request.SetControl(AppControlField::Request(seq));
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));
}

void NullUnsolicited_in_APDUBuilders_static(APDUResponse* response, uint8_t seq, IINField* iin)
{
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, true, true, seq);
////        response.SetControl(AppControlField(true, true, true, true, seq));
  SetControl_in_APDUWrapper(&(response->aAPDUWrapper), aAppControlField);
////        response.SetFunction(FunctionCode::UNSOLICITED_RESPONSE);
  SetFunction_in_APDUWrapper(&(response->aAPDUWrapper), FunctionCode_UNSOLICITED_RESPONSE);
//    void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
////        response.SetIIN(iin);
  SetIIN_in_APDUResponse(response, iin);
}

////} // namespace build
////} // namespace opendnp3
