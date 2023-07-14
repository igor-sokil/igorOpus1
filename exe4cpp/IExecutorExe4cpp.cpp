#include "header.h"
#include "IExecutorExe4cpp.h"

TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *pIExecutorExe4cpp, uint32_t duration, void (*pAction)(void))
{
  return (pIExecutorExe4cpp->pStart_in_IExecutorExe4cpp)(pIExecutorExe4cpp, duration, pAction);
}

void Post_in_IExecutorExe4cpp(IExecutorExe4cpp *pIExecutorExe4cpp, void (*pAction)(void))
{
  return (pIExecutorExe4cpp->pPost_in_IExecutorExe4cpp)(pIExecutorExe4cpp, pAction);
}

void* getParentPointer_in_IExecutorExe4cpp(IExecutorExe4cpp* pIExecutorExe4cpp)
{
  return pIExecutorExe4cpp->pParentPointer_in_IExecutorExe4cpp;
}

void  setParentPointer_in_IExecutorExe4cpp(IExecutorExe4cpp* pIExecutorExe4cpp, void* pParentPointer)
{
  pIExecutorExe4cpp->pParentPointer_in_IExecutorExe4cpp = pParentPointer;
}

