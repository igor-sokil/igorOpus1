#ifndef OPENDNP3_TRANSFORMCOLLECTION_for_uint32_H
#define OPENDNP3_TRANSFORMCOLLECTION_for_uint32_H

#include "ICollection_for_uint32.h"
////template<class T, class U, class Transform> class TransformedCollection : public ICollection<U>
typedef struct
{
  ICollection_for_uint32 iICollection_for_uint32;
////public:
////    TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}

////    virtual size_t Count() const override final
////    {
////        return input->Count();
////    }

////    virtual void Foreach(IVisitor<U>& visitor) const override final
////    {
////        auto process = [this, &visitor](const T& elem) { visitor.OnValue(transform(elem)); };
////        input->ForeachItem(process);
////    }

////private:
////    const ICollection<T>* input;
   ICollection_for_uint32* input1;
////    Transform transform;
   uint32_t (*transform)(uint32_t);
} TransformedCollection_for_uint32;

 void TransformedCollection_for_uint32_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32,
                  ICollection_for_uint32* input, uint32_t (*transform)(uint32_t));
uint16_t  Count_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32);
void  Foreach_in_TransformedCollection_for_uint32(TransformedCollection_for_uint32 *pTransformedCollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32);
uint16_t  Count_in_TransformedCollection_for_uint32_override(void *pICollection_for_uint32);
void  Foreach_in_TransformedCollection_for_uint32_override(void *pICollection_for_uint32, IVisitor_for_uint32 *pIVisitor_for_uint32);

////template<class T, class U, class Transform>
////TransformedCollection<T, U, Transform> Map(const ICollection<T>& input, Transform transform)
////{
////    return TransformedCollection<T, U, Transform>(input, transform);
////}

////TransformedCollection<T, U, Transform> Map(const ICollection<T>& input, Transform transform)
TransformedCollection_for_uint32 Map_for_uint32(ICollection_for_uint32 *input, uint32_t (*transform)(uint32_t));


#endif