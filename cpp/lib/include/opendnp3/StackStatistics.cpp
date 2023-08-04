#include "header.h"
#include "StackStatistics.h"

void Link_StackStatistics_in_Link_StackStatistics(Link_StackStatistics *pLink_StackStatistics)
{
  pLink_StackStatistics->numUnexpectedFrame = 0;

  /// frames received w/ wrong master bit
  pLink_StackStatistics->numBadMasterBit = 0;

  /// frames received for an unknown destination
  pLink_StackStatistics->numUnknownDestination = 0;

  /// frames received for an unknown source
  pLink_StackStatistics->numUnknownSource = 0;
}

void Rx_Transport_in_Rx_Transport(Rx_Transport *pRx_Transport)
{
  pRx_Transport->numTransportRx = 0;

  /// Number of TPDUs dropped due to malformed contents
  pRx_Transport->numTransportErrorRx = 0;

  /// Number of times received data was too big for reassembly buffer
  pRx_Transport->numTransportBufferOverflow = 0;

  /// number of times transport buffer is discard due to new FIR
  pRx_Transport->numTransportDiscard = 0;

  /// number of segments ignored due to bad FIR/FIN or SEQ
  pRx_Transport->numTransportIgnore = 0;
}

void Tx_Transport_in_Tx_Transport(Tx_Transport *pTx_Transport)
{
  pTx_Transport->numTransportTx = 0;
}

void Transport_StackStatistics_in_Transport_StackStatisticsOver1(Transport_StackStatistics *pTransport_StackStatistics)
{
  Tx_Transport_in_Tx_Transport(&(pTransport_StackStatistics->tx));
  Rx_Transport_in_Rx_Transport(&(pTransport_StackStatistics->rx));
}

void Transport_StackStatistics_in_Transport_StackStatisticsOver2(Transport_StackStatistics *pTransport_StackStatistics,
    Rx_Transport* rx, Tx_Transport* tx)
{
  pTransport_StackStatistics->tx = *tx;
  pTransport_StackStatistics->rx = *rx;
}

void StackStatistics_in_StackStatisticsOver1(StackStatistics *pStackStatistics)
{
  Link_StackStatistics_in_Link_StackStatistics(&(pStackStatistics->link));
  Transport_StackStatistics_in_Transport_StackStatisticsOver1(&(pStackStatistics->transport));
}

void StackStatistics_in_StackStatisticsOver2(StackStatistics *pStackStatistics,
    Link_StackStatistics* link, Transport_StackStatistics* transport)
{
  pStackStatistics->link = *link;
  pStackStatistics->transport = *transport;
}
