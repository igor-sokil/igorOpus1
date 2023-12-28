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
#ifndef OPENDNP3_STACKSTATISTICS_H
#define OPENDNP3_STACKSTATISTICS_H

////#include <cstdint>

////namespace opendnp3
////{

///    struct Link
typedef struct
{
  /// number of unexpected frames
  uint16_t numUnexpectedFrame;// = 0;

  /// frames received w/ wrong master bit
  uint16_t numBadMasterBit;// = 0;

  /// frames received for an unknown destination
  uint16_t numUnknownDestination;// = 0;

  /// frames received for an unknown source
  uint16_t numUnknownSource;// = 0;
} Link_StackStatistics;
void Link_StackStatistics_in_Link_StackStatistics(Link_StackStatistics *pLink_StackStatistics);

///        struct Rx
typedef struct
{
  /// Number of valid TPDU's received
  uint16_t numTransportRx;// = 0;

  /// Number of TPDUs dropped due to malformed contents
  uint16_t numTransportErrorRx;// = 0;

  /// Number of times received data was too big for reassembly buffer
  uint16_t numTransportBufferOverflow;// = 0;

  /// number of times transport buffer is discard due to new FIR
  uint16_t numTransportDiscard;// = 0;

  /// number of segments ignored due to bad FIR/FIN or SEQ
  uint16_t numTransportIgnore;// = 0;
} Rx_Transport;

void Rx_Transport_in_Rx_Transport(Rx_Transport *pRx_Transport);
////        struct Tx
typedef struct
{
  /// Number of TPDUs transmitted
  uint16_t numTransportTx;// = 0;
} Tx_Transport;
void Tx_Transport_in_Tx_Transport(Tx_Transport *pTx_Transport);

////    struct Transport
typedef struct
{

////        Transport() = default;
////        Transport(const Rx& rx, const Tx& tx) : rx(rx), tx(tx) {}

  Rx_Transport rx;
  Tx_Transport tx;
} Transport_StackStatistics;

void Transport_StackStatistics_in_Transport_StackStatisticsOver1(Transport_StackStatistics *pTransport_StackStatistics);
void Transport_StackStatistics_in_Transport_StackStatisticsOver2(Transport_StackStatistics *pTransport_StackStatistics,
    Rx_Transport* rx, Tx_Transport* tx);


/**
 * Statistics related to both a master or outstation session
* Статистика, относящаяся как к главному, так и к внешнему сеансу.
 */
////struct StackStatistics
typedef struct
{

////    StackStatistics() = default;

////    StackStatistics(const Link& link, const Transport& transport) : link(link), transport(transport) {}

  Link_StackStatistics link;
  Transport_StackStatistics transport;
} StackStatistics;

void StackStatistics_in_StackStatisticsOver1(StackStatistics *pStackStatistics);
void StackStatistics_in_StackStatisticsOver2(StackStatistics *pStackStatistics,
    Link_StackStatistics* link, Transport_StackStatistics* transport);


////} // namespace opendnp3

#endif
