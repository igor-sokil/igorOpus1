
#ifndef OPENDNP3_ICOLLECTION_for_Group51Var2_H
#define OPENDNP3_ICOLLECTION_for_Group51Var2_H

//#include "Indexed.h"
#include "Group51.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_for_Group51Var2--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Group51Var2)(void*, Group51Var2* value);// = 0;

  void* pParentPointer_in_IVisitor__for__Group51Var2;
} IVisitor__for__Group51Var2;

void* getParentPointer_in_IVisitor_for_Group51Var2(IVisitor__for__Group51Var2*);
void  setParentPointer_in_IVisitor_for_Group51Var2(IVisitor__for__Group51Var2*, void*);

void OnValue_in_IVisitor__for__Group51Var2(IVisitor__for__Group51Var2 *, Group51Var2* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  Group51Var2 *pValue_in_ICollection_for_Group51Var2;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_Group51Var2)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_Group51Var2)(void*, IVisitor__for__Group51Var2* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_for_Group51Var2(uint16_t* value) const
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
  void* pParentPointer_in_ICollection_for_Group51Var2;
} ICollection_for_Group51Var2;

void* getParentPointer_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2*);
void  setParentPointer_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2*, void*);
uint16_t Count_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2*);
void     Foreach_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2*, IVisitor__for__Group51Var2* visitor);

boolean ReadOnlyValue_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2 *pICollection_for_Group51Var2, Group51Var2* value);

void ForeachItem_in_ICollection_for_Group51Var2(ICollection_for_Group51Var2 *pICollection_for_Group51Var2, void (*fun)(Group51Var2* item));

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
  IVisitor__for__Group51Var2 iIVisitor__for__Group51Var2;

////private:
  void (*Fun)(Group51Var2* item);

} FunctorVisitor__for__Group51Var2;

void FunctorVisitor__for__Group51Var2_in_FunctorVisitor__for__Group51Var2(FunctorVisitor__for__Group51Var2 *pFunctorVisitor__for__Group51Var2,
    void (*fun)(Group51Var2* item));
void OnValue_in_FunctorVisitor__for__Group51Var2_override(void *pFunctorVisitor__for__Group51Var2, Group51Var2 *value);
//--------------------------------ICollection_for_Group51Var2--------------------------------

////} // namespace opendnp3
#endif
