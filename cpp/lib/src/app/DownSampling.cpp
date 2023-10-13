#include "header.h"
#include "DownSampling.h"

boolean Apply_in_DownSampling_for_uint32(uint32_t src, uint32_t *target)
{
  if (src > (uint32_t)TARGET_MAX_for_uint32)
  {
////            target = TARGET_MAX;
    *target = TARGET_MAX_for_uint32;
    return true;
  }
//  else if (src < (uint32_t)TARGET_MIN_for_uint32)
//  {
////            target = TARGET_MIN;
//    *target = TARGET_MIN_for_uint32;
//    return true;
//  }
  else
  {
////            target = static_cast<Target>(src);
    *target = (uint32_t)src;
    return false;
  }
}

boolean Apply_in_DownSampling_for_uint16(uint16_t src, uint16_t *target)
{
  if (src > (uint16_t)TARGET_MAX_for_uint16)
  {
////            target = TARGET_MAX;
    *target = TARGET_MAX_for_uint16;
    return true;
  }
//  else if (src < (uint16_t)TARGET_MIN_for_uint16)
//  {
////            target = TARGET_MIN;
//    *target = TARGET_MIN_for_uint16;
//    return true;
//  }
  else
  {
////            target = static_cast<Target>(src);
    *target = (uint16_t)src;
    return false;
  }
}

boolean Apply_in_DownSampling_for_Float32(double src, float *target)
{
  if (src > TARGET_MAX_for_float)
  {
////            target = TARGET_MAX;
    *target = TARGET_MAX_for_float;
    return true;
  }
  else if (src < TARGET_MIN_for_float)
  {
////            target = TARGET_MIN;
    *target = TARGET_MIN_for_float;
    return true;
  }
  else
  {
////            target = static_cast<Target>(src);
    *target = (float)src;
    return false;
  }
}
