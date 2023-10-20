#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_BinaryOutputStatus_in_Database_static(StaticDataMap_for_BinaryOutputStatusSpec& map, HeaderWriter* writer)
{
  while (true)
  {
    auto iter = map.begin();

    if (iter == map.end())
    {
      // there is no data left to write
      return true;
    }

    StaticBinaryOutputStatusVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_BinaryOutputStatusSpec)(StaticDataMap_for_BinaryOutputStatusSpec& map, HeaderWriter* writer);//указатель на ф-цию
//static_write_func_t_for_BinaryOutputStatusSpec                   get_for_BinaryOutputStatusSpec_static(StaticBinaryOutputStatusVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_BinaryOutputStatusSpec_in_StaticWriters_static(variation)(map, writer))
    {
      // the APDU is full
      return false;
    }
  }
}

////template<class Spec> void Database::select_all_class_zero(StaticDataMap<Spec>& map)
void select_all_class_zero_StaticDataMap_for_BinaryOutputStatusSpec(Database *pDatabase, StaticDataMap_for_BinaryOutputStatusSpec* map)
{
//boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
////    if (this->allowed_class_zero_types.IsSet(Spec::StaticTypeEnum))
  if (IsSet_in_StaticTypeBitField(&(pDatabase->allowed_class_zero_types), StaticTypeBitmask_BinaryOutputStatus))
  {
//IINField select_all_StaticDataMap_for_BinaryOutputStatusSpec_in_Database_static(StaticDataMap_for_BinaryOutputStatusSpec* map)
////        select_all<Spec>(map);
    select_all_StaticDataMap_for_BinaryOutputStatusSpec_in_Database_static(map);
  }
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
IINField select_all_StaticDataMap_for_BinaryOutputStatusSpec_in_Database_static(StaticDataMap_for_BinaryOutputStatusSpec* map)
{
////    map.select_all();
  select_all_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(map);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////bool Database::Update(const Binary& meas, uint16_t index, EventMode mode)
boolean Update_for_BinaryOutputStatus_in_Database(Database *pDatabase, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode)
{
//boolean update_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(StaticDataMap_for_BinaryOutputStatusSpec *pStaticDataMap_for_BinaryOutputStatusSpec,
//    BinaryOutputStatus* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return this->binary_output_status.update(meas, index, mode, event_receiver);
  return update_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(&(pDatabase->binary_output_status), meas, index, mode, pDatabase->event_receiver);
}
