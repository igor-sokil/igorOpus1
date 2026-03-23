#include "log_info.h"
//#ifndef  LOG_INFO_INC
#include <iostream>
//#endif
#include <QApplication>
#include "header.h"
#include "MockMasterApplication.h"

void MockMasterApplication_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication)
{
  pMockMasterApplication->timeMasterApplication = 0;

  pMockMasterApplication->iIMasterApplication.iIUTCTimeSource.pNow_in_IUTCTimeSource = Now_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pOnReceiveIIN_in_IMasterApplication = OnReceiveIIN_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pOnTaskStart_in_IMasterApplication = OnTaskStart_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pOnTaskComplete_in_IMasterApplication = OnTaskComplete_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pOnOpen_in_IMasterApplication = OnOpen_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pOnClose_in_IMasterApplication = OnClose_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pAssignClassDuringStartup_in_IMasterApplication = AssignClassDuringStartup_in_MockMasterApplication_override;
  pMockMasterApplication->iIMasterApplication.pConfigureAssignClassRequest_in_IMasterApplication = ConfigureAssignClassRequest_in_MockMasterApplication_override;

  setParentPointer_in_IMasterApplication(&(pMockMasterApplication->iIMasterApplication), pMockMasterApplication);
  setParentPointer_in_IUTCTimeSource(&(pMockMasterApplication->iIMasterApplication.iIUTCTimeSource), pMockMasterApplication);
//  setParentPointer_in_ILinkListener(&(pMockMasterApplication->iILinkListener), pMockMasterApplication);
}

////    virtual opendnp3::UTCTimestamp Now() override
UTCTimestamp Now_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication)
{
////        return opendnp3::UTCTimestamp(time);
  UTCTimestamp uUTCTimestamp;
  UTCTimestamp_in_UTCTimestampOver2(&uUTCTimestamp, pMockMasterApplication->timeMasterApplication);
  return uUTCTimestamp;
}
UTCTimestamp Now_in_MockMasterApplication_override(void *pIUTCTimeSource)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IUTCTimeSource((IUTCTimeSource*) pIUTCTimeSource);
  return Now_in_MockMasterApplication(parent);
}

void OnReceiveIIN_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, IINField* iin)
{
  pMockMasterApplication->rxIIN.push_back(*iin);
}

void OnReceiveIIN_in_MockMasterApplication_override(void *pIMasterApplication, IINField* iin)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnReceiveIIN_in_MockMasterApplication(parent, iin);
}

void OnTaskStart_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, MasterTaskType_uint8_t type, TaskId id)
{
  UNUSED(id);
  pMockMasterApplication->taskStartEvents.push_back(type);
}
void OnTaskStart_in_MockMasterApplication_override(void *pIMasterApplication, MasterTaskType_uint8_t type, TaskId id)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnTaskStart_in_MockMasterApplication(parent, type, id);
}

void OnTaskComplete_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, TaskInfo* info)
{
  pMockMasterApplication->taskCompletionEvents.push_back(*info);
}
void OnTaskComplete_in_MockMasterApplication_override(void *pIMasterApplication, TaskInfo* info)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnTaskComplete_in_MockMasterApplication(parent, info);
}

void OnOpen_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication)
{
   std::cout<<'\n';
   std::cout<<"OnOpen_in_MockMasterApplication1"<<'\n';
  pMockMasterApplication->stateChanges.push_back(State_in_MockMasterApplication_OPEN);
}
void OnOpen_in_MockMasterApplication_override(void *pIMasterApplication)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnOpen_in_MockMasterApplication(parent);
}

void OnClose_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication)
{
   std::cout<<'\n';
   std::cout<<"OnClose_in_MockMasterApplication1"<<'\n';
  pMockMasterApplication->stateChanges.push_back(State_in_MockMasterApplication_CLOSED);
}
void OnClose_in_MockMasterApplication_override(void *pIMasterApplication)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnClose_in_MockMasterApplication(parent);
}

boolean AssignClassDuringStartup_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication)
{
  return !pMockMasterApplication->assignClassHeaders.empty();
}
boolean AssignClassDuringStartup_in_MockMasterApplication_override(void *pIMasterApplication)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  return AssignClassDuringStartup_in_MockMasterApplication(parent);
}

void ConfigureAssignClassRequest_in_MockMasterApplication(MockMasterApplication *pMockMasterApplication, WriteHeaderFunT fun)
{
  for (auto& header : pMockMasterApplication->assignClassHeaders)
  {
    fun(&header);
  }
}
void ConfigureAssignClassRequest_in_MockMasterApplication_override(void *pIMasterApplication, WriteHeaderFunT fun)
{
  MockMasterApplication *parent = (MockMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  ConfigureAssignClassRequest_in_MockMasterApplication(parent, fun);
}
