#ifndef OPENDNP3_MAP_AnalogMrzs_H
#define OPENDNP3_MAP_AnalogMrzs_H

#include "StaticDataMap.h"
#include "MeasurementTypeSpecs.h"
#include "Range.h"
//#include "IEventReceiver.h"
#include "StaticDataCell.h"

#define SIZE_map_for_AnalogMrzs  10

typedef struct
{
  StaticDataRecord_for_Analog* begin;
  StaticDataRecord_for_Analog* end;
  Range range;
} Iterator_Map_for_AnalogMrzs;

typedef struct
{
  StaticDataRecord_for_Analog map_for_AnalogMrzs[SIZE_map_for_AnalogMrzs];
//  Range selected_in_StaticDataMap_for_AnalogMrzs;

  uint16_t sizeMap_for_AnalogMrzs;
  Iterator_Map_for_AnalogMrzs iIterator_Map_for_AnalogMrzs;
} Map_for_AnalogMrzs;

///*
StaticDataRecord_for_Analog* IncrementIteratorBegin_for_Map_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs);

StaticDataRecord_for_Analog *mapEnd_in_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs);
StaticDataRecord_for_Analog *mapBegin_in_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs);
//StaticDataRecord_for_Analog *mapLowerBound_in_StaticDataMap_for_AnalogMrzs(StaticDataMap_for_AnalogMrzs *pStaticDataMap_for_AnalogMrzs, uint16_t lowerBound);

void Iterator_Map_for_AnalogMrzs_in_Iterator_Map_for_AnalogMrzs(Iterator_Map_for_AnalogMrzs *pIterator_Map_for_AnalogMrzs,
     StaticDataRecord_for_Analog* begin, StaticDataRecord_for_Analog* end, Range *range);

//StaticDataRecord_for_Analog* setIteratorEnd_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs);
//StaticDataRecord_for_Analog* setIteratorBegin_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs);
StaticDataRecord_for_Analog* getIteratorBegin_Map_for_AnalogMrzs(Map_for_AnalogMrzs *pMap_for_AnalogMrzs);
//*/

#endif
