
#ifndef OPENDNP3_IVISITOR_for_uint32_H
#define OPENDNP3_IVISITOR_for_uint32_H

////namespace opendnp3
////{
//--------------------------------IVisitor_for_uint32--------------------------------
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


////} // namespace opendnp3
#endif
