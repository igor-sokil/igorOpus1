#include "header.h"
#include "MasterParams.h"

void MasterParams_in_MasterParams(MasterParams *pMasterParams)
{
  pMasterParams->responseTimeout = Seconds_in_TimeDuration_static(5);

  pMasterParams->timeSyncMode = TimeSyncMode_None;

  pMasterParams->disableUnsolOnStartup = true;

  pMasterParams->ignoreRestartIIN = false;

  pMasterParams->unsolClassMask = AllEventClasses_in_ClassField_static();

  pMasterParams->startupIntegrityClassMask = AllClasses_in_ClassField_static();

  pMasterParams->integrityOnEventOverflowIIN = true;

  pMasterParams->eventScanOnEventsAvailableClassMask = None_in_ClassField_static();

  pMasterParams->taskRetryPeriod = Seconds_in_TimeDuration_static(5);

  pMasterParams->maxTaskRetryPeriod = Minutes_in_TimeDuration_static(1);

  pMasterParams->taskStartTimeout = Seconds_in_TimeDuration_static(10);

  pMasterParams->maxTxFragSize = DEFAULT_MAX_APDU_SIZE;

  pMasterParams->maxRxFragSize = DEFAULT_MAX_APDU_SIZE;

  pMasterParams->controlQualifierMode = IndexQualifierMode_always_two_bytes;
}
