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
#include "header.h"
#include "CommandResponseHandler.h"

#include "Group12.h"
#include "Group41.h"
#include <string.h>

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

void CommandResponseHandler_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"CommandResponseHandler_in_CommandResponseHandler1"<<'\n';
  decrement_stack_info();
#endif

  IAPDUHandler_in_IAPDUHandler(&(pCommandResponseHandler->iIAPDUHandler));

  pCommandResponseHandler->pCommandAction = pCommandAction_;
  pCommandResponseHandler->numRequests = 0;
  pCommandResponseHandler->numSuccess = 0;
  pCommandResponseHandler->maxCommands = maxCommands_;
  pCommandResponseHandler->pWriter = pWriter_;

  (pCommandResponseHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_CommandResponseHandler_override;

  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandResponseHandler_override;

  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandResponseHandler_override;
//      (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_Indexed_AnalogOutputDouble64_in_IAPDUHandler =
//                                     ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_CommandResponseHandler_override;

  setParentPointer_in_IWhiteList(&((pCommandResponseHandler->iIAPDUHandler).iIWhiteList), pCommandResponseHandler);
  setParentPointer_in_IAPDUHandler(&(pCommandResponseHandler->iIAPDUHandler), pCommandResponseHandler);
}

boolean IsAllowed_in_CommandResponseHandler_override(void *v, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(v);
  UNUSED(headerCount);
  if (!(qc == QualifierCode_UINT8_CNT_UINT8_INDEX || qc == QualifierCode_UINT16_CNT_UINT16_INDEX))
  {
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

boolean AllCommandsSuccessful_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler)
{
  return pCommandResponseHandler->numRequests == pCommandResponseHandler->numSuccess;
}

//---------------------------------------ControlRelayOutputBlock----------------------------------------------------------
CommandStatus_uint8_t ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    ControlRelayOutputBlock* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler1"<<'\n';
#endif

  if (pCommandResponseHandler->numRequests < pCommandResponseHandler->maxCommands)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler2"<<'\n';
#endif
    ++(pCommandResponseHandler->numRequests);
//CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_ICommandAction(ICommandAction *, ControlRelayOutputBlock* arCommand, uint16_t aIndex);
////        return pCommandAction->Action(command, index);
    CommandStatus_uint8_t tmp = Action_ControlRelayOutputBlock_in_ICommandAction(pCommandResponseHandler->pCommandAction, command, index);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler3"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_uint8_t tmp = "<<(uint16_t)tmp<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_TOO_MANY_OPS"<<'\n';
    decrement_stack_info();
#endif
    return CommandStatus_TOO_MANY_OPS;
  }
}
//---------------------------------------ControlRelayOutputBlock----------------------------------------------------------
//---------------------------------------AnalogOutputInt16----------------------------------------------------------
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputInt16* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler1"<<'\n';
#endif

  if (pCommandResponseHandler->numRequests < pCommandResponseHandler->maxCommands)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler2"<<'\n';
#endif
    ++(pCommandResponseHandler->numRequests);
//CommandStatus_uint8_t Action_AnalogOutputInt16_in_ICommandAction(ICommandAction *, AnalogOutputInt16* arCommand, uint16_t aIndex);
////        return pCommandAction->Action(command, index);
    CommandStatus_uint8_t tmp = Action_AnalogOutputInt16_in_ICommandAction(pCommandResponseHandler->pCommandAction, command, index);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler3"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_uint8_t tmp = "<<(uint16_t)tmp<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_TOO_MANY_OPS"<<'\n';
    decrement_stack_info();
#endif
    return CommandStatus_TOO_MANY_OPS;
  }
}
//---------------------------------------AnalogOutputInt16----------------------------------------------------------
//---------------------------------------AnalogOutputInt32----------------------------------------------------------
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputInt32* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessCommand_for_AnalogOutputInt32_in_CommandResponseHandler1"<<'\n';
#endif

  if (pCommandResponseHandler->numRequests < pCommandResponseHandler->maxCommands)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_AnalogOutputInt32_in_CommandResponseHandler2"<<'\n';
#endif
    ++(pCommandResponseHandler->numRequests);
//CommandStatus_uint8_t Action_AnalogOutputInt32_in_ICommandAction(ICommandAction *, AnalogOutputInt32* arCommand, uint16_t aIndex);
////        return pCommandAction->Action(command, index);
    CommandStatus_uint8_t tmp = Action_AnalogOutputInt32_in_ICommandAction(pCommandResponseHandler->pCommandAction, command, index);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_AnalogOutputInt32_in_CommandResponseHandler3"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_uint8_t tmp = "<<(uint16_t)tmp<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_TOO_MANY_OPS"<<'\n';
    decrement_stack_info();
#endif
    return CommandStatus_TOO_MANY_OPS;
  }
}
//---------------------------------------AnalogOutputInt32----------------------------------------------------------
//---------------------------------------AnalogOutputFloat32----------------------------------------------------------
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputFloat32* command, uint16_t index)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessCommand_for_AnalogOutputFloat32_in_CommandResponseHandler1"<<'\n';
#endif

  if (pCommandResponseHandler->numRequests < pCommandResponseHandler->maxCommands)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_AnalogOutputFloat32_in_CommandResponseHandler2"<<'\n';
#endif
    ++(pCommandResponseHandler->numRequests);
//CommandStatus_uint8_t Action_AnalogOutputFloat32_in_ICommandAction(ICommandAction *, AnalogOutputFloat32* arCommand, uint16_t aIndex);
////        return pCommandAction->Action(command, index);
    CommandStatus_uint8_t tmp = Action_AnalogOutputFloat32_in_ICommandAction(pCommandResponseHandler->pCommandAction, command, index);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"ProcessCommand_for_AnalogOutputFloat32_in_CommandResponseHandler3"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_uint8_t tmp = "<<(uint16_t)tmp<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*CommandStatus_TOO_MANY_OPS"<<'\n';
    decrement_stack_info();
#endif
    return CommandStatus_TOO_MANY_OPS;
  }
}
//---------------------------------------AnalogOutputFloat32----------------------------------------------------------

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<ControlRelayOutputBlock>>& meas)
////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
///                                                           const ICollection<Indexed<AnalogOutputInt16>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                     Group41Var2::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputInt32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt32, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                     Group41Var1::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputFloat32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputFloat32, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                       Group41Var3::Inst(), meas);
///}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputDouble64>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputDouble64, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                        Group41Var4::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<ControlRelayOutputBlock>>& meas)
////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputInt16>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                    Group41Var2::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputInt32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt32, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                    Group41Var1::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputFloat32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputFloat32, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                      Group41Var3::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputDouble64>>& meas)
///{
////    return this->RespondToHeader<AnalogOutputDouble64, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                       Group41Var4::Inst(), meas);
////}

////} // namespace opendnp3

