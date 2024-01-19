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
#ifndef OPENDNP3_MASTERPARAMS_H
#define OPENDNP3_MASTERPARAMS_H

////#include "opendnp3/app/AppConstants.h"
////#include "opendnp3/app/ClassField.h"
////#include "opendnp3/gen/IndexQualifierMode.h"
////#include "opendnp3/gen/TimeSyncMode.h"
////#include "opendnp3/util/TimeDuration.h"

#include "AppConstants.h"
#include "ClassField.h"
#include "IndexQualifierMode.h"
#include "TimeSyncMode.h"
#include "TimeDuration.h"

////namespace opendnp3
////{

/**
Configuration information for the dnp3 master
*/
////struct MasterParams
typedef struct
{
  /// Default constructor
////    MasterParams() {}

  /// Application layer response timeout
  TimeDuration responseTimeout;// = TimeDuration::Seconds(5);

  /// If true, the master will do time syncs when it sees the time IIN bit from the outstation
/// ≈сли true, мастер будет синхронизировать врем€, когда увидит бит времени IN от внешней станции
  TimeSyncMode_uint8_t timeSyncMode;// = TimeSyncMode::None;

  /// If true, the master will disable unsol on startup for all 3 classes
/// ≈сли true, мастер отключит unsol при запуске дл€ всех трех классов
  boolean disableUnsolOnStartup;// = true;

  /// If true, the master will not clear the restart IIN bit in response to detecting it set
/// ≈сли true, мастер не будет очищать бит IIN перезапуска в ответ на его установку
  boolean ignoreRestartIIN;// = false;

  /// Bitwise mask used determine which classes are enabled for unsol, if 0 unsol is not enabled
/// »спользуема€ побитова€ маска определ€ет, какие классы включены дл€ unsol, если 0 unsol не включен
  ClassField unsolClassMask;// = ClassField::AllEventClasses();

  /// Which classes should be requested in a startup integrity scan, defaults to 3/2/1/0
  /// A mask equal to 0 means no startup integrity scan will be performed
///  акие классы следует запрашивать при сканировании целостности при запуске, по умолчанию 3/2/1/0
  /// ћаска, равна€ 0, означает, что сканирование целостности при запуске выполн€тьс€ не будет.
  ClassField startupIntegrityClassMask;// = ClassField::AllClasses();

  /// Defines whether an integrity scan will be performed when the EventBufferOverflow IIN is detected
/// ќпредел€ет, будет ли выполн€тьс€ проверка целостности при обнаружении IIN EventBufferOverflow
  boolean integrityOnEventOverflowIIN;// = true;

  /// Which classes should be requested in an event scan when detecting corresponding events available IIN
///  акие классы следует запрашивать при сканировании событий при обнаружении соответствующих событий, доступных IN
  ClassField eventScanOnEventsAvailableClassMask;// = ClassField::None();

  /// Time delay before retrying a failed task
/// «адержка перед повторной попыткой неудачного задани€
  TimeDuration taskRetryPeriod;// = TimeDuration::Seconds(5);

  /// Maximum time delay before retrying a failed task. Backs off exponentially from taskRetryPeriod
/// ћаксимальна€ задержка перед повторной попыткой неудачной задачи. Ёкспоненциально отступает от TaskRetryPeriod
  TimeDuration maxTaskRetryPeriod;// = TimeDuration::Minutes(1);

  /// Time delay before failing a non-recurring task (e.g. commands) that cannot start
/// «адержка времени перед сбоем неповтор€ющейс€ задачи (например, команд), которую невозможно запустить
  TimeDuration taskStartTimeout;// = TimeDuration::Seconds(10);

  /// maximum APDU tx size in bytes
  uint32_t maxTxFragSize;// = DEFAULT_MAX_APDU_SIZE;

  /// maximum APDU rx size in bytes
  uint32_t maxRxFragSize;// = DEFAULT_MAX_APDU_SIZE;

  /// Control how the master chooses what qualifier to send when making requests
  /// The default behavior is to always use two bytes, but the one byte optimization
  /// can be enabled
///  онтролируем, как мастер выбирает, какой квалификатор отправл€ть при отправке запросов
  /// ѕоведение по умолчанию Ч всегда использовать два байта, но оптимизаци€ в один байт
  /// можно включить
  IndexQualifierMode_uint8_t controlQualifierMode;// = IndexQualifierMode::always_two_bytes;
} MasterParams;

void MasterParams_in_MasterParams(MasterParams *pMasterParams);


////} // namespace opendnp3

#endif
