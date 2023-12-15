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
#ifndef OPENDNP3_LINKLAYERPARSER_H
#define OPENDNP3_LINKLAYERPARSER_H

////#include "link/IFrameSink.h"
////#include "link/LinkFrame.h"
////#include "link/LinkHeader.h"
////#include "link/ShiftableBuffer.h"

////#include "opendnp3/link/LinkStatistics.h"
////#include "opendnp3/logging/Logger.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "IFrameSink.h"
#include "LinkFrame.h"
#include "LinkHeader.h"
#include "ShiftableBuffer.h"

#include "LinkStatistics.h"
//#include "opendnp3/logging/Logger.h"

//#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"
#include "WSeq.h"

////namespace opendnp3
////{

#define State_LinkLayerParser_uint8_t  uint8_t
enum State_LinkLayerParser//class State
{
  FindSync_State_LinkLayerParser,
  ReadHeader_State_LinkLayerParser,
  ReadBody_State_LinkLayerParser,
  Complete_State_LinkLayerParser
};

/// Parses FT3 frames
////class LinkLayerParser
typedef struct
{
////    enum class State
////    {
////        FindSync,
////        ReadHeader,
////        ReadBody,
////        Complete
////    };

////public:
  /// @param logger_ Logger that the receiver is to use.
  /// @param pSink_ Completely parsed frames are sent to this interface
/// @param logger_ Регистратор, который должен использовать получатель.
  /// @param pSink_ На этот интерфейс отправляются полностью проанализированные кадры
////    LinkLayerParser(const Logger& logger);

  /// Called when valid data has been written to the current buffer write position
  /// Parses the new data and calls the specified frame sink
  /// @param numBytes Number of bytes written
/// Вызывается, когда корректные данные были записаны в текущую позицию записи буфера
  /// Анализирует новые данные и вызывает указанный приемник кадров
  /// @param numBytes Количество записанных байтов
////    void OnRead(size_t numBytes, IFrameSink& sink);

  /// @return Buffer that can currently be used for writing
/// @return Буфер, который в данный момент можно использовать для записи
////    ser4cpp::wseq_t WriteBuff() const;

  /// Resets the state of parser
/// Сбрасывает состояние парсера
////    void Reset();

////    const LinkStatistics::Parser& Statistics() const
////    {
////        return this->statistics;
////    }

////private:
////    State ParseUntilComplete();
////    State ParseOneStep();
////    State ParseSync();
////    State ParseHeader();
////    State ParseBody();

////    void PushFrame(IFrameSink& sink);

////    bool ReadHeader();
////    bool ValidateBody();
////    bool ValidateHeaderParameters();
////    bool ValidateFunctionCode();
////    void FailFrame();

////    void TransferUserData();

////    Logger logger;
////    LinkStatistics::Parser statistics;
  Parser_in_LinkStatistics statistics;

  LinkHeader header;

  State_LinkLayerParser_uint8_t state;
  uint16_t frameSize;
  RSeq_for_Uint16_t userData;

  // buffer where received data is written
  uint8_t rxBuffer[LPDU_MAX_FRAME_SIZE];

  // facade over the rxBuffer that provides ability to "shift" as data is read
// фасад над rxBuffer, который обеспечивает возможность «сдвигаться» при чтении данных
  ShiftableBuffer buffer;
} LinkLayerParser;


/// @param logger_ Logger that the receiver is to use.
/// @param pSink_ Completely parsed frames are sent to this interface
/// @param logger_ Регистратор, который должен использовать получатель.
/// @param pSink_ На этот интерфейс отправляются полностью проанализированные кадры
void LinkLayerParser_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);//const Logger& logger);

/// Called when valid data has been written to the current buffer write position
/// Parses the new data and calls the specified frame sink
/// @param numBytes Number of bytes written
/// Вызывается, когда корректные данные были записаны в текущую позицию записи буфера
/// Анализирует новые данные и вызывает указанный приемник кадров
/// @param numBytes Количество записанных байтов
void OnRead_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, uint16_t numBytes, IFrameSink* sink);

/// @return Buffer that can currently be used for writing
/// @return Буфер, который в данный момент можно использовать для записи
WSeq_for_Uint16_t WriteBuff_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);

/// Resets the state of parser
/// Сбрасывает состояние парсера
void Reset_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);

Parser_in_LinkStatistics* Statistics_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);

////private:
State_LinkLayerParser_uint8_t ParseUntilComplete_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
State_LinkLayerParser_uint8_t ParseOneStep_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
State_LinkLayerParser_uint8_t ParseSync_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
State_LinkLayerParser_uint8_t ParseHeader_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
State_LinkLayerParser_uint8_t ParseBody_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);

void PushFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, IFrameSink* sink);

boolean ReadHeader_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
boolean ValidateBody_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
boolean ValidateHeaderParameters_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
boolean ValidateFunctionCode_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
void FailFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);

void TransferUserData_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);

////} // namespace opendnp3

#endif
