
#ifndef OPENDNP3_ICOLLECTION_for_DNPTime_H
#define OPENDNP3_ICOLLECTION_for_DNPTime_H

//#include "Indexed.h"
//#include "Group50.h"
////#include <cstddef>

////namespace opendnp3
////{
//--------------------------------ICollection_for_DNPTime--------------------------------
/**
 * Abstract way of visiting elements of a collection
 *
 */
////template<class T> class IVisitor
typedef struct
{
////public:
  void (*pOnValue_in_IVisitor__for__DNPTime)(void*, DNPTime* value);// = 0;

  void* pParentPointer_in_IVisitor__for__DNPTime;
} IVisitor__for__DNPTime;

void* getParentPointer_in_IVisitor_for_DNPTime(IVisitor__for__DNPTime*);
void  setParentPointer_in_IVisitor_for_DNPTime(IVisitor__for__DNPTime*, void*);

void OnValue_in_IVisitor__for__DNPTime(IVisitor__for__DNPTime *, DNPTime* );

/**
 * An interface representing an abstract immutable collection of things of type T.
 *
 * The user can only read these values via callback to receive each element.
 */
////template<class T> class ICollection
typedef struct
{
//  DNPTime *pValue_in_ICollection_for_DNPTime;
////public:
  /**
   * The number of elements in the collection
   */
  uint16_t (*pCount_in_ICollection_for_DNPTime)(void*);// const = 0;

  /**
   * Visit all the elements of a collection
   */
  void (*pForeach_in_ICollection_for_DNPTime)(void*, IVisitor__for__DNPTime* visitor);// const = 0;

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
////    boolean ReadOnlyValue_in_ICollection_for_DNPTime(uint16_t* value) const
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

void* getParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime*);
void  setParentPointer_in_ICollection_for_DNPTime(ICollection_for_DNPTime*, void*);
uint16_t Count_in_ICollection_for_DNPTime(ICollection_for_DNPTime*);
void     Foreach_in_ICollection_for_DNPTime(ICollection_for_DNPTime*, IVisitor__for__DNPTime* visitor);

boolean ReadOnlyValue_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, DNPTime* value);

void ForeachItem_in_ICollection_for_DNPTime(ICollection_for_DNPTime *pICollection_for_DNPTime, void (*fun)(DNPTime* item));

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
  IVisitor__for__DNPTime iIVisitor__for__DNPTime;

////private:
  void (*Fun)(DNPTime* item);

} FunctorVisitor__for__DNPTime;

void FunctorVisitor__for__DNPTime_in_FunctorVisitor__for__DNPTime(FunctorVisitor__for__DNPTime *pFunctorVisitor__for__DNPTime,
    void (*fun)(DNPTime* item));
void OnValue_in_FunctorVisitor__for__DNPTime_override(void *pFunctorVisitor__for__DNPTime, DNPTime *value);
//--------------------------------ICollection_for_DNPTime--------------------------------

////} // namespace opendnp3
#endif
