#include  "header.h"
#include  <string.h>
#include  "Buffer.h"

void Buffer_in_BufferOver1(Buffer *pBuffer)
{
  pBuffer->data = NULL;
  pBuffer->length = 0;
}

void Buffer_in_BufferOver2(Buffer *pBuffer, uint8_t* data, uint16_t length)
{
  pBuffer->data = data;
  pBuffer->length = length;
}
