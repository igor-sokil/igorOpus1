#include "header.h"
#include "StaticBuffer.h"

   RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_LENGTH10Over1(StaticBuffer_for_LENGTH10 *pStaticBuffer_for_LENGTH10)
{
    RSeq_for_Uint16_t rRSeq_for_Uint16_t;
////    return rseq_t(this->buffer, LENGTH);
    RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t, pStaticBuffer_for_LENGTH10-> buffer, LENGTH10);
    return rRSeq_for_Uint16_t;
}

    RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_LENGTH10Over2(StaticBuffer_for_LENGTH10 *pStaticBuffer_for_LENGTH10, uint16_t max_size)
{
////    return this->as_seq().take(max_size);
   RSeq_for_Uint16_t temp1 = as_seq_in_StaticBuffer_for_LENGTH10Over1(pStaticBuffer_for_LENGTH10);
   return  take_in_RSeq_for_Uint16_t(&temp1, max_size);
}

   WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LENGTH10Over1(StaticBuffer_for_LENGTH10 *pStaticBuffer_for_LENGTH10)
{
////    return wseq_t(this->buffer, LENGTH);
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pStaticBuffer_for_LENGTH10-> buffer, LENGTH10);
  return wWSeq_for_Uint16_t;
}

   WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LENGTH10Over2(StaticBuffer_for_LENGTH10 *pStaticBuffer_for_LENGTH10, uint16_t max_size)
{
////    return wseq_t(this->buffer, ser4cpp::min(LENGTH, max_size));
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pStaticBuffer_for_LENGTH10-> buffer, min_for_Uint16_t(LENGTH10, max_size));
  return wWSeq_for_Uint16_t;
}

   uint16_t length_in_StaticBuffer_for_LENGTH10(void) 
{
    return LENGTH10;
}
