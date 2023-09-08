#include <QtWidgets>
#include "header.h"

#include <string.h>

//-------------------RSeq------------------------
Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16(Memory_RSeq_for_Uint16 *pMemory_RSeq_for_Uint16, uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t);

static const 
void *title_RSeq[] =
{
  (void*)"RSeq"
};

Memory_RSeq_for_Uint16* pMemory_RSeq_for_Uint16_1;
Memory_RSeq_for_Uint16* pMemory_RSeq_for_Uint16_2;
Memory_RSeq_for_Uint16* pMemory_RSeq_for_Uint16_3;

static Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16_1;
static Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16_2;
static Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16_3;

Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16_1(uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t)
{
 return MEMORY_RSeq_for_Uint16(&mMemory_RSeq_for_Uint16_1, titleSpace, pRSeq_for_Uint16_t);
}
Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16_2(uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t)
{
 return MEMORY_RSeq_for_Uint16(&mMemory_RSeq_for_Uint16_2, titleSpace, pRSeq_for_Uint16_t);
}
Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16_3(uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t)
{
 return MEMORY_RSeq_for_Uint16(&mMemory_RSeq_for_Uint16_3, titleSpace, pRSeq_for_Uint16_t);
}

Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16(Memory_RSeq_for_Uint16 *pMemory_RSeq_for_Uint16, uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 RSeq_for_Uint16_t* pRSeq_for_Uint16_t;
 void* title;

 RSeq_for_Uint16_t rseq;
 uint8_t buffer4rseq[100];
} Memory_RSeq_for_Uint16;
*/

 pMemory_RSeq_for_Uint16->counter_inspect++;
 pMemory_RSeq_for_Uint16->titleSpace = titleSpace;
 pMemory_RSeq_for_Uint16->pRSeq_for_Uint16_t = pRSeq_for_Uint16_t;
 pMemory_RSeq_for_Uint16->title = (void*)title_RSeq;

 memcpy((void*)&(pMemory_RSeq_for_Uint16->rseq), (void*)pRSeq_for_Uint16_t, sizeof(RSeq_for_Uint16_t));
 memcpy((void*)pMemory_RSeq_for_Uint16->buffer4rseq, (void*)pMemory_RSeq_for_Uint16->rseq.buffer_, 100);

 return pMemory_RSeq_for_Uint16;
}
//-------------------RSeq------------------------
//-------------------Message------------------------
Memory_Message*  MEMORY_Message(Memory_Message* pMemory_Message, uint16_t titleSpace, Message* pMessage);

static const 
void *title_Message[] =
{
  (void*)"Message"
};

Memory_Message* pMemory_Message_1;
Memory_Message* pMemory_Message_2;
Memory_Message* pMemory_Message_3;

static Memory_Message mMemory_Message_1;
static Memory_Message mMemory_Message_2;
static Memory_Message mMemory_Message_3;

Memory_Message*  MEMORY_Message_1(uint16_t titleSpace, Message* pMessage)
{
qDebug()<<"            ---MEMORY_Message_1---";
 return  MEMORY_Message(&mMemory_Message_1, titleSpace, pMessage);
}
Memory_Message*  MEMORY_Message_2(uint16_t titleSpace, Message* pMessage)
{
qDebug()<<"            ---MEMORY_Message_2---";
 return  MEMORY_Message(&mMemory_Message_2, titleSpace, pMessage);
}
Memory_Message*  MEMORY_Message_3(uint16_t titleSpace, Message* pMessage)
{
qDebug()<<"            ---MEMORY_Message_3---";
 return  MEMORY_Message(&mMemory_Message_3, titleSpace, pMessage);
}

Memory_Message*  MEMORY_Message(Memory_Message* pMemory_Message, uint16_t titleSpace, Message* pMessage)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Message* pMessage;
 void* title;

 Message mMessage;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_Message;
*/

 pMemory_Message->counter_inspect++;
 pMemory_Message->titleSpace = titleSpace;
 pMemory_Message->pMessage = pMessage;
 pMemory_Message->title = (void*)title_Message;

 memcpy((void*)&(pMemory_Message->mMessage), (void*)pMessage, sizeof(Message));
 MEMORY_RSeq_for_Uint16(&(pMemory_Message->mMemory_RSeq_for_Uint16), 4, &(pMemory_Message->mMessage.payload));

 pMemory_Message->mMessage.payload = pMemory_Message->mMemory_RSeq_for_Uint16.rseq;
 pMemory_Message->mMessage.payload.buffer_ = pMemory_Message->mMemory_RSeq_for_Uint16.buffer4rseq;

 return pMemory_Message;
}
//-------------------Message------------------------
//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser(Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser, uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);

static const 
void *title_Result_for_APDUHeader_in_APDUHeaderParser[] =
{
  (void*)"Result_for_APDUHeader..."
};

Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_1;
Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_2;
Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_3;

static Memory_Result_for_APDUHeader_in_APDUHeaderParser mMemory_Result_for_APDUHeader_in_APDUHeaderParser_1;
static Memory_Result_for_APDUHeader_in_APDUHeaderParser mMemory_Result_for_APDUHeader_in_APDUHeaderParser_2;
static Memory_Result_for_APDUHeader_in_APDUHeaderParser mMemory_Result_for_APDUHeader_in_APDUHeaderParser_3;

Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_1(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser)
{
qDebug()<<"            ---MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_1---";
 return  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser(&mMemory_Result_for_APDUHeader_in_APDUHeaderParser_1, titleSpace, pResult_for_APDUHeader_in_APDUHeaderParser);
}
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_2(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser)
{
qDebug()<<"            ---MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_2---";
 return  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser(&mMemory_Result_for_APDUHeader_in_APDUHeaderParser_2, titleSpace, pResult_for_APDUHeader_in_APDUHeaderParser);
}
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_3(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser)
{
qDebug()<<"            ---MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_3---";
 return  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser(&mMemory_Result_for_APDUHeader_in_APDUHeaderParser_3, titleSpace, pResult_for_APDUHeader_in_APDUHeaderParser);
}

Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser(Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser, uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser;
 void* title;

 Result_for_APDUHeader_in_APDUHeaderParser rResult_for_APDUHeader_in_APDUHeaderParser;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_Result_for_APDUHeader_in_APDUHeaderParser;
*/

 pMemory_Result_for_APDUHeader_in_APDUHeaderParser->counter_inspect++;
 pMemory_Result_for_APDUHeader_in_APDUHeaderParser->titleSpace = titleSpace;
 pMemory_Result_for_APDUHeader_in_APDUHeaderParser->pResult_for_APDUHeader_in_APDUHeaderParser = pResult_for_APDUHeader_in_APDUHeaderParser;
 pMemory_Result_for_APDUHeader_in_APDUHeaderParser->title = (void*)title_Result_for_APDUHeader_in_APDUHeaderParser;

 memcpy((void*)&(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser), (void*)pResult_for_APDUHeader_in_APDUHeaderParser, sizeof(Result_for_APDUHeader_in_APDUHeaderParser));
 MEMORY_RSeq_for_Uint16(&(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->mMemory_RSeq_for_Uint16), 4, &(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser.objects));

 pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser.objects = 
                          pMemory_Result_for_APDUHeader_in_APDUHeaderParser->mMemory_RSeq_for_Uint16.rseq;
 pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser.objects.buffer_ =
                          pMemory_Result_for_APDUHeader_in_APDUHeaderParser->mMemory_RSeq_for_Uint16.buffer4rseq;

 return pMemory_Result_for_APDUHeader_in_APDUHeaderParser;
}

//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser(Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser, uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);

static const 
void *title_Result_for_APDUResponseHeader_in_APDUHeaderParser[] =
{
  (void*)"Result_for_APDUResponseHeader..."
};

Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_1;
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_2;
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_3;

static Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser mMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_1;
static Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser mMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_2;
static Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser mMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_3;

Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_1(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser)
{
qDebug()<<"            ---MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_1---";
 return  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser(&mMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_1, titleSpace, pResult_for_APDUResponseHeader_in_APDUHeaderParser);
}
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_2(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser)
{
qDebug()<<"            ---MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_2---";
 return  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser(&mMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_2, titleSpace, pResult_for_APDUResponseHeader_in_APDUHeaderParser);
}
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_3(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser)
{
qDebug()<<"            ---MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_3---";
 return  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser(&mMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser_3, titleSpace, pResult_for_APDUResponseHeader_in_APDUHeaderParser);
}

Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser(Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser, uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser;
 void* title;

 Result_for_APDUResponseHeader_in_APDUHeaderParser rResult_for_APDUResponseHeader_in_APDUHeaderParser;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser;
*/

 pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->counter_inspect++;
 pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->titleSpace = titleSpace;
 pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->pResult_for_APDUResponseHeader_in_APDUHeaderParser = pResult_for_APDUResponseHeader_in_APDUHeaderParser;
 pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->title = (void*)title_Result_for_APDUResponseHeader_in_APDUHeaderParser;

 memcpy((void*)&(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser), (void*)pResult_for_APDUResponseHeader_in_APDUHeaderParser, sizeof(Result_for_APDUResponseHeader_in_APDUHeaderParser));
 MEMORY_RSeq_for_Uint16(&(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->mMemory_RSeq_for_Uint16), 4, &(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser.objects));

 pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser.objects = 
                          pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->mMemory_RSeq_for_Uint16.rseq;
 pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser.objects.buffer_ =
                          pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->mMemory_RSeq_for_Uint16.buffer4rseq;

 return pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser;
}
//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------
//-------------------ParsedRequest------------------------
Memory_ParsedRequest*  MEMORY_ParsedRequest(Memory_ParsedRequest* pMemory_ParsedRequest, uint16_t titleSpace, ParsedRequest* pParsedRequest);

static const 
void *title_ParsedRequest[] =
{
  (void*)"ParsedRequest"
};

Memory_ParsedRequest* pMemory_ParsedRequest_1;
Memory_ParsedRequest* pMemory_ParsedRequest_2;
Memory_ParsedRequest* pMemory_ParsedRequest_3;

static Memory_ParsedRequest mMemory_ParsedRequest_1;
static Memory_ParsedRequest mMemory_ParsedRequest_2;
static Memory_ParsedRequest mMemory_ParsedRequest_3;

Memory_ParsedRequest*  MEMORY_ParsedRequest_1(uint16_t titleSpace, ParsedRequest* pParsedRequest)
{
qDebug()<<"            ---MEMORY_ParsedRequest_1---";
 return  MEMORY_ParsedRequest(&mMemory_ParsedRequest_1, titleSpace, pParsedRequest);
}
Memory_ParsedRequest*  MEMORY_ParsedRequest_2(uint16_t titleSpace, ParsedRequest* pParsedRequest)
{
qDebug()<<"            ---MEMORY_ParsedRequest_2---";
 return  MEMORY_ParsedRequest(&mMemory_ParsedRequest_2, titleSpace, pParsedRequest);
}
Memory_ParsedRequest*  MEMORY_ParsedRequest_3(uint16_t titleSpace, ParsedRequest* pParsedRequest)
{
qDebug()<<"            ---MEMORY_ParsedRequest_3---";
 return  MEMORY_ParsedRequest(&mMemory_ParsedRequest_3, titleSpace, pParsedRequest);
}

Memory_ParsedRequest*  MEMORY_ParsedRequest(Memory_ParsedRequest* pMemory_ParsedRequest, uint16_t titleSpace, ParsedRequest* pParsedRequest)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 ParsedRequest* pParsedRequest;
 void* title;

 ParsedRequest mParsedRequest;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_ParsedRequest;
*/

 pMemory_ParsedRequest->counter_inspect++;
 pMemory_ParsedRequest->titleSpace = titleSpace;
 pMemory_ParsedRequest->pParsedRequest = pParsedRequest;
 pMemory_ParsedRequest->title = (void*)title_ParsedRequest;

 memcpy((void*)&(pMemory_ParsedRequest->mParsedRequest), (void*)pParsedRequest, sizeof(ParsedRequest));
 MEMORY_RSeq_for_Uint16(&(pMemory_ParsedRequest->mMemory_RSeq_for_Uint16), 4, &(pMemory_ParsedRequest->mParsedRequest.objects));

 pMemory_ParsedRequest->mParsedRequest.objects = pMemory_ParsedRequest->mMemory_RSeq_for_Uint16.rseq;
 pMemory_ParsedRequest->mParsedRequest.objects.buffer_ = pMemory_ParsedRequest->mMemory_RSeq_for_Uint16.buffer4rseq;

 return pMemory_ParsedRequest;
}
//-------------------ParsedRequest------------------------
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField(Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField, uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);

static const 
void *title_PairSer4cpp_for_IINField_AppControlField[] =
{
  (void*)"PairSer4cpp..."
};

Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_1;
Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_2;
Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_3;

static Memory_PairSer4cpp_for_IINField_AppControlField mMemory_PairSer4cpp_for_IINField_AppControlField_1;
static Memory_PairSer4cpp_for_IINField_AppControlField mMemory_PairSer4cpp_for_IINField_AppControlField_2;
static Memory_PairSer4cpp_for_IINField_AppControlField mMemory_PairSer4cpp_for_IINField_AppControlField_3;

Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_1(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField)
{
qDebug()<<"            ---MEMORY_PairSer4cpp_for_IINField_AppControlField_1---";
 return  MEMORY_PairSer4cpp_for_IINField_AppControlField(&mMemory_PairSer4cpp_for_IINField_AppControlField_1, titleSpace, pPairSer4cpp_for_IINField_AppControlField);
}
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_2(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField)
{
qDebug()<<"            ---MEMORY_PairSer4cpp_for_IINField_AppControlField_2---";
 return  MEMORY_PairSer4cpp_for_IINField_AppControlField(&mMemory_PairSer4cpp_for_IINField_AppControlField_2, titleSpace, pPairSer4cpp_for_IINField_AppControlField);
}
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_3(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField)
{
qDebug()<<"            ---MEMORY_PairSer4cpp_for_IINField_AppControlField_3---";
 return  MEMORY_PairSer4cpp_for_IINField_AppControlField(&mMemory_PairSer4cpp_for_IINField_AppControlField_3, titleSpace, pPairSer4cpp_for_IINField_AppControlField);
}

Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField(Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField, uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField;
 void* title;

 PairSer4cpp_for_IINField_AppControlField mPairSer4cpp_for_IINField_AppControlField;
} Memory_PairSer4cpp_for_IINField_AppControlField;
*/

 pMemory_PairSer4cpp_for_IINField_AppControlField->counter_inspect++;
 pMemory_PairSer4cpp_for_IINField_AppControlField->titleSpace = titleSpace;
 pMemory_PairSer4cpp_for_IINField_AppControlField->pPairSer4cpp_for_IINField_AppControlField = pPairSer4cpp_for_IINField_AppControlField;
 pMemory_PairSer4cpp_for_IINField_AppControlField->title = (void*)title_PairSer4cpp_for_IINField_AppControlField;

 memcpy((void*)&(pMemory_PairSer4cpp_for_IINField_AppControlField->mPairSer4cpp_for_IINField_AppControlField), (void*)pPairSer4cpp_for_IINField_AppControlField, sizeof(PairSer4cpp_for_IINField_AppControlField));

 return pMemory_PairSer4cpp_for_IINField_AppControlField;
}
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
//-------------------IINField------------------------
Memory_IINField*  MEMORY_IINField(Memory_IINField* pMemory_IINField, uint16_t titleSpace, IINField* pIINField);

static const 
void *title_IINField[] =
{
  (void*)"IINField"
};

Memory_IINField* pMemory_IINField_1;
Memory_IINField* pMemory_IINField_2;
Memory_IINField* pMemory_IINField_3;

static Memory_IINField mMemory_IINField_1;
static Memory_IINField mMemory_IINField_2;
static Memory_IINField mMemory_IINField_3;

Memory_IINField*  MEMORY_IINField_1(uint16_t titleSpace, IINField* pIINField)
{
qDebug()<<"            ---MEMORY_IINField_1---";
 return  MEMORY_IINField(&mMemory_IINField_1, titleSpace, pIINField);
}
Memory_IINField*  MEMORY_IINField_2(uint16_t titleSpace, IINField* pIINField)
{
qDebug()<<"            ---MEMORY_IINField_2---";
 return  MEMORY_IINField(&mMemory_IINField_2, titleSpace, pIINField);
}
Memory_IINField*  MEMORY_IINField_3(uint16_t titleSpace, IINField* pIINField)
{
qDebug()<<"            ---MEMORY_IINField_3---";
 return  MEMORY_IINField(&mMemory_IINField_3, titleSpace, pIINField);
}

Memory_IINField*  MEMORY_IINField(Memory_IINField* pMemory_IINField, uint16_t titleSpace, IINField* pIINField)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 IINField* pIINField;
 void* title;

 IINField mIINField;
} Memory_IINField;
*/

 pMemory_IINField->counter_inspect++;
 pMemory_IINField->titleSpace = titleSpace;
 pMemory_IINField->pIINField = pIINField;
 pMemory_IINField->title = (void*)title_IINField;

 memcpy((void*)&(pMemory_IINField->mIINField), (void*)pIINField, sizeof(IINField));

 return pMemory_IINField;
}
//-------------------IINField------------------------
//-------------------ObjectHeader------------------------
Memory_ObjectHeader*  MEMORY_ObjectHeader(Memory_ObjectHeader* pMemory_ObjectHeader, uint16_t titleSpace, ObjectHeader* pObjectHeader);

static const 
void *title_ObjectHeader[] =
{
  (void*)"ObjectHeader"
};

Memory_ObjectHeader* pMemory_ObjectHeader_1;
Memory_ObjectHeader* pMemory_ObjectHeader_2;
Memory_ObjectHeader* pMemory_ObjectHeader_3;

static Memory_ObjectHeader mMemory_ObjectHeader_1;
static Memory_ObjectHeader mMemory_ObjectHeader_2;
static Memory_ObjectHeader mMemory_ObjectHeader_3;

Memory_ObjectHeader*  MEMORY_ObjectHeader_1(uint16_t titleSpace, ObjectHeader* pObjectHeader)
{
qDebug()<<"            ---MEMORY_ObjectHeader_1---";
 return  MEMORY_ObjectHeader(&mMemory_ObjectHeader_1, titleSpace, pObjectHeader);
}
Memory_ObjectHeader*  MEMORY_ObjectHeader_2(uint16_t titleSpace, ObjectHeader* pObjectHeader)
{
qDebug()<<"            ---MEMORY_ObjectHeader_2---";
 return  MEMORY_ObjectHeader(&mMemory_ObjectHeader_2, titleSpace, pObjectHeader);
}
Memory_ObjectHeader*  MEMORY_ObjectHeader_3(uint16_t titleSpace, ObjectHeader* pObjectHeader)
{
qDebug()<<"            ---MEMORY_ObjectHeader_3---";
 return  MEMORY_ObjectHeader(&mMemory_ObjectHeader_3, titleSpace, pObjectHeader);
}

Memory_ObjectHeader*  MEMORY_ObjectHeader(Memory_ObjectHeader* pMemory_ObjectHeader, uint16_t titleSpace, ObjectHeader* pObjectHeader)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 ObjectHeader* pObjectHeader;
 void* title;

 ObjectHeader mObjectHeader;
} Memory_ObjectHeader;
*/

 pMemory_ObjectHeader->counter_inspect++;
 pMemory_ObjectHeader->titleSpace = titleSpace;
 pMemory_ObjectHeader->pObjectHeader = pObjectHeader;
 pMemory_ObjectHeader->title = (void*)title_ObjectHeader;

 int idx = pMemory_ObjectHeader->counter_inspect;
 if(idx > COUNT_ObjectHeader) idx = COUNT_ObjectHeader;
 memcpy((void*)&(pMemory_ObjectHeader->mObjectHeader[idx-1]), (void*)pObjectHeader, sizeof(ObjectHeader));

 return pMemory_ObjectHeader;
}
//-------------------ObjectHeader------------------------
//-------------------GroupVariationRecord------------------------
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord(Memory_GroupVariationRecord* pMemory_GroupVariationRecord, uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);

static const 
void *title_GroupVariationRecord[] =
{
  (void*)"GroupVariationRecord"
};

Memory_GroupVariationRecord* pMemory_GroupVariationRecord_1;
Memory_GroupVariationRecord* pMemory_GroupVariationRecord_2;
Memory_GroupVariationRecord* pMemory_GroupVariationRecord_3;

static Memory_GroupVariationRecord mMemory_GroupVariationRecord_1;
static Memory_GroupVariationRecord mMemory_GroupVariationRecord_2;
static Memory_GroupVariationRecord mMemory_GroupVariationRecord_3;

Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_1(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord)
{
qDebug()<<"            ---MEMORY_GroupVariationRecord_1---";
 return  MEMORY_GroupVariationRecord(&mMemory_GroupVariationRecord_1, titleSpace, pGroupVariationRecord);
}
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_2(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord)
{
qDebug()<<"            ---MEMORY_GroupVariationRecord_2---";
 return  MEMORY_GroupVariationRecord(&mMemory_GroupVariationRecord_2, titleSpace, pGroupVariationRecord);
}
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_3(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord)
{
qDebug()<<"            ---MEMORY_GroupVariationRecord_3---";
 return  MEMORY_GroupVariationRecord(&mMemory_GroupVariationRecord_3, titleSpace, pGroupVariationRecord);
}

Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord(Memory_GroupVariationRecord* pMemory_GroupVariationRecord, uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 GroupVariationRecord* pGroupVariationRecord;
 void* title;

 GroupVariationRecord mGroupVariationRecord;
} Memory_GroupVariationRecord;
*/

 pMemory_GroupVariationRecord->counter_inspect++;
 pMemory_GroupVariationRecord->titleSpace = titleSpace;
 pMemory_GroupVariationRecord->pGroupVariationRecord = pGroupVariationRecord;
 pMemory_GroupVariationRecord->title = (void*)title_GroupVariationRecord;

 memcpy((void*)&(pMemory_GroupVariationRecord->mGroupVariationRecord), (void*)pGroupVariationRecord, sizeof(GroupVariationRecord));

 return pMemory_GroupVariationRecord;
}
//-------------------GroupVariationRecord------------------------
//-------------------HeaderRecord------------------------
Memory_HeaderRecord*  MEMORY_HeaderRecord(Memory_HeaderRecord* pMemory_HeaderRecord, uint16_t titleSpace, HeaderRecord* pHeaderRecord);

static const 
void *title_HeaderRecord[] =
{
  (void*)"HeaderRecord"
};

Memory_HeaderRecord* pMemory_HeaderRecord_1;
Memory_HeaderRecord* pMemory_HeaderRecord_2;
Memory_HeaderRecord* pMemory_HeaderRecord_3;

static Memory_HeaderRecord mMemory_HeaderRecord_1;
static Memory_HeaderRecord mMemory_HeaderRecord_2;
static Memory_HeaderRecord mMemory_HeaderRecord_3;

Memory_HeaderRecord*  MEMORY_HeaderRecord_1(uint16_t titleSpace, HeaderRecord* pHeaderRecord)
{
qDebug()<<"            ---MEMORY_HeaderRecord_1---";
 return  MEMORY_HeaderRecord(&mMemory_HeaderRecord_1, titleSpace, pHeaderRecord);
}
Memory_HeaderRecord*  MEMORY_HeaderRecord_2(uint16_t titleSpace, HeaderRecord* pHeaderRecord)
{
qDebug()<<"            ---MEMORY_HeaderRecord_2---";
 return  MEMORY_HeaderRecord(&mMemory_HeaderRecord_2, titleSpace, pHeaderRecord);
}
Memory_HeaderRecord*  MEMORY_HeaderRecord_3(uint16_t titleSpace, HeaderRecord* pHeaderRecord)
{
qDebug()<<"            ---MEMORY_HeaderRecord_3---";
 return  MEMORY_HeaderRecord(&mMemory_HeaderRecord_3, titleSpace, pHeaderRecord);
}

Memory_HeaderRecord*  MEMORY_HeaderRecord(Memory_HeaderRecord* pMemory_HeaderRecord, uint16_t titleSpace, HeaderRecord* pHeaderRecord)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 HeaderRecord* pHeaderRecord;
 void* title;

 HeaderRecord mHeaderRecord;
} Memory_HeaderRecord;
*/

 pMemory_HeaderRecord->counter_inspect++;
 pMemory_HeaderRecord->titleSpace = titleSpace;
 pMemory_HeaderRecord->pHeaderRecord = pHeaderRecord;
 pMemory_HeaderRecord->title = (void*)title_HeaderRecord;

 memcpy((void*)&(pMemory_HeaderRecord->mHeaderRecord), (void*)pHeaderRecord, sizeof(HeaderRecord));

 return pMemory_HeaderRecord;
}
//-------------------HeaderRecord------------------------
//-------------------EventLists------------------------
Memory_EventLists*  MEMORY_EventLists(Memory_EventLists* pMemory_EventLists, uint16_t titleSpace, EventLists* pEventLists);

static const 
void *title_EventLists[] =
{
  (void*)"EventLists"
};

Memory_EventLists* pMemory_EventLists_1;
Memory_EventLists* pMemory_EventLists_2;
Memory_EventLists* pMemory_EventLists_3;

static Memory_EventLists mMemory_EventLists_1;
static Memory_EventLists mMemory_EventLists_2;
static Memory_EventLists mMemory_EventLists_3;

Memory_EventLists*  MEMORY_EventLists_1(uint16_t titleSpace, EventLists* pEventLists)
{
qDebug()<<"            ---MEMORY_EventLists_1---";
 return  MEMORY_EventLists(&mMemory_EventLists_1, titleSpace, pEventLists);
}
Memory_EventLists*  MEMORY_EventLists_2(uint16_t titleSpace, EventLists* pEventLists)
{
qDebug()<<"            ---MEMORY_EventLists_2---";
 return  MEMORY_EventLists(&mMemory_EventLists_2, titleSpace, pEventLists);
}
Memory_EventLists*  MEMORY_EventLists_3(uint16_t titleSpace, EventLists* pEventLists)
{
qDebug()<<"            ---MEMORY_EventLists_3---";
 return  MEMORY_EventLists(&mMemory_EventLists_3, titleSpace, pEventLists);
}

Memory_EventLists*  MEMORY_EventLists(Memory_EventLists* pMemory_EventLists, uint16_t titleSpace, EventLists* pEventLists)
{
/*
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 EventLists* pEventLists;
 void* title;

 EventLists mEventLists;
} Memory_EventLists;
*/

 pMemory_EventLists->counter_inspect++;
 pMemory_EventLists->titleSpace = titleSpace;
 pMemory_EventLists->pEventLists = pEventLists;
 pMemory_EventLists->title = (void*)title_EventLists;

 int idx = pMemory_EventLists->counter_inspect;
 if(idx > COUNT_EventLists) idx = COUNT_EventLists;
 memcpy((void*)&(pMemory_EventLists->mEventLists[idx-1]), (void*)pEventLists, sizeof(EventLists));

 return pMemory_EventLists;
}
//-------------------EventLists------------------------
