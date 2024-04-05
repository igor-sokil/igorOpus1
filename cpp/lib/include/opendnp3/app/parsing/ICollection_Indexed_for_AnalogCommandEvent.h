#ifndef OPENDNP3_ICOLLECTION_Indexed_for_AnalogCommandEvent_H
#define OPENDNP3_ICOLLECTION_Indexed_for_AnalogCommandEvent_H

#include "Indexed.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_Indexed_for_AnalogCommandEvent)(void*, Indexed_for_AnalogCommandEvent value);// = 0;

  void* pParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent;
} IVisitor_Indexed_for_AnalogCommandEvent;

void* getParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent(IVisitor_Indexed_for_AnalogCommandEvent*);
void  setParentPointer_in_IVisitor_Indexed_for_AnalogCommandEvent(IVisitor_Indexed_for_AnalogCommandEvent*, void*);

void OnValue_in_IVisitor_Indexed_for_AnalogCommandEvent(IVisitor_Indexed_for_AnalogCommandEvent *, Indexed_for_AnalogCommandEvent );

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
  IVisitor_Indexed_for_AnalogCommandEvent iIVisitor_Indexed_for_AnalogCommandEvent;

////private:
  void (*Fun)(Indexed_for_AnalogCommandEvent item);

} FunctorVisitor_Indexed_for_AnalogCommandEvent;

void FunctorVisitor_Indexed_for_AnalogCommandEvent_in_FunctorVisitor_Indexed_for_AnalogCommandEvent(FunctorVisitor_Indexed_for_AnalogCommandEvent *pFunctorVisitor_Indexed_for_AnalogCommandEvent,
    void (*fun)(Indexed_for_AnalogCommandEvent item));
void OnValue_in_FunctorVisitor_Indexed_for_AnalogCommandEvent(FunctorVisitor_Indexed_for_AnalogCommandEvent *pFunctorVisitor_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent value);
void OnValue_in_FunctorVisitor_Indexed_for_AnalogCommandEvent_override(void *pIVisitor_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent value);

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
    uint16_t (*pCount_in_ICollection_Indexed_for_AnalogCommandEvent)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_Indexed_for_AnalogCommandEvent)(void *, IVisitor_Indexed_for_AnalogCommandEvent *pIVisitor_Indexed_for_AnalogCommandEvent);// const = 0;

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
  void* pParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent;
} ICollection_Indexed_for_AnalogCommandEvent;


void ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, void (*fun)(Indexed_for_AnalogCommandEvent item));

void* getParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent);
void  setParentPointer_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent* pICollection_Indexed_for_AnalogCommandEvent, void* pParentPointer);
uint16_t  Count_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent);
void  Foreach_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, IVisitor_Indexed_for_AnalogCommandEvent *pIVisitor_Indexed_for_AnalogCommandEvent);


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
boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogCommandEvent(ICollection_Indexed_for_AnalogCommandEvent *pICollection_Indexed_for_AnalogCommandEvent, Indexed_for_AnalogCommandEvent* value);


#endif
