#ifndef OPENDNP3_EVENTWRITERS_H
#define OPENDNP3_EVENTWRITERS_H

#include "IEventWriteHandler.h"
#include "DNP3Serializer.h"
#include "HeaderWriter_for_OctetString.h"

  uint16_t Write_in_EventWriters_static(uint8_t firstSize, HeaderWriter* writer, IEventCollection_for_OctetString* items);

#endif
