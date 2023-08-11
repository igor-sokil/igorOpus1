
#include <QApplication>
#include "header.h"
#include "BufferSer4.h"
#include "HexConversions.h"

char to_hex_char_in_HexConversions(char c)
{
  return (c > 9) ? ('A' + (c - 10)) : ('0' + c);
}

std::string byte_to_hex_in_HexConversions(uint8_t b)
{
  std::ostringstream oss;
  oss << to_hex_char_in_HexConversions((b & 0xf0) >> 4) << to_hex_char_in_HexConversions(b & 0xf);
  return oss.str();
}

std::string to_hex_in_HexConversions(const uint8_t* buffer, size_t length, bool spaced)
{
  std::ostringstream oss;
  size_t last = length - 1;
  for (size_t i = 0; i < length; i++)
  {
    char c = buffer[i];
    oss << to_hex_char_in_HexConversions((c & 0xf0) >> 4) << to_hex_char_in_HexConversions(c & 0xf);
    if (spaced && i != last)oss << " ";
  }
  return oss.str();
}

std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced)
{
//    uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
  return to_hex_in_HexConversions(buffer->buffer_, length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)), /*buffer.length(),*/ spaced);
}

std::string increment_hex_in_HexConversions(uint8_t start, uint16_t count, bool spaced)
{
////        Buffer buffer(count);
  BufferSer4 buffer;
  BufferSer4_in_BufferSer4Over2(&buffer, count);

  for (uint16_t i = 0; i < count; ++i)
  {
//    WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////            buffer.as_wslice()[i] = start;
    WSeq_for_Uint16_t temp = as_wslice_in_BufferSer4(&buffer);
    temp.buffer_[i] = start;
    ++start;
  }
//    RSeq_for_Uint16_t as_rslice_in_BufferSer4(BufferSer4 *pBufferSer4);
//    std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////        return to_hex(buffer.as_rslice(), spaced);
  RSeq_for_Uint16_t temp1 = as_rslice_in_BufferSer4(&buffer);
  return to_hex_in_HexConversionsOver2(&temp1, spaced);
}
