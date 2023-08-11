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
#ifndef OPENDNP3_LINKSTATISTICS_H
#define OPENDNP3_LINKSTATISTICS_H

////#include <cstdint>

////namespace opendnp3
////{

////    struct Parser
typedef struct
{
  /// Number of frames discarded due to header CRC errors
/// Количество кадров, отброшенных из-за ошибок CRC в заголовке
  uint16_t numHeaderCrcError;// = 0;

  /// Number of frames discarded due to body CRC errors
/// Количество кадров, отброшенных из-за ошибок CRC тела
  uint16_t numBodyCrcError;// = 0;

  /// Number of frames received
/// Количество полученных кадров
  uint16_t numLinkFrameRx;// = 0;

  /// number of bad LEN fields received (malformed frame)
/// количество полученных неверных полей LEN (деформированный кадр)
  uint16_t numBadLength;// = 0;

  /// number of bad function codes (malformed frame)
/// количество неправильных кодов функций (деформированный фрейм)
  uint16_t numBadFunctionCode;// = 0;

  /// number of FCV / function code mismatches (malformed frame)
/// количество несоответствий кода FCV/функции (неверный кадр)
  uint16_t numBadFCV;// = 0;

  /// number of frames w/ unexpected FCB bit set (malformed frame)
/// количество кадров с неожиданным установленным битом FCB (деформированный кадр)
  uint16_t numBadFCB;// = 0;
} Parser_in_LinkStatistics;
void Parser_in_LinkStatistics__in__Parser_in_LinkStatistics(Parser_in_LinkStatistics *pParser_in_LinkStatistics);

////    struct Channel
typedef struct
{
  /// The number of times the channel has successfully opened
/// Сколько раз канал успешно открывался
  uint16_t numOpen;// = 0;

  /// The number of times the channel has failed to open
/// Сколько раз канал не открылся
  uint16_t numOpenFail;// = 0;

  /// The number of times the channel has closed either due to user intervention or an error
/// Сколько раз канал закрывался либо из-за вмешательства пользователя, либо из-за ошибки
  uint16_t numClose;// = 0;

  /// The number of bytes received
/// Количество полученных байтов
  uint16_t numBytesRx;// = 0;

  /// The number of bytes transmitted
/// Количество переданных байтов
  uint16_t numBytesTx;// = 0;

  /// Number of frames transmitted
/// Количество переданных кадров
  uint16_t numLinkFrameTx;// = 0;
} Channel_in_LinkStatistics;

void Channel_in_LinkStatistics__in__Channel_in_LinkStatistics(Channel_in_LinkStatistics *pChannel_in_LinkStatistics);

/**
 * Counters for the channel and the DNP3 link layer
 */
////struct LinkStatistics
typedef struct
{
////    struct Parser
////    {
  /// Number of frames discarded due to header CRC errors
////        size_t numHeaderCrcError = 0;

  /// Number of frames discarded due to body CRC errors
////        size_t numBodyCrcError = 0;

  /// Number of frames received
////        size_t numLinkFrameRx = 0;

  /// number of bad LEN fields received (malformed frame)
////        size_t numBadLength = 0;

  /// number of bad function codes (malformed frame)
////        size_t numBadFunctionCode = 0;

  /// number of FCV / function code mismatches (malformed frame)
////        size_t numBadFCV = 0;

  /// number of frames w/ unexpected FCB bit set (malformed frame)
////        size_t numBadFCB = 0;
////    };

////    struct Channel
////    {
  /// The number of times the channel has successfully opened
////        size_t numOpen = 0;

  /// The number of times the channel has failed to open
////        size_t numOpenFail = 0;

  /// The number of times the channel has closed either due to user intervention or an error
////        size_t numClose = 0;

  /// The number of bytes received
////        size_t numBytesRx = 0;

  /// The number of bytes transmitted
////        size_t numBytesTx = 0;

  /// Number of frames transmitted
////        size_t numLinkFrameTx = 0;
////    };

////    LinkStatistics() = default;

////    LinkStatistics(const Channel& channel, const Parser& parser) : channel(channel), parser(parser) {}

  /// statistics for the communicaiton channel
  Channel_in_LinkStatistics channel;

  /// statistics for the link parser
  Parser_in_LinkStatistics parser;
} LinkStatistics;

void LinkStatistics_in_LinkStatisticsOver1(LinkStatistics *pLinkStatistics);
void LinkStatistics_in_LinkStatisticsOver2(LinkStatistics *pLinkStatistics,
    Channel_in_LinkStatistics* channel,
    Parser_in_LinkStatistics* parser);


////} // namespace opendnp3

#endif
