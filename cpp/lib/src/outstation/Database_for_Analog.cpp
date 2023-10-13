#include <QApplication>
#include "header.h"
#include "Database.h"

////template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
boolean load_type_for_Analog_in_Database_static(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer)
{
  while (true)
  {
    auto iter = map.begin();

    if (iter == map.end())
    {
      // there is no data left to write
      return true;
    }

    StaticAnalogVariation_uint8_t variation = (*iter).second.variation;
//typedef boolean  (* static_write_func_t_for_AnalogSpec)(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer);//указатель на ф-цию
//static_write_func_t_for_AnalogSpec                   get_for_AnalogSpec_static(StaticAnalogVariation_uint8_t variation);
////        if (!StaticWriters::get((*iter).second.variation)(map, writer))
    if (!get_for_AnalogSpec_in_StaticWriters_static(variation)(map, writer))
    {
      // the APDU is full
      return false;
    }
  }
}
