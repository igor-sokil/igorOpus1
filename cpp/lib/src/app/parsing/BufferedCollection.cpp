#include "header.h"
#include "BufferedCollection.h"

//-----------------------------------Indexed_for_Group1Var2---------------------------------------------------
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
void  BufferedCollection_Indexed_for_Group1Var2_in_BufferedCollection_Indexed_for_Group1Var2(
  BufferedCollection_Indexed_for_Group1Var2 *pBufferedCollection_Indexed_for_Group1Var2,
  RSeq_for_Uint16_t* buffer,
  uint16_t count,
  ReadFunc_Indexed_for_Group1Var2 readFunc)
{
  pBufferedCollection_Indexed_for_Group1Var2->buffer = *buffer;
  pBufferedCollection_Indexed_for_Group1Var2->COUNT = count;
  pBufferedCollection_Indexed_for_Group1Var2->readFunc = readFunc;

  pBufferedCollection_Indexed_for_Group1Var2->iICollection_Indexed_for_Group1Var2.pCount_in_ICollection_Indexed_for_Group1Var2 =
    Count_in_BufferedCollection_Indexed_for_Group1Var2_override;
  pBufferedCollection_Indexed_for_Group1Var2->iICollection_Indexed_for_Group1Var2.pForeach_in_ICollection_Indexed_for_Group1Var2 =
    Foreach_in_BufferedCollection_Indexed_for_Group1Var2_override;

  setParentPointer_in_ICollection_Indexed_for_Group1Var2(&(pBufferedCollection_Indexed_for_Group1Var2->iICollection_Indexed_for_Group1Var2), pBufferedCollection_Indexed_for_Group1Var2);
}

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
BufferedCollection_Indexed_for_Group1Var2 CreateBufferedCollection_Indexed_for_Group1Var2_static(
  RSeq_for_Uint16_t* buffer,
  uint16_t count,
  ReadFunc_Indexed_for_Group1Var2 readFunc)
{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
  BufferedCollection_Indexed_for_Group1Var2 bBufferedCollection_Indexed_for_Group1Var2;
  BufferedCollection_Indexed_for_Group1Var2_in_BufferedCollection_Indexed_for_Group1Var2(&bBufferedCollection_Indexed_for_Group1Var2,
      buffer,
      count, readFunc);
  return bBufferedCollection_Indexed_for_Group1Var2;
}

uint16_t Count_in_BufferedCollection_Indexed_for_Group1Var2(BufferedCollection_Indexed_for_Group1Var2 *pBufferedCollection_Indexed_for_Group1Var2)
{
  return pBufferedCollection_Indexed_for_Group1Var2->COUNT;
}

void Foreach_in_BufferedCollection_Indexed_for_Group1Var2(BufferedCollection_Indexed_for_Group1Var2 *pBufferedCollection_Indexed_for_Group1Var2,
    IVisitor__for__Indexed_for_Group1Var2* visitor)
{
////        ser4cpp::rseq_t copy(buffer);
  RSeq_for_Uint16_t copy;
  copy = pBufferedCollection_Indexed_for_Group1Var2->buffer;

  for (uint32_t pos = 0; pos < pBufferedCollection_Indexed_for_Group1Var2->COUNT; ++pos)
  {
//void OnValue_in_IVisitor__for__Indexed_for_Group1Var2(IVisitor__for__Indexed_for_Group1Var2 *, Indexed_for_Group1Var2* );
////            visitor.OnValue(readFunc(copy, pos));
    Indexed_for_Group1Var2 temp = pBufferedCollection_Indexed_for_Group1Var2->readFunc(&copy, pos);
    OnValue_in_IVisitor__for__Indexed_for_Group1Var2(visitor, &temp );
  }
}

uint16_t Count_in_BufferedCollection_Indexed_for_Group1Var2_override(void *pICollection_Indexed_for_Group1Var2)
{
  BufferedCollection_Indexed_for_Group1Var2* parent =
    (BufferedCollection_Indexed_for_Group1Var2*)getParentPointer_in_ICollection_Indexed_for_Group1Var2(
      (ICollection_Indexed_for_Group1Var2*)pICollection_Indexed_for_Group1Var2);
  return Count_in_BufferedCollection_Indexed_for_Group1Var2(parent);
}
void Foreach_in_BufferedCollection_Indexed_for_Group1Var2_override(void *pICollection_Indexed_for_Group1Var2,
    IVisitor__for__Indexed_for_Group1Var2* visitor)
{
  BufferedCollection_Indexed_for_Group1Var2* parent =
    (BufferedCollection_Indexed_for_Group1Var2*)getParentPointer_in_ICollection_Indexed_for_Group1Var2(
      (ICollection_Indexed_for_Group1Var2*)pICollection_Indexed_for_Group1Var2);
  Foreach_in_BufferedCollection_Indexed_for_Group1Var2(parent, visitor);
}

//-----------------------------------Indexed_for_Group1Var2---------------------------------------------------
