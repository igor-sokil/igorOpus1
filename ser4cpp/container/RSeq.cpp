#include "header.h"
#include "RSeq.h"
#include <string.h>

boolean equals_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, RSeq_for_Uint16_t *rhs)
{
  if ((pRSeq->hHasLength).m_length == (rhs->hHasLength).m_length)
  {
    return (memcmp(pRSeq->buffer_, rhs->buffer_, (pRSeq->hHasLength).m_length) == 0);
  }
  else
  {
    return false;
  }
}

RSeq_for_Uint16_t empty_in_RSeq_for_Uint16_t_static(void)
{
  RSeq_for_Uint16_t rRSeq;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq, NULL, 0);
  return rRSeq;
}

void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver1(RSeq_for_Uint16_t *pRSeq)
{
  HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver2(&(pRSeq->hHasLength), 0);
}

void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(RSeq_for_Uint16_t *pRSeq, uint8_t * buffer, uint16_t length)
{
  HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver2(&(pRSeq->hHasLength), length);
  pRSeq->buffer_ = buffer;
}

void make_empty_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq)
{
  pRSeq->buffer_ = NULL;
  (pRSeq->hHasLength).m_length = 0;
}

RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count)
{
  RSeq_for_Uint16_t rRSeq;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq, pRSeq->buffer_,
      (count < length_in_HasLength_for_Uint16_t(&(pRSeq->hHasLength))) ? count : length_in_HasLength_for_Uint16_t(&(pRSeq->hHasLength)));
  return rRSeq;
////    return RSeq(this->buffer_, (count < this->length()) ? count : this->length());
}

RSeq_for_Uint16_t skip_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count)
{
  RSeq_for_Uint16_t rRSeq;
////    auto num = ser4cpp::min(this->length(), count);
  uint16_t num = min_for_Uint16_t(length_in_HasLength_for_Uint16_t(&(pRSeq->hHasLength)), count);
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq, pRSeq->buffer_ + num, length_in_HasLength_for_Uint16_t(&(pRSeq->hHasLength)) - num);
////    return RSeq(this->buffer_ + num, this->length() - num);
  return rRSeq;
}

void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count)
{
////    auto num = ser4cpp::min(this->length(), count);
  uint16_t num = min_for_Uint16_t(length_in_HasLength_for_Uint16_t(&(pRSeq->hHasLength)), count);
////    this->buffer_ += num;
  pRSeq->buffer_ += num;
////    this->m_length -= num;
  (pRSeq->hHasLength).m_length -= num;
}
//-----------------------------------------------------------------------------------------------------
/*
     RSeqTemplateUint8_t empty_in_RSeqTemplateUint8_t_static(void)
{
    RSeqTemplateUint8_t rRSeq;
    RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver2(&rRSeq, NULL, 0);
    return rRSeq;
}

    void RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver1(RSeqTemplateUint8_t *pRSeq)
{
  HasLengthTemplateUint8_t_in_HasLengthTemplateUint8_tOver2(&(pRSeq->hHasLength), 0);
}

    void RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver2(RSeqTemplateUint8_t *pRSeq, uint8_t * buffer, uint8_t length)
{
  HasLengthTemplateUint8_t_in_HasLengthTemplateUint8_tOver2(&(pRSeq->hHasLength), length);
  pRSeq->buffer_ = buffer;
}

    void make_empty_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq)
{
    pRSeq->buffer_ = NULL;
    (pRSeq->hHasLength).m_length = 0;
}

    RSeqTemplateUint8_t take_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq, uint8_t count)
{
    RSeqTemplateUint8_t rRSeq;
    RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver2(&rRSeq, pRSeq->buffer_,
                      (count < length_in_HasLengthTemplateUint8_t(&(pRSeq->hHasLength))) ? count : length_in_HasLengthTemplateUint8_t(&(pRSeq->hHasLength)));
    return rRSeq;
////    return RSeq(this->buffer_, (count < this->length()) ? count : this->length());
}

    RSeqTemplateUint8_t skip_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq, uint8_t count)
{
    RSeqTemplateUint8_t rRSeq;
////    auto num = ser4cpp::min(this->length(), count);
    uint8_t num = minTemplateUint8_t(length_in_HasLengthTemplateUint8_t(&(pRSeq->hHasLength)), count);
    RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver2(&rRSeq, pRSeq->buffer_ + num, length_in_HasLengthTemplateUint8_t(&(pRSeq->hHasLength)) - num);
////    return RSeq(this->buffer_ + num, this->length() - num);
    return rRSeq;
}

    void advance_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq, uint8_t count)
{
////    auto num = ser4cpp::min(this->length(), count);
    uint8_t num = minTemplateUint8_t(length_in_HasLengthTemplateUint8_t(&(pRSeq->hHasLength)), count);
////    this->buffer_ += num;
    pRSeq->buffer_ += num;
////    this->m_length -= num;
    (pRSeq->hHasLength).m_length -= num;
}
*/
