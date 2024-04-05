#ifndef OPENDNP3_ICOLLECTION_for_Group50Var3_H
#define OPENDNP3_ICOLLECTION_for_Group50Var3_H

#include "Group50.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_Group50Var3)(void*, Group50Var3 value);// = 0;

  void* pParentPointer_in_IVisitor_for_Group50Var3;
} IVisitor_for_Group50Var3;

void* getParentPointer_in_IVisitor_for_Group50Var3(IVisitor_for_Group50Var3*);
void  setParentPointer_in_IVisitor_for_Group50Var3(IVisitor_for_Group50Var3*, void*);

void OnValue_in_IVisitor_for_Group50Var3(IVisitor_for_Group50Var3 *, Group50Var3 );

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
  IVisitor_for_Group50Var3 iIVisitor_for_Group50Var3;

////private:
  void (*Fun)(Group50Var3 item);

} FunctorVisitor_for_Group50Var3;

void FunctorVisitor_for_Group50Var3_in_FunctorVisitor_for_Group50Var3(FunctorVisitor_for_Group50Var3 *pFunctorVisitor_for_Group50Var3,
    void (*fun)(Group50Var3 item));
void OnValue_in_FunctorVisitor_for_Group50Var3(FunctorVisitor_for_Group50Var3 *pFunctorVisitor_for_Group50Var3, Group50Var3 value);
void OnValue_in_FunctorVisitor_for_Group50Var3_override(void *pIVisitor_for_Group50Var3, Group50Var3 value);

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
    uint16_t (*pCount_in_ICollection_for_Group50Var3)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_for_Group50Var3)(void *, IVisitor_for_Group50Var3 *pIVisitor_for_Group50Var3);// const = 0;

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
  void* pParentPointer_in_ICollection_for_Group50Var3;
} ICollection_for_Group50Var3;


void ForeachItem_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, void (*fun)(Group50Var3 item));

void* getParentPointer_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3* pICollection_for_Group50Var3);
void  setParentPointer_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3* pICollection_for_Group50Var3, void* pParentPointer);
uint16_t  Count_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3);
void  Foreach_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, IVisitor_for_Group50Var3 *pIVisitor_for_Group50Var3);


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
boolean ReadOnlyValue_in_ICollection_for_Group50Var3(ICollection_for_Group50Var3 *pICollection_for_Group50Var3, Group50Var3* value);


#endif
