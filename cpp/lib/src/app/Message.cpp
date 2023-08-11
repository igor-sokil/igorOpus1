#include "header.h"
#include "Message.h"

void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload)
{
  pMessage->addresses = *addresses;
  pMessage->payload = *payload;
}
