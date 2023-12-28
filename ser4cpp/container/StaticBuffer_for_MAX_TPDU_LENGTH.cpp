#include "header.h"
#include "StaticBuffer_for_MAX_TPDU_LENGTH.h"

RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver1(StaticBuffer_for_MAX_TPDU_LENGTH *pStaticBuffer)
{
  RSeq_for_Uint16_t rRSeq_for_Uint16_t;
////    return rseq_t(this->buffer, LENGTH);
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t, pStaticBuffer-> buffer, MAX_TPDU_LENGTH);
  return rRSeq_for_Uint16_t;
}

RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver2(StaticBuffer_for_MAX_TPDU_LENGTH *pStaticBuffer, uint16_t max_size)
{
////    return this->as_seq().take(max_size);
  RSeq_for_Uint16_t temp1 = as_seq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver1(pStaticBuffer);
  return  take_in_RSeq_for_Uint16_t(&temp1, max_size);
}

WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver1(StaticBuffer_for_MAX_TPDU_LENGTH *pStaticBuffer)
{
////    return wseq_t(this->buffer, LENGTH);
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pStaticBuffer-> buffer, MAX_TPDU_LENGTH);
  return wWSeq_for_Uint16_t;
}

WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver2(StaticBuffer_for_MAX_TPDU_LENGTH *pStaticBuffer, uint16_t max_size)
{
////    return wseq_t(this->buffer, ser4cpp::min(LENGTH, max_size));
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pStaticBuffer-> buffer, min_for_Uint16_t(MAX_TPDU_LENGTH, max_size));
  return wWSeq_for_Uint16_t;
}

uint16_t length_in_StaticBuffer_for_MAX_TPDU_LENGTH(void)
{
  return MAX_TPDU_LENGTH;
}
