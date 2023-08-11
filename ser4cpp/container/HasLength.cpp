#include "header.h"
#include "HasLength.h"

//----------------------------HasLength_for_Uint16_t--------------------------------------
uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength)
{
  return pHasLength->m_length;
}

boolean is_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength)
{
  return pHasLength->m_length == 0;
}

boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength)
{
  return pHasLength->m_length != 0;
}

void HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver1(HasLength_for_Uint16_t *pHasLength)
{
  pHasLength->m_length = 0;
}

void HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver2(HasLength_for_Uint16_t *pHasLength, uint16_t length)
{
  pHasLength->m_length = length;
}
//----------------------------HasLength_for_Uint16_t--------------------------------------
//----------------------------HasLength_for_Uint32_t--------------------------------------

uint32_t length_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength)
{
  return pHasLength->m_length;
}

boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength)
{
  return pHasLength->m_length == 0;
}

boolean is_not_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength)
{
  return pHasLength->m_length != 0;
}

void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver1(HasLength_for_Uint32_t *pHasLength)
{
  pHasLength->m_length = 0;
}

void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length)
{
  pHasLength->m_length = length;
}
//----------------------------HasLength_for_Uint32_t--------------------------------------
