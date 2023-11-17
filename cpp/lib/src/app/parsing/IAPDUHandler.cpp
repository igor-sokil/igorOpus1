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
#include "IAPDUHandler.h"

////namespace opendnp3
////{
void IAPDUHandler_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"IAPDUHandler_in_IAPDUHandler1"<<std::endl;

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pIAPDUHandler= "<<(uint32_t)pIAPDUHandler<<std::endl;
//  std::cout<<"*"<<getString_stack_info();
//  std::cout<<"*pProcessHeader_AllObjectsHeader_in_IAPDUHandler= "<<(uint32_t)(pReadHandler->iIAPDUHandler).pProcessHeader_AllObjectsHeader_in_IAPDUHandler<<std::endl;
  decrement_stack_info();
#endif

  IINField_in_IINFieldOver1(&(pIAPDUHandler->errors));
  pIAPDUHandler->numTotalHeaders = 0;
  pIAPDUHandler->numIgnoredHeaders = 0;

  pIAPDUHandler->pProcessHeader_AllObjectsHeader_in_IAPDUHandler = ProcessHeader_AllObjectsHeader_in_IAPDUHandler_override;

  pIAPDUHandler->pProcessHeader_RangeHeader_in_IAPDUHandler  = ProcessHeader_RangeHeader_in_IAPDUHandler_override;

  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler            = ProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler      = ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler           = ProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler             = ProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler = ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler             = ProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler    = ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler = ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler        = ProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler_override;

  pIAPDUHandler->pProcessHeader_CountHeader_in_IAPDUHandler = ProcessHeader_CountHeader_in_IAPDUHandler_override;

  pIAPDUHandler->pProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler = ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler = ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler_override;

  pIAPDUHandler->pOnHeaderResult_in_IAPDUHandler            =  OnHeaderResult_in_IAPDUHandler_override;

  pIAPDUHandler->pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler = ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler_override;
  pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler_override;

  setParentPointer_in_IAPDUHandler(pIAPDUHandler, pIAPDUHandler);
  setParentPointer_in_IWhiteList(&(pIAPDUHandler->iIWhiteList), pIAPDUHandler);
}

void Reset_in_IAPDUHandlert(IAPDUHandler *pIAPDUHandler)
{
  pIAPDUHandler->numTotalHeaders = 0;
  pIAPDUHandler->numIgnoredHeaders = 0;
//   void Clear_in_IINField(IINField *pIINField);
////    errors.Clear();
  Clear_in_IINField(&(pIAPDUHandler->errors));
}

IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
  return pIAPDUHandler->errors;
}

////void OnHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, AllObjectsHeader* header)
void OnHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, AllObjectsHeader* header)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_AllObjectsHeader_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
//    IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler*, AllObjectsHeader* record);
//    void Record_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, HeaderRecord* record, IINField* result)
////    Record(header, this->ProcessHeader(header));
  IINField temp = ProcessHeader_AllObjectsHeader_in_IAPDUHandler(pIAPDUHandler, header);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header)
void OnHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
//    IINField ProcessHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header);
////    Record(header, this->ProcessHeader(header));
  IINField temp = ProcessHeader_RangeHeader_in_IAPDUHandler(pIAPDUHandler, header);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

/////void IAPDUHandler::OnHeader(const CountHeader& header)
void OnHeader_CountHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_CountHeader_in_IAPDUHandler1"<<'\n';
#endif
//    IINField ProcessHeader_CountHeader_in_IAPDUHandler(IAPDUHandler*, CountHeader* header);
////    Record(header, this->ProcessHeader(header));
  IINField temp = ProcessHeader_CountHeader_in_IAPDUHandler(pIAPDUHandler, header);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group50Var1>& values)
void OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group50Var3>& values)
void OnHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_CountHeader_for_Group50Var3_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group51Var1>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group51Var2>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group52Var1>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const CountHeader& header, const ICollection<Group52Var2>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<IINValue>>& values)
void OnHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_for_IINValue_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<Binary>>& values)
void OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
//    void Record_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, HeaderRecord* record, IINField* result)
//IINField ProcessHeader_RangeHeader_for_Binary_in_IAPDUHandler(IAPDUHandler*, RangeHeader* header, ICollection_Indexed_for_Binary* values);
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values)
void OnHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values)
void OnHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<Counter>>& values)
void OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Counter* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
void OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<Analog>>& values)
void OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Analog* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values)
void OnHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<OctetString>>& values)
void OnHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_OctetString* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const RangeHeader& header, const ICollection<Indexed<TimeAndInterval>>& values)
void OnHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

// --- index prefixes ----

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<Binary>>& values)
void OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryOutputStatus>>& values)
void OnHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<DoubleBitBinary>>& values)
void OnHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<Counter>>& values)
void OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
void OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<Analog>>& values)
void OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputStatus>>& values)
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<OctetString>>& values)
void OnHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<TimeAndInterval>>& values)
void OnHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<BinaryCommandEvent>>& values)
void OnHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogCommandEvent>>& values)
void OnHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<uint16_t>& values)
void OnHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_for_uint16_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

// --- controls ----

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<ControlRelayOutputBlock>>& values)
void OnHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt16>>& values)
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputInt32>>& values)
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputFloat32>>& values)
void OnHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
////    Record(header, this->ProcessHeader(header, values));
  IINField temp = ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler(pIAPDUHandler, header, values);
  Record_in_IAPDUHandler(pIAPDUHandler, &(header->hHeaderRecord), &temp);
}

////void IAPDUHandler::OnHeader(const PrefixHeader& header, const ICollection<Indexed<AnalogOutputDouble64>>& values)
////{
////    Record(header, this->ProcessHeader(header, values));
////}

IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, AllObjectsHeader* record)
{
  return (pIAPDUHandler->pProcessHeader_AllObjectsHeader_in_IAPDUHandler)(pIAPDUHandler, record);
}

IINField ProcessHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header)
{
  return (pIAPDUHandler->pProcessHeader_RangeHeader_in_IAPDUHandler)(pIAPDUHandler, header);
}
IINField ProcessHeader_CountHeader_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header)
{
  return (pIAPDUHandler->pProcessHeader_CountHeader_in_IAPDUHandler)(pIAPDUHandler, header);
}
void OnHeaderResult_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, HeaderRecord* record, IINField* result)
{
  (pIAPDUHandler->pOnHeaderResult_in_IAPDUHandler)(pIAPDUHandler, record, result);
}

////IINField IAPDUHandler::ProcessHeader(const AllObjectsHeader& /*record*/)
IINField ProcessHeader_AllObjectsHeader_in_IAPDUHandler_override(void* pIAPDUHandler, AllObjectsHeader* record)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessHeader_AllObjectsHeader_in_IAPDUHandler_override1"<<'\n';
  decrement_stack_info();
#endif
  UNUSED(record);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
//    IINField ProcessUnsupportedHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/)
IINField ProcessHeader_RangeHeader_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header)
{
  UNUSED(header);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/)
IINField ProcessHeader_CountHeader_in_IAPDUHandler_override(void* pIAPDUHandler, CountHeader* header)
{
  UNUSED(header);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

void OnHeaderResult_in_IAPDUHandler_override(void* pIAPDUHandler, HeaderRecord* record, IINField* result)
{
  UNUSED(pIAPDUHandler);
  UNUSED(record);
  UNUSED(result);
}

/// ---- counts -----

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group50Var1>& /*unused*/)
IINField ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler_override(void* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group50Var3>& /*values*/)
IINField ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler_override(void* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group51Var1>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group51Var2>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group52Var1>& /*values*/)
////{
////    return ProcessUnsupportedHeader();
////}

////IINField IAPDUHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group52Var2>& /*unused*/)
////{
////    return ProcessUnsupportedHeader();
////}

/// ---- ranges -----

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<IINValue>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<Binary>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<DoubleBitBinary>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<BinaryOutputStatus>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<Counter>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Counter* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<FrozenCounter>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<Analog>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Analog* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputStatus>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/, const ICollection<Indexed<OctetString>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_OctetString* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const RangeHeader& /*header*/,
////                                     const ICollection<Indexed<TimeAndInterval>>& /*values*/)
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

/// ---- index prefixes -----

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<Indexed<Counter>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<FrozenCounter>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<Indexed<Binary>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<BinaryOutputStatus>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<DoubleBitBinary>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<Indexed<Analog>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputStatus>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<OctetString>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<TimeAndInterval>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<BinaryCommandEvent>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogCommandEvent>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return ProcessUnsupportedHeader();
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

IINField ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* record, ICollection_for_uint16* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler)(pIAPDUHandler, record, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputDouble64* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
{
  return (pIAPDUHandler->pProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler)(pIAPDUHandler, header, values);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/, const ICollection<uint16_t>& /*values*/)
IINField ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* values)
{
////    return ProcessUnsupportedHeader();
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

//// --- controls ----

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<ControlRelayOutputBlock>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
////    return ProcessUnsupportedHeader();
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputInt16>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
{
////    return ProcessUnsupportedHeader();
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputInt32>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
{
////    return ProcessUnsupportedHeader();
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputFloat32>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
{
////    return ProcessUnsupportedHeader();
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////IINField IAPDUHandler::ProcessHeader(const PrefixHeader& /*header*/,
////                                     const ICollection<Indexed<AnalogOutputDouble64>>& /*values*/)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_IAPDUHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputDouble64* values)
{
////    return ProcessUnsupportedHeader();
  UNUSED(header);
  UNUSED(values);
  IAPDUHandler* parent = (IAPDUHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessUnsupportedHeader_in_IAPDUHandler(parent);
}

////} // namespace opendnp3


IINField ProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values)
{
  return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values)
{
  return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
//    IINField ProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var1* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var2* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var1* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var2* values)
//{
// return (pIAPDUHandler->pProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_IINValue* values)
{
  return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values)
{
  return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
{
  return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Counter* values)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter* values)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Analog* values)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_OctetString* values)
{
  return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler)(pIAPDUHandler, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
{
 return (pIAPDUHandler->pProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler)(pIAPDUHandler, header, values);
}

//    IINField ProcessHeader_PrefixHeader_for_Binary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_Binary_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_BinaryOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_BinaryOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_DoubleBitBinary_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_DoubleBitBinary_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_Counter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_Counter_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_FrozenCounter_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_FrozenCounter_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_Analog_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_Analog_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputStatus_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputStatus_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_OctetString_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_OctetString_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_TimeAndInterval_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_TimeAndInterval_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_BinaryCommandEvent_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_BinaryCommandEvent_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogCommandEvent_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogCommandEvent_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

// adhoc read by index
//    IINField ProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

//    IINField ProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header,
//                            ICollection_Indexed_for_ControlRelayOutputBlock* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}
//    IINField ProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, PrefixHeader* header,
//                                   ICollection_Indexed_for_AnalogOutputDouble64* values)
//{
// return (pIAPDUHandler->pProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler)(pIAPDUHandler, header, values);
//}

void* getParentPointer_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler)
{
  return pIAPDUHandler->pParentPointer_in_IAPDUHandler;
}

void  setParentPointer_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, void* pParentPointer)
{
  pIAPDUHandler->pParentPointer_in_IAPDUHandler = pParentPointer;
}

uint32_t NumIgnoredHeaders_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
  return pIAPDUHandler->numIgnoredHeaders;
}

uint32_t GetCurrentHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
  return pIAPDUHandler->numTotalHeaders;
}

boolean IsFirstHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
  return pIAPDUHandler->numTotalHeaders == 0;
}

void Record_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, HeaderRecord* record, IINField* result)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Record_in_IAPDUHandler1"<<'\n';
  decrement_stack_info();
#endif
//    IINField operatorOREQ_in_IINField(IINField *pIINField, IINField* aIIN);
////        pIAPDUHandler->errors |= result;
  pIAPDUHandler->errors = operatorOREQ_in_IINField(&(pIAPDUHandler->errors), result);
  ++(pIAPDUHandler->numTotalHeaders);
//    void OnHeaderResult_in_IAPDUHandler(IAPDUHandler* pIAPDUHandler, HeaderRecord* record, IINField* result)// {}
////        this->OnHeaderResult(record, result);
  OnHeaderResult_in_IAPDUHandler(pIAPDUHandler, record, result);
}

void OnHeaderResult_in_IAPDUHandler(void* pIAPDUHandler, HeaderRecord* record, IINField* result)
{
  UNUSED(pIAPDUHandler);
  UNUSED(record);
  UNUSED(result);
}

IINField ProcessUnsupportedHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessUnsupportedHeader_in_IAPDUHandler1"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IINBit::FUNC_NOT_SUPPORTED"<<'\n';

  decrement_stack_info();
#endif

  ++(pIAPDUHandler->numIgnoredHeaders);
//   void IINField_in_IINFieldOver2(IINField *pIINField, IINBit_uint8_t bit);
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
  return iIINField;
}

