#include "header.h"
#include "SequenceNum.h"

uint8_t Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(uint8_t seq)
{
  return (seq + 1) % Modulus16;
}

uint8_t Get_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16)
{
  return pSequenceNum_for_uint8_Modulus16->seq;
}

////    operator uint8_t() const
////    {
////        return this->seq;
////    }
////
void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16)
{
  pSequenceNum_for_uint8_Modulus16->seq = 0;
}

////    SequenceNum(T value) : seq(value) {}
void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t value)
{
  pSequenceNum_for_uint8_Modulus16->seq = value;
}

boolean Equals_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t other)
{
  return other == pSequenceNum_for_uint8_Modulus16->seq;
}

void Increment_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16)
{
  pSequenceNum_for_uint8_Modulus16->seq = Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(pSequenceNum_for_uint8_Modulus16->seq);
}

void Reset_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16)
{
  pSequenceNum_for_uint8_Modulus16->seq = 0;
}

SequenceNum_for_uint8_Modulus16 Next_in_SequenceNum_for_uint8_Modulus16Over1(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16)
{
  SequenceNum_for_uint8_Modulus16 sSequenceNum_for_uint8_Modulus16;
//     uint8_t Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(uint8_t seq);
//   void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t value)
////        return SequenceNum(Next(seq));
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16(&sSequenceNum_for_uint8_Modulus16,
      Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(pSequenceNum_for_uint8_Modulus16->seq));
  return sSequenceNum_for_uint8_Modulus16;
}
