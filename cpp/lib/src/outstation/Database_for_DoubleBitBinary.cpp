#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_DoubleBitBinary_in_Database_static(StaticDataMap_for_DoubleBitBinarySpec& map, HeaderWriter* writer)
{
  while (true)
  {
    auto iter = map.begin();

    if (iter == map.end())
    {
      // there is no data left to write
      return true;
    }

    StaticDoubleBinaryVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_DoubleBitBinarySpec)(StaticDataMap_for_DoubleBitBinarySpec& map, HeaderWriter* writer);//указатель на ф-цию
//static_write_func_t_for_DoubleBitBinarySpec                   get_for_DoubleBitBinarySpec_static(StaticDoubleBitBinaryVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_DoubleBitBinarySpec_in_StaticWriters_static(variation)(map, writer))
    {
      // the APDU is full
      return false;
    }
  }
}

////template<class Spec> void Database::select_all_class_zero(StaticDataMap<Spec>& map)
void select_all_class_zero_StaticDataMap_for_DoubleBitBinarySpec(Database *pDatabase, StaticDataMap_for_DoubleBitBinarySpec* map)
{
//boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
////    if (this->allowed_class_zero_types.IsSet(Spec::StaticTypeEnum))
  if (IsSet_in_StaticTypeBitField(&(pDatabase->allowed_class_zero_types), StaticTypeBitmask_DoubleBinaryInput))
  {
//IINField select_all_StaticDataMap_for_DoubleBitBinarySpec_in_Database_static(StaticDataMap_for_DoubleBitBinarySpec* map)
////        select_all<Spec>(map);
    select_all_StaticDataMap_for_DoubleBitBinarySpec_in_Database_static(map);
  }
}

////template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
IINField select_all_StaticDataMap_for_DoubleBitBinarySpec_in_Database_static(StaticDataMap_for_DoubleBitBinarySpec* map)
{
////    map.select_all();
  select_all_in_StaticDataMap_for_DoubleBitBinarySpecOver1(map);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////bool Database::Update(const DoubleBitBinary& meas, uint16_t index, EventMode mode)
boolean Update_for_DoubleBitBinary_in_Database(Database *pDatabase, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode)
{
//boolean update_in_StaticDataMap_for_DoubleBitBinarySpecOver1(StaticDataMap_for_DoubleBitBinarySpec *pStaticDataMap_for_DoubleBitBinarySpec,
//    DoubleBitBinary* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////    return this->double_binary.update(meas, index, mode, event_receiver);
  return update_in_StaticDataMap_for_DoubleBitBinarySpecOver1(&(pDatabase->double_binary), meas, index, mode, pDatabase->event_receiver);
}
