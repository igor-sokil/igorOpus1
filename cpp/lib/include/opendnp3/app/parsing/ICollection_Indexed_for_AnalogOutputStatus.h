#ifndef OPENDNP3_ICOLLECTION_Indexed_for_AnalogOutputStatus_H
#define OPENDNP3_ICOLLECTION_Indexed_for_AnalogOutputStatus_H

#include "Indexed.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_Indexed_for_AnalogOutputStatus)(void*, Indexed_for_AnalogOutputStatus value);// = 0;

  void* pParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus;
} IVisitor_Indexed_for_AnalogOutputStatus;

void* getParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus(IVisitor_Indexed_for_AnalogOutputStatus*);
void  setParentPointer_in_IVisitor_Indexed_for_AnalogOutputStatus(IVisitor_Indexed_for_AnalogOutputStatus*, void*);

void OnValue_in_IVisitor_Indexed_for_AnalogOutputStatus(IVisitor_Indexed_for_AnalogOutputStatus *, Indexed_for_AnalogOutputStatus );

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
  IVisitor_Indexed_for_AnalogOutputStatus iIVisitor_Indexed_for_AnalogOutputStatus;

////private:
  void (*Fun)(Indexed_for_AnalogOutputStatus item);

} FunctorVisitor_Indexed_for_AnalogOutputStatus;

void FunctorVisitor_Indexed_for_AnalogOutputStatus_in_FunctorVisitor_Indexed_for_AnalogOutputStatus(FunctorVisitor_Indexed_for_AnalogOutputStatus *pFunctorVisitor_Indexed_for_AnalogOutputStatus,
    void (*fun)(Indexed_for_AnalogOutputStatus item));
void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputStatus(FunctorVisitor_Indexed_for_AnalogOutputStatus *pFunctorVisitor_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus value);
void OnValue_in_FunctorVisitor_Indexed_for_AnalogOutputStatus_override(void *pIVisitor_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus value);

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
    uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputStatus)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_Indexed_for_AnalogOutputStatus)(void *, IVisitor_Indexed_for_AnalogOutputStatus *pIVisitor_Indexed_for_AnalogOutputStatus);// const = 0;

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
  void* pParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus;
} ICollection_Indexed_for_AnalogOutputStatus;


void ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, void (*fun)(Indexed_for_AnalogOutputStatus item));

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus);
void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus* pICollection_Indexed_for_AnalogOutputStatus, void* pParentPointer);
uint16_t  Count_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus);
void  Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, IVisitor_Indexed_for_AnalogOutputStatus *pIVisitor_Indexed_for_AnalogOutputStatus);


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
boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus* value);


#endif
