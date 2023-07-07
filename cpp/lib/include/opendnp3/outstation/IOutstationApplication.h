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
#ifndef OPENDNP3_IOUTSTATIONAPPLICATION_H
#define OPENDNP3_IOUTSTATIONAPPLICATION_H

////#include "opendnp3/app/Indexed.h"
////#include "opendnp3/app/MeasurementTypes.h"
////#include "opendnp3/app/parsing/ICollection.h"
////#include "opendnp3/gen/AssignClassType.h"
////#include "opendnp3/gen/PointClass.h"
////#include "opendnp3/gen/RestartMode.h"
////#include "opendnp3/link/ILinkListener.h"
////#include "opendnp3/outstation/ApplicationIIN.h"
////#include "opendnp3/outstation/IDnpTimeSource.h"
////#include "opendnp3/util/UTCTimestamp.h"

////#include <memory>

#include "Indexed.h"
#include "MeasurementTypes.h"
#include "parsing/ICollection.h"
#include "AssignClassType.h"
#include "PointClass.h"
#include "RestartMode.h"
#include "ILinkListener.h"
#include "ApplicationIIN.h"
#include "IDnpTimeSource.h"
#include "UTCTimestamp.h"

//#include <memory>

////namespace opendnp3
////{

/**
 * Interface for all outstation application callback info except for control requests
 */
////class IOutstationApplication : public ILinkListener, public IDnpTimeSource
typedef struct
{
  ILinkListener  iILinkListener;
  IDnpTimeSource iIDnpTimeSource;
////public:
    /// Queries whether the the outstation supports absolute time writes
    /// If this function returns false, WriteAbsoluteTime will never be called
    /// and the outstation will return IIN 2.1 (FUNC_NOT_SUPPORTED)
    boolean (*pSupportsWriteAbsoluteTime_in_IOutstationApplication)(void*);
////    virtual bool SupportsWriteAbsoluteTime()
////    {
////        return false;
////    }

    /// Write the time to outstation, only called if SupportsWriteAbsoluteTime return true
    /// @return boolean value indicating if the time value supplied was accepted. Returning
    /// false will cause the outstation to set IIN 2.3 (PARAM_ERROR) in its response.
    /// The outstation should clear its NEED_TIME field when handling this response
    boolean (*pWriteAbsoluteTime_in_IOutstationApplication)(void*, UTCTimestamp* timestamp);
////    virtual bool WriteAbsoluteTime(const UTCTimestamp& timestamp)
////    {
////        return false;
////    }

    /// Queries whether the outstation supports the writing of TimeAndInterval
    /// If this function returns false, WriteTimeAndInterval will never be called
    /// and the outstation will return IIN 2.1 (FUNC_NOT_SUPPORTED) when it receives this request
    boolean (*pSupportsWriteTimeAndInterval_in_IOutstationApplication)(void*);
////    virtual bool SupportsWriteTimeAndInterval()
////    {
////        return false;
////    }

    /// Write one or more TimeAndInterval values. Only called if SupportsWriteTimeAndInterval returns true.
    /// The outstation application code is reponsible for updating TimeAndInterval values in the database if this
    /// behavior is desired
    /// @return boolean value indicating if the values supplied were accepted. Returning
    /// false will cause the outstation to set IIN 2.3 (PARAM_ERROR) in its response.
//    boolean (*pWriteTimeAndInterval_in_IOutstationApplication)(void*, ICollection_Indexed_for_TimeAndInterval* values);
////    virtual bool WriteTimeAndInterval(const ICollection<Indexed<TimeAndInterval>>& values)
////    {
////        return false;
////    }

    /// True if the outstation supports the assign class function code
    /// If this function returns false, the assign class callbacks will never be called
    /// and the outstation will return IIN 2.1 (FUNC_NOT_SUPPORTED) when it receives this function code
     boolean (*pSupportsAssignClass_in_IOutstationApplication)(void*);
////    virtual bool SupportsAssignClass()
////    {
////        return false;
////    }

    /// Called if SupportsAssignClass returns true
    /// The type and range are pre-validated against the outstation's database
    /// and class assignments are automatically applied internally.
    /// This callback allows user code to persist the changes to non-volatile memory
    void (*pRecordClassAssignment_in_IOutstationApplication)(void*, AssignClassType_uint8_t type, PointClass_uint8_t clazz, uint16_t start, uint16_t stop);
////    virtual void RecordClassAssignment(AssignClassType type, PointClass clazz, uint16_t start, uint16_t stop) {}

    /// Returns the application-controlled IIN field
    ApplicationIIN (*pGetApplicationIIN_in_IOutstationApplication)(void*);
////    virtual ApplicationIIN GetApplicationIIN() const
////    {
////        return ApplicationIIN();
////    }

    /// Query the outstation for the cold restart mode it supports
    RestartMode_uint8_t (*pColdRestartSupport_in_IOutstationApplication)(void*);
////    virtual RestartMode ColdRestartSupport() const
////    {
////        return RestartMode::UNSUPPORTED;
////    }

    /// Query the outstation for the warm restart mode it supports
    RestartMode_uint8_t (*pWarmRestartSupport_in_IOutstationApplication)(void*);
////    virtual RestartMode WarmRestartSupport() const
////    {
////        return RestartMode::UNSUPPORTED;
////    }

    /// The outstation should perform a complete restart.
    /// See the DNP3 specification for a complete descripton of normal behavior
    /// @return number of seconds or milliseconds until restart is complete. The value
    /// is interpreted based on the Restart Mode returned from ColdRestartSupport()
    uint16_t (*pColdRestart_in_IOutstationApplication)(void*);
////    virtual uint16_t ColdRestart()
////    {
////        return 65535;
////    }

    /// The outstation should perform a partial restart of only the DNP3 application.
    /// See the DNP3 specification for a complete descripton of normal behavior
    /// @return number of seconds or milliseconds until restart is complete. The value
    /// is interpreted based on the Restart Mode returned from WarmRestartSupport()
    uint16_t (*pWarmRestart_in_IOutstationApplication)(void*);
////    virtual uint16_t WarmRestart()
////    {
////        return 65535;
////    }

    /// This method notifies that application code that an expected CONFIRM has been
    /// received, and events may have cleared from the event buffer. It is informational
    /// only.
    ///
    /// @param is_unsolicited true, if the confirm is for an unsolicited response, false for a solicited response
    /// @param num_class1 number of Class 1 events remaining in the event buffer after processing the confirm
    /// @param num_class2 number of Class 2 events remaining in the event buffer after processing the confirm
    /// @param num_class3 number of Class 3 events remaining in the event buffer after processing the confirm
    void (*pOnConfirmProcessed_in_IOutstationApplication)(void*, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3);
////    virtual void OnConfirmProcessed(bool is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3) {}

    void (*pIOutstationApplication_destr_IOutstationApplication)(void*);
////    virtual ~IOutstationApplication() = default;

  void* pParentPointer_in_IOutstationApplication;
} IOutstationApplication;

    boolean SupportsWriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication*);
    boolean WriteAbsoluteTime_in_IOutstationApplication(IOutstationApplication*, UTCTimestamp* timestamp);
    boolean SupportsWriteTimeAndInterval_in_IOutstationApplication(IOutstationApplication*);
//    boolean WriteTimeAndInterval_in_IOutstationApplication(IOutstationApplication*, ICollection_Indexed_for_TimeAndInterval* values);
     boolean SupportsAssignClass_in_IOutstationApplication(IOutstationApplication*);
    void RecordClassAssignment_in_IOutstationApplication(IOutstationApplication*, AssignClassType_uint8_t type, PointClass_uint8_t clazz, uint16_t start, uint16_t stop);
    ApplicationIIN GetApplicationIIN_in_IOutstationApplication(IOutstationApplication*);
    RestartMode_uint8_t ColdRestartSupport_in_IOutstationApplication(IOutstationApplication*);
    RestartMode_uint8_t WarmRestartSupport_in_IOutstationApplication(IOutstationApplication*);
    uint16_t ColdRestart_in_IOutstationApplication(IOutstationApplication*);
    uint16_t WarmRestart_in_IOutstationApplication(IOutstationApplication*);
    void OnConfirmProcessed_in_IOutstationApplication(IOutstationApplication*, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3);
    void IOutstationApplication_destr_IOutstationApplication(IOutstationApplication*);

    boolean SupportsWriteAbsoluteTime_in_IOutstationApplication_override(void*);
    boolean WriteAbsoluteTime_in_IOutstationApplication_override(void*, UTCTimestamp* timestamp);
    boolean SupportsWriteTimeAndInterval_in_IOutstationApplication_override(void*);
//    boolean WriteTimeAndInterval_in_IOutstationApplication_override(void*, ICollection_Indexed_for_TimeAndInterval* values);
     boolean SupportsAssignClass_in_IOutstationApplication_override(void*);
    void RecordClassAssignment_in_IOutstationApplication_override(void*, AssignClassType_uint8_t type, PointClass_uint8_t clazz, uint16_t start, uint16_t stop);
    ApplicationIIN GetApplicationIIN_in_IOutstationApplication_override(void*);
    RestartMode_uint8_t ColdRestartSupport_in_IOutstationApplication_override(void*);
    RestartMode_uint8_t WarmRestartSupport_in_IOutstationApplication_override(void*);
    uint16_t ColdRestart_in_IOutstationApplication_override(void*);
    uint16_t WarmRestart_in_IOutstationApplication_override(void*);
    void OnConfirmProcessed_in_IOutstationApplication_override(void*, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3);
    void IOutstationApplication_destr_IOutstationApplication_override(void*);

    void IOutstationApplication_in_IOutstationApplication(IOutstationApplication*);
void* getParentPointer_in_IOutstationApplication(IOutstationApplication*);
void  setParentPointer_in_IOutstationApplication(IOutstationApplication*, void*);

////} // namespace opendnp3

#endif
