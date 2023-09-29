#ifndef OPENDNP3___ICOLLECTION_H
#define OPENDNP3___ICOLLECTION_H

#include "Indexed.h"
#include "Group50.h"

//--------------------------------ICollection_Indexed_for_TimeAndInterval--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_TimeAndInterval)(void*, Indexed_for_TimeAndInterval* value);// = 0;

  void* pParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval;
} __IVisitor__for__Indexed_for_TimeAndInterval;

void* getParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval(__IVisitor__for__Indexed_for_TimeAndInterval*);
void  setParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval(__IVisitor__for__Indexed_for_TimeAndInterval*, void*);
/*
void* getParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval(__IVisitor__for__Indexed_for_TimeAndInterval* pIVisitor__for__Indexed_for_TimeAndInterval)
{
  return pIVisitor__for__Indexed_for_TimeAndInterval->pParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval;
}
void  setParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval(__IVisitor__for__Indexed_for_TimeAndInterval* pIVisitor__for__Indexed_for_TimeAndInterval, void* pParentPointer)
{
  pIVisitor__for__Indexed_for_TimeAndInterval->pParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval = pParentPointer;
}
*/

void OnValue_in_IVisitor__for__Indexed_for_TimeAndInterval(__IVisitor__for__Indexed_for_TimeAndInterval *, Indexed_for_TimeAndInterval* );
/*
void OnValue_in_IVisitor__for__Indexed_for_TimeAndInterval(__IVisitor__for__Indexed_for_TimeAndInterval *pIVisitor__for__Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* pIndexed_for_TimeAndInterval)
{
  (pIVisitor__for__Indexed_for_TimeAndInterval->pOnValue_in_IVisitor__for__Indexed_for_TimeAndInterval)(pIVisitor__for__Indexed_for_TimeAndInterval, pIndexed_for_TimeAndInterval);
}
*/

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  Indexed_for_TimeAndInterval *pValue_in_ICollection_Indexed_for_TimeAndInterval;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_TimeAndInterval)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_TimeAndInterval)(void*, __IVisitor__for__Indexed_for_TimeAndInterval* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_TimeAndInterval(uint16_t* value) const
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
  void* pParentPointer_in_ICollection_Indexed_for_TimeAndInterval;
} __ICollection_Indexed_for_TimeAndInterval;

void* getParentPointer_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval*);
void  setParentPointer_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval*, void*);
  uint16_t Count_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval*);
  void     Foreach_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval*, __IVisitor__for__Indexed_for_TimeAndInterval* visitor);
/*
  uint16_t Count_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval* pICollection_Indexed_for_TimeAndInterval)
{
 return (pICollection_Indexed_for_TimeAndInterval->pCount_in_ICollection_Indexed_for_TimeAndInterval)
        (pICollection_Indexed_for_TimeAndInterval);
}
  void     Foreach_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval* pICollection_Indexed_for_TimeAndInterval, __IVisitor__for__Indexed_for_TimeAndInterval* visitor)
{
  (pICollection_Indexed_for_TimeAndInterval->pForeach_in_ICollection_Indexed_for_TimeAndInterval)
        (pICollection_Indexed_for_TimeAndInterval, visitor);
}
*/

/*
void* getParentPointer_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval* pICollection_Indexed_for_TimeAndInterval)
{
  return pICollection_Indexed_for_TimeAndInterval->pParentPointer_in_ICollection_Indexed_for_TimeAndInterval;
}

void  setParentPointer_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval* pICollection_Indexed_for_TimeAndInterval, void* pParentPointer)
{
  pICollection_Indexed_for_TimeAndInterval->pParentPointer_in_ICollection_Indexed_for_TimeAndInterval = pParentPointer;
}
*/

boolean __ReadOnlyValue_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* value);
/*
void assignValue_in_ICollection_Indexed_for_TimeAndInterval(Indexed_for_TimeAndInterval* item);

void assignValue_in_ICollection_Indexed_for_TimeAndInterval(Indexed_for_TimeAndInterval* item)
{
    *((Indexed_for_TimeAndInterval*)pPointerGlobal1) = *item;
}

boolean __ReadOnlyValue_in_ICollection_Indexed_for_TimeAndInterval(
    __ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* pValue)
{
    pPointerGlobal1 = pValue;

////        if (this->Count() == 1)
  if (Count_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval) == 1)
  {
////            auto assignValue = [&value](const T& item) { value = item; };
////            this->ForeachItem(assignValue);
//void __ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, 
//                  void (*fun)(Indexed_for_TimeAndInterval* item));
    __ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval, assignValue_in_ICollection_Indexed_for_TimeAndInterval);
    return true;
  }
  else
  {
    return false;
  }
}
*/

void __ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, void (*fun)(Indexed_for_TimeAndInterval* item));
/*
void __ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(__ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, void (*fun)(ICollection_Indexed_for_TimeAndInterval *pICollection_Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval* item))
{
  __FunctorVisitor__for__Indexed_for_TimeAndInterval visitor;
//void __FunctorVisitor__for__Indexed_for_TimeAndInterval_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(__FunctorVisitor__for__Indexed_for_TimeAndInterval *pFunctorVisitor__for__Indexed_for_TimeAndInterval,
//    void (*fun)(Indexed_for_TimeAndInterval* item));
  __FunctorVisitor__for__Indexed_for_TimeAndInterval_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(&visitor, fun);
//  (pICollection_Indexed_for_TimeAndInterval->pForeach_in_ICollection_Indexed_for_TimeAndInterval)
//       (pICollection_Indexed_for_TimeAndInterval, &(visitor.iIVisitor__for__Indexed_for_TimeAndInterval));
   Foreach_in_ICollection_Indexed_for_TimeAndInterval(pICollection_Indexed_for_TimeAndInterval, &(visitor.iIVisitor__for__Indexed_for_TimeAndInterval));
}
*/

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
  __IVisitor__for__Indexed_for_TimeAndInterval iIVisitor__for__Indexed_for_TimeAndInterval;

////private:
  void (*Fun)(Indexed_for_TimeAndInterval* item);

} __FunctorVisitor__for__Indexed_for_TimeAndInterval;

void __FunctorVisitor__for__Indexed_for_TimeAndInterval_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(__FunctorVisitor__for__Indexed_for_TimeAndInterval *pFunctorVisitor__for__Indexed_for_TimeAndInterval,
    void (*fun)(Indexed_for_TimeAndInterval* item));
/*
void __FunctorVisitor__for__Indexed_for_TimeAndInterval_in_FunctorVisitor__for__Indexed_for_TimeAndInterval(__FunctorVisitor__for__Indexed_for_TimeAndInterval *pFunctorVisitor__for__Indexed_for_TimeAndInterval,
    void (*fun)(Indexed_for_TimeAndInterval* item))
{
  pFunctorVisitor__for__Indexed_for_TimeAndInterval->Fun = fun;

  pFunctorVisitor__for__Indexed_for_TimeAndInterval->pOnValue_in_IVisitor__for__Indexed_for_TimeAndInterval =
  __OnValue_in_FunctorVisitor__for__Indexed_for_TimeAndInterval_override;

  setParentPointer_in_IVisitor__for__Indexed_for_TimeAndInterval(&(pFunctorVisitor__for__Indexed_for_TimeAndInterval->iIVisitor__for__Indexed_for_TimeAndInterval), pFunctorVisitor__for__Indexed_for_TimeAndInterval);
}
*/
void __OnValue_in_FunctorVisitor__for__Indexed_for_TimeAndInterval_override(void *pFunctorVisitor__for__Indexed_for_TimeAndInterval, Indexed_for_TimeAndInterval *value);
/*
void __OnValue_in_FunctorVisitor__for__Indexed_for_TimeAndInterval_override(void *pFunctorVisitor__for__Indexed_for_TimeAndInterval,
                       Indexed_for_TimeAndInterval *value)
{
  ((FunctorVisitor__for__Indexed_for_TimeAndInterval*)pFunctorVisitor__for__Indexed_for_TimeAndInterval)->
  Fun(value);
}

*/

//--------------------------------ICollection_Indexed_for_TimeAndInterval--------------------------------

#endif
