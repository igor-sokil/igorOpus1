#include "log_info.h"
//#ifndef  LOG_INFO_INC
#include <iostream>
//#endif
#include <QApplication>
#include "header.h"
#include "MockOutstationApplication.h"

////    MockOutstationApplication()
////        : currentTime(opendnp3::DNPTime(0, opendnp3::TimestampQuality::INVALID)),
////          supportsTimeWrite(true),
////          supportsAssignClass(false),
////          supportsWriteTimeAndInterval(false),
////          allowTimeWrite(true),
////          warmRestartSupport(opendnp3::RestartMode::UNSUPPORTED),
////          coldRestartSupport(opendnp3::RestartMode::UNSUPPORTED),
////          warmRestartTimeDelay(0),
////          coldRestartTimeDelay(0)
////    {
////    }

void MockOutstationApplication_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
//  void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
////        : currentTime(opendnp3::DNPTime(0, opendnp3::TimestampQuality::INVALID)),
  DNPTime_in_DNPTimeOver2(&(pMockOutstationApplication->currentTime), TimestampQuality_INVALID);

  ApplicationIIN_in_ApplicationIIN(&(pMockOutstationApplication->appIIN));

  pMockOutstationApplication->supportsTimeWrite = true;
  pMockOutstationApplication->supportsAssignClass = false;
  pMockOutstationApplication->supportsWriteTimeAndInterval = false;
  pMockOutstationApplication->allowTimeWrite = true;

  pMockOutstationApplication->warmRestartSupport = RestartMode_UNSUPPORTED;
  pMockOutstationApplication->coldRestartSupport = RestartMode_UNSUPPORTED;

  pMockOutstationApplication->warmRestartTimeDelay = 0;
  pMockOutstationApplication->coldRestartTimeDelay = 0;

  pMockOutstationApplication->iIOutstationApplication.iIDnpTimeSource.pNow_in_IDnpTimeSource_static = Now_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.iILinkListener.pOnStateChange_in_ILinkListener = OnStateChange_in_MockOutstationApplication_override;

  pMockOutstationApplication->iIOutstationApplication.pSupportsWriteAbsoluteTime_in_IOutstationApplication = SupportsWriteAbsoluteTime_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pWriteAbsoluteTime_in_IOutstationApplication = WriteAbsoluteTime_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pSupportsWriteTimeAndInterval_in_IOutstationApplication = SupportsWriteTimeAndInterval_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pWriteTimeAndInterval_in_IOutstationApplication = WriteTimeAndInterval_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pSupportsAssignClass_in_IOutstationApplication = SupportsAssignClass_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pRecordClassAssignment_in_IOutstationApplication = RecordClassAssignment_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pGetApplicationIIN_in_IOutstationApplication = GetApplicationIIN_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pColdRestartSupport_in_IOutstationApplication = ColdRestartSupport_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pWarmRestartSupport_in_IOutstationApplication = WarmRestartSupport_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pColdRestart_in_IOutstationApplication = ColdRestart_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pWarmRestart_in_IOutstationApplication = WarmRestart_in_MockOutstationApplication_override;
  pMockOutstationApplication->iIOutstationApplication.pOnConfirmProcessed_in_IOutstationApplication = OnConfirmProcessed_in_MockOutstationApplication_override;

  setParentPointer_in_IDnpTimeSource(&(pMockOutstationApplication->iIOutstationApplication.iIDnpTimeSource), pMockOutstationApplication);
  setParentPointer_in_ILinkListener(&(pMockOutstationApplication->iIOutstationApplication.iILinkListener), pMockOutstationApplication);

  setParentPointer_in_IOutstationApplication(&(pMockOutstationApplication->iIOutstationApplication), pMockOutstationApplication);
}

DNPTime Now_in_MockOutstationApplication_override(void *pIDnpTimeSource)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IDnpTimeSource((IDnpTimeSource*)pIDnpTimeSource);
  return Now_in_MockOutstationApplication(parent);
}

void OnStateChange_in_MockOutstationApplication_override(void *pILinkListener, LinkStatus_uint8_t value)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_ILinkListener((ILinkListener*)pILinkListener);
  OnStateChange_in_MockOutstationApplication(parent, value);
}

boolean SupportsWriteAbsoluteTime_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return SupportsWriteAbsoluteTime_in_MockOutstationApplication(parent);
}

boolean WriteAbsoluteTime_in_MockOutstationApplication_override(void *pIOutstationApplication, UTCTimestamp* timestamp)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return WriteAbsoluteTime_in_MockOutstationApplication(parent, timestamp);
}

boolean SupportsWriteTimeAndInterval_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return SupportsWriteTimeAndInterval_in_MockOutstationApplication(parent);
}
/*
WriteTimeAndInterval_in_MockOutstationApplication
`WriteTimeAndInterval_in_MockOutstationApplication(MockOutstationApplication*, ICollection_Indexed_for_TimeAndInterval*)
*/
boolean WriteTimeAndInterval_in_MockOutstationApplication_override(void *pIOutstationApplication,
    ICollection_Indexed_for_TimeAndInterval* meas)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return __WriteTimeAndInterval_in_MockOutstationApplication(parent, meas);
}

boolean SupportsAssignClass_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return SupportsAssignClass_in_MockOutstationApplication(parent);
}

void RecordClassAssignment_in_MockOutstationApplication_override(void *pIOutstationApplication,
    AssignClassType_uint8_t type,
    PointClass_uint8_t clazz,
    uint16_t start,
    uint16_t stop)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  RecordClassAssignment_in_MockOutstationApplication(parent,
      type,
      clazz,
      start,
      stop);
}

ApplicationIIN GetApplicationIIN_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return GetApplicationIIN_in_MockOutstationApplication(parent);
}

RestartMode_uint8_t ColdRestartSupport_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return ColdRestartSupport_in_MockOutstationApplication(parent);
}

RestartMode_uint8_t WarmRestartSupport_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return WarmRestartSupport_in_MockOutstationApplication(parent);
}

uint16_t ColdRestart_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return ColdRestart_in_MockOutstationApplication(parent);
}

uint16_t WarmRestart_in_MockOutstationApplication_override(void *pIOutstationApplication)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  return WarmRestart_in_MockOutstationApplication(parent);
}

void OnConfirmProcessed_in_MockOutstationApplication_override(void *pIOutstationApplication,
    boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3)
{
  MockOutstationApplication* parent = (MockOutstationApplication*)getParentPointer_in_IOutstationApplication((IOutstationApplication*)pIOutstationApplication);
  OnConfirmProcessed_in_MockOutstationApplication(parent,
      is_unsolicited, num_class1, num_class2, num_class3);
}

DNPTime Now_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->currentTime;
}

void OnStateChange_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication, LinkStatus_uint8_t value)
{
  UNUSED(pMockOutstationApplication);
  UNUSED(value);
}

boolean SupportsWriteAbsoluteTime_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->supportsTimeWrite;
}

boolean WriteAbsoluteTime_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication, UTCTimestamp* timestamp)
{
  if (pMockOutstationApplication->allowTimeWrite)
  {
    UTCTimestamp Timestamp;
    Timestamp = *timestamp;
    pMockOutstationApplication->timestamps.push_back(Timestamp);
    return true;
  }
  else
  {
    return false;
  }
}

boolean SupportsWriteTimeAndInterval_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->supportsWriteTimeAndInterval;
}

void __push_in_MockOutstationApplication(Indexed_for_TimeAndInterval* value);

//            void (*fun)(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval,
//            Indexed_for_TimeAndInterval* item));
////        auto push = [this](const opendnp3::Indexed<opendnp3::TimeAndInterval>& value)
void __push_in_MockOutstationApplication(Indexed_for_TimeAndInterval* value)
{
//  pPointerGlobal1 = pMockOutstationApplication;
  Indexed_for_TimeAndInterval iIndexed_for_TimeAndInterval;
  iIndexed_for_TimeAndInterval = *value;
////            this->timeAndIntervals.push_back(value);
  ((MockOutstationApplication*)pPointerGlobal1)->timeAndIntervals.push_back(iIndexed_for_TimeAndInterval);
}

boolean __WriteTimeAndInterval_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication,
    ICollection_Indexed_for_TimeAndInterval* meas);

/*
__WriteTimeAndInterval_in_MockOutstationApplication(MockOutstationApplication*, ICollection_Indexed_for_TimeAndInterval*)
*/
boolean __WriteTimeAndInterval_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication,
    ICollection_Indexed_for_TimeAndInterval* meas)
{
////        auto push = [this](const opendnp3::Indexed<opendnp3::TimeAndInterval>& value) {
////            this->timeAndIntervals.push_back(value);
////        };

//void ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(
//            ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval,
//            void (*fun)(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval,
//            Indexed_for_TimeAndInterval* item));
////        meas.ForeachItem(push);
  pPointerGlobal1 = pMockOutstationApplication;
  ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(meas, __push_in_MockOutstationApplication);
  return true;
}

boolean SupportsAssignClass_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->supportsAssignClass;
}

void RecordClassAssignment_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication,
    AssignClassType_uint8_t type,
    PointClass_uint8_t clazz,
    uint16_t start,
    uint16_t stop)
{
   std::cout<<'\n';
   std::cout<<"RecordClassAssignment_in_MockOutstationApplication1"<<'\n';
   std::cout<<"*AssignClassType_uint8_t type= "<<(uint16_t)type<<'\n';
   std::cout<<"*PointClass_uint8_t clazz= "<<(uint16_t)clazz<<'\n';
   std::cout<<"*uint16_t start= "<<(uint16_t)start<<'\n';
   std::cout<<"*uint16_t stop= "<<(uint16_t)stop<<'\n';
  pMockOutstationApplication->classAssignments.push_back(std::make_tuple(type, clazz, start, stop));
}

ApplicationIIN GetApplicationIIN_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->appIIN;
}

RestartMode_uint8_t ColdRestartSupport_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->coldRestartSupport;
}

RestartMode_uint8_t WarmRestartSupport_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->warmRestartSupport;
}

uint16_t ColdRestart_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->coldRestartTimeDelay;
}

uint16_t WarmRestart_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication)
{
  return pMockOutstationApplication->warmRestartTimeDelay;
}

void OnConfirmProcessed_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication,
    boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3)
{
  ConfirmResult confirm{};
  confirm.is_unsolicited = is_unsolicited;
  confirm.num_class1 = num_class1;
  confirm.num_class2 = num_class2;
  confirm.num_class3 = num_class3;
  pMockOutstationApplication->confirms.push_back(confirm);
}
