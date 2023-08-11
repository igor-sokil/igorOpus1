#include "header.h"
#include "StaticTypeBitfield.h"

void StaticTypeBitField_in_StaticTypeBitFieldOver1(StaticTypeBitField *pStaticTypeBitField)
{
  pStaticTypeBitField->mask = 0;
}

void StaticTypeBitField_in_StaticTypeBitFieldOver2(StaticTypeBitField *pStaticTypeBitField, uint16_t mask)
{
  pStaticTypeBitField->mask = mask;
}

StaticTypeBitField AllTypes_in_StaticTypeBitField_static(void)
{
  StaticTypeBitField sStaticTypeBitField;
  StaticTypeBitField_in_StaticTypeBitFieldOver2(&sStaticTypeBitField, ~0);
////        return StaticTypeBitField(~0);
  return sStaticTypeBitField;
}

boolean IsSet_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
{
  return (pStaticTypeBitField->mask & (uint16_t)(type)) != 0;
}

StaticTypeBitField Except_in_StaticTypeBitField(StaticTypeBitField *pStaticTypeBitField, StaticTypeBitmask_uint16_t type)
{
  StaticTypeBitField sStaticTypeBitField;
  StaticTypeBitField_in_StaticTypeBitFieldOver2(&sStaticTypeBitField, pStaticTypeBitField->mask & ~((uint16_t)(type)));
////        return StaticTypeBitField(mask & ~static_cast<uint16_t>(type));
  return sStaticTypeBitField;
}
