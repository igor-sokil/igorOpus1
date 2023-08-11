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
#ifndef OPENDNP3_APPCONTROLFIELD_H
#define OPENDNP3_APPCONTROLFIELD_H

////#include <cstdint>

////namespace opendnp3
////{

/** Represents the first byte in every APDU
 */
////struct AppControlField
typedef struct
{
////    const static AppControlField DEFAULT;

////    static AppControlField Request(uint8_t seq);

////    AppControlField() = default;

////    explicit AppControlField(uint8_t byte);

////    AppControlField(bool fir, bool fin, bool con, bool uns, uint8_t seq = 0);

////    uint8_t ToByte() const;

////    bool IsFirAndFin() const
////    {
////        return FIR && FIN;
////    }
  boolean FIR;//// = true;
  boolean FIN;//// = true;
  boolean CON;//// = false;
  boolean UNS;//// = false;

  uint8_t SEQ;//// = 0;

////private:
} AppControlField;

void AppControlField_in_AppControlFieldOver1(AppControlField *);
void AppControlField_in_AppControlFieldOver2(AppControlField *, uint8_t byte);
void AppControlField_in_AppControlFieldOver3(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns);
void AppControlField_in_AppControlFieldOver4(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq);
AppControlField Request_in_AppControlField_static(uint8_t seq);
uint8_t ToByte_in_AppControlField(AppControlField *);
boolean IsFirAndFin_in_AppControlField(AppControlField *);

const uint8_t AppControlField_FIR_MASK = 0x80;
const uint8_t AppControlField_FIN_MASK = 0x40;
const uint8_t AppControlField_CON_MASK = 0x20;
const uint8_t AppControlField_UNS_MASK = 0x10;
const uint8_t AppControlField_SEQ_MASK = 0x0F;

////} // namespace opendnp3

#endif
