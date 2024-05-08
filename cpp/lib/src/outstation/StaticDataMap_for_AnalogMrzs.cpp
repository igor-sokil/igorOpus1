#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "StaticDataMap_for_AnalogMrzs.h"
#include "DatabaseConfigMrzs.h"

void Iterator_StaticDataMap_for_AnalogMrzs_in_Iterator_StaticDataMap_for_AnalogMrzs(Iterator_StaticDataMap_for_AnalogMrzs *pIterator_StaticDataMap_for_AnalogMrzs,
     StaticDataRecord_for_Analog* begin, StaticDataRecord_for_Analog* end, Range *range)
{
  pIterator_StaticDataMap_for_AnalogMrzs->begin = begin;
  pIterator_StaticDataMap_for_AnalogMrzs->end = end;
  pIterator_StaticDataMap_for_AnalogMrzs->range = *range;
}
/*
Iterator_StaticDataMap_for_AnalogMrzs* getIterator_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{getIterator_StaticDataMap_for_AnalogMrzs1"<<'\n';
#endif
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}getIterator_StaticDataMap_for_AnalogMrzs_"<<'\n';
  decrement_stack_info();
#endif
  return &(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs);
}
*/

StaticDataRecord_for_Analog* IncrementIteratorBegin_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
  pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.begin++;
  return pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.begin;
}

StaticDataRecord_for_Analog* getIteratorBegin_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
  return pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.begin;
}

StaticDataRecord_for_Analog* setIteratorBegin_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{setIteratorBegin_StaticDataMap_for_AnalogMrzs1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*IteratorBegin_StaticDataMap_for_AnalogMrzs::begin()1"<<'\n';
#endif

  if (!IsValid_in_Range(&(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs)))
  {
////    return iterator(this->map.end(), this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
  Iterator_StaticDataMap_for_AnalogMrzs_in_Iterator_StaticDataMap_for_AnalogMrzs(&(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs),
      mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
      mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
     &(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}IteratorBegin_StaticDataMap_for_AnalogMrzs::begin()1_"<<'\n';
  decrement_stack_info();
#endif
   return mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs);
  }

////  const auto begin = this->map.lower_bound(this->selected_in_StaticDataMap_for_AnalogSpec.start);
 uint16_t start = pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs.start;
 StaticDataRecord_for_Analog* begin = &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[start]);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*IteratorBegin_StaticDataMap_for_AnalogMrzs2"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* begin= "<<(uint32_t)begin<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*uint16_t start = "<<start<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog* begin.index_in_StaticDataRecord_for_Analog= "<<begin->index_in_StaticDataRecord_for_Analog<<'\n';
#endif

////  return iterator(begin, this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
  Iterator_StaticDataMap_for_AnalogMrzs_in_Iterator_StaticDataMap_for_AnalogMrzs(&(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs),
      begin,
      mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
     &(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*IteratorBegin_StaticDataMap_for_AnalogMrzs::begin()2_"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}setIteratorBegin_StaticDataMap_for_AnalogMrzs2_"<<'\n';
  decrement_stack_info();
#endif
  return begin;
}

StaticDataRecord_for_Analog* IteratorEnd_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{IteratorEnd_StaticDataMap_for_AnalogMrzs::end()1"<<'\n';
#endif
////  return iterator(this->map.end(), this->map.end(), this->selected_in_StaticDataMap_for_AnalogSpec);
  Iterator_StaticDataMap_for_AnalogMrzs iterEnd;
  Iterator_StaticDataMap_for_AnalogMrzs_in_Iterator_StaticDataMap_for_AnalogMrzs(&iterEnd,
      mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
      mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
     &(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}IteratorEnd_StaticDataMap_for_AnalogMrzs::end()_"<<'\n';
  decrement_stack_info();
#endif
  return mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs);
}
/*
boolean operatorEQ_in_Iterator_StaticDataMap_for_AnalogMrzs(Iterator_StaticDataMap_for_AnalogMrzs* iter1, Iterator_StaticDataMap_for_AnalogMrzs* iter2)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{operatorEQ_in_Iterator_StaticDataMap_for_AnalogMrzs1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*iter1->begin= "<<(uint32_t)iter1->begin<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*iter2->begin= "<<(uint32_t)iter2->begin<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*iter1->end= "<<(uint32_t)iter1->end<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*iter2->end= "<<(uint32_t)iter2->end<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}operatorEQ_in_Iterator_StaticDataMap_for_AnalogMrzs_"<<'\n';
  decrement_stack_info();
#endif

  if((iter1->begin == iter2->begin) && (iter1->end == iter2->end)) return true;
  return false;
}
*/
/*
StaticDataRecord_for_Analog* Increment_in_Iterator_StaticDataMap_for_AnalogMrzs(Iterator_StaticDataMap_for_AnalogMrzs *pIterator_StaticDataMap_for_AnalogMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Increment_in_Iterator_StaticDataMap_for_AnalogMrzs1"<<'\n';
#endif
  StaticDataRecord_for_Analog *current = pIterator_StaticDataMap_for_AnalogMrzs->begin;
//  if(pIterator_StaticDataMap_for_AnalogMrzs->begin >= pIterator_StaticDataMap_for_AnalogMrzs->end) current = NULL;
  if(pIterator_StaticDataMap_for_AnalogMrzs->begin < pIterator_StaticDataMap_for_AnalogMrzs->end) pIterator_StaticDataMap_for_AnalogMrzs->begin++;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*pIterator_StaticDataMap_for_AnalogMrzs->begin= "<<(uint32_t)pIterator_StaticDataMap_for_AnalogMrzs->begin<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pIterator_StaticDataMap_for_AnalogMrzs->end= "<<(uint32_t)pIterator_StaticDataMap_for_AnalogMrzs->end<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}Increment_in_Iterator_StaticDataMap_for_AnalogMrzs_"<<'\n';
  decrement_stack_info();
#endif
  return current;//pIterator_StaticDataMap_for_AnalogMrzs->begin;
}
*/
StaticDataRecord_for_Analog *mapEnd_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
 return &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[(pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs)]);
}

StaticDataRecord_for_Analog *mapBegin_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
 return &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[0]);
}

StaticDataRecord_for_Analog *mapLowerBound_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs, uint16_t lowerBound)
{
 return &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[lowerBound]);
}

void StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs, uint16_t size)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1_1"<<'\n';
#endif
  pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs = size;
  Range_in_RangeOver1(&(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs));
  Iterator_StaticDataMap_for_AnalogMrzs_in_Iterator_StaticDataMap_for_AnalogMrzs(&(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs),
      mapBegin_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
      mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs),
     &(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs));
/*
  Iterator_StaticDataMap_for_AnalogMrzs_in_Iterator_StaticDataMap_for_AnalogMrzs(&(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs),
     &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs.start]),//void* begin,
     &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[(pStaticDataMap_for_AnalogMrzs->countAnalog_input)-1]),//void* end,
     &(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs));
*/
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs= "<<pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.begin= "<<(uint32_t)pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.begin<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.end= "<<(uint32_t)pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs.end<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1__"<<'\n';
  decrement_stack_info();
#endif
}

void StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2_1"<<'\n';
#endif
  StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver1(pStaticDataMap_for_AnalogMrzs, getDatabaseConfigMrzs()->sizeConfig_for_AnalogMrzs);
  if(pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs > SIZE_map_StaticDataMap_for_AnalogMrzs) pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs = SIZE_map_StaticDataMap_for_AnalogMrzs;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataMap_for_AnalogMrzs_in_StaticDataMap_for_AnalogMrzsOver2_2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs= "<<pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs<<'\n';
#endif

// Increment_in_Iterator_StaticDataMap_for_AnalogMrzs(&(pStaticDataMap_for_AnalogMrzs->iIterator_StaticDataMap_for_AnalogMrzs));

  for(uint16_t index=0; index<pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs; index++)
  {
    StaticDataRecord_for_Analog sStaticDataRecord_for_Analog;
    AnalogConfig temp = getDatabaseConfigMrzs()->analog_input[index];
    StaticDataRecord_for_Analog_in_StaticDataRecord_for_Analog(&sStaticDataRecord_for_Analog, index);
    StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(&sStaticDataRecord_for_Analog.sStaticDataCell_for_Analog, &temp);
    pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[index] = sStaticDataRecord_for_Analog;
  }//for

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

boolean update_in_StaticDataMap_for_AnalogMrzsOver1(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs,
    Analog* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{update_in_StaticDataMap_for_AnalogMrzsOver1_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t index= "<<index<<'\n';
//  std::cout<<"*"<<getString_stack_info();
//  std::cout<<"*pStaticDataMap_for_AnalogSpec->map.size()= "<<pStaticDataMap_for_AnalogSpec->map.size()<<'\n';
#endif
//boolean update_in_StaticDataMap_for_AnalogSpecOver2(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec,
//    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
//    Analog* new_value,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return update(this->map.find(index), value, mode, receiver);
  if(index >= SIZE_map_StaticDataMap_for_AnalogMrzs) return false;//вихід за межі
//  map_iter_t_StaticDataMap_for_AnalogSpec  iter = pStaticDataMap_for_AnalogSpec->map.find(index);
  StaticDataRecord_for_Analog* iter = &(pStaticDataMap_for_AnalogMrzs->map_StaticDataMap_for_AnalogMrzs[index]);
  boolean tmp = update_in_StaticDataMap_for_AnalogMrzsOver2(pStaticDataMap_for_AnalogMrzs, iter, value, mode, receiver);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_AnalogMrzsOver1__"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

boolean update_in_StaticDataMap_for_AnalogMrzsOver2(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs,
//    map_iter_t_StaticDataMap_for_AnalogSpec & iter,
    StaticDataRecord_for_Analog* iter,
    Analog* new_value,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{update_in_StaticDataMap_for_AnalogMrzsOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*inspect_Analog(new_value)"<<'\n';
  inspect_Analog(new_value);
  std::cout<<"*"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_uint8_t mode= "<<(uint16_t)mode<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_Force= "<<(uint16_t)EventMode_Force<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventMode_EventOnly= "<<(uint16_t)EventMode_EventOnly<<'\n';
#endif

//StaticDataCell_for_Analog *mapEnd_in_StaticDataMap_for_AnalogMrzs(void)
///  if (iter == pStaticDataMap_for_AnalogSpec->map.end())
  if (iter == mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_AnalogMrzsOver21_"<<'\n';
  decrement_stack_info();
#endif
    return false;
  }

//StaticDataCell_for_Analog ttt = iter->second;////!

  if (mode != EventMode_EventOnly)
  {
////    iter->second.value_in_StaticDataCell = *new_value;
    iter->sStaticDataCell_for_Analog.value_in_StaticDataCell = *new_value;
  }

////  Analog old_value = iter->second.event_in_StaticDataCell.eEventCellBase_for_Analog.lastEvent_in_EventCellBase;
  Analog old_value = iter->sStaticDataCell_for_Analog.event_in_StaticDataCell.eEventCellBase_for_Analog.lastEvent_in_EventCellBase;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"update_in_StaticDataMap_for_AnalogMrzsOver2_2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*inspect_Analog(&old_value)"<<'\n';
  inspect_Analog(&old_value);
#endif

  if (mode == EventMode_Force || mode == EventMode_EventOnly ||
//boolean IsEvent_in_AnalogSpec_static(Analog *old_value, Analog *new_value, AnalogConfig *config);
////        Spec::IsEvent(iter->second.event.lastEvent, new_value, iter->second.config))
      IsEvent_in_AnalogSpec_static(&old_value, new_value, &(iter->sStaticDataCell_for_Analog.config_in_StaticDataCell)))
  {
    iter->sStaticDataCell_for_Analog.event_in_StaticDataCell.eEventCellBase_for_Analog.lastEvent_in_EventCellBase = *new_value;
    if (mode != EventMode_Suppress)
    {
      EventClass_uint8_t ec;
//boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec);
////            if (convert_to_event_class(iter->second.config.clazz, ec))
      if (convert_to_event_class_in_StaticDataMap_static(iter->sStaticDataCell_for_Analog.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.clazz, &ec))
      {
//void Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(Event_for_AnalogSpec *pEvent_for_AnalogSpec,
//    Analog* value, uint16_t index,
//    EventClass_uint8_t clazz,
//    event_variation_t_in_AnalogInfo variation);
//void Update_AnalogSpec_in_IEventReceiver(IEventReceiver *, Event_for_AnalogSpec* evt);
////                receiver.Update(Event<Spec>(new_value, iter->first, ec, iter->second.config.evariation));
        Event_for_AnalogSpec eEvent_for_AnalogSpec;
        Event_for_AnalogSpec_in_Event_for_AnalogSpecOver2(&eEvent_for_AnalogSpec,
            new_value, iter->index_in_StaticDataRecord_for_Analog,//first,
            ec,
            iter->sStaticDataCell_for_Analog.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.evariation);
        Update_AnalogSpec_in_IEventReceiver(receiver, &eEvent_for_AnalogSpec);

      }
    }
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}update_in_StaticDataMap_for_AnalogMrzsOver22_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

uint16_t select_in_StaticDataMap_for_AnalogMrzsOver5(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs, Range range, StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{select_in_StaticDataMap_for_AnalogMrzsOver5_1"<<'\n';
#endif
//boolean IsValid_in_Range(Range *pRange);
////    if (!range.IsValid())
  if (!IsValid_in_Range(&range))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}select_in_StaticDataMap_for_AnalogMrzsOver5_1_"<<'\n';
  decrement_stack_info();
#endif
    return 0;
  }

//StaticDataRecord_for_Analog *mapLowerBound_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs, uint16_t lowerBound)
//  const auto start = pStaticDataMap_for_AnalogSpec->map.lower_bound(range.start);
StaticDataRecord_for_Analog *startRecord = mapLowerBound_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs, range.start);
//StaticDataCell_for_Analog ttt2 = start->second;////!
uint16_t start_first = startRecord->index_in_StaticDataRecord_for_Analog;////!

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*StaticDataRecord_for_Analog *startRecord= "<<(uint32_t)startRecord<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*uint16_t start_first= "<<start_first<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*select_in_StaticDataMap_for_AnalogMrzsOver5_2"<<'\n';
#endif

////  if (start == pStaticDataMap_for_AnalogSpec->map.end())
  if(startRecord >= mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}select_in_StaticDataMap_for_AnalogMrzsOver5_2_"<<'\n';
  decrement_stack_info();
#endif
    return 0;
  }

//boolean Contains_in_Range(Range *pRange, uint16_t index);
////    if (!range.Contains(start->first))
//  if (!Contains_in_Range(&range, start->first))
  if (!Contains_in_Range(&range, start_first))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}select_in_StaticDataMap_for_AnalogMrzsOver5_3_"<<'\n';
  decrement_stack_info();
#endif
    return 0;
  }

  uint16_t stop = 0;
  uint16_t count = 0;

////  for (auto iter = start; iter != pStaticDataMap_for_AnalogSpec->map.end(); ++iter)
  for(StaticDataRecord_for_Analog *iter=startRecord; iter != mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs); iter++)
  {
//StaticDataCell_for_Analog ttt = iter->second;////!

////        if (!range.Contains(iter->first))
//    if (!Contains_in_Range(&range, iter->first))
    if (!Contains_in_Range(&range, iter->index_in_StaticDataRecord_for_Analog))
    {
      break;
    }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*iter->index= "<<iter->index_in_StaticDataRecord_for_Analog<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*select_in_StaticDataMap_for_AnalogMrzsOver5_4"<<'\n';
#endif

//    stop = iter->first;
    stop = iter->index_in_StaticDataRecord_for_Analog;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*uint16_t stop= "<<stop<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*select_in_StaticDataMap_for_AnalogMrzsOver5_5"<<'\n';
#endif

//StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec_static(Analog* value, StaticAnalogVariation_uint8_t variation);
////        iter->second.selection = SelectedValue<Spec>{
////            true, iter->second.value,
////            check_for_promotion<Spec>(iter->second.value, get_variation(iter->second.config.svariation))};
//    Analog aAnalog = iter->second.value_in_StaticDataCell;
    Analog aAnalog = iter->sStaticDataCell_for_Analog.value_in_StaticDataCell;
    SelectedValue_for_AnalogSpec sSelectedValue_for_AnalogMrzs = {
      true, aAnalog, variation//check_for_promotion_for_AnalogSpec_static(&aAnalog, get_variation(iter->second.config_in_StaticDataCell.dDeadbandConfig_for_AnalogInfo.eEventConfig.svariation))
    };
//    iter->second.selection_in_StaticDataCell = sSelectedValue_for_AnalogMrzs;
    iter->sStaticDataCell_for_Analog.selection_in_StaticDataCell = sSelectedValue_for_AnalogMrzs;
    ++count;
  }

//Range Union_in_Range(Range *pRange, Range* other);
//Range From_in_Range_static(uint16_t start, uint16_t stop);
////    this->selected = this->selected.Union(Range::From(start->first, stop));
//  Range rRange = From_in_Range_static(start->first, stop);
  Range rRange = From_in_Range_static(start_first, stop);
  pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs = Union_in_Range(&(pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs), &rRange);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}select_in_StaticDataMap_for_AnalogMrzsOver5_4_"<<'\n';
  decrement_stack_info();
#endif
  return count;
}

Range get_selected_range_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
{
  return pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs;
}
///*
void operatorPLUS_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
    {
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{operatorPLUS_in_StaticDataMap_for_AnalogMrzs1"<<'\n';
#endif
////StaticDataCell_for_Analog sss = this->iter->second;//.second;

//  Iterator_StaticDataMap_for_AnalogMrzs iIterator_StaticDataMap_for_AnalogMrzs;
      // unselect the point
////      this->iter->second.selection_in_StaticDataCell.selected_in_SelectedValue_for_AnalogSpec = false;

////      while (true)
////      {
//for(int idx=0; idx<2; idx++)
while(true)
{
//StaticDataRecord_for_Analog* IncrementIteratorBegin_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs)
////        iter++;
StaticDataRecord_for_Analog* iterBegin = IncrementIteratorBegin_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs);

////        if (iter == this->end)
        if(iterBegin == mapEnd_in_StaticDataMap_for_AnalogMrzs(pStaticDataMap_for_AnalogMrzs))
        {
////                    this->range = Range::Invalid();
////          this->range = Invalid_in_Range_static();
           pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs = Invalid_in_Range_static();
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}operatorPLUS_in_StaticDataMap_for_AnalogMrzs1_"<<'\n';
//  std::cout<<getString_stack_info();
//  std::cout<<"*iter->first= "<<iter->first<<'\n';
//  std::cout<<getString_stack_info();
//  std::cout<<"*iterBegin->index_in_StaticDataRecord_for_Analog= "<<(uint32_t)iterBegin->index_in_StaticDataRecord_for_Analog<<'\n';
  decrement_stack_info();
#endif
          return;
        }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*operatorPLUS_in_StaticDataMap_for_AnalogMrzs2"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*iterBegin->index_in_StaticDataRecord_for_Analog= "<<(uint32_t)iterBegin->index_in_StaticDataRecord_for_Analog<<'\n';
#endif

///#ifdef  LOG_INFO
///  std::cout<<getString_stack_info();
///  std::cout<<"*operator++1"<<'\n';
///  std::cout<<getString_stack_info();
///  std::cout<<"*iter->first= "<<iter->first<<'\n';
///#endif
        // shorten the range
////        this->range.start = iter->first;

////        if (iter->second.selection_in_StaticDataCell.selected_in_SelectedValue_for_AnalogSpec)
        if(iterBegin->sStaticDataCell_for_Analog.selection_in_StaticDataCell.selected_in_SelectedValue_for_AnalogSpec)
        {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}operatorPLUS_in_StaticDataMap_for_AnalogMrzs2_"<<'\n';
//  std::cout<<getString_stack_info();
//  std::cout<<"*iter->first= "<<iter->first<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*iterBegin->index_in_StaticDataRecord_for_Analog= "<<(uint32_t)iterBegin->index_in_StaticDataRecord_for_Analog<<'\n';
  decrement_stack_info();
#endif
          return;
        }
////      }//while
}//for

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}operatorPLUS_in_StaticDataMap_for_AnalogMrzs3_"<<'\n';
  decrement_stack_info();
#endif
    }
//*/
///*
uint16_t select_all_in_StaticDataMap_for_AnalogMrzsOver3(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs, StaticAnalogVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{select_all_in_StaticDataMap_for_AnalogMrzsOver3_1"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs= "<<pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs<<'\n';
#endif
//  if (pStaticDataMap_for_AnalogSpec->map.empty())
  if (pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs == 0)
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}select_all_in_StaticDataMap_for_AnalogMrzsOver3_1_"<<'\n';
  decrement_stack_info();
#endif
    return 0;
  }

  else
  {

//Range From_in_Range_static(uint16_t start, uint16_t stop);
////        this->selected = Range::From(map.begin()->first, map.rbegin()->first);
//    pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs = From_in_Range_static(pStaticDataMap_for_AnalogSpec->map.begin()->first,
//        pStaticDataMap_for_AnalogSpec->map.rbegin()->first);

    pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs = From_in_Range_static(0,
        pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs-1);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogSpec.start= "<<pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs.start<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"*pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogSpec.stop= "<<pStaticDataMap_for_AnalogMrzs->selected_in_StaticDataMap_for_AnalogMrzs.stop<<'\n';
#endif

/*
    for (auto& iter : pStaticDataMap_for_AnalogSpec->map)
    {
//qDebug()<<"iter___";
// StaticAnalogVariation_uint8_t check_for_promotion_for_AnalogSpec(Analog* value, StaticAnalogVariation_uint8_t variation);
//void SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver2(SelectedValue_for_AnalogSpec *pSelectedValue_for_AnalogSpec,
//                                          boolean selected, Analog* value, StaticAnalogVariation_uint8_t variation);
////            iter.second.selection = SelectedValue<Spec>{
////                true, iter.second.value,
////                check_for_promotion<Spec>(iter.second.value, get_variation(iter.second.config.svariation))};
      SelectedValue_for_AnalogSpec sSelectedValue_for_AnalogSpec;
      SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver2(&sSelectedValue_for_AnalogSpec,
          true, &iter.second.value_in_StaticDataCell,
          check_for_promotion_for_AnalogSpec_static(&iter.second.value_in_StaticDataCell, get_variation(iter.second.config_in_StaticDataCell.
              dDeadbandConfig_for_AnalogInfo.eEventConfig.svariation)));

      iter.second.selection_in_StaticDataCell = sSelectedValue_for_AnalogSpec;
    }//for
*/
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}select_all_in_StaticDataMap_for_AnalogMrzsOver3_2_"<<'\n';
  decrement_stack_info();
#endif
//    return pStaticDataMap_for_AnalogSpec->map.size();
  return pStaticDataMap_for_AnalogMrzs->sizeMap_for_AnalogMrzs;
  }

}
//*/
