#include "header.h"
#include "HasLength.h"

void __HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
boolean __is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);

void __HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length)
{
  pHasLength->m_length = length;
}

boolean __is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength)
{
    return pHasLength->m_length == 0;
}
