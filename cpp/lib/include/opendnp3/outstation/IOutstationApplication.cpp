#include "header.h"
#include "IOutstationApplication.h"

    boolean SupportsWriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
 return (pIOutstationApplication->pSupportsWriteAbsoluteTime_in_IOutstationApplication)(pIOutstationApplication);
}
//    boolean WriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication, UTCTimestamp* timestamp);
    boolean SupportsWriteTimeAndInterval_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
 return (pIOutstationApplication->pSupportsWriteTimeAndInterval_in_IOutstationApplication)(pIOutstationApplication);
}

//    boolean WriteTimeAndInterval_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication, ICollection__for__Indexed_for_TimeAndInterval* values);
     boolean SupportsAssignClass_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
 return (pIOutstationApplication->pSupportsAssignClass_in_IOutstationApplication)(pIOutstationApplication);
}

    void RecordClassAssignment_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication, AssignClassType_uint8_t type, PointClass_uint8_t clazz, uint16_t start, uint16_t stop)
{
   (pIOutstationApplication->pRecordClassAssignment_in_IOutstationApplication)(pIOutstationApplication, type, clazz, start, stop);
}

    ApplicationIIN GetApplicationIIN_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
  return (pIOutstationApplication->pGetApplicationIIN_in_IOutstationApplication)(pIOutstationApplication);
}

    RestartMode_uint8_t ColdRestartSupport_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
  return (pIOutstationApplication->pColdRestartSupport_in_IOutstationApplication)(pIOutstationApplication);
}

    RestartMode_uint8_t WarmRestartSupport_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
  return (pIOutstationApplication->pWarmRestartSupport_in_IOutstationApplication)(pIOutstationApplication);
}

    uint16_t ColdRestart_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
  return (pIOutstationApplication->pColdRestart_in_IOutstationApplication)(pIOutstationApplication);
}

    uint16_t WarmRestart_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
  return (pIOutstationApplication->pWarmRestart_in_IOutstationApplication)(pIOutstationApplication);
}

    void OnConfirmProcessed_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3)
{
   (pIOutstationApplication->pOnConfirmProcessed_in_IOutstationApplication)(pIOutstationApplication, is_unsolicited, num_class1, num_class2, num_class3);
}

    void IOutstationApplication_destr_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
   (pIOutstationApplication->pIOutstationApplication_destr_IOutstationApplication)(pIOutstationApplication);
}


    void IOutstationApplication_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
    pIOutstationApplication->pSupportsWriteAbsoluteTime_in_IOutstationApplication = SupportsWriteAbsoluteTime_in_IOutstationApplication_default;
    pIOutstationApplication->pSupportsWriteTimeAndInterval_in_IOutstationApplication = SupportsWriteTimeAndInterval_in_IOutstationApplication_default;
    pIOutstationApplication->pSupportsAssignClass_in_IOutstationApplication = SupportsAssignClass_in_IOutstationApplication_default;
    pIOutstationApplication->pRecordClassAssignment_in_IOutstationApplication = RecordClassAssignment_in_IOutstationApplication_default;
    pIOutstationApplication->pGetApplicationIIN_in_IOutstationApplication = GetApplicationIIN_in_IOutstationApplication_default;
    pIOutstationApplication->pColdRestartSupport_in_IOutstationApplication = ColdRestartSupport_in_IOutstationApplication_default;
    pIOutstationApplication->pWarmRestartSupport_in_IOutstationApplication = WarmRestartSupport_in_IOutstationApplication_default;
    pIOutstationApplication->pColdRestart_in_IOutstationApplication = ColdRestart_in_IOutstationApplication_default;
    pIOutstationApplication->pWarmRestart_in_IOutstationApplication = WarmRestart_in_IOutstationApplication_default;
    pIOutstationApplication->pOnConfirmProcessed_in_IOutstationApplication = OnConfirmProcessed_in_IOutstationApplication_default;
    pIOutstationApplication->pIOutstationApplication_destr_IOutstationApplication = IOutstationApplication_destr_IOutstationApplication_default;
}

    boolean SupportsWriteAbsoluteTime_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
        return false;
}
//    boolean WriteAbsoluteTime_in_IOutstationApplication_default(void*, UTCTimestamp* timestamp);
    boolean SupportsWriteTimeAndInterval_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
        return false;
}
//    boolean WriteTimeAndInterval_in_IOutstationApplication_default(void*, ICollection__for__Indexed_for_TimeAndInterval* values);
     boolean SupportsAssignClass_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
        return false;
}
    void RecordClassAssignment_in_IOutstationApplication_default(void* v, AssignClassType_uint8_t type, PointClass_uint8_t clazz, uint16_t start, uint16_t stop)
{
UNUSED(type);
UNUSED(clazz);
UNUSED(start);
UNUSED(stop);
UNUSED(v);
}
    ApplicationIIN GetApplicationIIN_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
// void ApplicationIIN_in_ApplicationIIN(ApplicationIIN *pApplicationIIN);
////        return ApplicationIIN();
   ApplicationIIN aApplicationIIN;
   ApplicationIIN_in_ApplicationIIN(&aApplicationIIN);
   return aApplicationIIN;
}
    RestartMode_uint8_t ColdRestartSupport_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
        return RestartMode_UNSUPPORTED;
}

    RestartMode_uint8_t WarmRestartSupport_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
        return RestartMode_UNSUPPORTED;
}
    uint16_t ColdRestart_in_IOutstationApplication_default(void* v)
{
UNUSED(v);
        return 65535;
}

    uint16_t WarmRestart_in_IOutstationApplication_default(void* v) 
{
UNUSED(v);
        return 65535;
}
    void OnConfirmProcessed_in_IOutstationApplication_default(void* v, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3)
{
UNUSED(is_unsolicited);
UNUSED(num_class1);
UNUSED(num_class2);
UNUSED(num_class3);
UNUSED(v);
}

    void IOutstationApplication_destr_IOutstationApplication_default(void* v)
{
UNUSED(v);
}


void* getParentPointer_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication)
{
  return pIOutstationApplication->pParentPointer_in_IOutstationApplication;
}

void  setParentPointer_in_IOutstationApplication(IOutstationApplication* pIOutstationApplication, void* pParentPointer)
{
  pIOutstationApplication->pParentPointer_in_IOutstationApplication = pParentPointer;
}
