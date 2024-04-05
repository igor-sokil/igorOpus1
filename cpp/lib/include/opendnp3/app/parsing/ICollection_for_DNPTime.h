#ifndef OPENDNP3_ICOLLECTION_for_DNPTime_H
#define OPENDNP3_ICOLLECTION_for_DNPTime_H

#include "DNPTime.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_DNPTime)(void*, DNPTime value);// = 0;

  void* pParentPointer_in_IVisitor_for_DNPTime;
} IVisitor_for_DNPTime;

void* getParentPointer_in_IVisitor_for_DNPTime(IVisitor_for_DNPTime*);
void  setParentPointer_in_IVisitor_for_DNPTime(IVisitor_for_DNPTime*, void*);

void OnValue_in_IVisitor_for_DNPTime(IVisitor_for_DNPTime *, DNPTime );

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
  IVisitor_for_DNPTime iIVisitor_for_DNPTime;

////private:
  void (*Fun)(DNPTime item);

} FunctorVisitor_for_DNPTime;

void FunctorVisitor_for_DNPTime_in_FunctorVisitor_for_DNPTime(FunctorVisitor_for_DNPTime *pFunctorVisitor_for_DNPTime,
    void (*fun)(DNPTime item));
void OnValue_in_FunctorVisitor_for_DNPTime(FunctorVisitor_for_DNPTime *pFunctorVisitor_for_DNPTime, DNPTime value);
void OnValue_in_FunctorVisitor_for_DNPTime_override(void *pIVisitor_for_DNPTime, DNPTime value);

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
    uint16_t (*pCount_in_ICollection_for_DNPTime)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_for_DNPTime)(void *, IVisitor_for_DNPTime *pIVisitor_for_DNPTime);// const = 0;

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
  void* pParentPointer_in_ICollection_for_DNPTime;
} ICollection_for_DNPTime;


void ForeachItem_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, void (*fun)(DNPTime item));

void* getParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_for_DNPTime);
void  setParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime* pICollection_for_DNPTime, void* pParentPointer);
uint16_t  Count_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime);
void  Foreach_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, IVisitor_for_DNPTime *pIVisitor_for_DNPTime);


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
boolean ReadOnlyValue_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, DNPTime* value);


#endif
