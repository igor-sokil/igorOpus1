
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <math.h>
#include "header.h"
#include "SerializationTemplates.h"
float to_Float32_static(uint32_t value);
uint32_t to_uint32_static(float value);

//---------------------------------------uint8_t-----------------------------------
////class UInt8
////{
////public:
boolean read_from_in_UInt8_static(RSeq_for_Uint16_t *input, uint8_t *out)
{
////        if (input.length() < size_in_UInt8) return false;
  if(length_in_HasLength_for_Uint16_t(&(input->hHasLength)) < size_in_UInt8) return false;

  *out = read_in_UInt8_static(input->buffer_);
////        input.advance(size);
  advance_in_RSeq_for_Uint16_t(input, size_in_UInt8);
  return true;
}

boolean write_to_in_UInt8_static(WSeq_for_Uint16_t *dest, uint8_t value)
{
////        if (dest.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(dest->hHasLength)) < size_in_UInt8) return false;

  write_in_UInt8_static(dest->buffer_, value);
////        dest.advance(size);
  advance_in_WSeq_for_Uint16_t(dest, size_in_UInt8);
  return true;
}


////    typedef uint8_t type_t;

////private:
uint8_t read_in_UInt8_static(uint8_t* start)
{
  return (*start);
}

void write_in_UInt8_static(uint8_t* start, uint8_t value)
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*write_in_UInt8_static = "<<(uint32_t)start<<"->"<<(uint16_t)value<<'\n';
#endif
  *(start) = value;
}
////};
//---------------------------------------uint8_t-----------------------------------

//---------------------------------------uint16_t-----------------------------------
////template <class T, uint8_t B0, uint8_t B1>
////class Bit16
////{
////    static_assert(sizeof(T) == 2, "bad size");
////    static_assert((B0 < sizeof(T))&& (B1 < sizeof(T))&& (B0 != B1), "bad config");

////public:
boolean write_to_in_UInt16_static(WSeq_for_Uint16_t *dest, uint16_t value)
{
//        if (dest.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(dest->hHasLength)) < size_in_UInt16) return false;

  write_in_UInt16_static(dest->buffer_, value);
////        dest.advance(size);
  advance_in_WSeq_for_Uint16_t(dest, size_in_UInt16);
  return true;
}

boolean read_from_in_UInt16_static(RSeq_for_Uint16_t *input, uint16_t *out)
{
////        if (input.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(input->hHasLength)) < size_in_UInt16) return false;

  *out = read_in_UInt16_static(input->buffer_);
////        input.advance(size);
  advance_in_RSeq_for_Uint16_t(input, size_in_UInt16);
  return true;
}

////    typedef T type_t;

////    const static size_t size = sizeof(T);
////    const static T max_value;
////    const static T min_value;

////private:
uint16_t read_in_UInt16_static(uint8_t* data)
{
////        return (static_cast<T>(data[B0]) << 0) | (static_cast<T>(data[B1]) << 8);
  return (((uint16_t)(data[0])) << 0) | (((uint16_t)(data[1])) << 8);
}

void write_in_UInt16_static(uint8_t* data, uint16_t value)
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*write_in_UInt16_static = "<<(uint32_t)data<<"->"<<(uint16_t)value<<'\n';
#endif
  data[0] = (uint8_t)(value & 0xFF);
  data[1] = (uint8_t)((value >> 8) & 0xFF);
}
////};

//---------------------------------------uint16_t-----------------------------------

//---------------------------------------uint32_t-----------------------------------
////template <class T, uint8_t B0, uint8_t B1>
////const T Bit16<T, B0, B1>::max_value = std::numeric_limits<T>::max();

////template <class T, uint8_t B0, uint8_t B1>
////const T Bit16<T, B0, B1>::min_value = std::numeric_limits<T>::min();

////template <class T, uint8_t B0, uint8_t B1, uint8_t B2, uint8_t B3>
////class Bit32
////{
////    static_assert(sizeof(T) == 4, "bad size");
////    static_assert((B0 < sizeof(T))&& (B1 < sizeof(T))&& (B2 < sizeof(T))&& (B3 < sizeof(T)), "bad config");

////public:
boolean write_to_in_UInt32_static(WSeq_for_Uint16_t *dest, uint32_t value)
{
////        if (dest.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(dest->hHasLength)) < size_in_UInt32) return false;

  write_in_UInt32_static(dest->buffer_, value);
////        dest.advance(size);
  advance_in_WSeq_for_Uint16_t(dest, size_in_UInt32);
  return true;
}
boolean read_from_in_UInt32_static(RSeq_for_Uint16_t *input, uint32_t *out)
{
////        if (input.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(input->hHasLength)) < size_in_UInt32) return false;

  *out = read_in_UInt32_static(input->buffer_);
////        input.advance(size);
  advance_in_RSeq_for_Uint16_t(input, size_in_UInt32);
  return true;
}

////    typedef T type_t;

////    const static size_t size = sizeof(T);
////    const static T max_value;
////    const static T min_value;

////private:
uint32_t read_in_UInt32_static(uint8_t* data)
{
  return	(((uint32_t)(data[0])) << 0) |
          (((uint32_t)(data[1])) << 8) |
          (((uint32_t)(data[2])) << 16) |
          (((uint32_t)(data[3])) << 24);
}

void write_in_UInt32_static(uint8_t* data, uint32_t value)
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*write_in_UInt32_static = "<<(uint32_t)data<<"->"<<value<<'\n';
#endif
  data[0] = (uint8_t)(value & 0xFF);
  data[1] = (uint8_t)((value >> 8) & 0xFF);
  data[2] = (uint8_t)((value >> 16) & 0xFF);
  data[3] = (uint8_t)((value >> 24) & 0xFF);
}
//---------------------------------------UInt32_t-----------------------------------
//---------------------------------------UInt48_t-----------------------------------
boolean read_from_in_UInt48_static(RSeq_for_Uint16_t *input, uint64_t *out)
{
////        if (input.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(input->hHasLength)) < size_in_UInt48) return false;

  *out = read_in_UInt48_static(input->buffer_);
////        input.advance(size);
  advance_in_RSeq_for_Uint16_t(input, size_in_UInt48);
  return true;
}

boolean write_to_in_UInt48_static(WSeq_for_Uint16_t *dest, uint64_t value)
{
////        if (dest.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(dest->hHasLength)) < size_in_UInt48) return false;

  write_in_UInt48_static(dest->buffer_, value);
////        dest.advance(size);
  advance_in_WSeq_for_Uint16_t(dest, size_in_UInt48);
  return true;
}

uint64_t read_in_UInt48_static(uint8_t* data)
{
  return (uint64_t) ((((uint64_t)(data[0])) << 0) |
                     (((uint64_t)(data[1])) << 8)  |
                     (((uint64_t)(data[2])) << 16) |
                     (((uint64_t)(data[3])) << 24) |
                     (((uint64_t)(data[4])) << 32) |
                     (((uint64_t)(data[5])) << 40));
}

void write_in_UInt48_static(uint8_t* data, uint64_t value)
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*write_in_UInt48_static = "<<(uint32_t)data<<"->"<<value<<'\n';
#endif
  if (value > 281474976710655ULL)
  {
    value = 281474976710655ULL;////UInt48Type(max_value);
  }
  data[0] = (uint8_t)(value & 0xFF);
  data[1] = (uint8_t)((value >> 8) & 0xFF);
  data[2] = (uint8_t)((value >> 16) & 0xFF);
  data[3] = (uint8_t)((value >> 24) & 0xFF);
  data[4] = (uint8_t)((value >> 32) & 0xFF);
  data[5] = (uint8_t)((value >> 40) & 0xFF);
}
/*
    inline static bool read_from(rseq_t& input, UInt48Type& out)
    {
        if (input.length() < size) return false;

        out = read(input);
        input.advance(size);
        return true;
    }

    static bool write_to(wseq_t& dest, UInt48Type value)
    {
        if (dest.length() < size) return false;

        write(dest, value);
        dest.advance(size);
        return true;
    }

    typedef UInt48Type type_t;
    const static size_t size = 6;
    const static uint64_t min_value = 0;
    const static uint64_t max_value = 281474976710655ULL; // 2^48 -1

    static inline UInt48Type read(const uint8_t* data)
    {
        return UInt48Type(
                    (static_cast<uint64_t>(data[B0]) << 0) |
                    (static_cast<uint64_t>(data[B1]) << 8) |
                    (static_cast<uint64_t>(data[B2]) << 16) |
                    (static_cast<uint64_t>(data[B3]) << 24) |
                    (static_cast<uint64_t>(data[B4]) << 32) |
                    (static_cast<uint64_t>(data[B5]) << 40));
    }

    static inline void write(uint8_t* data, UInt48Type value)
    {
        if (value > max_value)
        {
            value = UInt48Type(max_value);
        }

        data[B0] = static_cast<uint8_t>(value & 0xFF);
        data[B1] = static_cast<uint8_t>((value >> 8) & 0xFF);
        data[B2] = static_cast<uint8_t>((value >> 16) & 0xFF);
        data[B3] = static_cast<uint8_t>((value >> 24) & 0xFF);
        data[B4] = static_cast<uint8_t>((value >> 32) & 0xFF);
        data[B5] = static_cast<uint8_t>((value >> 40) & 0xFF);
    }
*/
//---------------------------------------UInt48_t-----------------------------------
//---------------------------------------Float32-----------------------------------
boolean read_from_in_Float32_static(RSeq_for_Uint16_t *input, float *out)
{
  {
    uint32_t value;
////        if(UInt32::read_from(input, value))
    if(read_from_in_UInt32_static(input, &value))
    {
      float temp = to_Float32_static(value);
      *out = temp;
      return true;
    }

    return false;
  }
}

float to_Float32_static(uint32_t value)
{
  // Extract the required values
  boolean sign = (value & 0x80000000) != 0;
////        uint8_t exponent = static_cast<uint8_t>((value >> 23) & 0xFF);
  uint8_t exponent = (uint8_t)((value >> 23) & 0xFF);
  uint32_t mantissa = value & 0x7FFFFF;

  // Check special cases
  if(exponent == 0xFF)
  {
    if(mantissa != 0)
    {
      return 0.0;////std::numeric_limits<float>::quiet_NaN();
    }
    else
    {
      if(!sign)
      {
        return 0.0;////std::numeric_limits<float>::infinity();
      }
      else
      {
        return 0.0;////-std::numeric_limits<float>::infinity();
      }

    }
  }
  if(exponent == 0 && mantissa == 0)
  {
    return 0.0f;
  }

  // Build the actual value
////        auto weighted_mantissa = static_cast<float>(mantissa)/(uint32_t{1} << 23);
  float weighted_mantissa = ((float)(mantissa))/(((uint32_t)1) << 23);
  float result;
  if(exponent == 0)
  {
////            result = std::ldexp(weighted_mantissa, 2 - (uint16_t{1} << 8));
    result = ldexp( weighted_mantissa, 2 - (((uint16_t)1) << 8) );
  }
  else
  {
////            result = std::ldexp(1.0f + weighted_mantissa, exponent - 127);
    result = ldexp( 1.0f + weighted_mantissa, exponent - 127 );
  }

  // Adjust the sign
  if(sign)
  {
    result = -result;
  }

  return result;
}

boolean write_to_in_Float32_static(WSeq_for_Uint16_t* dest, float value)
{
////        if (dest.length() < size) return false;
  if(length_in_HasLength_for_Uint16_t(&(dest->hHasLength)) < size_in_Float32) return false;

////        const auto uint32_value = to_uint32(value);
  uint32_t uint32_value = to_uint32_static(value);
////        return UInt32::write_to(dest, uint32_value);
  return write_to_in_UInt32_static(dest, uint32_value);
}

uint32_t to_uint32_static(float value)
{
  union FloatUnion
  {
    uint32_t bytes;
    float f;
  } floatUnion;
  floatUnion.f = value;
  uint8_t expon = (uint8_t)((floatUnion.bytes >> 23) & 0xFF);
  boolean sign = (floatUnion.bytes & 0x80000000) != 0;

  uint32_t encoded_value = 0;

////        if (std::isnan(value))

  if(expon == 0xFF)////((uint32_t)(value&0xFF000000)) == 0xFF000000)
  {
    // NaN has all exponent bit set to 1, and mantissa with a least a 1. Sign bit is ignored.
    // Here, I use x86 qNaN (because libiec61850 simply cast the value into a double)
    encoded_value = 0x7F800001;
  }

////        else if (std::isinf(value))
////        {
  // Infinite has all exponent bit set to 1, and mantissa filled with zeroes. Sign bit determines
  // which infinite it represents
////            encoded_value = 0x7F800000;
////        }

  else if (value != 0.0f)
  {
    int integral_part;
////            float fraction_part = std::frexp(std::abs(value), &integral_part);
    float fraction_part = frexp( fabs(value), &integral_part );

    uint16_t expon1 = integral_part + 126;
////            encoded_value |= (static_cast<uint32_t>(exponent) & 0xFF) << 23;
////            encoded_value |= static_cast<uint32_t>(fraction_part * (uint32_t{1} << 24)) & 0x007FFFFF;
    encoded_value |= (((uint32_t)(expon1)) & 0xFF) << 23;
    encoded_value |= (uint32_t)(fraction_part * (((uint32_t)1) << 24)) & 0x007FFFFF;
  }

////        if (std::signbit(value))
  if(sign)////((uint32_t)(value&0x80000000)) == 0x80000000)
  {
////            encoded_value |= uint32_t{1} << 31;
    encoded_value |= (((uint32_t)1) << 31);
  }

  return encoded_value;
}

//---------------------------------------Float32-----------------------------------

