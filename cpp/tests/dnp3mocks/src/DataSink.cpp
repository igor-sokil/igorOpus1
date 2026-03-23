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
#include "DataSink.h"
#include "HexConversions.h"
////#include <ser4cpp/util/HexConversions.h>

////#include <memory>
////#include <stdexcept>

////using namespace ser4cpp;

////void DataSink::Write(const rseq_t& data)
void Write_in_DataSink(DataSink *pDataSink, RSeq_for_Uint16_t* data)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{Write_in_DataSink1"<<'\n';
  inspect_RSeq(data);
#endif
//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    for (uint16_t i = 0; i < data.length(); ++i)
  for (uint16_t i = 0; i < length_in_HasLength_for_Uint16_t(&(data->hHasLength)); ++i)
  {
    pDataSink->buffer_in_DataSink.push_back(data->buffer_[i]);////data[i]);
  }
#ifdef  LOG_INFO
  std::cout<<"}Write_in_DataSink_"<<'\n';
#endif
}

void Clear_in_DataSink(DataSink *pDataSink)
{
  pDataSink->buffer_in_DataSink.clear();
}

boolean Equals_in_DataSink(DataSink *pDataSink, RSeq_for_Uint16_t* data)
{
////    if (data.length() != this->buffer.size())
  if (length_in_HasLength_for_Uint16_t(&(data->hHasLength)) != pDataSink->buffer_in_DataSink.size())
    return false;

  for (uint16_t i = 0; i < pDataSink->buffer_in_DataSink.size(); i++)
  {
    if (data->buffer_[i] != pDataSink->buffer_in_DataSink[i])
    {
      return false;
    }
  }
  return true;
}

////std::string DataSink::AsHex(bool spaced) const
std::string AsHex_in_DataSink(DataSink *pDataSink, boolean spaced)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{AsHex_in_DataSink1"<<'\n';
#endif
////    const ser4cpp::rseq_t temp(this->buffer.data(), this->buffer.size());
  RSeq_for_Uint16_t temp;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&temp, pDataSink->buffer_in_DataSink.data(), pDataSink->buffer_in_DataSink.size());
////    return HexConversions::to_hex(temp, spaced);
  std::string tmp = to_hex_in_HexConversionsOver2(&temp, spaced);
#ifdef  LOG_INFO
  std::cout<<"}AsHex_in_DataSink_"<<'\n';
#endif
  return tmp;
}

boolean IsEmpty_in_DataSink(DataSink *pDataSink)
{
  return pDataSink->buffer_in_DataSink.size() == 0;
}

uint16_t Size_in_DataSink(DataSink *pDataSink)
{
  return pDataSink->buffer_in_DataSink.size();
}
