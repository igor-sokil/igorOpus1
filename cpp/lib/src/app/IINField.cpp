/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
////#include "opendnp3/app/IINField.h"
#include "header.h"
#include "IINField.h"

////namespace opendnp3
////{

boolean IsSet_in_IINField(IINField *pIINField, IINBit_uint8_t bit)
{
  switch (bit)
  {
  case (IINBit_BROADCAST):
    return Get_in_IINField_LSB(pIINField, LSBMask_BROADCAST);
  case (IINBit_CLASS1_EVENTS):
    return Get_in_IINField_LSB(pIINField, LSBMask_CLASS1_EVENTS);
  case (IINBit_CLASS2_EVENTS):
    return Get_in_IINField_LSB(pIINField, LSBMask_CLASS2_EVENTS);
  case (IINBit_CLASS3_EVENTS):
    return Get_in_IINField_LSB(pIINField, LSBMask_CLASS3_EVENTS);
  case (IINBit_NEED_TIME):
    return Get_in_IINField_LSB(pIINField, LSBMask_NEED_TIME);
  case (IINBit_LOCAL_CONTROL):
    return Get_in_IINField_LSB(pIINField, LSBMask_LOCAL_CONTROL);
  case (IINBit_DEVICE_TROUBLE):
    return Get_in_IINField_LSB(pIINField, LSBMask_DEVICE_TROUBLE);
  case (IINBit_DEVICE_RESTART):
    return Get_in_IINField_LSB(pIINField, LSBMask_DEVICE_RESTART);
  case (IINBit_FUNC_NOT_SUPPORTED):
    return Get_in_IINField_MSB(pIINField, MSBMask_FUNC_NOT_SUPPORTED);
  case (IINBit_OBJECT_UNKNOWN):
    return Get_in_IINField_MSB(pIINField, MSBMask_OBJECT_UNKNOWN);
  case (IINBit_PARAM_ERROR):
    return Get_in_IINField_MSB(pIINField, MSBMask_PARAM_ERROR);
  case (IINBit_EVENT_BUFFER_OVERFLOW):
    return Get_in_IINField_MSB(pIINField, MSBMask_EVENT_BUFFER_OVERFLOW);
  case (IINBit_ALREADY_EXECUTING):
    return Get_in_IINField_MSB(pIINField, MSBMask_ALREADY_EXECUTING);
  case (IINBit_CONFIG_CORRUPT):
    return Get_in_IINField_MSB(pIINField, MSBMask_CONFIG_CORRUPT);
  case (IINBit_RESERVED1):
    return Get_in_IINField_MSB(pIINField, MSBMask_RESERVED1);
  case (IINBit_RESERVED2):
    return Get_in_IINField_MSB(pIINField, MSBMask_RESERVED2);
  default:
    return false;
  };
}

void SetBitToValue_in_IINField(IINField *pIINField, IINBit_uint8_t bit, boolean value)
{
  if (value)
  {
    SetBit_in_IINField(pIINField, bit);
  }
  else
  {
    ClearBit_in_IINField(pIINField, bit);
  }
}

void SetBit_in_IINField(IINField *pIINField, IINBit_uint8_t bit)
{
  switch (bit)
  {
  case (IINBit_BROADCAST):
    Set_in_IINField_LSB(pIINField, LSBMask_BROADCAST);
    break;
  case (IINBit_CLASS1_EVENTS):
    Set_in_IINField_LSB(pIINField, LSBMask_CLASS1_EVENTS);
    break;
  case (IINBit_CLASS2_EVENTS):
    Set_in_IINField_LSB(pIINField, LSBMask_CLASS2_EVENTS);
    break;
  case (IINBit_CLASS3_EVENTS):
    Set_in_IINField_LSB(pIINField, LSBMask_CLASS3_EVENTS);
    break;
  case (IINBit_NEED_TIME):
    Set_in_IINField_LSB(pIINField, LSBMask_NEED_TIME);
    break;
  case (IINBit_LOCAL_CONTROL):
    Set_in_IINField_LSB(pIINField, LSBMask_LOCAL_CONTROL);
    break;
  case (IINBit_DEVICE_TROUBLE):
    Set_in_IINField_LSB(pIINField, LSBMask_DEVICE_TROUBLE);
    break;
  case (IINBit_DEVICE_RESTART):
    Set_in_IINField_LSB(pIINField, LSBMask_DEVICE_RESTART);
    break;
  case (IINBit_FUNC_NOT_SUPPORTED):
    Set_in_IINField_MSB(pIINField, MSBMask_FUNC_NOT_SUPPORTED);
    break;
  case (IINBit_OBJECT_UNKNOWN):
    Set_in_IINField_MSB(pIINField, MSBMask_OBJECT_UNKNOWN);
    break;
  case (IINBit_PARAM_ERROR):
    Set_in_IINField_MSB(pIINField, MSBMask_PARAM_ERROR);
    break;
  case (IINBit_EVENT_BUFFER_OVERFLOW):
    Set_in_IINField_MSB(pIINField, MSBMask_EVENT_BUFFER_OVERFLOW);
    break;
  case (IINBit_ALREADY_EXECUTING):
    Set_in_IINField_MSB(pIINField, MSBMask_ALREADY_EXECUTING);
    break;
  case (IINBit_CONFIG_CORRUPT):
    Set_in_IINField_MSB(pIINField, MSBMask_CONFIG_CORRUPT);
    break;
  case (IINBit_RESERVED1):
    Set_in_IINField_MSB(pIINField, MSBMask_RESERVED1);
    break;
  case (IINBit_RESERVED2):
    Set_in_IINField_MSB(pIINField, MSBMask_RESERVED2);
    break;
  default:
    break;
  };
}

void ClearBit_in_IINField(IINField *pIINField, IINBit_uint8_t bit)
{
  switch (bit)
  {
  case (IINBit_BROADCAST):
    Clear_in_IINField_LSB(pIINField, LSBMask_BROADCAST);
    break;
  case (IINBit_CLASS1_EVENTS):
    Clear_in_IINField_LSB(pIINField, LSBMask_CLASS1_EVENTS);
    break;
  case (IINBit_CLASS2_EVENTS):
    Clear_in_IINField_LSB(pIINField, LSBMask_CLASS2_EVENTS);
    break;
  case (IINBit_CLASS3_EVENTS):
    Clear_in_IINField_LSB(pIINField, LSBMask_CLASS3_EVENTS);
    break;
  case (IINBit_NEED_TIME):
    Clear_in_IINField_LSB(pIINField, LSBMask_NEED_TIME);
    break;
  case (IINBit_LOCAL_CONTROL):
    Clear_in_IINField_LSB(pIINField, LSBMask_LOCAL_CONTROL);
    break;
  case (IINBit_DEVICE_TROUBLE):
    Clear_in_IINField_LSB(pIINField, LSBMask_DEVICE_TROUBLE);
    break;
  case (IINBit_DEVICE_RESTART):
    Clear_in_IINField_LSB(pIINField, LSBMask_DEVICE_RESTART);
    break;
  case (IINBit_FUNC_NOT_SUPPORTED):
    Clear_in_IINField_MSB(pIINField, MSBMask_FUNC_NOT_SUPPORTED);
    break;
  case (IINBit_OBJECT_UNKNOWN):
    Clear_in_IINField_MSB(pIINField, MSBMask_OBJECT_UNKNOWN);
    break;
  case (IINBit_PARAM_ERROR):
    Clear_in_IINField_MSB(pIINField, MSBMask_PARAM_ERROR);
    break;
  case (IINBit_EVENT_BUFFER_OVERFLOW):
    Clear_in_IINField_MSB(pIINField, MSBMask_EVENT_BUFFER_OVERFLOW);
    break;
  case (IINBit_ALREADY_EXECUTING):
    Clear_in_IINField_MSB(pIINField, MSBMask_ALREADY_EXECUTING);
    break;
  case (IINBit_CONFIG_CORRUPT):
    Clear_in_IINField_MSB(pIINField, MSBMask_CONFIG_CORRUPT);
    break;
  case (IINBit_RESERVED1):
    Clear_in_IINField_MSB(pIINField, MSBMask_RESERVED1);
    break;
  case (IINBit_RESERVED2):
    Clear_in_IINField_MSB(pIINField, MSBMask_RESERVED2);
    break;
  default:
    break;
  };
}

IINField Empty_in_IINField_static(void)
{
  IINField iINField;
  IINField_in_IINFieldOver3(&iINField, 0, 0);
  return iINField;
}

void IINField_in_IINFieldOver2(IINField *pIINField, IINBit_uint8_t bit)
{
  pIINField -> LSB = 0;
  pIINField -> MSB = 0;
  SetBit_in_IINField(pIINField, bit);
}

void IINField_in_IINFieldOver3(IINField *pIINField, uint8_t aLSB, uint8_t aMSB)
{
  pIINField -> LSB = aLSB;
  pIINField -> MSB = aMSB;
}

void IINField_in_IINFieldOver1(IINField *pIINField)
{
  pIINField -> LSB = 0;
  pIINField -> MSB = 0;
}

IINField operatorOREQ_in_IINField(IINField *pIINField, IINField* aIIN)
{
  pIINField->MSB |= aIIN->MSB;
  pIINField->LSB |= aIIN->LSB;
  return *pIINField;
}

////    IINField operator|(const IINField& aIIN) const
IINField operatorOR_in_IINField(IINField *pIINField, IINField* aIIN)
{
////        return IINField(LSB | aIIN.LSB, MSB | aIIN.MSB);
  IINField iIINField;
  IINField_in_IINFieldOver3(&iIINField, pIINField->LSB | aIIN->LSB, pIINField->MSB | aIIN->MSB);
  return iIINField;
}

////    bool IsSet(IINBit bit) const;

boolean IsClear_in_IINField(IINField *pIINField, IINBit_uint8_t bit)
{
  return !IsSet_in_IINField(pIINField, bit);
}

////    void SetBit(IINBit bit);
////    void ClearBit(IINBit bit);

////    void SetBitToValue(IINBit bit, bool value);

////    bool operator==(const IINField& aRHS) const;

boolean Any_in_IINField(IINField *pIINField)
{
  return (pIINField->LSB | pIINField->MSB) != 0;
}

void Clear_in_IINField(IINField *pIINField)
{
  pIINField->LSB = pIINField->MSB = 0;
}

boolean HasRequestError_in_IINField(IINField *pIINField)
{
  return Get_in_IINField_MSB(pIINField, MSBMask_REQUEST_ERROR_MASK);
}

////    IINField operator|(const IINField& aIIN) const
////    {
////        return IINField(LSB | aIIN.LSB, MSB | aIIN.MSB);
////    }

////    IINField& operator|=(const IINField& aIIN)
////    {
////        MSB |= aIIN.MSB;
////        LSB |= aIIN.LSB;
////        return *this;
////    }

////    IINField operator&(const IINField& aIIN) const
////    {
////        return IINField(LSB & aIIN.LSB, MSB & aIIN.MSB);
////    }

////    IINField& operator&=(const IINField& aIIN)
////    {
////        MSB &= aIIN.MSB;
////        LSB &= aIIN.LSB;
////        return *this;
////    }

////    IINField operator~() const
////    {
////        return IINField(~LSB, ~MSB);
////    }

////private:
////    static const uint8_t REQUEST_ERROR_MASK;

boolean Get_in_IINField_LSB(IINField *pIINField, LSBMask_uint8_t bit)
{
  return (pIINField->LSB & bit) != 0;////static_cast<uint8_t>(bit)) != 0;
}

boolean Get_in_IINField_MSB(IINField *pIINField, MSBMask_uint8_t bit)
{
  return (pIINField->MSB & bit) != 0;////static_cast<uint8_t>(bit)) != 0;
}

void Set_in_IINField_LSB(IINField *pIINField, LSBMask_uint8_t bit)
{
  pIINField->LSB |= bit;
}

void Set_in_IINField_MSB(IINField *pIINField, MSBMask_uint8_t bit)
{
  pIINField->MSB |= bit;
}

void Clear_in_IINField_LSB(IINField *pIINField, LSBMask_uint8_t bit)
{
  pIINField->LSB &= ~(int)bit;
}

void Clear_in_IINField_MSB(IINField *pIINField, MSBMask_uint8_t bit)
{
  pIINField->MSB &= ~(int)bit;
}

////bool IINField::operator==(const IINField& aRHS) const
////{
////    return (LSB == aRHS.LSB) && (MSB == aRHS.MSB);
////}

////} // namespace opendnp3
