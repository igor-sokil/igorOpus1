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

#ifndef OPENDNP3_FUNCTIONCODE_H
#define OPENDNP3_FUNCTIONCODE_H

////#include <cstdint>
////#include <string>

////namespace opendnp3 {

/**
  Application layer function code enumeration
*/
//enum class FunctionCode : uint8_t
#define FunctionCode_uint8_t uint8_t
enum FunctionCode 
{
  /// Master sends this to an outstation to confirm the receipt of an Application Layer fragment
/// Мастер отправляет это на удаленную станцию, чтобы подтвердить получение фрагмента прикладного уровня
  FunctionCode_CONFIRM = 0x0,
  /// Outstation shall return the data specified by the objects in the request
/// Outstation вернет данные, указанные объектами в запросе
  FunctionCode_READ = 0x1,
  /// Outstation shall store the data specified by the objects in the request
/// Outstation будет хранить данные, указанные объектами в запросе
  FunctionCode_WRITE = 0x2,
  /// Outstation shall select (or arm) the output points specified by the objects in the request in preparation for a subsequent operate command
/// Outstation должна выбрать (или поставить на охрану) точки вывода, указанные объектами в запросе, при подготовке к последующей команде срабатывания
  FunctionCode_SELECT = 0x3,
  /// Outstation shall activate the output points selected (or armed) by a previous select function code command
/// Outstation активирует точки выхода, выбранные (или поставленные на охрану) предыдущей командой кода функции выбора.
  FunctionCode_OPERATE = 0x4,
  /// Outstation shall immediately actuate the output points specified by the objects in the request
/// Outstation немедленно сработает точки выхода, указанные объектами в запросе
  FunctionCode_DIRECT_OPERATE = 0x5,
  /// Same as DIRECT_OPERATE but outstation shall not send a response
/// То же, что и DIRECT_OPERATE, но удаленная станция не должна отправлять ответ
  FunctionCode_DIRECT_OPERATE_NR = 0x6,
  /// Outstation shall copy the point data values specified by the objects in the request to a separate freeze buffer
/// Outstation скопирует значения данных точек, указанные объектами в запросе, в отдельный замораживающий буфер
  FunctionCode_IMMED_FREEZE = 0x7,
  /// Same as IMMED_FREEZE but outstation shall not send a response
/// То же, что IMMED_FREEZE, но удаленная станция не будет отправлять ответ
  FunctionCode_IMMED_FREEZE_NR = 0x8,
  /// Outstation shall copy the point data values specified by the objects in the request into a separate freeze buffer and then clear the values
/// Outstation скопирует значения данных точек, указанные объектами в запросе, в отдельный замораживающий буфер, а затем очистит значения
  FunctionCode_FREEZE_CLEAR = 0x9,
  /// Same as FREEZE_CLEAR but outstation shall not send a response
/// То же, что и FREEZE_CLEAR, но внешняя станция не будет отправлять ответ
  FunctionCode_FREEZE_CLEAR_NR = 0xA,
  /// Outstation shall copy the point data values specified by the objects in the request to a separate freeze buffer at the time and/or time intervals specified in a special time data information object
/// Outstation копирует значения данных точек, указанные объектами в запросе, в отдельный буфер фиксации во время и/или интервалы времени, указанные в специальном информационном объекте данных времени.
  FunctionCode_FREEZE_AT_TIME = 0xB,
  /// Same as FREEZE_AT_TIME but outstation shall not send a response
/// То же, что и FREEZE_AT_TIME, но удаленная станция не будет отправлять ответ
  FunctionCode_FREEZE_AT_TIME_NR = 0xC,
  /// Outstation shall perform a complete reset of all hardware and software in the device
/// Outstation выполнит полный сброс всего аппаратного и программного обеспечения устройства.
  FunctionCode_COLD_RESTART = 0xD,
  /// Outstation shall reset only portions of the device
/// Outstation будет сбрасывать только части устройства
  FunctionCode_WARM_RESTART = 0xE,
  /// Obsolete-Do not use for new designs
/// Устарело – не использовать для новых проектов
  FunctionCode_INITIALIZE_DATA = 0xF,
  /// Outstation shall place the applications specified by the objects in the request into the ready to run state
/// Outstation переводит приложения, указанные объектами в запросе, в состояние готовности к запуску
  FunctionCode_INITIALIZE_APPLICATION = 0x10,
  /// Outstation shall start running the applications specified by the objects in the request
/// Outstation начнет запускать приложения, указанные объектами в запросе
  FunctionCode_START_APPLICATION = 0x11,
  /// Outstation shall stop running the applications specified by the objects in the request
/// Outstation прекратит запуск приложений, указанных объектами в запросе
  FunctionCode_STOP_APPLICATION = 0x12,
  /// This code is deprecated-Do not use for new designs
/// Этот код устарел. Не используйте для новых проектов.
  FunctionCode_SAVE_CONFIGURATION = 0x13,
  /// Enables outstation to initiate unsolicited responses from points specified by the objects in the request
/// Позволяет удаленной станции инициировать незапрошенные ответы из точек, указанных объектами в запросе
  FunctionCode_ENABLE_UNSOLICITED = 0x14,
  /// Prevents outstation from initiating unsolicited responses from points specified by the objects in the request
/// Предотвращает инициацию нежелательных ответов удаленной станцией из точек, указанных объектами в запросе
  FunctionCode_DISABLE_UNSOLICITED = 0x15,
  /// Outstation shall assign the events generated by the points specified by the objects in the request to one of the classes
/// Outstation отнесет события, генерируемые точками, указанными объектами в запросе, к одному из классов
  FunctionCode_ASSIGN_CLASS = 0x16,
  /// Outstation shall report the time it takes to process and initiate the transmission of its response
/// Outstation сообщит время, необходимое для обработки и инициации передачи своего ответа.
  FunctionCode_DELAY_MEASURE = 0x17,
  /// Outstation shall save the time when the last octet of this message is received
/// Outstation сохранит время получения последнего октета этого сообщения
  FunctionCode_RECORD_CURRENT_TIME = 0x18,
  /// Outstation shall open a file
/// Outstation откроет файл
  FunctionCode_OPEN_FILE = 0x19,
  /// Outstation shall close a file
/// Outstation закроет файл
  FunctionCode_CLOSE_FILE = 0x1A,
  /// Outstation shall delete a file
/// Outstation должен удалить файл
  FunctionCode_DELETE_FILE = 0x1B,
  /// Outstation shall retrieve information about a file
/// Outstation получит информацию о файле
  FunctionCode_GET_FILE_INFO = 0x1C,
  /// Outstation shall return a file authentication key
/// Outstation вернет ключ аутентификации файла
  FunctionCode_AUTHENTICATE_FILE = 0x1D,
  /// Outstation shall abort a file transfer operation
/// Outstation прервет операцию передачи файлов
  FunctionCode_ABORT_FILE = 0x1E,
  /// The master uses this function code when sending authentication requests to the outstation
/// Мастер использует этот код функции при отправке запросов аутентификации на удаленную станцию
  FunctionCode_AUTH_REQUEST = 0x20,
  /// The master uses this function code when sending authentication requests to the outstation that do no require acknowledgement
/// Мастер использует этот код функции при отправке запросов аутентификации на удаленную станцию, которые не требуют подтверждения
  FunctionCode_AUTH_REQUEST_NO_ACK = 0x21,
  /// Master shall interpret this fragment as an Application Layer response to an ApplicationLayer request
/// Мастер должен интерпретировать этот фрагмент как ответ уровня приложения на запрос уровня приложения.
  FunctionCode_RESPONSE = 0x81,
  /// Master shall interpret this fragment as an unsolicited response that was not prompted by an explicit request
/// Мастер должен интерпретировать этот фрагмент как незапрошенный ответ, который не был вызван явным запросом
  FunctionCode_UNSOLICITED_RESPONSE = 0x82,
  /// The outstation uses this function code to issue authentication messages to the master
/// Удаленная станция использует этот код функции для отправки сообщений аутентификации мастеру
  FunctionCode_AUTH_RESPONSE = 0x83,
  /// Unknown function code. Used internally in opendnp3 to indicate the code didn't match anything known
/// Неизвестный код функции. Используется внутри opendnp3, чтобы указать, что код не соответствует ничему известному.
  FunctionCode_UNKNOWN = 0xFF
};

FunctionCode_uint8_t from_type_in_FunctionCodeSpec(uint8_t arg);

////struct FunctionCodeSpec
////{
////  using enum_type_t = FunctionCode;

////  static uint8_t to_type(FunctionCode arg);
////  static FunctionCode from_type(uint8_t arg);
////  static char const* to_string(FunctionCode arg);
////  static char const* to_human_string(FunctionCode arg);
////  static FunctionCode from_string(const std::string& arg);
////};

////}

#endif
