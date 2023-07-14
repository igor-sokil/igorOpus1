#include "header.h"
#include "ICollection.h"
//--------------------------------ICollection_for_uint16--------------------------------

void FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(FunctorVisitor_for_uint16 *pFunctorVisitor_for_uint16,
    ICollection_for_uint16 *pICollection_for_uint16,
    void (*fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item))
{
  pFunctorVisitor_for_uint16->Fun = fun;
  pFunctorVisitor_for_uint16->pICollection_for_uint16 = pICollection_for_uint16;
  (pFunctorVisitor_for_uint16->iIVisitor_for_uint16).pOnValue_in_IVisitor_for_uint16 = OnValue_in_FunctorVisitor_for_uint16;
}

void OnValue_in_FunctorVisitor_for_uint16(void *pFunctorVisitor_for_uint16, uint16_t *value)
{
  ((FunctorVisitor_for_uint16*)pFunctorVisitor_for_uint16)->Fun(((FunctorVisitor_for_uint16*)pFunctorVisitor_for_uint16)->pICollection_for_uint16,
      value);
}

void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item))
{
  FunctorVisitor_for_uint16 visitor;
  FunctorVisitor_for_uint16_in_FunctorVisitor_for_uint16(&visitor, pICollection_for_uint16, fun);
  (pICollection_for_uint16->pForeach_in_ICollection_for_uint16)(pICollection_for_uint16, &(visitor.iIVisitor_for_uint16));
}

void assignValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item);

void assignValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* item)
{
  *(pICollection_for_uint16->pValue_in_ICollection_for_uint16) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, uint16_t* pValue)
{
  pICollection_for_uint16->pValue_in_ICollection_for_uint16 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_for_uint16->pCount_in_ICollection_for_uint16)(pICollection_for_uint16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_for_uint16(pICollection_for_uint16, assignValue_in_ICollection_for_uint16);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_for_uint16--------------------------------
//--------------------------------ICollection_Indexed_for_IINValue--------------------------------

void FunctorVisitor__for__Indexed_for_IINValue_in_FunctorVisitor__for__Indexed_for_IINValue(FunctorVisitor__for__Indexed_for_IINValue *pFunctorVisitor__for__Indexed_for_IINValue,
    ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue,
    void (*fun)(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item))
{
  pFunctorVisitor__for__Indexed_for_IINValue->Fun = fun;
  pFunctorVisitor__for__Indexed_for_IINValue->pICollection_Indexed_for_IINValue = pICollection_Indexed_for_IINValue;
  (pFunctorVisitor__for__Indexed_for_IINValue->iIVisitor__for__Indexed_for_IINValue).pOnValue_in_IVisitor__for__Indexed_for_IINValue = OnValue_in_FunctorVisitor__for__Indexed_for_IINValue;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_IINValue(void *pFunctorVisitor__for__Indexed_for_IINValue, Indexed_for_IINValue *value)
{
  ((FunctorVisitor__for__Indexed_for_IINValue*)pFunctorVisitor__for__Indexed_for_IINValue)->Fun(((FunctorVisitor__for__Indexed_for_IINValue*)pFunctorVisitor__for__Indexed_for_IINValue)->pICollection_Indexed_for_IINValue,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, void (*fun)(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item))
{
  FunctorVisitor__for__Indexed_for_IINValue visitor;
  FunctorVisitor__for__Indexed_for_IINValue_in_FunctorVisitor__for__Indexed_for_IINValue(&visitor, pICollection_Indexed_for_IINValue, fun);
  (pICollection_Indexed_for_IINValue->pForeach_in_ICollection_Indexed_for_IINValue)(pICollection_Indexed_for_IINValue, &(visitor.iIVisitor__for__Indexed_for_IINValue));
}

void assignValue_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item);

void assignValue_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* item)
{
  *(pICollection_Indexed_for_IINValue->pValue_in_ICollection_Indexed_for_IINValue) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* pValue)
{
  pICollection_Indexed_for_IINValue->pValue_in_ICollection_Indexed_for_IINValue = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_IINValue->pCount_in_ICollection_Indexed_for_IINValue)(pICollection_Indexed_for_IINValue) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_IINValue(pICollection_Indexed_for_IINValue, assignValue_in_ICollection_Indexed_for_IINValue);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_IINValue--------------------------------
//--------------------------------ICollection_Indexed_for_TimeAndInterval--------------------------------

void FunctorVisitor__for__Indexed_for_TimeAndInterval_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(FunctorVisitor__for__Indexed_for_TimeAndInterval *pFunctorVisitor__for__Indexed_for_TimeAndInterval,
    ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval,
    void (*fun)(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* item))
{
  pFunctorVisitor__for__Indexed_for_TimeAndInterval->Fun = fun;
  pFunctorVisitor__for__Indexed_for_TimeAndInterval->pICollection_Indexed_for_TimeAndInterval = pICollection_Indexed_for_TimeAndInterval;
  (pFunctorVisitor__for__Indexed_for_TimeAndInterval->iIVisitor__for__Indexed_for_TimeAndInterval).pOnValue_in_IVisitor__for__Indexed_for_TimeAndInterval = OnValue_in_FunctorVisitor__for__Indexed_for_TimeAndInterval;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(void *pFunctorVisitor__for__Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval *value)
{
  ((FunctorVisitor__for__Indexed_for_TimeAndInterval*)pFunctorVisitor__for__Indexed_for_TimeAndInterval)->Fun(((FunctorVisitor__for__Indexed_for_TimeAndInterval*)pFunctorVisitor__for__Indexed_for_TimeAndInterval)->pICollection_Indexed_for_TimeAndInterval,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, void (*fun)(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* item))
{
  FunctorVisitor__for__Indexed_for_TimeAndInterval visitor;
  FunctorVisitor__for__Indexed_for_TimeAndInterval_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(&visitor, pICollection_Indexed_for_TimeAndInterval, fun);
  (pICollection_Indexed_for_TimeAndInterval->pForeach_in_ICollection_Indexed_for_TimeAndInterval)(pICollection_Indexed_for_TimeAndInterval, &(visitor.iIVisitor__for__Indexed_for_TimeAndInterval));
}

void assignValue_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* item);

void assignValue_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* item)
{
  *(pICollection_Indexed_for_TimeAndInterval->pValue_in_ICollection_Indexed_for_TimeAndInterval) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_TimeAndInterval(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* pValue)
{
  pICollection_Indexed_for_TimeAndInterval->pValue_in_ICollection_Indexed_for_TimeAndInterval = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_TimeAndInterval->pCount_in_ICollection_Indexed_for_TimeAndInterval)(pICollection_Indexed_for_TimeAndInterval) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval, assignValue_in_ICollection_Indexed_for_TimeAndInterval);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_TimeAndInterval--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------

void FunctorVisitor__for__Indexed_for_AnalogOutputInt16_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(FunctorVisitor__for__Indexed_for_AnalogOutputInt16 *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16,
    ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
    void (*fun)(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputInt16->Fun = fun;
  pFunctorVisitor__for__Indexed_for_AnalogOutputInt16->pICollection_Indexed_for_AnalogOutputInt16 = pICollection_Indexed_for_AnalogOutputInt16;
  (pFunctorVisitor__for__Indexed_for_AnalogOutputInt16->iIVisitor__for__Indexed_for_AnalogOutputInt16).pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt16 = OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(void *pFunctorVisitor__for__Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputInt16*)pFunctorVisitor__for__Indexed_for_AnalogOutputInt16)->Fun(((FunctorVisitor__for__Indexed_for_AnalogOutputInt16*)pFunctorVisitor__for__Indexed_for_AnalogOutputInt16)->pICollection_Indexed_for_AnalogOutputInt16,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, void (*fun)(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputInt16 visitor;
  FunctorVisitor__for__Indexed_for_AnalogOutputInt16_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt16(&visitor, pICollection_Indexed_for_AnalogOutputInt16, fun);
  (pICollection_Indexed_for_AnalogOutputInt16->pForeach_in_ICollection_Indexed_for_AnalogOutputInt16)(pICollection_Indexed_for_AnalogOutputInt16, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputInt16));
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* item)
{
  *(pICollection_Indexed_for_AnalogOutputInt16->pValue_in_ICollection_Indexed_for_AnalogOutputInt16) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt16(ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16, Indexed_for_AnalogOutputInt16* pValue)
{
  pICollection_Indexed_for_AnalogOutputInt16->pValue_in_ICollection_Indexed_for_AnalogOutputInt16 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_AnalogOutputInt16->pCount_in_ICollection_Indexed_for_AnalogOutputInt16)(pICollection_Indexed_for_AnalogOutputInt16) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(pICollection_Indexed_for_AnalogOutputInt16, assignValue_in_ICollection_Indexed_for_AnalogOutputInt16);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_AnalogOutputInt16--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputInt32--------------------------------

void FunctorVisitor__for__Indexed_for_AnalogOutputInt32_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt32(FunctorVisitor__for__Indexed_for_AnalogOutputInt32 *pFunctorVisitor__for__Indexed_for_AnalogOutputInt32,
    ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32,
    void (*fun)(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputInt32->Fun = fun;
  pFunctorVisitor__for__Indexed_for_AnalogOutputInt32->pICollection_Indexed_for_AnalogOutputInt32 = pICollection_Indexed_for_AnalogOutputInt32;
  (pFunctorVisitor__for__Indexed_for_AnalogOutputInt32->iIVisitor__for__Indexed_for_AnalogOutputInt32).pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputInt32 = OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt32;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt32(void *pFunctorVisitor__for__Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputInt32*)pFunctorVisitor__for__Indexed_for_AnalogOutputInt32)->Fun(((FunctorVisitor__for__Indexed_for_AnalogOutputInt32*)pFunctorVisitor__for__Indexed_for_AnalogOutputInt32)->pICollection_Indexed_for_AnalogOutputInt32,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt32(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, void (*fun)(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputInt32 visitor;
  FunctorVisitor__for__Indexed_for_AnalogOutputInt32_in_FunctorVisitor__for__Indexed_for_AnalogOutputInt32(&visitor, pICollection_Indexed_for_AnalogOutputInt32, fun);
  (pICollection_Indexed_for_AnalogOutputInt32->pForeach_in_ICollection_Indexed_for_AnalogOutputInt32)(pICollection_Indexed_for_AnalogOutputInt32, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputInt32));
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputInt32(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputInt32(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* item)
{
  *(pICollection_Indexed_for_AnalogOutputInt32->pValue_in_ICollection_Indexed_for_AnalogOutputInt32) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputInt32(ICollection_Indexed_for_AnalogOutputInt32 *pICollection_Indexed_for_AnalogOutputInt32, Indexed_for_AnalogOutputInt32* pValue)
{
  pICollection_Indexed_for_AnalogOutputInt32->pValue_in_ICollection_Indexed_for_AnalogOutputInt32 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_AnalogOutputInt32->pCount_in_ICollection_Indexed_for_AnalogOutputInt32)(pICollection_Indexed_for_AnalogOutputInt32) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt32(pICollection_Indexed_for_AnalogOutputInt32, assignValue_in_ICollection_Indexed_for_AnalogOutputInt32);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_AnalogOutputInt32--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputFloat32--------------------------------

void FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(FunctorVisitor__for__Indexed_for_AnalogOutputFloat32 *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32,
    ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32,
    void (*fun)(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32->Fun = fun;
  pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32->pICollection_Indexed_for_AnalogOutputFloat32 = pICollection_Indexed_for_AnalogOutputFloat32;
  (pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32->iIVisitor__for__Indexed_for_AnalogOutputFloat32).pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputFloat32 = OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(void *pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputFloat32*)pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32)->Fun(((FunctorVisitor__for__Indexed_for_AnalogOutputFloat32*)pFunctorVisitor__for__Indexed_for_AnalogOutputFloat32)->pICollection_Indexed_for_AnalogOutputFloat32,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, void (*fun)(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputFloat32 visitor;
  FunctorVisitor__for__Indexed_for_AnalogOutputFloat32_in_FunctorVisitor__for__Indexed_for_AnalogOutputFloat32(&visitor, pICollection_Indexed_for_AnalogOutputFloat32, fun);
  (pICollection_Indexed_for_AnalogOutputFloat32->pForeach_in_ICollection_Indexed_for_AnalogOutputFloat32)(pICollection_Indexed_for_AnalogOutputFloat32, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputFloat32));
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* item)
{
  *(pICollection_Indexed_for_AnalogOutputFloat32->pValue_in_ICollection_Indexed_for_AnalogOutputFloat32) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputFloat32(ICollection_Indexed_for_AnalogOutputFloat32 *pICollection_Indexed_for_AnalogOutputFloat32, Indexed_for_AnalogOutputFloat32* pValue)
{
  pICollection_Indexed_for_AnalogOutputFloat32->pValue_in_ICollection_Indexed_for_AnalogOutputFloat32 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_AnalogOutputFloat32->pCount_in_ICollection_Indexed_for_AnalogOutputFloat32)(pICollection_Indexed_for_AnalogOutputFloat32) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputFloat32(pICollection_Indexed_for_AnalogOutputFloat32, assignValue_in_ICollection_Indexed_for_AnalogOutputFloat32);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_AnalogOutputFloat32--------------------------------
//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------

void FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64,
    ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64,
    void (*fun)(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item))
{
  pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64->Fun = fun;
  pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64->pICollection_Indexed_for_AnalogOutputDouble64 = pICollection_Indexed_for_AnalogOutputDouble64;
  (pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64->iIVisitor__for__Indexed_for_AnalogOutputDouble64).pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64 = OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(void *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 *value)
{
  ((FunctorVisitor__for__Indexed_for_AnalogOutputDouble64*)pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64)->Fun(((FunctorVisitor__for__Indexed_for_AnalogOutputDouble64*)pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64)->pICollection_Indexed_for_AnalogOutputDouble64,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, void (*fun)(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item))
{
  FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 visitor;
  FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(&visitor, pICollection_Indexed_for_AnalogOutputDouble64, fun);
  (pICollection_Indexed_for_AnalogOutputDouble64->pForeach_in_ICollection_Indexed_for_AnalogOutputDouble64)(pICollection_Indexed_for_AnalogOutputDouble64, &(visitor.iIVisitor__for__Indexed_for_AnalogOutputDouble64));
}

void assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item);

void assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* item)
{
  *(pICollection_Indexed_for_AnalogOutputDouble64->pValue_in_ICollection_Indexed_for_AnalogOutputDouble64) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* pValue)
{
  pICollection_Indexed_for_AnalogOutputDouble64->pValue_in_ICollection_Indexed_for_AnalogOutputDouble64 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_AnalogOutputDouble64->pCount_in_ICollection_Indexed_for_AnalogOutputDouble64)(pICollection_Indexed_for_AnalogOutputDouble64) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(pICollection_Indexed_for_AnalogOutputDouble64, assignValue_in_ICollection_Indexed_for_AnalogOutputDouble64);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------

void FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock,
    ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock,
    void (*fun)(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item))
{
  pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock->Fun = fun;
  pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock->pICollection_Indexed_for_ControlRelayOutputBlock = pICollection_Indexed_for_ControlRelayOutputBlock;
  (pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock->iIVisitor__for__Indexed_for_ControlRelayOutputBlock).pOnValue_in_IVisitor__for__Indexed_for_ControlRelayOutputBlock = OnValue_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock;
}

void OnValue_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(void *pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock *value)
{
  ((FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock*)pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock)->Fun(((FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock*)pFunctorVisitor__for__Indexed_for_ControlRelayOutputBlock)->pICollection_Indexed_for_ControlRelayOutputBlock,
      value);
}

void ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, void (*fun)(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item))
{
  FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock visitor;
  FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock_in_FunctorVisitor__for__Indexed_for_ControlRelayOutputBlock(&visitor, pICollection_Indexed_for_ControlRelayOutputBlock, fun);
  (pICollection_Indexed_for_ControlRelayOutputBlock->pForeach_in_ICollection_Indexed_for_ControlRelayOutputBlock)(pICollection_Indexed_for_ControlRelayOutputBlock, &(visitor.iIVisitor__for__Indexed_for_ControlRelayOutputBlock));
}

void assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item);

void assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item)
{
  *(pICollection_Indexed_for_ControlRelayOutputBlock->pValue_in_ICollection_Indexed_for_ControlRelayOutputBlock) = *item;
}

boolean ReadOnlyValue_in_ICollection_Indexed_for_ControlRelayOutputBlock(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* pValue)
{
  pICollection_Indexed_for_ControlRelayOutputBlock->pValue_in_ICollection_Indexed_for_ControlRelayOutputBlock = pValue;
////        if (this->Count() == 1)
  if ((pICollection_Indexed_for_ControlRelayOutputBlock->pCount_in_ICollection_Indexed_for_ControlRelayOutputBlock)(pICollection_Indexed_for_ControlRelayOutputBlock) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(pICollection_Indexed_for_ControlRelayOutputBlock, assignValue_in_ICollection_Indexed_for_ControlRelayOutputBlock);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_Indexed_for_ControlRelayOutputBlock--------------------------------
//--------------------------------ICollection_for_Group50Var1--------------------------------

void FunctorVisitor_for_Group50Var1_in_FunctorVisitor_for_Group50Var1(FunctorVisitor_for_Group50Var1 *pFunctorVisitor_for_Group50Var1,
    ICollection_for_Group50Var1 *pICollection_for_Group50Var1,
    void (*fun)(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item))
{
  pFunctorVisitor_for_Group50Var1->Fun = fun;
  pFunctorVisitor_for_Group50Var1->pICollection_for_Group50Var1 = pICollection_for_Group50Var1;
  (pFunctorVisitor_for_Group50Var1->iIVisitor_for_Group50Var1).pOnValue_in_IVisitor_for_Group50Var1 = OnValue_in_FunctorVisitor_for_Group50Var1;
}

void OnValue_in_FunctorVisitor_for_Group50Var1(void *pFunctorVisitor_for_Group50Var1, Group50Var1 *value)
{
  ((FunctorVisitor_for_Group50Var1*)pFunctorVisitor_for_Group50Var1)->Fun(((FunctorVisitor_for_Group50Var1*)pFunctorVisitor_for_Group50Var1)->pICollection_for_Group50Var1,
      value);
}

void ForeachItem_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, void (*fun)(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item))
{
  FunctorVisitor_for_Group50Var1 visitor;
  FunctorVisitor_for_Group50Var1_in_FunctorVisitor_for_Group50Var1(&visitor, pICollection_for_Group50Var1, fun);
  (pICollection_for_Group50Var1->pForeach_in_ICollection_for_Group50Var1)(pICollection_for_Group50Var1, &(visitor.iIVisitor_for_Group50Var1));
}

void assignValue_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item);

void assignValue_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* item)
{
  *(pICollection_for_Group50Var1->pValue_in_ICollection_for_Group50Var1) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* pValue)
{
  pICollection_for_Group50Var1->pValue_in_ICollection_for_Group50Var1 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_for_Group50Var1->pCount_in_ICollection_for_Group50Var1)(pICollection_for_Group50Var1) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_for_Group50Var1(pICollection_for_Group50Var1, assignValue_in_ICollection_for_Group50Var1);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_for_Group50Var1--------------------------------
//--------------------------------ICollection_for_Group50Var3--------------------------------

void FunctorVisitor_for_Group50Var3_in_FunctorVisitor_for_Group50Var3(FunctorVisitor_for_Group50Var3 *pFunctorVisitor_for_Group50Var3,
    ICollection_for_Group50Var3 *pICollection_for_Group50Var3,
    void (*fun)(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, Group50Var3* item))
{
  pFunctorVisitor_for_Group50Var3->Fun = fun;
  pFunctorVisitor_for_Group50Var3->pICollection_for_Group50Var3 = pICollection_for_Group50Var3;
  (pFunctorVisitor_for_Group50Var3->iIVisitor_for_Group50Var3).pOnValue_in_IVisitor_for_Group50Var3 = OnValue_in_FunctorVisitor_for_Group50Var3;
}

void OnValue_in_FunctorVisitor_for_Group50Var3(void *pFunctorVisitor_for_Group50Var3, Group50Var3 *value)
{
  ((FunctorVisitor_for_Group50Var3*)pFunctorVisitor_for_Group50Var3)->Fun(((FunctorVisitor_for_Group50Var3*)pFunctorVisitor_for_Group50Var3)->pICollection_for_Group50Var3,
      value);
}

void ForeachItem_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, void (*fun)(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, Group50Var3* item))
{
  FunctorVisitor_for_Group50Var3 visitor;
  FunctorVisitor_for_Group50Var3_in_FunctorVisitor_for_Group50Var3(&visitor, pICollection_for_Group50Var3, fun);
  (pICollection_for_Group50Var3->pForeach_in_ICollection_for_Group50Var3)(pICollection_for_Group50Var3, &(visitor.iIVisitor_for_Group50Var3));
}

void assignValue_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, Group50Var3* item);

void assignValue_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, Group50Var3* item)
{
  *(pICollection_for_Group50Var3->pValue_in_ICollection_for_Group50Var3) = *item;
}

boolean ReadOnlyValue_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, Group50Var3* pValue)
{
  pICollection_for_Group50Var3->pValue_in_ICollection_for_Group50Var3 = pValue;
////        if (this->Count() == 1)
  if ((pICollection_for_Group50Var3->pCount_in_ICollection_for_Group50Var3)(pICollection_for_Group50Var3) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
    ForeachItem_in_ICollection_for_Group50Var3(pICollection_for_Group50Var3, assignValue_in_ICollection_for_Group50Var3);
    return true;
  }
  else
  {
    return false;
  }
}
//--------------------------------ICollection_for_Group50Var3--------------------------------
