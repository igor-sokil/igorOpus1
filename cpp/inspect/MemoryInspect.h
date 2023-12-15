#ifndef MEMORYINSPECT_H
#define MEMORYINSPECT_H

#include "RSeq.h"
#include "MeasurementTypes.h"
#include "IINField.h"
//#include "WSeq.h"
//#include "Message.h"
//#include "APDUHeaderParser.h"
//#include "ParsedRequest.h"
//#include "EventLists.h"
//#include "LinkHeader.h"
//#include "LinkHeaderFields.h"
//#include "Pair_for_IINField_AppControlField.h"
//#include "ObjectHeaderParser.h"
//#include "GroupVariationRecord.h"

void inspect_Analog(Analog *b);
void inspect_Binary(Binary *b);
void inspect_IINField(IINField *b);

void inspect_Counter(Counter *b);
void inspect_FrozenCounter(FrozenCounter *b);
void inspect_RSeq(RSeq_for_Uint16_t *buffer);
//void inspect_WSeq(WSeq_for_Uint16_t *buffer);
/*
//-------------------RSeq------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 RSeq_for_Uint16_t* pRSeq_for_Uint16_t;
 void* title;

 RSeq_for_Uint16_t rseq;
 uint8_t buffer4rseq[100];
} Memory_RSeq_for_Uint16;


extern Memory_RSeq_for_Uint16* pMemory_RSeq_for_Uint16_1;
extern Memory_RSeq_for_Uint16* pMemory_RSeq_for_Uint16_2;
extern Memory_RSeq_for_Uint16* pMemory_RSeq_for_Uint16_3;

Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16_1(uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t);
Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16_2(uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t);
Memory_RSeq_for_Uint16*  MEMORY_RSeq_for_Uint16_3(uint16_t titleSpace, RSeq_for_Uint16_t* pRSeq_for_Uint16_t);
//-------------------RSeq------------------------

//-------------------Message------------------------
#define COUNT_Message  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Message* pMessage;
 void* title;

 Message mMessage[COUNT_Message];
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16[COUNT_Message];
} Memory_Message;

extern Memory_Message* pMemory_Message_1;
extern Memory_Message* pMemory_Message_2;
extern Memory_Message* pMemory_Message_3;

Memory_Message*  MEMORY_Message_1(uint16_t titleSpace, Message* pMessage);
Memory_Message*  MEMORY_Message_2(uint16_t titleSpace, Message* pMessage);
Memory_Message*  MEMORY_Message_3(uint16_t titleSpace, Message* pMessage);
//-------------------Message------------------------

//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------
#define COUNT_Result_for_APDUHeader_in_APDUHeaderParser  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser;
 void* title;

 Result_for_APDUHeader_in_APDUHeaderParser rResult_for_APDUHeader_in_APDUHeaderParser[COUNT_Result_for_APDUHeader_in_APDUHeaderParser];
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16[COUNT_Result_for_APDUHeader_in_APDUHeaderParser];
} Memory_Result_for_APDUHeader_in_APDUHeaderParser;

extern Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_1;
extern Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_2;
extern Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_3;

Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_1(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_2(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_3(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);
//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------
#define COUNT_Result_for_APDUResponseHeader_in_APDUHeaderParser  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser;
 void* title;

 Result_for_APDUResponseHeader_in_APDUHeaderParser rResult_for_APDUResponseHeader_in_APDUHeaderParser[COUNT_Result_for_APDUResponseHeader_in_APDUHeaderParser];
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16[COUNT_Result_for_APDUResponseHeader_in_APDUHeaderParser];
} Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser;

extern Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser_1;
extern Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser_2;
extern Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser_3;

Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_1(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_2(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_3(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);
//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------

//-------------------ParsedRequest------------------------
#define COUNT_ParsedRequest  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 ParsedRequest* pParsedRequest;
 void* title;

 ParsedRequest mParsedRequest[COUNT_ParsedRequest];
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16[COUNT_ParsedRequest];
} Memory_ParsedRequest;

extern Memory_ParsedRequest* pMemory_ParsedRequest_1;
extern Memory_ParsedRequest* pMemory_ParsedRequest_2;
extern Memory_ParsedRequest* pMemory_ParsedRequest_3;

Memory_ParsedRequest*  MEMORY_ParsedRequest_1(uint16_t titleSpace, ParsedRequest* pParsedRequest);
Memory_ParsedRequest*  MEMORY_ParsedRequest_2(uint16_t titleSpace, ParsedRequest* pParsedRequest);
Memory_ParsedRequest*  MEMORY_ParsedRequest_3(uint16_t titleSpace, ParsedRequest* pParsedRequest);
//-------------------ParsedRequest------------------------

//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
#define COUNT_PairSer4cpp_for_IINField_AppControlField  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField;
 void* title;

 PairSer4cpp_for_IINField_AppControlField mPairSer4cpp_for_IINField_AppControlField[COUNT_PairSer4cpp_for_IINField_AppControlField];
} Memory_PairSer4cpp_for_IINField_AppControlField;

extern Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_1;
extern Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_2;
extern Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_3;

Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_1(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_2(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_3(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------

//-------------------IINField------------------------
#define COUNT_IINField  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 IINField* pIINField;
 void* title;

 IINField mIINField[COUNT_IINField];
} Memory_IINField;

extern Memory_IINField* pMemory_IINField_1;
extern Memory_IINField* pMemory_IINField_2;
extern Memory_IINField* pMemory_IINField_3;

Memory_IINField*  MEMORY_IINField_1(uint16_t titleSpace, IINField* pIINField);
Memory_IINField*  MEMORY_IINField_2(uint16_t titleSpace, IINField* pIINField);
Memory_IINField*  MEMORY_IINField_3(uint16_t titleSpace, IINField* pIINField);
//-------------------IINField------------------------

//-------------------ObjectHeader------------------------
#define COUNT_ObjectHeader  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 ObjectHeader* pObjectHeader;
 void* title;

 ObjectHeader mObjectHeader[COUNT_ObjectHeader];
} Memory_ObjectHeader;

extern Memory_ObjectHeader* pMemory_ObjectHeader_1;
extern Memory_ObjectHeader* pMemory_ObjectHeader_2;
extern Memory_ObjectHeader* pMemory_ObjectHeader_3;

Memory_ObjectHeader*  MEMORY_ObjectHeader_1(uint16_t titleSpace, ObjectHeader* pObjectHeader);
Memory_ObjectHeader*  MEMORY_ObjectHeader_2(uint16_t titleSpace, ObjectHeader* pObjectHeader);
Memory_ObjectHeader*  MEMORY_ObjectHeader_3(uint16_t titleSpace, ObjectHeader* pObjectHeader);
//-------------------ObjectHeader------------------------

//-------------------GroupVariationRecord------------------------
#define COUNT_GroupVariationRecord  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 GroupVariationRecord* pGroupVariationRecord;
 void* title;

 GroupVariationRecord mGroupVariationRecord[COUNT_GroupVariationRecord];
} Memory_GroupVariationRecord;

extern Memory_GroupVariationRecord* pMemory_GroupVariationRecord_1;
extern Memory_GroupVariationRecord* pMemory_GroupVariationRecord_2;
extern Memory_GroupVariationRecord* pMemory_GroupVariationRecord_3;

Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_1(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_2(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_3(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);
//-------------------GroupVariationRecord------------------------
//-------------------HeaderRecord------------------------
#define COUNT_HeaderRecord  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 HeaderRecord* pHeaderRecord;
 void* title;

 HeaderRecord mHeaderRecord[COUNT_HeaderRecord];
} Memory_HeaderRecord;

extern Memory_HeaderRecord* pMemory_HeaderRecord_1;
extern Memory_HeaderRecord* pMemory_HeaderRecord_2;
extern Memory_HeaderRecord* pMemory_HeaderRecord_3;

Memory_HeaderRecord*  MEMORY_HeaderRecord_1(uint16_t titleSpace, HeaderRecord* pHeaderRecord);
Memory_HeaderRecord*  MEMORY_HeaderRecord_2(uint16_t titleSpace, HeaderRecord* pHeaderRecord);
Memory_HeaderRecord*  MEMORY_HeaderRecord_3(uint16_t titleSpace, HeaderRecord* pHeaderRecord);
//-------------------HeaderRecord------------------------
//-------------------EventLists------------------------
#define COUNT_EventLists  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 EventLists* pEventLists;
 void* title;

 EventLists mEventLists[COUNT_EventLists];
} Memory_EventLists;

extern Memory_EventLists* pMemory_EventLists_1;
extern Memory_EventLists* pMemory_EventLists_2;
extern Memory_EventLists* pMemory_EventLists_3;

Memory_EventLists*  MEMORY_EventLists_1(uint16_t titleSpace, EventLists* pEventLists);
Memory_EventLists*  MEMORY_EventLists_2(uint16_t titleSpace, EventLists* pEventLists);
Memory_EventLists*  MEMORY_EventLists_3(uint16_t titleSpace, EventLists* pEventLists);
//-------------------EventLists------------------------
//-------------------EventRecord------------------------
#define COUNT_EventRecord  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 EventRecord* pEventRecord;
 void* title;

 EventRecord mEventRecord[COUNT_EventRecord];
} Memory_EventRecord;

extern Memory_EventRecord* pMemory_EventRecord_1;
extern Memory_EventRecord* pMemory_EventRecord_2;
extern Memory_EventRecord* pMemory_EventRecord_3;

Memory_EventRecord*  MEMORY_EventRecord_1(uint16_t titleSpace, EventRecord* pEventRecord);
Memory_EventRecord*  MEMORY_EventRecord_2(uint16_t titleSpace, EventRecord* pEventRecord);
Memory_EventRecord*  MEMORY_EventRecord_3(uint16_t titleSpace, EventRecord* pEventRecord);
//-------------------EventRecord------------------------
//-------------------LinkHeader------------------------
#define COUNT_LinkHeader  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 LinkHeader* pLinkHeader;
 void* title;

 LinkHeader mLinkHeader[COUNT_LinkHeader];
} Memory_LinkHeader;

extern Memory_LinkHeader* pMemory_LinkHeader_1;
extern Memory_LinkHeader* pMemory_LinkHeader_2;
extern Memory_LinkHeader* pMemory_LinkHeader_3;

Memory_LinkHeader*  MEMORY_LinkHeader_1(uint16_t titleSpace, LinkHeader* pLinkHeader);
Memory_LinkHeader*  MEMORY_LinkHeader_2(uint16_t titleSpace, LinkHeader* pLinkHeader);
Memory_LinkHeader*  MEMORY_LinkHeader_3(uint16_t titleSpace, LinkHeader* pLinkHeader);
//-------------------LinkHeader------------------------
//-------------------LinkHeaderFields------------------------
#define COUNT_LinkHeaderFields  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 LinkHeaderFields* pLinkHeaderFields;
 void* title;

 LinkHeaderFields mLinkHeaderFields[COUNT_LinkHeaderFields];
} Memory_LinkHeaderFields;

extern Memory_LinkHeaderFields* pMemory_LinkHeaderFields_1;
extern Memory_LinkHeaderFields* pMemory_LinkHeaderFields_2;
extern Memory_LinkHeaderFields* pMemory_LinkHeaderFields_3;

Memory_LinkHeaderFields*  MEMORY_LinkHeaderFields_1(uint16_t titleSpace, LinkHeaderFields* pLinkHeaderFields);
Memory_LinkHeaderFields*  MEMORY_LinkHeaderFields_2(uint16_t titleSpace, LinkHeaderFields* pLinkHeaderFields);
Memory_LinkHeaderFields*  MEMORY_LinkHeaderFields_3(uint16_t titleSpace, LinkHeaderFields* pLinkHeaderFields);
//-------------------LinkHeaderFields------------------------
//-------------------RangeHeader------------------------
#define COUNT_RangeHeader  5
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 RangeHeader* pRangeHeader;
 void* title;

 RangeHeader mRangeHeader[COUNT_RangeHeader];
} Memory_RangeHeader;

extern Memory_RangeHeader* pMemory_RangeHeader_1;
extern Memory_RangeHeader* pMemory_RangeHeader_2;
extern Memory_RangeHeader* pMemory_RangeHeader_3;

Memory_RangeHeader*  MEMORY_RangeHeader_1(uint16_t titleSpace, RangeHeader* pRangeHeader);
Memory_RangeHeader*  MEMORY_RangeHeader_2(uint16_t titleSpace, RangeHeader* pRangeHeader);
Memory_RangeHeader*  MEMORY_RangeHeader_3(uint16_t titleSpace, RangeHeader* pRangeHeader);
//-------------------RangeHeader------------------------
*/
#endif
