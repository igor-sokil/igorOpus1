
#include "header.h"
#include "Message.h"

void  Message_in_MessageOver1(Message *pMessage)
{
 Addresses_in_AddressesOver1(&(pMessage->addresses));
 RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver1(&(pMessage->payload));
}

void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload)
{
  pMessage->addresses = *addresses;
  pMessage->payload = *payload;
}
