#include "header.h"
#include "ParsedRequest.h"

  void  ParsedRequest_in_ParsedRequest(ParsedRequest *pParsedRequest, Addresses* addresses, APDUHeader* header, RSeq_for_Uint16_t* objects)
{
        pParsedRequest->addresses = *addresses;
        pParsedRequest->header = *header;
        pParsedRequest->objects = *objects;
    }
