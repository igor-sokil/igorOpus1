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
#ifndef OPENDNP3_IMASTERSCAN_H
#define OPENDNP3_IMASTERSCAN_H

////namespace opendnp3
////{

/**
 * Interface for interacting w/ a permanently bound scan
* »нтерфейс дл€ взаимодействи€ с посто€нно прив€занным сканированием
 */
////class IMasterScan
typedef struct
{
////public:
////    virtual ~IMasterScan() = default;

    // Request that the scan be performed as soon as possible
// «апрос, чтобы сканирование было выполнено как можно скорее
    void (*pDemand_in_IMasterScan)(void *);// = 0;

  void* pParentPointer_in_IMasterScan;
} IMasterScan;

void Demand_in_IMasterScan(IMasterScan* pIMasterScan);

void* getParentPointer_in_IMasterScan(IMasterScan*);
void  setParentPointer_in_IMasterScan(IMasterScan*, void*);

////} // namespace opendnp3

#endif
