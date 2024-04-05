#ifndef OPENDNP3_ICOLLECTION_Indexed_for_IINValue_H
#define OPENDNP3_ICOLLECTION_Indexed_for_IINValue_H

#include "Indexed.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_Indexed_for_IINValue)(void*, Indexed_for_IINValue value);// = 0;

  void* pParentPointer_in_IVisitor_Indexed_for_IINValue;
} IVisitor_Indexed_for_IINValue;

void* getParentPointer_in_IVisitor_Indexed_for_IINValue(IVisitor_Indexed_for_IINValue*);
void  setParentPointer_in_IVisitor_Indexed_for_IINValue(IVisitor_Indexed_for_IINValue*, void*);

void OnValue_in_IVisitor_Indexed_for_IINValue(IVisitor_Indexed_for_IINValue *, Indexed_for_IINValue );

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
  IVisitor_Indexed_for_IINValue iIVisitor_Indexed_for_IINValue;

////private:
  void (*Fun)(Indexed_for_IINValue item);

} FunctorVisitor_Indexed_for_IINValue;

void FunctorVisitor_Indexed_for_IINValue_in_FunctorVisitor_Indexed_for_IINValue(FunctorVisitor_Indexed_for_IINValue *pFunctorVisitor_Indexed_for_IINValue,
    void (*fun)(Indexed_for_IINValue item));
void OnValue_in_FunctorVisitor_Indexed_for_IINValue(FunctorVisitor_Indexed_for_IINValue *pFunctorVisitor_Indexed_for_IINValue, Indexed_for_IINValue value);
void OnValue_in_FunctorVisitor_Indexed_for_IINValue_override(void *pIVisitor_Indexed_for_IINValue, Indexed_for_IINValue value);

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
    uint16_t (*pCount_in_ICollection_Indexed_for_IINValue)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_Indexed_for_IINValue)(void *, IVisitor_Indexed_for_IINValue *pIVisitor_Indexed_for_IINValue);// const = 0;

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
  void* pParentPointer_in_ICollection_Indexed_for_IINValue;
} ICollection_Indexed_for_IINValue;


void ForeachItem_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, void (*fun)(Indexed_for_IINValue item));

void* getParentPointer_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue);
void  setParentPointer_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue* pICollection_Indexed_for_IINValue, void* pParentPointer);
uint16_t  Count_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue);
void  Foreach_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, IVisitor_Indexed_for_IINValue *pIVisitor_Indexed_for_IINValue);


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
boolean ReadOnlyValue_in_ICollection_Indexed_for_IINValue(ICollection_Indexed_for_IINValue *pICollection_Indexed_for_IINValue, Indexed_for_IINValue* value);


#endif
