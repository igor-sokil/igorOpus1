#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_OctetString_in_Database_static(StaticDataMap_for_OctetStringSpec& map, HeaderWriter* writer)
{
  while (true)
  {
    auto iter = map.begin();

    if (iter == map.end())
    {
      // there is no data left to write
      return true;
    }

    StaticOctetStringVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_OctetStringSpec)(StaticDataMap_for_OctetStringSpec& map, HeaderWriter* writer);//��������� �� �-���
//static_write_func_t_for_OctetStringSpec                   get_for_OctetStringSpec_static(StaticOctetStringVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_OctetStringSpec_in_StaticWriters_static(variation)(map, writer))
    {
      // the APDU is full
      return false;
    }
  }
}

////template<class Spec> void Database::select_all_class_zero(StaticDataMap<Spec>& map)
void select_all_class_zero_StaticDataMap_for_OctetStringSpec(Database *pDatabase, StaticDataMap_for_OctetStringSpec* map)
{
//boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
////    if (this->allowed_class_zero_types.IsSet(Spec::StaticTypeEnum))
  if (IsSet_in_StaticTypeBitField(&(pDatabase->allowed_class_zero_types), StaticTypeBitmask_OctetString))
  {
//IINField select_all_StaticDataMap_for_OctetStringSpec_in_Database_static(StaticDataMap_for_OctetStringSpec* map)
////        select_all<Spec>(map);
    select_all_StaticDataMap_for_OctetStringSpec_in_Database_static(map);
  }
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
IINField select_all_StaticDataMap_for_OctetStringSpec_in_Database_static(StaticDataMap_for_OctetStringSpec* map)
{
////    map.select_all();
  select_all_in_StaticDataMap_for_OctetStringSpecOver1(map);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////bool Database::Update(const OctetString& meas, uint16_t index, EventMode mode)
boolean Update_for_OctetString_in_Database(Database *pDatabase, OctetString* meas, uint16_t index, EventMode_uint8_t mode)
{
//boolean update_in_StaticDataMap_for_OctetStringSpecOver1(StaticDataMap_for_OctetStringSpec *pStaticDataMap_for_OctetStringSpec,
//    OctetString* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return this->octet_string.update(meas, index, mode, event_receiver);
  return update_in_StaticDataMap_for_OctetStringSpecOver1(&(pDatabase->octet_string), meas, index, mode, pDatabase->event_receiver);
}
