#ifndef SER4CPP_BufferSer4_292_H
#define SER4CPP_BufferSer4_292_H

#include "BufferSer4_Core.h"

typedef struct
{
  uint8_t bytes[292];
  BufferSer4_Core bBufferSer4_Core;
} BufferSer4_292;

void BufferSer4_292_in_BufferSer4_292Over1(BufferSer4_292 *pBufferSer4_292);
void BufferSer4_292_in_BufferSer4_292Over2(BufferSer4_292 *pBufferSer4_292, uint16_t length);
void BufferSer4_292_in_BufferSer4_292Over3(BufferSer4_292 *pBufferSer4_292, RSeq_for_Uint16_t *input);

#endif // SER4CPP_BufferSer4_H
