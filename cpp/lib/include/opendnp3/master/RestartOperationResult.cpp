
#include "header.h"
#include "RestartOperationResult.h"

void RestartOperationResult_in_RestartOperationResultOver1(RestartOperationResult *pRestartOperationResult)
{
////: summary(TaskCompletion::FAILURE_NO_COMMS) {}
  pRestartOperationResult->summary = TaskCompletion_FAILURE_NO_COMMS;
  TimeDuration_in_TimeDuration(&(pRestartOperationResult->restartTime), 0);
}

void RestartOperationResult_in_RestartOperationResultOver2(RestartOperationResult *pRestartOperationResult, TaskCompletion_uint8_t summary_, TimeDuration restartTime_)
{
  pRestartOperationResult->summary = summary_;
  pRestartOperationResult->restartTime = restartTime_;
}
