#ifndef OPENDNP3_ICOLLECTION_for_CommandState_H
#define OPENDNP3_ICOLLECTION_for_CommandState_H

#include "CommandState.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_CommandState)(void*, CommandState value);// = 0;

  void* pParentPointer_in_IVisitor_for_CommandState;
} IVisitor_for_CommandState;

void* getParentPointer_in_IVisitor_for_CommandState(IVisitor_for_CommandState*);
void  setParentPointer_in_IVisitor_for_CommandState(IVisitor_for_CommandState*, void*);

void OnValue_in_IVisitor_for_CommandState(IVisitor_for_CommandState *, CommandState );

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
  IVisitor_for_CommandState iIVisitor_for_CommandState;

////private:
  void (*Fun)(CommandState item);

} FunctorVisitor_for_CommandState;

void FunctorVisitor_for_CommandState_in_FunctorVisitor_for_CommandState(FunctorVisitor_for_CommandState *pFunctorVisitor_for_CommandState,
    void (*fun)(CommandState item));
void OnValue_in_FunctorVisitor_for_CommandState(FunctorVisitor_for_CommandState *pFunctorVisitor_for_CommandState, CommandState value);
void OnValue_in_FunctorVisitor_for_CommandState_override(void *pIVisitor_for_CommandState, CommandState value);

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
////public:
    /**
     * The number of elements in the collection
     */
////    virtual size_t Count() const = 0;
    uint16_t (*pCount_in_ICollection_for_CommandState)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_for_CommandState)(void *, IVisitor_for_CommandState *pIVisitor_for_CommandState);// const = 0;

    /**
        visit all of the elements of a collection
    */
////    template<class Fun> void ForeachItem(const Fun& fun) const
////    {
////        FunctorVisitor<T, Fun> visitor(fun);
////        this->Foreach(visitor);
////    }

    /**
        Retrieve the only value from the collection.
    */
////    bool ReadOnlyValue(T& value) const
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


void ForeachItem_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, void (*fun)(CommandState item));

void* getParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_for_CommandState);
void  setParentPointer_in_ICollection_for_CommandState(ICollection_for_CommandState* pICollection_for_CommandState, void* pParentPointer);
uint16_t  Count_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState);
void  Foreach_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, IVisitor_for_CommandState *pIVisitor_for_CommandState);


    /**
        Retrieve the only value from the collection.
    */
////    bool ReadOnlyValue(T& value) const
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
boolean ReadOnlyValue_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, CommandState* value);


#endif
