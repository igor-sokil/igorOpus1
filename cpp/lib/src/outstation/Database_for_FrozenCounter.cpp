#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_FrozenCounter_in_Database_static(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer)
{
  while (true)
  {
    auto iter = map.begin();

    if (iter == map.end())
    {
      // there is no data left to write
      return true;
    }

    StaticFrozenCounterVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_FrozenCounterSpec)(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);//указатель на ф-цию
//static_write_func_t_for_FrozenCounterSpec                   get_for_FrozenCounterSpec_static(StaticFrozenCounterVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_FrozenCounterSpec_in_StaticWriters_static(variation)(map, writer))
    {
      // the APDU is full
      return false;
    }
  }
}

////template<class Spec> void Database::select_all_class_zero(StaticDataMap<Spec>& map)
void select_all_class_zero_StaticDataMap_for_FrozenCounterSpec(Database *pDatabase, StaticDataMap_for_FrozenCounterSpec* map)
{
//boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
////    if (this->allowed_class_zero_types.IsSet(Spec::StaticTypeEnum))
  if (IsSet_in_StaticTypeBitField(&(pDatabase->allowed_class_zero_types), StaticTypeBitmask_FrozenCounter))
  {
//IINField select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_static(StaticDataMap_for_FrozenCounterSpec* map)
////        select_all<Spec>(map);
    select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_static(map);
  }
}


////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
IINField select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_static(StaticDataMap_for_FrozenCounterSpec* map)
{
////    map.select_all();
  select_all_in_StaticDataMap_for_FrozenCounterSpecOver1(map);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}
