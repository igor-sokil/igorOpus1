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
#include "APDUHeader.h"

////namespace opendnp3
////{

   APDUHeader SolicitedConfirm_in_APDUHeader(uint8_t seq)
{
    return Confirm_in_APDUHeader(seq, false);
}

   APDUHeader UnsolicitedConfirm_in_APDUHeader(uint8_t seq)
{
    return Confirm_in_APDUHeader(seq, true);
}

   APDUHeader Confirm_in_APDUHeader(uint8_t seq, boolean unsolicited)
{
    APDUHeader header;
    header.function = FunctionCode_CONFIRM;
    AppControlField_in_AppControlFieldOver4(&header.control, true, true, false, unsolicited, seq);
    return header;
}

   void APDUHeader_in_APDUHeaderOver1(APDUHeader *pAPDUHeader)
{
//qDebug()<<"pAPDUHeader"<< pAPDUHeader;
//qDebug()<<"pAPDUHeader->function"<< pAPDUHeader->function;
   pAPDUHeader->function = FunctionCode_UNKNOWN;
}

   void APDUHeader_in_APDUHeaderOver2(APDUHeader *pAPDUHeader, AppControlField *control, FunctionCode_uint8_t function)
{
   pAPDUHeader->control    = *control;
   pAPDUHeader->function   = function;
}

    boolean Equals_in_APDUHeader(APDUHeader *pAPDUHeader, APDUHeader *header)
{
  return
   (ToByte_in_AppControlField(&(header->control)) == ToByte_in_AppControlField(&(pAPDUHeader->control))) &&
   (pAPDUHeader->function == header->function);
}

 void APDUResponseHeader_in_APDUResponseHeaderOver1(APDUResponseHeader *pAPDUResponseHeader)
{
  APDUHeader_in_APDUHeaderOver1(&(pAPDUResponseHeader -> aAPDUHeader));
}

 void APDUResponseHeader_in_APDUResponseHeaderOver2(APDUResponseHeader *pAPDUResponseHeader,
                                                    AppControlField *control,
                                                    FunctionCode_uint8_t function,
                                                    IINField *pIIN)
{
  APDUHeader_in_APDUHeaderOver2(&(pAPDUResponseHeader -> aAPDUHeader), control, function);
  pAPDUResponseHeader -> IIN = (*pIIN);
}
////} // namespace opendnp3
