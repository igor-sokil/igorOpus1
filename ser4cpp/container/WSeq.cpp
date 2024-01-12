
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <string.h>

#include "header.h"
#include "WSeq.h"

WSeq_for_Uint16_t empty_in_WSeq_for_Uint16_t_static(void)
{
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver1(&wWSeq_for_Uint16_t);
  return wWSeq_for_Uint16_t;
}

void WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver1(WSeq_for_Uint16_t *pWSeq_for_Uint16_t)
{
  pWSeq_for_Uint16_t->buffer_ = NULL;
}

void WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint8_t* buffer, uint16_t length)
{
  HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver2(&(pWSeq_for_Uint16_t->hHasLength), length);
  pWSeq_for_Uint16_t->buffer_ = buffer;
}

void set_all_to_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint8_t value)
{
  memset(pWSeq_for_Uint16_t->buffer_, value, length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)));
}

void make_empty_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t)
{
  pWSeq_for_Uint16_t->buffer_ = NULL;
  (pWSeq_for_Uint16_t->hHasLength).m_length = 0;
}

uint16_t advance_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint16_t count)
{
  uint16_t num = min_for_Uint16_t(count, length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)));
  pWSeq_for_Uint16_t->buffer_ += num;
  (pWSeq_for_Uint16_t->hHasLength).m_length -= num;
  return num;
}

boolean put_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint8_t byte)
{
  if (length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)) == 0) return false;
  else
  {
    pWSeq_for_Uint16_t->buffer_[0] = byte;
    ++pWSeq_for_Uint16_t->buffer_;
    --(pWSeq_for_Uint16_t->hHasLength).m_length;
    return true;
  }
}

WSeq_for_Uint16_t skip_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint16_t count)
{
  uint16_t num = min_for_Uint16_t(count, length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)));
//    uint16_t num = ser4cpp::min(count, this->m_length);
//    return WSeq(this->buffer_ + num, this->m_length - num);
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pWSeq_for_Uint16_t->buffer_ + num,
      (pWSeq_for_Uint16_t->hHasLength).m_length - num);
  return wWSeq_for_Uint16_t;
}

WSeq_for_Uint16_t take_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint16_t count)
{
////    return WSeq(this->buffer_, ser4cpp::min(this->m_length, count));
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t, pWSeq_for_Uint16_t->buffer_,
      min_for_Uint16_t((pWSeq_for_Uint16_t->hHasLength).m_length, count));
  return wWSeq_for_Uint16_t;
}

RSeq_for_Uint16_t readonly_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t)
{
  RSeq_for_Uint16_t rRSeq_for_Uint16_t;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t,
      pWSeq_for_Uint16_t->buffer_,
      length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)));
////    return RSeq<L>(this->buffer_, this->length());
  return rRSeq_for_Uint16_t;
}

////    operator uint8_t* () const
////    {
////        return buffer_;
////    };

RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src)
{
  return transfer_fromMemcpy_in_WSeq_for_Uint16_t(pWSeq_for_Uint16_t, src);
}

RSeq_for_Uint16_t move_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src)
{
  return transfer_fromMemmove_in_WSeq_for_Uint16_t(pWSeq_for_Uint16_t, src);
}

////private:
////    template <memfunc_t mem_func>
////    RSeq<L> transfer_from(const RSeq<L>& src)
////    {
////        if (src.length() > this->length())
////        {
////            return RSeq<L>::empty();
////        }
////        else
////        {
////            const auto ret = this->readonly().take(src.length());
////            mem_func(buffer_, src, src.length());
////            this->advance(src.length());
////            return ret;
////        }
////    }
RSeq_for_Uint16_t transfer_fromMemcpy_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{transfer_fromMemcpy_in_WSeq_for_Uint16_t1"<<std::endl;
//  inspect_RSeq(src);
#endif
  if (length_in_HasLength_for_Uint16_t(&(src->hHasLength)) > length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)))
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}transfer_fromMemcpy_in_WSeq_for_Uint16_t1_"<<std::endl;
  decrement_stack_info();
#endif
    return empty_in_RSeq_for_Uint16_t_static();
  }
  else
  {
////            const auto ret = this->readonly().take(src.length());
////            mem_func(buffer_, src, src.length());
////            this->advance(src.length());
////            return ret;

    RSeq_for_Uint16_t ret1 = readonly_in_WSeq_for_Uint16_t(pWSeq_for_Uint16_t);
//#ifdef  LOG_INFO
//  inspect_RSeq(&ret1);
//#endif

    RSeq_for_Uint16_t ret2 = take_in_RSeq_for_Uint16_t(&ret1, length_in_HasLength_for_Uint16_t(&(src->hHasLength)));
//#ifdef  LOG_INFO
//  inspect_RSeq(&ret2);
//#endif

    memcpy(pWSeq_for_Uint16_t->buffer_, src->buffer_, length_in_HasLength_for_Uint16_t(&(src->hHasLength)));
    advance_in_WSeq_for_Uint16_t(pWSeq_for_Uint16_t, length_in_HasLength_for_Uint16_t(&(src->hHasLength)));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}transfer_fromMemcpy_in_WSeq_for_Uint16_t2_"<<std::endl;
  decrement_stack_info();
#endif
    return ret2;
  }
}

RSeq_for_Uint16_t transfer_fromMemmove_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src)
{
  if (length_in_HasLength_for_Uint16_t(&(src->hHasLength)) > length_in_HasLength_for_Uint16_t(&(pWSeq_for_Uint16_t->hHasLength)))
  {
    return empty_in_RSeq_for_Uint16_t_static();
  }
  else
  {
    RSeq_for_Uint16_t ret = readonly_in_WSeq_for_Uint16_t(pWSeq_for_Uint16_t);
    ret = take_in_RSeq_for_Uint16_t(&ret, length_in_HasLength_for_Uint16_t(&(src->hHasLength)));
    memmove(pWSeq_for_Uint16_t->buffer_, src, length_in_HasLength_for_Uint16_t(&(src->hHasLength)));
    advance_in_WSeq_for_Uint16_t(pWSeq_for_Uint16_t, length_in_HasLength_for_Uint16_t(&(src->hHasLength)));
    return ret;
  }
}
//--------------------------------------------------------------------------------------------------
/*
   WSeqTemplateUint8_t empty_in_WSeqTemplateUint8_t_static(void)
{
    WSeqTemplateUint8_t wWSeqTemplateUint8_t;
    WSeqTemplateUint8_t_in_WSeqTemplateUint8_tOver1(&wWSeqTemplateUint8_t);
    return wWSeqTemplateUint8_t;
}

    void WSeqTemplateUint8_t_in_WSeqTemplateUint8_tOver1(WSeqTemplateUint8_t *pWSeqTemplateUint8_t)
{
   pWSeqTemplateUint8_t->buffer_ = NULL;
}

    void WSeqTemplateUint8_t_in_WSeqTemplateUint8_tOver2(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, uint8_t* buffer, uint8_t length)
{
   HasLengthTemplateUint8_t_in_HasLengthTemplateUint8_tOver2(&(pWSeqTemplateUint8_t->hHasLength), length);
   pWSeqTemplateUint8_t->buffer_ = buffer;
}

    void set_all_to_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, uint8_t value)
{
    memset(pWSeqTemplateUint8_t->buffer_, value, length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)));
}

    void make_empty_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t)
{
    pWSeqTemplateUint8_t->buffer_ = NULL;
    (pWSeqTemplateUint8_t->hHasLength).m_length = 0;
}

    uint8_t advance_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, uint8_t count)
{
    uint8_t num = minTemplateUint8_t(count, length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)));
    pWSeqTemplateUint8_t->buffer_ += num;
    (pWSeqTemplateUint8_t->hHasLength).m_length -= num;
    return num;
}

    boolean put_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, uint8_t byte)
{
    if (length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)) == 0) return false;
    else
    {
        pWSeqTemplateUint8_t->buffer_[0] = byte;
        ++pWSeqTemplateUint8_t->buffer_;
        --(pWSeqTemplateUint8_t->hHasLength).m_length;
        return true;
    }
}

    WSeqTemplateUint8_t skip_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, uint8_t count)
{
    uint8_t num = minTemplateUint8_t(count, length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)));
//    uint16_t num = ser4cpp::min(count, this->m_length);
//    return WSeq(this->buffer_ + num, this->m_length - num);
    WSeqTemplateUint8_t wWSeqTemplateUint8_t;
    WSeqTemplateUint8_t_in_WSeqTemplateUint8_tOver2(&wWSeqTemplateUint8_t, pWSeqTemplateUint8_t->buffer_ + num,
                                                      (pWSeqTemplateUint8_t->hHasLength).m_length - num);
    return wWSeqTemplateUint8_t;
}

    WSeqTemplateUint8_t take_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, uint8_t count)
{
////    return WSeq(this->buffer_, ser4cpp::min(this->m_length, count));
    WSeqTemplateUint8_t wWSeqTemplateUint8_t;
    WSeqTemplateUint8_t_in_WSeqTemplateUint8_tOver2(&wWSeqTemplateUint8_t, pWSeqTemplateUint8_t->buffer_,
                                                      minTemplateUint8_t((pWSeqTemplateUint8_t->hHasLength).m_length, count));
    return wWSeqTemplateUint8_t;
}

    RSeqTemplateUint8_t readonly_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t)
{
    RSeqTemplateUint8_t rRSeqTemplateUint8_t;
    RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver2(&rRSeqTemplateUint8_t,
                                                       pWSeqTemplateUint8_t->buffer_,
                                                       length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)));
////    return RSeq<L>(this->buffer_, this->length());
    return rRSeqTemplateUint8_t;
}

////    operator uint8_t* () const
////    {
////        return buffer_;
////    };

    RSeqTemplateUint8_t copy_from_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, RSeqTemplateUint8_t *src)
{
    return transfer_fromMemcpy_in_WSeqTemplateUint8_t(pWSeqTemplateUint8_t, src);
}

    RSeqTemplateUint8_t move_from_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, RSeqTemplateUint8_t *src)
{
    return transfer_fromMemmove_in_WSeqTemplateUint8_t(pWSeqTemplateUint8_t, src);
}

////private:
////    template <memfunc_t mem_func>
////    RSeq<L> transfer_from(const RSeq<L>& src)
////    {
////        if (src.length() > this->length())
////        {
////            return RSeq<L>::empty();
////        }
////        else
////        {
////            const auto ret = this->readonly().take(src.length());
////            mem_func(buffer_, src, src.length());
////            this->advance(src.length());
////            return ret;
////        }
////    }
    RSeqTemplateUint8_t transfer_fromMemcpy_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, RSeqTemplateUint8_t *src)
{
    if (length_in_HasLengthTemplateUint8_t(&(src->hHasLength)) > length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)))
    {
        return empty_in_RSeqTemplateUint8_t_static();
    }
    else
    {
        RSeqTemplateUint8_t ret = readonly_in_WSeqTemplateUint8_t(pWSeqTemplateUint8_t);
        ret = take_in_RSeqTemplateUint8_t(&ret, length_in_HasLengthTemplateUint8_t(&(src->hHasLength)));
        memcpy(pWSeqTemplateUint8_t->buffer_, src, length_in_HasLengthTemplateUint8_t(&(src->hHasLength)));
        advance_in_WSeqTemplateUint8_t(pWSeqTemplateUint8_t, length_in_HasLengthTemplateUint8_t(&(src->hHasLength)));
        return ret;
    }
}

    RSeqTemplateUint8_t transfer_fromMemmove_in_WSeqTemplateUint8_t(WSeqTemplateUint8_t *pWSeqTemplateUint8_t, RSeqTemplateUint8_t *src)
{
    if (length_in_HasLengthTemplateUint8_t(&(src->hHasLength)) > length_in_HasLengthTemplateUint8_t(&(pWSeqTemplateUint8_t->hHasLength)))
    {
        return empty_in_RSeqTemplateUint8_t_static();
    }
    else
    {
        RSeqTemplateUint8_t ret = readonly_in_WSeqTemplateUint8_t(pWSeqTemplateUint8_t);
        ret = take_in_RSeqTemplateUint8_t(&ret, length_in_HasLengthTemplateUint8_t(&(src->hHasLength)));
        memmove(pWSeqTemplateUint8_t->buffer_, src, length_in_HasLengthTemplateUint8_t(&(src->hHasLength)));
        advance_in_WSeqTemplateUint8_t(pWSeqTemplateUint8_t, length_in_HasLengthTemplateUint8_t(&(src->hHasLength)));
        return ret;
    }
}
*/
