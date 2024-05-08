#ifndef OPENDNP3_UNITTESTS_TRANSPORT_MRZS_OBJECT_H
#define OPENDNP3_UNITTESTS_TRANSPORT_MRZS_OBJECT_H

//#include "AppConstants.h"
////#include <opendnp3/logging/LogLevels.h>

///#include "MockExecutorExe4cpp.h"

////#include "MockLinkLayer.h"
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
////  MockExecutor exe;
  TransportLayer transport;
//  MockLinkLayer link;
  MockUpperLayer upper;
} TransportObjectMrzs;

void TransportObjectMrzs_in_TransportObjectMrzs(TransportObjectMrzs *pTransportObjectMrzs, boolean openOnStart,/* = false,*/ uint32_t maxRxFragmentSize);// = opendnp3::DEFAULT_MAX_APDU_SIZE);
///std::string GeneratePacketSequence_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::vector<std::string>&, uint32_t aNumPackets, uint32_t aLastPacketLength);
///std::string GetData_in_TransportTestObject(TransportTestObject *pTransportTestObject, std::string& arHdr, uint8_t aSeed,/* = 0,*/ uint32_t aLength);// = opendnp3::MAX_TPDU_PAYLOAD);

#endif