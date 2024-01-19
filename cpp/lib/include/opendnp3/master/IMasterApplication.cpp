#include "header.h"
#include "IMasterApplication.h"

void IMasterApplication_in_IMasterApplication(IMasterApplication *pIMasterApplication)
{
  pIMasterApplication->pOnReceiveIIN_in_IMasterApplication = OnReceiveIIN_in_IMasterApplication_override;
  pIMasterApplication->pOnTaskStart_in_IMasterApplication  = OnTaskStart_in_IMasterApplication_override;
  pIMasterApplication->pOnTaskComplete_in_IMasterApplication = OnTaskComplete_in_IMasterApplication_override;
  pIMasterApplication->pOnOpen_in_IMasterApplication = OnOpen_in_IMasterApplication_override;
  pIMasterApplication->pOnClose_in_IMasterApplication = OnClose_in_IMasterApplication_override;
  pIMasterApplication->pAssignClassDuringStartup_in_IMasterApplication = AssignClassDuringStartup_in_IMasterApplication_override;
  pIMasterApplication->pConfigureAssignClassRequest_in_IMasterApplication = ConfigureAssignClassRequest_in_IMasterApplication_override;
}

void OnTaskStart_in_IMasterApplication(IMasterApplication *pIMasterApplication, MasterTaskType_uint8_t type, TaskId* id)
{
  (pIMasterApplication->pOnTaskStart_in_IMasterApplication)(pIMasterApplication, type, id);
}
void OnTaskComplete_in_IMasterApplication(IMasterApplication* pIMasterApplication, TaskInfo* info)
{
  (pIMasterApplication->pOnTaskComplete_in_IMasterApplication)(pIMasterApplication, info);
}
void OnReceiveIIN_in_IMasterApplication(IMasterApplication *pIMasterApplication, IINField* iin)
{
  (pIMasterApplication->pOnReceiveIIN_in_IMasterApplication)(pIMasterApplication, iin);
}
void OnOpen_in_IMasterApplication(IMasterApplication* pIMasterApplication)
{
  (pIMasterApplication->pOnOpen_in_IMasterApplication)(pIMasterApplication);
}
void OnClose_in_IMasterApplication(IMasterApplication *pIMasterApplication)
{
  (pIMasterApplication->pOnClose_in_IMasterApplication)(pIMasterApplication);
}
boolean AssignClassDuringStartup_in_IMasterApplication(IMasterApplication *pIMasterApplication)
{
 return (pIMasterApplication->pAssignClassDuringStartup_in_IMasterApplication)(pIMasterApplication);
}
void ConfigureAssignClassRequest_in_IMasterApplication(IMasterApplication *pIMasterApplication, WriteHeaderFunT fun)
{
  (pIMasterApplication->pConfigureAssignClassRequest_in_IMasterApplication)(pIMasterApplication, fun);
}

void OnReceiveIIN_in_IMasterApplication_override(void *pIMasterApplication, IINField* iin)
{
  UNUSED(pIMasterApplication);
  UNUSED(iin);
}
void OnTaskStart_in_IMasterApplication_override(void *pIMasterApplication, MasterTaskType_uint8_t type, TaskId* id)
{
  UNUSED(pIMasterApplication);
  UNUSED(type);
  UNUSED(id);
}
void OnTaskComplete_in_IMasterApplication_override(void* pIMasterApplication, TaskInfo* info)
{
  UNUSED(pIMasterApplication);
  UNUSED(info);
}
void OnOpen_in_IMasterApplication_override(void* pIMasterApplication)
{
  UNUSED(pIMasterApplication);
}
void OnClose_in_IMasterApplication_override(void *pIMasterApplication)
{
  UNUSED(pIMasterApplication);
}
boolean AssignClassDuringStartup_in_IMasterApplication_override(void *pIMasterApplication)
{
  UNUSED(pIMasterApplication);
  return false;
}

void ConfigureAssignClassRequest_in_IMasterApplication_override(void *pIMasterApplication, WriteHeaderFunT fun)
{
  UNUSED(pIMasterApplication);
  UNUSED(fun);
}

void* getParentPointer_in_IMasterApplication(IMasterApplication* pIMasterApplication)
{
  return pIMasterApplication->pParentPointer_in_IMasterApplication;
}
void  setParentPointer_in_IMasterApplication(IMasterApplication* pIMasterApplication, void* pParentPointer)
{
  pIMasterApplication->pParentPointer_in_IMasterApplication = pParentPointer;
}
