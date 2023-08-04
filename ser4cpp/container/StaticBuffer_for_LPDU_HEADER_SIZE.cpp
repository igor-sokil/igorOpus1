#include "header.h"
#include "StaticBuffer_for_LPDU_HEADER_SIZE.h"

RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver1(StaticBuffer_for_LPDU_HEADER_SIZE *pStaticBuffer)
{
  RSeq_for_Uint16_t rRSeq_for_Uint16_t;
////    return rseq_t(this->buffer, LENGTH);
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t, pStaticBuffer-> buffer, LPDU_HEADER_SIZE);
  return rRSeq_for_Uint16_t;
}

RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver2(StaticBuffer_for_LPDU_HEADER_SIZE *pStaticBuffer, uint16_t max_size)
{
////    return this->as_seq().take(max_size);
  RSeq_for_Uint16_t temp1 = as_seq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver1(pStaticBuffer);
  return  take_in_RSeq_for_Uint16_t(&temp1, max_size);
}

WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver1(StaticBuffer_for_LPDU_HEADER_SIZE *pStaticBuffer)
{
////    return wseq_t(this->buffer, LENGTH);
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pStaticBuffer-> buffer, LPDU_HEADER_SIZE);
  return wWSeq_for_Uint16_t;
}

WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver2(StaticBuffer_for_LPDU_HEADER_SIZE *pStaticBuffer, uint16_t max_size)
{
////    return wseq_t(this->buffer, ser4cpp::min(LENGTH, max_size));
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pStaticBuffer-> buffer, min_for_Uint16_t(LPDU_HEADER_SIZE, max_size));
  return wWSeq_for_Uint16_t;
}

uint16_t length_in_StaticBuffer_for_LPDU_HEADER_SIZE(void)
{
  return LPDU_HEADER_SIZE;
}
