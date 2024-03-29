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
#ifndef OPENDNP3_APPLICATIONIIN_H
#define OPENDNP3_APPLICATIONIIN_H

////#include "opendnp3/app/IINField.h"
#include "IINField.h"

////namespace opendnp3
////{

/**
    Some IIN bits are necessarily controlled by the outstation application,
    not the underlying protocol stack. This structure describes the state of
    the bits controllable by the application.
��������� ���� IIN ����������� �������������� ����������� ��������� �������.
     � �� ������� ���� ����������. ��� ��������� ��������� ���������
     ����, ����������� �����������.
*/
////class ApplicationIIN
typedef struct
{

////public:
////    ApplicationIIN() = default;

  // flags normally controlled by the application, not the stack
// �����, ������� ������ �������������� �����������, � �� ������
  boolean needTime;// = false;
  boolean localControl;// = false;
  boolean deviceTrouble;// = false;
  boolean configCorrupt;// = false;

  // this is only for appliactions that have an additional external event buffer that can overflow
// ��� ������ ��� ����������, � ������� ���� �������������� ������� ����� �������, ������� ����� �������������
  boolean eventBufferOverflow;// = false;

////    IINField ToIIN() const;
} ApplicationIIN;

void ApplicationIIN_in_ApplicationIIN(ApplicationIIN *pApplicationIIN);
IINField ToIIN_in_ApplicationIIN(ApplicationIIN *pApplicationIIN);
////} // namespace opendnp3

#endif
