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
#ifndef OPENDNP3_OUTSTATIONPARAMS_H
#define OPENDNP3_OUTSTATIONPARAMS_H

////#include "opendnp3/app/AppConstants.h"
////#include "opendnp3/app/ClassField.h"
////#include "opendnp3/outstation/NumRetries.h"
////#include "opendnp3/outstation/StaticTypeBitfield.h"
////#include "opendnp3/util/TimeDuration.h"

#include "AppConstants.h"
#include "ClassField.h"
#include "NumRetries.h"
#include "StaticTypeBitfield.h"
#include "TimeDuration.h"

////namespace opendnp3
////{

/**
 *	Static configuration parameters for an outstation session
 */
////struct OutstationParams
typedef struct
{
  /// The maximum number of controls the outstation will attempt to process from a single APDU
/// Максимальное количество элементов управления, которые удаленная станция попытается обработать из одного APDU
  uint32_t maxControlsPerRequest;// = 4'294'967'295;

  /// How long the outstation will allow an operate to proceed after a prior select
/// Как долго удаленная станция позволит продолжить работу после предварительного выбора
  TimeDuration selectTimeout;// = Seconds_in_TimeDuration_static(10);

  /// Timeout for solicited confirms
/// Таймаут для запрошенных подтверждений
  TimeDuration solConfirmTimeout;// = DEFAULT_APP_TIMEOUT;

  /// Timeout for unsolicited confirms
/// Тайм-аут для незапрошенных подтверждений
  TimeDuration unsolConfirmTimeout;// = DEFAULT_APP_TIMEOUT;

  /// Number of unsolicited non-regenerated retries
/// Количество незапрошенных невосстановленных повторных попыток
  NumRetries numUnsolRetries;// = NumRetries::Infinite();

  /// Workaround for test procedure 8.11.2.1. Will respond immediatly to READ requests
  /// when waiting for unsolicited NULL responses.
/// Обходной путь для процедуры тестирования 8.11.2.1. Будет немедленно отвечать на запросы READ
   /// при ожидании незапрошенных NULL-ответов.
  ///
  /// @warning This is NOT compliant to IEEE-1815-2012.
  boolean noDefferedReadDuringUnsolicitedNullResponse;// = false;

  /// The maximum fragment size the outstation will use for fragments it sends
/// Максимальный размер фрагмента, который удаленная станция будет использовать для отправляемых фрагментов
  uint32_t maxTxFragSize;// = DEFAULT_MAX_APDU_SIZE;

  /// The maximum fragment size the outstation will be able to receive
/// Максимальный размер фрагмента, который сможет получить удаленная станция
  uint32_t maxRxFragSize;// = DEFAULT_MAX_APDU_SIZE;

  /// Global enabled / disable for unsolicited messages. If false, the NULL unsolicited message is not even sent
/// Глобальное включение/выключение нежелательных сообщений. Если false, незапрошенное сообщение NULL даже не отправляется.
  boolean allowUnsolicited;// = false;

  /// A bitmask type that specifies the types allowed in a class 0 reponse
/// Тип битовой маски, определяющий типы, разрешенные в ответе класса 0
  StaticTypeBitField typesAllowedInClass0;// = StaticTypeBitField::AllTypes();

  /// Class mask for unsolicted, default to 0 as unsolicited has to be enabled
/// Маска класса для нежелательных сообщений, по умолчанию 0, поскольку нежелательные запросы должны быть включены
  ClassField unsolClassMask;// = ClassField::None();

  /// If true, the outstation processes responds to any request/confirmation as if it came from the expected master
  /// address
  boolean respondToAnyMaster;// = false;
} OutstationParams;

void OutstationParams_in_OutstationParams(OutstationParams *pOutstationParams);
////} // namespace opendnp3

#endif
