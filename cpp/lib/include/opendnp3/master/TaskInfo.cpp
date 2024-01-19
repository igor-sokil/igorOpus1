#include "header.h"
#include "TaskInfo.h"

void TaskInfo_in_TaskInfo(TaskInfo *pTaskInfo, MasterTaskType_uint8_t type_, TaskCompletion_uint8_t result_, TaskId id_)
{
  pTaskInfo->type = type_;
  pTaskInfo->result = result_;
  pTaskInfo->id = id_;
}
