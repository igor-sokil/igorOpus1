#ifndef OPENDNP3_ICOLLECTION_for_uint32_H
#define OPENDNP3_ICOLLECTION_for_uint32_H

////#include "IVisitor_for_uint32.h"

/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor_for_uint32)(void*, uint32_t value);// = 0;

  void* pParentPointer_in_IVisitor_for_uint32;
} IVisitor_for_uint32;

void* getParentPointer_in_IVisitor_for_uint32(IVisitor_for_uint32*);
void  setParentPointer_in_IVisitor_for_uint32(IVisitor_for_uint32*, void*);

void OnValue_in_IVisitor_for_uint32(IVisitor_for_uint32 *, uint32_t );

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
  IVisitor_for_uint32 iIVisitor_for_uint32;

////private:
  void (*Fun)(uint32_t item);

} FunctorVisitor_for_uint32;

void FunctorVisitor_for_uint32_in_FunctorVisitor_for_uint32(FunctorVisitor_for_uint32 *pFunctorVisitor_for_uint32,
    void (*fun)(uint32_t item));
void OnValue_in_FunctorVisitor_for_uint32(FunctorVisitor_for_uint32 *pFunctorVisitor_for_uint32, uint32_t value);
void OnValue_in_FunctorVisitor_for_uint32_override(void *pIVisitor_for_uint32, uint32_t value);

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
    uint16_t (*pCount_in_ICollection_for_uint32)(void *);// const = 0;

    /**
     * Visit all the elements of a collection
     */
////    virtual void Foreach(IVisitor<T>& visitor) const = 0;
    void (*pForeach_in_ICollection_for_uint32)(void *, IVisitor_for_uint32 *pIVisitor_for_uint32);// const = 0;

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
  void* pParentPointer_in_ICollection_for_uint32;
} ICollection_for_uint32;


void ForeachItem_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32, void (*fun)(uint32_t item));

void* getParentPointer_in_ICollection_for_uint32(ICollection_for_uint32* pICollection_for_uint32);
void  setParentPointer_in_ICollection_for_uint32(ICollection_for_uint32* pICollection_for_uint32, void* pParentPointer);
uint16_t  Count_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32);
void  Foreach_in_ICollection_for_uint32(ICollection_for_uint32 *pICollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32);


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


#endif
