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

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventWriting.h"

#include "EventCollection.h"
#include "IEventType.h"
#include <string.h>

////namespace opendnp3
////{

////uint32_t EventWriting::Write(EventLists& lists, IEventWriteHandler& handler)
uint32_t Write_in_EventWriting_static(EventLists* lists, IEventWriteHandler* handler)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Write_in_EventWriting_static1"<<'\n';
#endif

  uint32_t total_num_written = 0;

//    Iterator_in_List_for_EventRecord Iterate_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord);
////    auto iterator = lists.events.Iterate();
  Iterator_in_List_for_EventRecord iter = Iterate_in_List_for_EventRecord(&(lists->events_in_EventLists));

  while (true)
  {
    // continue calling WriteSome(..) until it fails to make progress
// ���������� �������� WriteSome(..) �� ��� ���, ���� �� ���������� �����������
//    uint16_t WriteSome_in_EventWriting_static(Iterator_in_List_for_EventRecord* iteratorEv, EventLists* lists, IEventWriteHandler* handler);
////        auto num_written = WriteSome(iterator, lists, handler);
    uint16_t num_written = WriteSome_in_EventWriting_static(&iter, lists, handler);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*uint16_t num_written ="<<num_written<<'\n';
#endif

    if (num_written == 0)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_EventWriting_static1_"<<'\n';
  decrement_stack_info();
#endif
      return total_num_written;
    }

    total_num_written += num_written;
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Write_in_EventWriting_static2_"<<'\n';
  decrement_stack_info();
#endif
}

////EventRecord* EventWriting::FindNextSelected(event_iter_t& iter, EventType type)
EventRecord* FindNextSelected_in_EventWriting_static(Iterator_in_List_for_EventRecord* iter, EventType_uint16_t type)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FindNextSelected_in_EventWriting_static1"<<'\n';
#endif
  while (true)
  {
//EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
////        auto current = iter.CurrentValue();
    EventRecord* current = CurrentValue__in__Iterator_in_List_for_EventRecord(iter);

    if (!current)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"FindNextSelected_in_EventWriting_static2"<<'\n';
      decrement_stack_info();
#endif
      return NULL;
    }

    if (current->state == EventState_selected)
    {
      // we terminate here since the type has changed
// ����� �� ��������� ������, ��� ��� ��� ���������
//   boolean IsEqual_in_IEventType(IEventType* pIEventType, EventType_uint16_t type);
////            return current->type->IsEqual(type) ? current : nullptr;
      if(IsEqual_in_IEventType((IEventType*)(current->type), type))
      {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"FindNextSelected_in_EventWriting_static3"<<'\n';
        decrement_stack_info();
#endif
        return current;
      }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"FindNextSelected_in_EventWriting_static4"<<'\n';
      decrement_stack_info();
#endif
      return NULL;
    }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"FindNextSelected_in_EventWriting_static5"<<'\n';
#endif
////        iter.Next();
    Next__in__Iterator_in_List_for_EventRecord(iter);
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"FindNextSelected_in_EventWriting_static6"<<'\n';
  decrement_stack_info();
#endif
}

boolean matches_in_EventWriting(EventRecord* pEventRecord);
boolean matches_in_EventWriting(EventRecord* record)
{
  return record->state == EventState_selected;
}

////uint16_t EventWriting::WriteSome(event_iter_t& iterator, EventLists& lists, IEventWriteHandler& handler)
uint16_t WriteSome_in_EventWriting_static(Iterator_in_List_for_EventRecord* iteratorEv, EventLists* lists, IEventWriteHandler* handler)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteSome_in_EventWriting_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*lists->counters.selected= "<<(uint16_t)lists->counters_in_EventLists.selected<<'\n';
#endif
  // don't bother searching
// �� ������������ �������
////    if (lists.counters.selected == 0)
  if (lists->counters_in_EventLists.selected == 0)
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return 0;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteSome_in_EventWriting_static2"<<'\n';
#endif

//EventRecord *Find__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord
////    const auto value = iterator.Find([](const EventRecord& record) { return record.state == EventState::selected; });
  EventRecord *value = Find__in__Iterator_in_List_for_EventRecord(iteratorEv, matches_in_EventWriting);

  if (!value)
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return 0; // no match
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"WriteSome_in_EventWriting_static3"<<'\n';
#endif
//     uint16_t (*pWriteSome)(Iterator_in_List_for_EventRecord* iterator,
//                               EventLists* lists,
//                               IEventWriteHandler* handler);// const = 0;
////    return value->type->WriteSome(iterator, lists, handler);
//  return  ((IEventType*)(value->type))->pWriteSome(iteratorEv, lists, handler);
  uint16_t tmp = WriteSome_in_IEventType((IEventType*)(value->type),
                                         iteratorEv,
                                         lists,
                                         handler);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

////} // namespace opendnp3
