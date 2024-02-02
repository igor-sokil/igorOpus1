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

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "CommandSetOps.h"

#include "APDUParser.h"
#include "CommandTaskResult.h"
#include "ICommandHeader.h"

////#include <algorithm>

////namespace opendnp3
////{

//----------------------------------ControlRelayOutputBlock----------------------------------
////template<class T> IINField CommandSetOps::ProcessAny(const PrefixHeader& header, const ICollection<Indexed<T>>& values)
IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
  if (header->hHeaderRecord.headerIndex >= pCommandSetOps->commands->m_headers.size()) // more response headers than request headers
// больше заголовков ответа, чем заголовков запроса
  {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

  if (pCommandSetOps->mode == Mode_in_CommandSetOps_Select)
  {
//void ApplySelectResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands);
////        commands->m_headers[header.headerIndex]->ApplySelectResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplySelectResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(&itmp, qtmp, values);
  }
  else
  {
////        commands->m_headers[header.headerIndex]->ApplyOperateResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplyOperateResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(&itmp, qtmp, values);
  }

////    return IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------------ControlRelayOutputBlock----------------------------------
//----------------------------------AnalogOutputInt16----------------------------------
////template<class T> IINField CommandSetOps::ProcessAny(const PrefixHeader& header, const ICollection<Indexed<T>>& values)
IINField ProcessAny_for_AnalogOutputInt16_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
{
  if (header->hHeaderRecord.headerIndex >= pCommandSetOps->commands->m_headers.size()) // more response headers than request headers
// больше заголовков ответа, чем заголовков запроса
  {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

  if (pCommandSetOps->mode == Mode_in_CommandSetOps_Select)
  {
//void ApplySelectResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands);
////        commands->m_headers[header.headerIndex]->ApplySelectResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplySelectResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader(&itmp, qtmp, values);
  }
  else
  {
////        commands->m_headers[header.headerIndex]->ApplyOperateResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplyOperateResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader(&itmp, qtmp, values);
  }

////    return IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------------AnalogOutputInt16----------------------------------
//----------------------------------AnalogOutputInt32----------------------------------
////template<class T> IINField CommandSetOps::ProcessAny(const PrefixHeader& header, const ICollection<Indexed<T>>& values)
IINField ProcessAny_for_AnalogOutputInt32_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
{
  if (header->hHeaderRecord.headerIndex >= pCommandSetOps->commands->m_headers.size()) // more response headers than request headers
// больше заголовков ответа, чем заголовков запроса
  {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

  if (pCommandSetOps->mode == Mode_in_CommandSetOps_Select)
  {
//void ApplySelectResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands);
////        commands->m_headers[header.headerIndex]->ApplySelectResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplySelectResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(&itmp, qtmp, values);
  }
  else
  {
////        commands->m_headers[header.headerIndex]->ApplyOperateResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplyOperateResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(&itmp, qtmp, values);
  }

////    return IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------------AnalogOutputInt32----------------------------------
//----------------------------------AnalogOutputFloat32----------------------------------
////template<class T> IINField CommandSetOps::ProcessAny(const PrefixHeader& header, const ICollection<Indexed<T>>& values)
IINField ProcessAny_for_AnalogOutputFloat32_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
{
  if (header->hHeaderRecord.headerIndex >= pCommandSetOps->commands->m_headers.size()) // more response headers than request headers
// больше заголовков ответа, чем заголовков запроса
  {
////        return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

  if (pCommandSetOps->mode == Mode_in_CommandSetOps_Select)
  {
//void ApplySelectResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(ICommandHeader *, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands);
////        commands->m_headers[header.headerIndex]->ApplySelectResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplySelectResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(&itmp, qtmp, values);
  }
  else
  {
////        commands->m_headers[header.headerIndex]->ApplyOperateResponse(header.GetQualifierCode(), values);
    QualifierCode_uint8_t qtmp = GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord));
    ICommandHeader itmp = pCommandSetOps->commands->m_headers[header->hHeaderRecord.headerIndex];
    ApplyOperateResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(&itmp, qtmp, values);
  }

////    return IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------------AnalogOutputFloat32----------------------------------

////CommandSetOps::CommandSetOps(Mode mode_, CommandSet& commands_) : mode(mode_), commands(&commands_) {}

void CommandSetOps_in_CommandSetOps(CommandSetOps *pCommandSetOps, Mode_in_CommandSetOps_uint8_t mode_, CommandSet* commands_)
{
  IAPDUHandler_in_IAPDUHandler(&(pCommandSetOps->iIAPDUHandler));

  pCommandSetOps->iIAPDUHandler.iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_CommandSetOps_override;
  pCommandSetOps->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler =  ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandSetOps_override;
  pCommandSetOps->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler =  ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandSetOps_override;
  pCommandSetOps->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler =  ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandSetOps_override;
  pCommandSetOps->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandSetOps_override;

  setParentPointer_in_IAPDUHandler(&(pCommandSetOps->iIAPDUHandler), pCommandSetOps);

  pCommandSetOps->mode = mode_;
  pCommandSetOps->commands = commands_;
}

////bool CommandSetOps::Write(const CommandSet& set, HeaderWriter& writer, IndexQualifierMode mode)
boolean Write_in_CommandSetOps_static(CommandSet* set, HeaderWriter* writer, IndexQualifierMode_uint8_t mode)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Write_in_CommandSetOps_static1"<<'\n';
#endif
  for (auto& header : set->m_headers)
  {
//boolean Write_in_ICommandHeader(ICommandHeader *, HeaderWriter*, IndexQualifierMode_uint8_t mode);
////        if (!header->Write(writer, mode))
    ICommandHeader tmp = header;
    if (!Write_in_ICommandHeader(&tmp, writer,  mode))
    {
#ifdef  LOG_INFO
      std::cout<<getString_stack_info();
      std::cout<<"}Write_in_CommandSetOps_static1_"<<'\n';
      decrement_stack_info();
#endif
      return false;
    }
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_CommandSetOps_static2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////void CommandSetOps::InvokeCallback(const CommandSet& set, TaskCompletion result, const CommandResultCallbackT& callback)
void InvokeCallback_in_CommandSetOps_static(CommandSet* set, TaskCompletion_uint8_t result, CommandResultCallbackT callback)
{
//typedef void (*CommandResultCallbackT) (ICommandTaskResult*);
//void CommandTaskResult_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult, TaskCompletion_uint8_t result, HeaderVector_in_CommandSet* vector);
////    CommandTaskResult impl(result, set.m_headers);
  CommandTaskResult impl;
  CommandTaskResult_in_CommandTaskResult(&impl, result, &(set->m_headers));
  callback(&(impl.iICommandTaskResult));
}

boolean selected_in_CommandSetOps(ICommandHeader* header);
boolean selected_in_CommandSetOps(ICommandHeader* header)
{
//boolean AreAllSelected_in_ICommandHeader(ICommandHeader *);
////    auto selected = [](const std::shared_ptr<ICommandHeader>& header) -> bool { return header->AreAllSelected(); };
  return AreAllSelected_in_ICommandHeader(header);
}
////CommandSetOps::SelectResult CommandSetOps::ProcessSelectResponse(CommandSet& set,
////                                                                 const ser4cpp::rseq_t& headers,
////                                                                 Logger* logger)
SelectResult_in_CommandSetOps_uint8_t ProcessSelectResponse_in_CommandSetOps_static(CommandSet* set, RSeq_for_Uint16_t* headers)//, Logger* logger)
{
//  void CommandSetOps_in_CommandSetOps(CommandSetOps *pCommandSetOps, Mode_in_CommandSetOps_uint8_t mode_, CommandSet* commands_)
////    CommandSetOps handler(Mode::Select, set);
  CommandSetOps handler;
  CommandSetOps_in_CommandSetOps(&handler, Mode_in_CommandSetOps_Select, set);

  expectsContents = true;
//ParseResult_uint8_t Parse_in_APDUParser_static(
//  RSeq_for_Uint16_t *buffer,
//  IAPDUHandler *handler);
////    const auto result = APDUParser::Parse(headers, handler, logger);
  ParseResult_uint8_t result = Parse_in_APDUParser_static(headers, &(handler.iIAPDUHandler));

  if (result != ParseResult_OK)
  {
    return SelectResult_in_CommandSetOps_FAIL_PARSE;
  }

////    auto selected = [](const std::shared_ptr<ICommandHeader>& header) -> bool { return header->AreAllSelected(); };
////    return std::all_of(set.m_headers.begin(), set.m_headers.end(), selected) ? SelectResult_in_CommandSetOps_OK
////                                                                             : SelectResult_in_CommandSetOps_FAIL_SELECT;
  /*
    return std::all_of(set->m_headers.begin(), set->m_headers.end(), selected_in_CommandSetOps) ?
           SelectResult_in_CommandSetOps_OK
           : SelectResult_in_CommandSetOps_FAIL_SELECT;
  */
  for(uint16_t i=0; i<set->m_headers.size(); i++)
  {
    if(true != selected_in_CommandSetOps(&(set->m_headers[i]))) return SelectResult_in_CommandSetOps_FAIL_SELECT;
  }//for
  return SelectResult_in_CommandSetOps_OK;
}

////CommandSetOps::OperateResult CommandSetOps::ProcessOperateResponse(CommandSet& set,
////                                                                   const ser4cpp::rseq_t& headers,
////                                                                   Logger* logger)
OperateResult_in_CommandSetOps_uint8_t ProcessOperateResponse_in_CommandSetOps_static(CommandSet* set, RSeq_for_Uint16_t* headers)//, Logger* logger);
{
////    CommandSetOps handler(Mode::Operate, set);
  CommandSetOps handler;
  CommandSetOps_in_CommandSetOps(&handler, Mode_in_CommandSetOps_Operate, set);
  expectsContents = true;
////    return (APDUParser::Parse(headers, handler, logger) == ParseResult::OK) ? OperateResult::OK
////                                                                            : OperateResult::FAIL_PARSE;
  return (Parse_in_APDUParser_static(headers, &(handler.iIAPDUHandler)) == ParseResult_OK) ? OperateResult_in_CommandSetOps_OK : OperateResult_in_CommandSetOps_FAIL_PARSE;
}

////bool CommandSetOps::IsAllowed(uint32_t /*headerCount*/, GroupVariation gv, QualifierCode qc)
boolean IsAllowed_in_CommandSetOps(CommandSetOps *pCommandSetOps, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(pCommandSetOps);
  UNUSED(headerCount);
  switch (qc)
  {
  case (QualifierCode_UINT8_CNT_UINT8_INDEX):
  case (QualifierCode_UINT16_CNT_UINT16_INDEX):
    break;
  default:
    return false;
  }

  switch (gv)
  {
  case (GroupVariation_Group12Var1): //	CROB
  case (GroupVariation_Group41Var1): //	4 kinds of AO
  case (GroupVariation_Group41Var2):
  case (GroupVariation_Group41Var3):
  case (GroupVariation_Group41Var4):
    return true;
  default:
    return false;
  }
}

boolean IsAllowed_in_CommandSetOps_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(pIWhiteList);
  return IsAllowed_in_CommandSetOps(NULL, headerCount, gv, qc);
}

////IINField CommandSetOps::ProcessHeader(const PrefixHeader& header,
////                                      const ICollection<Indexed<ControlRelayOutputBlock>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandSetOps(CommandSetOps* pCommandSetOps, PrefixHeader* header,
    ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
//IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values);
////    return this->ProcessAny(header, values);
  return ProcessAny_for_ControlRelayOutputBlock_in_CommandSetOps(pCommandSetOps, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
  CommandSetOps *parent = (CommandSetOps*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandSetOps(parent, header, values);
}

IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandSetOps(CommandSetOps* pCommandSetOps, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt16* values)
{
//IINField ProcessAny_for_AnalogOutputInt16_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values);
////    return this->ProcessAny(header, values);
  return ProcessAny_for_AnalogOutputInt16_in_CommandSetOps(pCommandSetOps, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
{
  CommandSetOps *parent = (CommandSetOps*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandSetOps(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandSetOps(CommandSetOps* pCommandSetOps, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt32* values)
{
//IINField ProcessAny_for_AnalogOutputInt32_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values);
////    return this->ProcessAny(header, values);
  return ProcessAny_for_AnalogOutputInt32_in_CommandSetOps(pCommandSetOps, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
{
  CommandSetOps *parent = (CommandSetOps*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandSetOps(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandSetOps(CommandSetOps* pCommandSetOps, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputFloat32* values)
{
//IINField ProcessAny_for_AnalogOutputFlaot32_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values);
////    return this->ProcessAny(header, values);
  return ProcessAny_for_AnalogOutputFloat32_in_CommandSetOps(pCommandSetOps, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
{
  CommandSetOps *parent = (CommandSetOps*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandSetOps(parent, header, values);
}

////} // namespace opendnp3
