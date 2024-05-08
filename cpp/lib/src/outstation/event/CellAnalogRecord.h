#ifndef OPENDNP3_CELLANALOGRECORD_H
#define OPENDNP3_CELLANALOGRECORD_H

#include "StaticDataCell.h"

//typedef struct
//{
//  uint16_t data1;
//  uint16_t data2;
//} UserData;

//void UserData_in_UserData(UserData *pUserData);

typedef struct
{
  uint16_t index;
  StaticDataCell_for_Analog sStaticDataCell_for_Analog;
} CellAnalogRecord;

void CellAnalogRecord_in_CellAnalogRecord(CellAnalogRecord *pCellAnalogRecord);

#endif
