#include "header.h"
#include "BaseMeasurementTypes.h"

void Measurement_in_MeasurementOver1(Measurement *pMeasurement)
{
  DNPTime timeDNPTime;
  DNPTime_in_DNPTimeOver1(&timeDNPTime);
  pMeasurement->timeDNPTime = timeDNPTime;
}

void Measurement_in_MeasurementOver2(Measurement *pMeasurement, Flags flags)
{
  Measurement_in_MeasurementOver1(pMeasurement);
  pMeasurement->flags = flags;
}

void Measurement_in_MeasurementOver3(Measurement *pMeasurement, Flags flags, DNPTime timeDNPTime)
{
  pMeasurement->timeDNPTime = timeDNPTime;
  pMeasurement->flags = flags;
}

void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over1(
  TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64)
{
  Measurement_in_MeasurementOver1( &(pTypedMeasurement_for_Double64->mMeasurement));
  pTypedMeasurement_for_Double64->value = 0;
}

void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over2(
  TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_Double64->mMeasurement), flags);
  pTypedMeasurement_for_Double64->value = 0;
}

void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over3(
  TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64,
  double value, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_Double64->mMeasurement), flags);
  pTypedMeasurement_for_Double64->value = value;
}

void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over4(
  TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64,
  double value, Flags flags, DNPTime timeDNPTime)
{
  Measurement_in_MeasurementOver3( &(pTypedMeasurement_for_Double64->mMeasurement), flags, timeDNPTime);
  pTypedMeasurement_for_Double64->value = value;
}
//--------------------------------------------------------------------------------------------------------------

void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver1(
  TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean)
{
  Measurement_in_MeasurementOver1( &(pTypedMeasurement_for_Boolean->mMeasurement));
  pTypedMeasurement_for_Boolean->value = 0;
}

void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver2(
  TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_Boolean->mMeasurement), flags);
  pTypedMeasurement_for_Boolean->value = 0;
}

void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(
  TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean,
  boolean value, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_Boolean->mMeasurement), flags);
  pTypedMeasurement_for_Boolean->value = value;
}

void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver4(
  TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean,
  boolean value, Flags flags, DNPTime timeDNPTime)
{
  Measurement_in_MeasurementOver3( &(pTypedMeasurement_for_Boolean->mMeasurement), flags, timeDNPTime);
  pTypedMeasurement_for_Boolean->value = value;
}

//--------------------------------------------------------------------------------------------------------------
void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver4(
  TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t, DoubleBit_uint8_t value, Flags flags, DNPTime timeDNPTime)
{
  Measurement_in_MeasurementOver3( &(pTypedMeasurement_for_DoubleBit_uint8_t->mMeasurement), flags, timeDNPTime);
  pTypedMeasurement_for_DoubleBit_uint8_t->value = value;
}

void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver3(
  TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t, DoubleBit_uint8_t value, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_DoubleBit_uint8_t->mMeasurement), flags);
  pTypedMeasurement_for_DoubleBit_uint8_t->value = value;
}

void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver2(
  TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_DoubleBit_uint8_t->mMeasurement), flags);
  pTypedMeasurement_for_DoubleBit_uint8_t->value = 0;
}

void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver1(
  TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t)
{
  Measurement_in_MeasurementOver1( &(pTypedMeasurement_for_DoubleBit_uint8_t->mMeasurement));
  pTypedMeasurement_for_DoubleBit_uint8_t->value = 0;
}

//--------------------------------------------------------------------------------------------------------------

void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over4(
  TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32, uint32_t value, Flags flags, DNPTime timeDNPTime)
{
  Measurement_in_MeasurementOver3( &(pTypedMeasurement_for_Uint32->mMeasurement), flags, timeDNPTime);
  pTypedMeasurement_for_Uint32->value = value;
}

void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(
  TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32, uint32_t value, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_Uint32->mMeasurement), flags);
  pTypedMeasurement_for_Uint32->value = value;
}

void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over2(
  TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32, Flags flags)
{
  Measurement_in_MeasurementOver2( &(pTypedMeasurement_for_Uint32->mMeasurement), flags);
  pTypedMeasurement_for_Uint32->value = 0;
}

void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over1(
  TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32)
{
  Measurement_in_MeasurementOver1( &(pTypedMeasurement_for_Uint32->mMeasurement));
  pTypedMeasurement_for_Uint32->value = 0;
}



