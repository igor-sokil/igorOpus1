#include "header.h"
#include "TaskConfig.h"
#include <string.h>

void TaskConfig_in_TaskConfig(TaskConfig *pTaskConfig, TaskId taskId, ITaskCallback* pCallback)
{
  pTaskConfig->taskId = taskId;
  pTaskConfig->pCallback = pCallback;
}

TaskConfig Default_in_TaskConfig_static(void)
{
////        return TaskConfig(TaskId::Undefined(), nullptr);
  TaskConfig tTaskConfig;
  TaskConfig_in_TaskConfig(&tTaskConfig, Undefined_in_TaskId_static(), NULL);
  return tTaskConfig;
}

TaskConfig With_in_TaskConfig_static(ITaskCallback* callback)
{
////        return TaskConfig(TaskId::Undefined(), callback);
  TaskConfig tTaskConfig;
  TaskConfig_in_TaskConfig(&tTaskConfig, Undefined_in_TaskId_static(), callback);
  return tTaskConfig;
}
