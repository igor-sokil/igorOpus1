
#ifndef OPENDNP3_ICOLLECTION_for_CommandPointResult_H
#define OPENDNP3_ICOLLECTION_for_CommandPointResult_H

#include "CommandPointResult.h"
//#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_for_CommandPointResult--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__CommandPointResult)(void*, CommandPointResult* value);// = 0;

  void* pParentPointer_in_IVisitor__for__CommandPointResult;
} IVisitor__for__CommandPointResult;

void* getParentPointer_in_IVisitor_for_CommandPointResult(IVisitor__for__CommandPointResult*);
void  setParentPointer_in_IVisitor_for_CommandPointResult(IVisitor__for__CommandPointResult*, void*);

void OnValue_in_IVisitor__for__CommandPointResult(IVisitor__for__CommandPointResult *, CommandPointResult* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  CommandPointResult *pValue_in_ICollection_for_CommandPointResult;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_CommandPointResult)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_CommandPointResult)(void*, IVisitor__for__CommandPointResult* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_for_CommandPointResult(uint16_t* value) const
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
  void* pParentPointer_in_ICollection_for_CommandPointResult;
} ICollection_for_CommandPointResult;

void* getParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult*);
void  setParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult*, void*);
uint16_t Count_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult*);
void     Foreach_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult*, IVisitor__for__CommandPointResult* visitor);

boolean ReadOnlyValue_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, CommandPointResult* value);

void ForeachItem_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, void (*fun)(CommandPointResult* item));

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
  IVisitor__for__CommandPointResult iIVisitor__for__CommandPointResult;

////private:
  void (*Fun)(CommandPointResult* item);

} FunctorVisitor__for__CommandPointResult;

void FunctorVisitor__for__CommandPointResult_in_FunctorVisitor__for__CommandPointResult(FunctorVisitor__for__CommandPointResult *pFunctorVisitor__for__CommandPointResult,
    void (*fun)(CommandPointResult* item));
void OnValue_in_FunctorVisitor__for__CommandPointResult_override(void *pFunctorVisitor__for__CommandPointResult, CommandPointResult *value);
//--------------------------------ICollection_for_CommandPointResult--------------------------------

////} // namespace opendnp3
#endif
