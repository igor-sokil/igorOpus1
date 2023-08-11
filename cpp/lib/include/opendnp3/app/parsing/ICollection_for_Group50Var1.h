
#ifndef OPENDNP3_ICOLLECTION_for_Group50Var1_H
#define OPENDNP3_ICOLLECTION_for_Group50Var1_H

//#include "Indexed.h"
#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_for_Group50Var1--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Group50Var1)(void*, Group50Var1* value);// = 0;

  void* pParentPointer_in_IVisitor__for__Group50Var1;
} IVisitor__for__Group50Var1;

void* getParentPointer_in_IVisitor_for_Group50Var1(IVisitor__for__Group50Var1*);
void  setParentPointer_in_IVisitor_for_Group50Var1(IVisitor__for__Group50Var1*, void*);

void OnValue_in_IVisitor__for__Group50Var1(IVisitor__for__Group50Var1 *, Group50Var1* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  Group50Var1 *pValue_in_ICollection_for_Group50Var1;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_Group50Var1)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_Group50Var1)(void*, IVisitor__for__Group50Var1* visitor);// const = 0;

  /**
      visit all of the elements of a collection
  */
//    template<class Fun> void ForeachItem(const Fun& fun) const
//    {
//        FunctorVisitor<T, Fun> visitor(fun);
//        this->Foreach(visitor);
//    }

  /**
      Retrieve the only value from the collection.
  */
////    boolean ReadOnlyValue_in_ICollection_for_Group50Var1(uint16_t* value) const
////    {
////        if (this->Count() == 1)
////        {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
  void* pParentPointer_in_ICollection_for_Group50Var1;
} ICollection_for_Group50Var1;

void* getParentPointer_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1*);
void  setParentPointer_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1*, void*);
uint16_t Count_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1*);
void     Foreach_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1*, IVisitor__for__Group50Var1* visitor);

boolean ReadOnlyValue_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, Group50Var1* value);

void ForeachItem_in_ICollection_for_Group50Var1(ICollection_for_Group50Var1 *pICollection_for_Group50Var1, void (*fun)(Group50Var1* item));

/**
 * A visitor implemented as an abstract functor
 *
 */
////template<class T, class Fun> class FunctorVisitor : public IVisitor<T>
////{

////public:
////    FunctorVisitor(const Fun& fun_) : fun(fun_) {}

////    virtual void OnValue(const T& value) override final
////    {
////        fun(value);
////    }

////private:
////    Fun fun;
////};
typedef struct
{
////public:
  IVisitor__for__Group50Var1 iIVisitor__for__Group50Var1;

////private:
  void (*Fun)(Group50Var1* item);

} FunctorVisitor__for__Group50Var1;

void FunctorVisitor__for__Group50Var1_in_FunctorVisitor__for__Group50Var1(FunctorVisitor__for__Group50Var1 *pFunctorVisitor__for__Group50Var1,
    void (*fun)(Group50Var1* item));
void OnValue_in_FunctorVisitor__for__Group50Var1_override(void *pFunctorVisitor__for__Group50Var1, Group50Var1 *value);
//--------------------------------ICollection_for_Group50Var1--------------------------------

////} // namespace opendnp3
#endif
