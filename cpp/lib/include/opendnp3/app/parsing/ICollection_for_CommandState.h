
#ifndef OPENDNP3_ICOLLECTION_for_CommandState_H
#define OPENDNP3_ICOLLECTION_for_CommandState_H

#include "CommandState.h"
//#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_for_CommandState--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__CommandState)(void*, CommandState* value);// = 0;

  void* pParentPointer_in_IVisitor__for__CommandState;
} IVisitor__for__CommandState;

void* getParentPointer_in_IVisitor_for_CommandState(IVisitor__for__CommandState*);
void  setParentPointer_in_IVisitor_for_CommandState(IVisitor__for__CommandState*, void*);

void OnValue_in_IVisitor__for__CommandState(IVisitor__for__CommandState *, CommandState* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  CommandState *pValue_in_ICollection_for_CommandState;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_CommandState)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_CommandState)(void*, IVisitor__for__CommandState* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_for_CommandState(uint16_t* value) const
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
  void* pParentPointer_in_ICollection_for_CommandState;
} ICollection_for_CommandState;

void* getParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState*);
void  setParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState*, void*);
uint16_t Count_in_ICollection_for_CommandState(ICollection_for_CommandState*);
void     Foreach_in_ICollection_for_CommandState(ICollection_for_CommandState*, IVisitor__for__CommandState* visitor);

boolean ReadOnlyValue_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, CommandState* value);

void ForeachItem_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, void (*fun)(CommandState* item));

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
  IVisitor__for__CommandState iIVisitor__for__CommandState;

////private:
  void (*Fun)(CommandState* item);

} FunctorVisitor__for__CommandState;

void FunctorVisitor__for__CommandState_in_FunctorVisitor__for__CommandState(FunctorVisitor__for__CommandState *pFunctorVisitor__for__CommandState,
    void (*fun)(CommandState* item));
void OnValue_in_FunctorVisitor__for__CommandState_override(void *pFunctorVisitor__for__CommandState, CommandState *value);
//--------------------------------ICollection_for_CommandState--------------------------------

////} // namespace opendnp3
#endif
