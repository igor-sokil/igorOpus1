#include "header.h"
#include "Settable_for_LinkBroadcastAddress.h"

void Settable_for_LinkBroadcastAddress_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress)
{
// : value_is_set(false) {}
  pSettable_for_LinkBroadcastAddress->value_is_set = false;
}

boolean is_set_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress)
{
  return pSettable_for_LinkBroadcastAddress->value_is_set;
}

boolean is_empty_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress)
{
  return !pSettable_for_LinkBroadcastAddress->value_is_set;
}

uint16_t get_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress)
{
  return pSettable_for_LinkBroadcastAddress->value;
}

boolean pop_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress, uint16_t *output)
{
  if (pSettable_for_LinkBroadcastAddress->value_is_set)
  {
    pSettable_for_LinkBroadcastAddress->value_is_set = false;
    *output = pSettable_for_LinkBroadcastAddress->value;
    return true;
  }
  else
  {
    return false;
  }
}

void clear_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress)
{
  pSettable_for_LinkBroadcastAddress->value_is_set = false;
}

void set_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress, uint16_t *value_)
{
  pSettable_for_LinkBroadcastAddress->value = *value_;
  pSettable_for_LinkBroadcastAddress->value_is_set = true;
}
