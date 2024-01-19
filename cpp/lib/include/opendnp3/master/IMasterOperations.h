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
#ifndef OPENDNP3_IMASTEROPERATIONS_H
#define OPENDNP3_IMASTEROPERATIONS_H

#include "StackStatistics.h"
#include "ClassField.h"
#include "MeasurementTypes.h"
#include "FunctionCode.h"
#include "RestartType.h"
////#include "opendnp3/logging/LogLevels.h"
#include "HeaderTypes.h"
#include "ICommandProcessor.h"
#include "IMasterScan.h"
#include "ISOEHandler.h"
#include "RestartOperationResult.h"
#include "TaskConfig.h"
#include "TimeDuration.h"

////#include <memory>
////#include <string>
////#include <vector>

////namespace opendnp3
////{

/**
 * All the operations that the user can perform on a running master
* ��� ��������, ������� ������������ ����� ��������� �� ���������� �������
 */
////class IMasterOperations : public ICommandProcessor
typedef struct
{
  ICommandProcessor iICommandProcessor;

////public:
////    virtual ~IMasterOperations() {}

  /**
   *  @param filters Adjust the filters to this value
  * @param filter ��������� ������� �� ��� ��������.
   */
////    virtual void SetLogFilters(const opendnp3::LogLevels& filters) = 0;

  /**
   * Add a recurring user-defined scan from a vector of headers
   * @ return A proxy class used to manipulate the scan
  * ���������� �������������� ����������������� ������������ �� ������� ����������.
    * @ return ������-�����, ������������ ��� ���������� �������������.
   */
  IMasterScan* (*pAddScan_in_IMasterOperations)(void *, TimeDuration period,
      std::vector<Header>& headers,
      ISOEHandler* soe_handler,
      TaskConfig* config);// = TaskConfig::Default())  = 0;

  /**
   * Add a scan that requests all objects using qualifier code 0x06
   * @ return A proxy class used to manipulate the scan
  * �������� ������������, ������� ����������� ��� ������� � �������������� ���� ������������� 0x06.
    * @ return ������-�����, ������������ ��� ���������� �������������.
   */
  IMasterScan* (*pAddAllObjectsScan_in_IMasterOperations)(void *, GroupVariationID gvId,
      TimeDuration period,
      ISOEHandler* soe_handler,
      TaskConfig* config);// = TaskConfig::Default())   = 0;

  /**
   * Add a class-based scan to the master
   * @return A proxy class used to manipulate the scan
  * �������� ������������ �� ������ ������� � ������-����
    * @return ������-�����, ������������ ��� ���������� �������������.
   */
  IMasterScan* (*pAddClassScan_in_IMasterOperations)(void *, ClassField* field,
      TimeDuration period,
      ISOEHandler* soe_handler,
      TaskConfig* config);// = TaskConfig::Default())   = 0;

  /**
   * Add a start/stop (range) scan to the master
   * @return A proxy class used to manipulate the scan
  * ���������� ������������ ������/��������� (���������) � ������-����.
    * @return ������-�����, ������������ ��� ���������� �������������.
   */
  IMasterScan* (*pAddRangeScan_in_IMasterOperations)(void *, GroupVariationID gvId,
      uint16_t start,
      uint16_t stop,
      TimeDuration period,
      ISOEHandler* soe_handler,
      TaskConfig* config);// = TaskConfig::Default())    = 0;

  /**
   * Initiate a single user defined scan via a vector of headers
  * ������������ ���� ���������������� ������������ ����� ������ ����������.
   */
  void (*pScan_in_IMasterOperations)(void *, const std::vector<Header>& headers,
                                     ISOEHandler* soe_handler,
                                     TaskConfig* config);// = TaskConfig::Default())     = 0;

  /**
   * Initiate a single scan that requests all objects (0x06 qualifier code) for a certain group and variation
  * ������������ ���� ������������, ������� ����������� ��� ������� (��� ������������� 0x06) ��� ������������ ������ � ��������.
   */
  void (*pScanAllObjects_in_IMasterOperations)(void *, GroupVariationID gvId,
      ISOEHandler* soe_handler,
      TaskConfig* config);// = TaskConfig::Default())    = 0;

  /**
   * Initiate a single class-based scan
  * ������������ ���� ������������ �� ������ �������.
   */
  void (*pScanClasses_in_IMasterOperations)(void *, ClassField* field,
      ISOEHandler* soe_handler,
      TaskConfig* config);// = TaskConfig::Default())      = 0;

  /**
   * Initiate a single start/stop (range) scan
  * ������������ ���� ������������ �����/���� (��������)
   */
  void (*pScanRange_in_IMasterOperations)(void *, GroupVariationID gvId,
                                          uint16_t start,
                                          uint16_t stop,
                                          ISOEHandler* soe_handler,
                                          TaskConfig* config);// = TaskConfig::Default())     = 0;

  /**
   * Write a time and interval object to a specific index
  * �������� ������ ������� � ��������� � ������������ ������.
   */
  void (*pWrite_in_IMasterOperations)(void *, TimeAndInterval* value, uint16_t index, TaskConfig* config);// = TaskConfig::Default())       = 0;

  /**
   * Perform a cold or warm restart and get back the time-to-complete value
  * ��������� �������� ��� ������ ���������� � ������� �������� ������� ����������.
   */
  void (*pRestart_in_IMasterOperations)(void *, RestartType_uint8_t op,
                                        RestartOperationCallbackT callback,
                                        TaskConfig* config);// = TaskConfig::Default()) = 0;

  /**
   * Perform any operation that requires just a function code
  * ��������� ����� ��������, ��� ������� ��������� ������ ��� �������.
   */
  void (*pPerformFunction_in_IMasterOperations)(void *, std::string& name,
      FunctionCode_uint8_t func,
      std::vector<Header>& headers,
      TaskConfig* config);// = TaskConfig::Default())      = 0;

  void* pParentPointer_in_IMasterOperations;
} IMasterOperations;

IMasterScan* AddScan_in_IMasterOperations(IMasterOperations *, TimeDuration period,
    std::vector<Header>& headers,
    ISOEHandler* soe_handler,
    TaskConfig* config);

IMasterScan* AddAllObjectsScan_in_IMasterOperations(IMasterOperations *, GroupVariationID gvId,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig* config);

IMasterScan* AddClassScan_in_IMasterOperations(IMasterOperations *, ClassField* field,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig* config);

IMasterScan* AddRangeScan_in_IMasterOperations(IMasterOperations *, GroupVariationID gvId,
    uint16_t start,
    uint16_t stop,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig* config);

void Scan_in_IMasterOperations(IMasterOperations *, const std::vector<Header>& headers,
                               ISOEHandler* soe_handler,
                               TaskConfig* config);

void ScanAllObjects_in_IMasterOperations(IMasterOperations *, GroupVariationID gvId,
    ISOEHandler* soe_handler,
    TaskConfig* config);

void ScanClasses_in_IMasterOperations(IMasterOperations *, ClassField* field,
                                      ISOEHandler* soe_handler,
                                      TaskConfig* config);

void ScanRange_in_IMasterOperations(IMasterOperations *, GroupVariationID gvId,
                                    uint16_t start,
                                    uint16_t stop,
                                    ISOEHandler* soe_handler,
                                    TaskConfig* config);

void Write_in_IMasterOperations(IMasterOperations *, TimeAndInterval* value, uint16_t index, TaskConfig* config);// = TaskConfig::Default())       = 0;

void Restart_in_IMasterOperations(IMasterOperations *, RestartType_uint8_t op,
                                  RestartOperationCallbackT* callback,
                                  TaskConfig* config);

void PerformFunction_in_IMasterOperations(IMasterOperations *, std::string& name,
    FunctionCode_uint8_t func,
    std::vector<Header>& headers,
    TaskConfig* config);

void* getParentPointer_in_IMasterOperations(IMasterOperations*);
void  setParentPointer_in_IMasterOperations(IMasterOperations*, void*);

////} // namespace opendnp3

#endif
