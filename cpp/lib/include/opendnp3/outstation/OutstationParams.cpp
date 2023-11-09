#include "header.h"
#include "OutstationParams.h"

void OutstationParams_in_OutstationParams(OutstationParams *pOutstationParams)
{
  pOutstationParams->maxControlsPerRequest = 4'294'967'295;

  /// How long the outstation will allow an operate to proceed after a prior select
/// Как долго удаленная станция позволит продолжить работу после предварительного выбора
  pOutstationParams->selectTimeout = Seconds_in_TimeDuration_static(10);

  /// Timeout for solicited confirms
/// Таймаут для запрошенных подтверждений
  pOutstationParams->solConfirmTimeout = Seconds_in_TimeDuration_static(DEFAULT_APP_TIMEOUT);// = DEFAULT_APP_TIMEOUT;

  /// Timeout for unsolicited confirms
/// Тайм-аут для незапрошенных подтверждений
  pOutstationParams->unsolConfirmTimeout = Seconds_in_TimeDuration_static(DEFAULT_APP_TIMEOUT);// = DEFAULT_APP_TIMEOUT;

  /// Number of unsolicited non-regenerated retries
/// Количество незапрошенных невосстановленных повторных попыток
  pOutstationParams->numUnsolRetries = Infinite_in_NumRetries_static();// = NumRetries::Infinite();

  /// Workaround for test procedure 8.11.2.1. Will respond immediatly to READ requests
  /// when waiting for unsolicited NULL responses.
/// Обходной путь для процедуры тестирования 8.11.2.1. Будет немедленно отвечать на запросы READ
   /// при ожидании незапрошенных NULL-ответов.
  ///
  /// @warning This is NOT compliant to IEEE-1815-2012.
  pOutstationParams->noDefferedReadDuringUnsolicitedNullResponse = false;

  /// The maximum fragment size the outstation will use for fragments it sends
/// Максимальный размер фрагмента, который удаленная станция будет использовать для отправляемых фрагментов
  pOutstationParams->maxTxFragSize = DEFAULT_MAX_APDU_SIZE;

  /// The maximum fragment size the outstation will be able to receive
/// Максимальный размер фрагмента, который сможет получить удаленная станция
  pOutstationParams->maxRxFragSize = DEFAULT_MAX_APDU_SIZE;

  /// Global enabled / disable for unsolicited messages. If false, the NULL unsolicited message is not even sent
/// Глобальное включение/выключение нежелательных сообщений. Если false, незапрошенное сообщение NULL даже не отправляется.
  pOutstationParams->allowUnsolicited = false;

  /// A bitmask type that specifies the types allowed in a class 0 reponse
/// Тип битовой маски, определяющий типы, разрешенные в ответе класса 0
  pOutstationParams->typesAllowedInClass0 = AllTypes_in_StaticTypeBitField_static();

  /// Class mask for unsolicted, default to 0 as unsolicited has to be enabled
/// Маска класса для нежелательных сообщений, по умолчанию 0, поскольку нежелательные запросы должны быть включены
  pOutstationParams->unsolClassMask = None_in_ClassField_static();

  /// If true, the outstation processes responds to any request/confirmation as if it came from the expected master
  /// address
/// Если true, процессы внешней станции отвечают на любой запрос/подтверждение, как если бы оно пришло от ожидаемого ведущего устройства
   /// адрес
  pOutstationParams->respondToAnyMaster = false;
}
