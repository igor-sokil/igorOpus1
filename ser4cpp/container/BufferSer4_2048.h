#ifndef SER4CPP_BufferSer4_2048_H
#define SER4CPP_BufferSer4_2048_H

#include "BufferSer4_Core.h"

typedef struct
{
  uint8_t bytes[2048];
  BufferSer4_Core bBufferSer4_Core;
} BufferSer4_2048;

void BufferSer4_2048_in_BufferSer4_2048Over1(BufferSer4_2048 *pBufferSer4_2048);
void BufferSer4_2048_in_BufferSer4_2048Over2(BufferSer4_2048 *pBufferSer4_2048, uint16_t length);
void BufferSer4_2048_in_BufferSer4_2048Over3(BufferSer4_2048 *pBufferSer4_2048, RSeq_for_Uint16_t *input);

#endif // SER4CPP_BufferSer4_H
