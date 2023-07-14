#include "header.h"
#include "Settable_for_WSeq.h"

void Settable_for_WSeq_t_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t)
{
// : value_is_set(false) {}
  pSettable_for_WSeq_t->value_is_set = false;
}

boolean is_set_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t)
{
  return pSettable_for_WSeq_t->value_is_set;
}

boolean is_empty_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t)
{
  return !pSettable_for_WSeq_t->value_is_set;
}

WSeq_for_Uint16_t get_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t)
{
  return pSettable_for_WSeq_t->value;
}

boolean pop_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t, WSeq_for_Uint16_t *output)
{
  if (pSettable_for_WSeq_t->value_is_set)
  {
    pSettable_for_WSeq_t->value_is_set = false;
    *output = pSettable_for_WSeq_t->value;
    return true;
  }
  else
  {
    return false;
  }
}

void clear_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t)
{
  pSettable_for_WSeq_t->value_is_set = false;
}

void set_in_Settable_for_WSeq_t(Settable_for_WSeq_t *pSettable_for_WSeq_t, WSeq_for_Uint16_t *value_)
{
  pSettable_for_WSeq_t->value = *value_;
  pSettable_for_WSeq_t->value_is_set = true;
}
