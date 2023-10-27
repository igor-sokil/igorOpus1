
#ifndef OPENDNP3_ICOLLECTION_Indexed_for_AnalogOutputStatus_H
#define OPENDNP3_ICOLLECTION_Indexed_for_AnalogOutputStatus_H

#include "Indexed.h"
//#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_Indexed_for_AnalogOutputStatus--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus)(void*, Indexed_for_AnalogOutputStatus* value);// = 0;

  void* pParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus;
} IVisitor__for__Indexed_for_AnalogOutputStatus;

void* getParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus*);
void  setParentPointer_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus*, void*);

void OnValue_in_IVisitor__for__Indexed_for_AnalogOutputStatus(IVisitor__for__Indexed_for_AnalogOutputStatus *, Indexed_for_AnalogOutputStatus* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  Indexed_for_AnalogOutputStatus *pValue_in_ICollection_Indexed_for_AnalogOutputStatus;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_AnalogOutputStatus)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_AnalogOutputStatus)(void*, IVisitor__for__Indexed_for_AnalogOutputStatus* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputStatus(uint16_t* value) const
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

void* getParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus*);
void  setParentPointer_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus*, void*);
uint16_t Count_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus*);
void     Foreach_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus*, IVisitor__for__Indexed_for_AnalogOutputStatus* visitor);

boolean ReadOnlyValue_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus* value);

void ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(ICollection_Indexed_for_AnalogOutputStatus *pICollection_Indexed_for_AnalogOutputStatus, void (*fun)(Indexed_for_AnalogOutputStatus* item));

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
  IVisitor__for__Indexed_for_AnalogOutputStatus iIVisitor__for__Indexed_for_AnalogOutputStatus;

////private:
  void (*Fun)(Indexed_for_AnalogOutputStatus* item);

} FunctorVisitor__for__Indexed_for_AnalogOutputStatus;

void FunctorVisitor__for__Indexed_for_AnalogOutputStatus_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus(FunctorVisitor__for__Indexed_for_AnalogOutputStatus *pFunctorVisitor__for__Indexed_for_AnalogOutputStatus,
    void (*fun)(Indexed_for_AnalogOutputStatus* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_AnalogOutputStatus_override(void *pFunctorVisitor__for__Indexed_for_AnalogOutputStatus, Indexed_for_AnalogOutputStatus *value);
//--------------------------------ICollection_Indexed_for_AnalogOutputStatus--------------------------------

////} // namespace opendnp3
#endif
