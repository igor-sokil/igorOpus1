//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2022 Step Function I/O, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
// LLC (https://stepfunc.io) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef OPENDNP3_COMMANDSTATUS_H
#define OPENDNP3_COMMANDSTATUS_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  An enumeration of result codes received from an outstation in response to command request.
  These correspond to those defined in the DNP3 standard
Перечень кодов результатов, полученных от удаленной станции в ответ на запрос команды.
   Они соответствуют тем, которые определены в стандарте DNP3.
*/
#define  CommandStatus_uint8_t  uint8_t
enum CommandStatus////class CommandStatus ////: uint8_t
{
  /// command was accepted, initiated, or queued
/// команда принята, инициирована или поставлена в очередь
  CommandStatus_SUCCESS = 0,
  /// command timed out before completing
/// тайм-аут команды истек до завершения
  CommandStatus_TIMEOUT = 1,
  /// command requires being selected before operate, configuration issue
/// команду необходимо выбрать перед выполнением, проблема с конфигурацией
  CommandStatus_NO_SELECT = 2,
  /// bad control code or timing values
/// неверный управляющий код или значения времени
  CommandStatus_FORMAT_ERROR = 3,
  /// command is not implemented
/// команда не реализована
  CommandStatus_NOT_SUPPORTED = 4,
  /// command is all ready in progress or its all ready in that mode
/// команда уже выполняется или уже находится в этом режиме
  CommandStatus_ALREADY_ACTIVE = 5,
  /// something is stopping the command, often a local/remote interlock
/// что-то мешает команде, часто локальная/дистанционная блокировка
  CommandStatus_HARDWARE_ERROR = 6,
  /// the function governed by the control is in local only control
/// функция, управляемая элементом управления, находится только в локальном управлении
  CommandStatus_LOCAL = 7,
  /// the command has been done too often and has been throttled
/// команда выполнялась слишком часто и была ограничена
  CommandStatus_TOO_MANY_OPS = 8,
  /// the command was rejected because the device denied it or an RTU intercepted it
/// команда была отклонена, потому что устройство отклонило ее или ее перехватил RTU
  CommandStatus_NOT_AUTHORIZED = 9,
  /// command not accepted because it was prevented or inhibited by a local automation process, such as interlocking logic or synchrocheck
/// команда не принята, поскольку она была предотвращена или запрещена локальным процессом автоматизации, например логикой блокировки или проверкой синхронизма
  CommandStatus_AUTOMATION_INHIBIT = 10,
  /// command not accepted because the device cannot process any more activities than are presently in progress
/// команда не принята, поскольку устройство не может обрабатывать больше действий, чем те, которые выполняются в данный момент
  CommandStatus_PROCESSING_LIMITED = 11,
  /// command not accepted because the value is outside the acceptable range permitted for this point
/// команда не принята, поскольку значение находится за пределами допустимого диапазона, разрешенного для этой точки
  CommandStatus_OUT_OF_RANGE = 12,
  /// command not accepted because the outstation is forwarding the request to another downstream device which reported LOCAL
/// команда не принята, поскольку удаленная станция пересылает запрос на другое нижестоящее устройство, которое сообщило LOCAL
  CommandStatus_DOWNSTREAM_LOCAL = 13,
  /// command not accepted because the outstation has already completed the requested operation
/// команда не принята, поскольку удаленная станция уже завершила запрошенную операцию
  CommandStatus_ALREADY_COMPLETE = 14,
  /// command not accepted because the requested function is specifically blocked at the outstation
/// команда не принята, поскольку запрошенная функция специально заблокирована на удаленной станции
  CommandStatus_BLOCKED = 15,
  /// command not accepted because the operation was cancelled
/// команда не принята, поскольку операция была отменена
  CommandStatus_CANCELLED = 16,
  /// command not accepted because another master is communicating with the outstation and has exclusive rights to operate this control point
///команда не принята, так как другой мастер общается с удаленной станцией и имеет эксклюзивные права на управление этой контрольной точкой
  CommandStatus_BLOCKED_OTHER_MASTER = 17,
  /// command not accepted because the outstation is forwarding the request to another downstream device which cannot be reached or is otherwise incapable of performing the request
/// команда не принята, поскольку удаленная станция перенаправляет запрос на другое нижестоящее устройство, с которым невозможно связаться или которое иным образом неспособно выполнить запрос
  CommandStatus_DOWNSTREAM_FAIL = 18,
  /// (deprecated) indicates the outstation shall not issue or perform the control operation
/// (устарело) указывает, что удаленная станция не должна выдавать или выполнять операцию управления.
  CommandStatus_NON_PARTICIPATING = 126,
  /// 10 to 126 are currently reserved
/// от 10 до 126 на данный момент зарезервированы
  CommandStatus_UNDEFINED = 127
};

CommandStatus_uint8_t from_type_in_CommandStatusSpec(uint8_t arg);

////struct CommandStatusSpec
////typedef struct
////{
////  using enum_type_t = CommandStatus;

////  static uint8_t to_type(CommandStatus arg);
//// unsigned char (*pTo_type)(unsigned char arg);
////  static CommandStatus from_type(uint8_t arg);
//// unsigned char (*pFrom_type)(unsigned char arg);
////  static char const* to_string(CommandStatus arg);
////  static char const* to_human_string(CommandStatus arg);
////  static CommandStatus from_string(const std::string& arg);
////} CommandStatusSpec;

////}

#endif
