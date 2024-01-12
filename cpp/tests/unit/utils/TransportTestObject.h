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
#ifndef OPENDNP3_UNITTESTS_TRANSPORT_TEST_OBJECT_H
#define OPENDNP3_UNITTESTS_TRANSPORT_TEST_OBJECT_H

#include "AppConstants.h"
////#include <opendnp3/logging/LogLevels.h>

#include "MockExecutorExe4cpp.h"

#include "MockLinkLayer.h"
///#include "MockLogHandler.h"
#include "MockUpperLayer.h"

#include "TransportLayer.h"

////#include <string>
////#include <vector>

////class TransportTestObject
typedef struct
{
////public:
////    TransportTestObject(bool openOnStart = false, uint32_t maxRxFragmentSize = opendnp3::DEFAULT_MAX_APDU_SIZE);

  // Generate a complete packet sequence inside the vector and
  // return the corresponding reassembled APDU
// Генерируем полную последовательность пакетов внутри вектора и
  // возвращаем соответствующий пересобранный APDU
////    std::string GeneratePacketSequence(std::vector<std::string>&, uint32_t aNumPackets, uint32_t aLastPacketLength);

  // Get a Sequence of data w/ optional header
// Получаем последовательность данных с необязательным заголовком
////    std::string GetData(const std::string& arHdr, uint8_t aSeed = 0, uint32_t aLength = opendnp3::MAX_TPDU_PAYLOAD);

////    MockLogHandler log;
  MockExecutor exe;
  TransportLayer transport;
  MockLinkLayer link;
  MockUpperLayer upper;
} TransportTestObject;

void TransportTestObject_in_TransportTestObject(TransportTestObject *pTransportTestObject, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
std::string GeneratePacketSequence_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::vector<std::string>&, uint32_t aNumPackets, uint32_t aLastPacketLength);
std::string GetData_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::string& arHdr, uint8_t aSeed,/* = 0,*/ uint32_t aLength);// = opendnp3::MAX_TPDU_PAYLOAD);

#endif
