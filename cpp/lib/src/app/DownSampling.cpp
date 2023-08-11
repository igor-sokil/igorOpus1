#include "header.h"
#include "DownSampling.h"

boolean Apply_in_DownSampling_for_uint32(double src, uint32_t *target)
{
  if (src > TARGET_MAX_for_double)
  {
////            target = TARGET_MAX;
    *target = TARGET_MAX_for_uint32;
    return true;
  }
  else if (src < TARGET_MIN_for_double)
  {
////            target = TARGET_MIN;
    *target = TARGET_MIN_for_uint32;
    return true;
  }
  else
  {
////            target = static_cast<Target>(src);
    *target = (uint32_t)src;
    return false;
  }
}

boolean Apply_in_DownSampling_for_uint16(double src, uint16_t *target)
{
  if (src > TARGET_MAX_for_double)
  {
////            target = TARGET_MAX;
    *target = TARGET_MAX_for_uint16;
    return true;
  }
  else if (src < TARGET_MIN_for_double)
  {
////            target = TARGET_MIN;
    *target = TARGET_MIN_for_uint16;
    return true;
  }
  else
  {
////            target = static_cast<Target>(src);
    *target = (uint16_t)src;
    return false;
  }
}

boolean Apply_in_DownSampling_for_Float32(double src, float *target)
{
  if (src > TARGET_MAX_for_double)
  {
////            target = TARGET_MAX;
    *target = TARGET_MAX_for_float;
    return true;
  }
  else if (src < TARGET_MIN_for_double)
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
