#ifndef OPENDNP3_ICOLLECTION_Indexed_for_Counter_H
#define OPENDNP3_ICOLLECTION_Indexed_for_Counter_H

#include "Indexed.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_Indexed_for_Counter)(void*, Indexed_for_Counter value);// = 0;

  void* pParentPointer_in_IVisitor_Indexed_for_Counter;
} IVisitor_Indexed_for_Counter;

void* getParentPointer_in_IVisitor_Indexed_for_Counter(IVisitor_Indexed_for_Counter*);
void  setParentPointer_in_IVisitor_Indexed_for_Counter(IVisitor_Indexed_for_Counter*, void*);

void OnValue_in_IVisitor_Indexed_for_Counter(IVisitor_Indexed_for_Counter *, Indexed_for_Counter );

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
  IVisitor_Indexed_for_Counter iIVisitor_Indexed_for_Counter;

////private:
  void (*Fun)(Indexed_for_Counter item);

} FunctorVisitor_Indexed_for_Counter;

void FunctorVisitor_Indexed_for_Counter_in_FunctorVisitor_Indexed_for_Counter(FunctorVisitor_Indexed_for_Counter *pFunctorVisitor_Indexed_for_Counter,
    void (*fun)(Indexed_for_Counter item));
void OnValue_in_FunctorVisitor_Indexed_for_Counter(FunctorVisitor_Indexed_for_Counter *pFunctorVisitor_Indexed_for_Counter, Indexed_for_Counter value);
void OnValue_in_FunctorVisitor_Indexed_for_Counter_override(void *pIVisitor_Indexed_for_Counter, Indexed_for_Counter value);

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
    uint16_t (*pCount_in_ICollection_Indexed_for_Counter)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_Indexed_for_Counter)(void *, IVisitor_Indexed_for_Counter *pIVisitor_Indexed_for_Counter);// const = 0;

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
  void* pParentPointer_in_ICollection_Indexed_for_Counter;
} ICollection_Indexed_for_Counter;


void ForeachItem_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, void (*fun)(Indexed_for_Counter item));

void* getParentPointer_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter);
void  setParentPointer_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter* pICollection_Indexed_for_Counter, void* pParentPointer);
uint16_t  Count_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter);
void  Foreach_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, IVisitor_Indexed_for_Counter *pIVisitor_Indexed_for_Counter);


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
boolean ReadOnlyValue_in_ICollection_Indexed_for_Counter(ICollection_Indexed_for_Counter *pICollection_Indexed_for_Counter, Indexed_for_Counter* value);


#endif
