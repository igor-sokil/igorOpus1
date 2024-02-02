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
#ifndef OPENDNP3_COMMAND_SET_OPS_H
#define OPENDNP3_COMMAND_SET_OPS_H

#include "HeaderWriter.h"
#include "IAPDUHandler.h"

#include "IndexQualifierMode.h"
#include "CommandResultCallbackT.h"
#include "CommandSet.h"
#include "TaskCompletion.h"

////namespace opendnp3
////{
/**
 *
 * Has private access to CommandSet
 *
 * Used to reduce the public API surface exposed in includes to users
* Используется для уменьшения публичной поверхности API, доступной пользователям.
 */
////    enum class OperateResult : uint8_t
#define OperateResult_in_CommandSetOps_uint8_t uint8_t
enum
{
  OperateResult_in_CommandSetOps_OK,
  OperateResult_in_CommandSetOps_FAIL_PARSE
};

////    enum class SelectResult : uint8_t
#define SelectResult_in_CommandSetOps_uint8_t uint8_t
enum
{
  SelectResult_in_CommandSetOps_OK,
  SelectResult_in_CommandSetOps_FAIL_PARSE,
  SelectResult_in_CommandSetOps_FAIL_SELECT
};

////    enum class Mode : uint8_t
#define Mode_in_CommandSetOps_uint8_t uint8_t
enum
{
  Mode_in_CommandSetOps_Select,
  Mode_in_CommandSetOps_Operate
};

////class CommandSetOps final : public IAPDUHandler, private Uncopyable
typedef struct
{
  IAPDUHandler iIAPDUHandler;
////    enum class Mode : uint8_t
////    {
////        Select,
////        Operate
////    };

////    CommandSetOps(Mode mode, CommandSet& commands_);

  Mode_in_CommandSetOps_uint8_t mode;

////public:
////    enum class OperateResult : uint8_t
////    {
////        OK,
////        FAIL_PARSE
////    };

////    enum class SelectResult : uint8_t
////    {
////        OK,
////        FAIL_PARSE,
////        FAIL_SELECT
////    };

  /// Write the headers to an ASDU
////    static bool Write(const CommandSet& set, HeaderWriter& writer, IndexQualifierMode mode);

  /// Invoke the callback for a response
////    static void InvokeCallback(const CommandSet& set, TaskCompletion result, const CommandResultCallbackT& callback);

  /**
   * parses a response to a select, applying each received header to the command set
  * анализирует ответ на выбор, применяя каждый полученный заголовок к набору команд
   *
   * @return true if every object in every header was correctly selected, false otherwise
   */
////    static SelectResult ProcessSelectResponse(CommandSet& set, const ser4cpp::rseq_t& headers, Logger* logger);

  /**
   * parses a response to an operate (or DO), applying each received header to the command set
  * анализирует ответ на операцию (или DO), применяя каждый полученный заголовок к набору команд
   *
   * @return true if parsing was successful, the results are left in the set
   */
////    static OperateResult ProcessOperateResponse(CommandSet& set, const ser4cpp::rseq_t& headers, Logger* logger);

////private:
////    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override;
////
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<ControlRelayOutputBlock>>& values) override;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputInt16>>& values) override;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputInt32>>& values) override;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputFloat32>>& values) override;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputDouble64>>& values) override;
////
////    template<class T> IINField ProcessAny(const PrefixHeader& header, const ICollection<Indexed<T>>& values);

  CommandSet* commands;
} CommandSetOps;

void CommandSetOps_in_CommandSetOps(CommandSetOps *pCommandSetOps, Mode_in_CommandSetOps_uint8_t mode, CommandSet* commands_);

boolean Write_in_CommandSetOps_static(CommandSet* set, HeaderWriter* writer, IndexQualifierMode_uint8_t mode);
void InvokeCallback_in_CommandSetOps_static(CommandSet* set, TaskCompletion_uint8_t result, CommandResultCallbackT callback);

OperateResult_in_CommandSetOps_uint8_t ProcessOperateResponse_in_CommandSetOps_static(CommandSet* set, RSeq_for_Uint16_t* headers);//, Logger* logger);
SelectResult_in_CommandSetOps_uint8_t ProcessSelectResponse_in_CommandSetOps_static(CommandSet* set, RSeq_for_Uint16_t* headers);//, Logger* logger);

IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values);
IINField ProcessAny_for_AnalogOutputInt16_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt16* values);
IINField ProcessAny_for_AnalogOutputInt32_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputInt32* values);
IINField ProcessAny_for_AnalogOutputFloat32_in_CommandSetOps(CommandSetOps *pCommandSetOps, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputFloat32* values);

boolean IsAllowed_in_CommandSetOps(CommandSetOps *, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
boolean IsAllowed_in_CommandSetOps_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

////     IINField ProcessHeader(const PrefixHeader& header,
////                            const ICollection<Indexed<ControlRelayOutputBlock>>& values) override;
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandSetOps(CommandSetOps*, PrefixHeader* header,
    ICollection_Indexed_for_ControlRelayOutputBlock* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header,
    ICollection_Indexed_for_ControlRelayOutputBlock* values);

////     IINField ProcessHeader(const PrefixHeader& header,
////                            const ICollection<Indexed<AnalogOutputInt16>>& values) override;
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandSetOps(CommandSetOps*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt16* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt16* values);

////     IINField ProcessHeader(const PrefixHeader& header,
////                            const ICollection<Indexed<AnalogOutputInt32>>& values) override;
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandSetOps(CommandSetOps*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt32* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt32* values);

////     IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputFloat32>>& values) override;
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandSetOps(CommandSetOps*, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputFloat32* values);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandSetOps_override(void* pIAPDUHandler, PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputFloat32* values);

////} // namespace opendnp3

#endif
