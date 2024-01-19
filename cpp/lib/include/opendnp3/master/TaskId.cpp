#include "header.h"
#include "TaskId.h"

TaskId Defined_in_TaskId_static(int id)
{
////        return TaskId(id, true);
  TaskId tTaskId;
  TaskId_in_TaskId(&tTaskId, id, true);
  return tTaskId;
}

TaskId Undefined_in_TaskId_static(void)
{
////        return TaskId(-1, false);
  TaskId tTaskId;
  TaskId_in_TaskId(&tTaskId, -1, true);
  return tTaskId;
}

int GetId_in_TaskId(TaskId *pTaskId)
{
  return pTaskId->id;
}
boolean IsDefined_in_TaskId(TaskId *pTaskId)
{
  return pTaskId->isDefined;
}

void TaskId_in_TaskId(TaskId *pTaskId, int id_, boolean isDefined_)
{
  pTaskId->id = id_;
  pTaskId->isDefined = isDefined_;
}
