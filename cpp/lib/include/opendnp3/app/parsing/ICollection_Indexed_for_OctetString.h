
#ifndef OPENDNP3_ICOLLECTION_Indexed_for_OctetString_H
#define OPENDNP3_ICOLLECTION_Indexed_for_OctetString_H

#include "Indexed.h"
//#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_Indexed_for_OctetString--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__Indexed_for_OctetString)(void*, Indexed_for_OctetString* value);// = 0;

  void* pParentPointer_in_IVisitor__for__Indexed_for_OctetString;
} IVisitor__for__Indexed_for_OctetString;

void* getParentPointer_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString*);
void  setParentPointer_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString*, void*);

void OnValue_in_IVisitor__for__Indexed_for_OctetString(IVisitor__for__Indexed_for_OctetString *, Indexed_for_OctetString* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  Indexed_for_OctetString *pValue_in_ICollection_Indexed_for_OctetString;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_Indexed_for_OctetString)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_Indexed_for_OctetString)(void*, IVisitor__for__Indexed_for_OctetString* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_Indexed_for_OctetString(uint16_t* value) const
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
  void* pParentPointer_in_ICollection_Indexed_for_OctetString;
} ICollection_Indexed_for_OctetString;

void* getParentPointer_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString*);
void  setParentPointer_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString*, void*);
uint16_t Count_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString*);
void     Foreach_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString*, IVisitor__for__Indexed_for_OctetString* visitor);

boolean ReadOnlyValue_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString, Indexed_for_OctetString* value);

void ForeachItem_in_ICollection_Indexed_for_OctetString(ICollection_Indexed_for_OctetString *pICollection_Indexed_for_OctetString, void (*fun)(Indexed_for_OctetString* item));

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
  IVisitor__for__Indexed_for_OctetString iIVisitor__for__Indexed_for_OctetString;

////private:
  void (*Fun)(Indexed_for_OctetString* item);

} FunctorVisitor__for__Indexed_for_OctetString;

void FunctorVisitor__for__Indexed_for_OctetString_in_FunctorVisitor__for__Indexed_for_OctetString(FunctorVisitor__for__Indexed_for_OctetString *pFunctorVisitor__for__Indexed_for_OctetString,
    void (*fun)(Indexed_for_OctetString* item));
void OnValue_in_FunctorVisitor__for__Indexed_for_OctetString_override(void *pFunctorVisitor__for__Indexed_for_OctetString, Indexed_for_OctetString *value);
//--------------------------------ICollection_Indexed_for_OctetString--------------------------------

////} // namespace opendnp3
#endif
