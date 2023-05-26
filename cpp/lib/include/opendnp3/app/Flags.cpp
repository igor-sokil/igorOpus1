#include "header.h"
#include "Flags.h"

  void Flags_In_FlagsOver1(Flags *pFlags)
{
  pFlags -> value = 0;
}
  void Flags_In_FlagsOver2(Flags *pFlags, uint8_t value)
{
  pFlags -> value = value;
}

  boolean IsSet_In_Flags(Flags *pFlags, uint8_t flag)
{
    return IsSetAny_In_Flags(pFlags, flag);
}
   void Set_In_Flags(Flags *pFlags, uint8_t flag)
{
    SetAny_In_Flags(pFlags, flag);
}

  boolean IsSetAny_In_Flags(Flags *pFlags, uint8_t flag) 
{
    return (pFlags->value & flag) != 0;
}

  void SetAny_In_Flags(Flags *pFlags, uint8_t flag)
{
    pFlags->value |= flag;
}
