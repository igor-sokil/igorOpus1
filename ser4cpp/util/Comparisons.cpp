#include "header.h"
#include "Comparisons.h"

uint16_t min_for_Uint16_t(uint16_t a, uint16_t b)
{
  return (a < b) ? a : b;
}

////template <class T>
////inline T max(T a, T b)
uint16_t max_for_Uint16_t(uint16_t a, uint16_t b)
{
  return (a > b) ? a : b;
}

////template <class T>
////inline T bounded(T value, T minimum, T maximum)
uint16_t boundedTemplateUint16_t(uint16_t value, uint16_t minimum, uint16_t maximum)
{
  return min_for_Uint16_t(max_for_Uint16_t(value, minimum), maximum);
}

////template <class T>
////inline bool is_within_limits(T value, T min, T max)
boolean is_within_limitsTemplateUint16_t(uint16_t value, uint16_t min, uint16_t max)
{
  return (value >= min) && (value <= max);
}

////template <class T>
////bool float_equal(T a, T b, T epsillon = 1e-6)
boolean float_equalTemplateFloat(float a, float b, float epsillon)//// = 1e-6)
{
  float diff = a - b;
  if(diff < 0) diff = -diff;
  return diff <= epsillon;
}
//-----------------------------------------------------------------------
/*
 int8_t minTemplateUint8_t(uint8_t a, uint8_t b)
{
    return (a < b) ? a : b;
}

////template <class T>
////inline T max(T a, T b)
 int8_t maxTemplateUint8_t(uint8_t a, uint8_t b)
{
    return (a > b) ? a : b;
}

////template <class T>
////inline T bounded(T value, T minimum, T maximum)
 int8_t boundedTemplateUint8_t(uint8_t value, uint8_t minimum, uint8_t maximum)
{
    return minTemplateUint8_t(maxTemplateUint8_t(value, minimum), maximum);
}

////template <class T>
////inline bool is_within_limits(T value, T min, T max)
boolean is_within_limitsTemplateUint8_t(uint8_t value, uint8_t min, uint8_t max)
{
    return (value >= min) && (value <= max);
}
*/
