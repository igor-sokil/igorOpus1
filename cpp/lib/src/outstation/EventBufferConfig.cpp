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
////#include "opendnp3/outstation/EventBufferConfig.h"

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventBufferConfig.h"

////namespace opendnp3
////{

EventBufferConfig AllTypes_in_EventBufferConfig_static(uint16_t sizes)
{
  EventBufferConfig eEventBufferConfig;
  EventBufferConfig_in_EventBufferConfigOver2(&eEventBufferConfig, sizes, sizes, sizes, sizes, sizes, sizes, sizes, sizes);
////    return EventBufferConfig(sizes, sizes, sizes, sizes, sizes, sizes, sizes, sizes);
  return eEventBufferConfig;
}

void EventBufferConfig_in_EventBufferConfigOver1(EventBufferConfig *pEventBufferConfig)
{
  UNUSED(pEventBufferConfig);
}

void EventBufferConfig_in_EventBufferConfigOver2(EventBufferConfig *pEventBufferConfig,
    uint16_t maxBinaryEvents,
    uint16_t maxDoubleBinaryEvents,
    uint16_t maxAnalogEvents,
    uint16_t maxCounterEvents,
    uint16_t maxFrozenCounterEvents,
    uint16_t maxBinaryOutputStatusEvents,
    uint16_t maxAnalogOutputStatusEvents,
    uint16_t maxOctetStringEvents)
{
  pEventBufferConfig->maxBinaryEvents = maxBinaryEvents;
  pEventBufferConfig->maxDoubleBinaryEvents = maxDoubleBinaryEvents;
  pEventBufferConfig->maxAnalogEvents = maxAnalogEvents;
  pEventBufferConfig->maxCounterEvents = maxCounterEvents;
  pEventBufferConfig->maxFrozenCounterEvents = maxFrozenCounterEvents;
  pEventBufferConfig->maxBinaryOutputStatusEvents = maxBinaryOutputStatusEvents;
  pEventBufferConfig->maxAnalogOutputStatusEvents = maxAnalogOutputStatusEvents;
  pEventBufferConfig->maxOctetStringEvents = maxOctetStringEvents;
}

uint32_t TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"TotalEvents_in_EventBufferConfig1"<<std::endl;

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxBinaryEvents= "<<(uint16_t)pEventBufferConfig->maxBinaryEvents<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxDoubleBinaryEvents="<<(uint16_t)pEventBufferConfig->maxDoubleBinaryEvents<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxAnalogEvents= "<<(uint16_t)pEventBufferConfig->maxAnalogEvents<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxCounterEvents= "<<(uint16_t)pEventBufferConfig->maxCounterEvents<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxBinaryOutputStatusEvents= "<<(uint16_t)pEventBufferConfig->maxBinaryOutputStatusEvents<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxAnalogOutputStatusEvents= "<<(uint16_t)pEventBufferConfig->maxAnalogOutputStatusEvents<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBufferConfig->maxOctetStringEvents= "<<(uint16_t)pEventBufferConfig->maxOctetStringEvents<<std::endl;
  decrement_stack_info();
#endif

  return pEventBufferConfig->maxBinaryEvents + pEventBufferConfig->maxDoubleBinaryEvents +
         pEventBufferConfig->maxAnalogEvents + pEventBufferConfig->maxCounterEvents +
         pEventBufferConfig->maxFrozenCounterEvents +
         pEventBufferConfig->maxBinaryOutputStatusEvents + pEventBufferConfig->maxAnalogOutputStatusEvents +
         pEventBufferConfig->maxOctetStringEvents;
}

////} // namespace opendnp3
