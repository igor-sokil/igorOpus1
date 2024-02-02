#include "header.h"
#include "IMasterScheduler.h"

//void IMasterScheduler_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler)
///{
/// pIMasterScheduler->pAdd_in_IMasterScheduler = Add_in_IMasterScheduler_override;
/// setParentPointer_in_IMasterScheduler(pIMasterScheduler->pParentPointer_in_IMasterScheduler, pIMasterScheduler);
///}
///void Add_in_IMasterScheduler_override(void *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner)
///{
/// IMasterScheduler* parent = (IMasterScheduler*)getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
/// Add_in_IMasterSchedulerOver2(parent, tasks, runner);
///}

void Shutdown_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler)
{
  (pIMasterScheduler->pShutdown_in_IMasterScheduler)(pIMasterScheduler);
}
void Add_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner)
{
  (pIMasterScheduler->pAdd_in_IMasterScheduler)(pIMasterScheduler, task, runner);
}
void SetRunnerOffline_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTaskRunner* runner)
{
  (pIMasterScheduler->pSetRunnerOffline_in_IMasterScheduler)(pIMasterScheduler, runner);
}
boolean CompleteCurrentFor_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTaskRunner* runner)
{
  return (pIMasterScheduler->pCompleteCurrentFor_in_IMasterScheduler)(pIMasterScheduler, runner);
}
void Evaluate_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler)
{
  (pIMasterScheduler->pEvaluate_in_IMasterScheduler)(pIMasterScheduler);
}
void Demand_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTask* task)
{
  (pIMasterScheduler->pDemand_in_IMasterScheduler)(pIMasterScheduler, task);
}

//void Add_in_IMasterSchedulerOver2(IMasterScheduler *pIMasterScheduler, IMasterTask* tasks, IMasterTaskRunner* runner)
//{
//  Add_in_IMasterScheduler(pIMasterScheduler, tasks, runner);
//}

void* getParentPointer_in_IMasterScheduler(IMasterScheduler* pIMasterScheduler)
{
  return pIMasterScheduler->pParentPointer_in_IMasterScheduler;
}
void  setParentPointer_in_IMasterScheduler(IMasterScheduler* pIMasterScheduler, void* pParentPointer)
{
  pIMasterScheduler->pParentPointer_in_IMasterScheduler = pParentPointer;
}
