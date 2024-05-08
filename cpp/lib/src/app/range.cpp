
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "Range.h"

Range From_in_Range_static(uint16_t start, uint16_t stop)
{
  Range range;
  Range_in_RangeOver3(&range, start, stop);
  return range;
////        return Range(start, stop);
}

Range Invalid_in_Range_static(void)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Invalid_in_Range_static1"<<'\n';
#endif
  Range range;
  Range_in_RangeOver3(&range, 1, 0);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Invalid_in_Range_static_"<<'\n';
  decrement_stack_info();
#endif
  return range;
////        return Range(1, 0);
}

void Range_in_RangeOver1(Range *pRange)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Range_in_RangeOver1_1"<<'\n';
#endif
  pRange -> start = 1;
  pRange -> stop  = 0;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Range_in_RangeOver1__"<<'\n';
  decrement_stack_info();
#endif
}

uint32_t Count_in_Range(Range *pRange)
{
  return IsValid_in_Range(pRange) ? (pRange->stop - pRange->start + 1) : 0;
}

boolean Advance_in_Range(Range *pRange)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"*Advance_in_Range1"<<'\n';
#endif
  if (IsValid_in_Range(pRange))
  {
    if (pRange->start < pRange->stop)
    {
      ++pRange->start;
    }
    else
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*Advance_in_Range2"<<'\n';
#endif
      // make the range invalid
      pRange->start = 1;
      pRange->stop = 0;
    }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return true;
  }
  else
  {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return false;
  }
}

boolean Contains_in_Range(Range *pRange, uint16_t index)
{
  return (index >= pRange->start) && (index <= pRange->stop);
}

Range Intersection_in_Range(Range *pRange, Range* other)
{
  Range range;
  Range_in_RangeOver3(&range, ser4cpp_max_uint16_t(pRange->start, other->start), ser4cpp_min_uint16_t(pRange->stop, other->stop));
  return range;
}

uint16_t ser4cpp_max_uint16_t(uint16_t t1, uint16_t t2)
{
  if(t1 > t2) return t1;
  return t2;
}

uint16_t ser4cpp_min_uint16_t(uint16_t t1, uint16_t t2)
{
  if(t1 < t2) return t1;
  return t2;
}

Range Union_in_Range(Range *pRange, Range* other)
{
////        if (!this->IsValid())
  if (!IsValid_in_Range(pRange))
  {
    return (*other);
  }

  Range range;
  Range_in_RangeOver3(&range, ser4cpp_min_uint16_t(pRange->start, other->start), ser4cpp_max_uint16_t(pRange->stop, other->stop));
  return range;
}

boolean Equals_in_Range(Range *pRange, Range* other)
{
  return (other->start == pRange->start) && (other->stop == pRange->stop);
}

boolean IsValid_in_Range(Range *pRange)
{
  return pRange->start <= pRange->stop;
}

boolean IsOneByte_in_Range(Range *pRange)
{
  return IsValid_in_Range(pRange) && (pRange->start <= 255) && (pRange->stop <= 255);
}

void Range_in_RangeOver2(Range *pRange, uint16_t index_)
{
  pRange->start = index_;
  pRange->stop  = index_;
}

void Range_in_RangeOver3(Range *pRange, uint16_t start_, uint16_t stop_)
{
  pRange->start = start_;
  pRange->stop  = stop_;
}

