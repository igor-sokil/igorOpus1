#include "header.h"
#include "ICommandTaskResult.h"

void ICommandTaskResult_in_ICommandTaskResult(ICommandTaskResult *pICommandTaskResult, TaskCompletion_uint8_t result_)
{
  pICommandTaskResult->summary = result_;
}
