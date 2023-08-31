#ifndef MEMORYINSPECT_H
#define MEMORYINSPECT_H

#include "RSeq.h"
#include "Message.h"
#include "APDUHeaderParser.h"
#include "ParsedRequest.h"
#include "Pair_for_IINField_AppControlField.h"
#include "ObjectHeaderParser.h"
#include "GroupVariationRecord.h"
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
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Message* pMessage;
 void* title;

 Message mMessage;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_Message;

extern Memory_Message* pMemory_Message_1;
extern Memory_Message* pMemory_Message_2;
extern Memory_Message* pMemory_Message_3;

Memory_Message*  MEMORY_Message_1(uint16_t titleSpace, Message* pMessage);
Memory_Message*  MEMORY_Message_2(uint16_t titleSpace, Message* pMessage);
Memory_Message*  MEMORY_Message_3(uint16_t titleSpace, Message* pMessage);
//-------------------Message------------------------

//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser;
 void* title;

 Result_for_APDUHeader_in_APDUHeaderParser rResult_for_APDUHeader_in_APDUHeaderParser;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_Result_for_APDUHeader_in_APDUHeaderParser;

extern Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_1;
extern Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_2;
extern Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser_3;

Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_1(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_2(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);
Memory_Result_for_APDUHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_3(uint16_t titleSpace, Result_for_APDUHeader_in_APDUHeaderParser* pResult_for_APDUHeader_in_APDUHeaderParser);
//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser;
 void* title;

 Result_for_APDUResponseHeader_in_APDUHeaderParser rResult_for_APDUResponseHeader_in_APDUHeaderParser;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser;

extern Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser_1;
extern Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser_2;
extern Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser_3;

Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_1(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_2(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);
Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser*  MEMORY_Result_for_APDUResponseHeader_in_APDUHeaderParser_3(uint16_t titleSpace, Result_for_APDUResponseHeader_in_APDUHeaderParser* pResult_for_APDUResponseHeader_in_APDUHeaderParser);
//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------

//-------------------ParsedRequest------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 ParsedRequest* pParsedRequest;
 void* title;

 ParsedRequest mParsedRequest;
 Memory_RSeq_for_Uint16 mMemory_RSeq_for_Uint16;
} Memory_ParsedRequest;

extern Memory_ParsedRequest* pMemory_ParsedRequest_1;
extern Memory_ParsedRequest* pMemory_ParsedRequest_2;
extern Memory_ParsedRequest* pMemory_ParsedRequest_3;

Memory_ParsedRequest*  MEMORY_ParsedRequest_1(uint16_t titleSpace, ParsedRequest* pParsedRequest);
Memory_ParsedRequest*  MEMORY_ParsedRequest_2(uint16_t titleSpace, ParsedRequest* pParsedRequest);
Memory_ParsedRequest*  MEMORY_ParsedRequest_3(uint16_t titleSpace, ParsedRequest* pParsedRequest);
//-------------------ParsedRequest------------------------

//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField;
 void* title;

 PairSer4cpp_for_IINField_AppControlField mPairSer4cpp_for_IINField_AppControlField;
} Memory_PairSer4cpp_for_IINField_AppControlField;

extern Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_1;
extern Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_2;
extern Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField_3;

Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_1(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_2(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);
Memory_PairSer4cpp_for_IINField_AppControlField*  MEMORY_PairSer4cpp_for_IINField_AppControlField_3(uint16_t titleSpace, PairSer4cpp_for_IINField_AppControlField* pPairSer4cpp_for_IINField_AppControlField);
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------

//-------------------IINField------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 IINField* pIINField;
 void* title;

 IINField mIINField;
} Memory_IINField;

extern Memory_IINField* pMemory_IINField_1;
extern Memory_IINField* pMemory_IINField_2;
extern Memory_IINField* pMemory_IINField_3;

Memory_IINField*  MEMORY_IINField_1(uint16_t titleSpace, IINField* pIINField);
Memory_IINField*  MEMORY_IINField_2(uint16_t titleSpace, IINField* pIINField);
Memory_IINField*  MEMORY_IINField_3(uint16_t titleSpace, IINField* pIINField);
//-------------------IINField------------------------

//-------------------ObjectHeader------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 ObjectHeader* pObjectHeader;
 void* title;

 ObjectHeader mObjectHeader;
} Memory_ObjectHeader;

extern Memory_ObjectHeader* pMemory_ObjectHeader_1;
extern Memory_ObjectHeader* pMemory_ObjectHeader_2;
extern Memory_ObjectHeader* pMemory_ObjectHeader_3;

Memory_ObjectHeader*  MEMORY_ObjectHeader_1(uint16_t titleSpace, ObjectHeader* pObjectHeader);
Memory_ObjectHeader*  MEMORY_ObjectHeader_2(uint16_t titleSpace, ObjectHeader* pObjectHeader);
Memory_ObjectHeader*  MEMORY_ObjectHeader_3(uint16_t titleSpace, ObjectHeader* pObjectHeader);
//-------------------ObjectHeader------------------------

//-------------------GroupVariationRecord------------------------
typedef struct
{
 uint32_t counter_inspect;
 uint16_t titleSpace;
 GroupVariationRecord* pGroupVariationRecord;
 void* title;

 GroupVariationRecord mGroupVariationRecord;
} Memory_GroupVariationRecord;

extern Memory_GroupVariationRecord* pMemory_GroupVariationRecord_1;
extern Memory_GroupVariationRecord* pMemory_GroupVariationRecord_2;
extern Memory_GroupVariationRecord* pMemory_GroupVariationRecord_3;

Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_1(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_2(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);
Memory_GroupVariationRecord*  MEMORY_GroupVariationRecord_3(uint16_t titleSpace, GroupVariationRecord* pGroupVariationRecord);
//-------------------GroupVariationRecord------------------------

#endif
