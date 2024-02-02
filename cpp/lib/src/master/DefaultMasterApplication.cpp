/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <QApplication>
#include "header.h"
#include "DefaultMasterApplication.h"

#include <chrono>

////namespace opendnp3
////{

void DefaultMasterApplication_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication)
{
  IMasterApplication_in_IMasterApplication(&(pDefaultMasterApplication->iIMasterApplication));

  pDefaultMasterApplication->iIMasterApplication.pOnReceiveIIN_in_IMasterApplication = OnReceiveIIN_in_DefaultMasterApplication_override;

  pDefaultMasterApplication->iIMasterApplication.pOnTaskStart_in_IMasterApplication = OnTaskStart_in_DefaultMasterApplication_override;

  pDefaultMasterApplication->iIMasterApplication.pOnTaskComplete_in_IMasterApplication = OnTaskComplete_in_DefaultMasterApplication_override;

  pDefaultMasterApplication->iIMasterApplication.pAssignClassDuringStartup_in_IMasterApplication = AssignClassDuringStartup_in_DefaultMasterApplication_override;

  pDefaultMasterApplication->iIMasterApplication.pConfigureAssignClassRequest_in_IMasterApplication = ConfigureAssignClassRequest_in_DefaultMasterApplication_override;

  pDefaultMasterApplication->iIMasterApplication.iIUTCTimeSource.pNow_in_IUTCTimeSource = Now_in_DefaultMasterApplication_override;

  pDefaultMasterApplication->iIMasterApplication.iILinkListener.pOnStateChange_in_ILinkListener = OnStateChange_in_DefaultMasterApplication_override;

  setParentPointer_in_IMasterApplication(&(pDefaultMasterApplication->iIMasterApplication), pDefaultMasterApplication);
  setParentPointer_in_IUTCTimeSource(&(pDefaultMasterApplication->iIMasterApplication.iIUTCTimeSource), pDefaultMasterApplication);
  setParentPointer_in_ILinkListener(&(pDefaultMasterApplication->iIMasterApplication.iILinkListener), pDefaultMasterApplication);
}

static DefaultMasterApplication dDefaultMasterApplication;

IMasterApplication* Create_in_DefaultMasterApplication_static(void)
{
////        return std::make_shared<DefaultMasterApplication>();
  DefaultMasterApplication_in_DefaultMasterApplication(&dDefaultMasterApplication);
  return &dDefaultMasterApplication.iIMasterApplication;
}

void OnReceiveIIN_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, IINField* iin)
{
  UNUSED(pDefaultMasterApplication);
  UNUSED(iin);
}
void OnReceiveIIN_in_DefaultMasterApplication_override(void *pIMasterApplication, IINField* iin)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnReceiveIIN_in_DefaultMasterApplication(parent, iin);
}

void OnTaskStart_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, MasterTaskType_uint8_t type, TaskId id)
{
  UNUSED(pDefaultMasterApplication);
  UNUSED(type);
  UNUSED(id);
}
void OnTaskStart_in_DefaultMasterApplication_override(void *pIMasterApplication, MasterTaskType_uint8_t type, TaskId id)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnTaskStart_in_DefaultMasterApplication(parent, type, id);
}

void OnTaskComplete_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, TaskInfo* info)
{
  UNUSED(pDefaultMasterApplication);
  UNUSED(info);
}
void OnTaskComplete_in_DefaultMasterApplication_override(void *pIMasterApplication, TaskInfo* info)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  OnTaskComplete_in_DefaultMasterApplication(parent, info);
}

boolean AssignClassDuringStartup_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication)
{
  UNUSED(pDefaultMasterApplication);
  return false;
}
boolean AssignClassDuringStartup_in_DefaultMasterApplication_override(void *pIMasterApplication)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  return AssignClassDuringStartup_in_DefaultMasterApplication(parent);
}

void ConfigureAssignClassRequest_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, WriteHeaderFunT fun)
{
  UNUSED(pDefaultMasterApplication);
  UNUSED(fun);
}
void ConfigureAssignClassRequest_in_DefaultMasterApplication_override(void *pIMasterApplication, WriteHeaderFunT fun)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_IMasterApplication((IMasterApplication*) pIMasterApplication);
  ConfigureAssignClassRequest_in_DefaultMasterApplication(parent, fun);
}

UTCTimestamp Now_in_DefaultMasterApplication_override(void *pIUTCTimeSource)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_IUTCTimeSource((IUTCTimeSource*) pIUTCTimeSource);
  return Now_in_DefaultMasterApplication(parent);
}

void OnStateChange_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication, LinkStatus_uint8_t value)
{
  UNUSED(pDefaultMasterApplication);
  UNUSED(value);
}
void OnStateChange_in_DefaultMasterApplication_override(void *pILinkListener, LinkStatus_uint8_t value)
{
  DefaultMasterApplication *parent = (DefaultMasterApplication*) getParentPointer_in_ILinkListener((ILinkListener*) pILinkListener);
  OnStateChange_in_DefaultMasterApplication(parent, value);
}

////UTCTimestamp DefaultMasterApplication::Now()
UTCTimestamp Now_in_DefaultMasterApplication(DefaultMasterApplication *pDefaultMasterApplication)
{
  UNUSED(pDefaultMasterApplication);
  uint64_t timet
    = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
      .count();
////    return {time};
  UTCTimestamp uUTCTimestamp;
  UTCTimestamp_in_UTCTimestampOver2(&uUTCTimestamp, timet);
  return uUTCTimestamp;
}

////} // namespace opendnp3
