#include "header.h"
#include "MeasurementTypeSpecs.h"
#include "StaticDataCell.h"

    void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
                                                                BinaryConfig_for_EventConfig_for_BinaryInfo* config)
{
 pStaticDataCell_for_Binary->config = *config;
}

  void  StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver2(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
                                                           Binary* value, 
                                                           BinaryConfig_for_EventConfig_for_BinaryInfo* config)
{
      pStaticDataCell_for_Binary->value = *value;
      pStaticDataCell_for_Binary->config = *config;
 }
