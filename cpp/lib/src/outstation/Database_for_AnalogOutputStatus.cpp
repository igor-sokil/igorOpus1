#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_AnalogOutputStatus_in_Database_static(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"load_type_for_AnalogOutputStatus_in_Database_static1"<<'\n';
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

    StaticAnalogOutputStatusVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_AnalogOutputStatusSpec)(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer);//��������� �� �-���
//static_write_func_t_for_AnalogOutputStatusSpec                   get_for_AnalogOutputStatusSpec_static(StaticAnalogOutputStatusVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_AnalogOutputStatusSpec_in_StaticWriters_static(variation)(map, writer))
    {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*if (!get_for_AnalogOutputStatusSpec_in_StaticWriters_static(variation)(map, writer))"<<'\n';
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
void select_all_class_zero_StaticDataMap_for_AnalogOutputStatusSpec(Database *pDatabase, StaticDataMap_for_AnalogOutputStatusSpec* map)
{
//boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
////    if (this->allowed_class_zero_types.IsSet(Spec::StaticTypeEnum))
  if (IsSet_in_StaticTypeBitField(&(pDatabase->allowed_class_zero_types), StaticTypeBitmask_AnalogOutputStatus))
  {
//IINField select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_static(StaticDataMap_for_AnalogOutputStatusSpec* map)
////        select_all<Spec>(map);
    select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver1(map);
  }
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
IINField select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver1(StaticDataMap_for_AnalogOutputStatusSpec* map)
{
////    map.select_all();
  select_all_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(map);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map, typename Spec::static_variation_t variation)
IINField select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver2(StaticDataMap_for_AnalogOutputStatusSpec* map, StaticAnalogOutputStatusVariation_uint8_t variation)
{
////    map.select_all(variation);
  select_all_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(map, variation);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////bool Database::Update(const AnalogOutputStatus& meas, uint16_t index, EventMode mode)
boolean Update_for_AnalogOutputStatus_in_Database(Database *pDatabase, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode)
{
//boolean update_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec,
//    AnalogOutputStatus* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return this->analog_output_status.update(meas, index, mode, event_receiver);
  return update_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(&(pDatabase->analog_output_status), meas, index, mode, pDatabase->event_receiver);
}

void select_for_AnalogOutputStatusSpec_in_DatabaseOver1(uint16_t *index);
void select_for_AnalogOutputStatusSpec_in_DatabaseOver1(uint16_t *index)
{
  StaticDataMap_for_AnalogOutputStatusSpec* map = (StaticDataMap_for_AnalogOutputStatusSpec*)pPointerGlobal1;
  boolean *missing_index = (boolean *)pPointerGlobal2;
  StaticAnalogOutputStatusVariation_uint8_t *variation = (StaticAnalogOutputStatusVariation_uint8_t *)pPointerGlobal3;

//boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index, StaticAnalogOutputStatusVariation_uint8_t variation);
//boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index);
////        if (!map.select(index, variation))
  if (!select_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(map, *index, *variation))
  {
    *missing_index = true;
  }
}

////template<class Spec>
IINField select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver1(StaticDataMap_for_AnalogOutputStatusSpec* map,
    ICollection_for_uint16* indices,
    StaticAnalogOutputStatusVariation_uint8_t variation)
{
  boolean missing_index = false;

  pPointerGlobal1 = map;
  pPointerGlobal2 = &missing_index;
  pPointerGlobal3 = &variation;

////    auto select = [&](uint16_t index) {

//boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index, StaticAnalogOutputStatusVariation_uint8_t variation);
//boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index);
////        if (!map.select(index, variation))
////        {
////            missing_index = true;
////        }
////    };

//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////    indices.ForeachItem(select);
  ForeachItem_in_ICollection_for_uint16(indices, select_for_AnalogOutputStatusSpec_in_DatabaseOver1);

//IINField Empty_in_IINField_static(void);
////    return missing_index ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return missing_index ? iIINField : Empty_in_IINField_static();
}

void select_for_AnalogOutputStatusSpec_in_DatabaseOver2(uint16_t *index);
void select_for_AnalogOutputStatusSpec_in_DatabaseOver2(uint16_t *index)
{
  StaticDataMap_for_AnalogOutputStatusSpec* map = (StaticDataMap_for_AnalogOutputStatusSpec*)pPointerGlobal1;
  boolean *missing_index = (boolean *)pPointerGlobal2;

//boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index, StaticAnalogOutputStatusVariation_uint8_t variation);
//boolean select_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(StaticDataMap_for_AnalogOutputStatusSpec *pStaticDataMap_for_AnalogOutputStatusSpec, uint16_t index);
////        if (!map.select(index))
  if (!select_in_StaticDataMap_for_AnalogOutputStatusSpecOver3(map, *index))
  {
    *missing_index = true;
  }
}

////template<class Spec> IINField select_indices(StaticDataMap<Spec>& map, const ICollection<uint16_t>& indices)
IINField select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver2(StaticDataMap_for_AnalogOutputStatusSpec* map,
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
  ForeachItem_in_ICollection_for_uint16(indices, select_for_AnalogOutputStatusSpec_in_DatabaseOver2);

////    return missing_index ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return missing_index ? iIINField : Empty_in_IINField_static();
}

////template<class Spec> IINField Database::select_range(StaticDataMap<Spec>& map, const Range& range)
IINField select_range_for_AnalogOutputStatusSpec_in_Database_staticOver1(StaticDataMap_for_AnalogOutputStatusSpec* map, Range* range)
{
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver1(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range);
////    const auto count = map.select(range);
uint16_t count = select_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(map, *range);

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
IINField select_range_for_AnalogOutputStatusSpec_in_Database_staticOver2(StaticDataMap_for_AnalogOutputStatusSpec* map,
    Range* range, StaticAnalogOutputStatusVariation_uint8_t variation)
{
//uint16_t select_in_StaticDataMap_for_AnalogSpecOver4(StaticDataMap_for_AnalogSpec *pStaticDataMap_for_AnalogSpec, Range range, StaticAnalogVariation_uint8_t variation);
////    const auto count = map.select(range, variation);
uint16_t count = select_in_StaticDataMap_for_AnalogOutputStatusSpecOver4(map, *range, variation);

////    return (count != range.Count()) ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return (count != Count_in_Range(range)) ? iIINField : Empty_in_IINField_static();
}
