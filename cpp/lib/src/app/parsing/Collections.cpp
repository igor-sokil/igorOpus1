
#include "header.h"
#include "Collections.h"

static void* pPointerGlobal1_in_TransformedCollection;
static void* pPointerGlobal2_in_TransformedCollection;

//------------------------------Group50Var1_for_DNPTime-----------------------------------
void TransformedCollection_Group50Var1_for_DNPTime_in_TransformedCollection_Group50Var1_for_DNPTime(TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime,
    ICollection_for_Group50Var1* input, Transform_Group50Var1_for_DNPTime transform)
{
////  TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}
  pTransformedCollection_Group50Var1_for_DNPTime->input = input;
  pTransformedCollection_Group50Var1_for_DNPTime->transform = transform;

  pTransformedCollection_Group50Var1_for_DNPTime->iICollection_for_DNPTime.pCount_in_ICollection_for_DNPTime = Count_in_TransformedCollection_Group50Var1_for_DNPTime_override;
  pTransformedCollection_Group50Var1_for_DNPTime->iICollection_for_DNPTime.pForeach_in_ICollection_for_DNPTime = Foreach_in_TransformedCollection_Group50Var1_for_DNPTime_override;
  setParentPointer_in_ICollection_for_DNPTime(&(pTransformedCollection_Group50Var1_for_DNPTime->iICollection_for_DNPTime), pTransformedCollection_Group50Var1_for_DNPTime);
}

////template<class T, class U, class Transform>
////TransformedCollection<T, U, Transform> Map(const ICollection<T>& input, Transform transform)
TransformedCollection_Group50Var1_for_DNPTime Map_in_TransformedCollection_Group50Var1_for_DNPTime(ICollection_for_Group50Var1* input, Transform_Group50Var1_for_DNPTime transform)
{
////  return TransformedCollection<T, U, Transform>(input, transform);
  TransformedCollection_Group50Var1_for_DNPTime tTransformedCollection_Group50Var1_for_DNPTime;
  TransformedCollection_Group50Var1_for_DNPTime_in_TransformedCollection_Group50Var1_for_DNPTime(&tTransformedCollection_Group50Var1_for_DNPTime,
      input, transform);
  return tTransformedCollection_Group50Var1_for_DNPTime;
}

uint16_t Count_in_TransformedCollection_Group50Var1_for_DNPTime(TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime)
{
//uint16_t Count_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1*);
////  return input->Count();
  return Count_in_ICollection_for_Group50Var1(pTransformedCollection_Group50Var1_for_DNPTime->input);
}

void fun_in_TransformedCollection_Group50Var1_for_DNPTime(Group50Var1* elem);
void fun_in_TransformedCollection_Group50Var1_for_DNPTime(Group50Var1* elem)
{
  TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime = (TransformedCollection_Group50Var1_for_DNPTime *)pPointerGlobal1_in_TransformedCollection;
  IVisitor__for__DNPTime* visitor = (IVisitor__for__DNPTime*)pPointerGlobal2_in_TransformedCollection;
//void OnValue_in_IVisitor__for__DNPTime(IVisitor__for__DNPTime *, DNPTime* );
////      visitor.OnValue(transform(elem));
  DNPTime dDNPTime = (pTransformedCollection_Group50Var1_for_DNPTime->transform)(elem);
  OnValue_in_IVisitor__for__DNPTime(visitor, &dDNPTime);
}
////  virtual void Foreach(IVisitor<U>& visitor) const override final
void Foreach_in_TransformedCollection_Group50Var1_for_DNPTime(TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime, IVisitor__for__DNPTime* visitor)
{
////    auto process = [this, &visitor](const T& elem) {
////      visitor.OnValue(transform(elem));
////    };
//void ForeachItem_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, void (*fun)(Group50Var1* item));
////    input->ForeachItem(process);
  pPointerGlobal1_in_TransformedCollection = pTransformedCollection_Group50Var1_for_DNPTime;
  pPointerGlobal2_in_TransformedCollection = visitor;
  ForeachItem_in_ICollection_for_Group50Var1(pTransformedCollection_Group50Var1_for_DNPTime->input, fun_in_TransformedCollection_Group50Var1_for_DNPTime);
}

uint16_t Count_in_TransformedCollection_Group50Var1_for_DNPTime_override(void* pICollection_for_DNPTime)
{
  TransformedCollection_Group50Var1_for_DNPTime *parent = (TransformedCollection_Group50Var1_for_DNPTime*) getParentPointer_in_ICollection_for_DNPTime((ICollection_for_DNPTime*)pICollection_for_DNPTime);
  return Count_in_TransformedCollection_Group50Var1_for_DNPTime(parent);
}
void Foreach_in_TransformedCollection_Group50Var1_for_DNPTime_override(void* pICollection_for_DNPTime, IVisitor__for__DNPTime* visitor)
{
  TransformedCollection_Group50Var1_for_DNPTime *parent = (TransformedCollection_Group50Var1_for_DNPTime*) getParentPointer_in_ICollection_for_DNPTime((ICollection_for_DNPTime*)pICollection_for_DNPTime);
  Foreach_in_TransformedCollection_Group50Var1_for_DNPTime(parent, visitor);
}
//------------------------------Group50Var1_for_DNPTime-----------------------------------
//------------------------------Indexed_for_Binary-----------------------------------
void TransformedCollection_Indexed_for_Binary_in_TransformedCollection_Indexed_for_Binary(TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary,
    ICollection_Indexed_for_Binary* input, Transform_Indexed_for_Binary transform)
{
////  TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}
  pTransformedCollection_Indexed_for_Binary->input = input;
  pTransformedCollection_Indexed_for_Binary->transform = transform;

  pTransformedCollection_Indexed_for_Binary->iICollection_Indexed_for_Binary.pCount_in_ICollection_Indexed_for_Binary = Count_in_TransformedCollection_Indexed_for_Binary_override;
  pTransformedCollection_Indexed_for_Binary->iICollection_Indexed_for_Binary.pForeach_in_ICollection_Indexed_for_Binary = Foreach_in_TransformedCollection_Indexed_for_Binary_override;
  setParentPointer_in_ICollection_Indexed_for_Binary(&(pTransformedCollection_Indexed_for_Binary->iICollection_Indexed_for_Binary), pTransformedCollection_Indexed_for_Binary);
}

////template<class T, class U, class Transform>
////TransformedCollection<T, U, Transform> Map(const ICollection<T>& input, Transform transform)
TransformedCollection_Indexed_for_Binary Map_in_TransformedCollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* input, Transform_Indexed_for_Binary transform)
{
////  return TransformedCollection<T, U, Transform>(input, transform);
  TransformedCollection_Indexed_for_Binary tTransformedCollection_Indexed_for_Binary;
  TransformedCollection_Indexed_for_Binary_in_TransformedCollection_Indexed_for_Binary(&tTransformedCollection_Indexed_for_Binary,
      input, transform);
  return tTransformedCollection_Indexed_for_Binary;
}

uint16_t Count_in_TransformedCollection_Indexed_for_Binary(TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary)
{
////  return input->Count();
  return Count_in_ICollection_Indexed_for_Binary(pTransformedCollection_Indexed_for_Binary->input);
}

//static void* pPointerGlobal1_in_TransformedCollection;
//static void* pPointerGlobal2_in_TransformedCollection;

void fun_in_TransformedCollection_Indexed_for_Binary(Indexed_for_Binary* elem);
void fun_in_TransformedCollection_Indexed_for_Binary(Indexed_for_Binary* elem)
{
  TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary = (TransformedCollection_Indexed_for_Binary *)pPointerGlobal1_in_TransformedCollection;
  IVisitor__for__Indexed_for_Binary* visitor = (IVisitor__for__Indexed_for_Binary*)pPointerGlobal2_in_TransformedCollection;
////      visitor.OnValue(transform(elem));
  Indexed_for_Binary iIndexed_for_Binary = (pTransformedCollection_Indexed_for_Binary->transform)(elem);
  OnValue_in_IVisitor__for__Indexed_for_Binary(visitor, &iIndexed_for_Binary);
}
////  virtual void Foreach(IVisitor<U>& visitor) const override final
void Foreach_in_TransformedCollection_Indexed_for_Binary(TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary, IVisitor__for__Indexed_for_Binary* visitor)
{
////    auto process = [this, &visitor](const T& elem) {
////      visitor.OnValue(transform(elem));
////    };
////    input->ForeachItem(process);
  pPointerGlobal1_in_TransformedCollection = pTransformedCollection_Indexed_for_Binary;
  pPointerGlobal2_in_TransformedCollection = visitor;
  ForeachItem_in_ICollection_Indexed_for_Binary(pTransformedCollection_Indexed_for_Binary->input, fun_in_TransformedCollection_Indexed_for_Binary);
}

uint16_t Count_in_TransformedCollection_Indexed_for_Binary_override(void* pICollection_Indexed_for_Binary)
{
  TransformedCollection_Indexed_for_Binary *parent = (TransformedCollection_Indexed_for_Binary*) getParentPointer_in_ICollection_Indexed_for_Binary((ICollection_Indexed_for_Binary*)pICollection_Indexed_for_Binary);
  return Count_in_TransformedCollection_Indexed_for_Binary(parent);
}
void Foreach_in_TransformedCollection_Indexed_for_Binary_override(void* pICollection_Indexed_for_Binary, IVisitor__for__Indexed_for_Binary* visitor)
{
  TransformedCollection_Indexed_for_Binary *parent = (TransformedCollection_Indexed_for_Binary*) getParentPointer_in_ICollection_Indexed_for_Binary((ICollection_Indexed_for_Binary*)pICollection_Indexed_for_Binary);
  Foreach_in_TransformedCollection_Indexed_for_Binary(parent, visitor);
}
//------------------------------Indexed_for_Binary-----------------------------------
//------------------------------Indexed_for_DoubleBitBinary-----------------------------------
void TransformedCollection_Indexed_for_DoubleBitBinary_in_TransformedCollection_Indexed_for_DoubleBitBinary(TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary,
    ICollection_Indexed_for_DoubleBitBinary* input, Transform_Indexed_for_DoubleBitBinary transform)
{
////  TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}
  pTransformedCollection_Indexed_for_DoubleBitBinary->input = input;
  pTransformedCollection_Indexed_for_DoubleBitBinary->transform = transform;

  pTransformedCollection_Indexed_for_DoubleBitBinary->iICollection_Indexed_for_DoubleBitBinary.pCount_in_ICollection_Indexed_for_DoubleBitBinary = Count_in_TransformedCollection_Indexed_for_DoubleBitBinary_override;
  pTransformedCollection_Indexed_for_DoubleBitBinary->iICollection_Indexed_for_DoubleBitBinary.pForeach_in_ICollection_Indexed_for_DoubleBitBinary = Foreach_in_TransformedCollection_Indexed_for_DoubleBitBinary_override;
  setParentPointer_in_ICollection_Indexed_for_DoubleBitBinary(&(pTransformedCollection_Indexed_for_DoubleBitBinary->iICollection_Indexed_for_DoubleBitBinary), pTransformedCollection_Indexed_for_DoubleBitBinary);
}

////template<class T, class U, class Transform>
////TransformedCollection<T, U, Transform> Map(const ICollection<T>& input, Transform transform)
TransformedCollection_Indexed_for_DoubleBitBinary Map_in_TransformedCollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* input, Transform_Indexed_for_DoubleBitBinary transform)
{
////  return TransformedCollection<T, U, Transform>(input, transform);
  TransformedCollection_Indexed_for_DoubleBitBinary tTransformedCollection_Indexed_for_DoubleBitBinary;
  TransformedCollection_Indexed_for_DoubleBitBinary_in_TransformedCollection_Indexed_for_DoubleBitBinary(&tTransformedCollection_Indexed_for_DoubleBitBinary,
      input, transform);
  return tTransformedCollection_Indexed_for_DoubleBitBinary;
}

uint16_t Count_in_TransformedCollection_Indexed_for_DoubleBitBinary(TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary)
{
////  return input->Count();
  return Count_in_ICollection_Indexed_for_DoubleBitBinary(pTransformedCollection_Indexed_for_DoubleBitBinary->input);
}

//static void* pPointerGlobal1_in_TransformedCollection;
//static void* pPointerGlobal2_in_TransformedCollection;

void fun_in_TransformedCollection_Indexed_for_DoubleBitBinary(Indexed_for_DoubleBitBinary* elem);
void fun_in_TransformedCollection_Indexed_for_DoubleBitBinary(Indexed_for_DoubleBitBinary* elem)
{
  TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary = (TransformedCollection_Indexed_for_DoubleBitBinary *)pPointerGlobal1_in_TransformedCollection;
  IVisitor__for__Indexed_for_DoubleBitBinary* visitor = (IVisitor__for__Indexed_for_DoubleBitBinary*)pPointerGlobal2_in_TransformedCollection;
////      visitor.OnValue(transform(elem));
  Indexed_for_DoubleBitBinary iIndexed_for_DoubleBitBinary = (pTransformedCollection_Indexed_for_DoubleBitBinary->transform)(elem);
  OnValue_in_IVisitor__for__Indexed_for_DoubleBitBinary(visitor, &iIndexed_for_DoubleBitBinary);
}
////  virtual void Foreach(IVisitor<U>& visitor) const override final
void Foreach_in_TransformedCollection_Indexed_for_DoubleBitBinary(TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary, IVisitor__for__Indexed_for_DoubleBitBinary* visitor)
{
////    auto process = [this, &visitor](const T& elem) {
////      visitor.OnValue(transform(elem));
////    };
////    input->ForeachItem(process);
  pPointerGlobal1_in_TransformedCollection = pTransformedCollection_Indexed_for_DoubleBitBinary;
  pPointerGlobal2_in_TransformedCollection = visitor;
  ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(pTransformedCollection_Indexed_for_DoubleBitBinary->input, fun_in_TransformedCollection_Indexed_for_DoubleBitBinary);
}

uint16_t Count_in_TransformedCollection_Indexed_for_DoubleBitBinary_override(void* pICollection_Indexed_for_DoubleBitBinary)
{
  TransformedCollection_Indexed_for_DoubleBitBinary *parent = (TransformedCollection_Indexed_for_DoubleBitBinary*) getParentPointer_in_ICollection_Indexed_for_DoubleBitBinary((ICollection_Indexed_for_DoubleBitBinary*)pICollection_Indexed_for_DoubleBitBinary);
  return Count_in_TransformedCollection_Indexed_for_DoubleBitBinary(parent);
}
void Foreach_in_TransformedCollection_Indexed_for_DoubleBitBinary_override(void* pICollection_Indexed_for_DoubleBitBinary, IVisitor__for__Indexed_for_DoubleBitBinary* visitor)
{
  TransformedCollection_Indexed_for_DoubleBitBinary *parent = (TransformedCollection_Indexed_for_DoubleBitBinary*) getParentPointer_in_ICollection_Indexed_for_DoubleBitBinary((ICollection_Indexed_for_DoubleBitBinary*)pICollection_Indexed_for_DoubleBitBinary);
  Foreach_in_TransformedCollection_Indexed_for_DoubleBitBinary(parent, visitor);
}
//------------------------------Indexed_for_DoubleBitBinary-----------------------------------
