
#ifndef OPENDNP3_ICOLLECTION_Indexed_for_AnalogOutputDouble64_H
#define OPENDNP3_ICOLLECTION_Indexed_for_AnalogOutputDouble64_H

#include "Indexed.h"
//#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64)(void*, Indexed_for_AnalogOutputDouble64* value);// = 0;

  void* pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64;
} IVisitor__for__Indexed_for_AnalogOutputDouble64;

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(IVisitor__for__Indexed_for_AnalogOutputDouble64*);
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(IVisitor__for__Indexed_for_AnalogOutputDouble64*, void*);

void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputDouble64(IVisitor__for__Indexed_for_AnalogOutputDouble64 *, Indexed_for_AnalogOutputDouble64* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  Indexed_for_AnalogOutputDouble64 *pValue_in_ICollection_Indexed_for_AnalogOutputDouble64;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputDouble64)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_AnalogOutputDouble64)(void*, IVisitor__for__Indexed_for_AnalogOutputDouble64* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(uint16_t* value) const
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
  void* pParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64;
} ICollection_Indexed_for_AnalogOutputDouble64;

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64*);
void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64*, void*);
  uint16_t Count_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64*);
  void     Foreach_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64*, IVisitor__for__Indexed_for_AnalogOutputDouble64* visitor);

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64* value);

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputDouble64(ICollection_Indexed_for_AnalogOutputDouble64 *pICollection_Indexed_for_AnalogOutputDouble64, void (*fun)(Indexed_for_AnalogOutputDouble64* item));

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
  IVisitor__for__Indexed_for_AnalogOutputDouble64 iIVisitor__for__Indexed_for_AnalogOutputDouble64;

////private:
  void (*Fun)(Indexed_for_AnalogOutputDouble64* item);

} FunctorVisitor__for__Indexed_for_AnalogOutputDouble64;

void FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64(FunctorVisitor__for__Indexed_for_AnalogOutputDouble64 *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64,
    void (*fun)(Indexed_for_AnalogOutputDouble64* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputDouble64_override(void *pFunctorVisitor__for__Indexed_for_AnalogOutputDouble64, Indexed_for_AnalogOutputDouble64 *value);
//--------------------------------ICollection_Indexed_for_AnalogOutputDouble64--------------------------------

////} // namespace opendnp3
#endif
