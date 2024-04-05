#ifndef OPENDNP3_ICOLLECTION_for_CommandPointResult_H
#define OPENDNP3_ICOLLECTION_for_CommandPointResult_H

#include "CommandPointResult.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_CommandPointResult)(void*, CommandPointResult value);// = 0;

  void* pParentPointer_in_IVisitor_for_CommandPointResult;
} IVisitor_for_CommandPointResult;

void* getParentPointer_in_IVisitor_for_CommandPointResult(IVisitor_for_CommandPointResult*);
void  setParentPointer_in_IVisitor_for_CommandPointResult(IVisitor_for_CommandPointResult*, void*);

void OnValue_in_IVisitor_for_CommandPointResult(IVisitor_for_CommandPointResult *, CommandPointResult );

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
  IVisitor_for_CommandPointResult iIVisitor_for_CommandPointResult;

////private:
  void (*Fun)(CommandPointResult item);

} FunctorVisitor_for_CommandPointResult;

void FunctorVisitor_for_CommandPointResult_in_FunctorVisitor_for_CommandPointResult(FunctorVisitor_for_CommandPointResult *pFunctorVisitor_for_CommandPointResult,
    void (*fun)(CommandPointResult item));
void OnValue_in_FunctorVisitor_for_CommandPointResult(FunctorVisitor_for_CommandPointResult *pFunctorVisitor_for_CommandPointResult, CommandPointResult value);
void OnValue_in_FunctorVisitor_for_CommandPointResult_override(void *pIVisitor_for_CommandPointResult, CommandPointResult value);

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
    uint16_t (*pCount_in_ICollection_for_CommandPointResult)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_for_CommandPointResult)(void *, IVisitor_for_CommandPointResult *pIVisitor_for_CommandPointResult);// const = 0;

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
  void* pParentPointer_in_ICollection_for_CommandPointResult;
} ICollection_for_CommandPointResult;


void ForeachItem_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, void (*fun)(CommandPointResult item));

void* getParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_for_CommandPointResult);
void  setParentPointer_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult* pICollection_for_CommandPointResult, void* pParentPointer);
uint16_t  Count_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult);
void  Foreach_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, IVisitor_for_CommandPointResult *pIVisitor_for_CommandPointResult);


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
boolean ReadOnlyValue_in_ICollection_for_CommandPointResult(ICollection_for_CommandPointResult *pICollection_for_CommandPointResult, CommandPointResult* value);


#endif
