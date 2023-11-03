#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_TimeAndInterval_in_Database_static(StaticDataMap_for_TimeAndIntervalSpec& map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"load_type_for_TimeAndInterval_in_Database_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*map.map.size()= "<<map.map.size()<<'\n';
#endif
  while (true)
  {
    auto iter = map.begin();

    if (iter == map.end())
    {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*if (iter == map.end())"<<'\n';
    decrement_stack_info();
#endif
      // there is no data left to write
      return true;
    }

    StaticTimeAndIntervalVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_TimeAndIntervalSpec)(StaticDataMap_for_TimeAndIntervalSpec& map, HeaderWriter* writer);//указатель на ф-цию
//static_write_func_t_for_TimeAndIntervalSpec                   get_for_TimeAndIntervalSpec_static(StaticTimeAndIntervalVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_TimeAndIntervalSpec_in_StaticWriters_static(variation)(map, writer))
    {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*if (!get_for_TimeAndIntervalSpec_in_StaticWriters_static(variation)(map, writer))"<<'\n';
    decrement_stack_info();
#endif
      // the APDU is full
      return false;
    }
  }
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*return"<<'\n';
    decrement_stack_info();
#endif
}

////template<class Spec> void Database::select_all_class_zero(StaticDataMap<Spec>& map)
void select_all_class_zero_StaticDataMap_for_TimeAndIntervalSpec(Database *pDatabase, StaticDataMap_for_TimeAndIntervalSpec* map)
{
//boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
////    if (this->allowed_class_zero_types.IsSet(Spec::StaticTypeEnum))
  if (IsSet_in_StaticTypeBitField(&(pDatabase->allowed_class_zero_types), StaticTypeBitmask_TimeAndInterval))
  {
//IINField select_all_StaticDataMap_for_TimeAndIntervalSpec_in_Database_static(StaticDataMap_for_TimeAndIntervalSpec* map)
////        select_all<Spec>(map);
    select_all_StaticDataMap_for_TimeAndIntervalSpec_in_Database_staticOver1(map);
  }
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
IINField select_all_StaticDataMap_for_TimeAndIntervalSpec_in_Database_staticOver1(StaticDataMap_for_TimeAndIntervalSpec* map)
{
////    map.select_all();
  select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver1(map);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map, typename Spec::static_variation_t variation)
IINField select_all_StaticDataMap_for_TimeAndIntervalSpec_in_Database_staticOver2(StaticDataMap_for_TimeAndIntervalSpec* map, StaticTimeAndIntervalVariation_uint8_t variation)
{
////    map.select_all(variation);
  select_all_in_StaticDataMap_for_TimeAndIntervalSpecOver2(map, variation);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////bool Database::Update(const TimeAndInterval& meas, uint16_t index, EventMode mode)
boolean Update_for_TimeAndInterval_in_Database(Database *pDatabase, TimeAndInterval* meas, uint16_t index)
{
//boolean update_in_StaticDataMap_for_TimeAndIntervalSpecOver1(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec,
//    TimeAndInterval* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return this->time_and_interval.update(meas, index, mode, event_receiver);
  return update_in_StaticDataMap_for_TimeAndIntervalSpecOver1(&(pDatabase->time_and_interval), meas, index, EventMode_Suppress, pDatabase->event_receiver);
}

void select_for_TimeAndIntervalSpec_in_DatabaseOver1(uint16_t *index);
void select_for_TimeAndIntervalSpec_in_DatabaseOver1(uint16_t *index)
{
  StaticDataMap_for_TimeAndIntervalSpec* map = (StaticDataMap_for_TimeAndIntervalSpec*)pPointerGlobal1;
  boolean *missing_index = (boolean *)pPointerGlobal2;
  StaticTimeAndIntervalVariation_uint8_t *variation = (StaticTimeAndIntervalVariation_uint8_t *)pPointerGlobal3;

//boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index, StaticTimeAndIntervalVariation_uint8_t variation);
//boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver3(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index);
////        if (!map.select(index, variation))
  if (!select_in_StaticDataMap_for_TimeAndIntervalSpecOver2(map, *index, *variation))
  {
    *missing_index = true;
  }
}

////template<class Spec>
IINField select_indices_for_TimeAndIntervalSpec_in_Database_staticOver1(StaticDataMap_for_TimeAndIntervalSpec* map,
    ICollection_for_uint16* indices,
    StaticTimeAndIntervalVariation_uint8_t variation)
{
  boolean missing_index = false;

  pPointerGlobal1 = map;
  pPointerGlobal2 = &missing_index;
  pPointerGlobal3 = &variation;

////    auto select = [&](uint16_t index) {

//boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index, StaticTimeAndIntervalVariation_uint8_t variation);
//boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver3(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index);
////        if (!map.select(index, variation))
////        {
////            missing_index = true;
////        }
////    };

//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////    indices.ForeachItem(select);
  ForeachItem_in_ICollection_for_uint16(indices, select_for_TimeAndIntervalSpec_in_DatabaseOver1);

//IINField Empty_in_IINField_static(void);
////    return missing_index ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return missing_index ? iIINField : Empty_in_IINField_static();
}

void select_for_TimeAndIntervalSpec_in_DatabaseOver2(uint16_t *index);
void select_for_TimeAndIntervalSpec_in_DatabaseOver2(uint16_t *index)
{
  StaticDataMap_for_TimeAndIntervalSpec* map = (StaticDataMap_for_TimeAndIntervalSpec*)pPointerGlobal1;
  boolean *missing_index = (boolean *)pPointerGlobal2;

//boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver2(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index, StaticTimeAndIntervalVariation_uint8_t variation);
//boolean select_in_StaticDataMap_for_TimeAndIntervalSpecOver3(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec, uint16_t index);
////        if (!map.select(index))
  if (!select_in_StaticDataMap_for_TimeAndIntervalSpecOver3(map, *index))
  {
    *missing_index = true;
  }
}

////template<class Spec> IINField select_indices(StaticDataMap<Spec>& map, const ICollection<uint16_t>& indices)
IINField select_indices_for_TimeAndIntervalSpec_in_Database_staticOver2(StaticDataMap_for_TimeAndIntervalSpec* map,
    ICollection_for_uint16* indices)
{
    boolean missing_index = false;

  pPointerGlobal1 = map;
  pPointerGlobal2 = &missing_index;

////    auto select = [&](uint16_t index) {
////        if (!map.select(index))
////        {
////            missing_index = true;
////        }
////    };

////    indices.ForeachItem(select);
  ForeachItem_in_ICollection_for_uint16(indices, select_for_TimeAndIntervalSpec_in_DatabaseOver2);

////    return missing_index ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return missing_index ? iIINField : Empty_in_IINField_static();
}

////template<class Spec> IINField Database::select_range(StaticDataMap<Spec>& map, const Range& range)
IINField select_range_for_TimaAndIntervalSpec_in_Database_staticOver1(StaticDataMap_for_TimeAndIntervalSpec* map, Range* range)
{
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range);
////    const auto count = map.select(range);
uint16_t count = select_in_StaticDataMap_for_TimeAndIntervalSpecOver1(map, *range);

//uint32_t Count_in_Range(Range *pRange);
////    return (count != range.Count()) ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return (count != Count_in_Range(range)) ? iIINField : Empty_in_IINField_static();
}

////template<class Spec>
////IINField Database::select_range(StaticDataMap<Spec>& map,
////                                const Range& range,
////                                typename Spec::static_variation_t variation)
IINField select_range_for_TimeAndIntervalSpec_in_Database_staticOver2(StaticDataMap_for_TimeAndIntervalSpec* map,
    Range* range, StaticTimeAndIntervalVariation_uint8_t variation)
{
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver4(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, StaticAnalogVariation_uint8_t variation);
////    const auto count = map.select(range, variation);
uint16_t count = select_in_StaticDataMap_for_TimeAndIntervalSpecOver4(map, *range, variation);

////    return (count != range.Count()) ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return (count != Count_in_Range(range)) ? iIINField : Empty_in_IINField_static();
}
