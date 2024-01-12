
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

BufferSer4 buffer_in_HexConversions;
BufferSer4* from_hex_in_HexConversions(std::string& hex)
{
  // create a copy of the string without space
  std::string copy = remove_spaces_in_HexConversions(hex);

  //annoying when you accidentally put an 'O' instead of zero '0'
////       if (copy.find_first_of("oO") != std::string::npos)
////        {
////            throw std::invalid_argument("Sequence contains 'o' or 'O'");
////        }

////        if (copy.size() % 2 != 0)
////        {
////            throw std::invalid_argument(hex);
////        }

  auto num_bytes = copy.size() / 2;

////       BufferSer4* buffer = std::make_unique<BufferSer4>(num_bytes);
  BufferSer4_in_BufferSer4Over2(&buffer_in_HexConversions, num_bytes);

  for (size_t index = 0, pos = 0; pos < copy.size(); ++index, pos += 2)
  {
    uint32_t val;
    std::stringstream ss;
    ss << std::hex << copy.substr(pos, 2);
    if ((ss >> val).fail())
    {
////                throw std::invalid_argument(hex);
    }
//WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////            buffer->as_wslice()[index] = static_cast<uint8_t>(val);
    WSeq_for_Uint16_t tmp = as_wslice_in_BufferSer4(&buffer_in_HexConversions);
    tmp.buffer_[index] = (uint8_t)(val);
  }

  return &buffer_in_HexConversions;
}

void remove_spaces_in_place_in_HexConversions(std::string& hex)
{
  size_t pos = hex.find_first_of(' ');
  if (pos != std::string::npos)
  {
    hex.replace(pos, 1, "");
    remove_spaces_in_place_in_HexConversions(hex);
  }
}

std::string remove_spaces_in_HexConversions(std::string& hex)
{
  std::string copy(hex);
  remove_spaces_in_place_in_HexConversions(copy);
  return copy;
}
