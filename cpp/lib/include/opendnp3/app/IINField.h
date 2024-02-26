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
#ifndef OPENDNP3_IINFIELD_H
#define OPENDNP3_IINFIELD_H

////#include <cstdint>

////namespace opendnp3
////{

#define IINBit_uint8_t uint8_t
enum IINBit
{
  IINBit_BROADCAST = 0,              //0
  IINBit_CLASS1_EVENTS,              //1
  IINBit_CLASS2_EVENTS,              //2
  IINBit_CLASS3_EVENTS,              //3

//Требуется синхронизация времени от мастера. Сбрасывается, когда время устанавливает мастер.
  IINBit_NEED_TIME,                  //4

//Установите, когда устройство находится в локальном состоянии. Сбрасывается, когда устройство находится в удаленном состоянии.
  IINBit_LOCAL_CONTROL,              //5
  IINBit_DEVICE_TROUBLE,             //6

//Перезапуск устройства — устанавливается при включении устройства или после выполнения холодного перезапуска. Сбрасывается кнопкой
//запись нуля в объект 80.
  IINBit_DEVICE_RESTART,             //7
  IINBit_FUNC_NOT_SUPPORTED,         //8
  IINBit_OBJECT_UNKNOWN,             //9
  IINBit_PARAM_ERROR,                //10
  IINBit_EVENT_BUFFER_OVERFLOW,      //11
  IINBit_ALREADY_EXECUTING,          //12

//устанавливается, когда текущая конфигурация устройства повреждена. Также может быть установлено в результате
//юридических изменений в конфигурации установки всякий раз, когда другая установка затрагивается
//внесены изменения. Устраняется сбросом диагностики устройства.
  IINBit_CONFIG_CORRUPT,             //13
  IINBit_RESERVED1,                  //14
  IINBit_RESERVED2 = 15              //15
};

/** DNP3 two-byte IIN field.
 */
//    enum class LSBMask : uint8_t
#define LSBMask_uint8_t uint8_t
enum LSBMask
{
  LSBMask_BROADCAST = 0x01,
  LSBMask_CLASS1_EVENTS = 0x02,
  LSBMask_CLASS2_EVENTS = 0x04,
  LSBMask_CLASS3_EVENTS = 0x08,
  LSBMask_NEED_TIME = 0x10,
  LSBMask_LOCAL_CONTROL = 0x20,
  LSBMask_DEVICE_TROUBLE = 0x40,
  LSBMask_DEVICE_RESTART = 0x80,
};

////    enum class MSBMask : uint8_t
#define MSBMask_uint8_t uint8_t
enum MSBMask
{
  MSBMask_FUNC_NOT_SUPPORTED = 0x01,
  MSBMask_OBJECT_UNKNOWN = 0x02,
  MSBMask_PARAM_ERROR = 0x04,
  MSBMask_EVENT_BUFFER_OVERFLOW = 0x08,
  MSBMask_ALREADY_EXECUTING = 0x10,
  MSBMask_CONFIG_CORRUPT = 0x20,
  MSBMask_RESERVED1 = 0x40,
  MSBMask_RESERVED2 = 0x80,

  // special mask that indicates if there was any error processing a request
  MSBMask_REQUEST_ERROR_MASK = MSBMask_FUNC_NOT_SUPPORTED | MSBMask_OBJECT_UNKNOWN | MSBMask_PARAM_ERROR
};

////class IINField
typedef struct
{

////private:

////public:
////    static IINField Empty()
////    {
////        return IINField(0, 0);
////    }

////    IINField(IINBit bit) : LSB(0), MSB(0)
////    {
////        this->SetBit(bit);
////    }

////    IINField(uint8_t aLSB, uint8_t aMSB) : LSB(aLSB), MSB(aMSB) {}

////    IINField() : LSB(0), MSB(0) {}

////    bool IsSet(IINBit bit) const;

////    bool IsClear(IINBit bit) const
////    {
////        return !IsSet(bit);
////    }

////    void SetBit(IINBit bit);
////    void ClearBit(IINBit bit);

////    void SetBitToValue(IINBit bit, bool value);

////    bool operator==(const IINField& aRHS) const;

////    bool Any() const
////    {
////        return (LSB | MSB) != 0;
////    }

////    void Clear()
////    {
////        LSB = MSB = 0;
////    }

////    bool HasRequestError() const
////    {
////        return Get(MSBMask::REQUEST_ERROR_MASK);
////    }

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

  uint8_t LSB;
  uint8_t MSB;

////private:
////    static const uint8_t REQUEST_ERROR_MASK;

////    inline bool Get(LSBMask bit) const
////    {
////        return (LSB & static_cast<uint8_t>(bit)) != 0;
////    }

////    inline bool Get(MSBMask bit) const
////    {
////        return (MSB & static_cast<uint8_t>(bit)) != 0;
////    }

////    inline void Set(LSBMask bit)
////    {
////        LSB |= static_cast<uint8_t>(bit);
////    }
////    inline void Set(MSBMask bit)
////    {
////        MSB |= static_cast<uint8_t>(bit);
////    }

////    inline void Clear(LSBMask bit)
////    {
////        LSB &= ~static_cast<uint8_t>(bit);
////    }
////    inline void Clear(MSBMask bit)
////    {
////        MSB &= ~static_cast<uint8_t>(bit);
////    }
} IINField;

IINField Empty_in_IINField_static(void);
void IINField_in_IINFieldOver1(IINField *pIINField);
void IINField_in_IINFieldOver2(IINField *pIINField, IINBit_uint8_t bit);
void IINField_in_IINFieldOver3(IINField *pIINField, uint8_t aLSB, uint8_t aMSB);
boolean HasRequestError_in_IINField(IINField *pIINField);
void Clear_in_IINField(IINField *pIINField);
boolean Any_in_IINField(IINField *pIINField);
boolean IsClear_in_IINField(IINField *pIINField, IINBit_uint8_t bit);
boolean Get_in_IINField_MSB(IINField *pIINField, MSBMask_uint8_t bit);
boolean Get_in_IINField_LSB(IINField *pIINField, LSBMask_uint8_t bit);
void Clear_in_IINField_LSB(IINField *pIINField, LSBMask_uint8_t bit);
void Clear_in_IINField_MSB(IINField *pIINField, MSBMask_uint8_t bit);
void Set_in_IINField_LSB(IINField *pIINField, LSBMask_uint8_t bit);
void Set_in_IINField_MSB(IINField *pIINField, MSBMask_uint8_t bit);

void ClearBit_in_IINField(IINField *, IINBit_uint8_t bit);
void SetBit_in_IINField(IINField *, IINBit_uint8_t bit);
void SetBitToValue_in_IINField(IINField *, IINBit_uint8_t bit, boolean value);
boolean IsSet_in_IINField(IINField *, IINBit_uint8_t bit);


////    IINField& operator|=(const IINField& aIIN)
IINField operatorOREQ_in_IINField(IINField *pIINField, IINField* aIIN);
IINField operatorOR_in_IINField(IINField *pIINField, IINField* aIIN);

////} // namespace opendnp3

#endif
