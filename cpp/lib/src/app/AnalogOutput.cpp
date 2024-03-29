////#include "opendnp3/app/AnalogOutput.h"
#include "header.h"
//#include <QtWidgets>

#include "AnalogOutput.h"

//-----------------------------------------AnalogOutput_for_Int16-------------------------------------------
boolean ValuesEqual_in_AnalogOutput_for_Int16(AnalogOutput_for_Int16 *pAnalogOutput, AnalogOutput_for_Int16* lhs)
{
  return pAnalogOutput -> value == lhs -> value;
}

void AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over1(AnalogOutput_for_Int16 *pAnalogOutput)
{
  pAnalogOutput -> value = 0;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over2(AnalogOutput_for_Int16 *pAnalogOutput, int16_t value_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over3(AnalogOutput_for_Int16 *pAnalogOutput, int16_t value_, CommandStatus_uint8_t status_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = status_;
}

//-------------------------------------------AnalogOutput_for_Int16--------------------------------------------------
//-------------------------------------------AnalogOutput_for_Int32--------------------------------------------------

boolean ValuesEqual_in_AnalogOutput_for_Int32(AnalogOutput_for_Int32 *pAnalogOutput, AnalogOutput_for_Int32* lhs)
{
  return pAnalogOutput -> value == lhs -> value;
}

void AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over1(AnalogOutput_for_Int32 *pAnalogOutput)
{
  pAnalogOutput -> value = 0;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over2(AnalogOutput_for_Int32 *pAnalogOutput, int32_t value_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over3(AnalogOutput_for_Int32 *pAnalogOutput, int32_t value_, CommandStatus_uint8_t status_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = status_;
}

//------------------------------------------------AnalogOutput_for_Int32---------------------------------------------
//------------------------------------------------AnalogOutput_for_Float32---------------------------------------------

////  boolean ValuesEqual_in_AnalogOutput_for_Float32(AnalogOutput_for_Float32 *pAnalogOutput, float value_)
////{
////    return pAnalogOutput -> value == lhs -> value;
////}

void AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over1(AnalogOutput_for_Float32 *pAnalogOutput)
{
  pAnalogOutput -> value = 0;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over2(AnalogOutput_for_Float32 *pAnalogOutput, float value_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over3(AnalogOutput_for_Float32 *pAnalogOutput, float value_, CommandStatus_uint8_t status_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = status_;
}

//-------------------------------------------AnalogOutput_for_Float32--------------------------------------------------
//-------------------------------------------AnalogOutput_for_Double64--------------------------------------------------


////  boolean ValuesEqual_in_AnalogOutput_for_Double64(AnalogOutput_for_Double64 *pAnalogOutput, double value_)
////{
////    return pAnalogOutput -> value == lhs -> value;
////}

void AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over1(AnalogOutput_for_Double64 *pAnalogOutput)
{
  pAnalogOutput -> value = 0;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over2(AnalogOutput_for_Double64 *pAnalogOutput, double value_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = CommandStatus_SUCCESS;
}

void AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over3(AnalogOutput_for_Double64 *pAnalogOutput, double value_, CommandStatus_uint8_t status_)
{
  pAnalogOutput -> value = value_;
  pAnalogOutput -> status = status_;
}

//---------------------------------------------------AnalogOutput_for_Double64------------------------------------------

void AnalogOutputInt16_in_AnalogOutputInt16Over1(AnalogOutputInt16 *pAnalogOutputInt16)
{
  AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over1(&(pAnalogOutputInt16 -> aAnalogOutput_for_Int16));
}

void AnalogOutputInt16_in_AnalogOutputInt16Over2(AnalogOutputInt16 *pAnalogOutputInt16, int16_t value_)
{
  AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over2(&(pAnalogOutputInt16 -> aAnalogOutput_for_Int16), value_);
}

void AnalogOutputInt16_in_AnalogOutputInt16Over3(AnalogOutputInt16 *pAnalogOutputInt16, int16_t value_, CommandStatus_uint8_t status_)
{
  AnalogOutput_for_Int16_in_AnalogOutput_for_Int16Over3(&(pAnalogOutputInt16 -> aAnalogOutput_for_Int16), value_, status_);
}

void AnalogOutputInt32_in_AnalogOutputInt32Over1(AnalogOutputInt32 *pAnalogOutputInt32)
{
  AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over1(&(pAnalogOutputInt32 -> aAnalogOutput_for_Int32));
}

void AnalogOutputInt32_in_AnalogOutputInt32Over2(AnalogOutputInt32 *pAnalogOutputInt32, int32_t value_)
{
  AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over2(&(pAnalogOutputInt32 -> aAnalogOutput_for_Int32), value_);
}

void AnalogOutputInt32_in_AnalogOutputInt32Over3(AnalogOutputInt32 *pAnalogOutputInt32, int32_t value_, CommandStatus_uint8_t status_)
{
  AnalogOutput_for_Int32_in_AnalogOutput_for_Int32Over3(&(pAnalogOutputInt32 -> aAnalogOutput_for_Int32), value_, status_);
}

void AnalogOutputFloat32_in_AnalogOutputFloat32Over1(AnalogOutputFloat32 *pAnalogOutputFloat32)
{
  AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over1(&(pAnalogOutputFloat32 -> aAnalogOutput_for_Float32));
}

void AnalogOutputFloat32_in_AnalogOutputFloat32Over2(AnalogOutputFloat32 *pAnalogOutputFloat32, float value_)
{
  AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over2(&(pAnalogOutputFloat32 -> aAnalogOutput_for_Float32), value_);
}

void AnalogOutputFloat32_in_AnalogOutputFloat32Over3(AnalogOutputFloat32 *pAnalogOutputFloat32, float value_, CommandStatus_uint8_t status_)
{
  AnalogOutput_for_Float32_in_AnalogOutput_for_Float32Over3(&(pAnalogOutputFloat32 -> aAnalogOutput_for_Float32), value_, status_);
}

void AnalogOutputDouble64_in_AnalogOutputDouble64Over1(AnalogOutputDouble64 *pAnalogOutputDouble64)
{
  AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over1(&(pAnalogOutputDouble64 -> aAnalogOutput_for_Double64));
}

void AnalogOutputDouble64_in_AnalogOutputDouble64Over2(AnalogOutputDouble64 *pAnalogOutputDouble64, double value_)
{
  AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over2(&(pAnalogOutputDouble64 -> aAnalogOutput_for_Double64), value_);
}

void AnalogOutputDouble64_in_AnalogOutputDouble64Over3(AnalogOutputDouble64 *pAnalogOutputDouble64, double value_, CommandStatus_uint8_t status_)
{
  AnalogOutput_for_Double64_in_AnalogOutput_for_Double64Over3(&(pAnalogOutputDouble64 -> aAnalogOutput_for_Double64), value_, status_);
}
