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
#include <QApplication>
#include "header.h"
#include "APDUHexBuilders.h"

#include "BufferHelpers.h"

#include "AppConstants.h"

#include "BufferSer4.h"
#include "HexConversions.h"

#include "APDUBuilders.h"
#include "APDURequest.h"
#include "APDUResponse.h"
#include "Group12.h"
#include "HeaderWriter_for_ControlRelayOutputBlock.h"

////using namespace opendnp3;
////using namespace ser4cpp;

////namespace hex
////{

std::string repeat_in_APDUHexBuilders(uint8_t value, uint16_t count)
{
  BufferSer4 buffer;//(count);
  BufferSer4_in_BufferSer4Over2(&buffer, count);

//void set_all_to_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint8_t value);
//WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    buffer.as_wslice().set_all_to(value);
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  set_all_to_in_WSeq_for_Uint16_t(&temp, value);

//std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
//RSeq_for_Uint16_t as_rslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    return HexConversions::to_hex(buffer.as_rslice());
  RSeq_for_Uint16_t tmp = as_rslice_in_BufferSer4(&buffer);
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string ClassTask_in_APDUHexBuilders(FunctionCode_uint8_t fc, uint8_t seq, ClassField* field)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDURequest request(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDURequest request;
  APDURequest_in_APDURequestOver2(&request, &temp);

//void ClassRequest_in_APDUBuilders_static(APDURequest* request, FunctionCode_uint8_t fc,  ClassField* classes, uint8_t seq)
////    opendnp3::build::ClassRequest(request, fc, field, seq);
  ClassRequest_in_APDUBuilders_static(&request, fc,  field, seq);

//RSeq_for_Uint16_t ToRSeq_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    return HexConversions::to_hex(request.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string DisableUnsol_in_APDUHexBuilders(uint8_t seq, ClassField* field)
{
  return ClassTask_in_APDUHexBuilders(FunctionCode_DISABLE_UNSOLICITED, seq, field);
}

std::string IntegrityPoll_in_APDUHexBuilders(uint8_t seq, ClassField* field)
{
  return ClassTask_in_APDUHexBuilders(FunctionCode_READ, seq, field);
}

std::string ClassPoll_in_APDUHexBuilders(uint8_t seq, PointClass_uint8_t pc)
{
//void ClassField_in_ClassFieldOver2(ClassField *pClassField, PointClass_uint8_t pc);
  ClassField cClassField;
  ClassField_in_ClassFieldOver2(&cClassField, pc);
  return ClassTask_in_APDUHexBuilders(FunctionCode_READ, seq, &cClassField);
}

std::string EventPoll_in_APDUHexBuilders(uint8_t seq, ClassField field)
{
  return ClassTask_in_APDUHexBuilders(FunctionCode_READ, seq, &field);
}

std::string ClearRestartIIN_in_APDUHexBuilders(uint8_t seq)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDURequest request(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDURequest request;
  APDURequest_in_APDURequestOver2(&request, &temp);

//void ClearRestartIIN_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);
////    build::ClearRestartIIN(request, seq);
  ClearRestartIIN_in_APDUBuilders_static(&request, seq);

////    return HexConversions::to_hex(request.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string MeasureDelay_in_APDUHexBuilders(uint8_t seq)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDURequest request(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDURequest request;
  APDURequest_in_APDURequestOver2(&request, &temp);

////    build::MeasureDelay(request, seq);
  MeasureDelay_in_APDUBuilders_static(&request, seq);// = 0);

////    return HexConversions::to_hex(request.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string RecordCurrentTime_in_APDUHexBuilders(uint8_t seq)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDURequest request(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDURequest request;
  APDURequest_in_APDURequestOver2(&request, &temp);

//void RecordCurrentTime_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);
////    build::RecordCurrentTime(request, seq);
  RecordCurrentTime_in_APDUBuilders_static(&request, seq);

////    return HexConversions::to_hex(request.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string Control_in_APDUHexBuilders(FunctionCode_uint8_t code,
                                       uint8_t seq,
                                       ControlRelayOutputBlock* crob,
                                       uint16_t index)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDURequest request(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDURequest request;
  APDURequest_in_APDURequestOver2(&request, &temp);

//AppControlField Request_in_AppControlField_static(uint8_t seq);
//void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////    request.SetControl(AppControlField::Request(seq));
  AppControlField tmp = Request_in_AppControlField_static(seq);
  SetControl_in_APDUWrapper(&(request.aAPDUWrapper), tmp);

//void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////    request.SetFunction(code);
  SetFunction_in_APDUWrapper(&(request.aAPDUWrapper), code);

//HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request.aAPDUWrapper));

//boolean WriteSingleIndexedValue_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
//    ControlRelayOutputBlock* value,
//    uint16_t index);
//DNP3Serializer_for_ControlRelayOutputBlock  Inst_in_Group12Var1_static(void)
////    writer.WriteSingleIndexedValue<UInt16, ControlRelayOutputBlock>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                    Group12Var1::Inst(), crob, index);
  DNP3Serializer_for_ControlRelayOutputBlock ser = Inst_in_Group12Var1_static();
  WriteSingleIndexedValue_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(&writer,
      QualifierCode_UINT16_CNT_UINT16_INDEX,
      &ser,
      crob,
      index);

////    return HexConversions::to_hex(request.ToRSeq());
  RSeq_for_Uint16_t mp = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&mp, true);
}

std::string EmptyResponse_in_APDUHexBuilders(uint8_t seq, IINField* iin)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDUResponse response(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDUResponse response;
  APDUResponse_in_APDUResponse(&response, &temp);

////    response.SetFunction(FunctionCode::RESPONSE);
  SetFunction_in_APDUWrapper(&(response.aAPDUWrapper), FunctionCode_RESPONSE);

//void AppControlField_in_AppControlFieldOver4(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq);
//void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////    response.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(response.aAPDUWrapper), aAppControlField);

//void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
////    response.SetIIN(iin);
  SetIIN_in_APDUResponse(&response, iin);

////    return HexConversions::to_hex(response.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string NullUnsolicited_in_APDUHexBuilders(uint8_t seq, IINField* iin)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDUResponse response(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDUResponse response;
  APDUResponse_in_APDUResponse(&response, &temp);

//void NullUnsolicited_in_APDUBuilders_static(APDUResponse* response, uint8_t seq, IINField* iin);
////    build::NullUnsolicited(response, seq, iin);
  NullUnsolicited_in_APDUBuilders_static(&response, seq, iin);

////    return HexConversions::to_hex(response.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(response.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

std::string SolicitedConfirm_in_APDUHexBuilders(uint8_t seq)
{
  return Confirm_in_APDUHexBuilders(seq, false);
}

std::string UnsolConfirm_in_APDUHexBuilders(uint8_t seq)
{
  return Confirm_in_APDUHexBuilders(seq, true);
}

std::string Confirm_in_APDUHexBuilders(uint8_t seq, boolean unsol)
{
  BufferSer4 buffer;//(DEFAULT_MAX_APDU_SIZE);
  BufferSer4_in_BufferSer4Over2(&buffer, DEFAULT_MAX_APDU_SIZE);

////    APDURequest apdu(buffer.as_wslice());
  WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
  APDURequest apdu;
  APDURequest_in_APDURequestOver2(&apdu, &temp);

////    apdu.SetControl(AppControlField(true, true, false, unsol, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, unsol, seq);
  SetControl_in_APDUWrapper(&(apdu.aAPDUWrapper), aAppControlField);

////    apdu.SetFunction(FunctionCode::CONFIRM);
  SetFunction_in_APDUWrapper(&(apdu.aAPDUWrapper), FunctionCode_CONFIRM);
////    return HexConversions::to_hex(apdu.ToRSeq());
  RSeq_for_Uint16_t tmp = ToRSeq_in_APDUWrapper(&(apdu.aAPDUWrapper));
  return to_hex_in_HexConversionsOver2(&tmp, true);
}

////} // namespace hex
