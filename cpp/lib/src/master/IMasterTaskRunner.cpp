#include  "header.h"
#include  "IMasterTaskRunner.h"

boolean Run_in_IMasterTaskRunner(IMasterTaskRunner *pIMasterTaskRunner, IMasterTask* task)
{
  return (pIMasterTaskRunner->pRun_in_IMasterTaskRunner)(pIMasterTaskRunner, task);
}

void* getParentPointer_in_IMasterTaskRunner(IMasterTaskRunner* pIMasterTaskRunner)
{
  return pIMasterTaskRunner->pParentPointer_in_IMasterTaskRunner;
}
void  setParentPointer_in_IMasterTaskRunner(IMasterTaskRunner* pIMasterTaskRunner, void* pParentPointer)
{
  pIMasterTaskRunner->pParentPointer_in_IMasterTaskRunner = pParentPointer;
}
