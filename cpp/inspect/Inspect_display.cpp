#include <QtWidgets>
#include "loghandler.h"

#include "header.h"

//-------------------Message------------------------
void inspect_Message(Memory_Message* pMemory_Message);

void inspect_Message(Memory_Message* pMemory_Message)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_Message->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("-Message-");
 loghandler.LogEntryShort("===========================");

 loghandler.LogEntry("");

 loghandler.logHandlerStampInteger((" counter = "), pMemory_Message->counter_inspect);

 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_Message->pMessage);

 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---Addresses addresses---");

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t source      = "), pMemory_Message->mMessage.addresses.source);

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t destination = "), pMemory_Message->mMessage.addresses.destination); 

 loghandler.LogEntry("");

 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---RSeq_for_Uint16_t payload---");

 uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_Message->mMessage.payload.hHasLength));
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t   length = "), len); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("    uint8_t buffer_[] = ");

 loghandler.logHandlerStampCharArray(pMemory_Message->mMessage.payload.buffer_, len);
}
//-------------------Message------------------------
//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

void inspect_Result_for_APDUHeader_in_APDUHeaderParser(Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser);

void inspect_Result_for_APDUHeader_in_APDUHeaderParser(Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_Result_for_APDUHeader_in_APDUHeaderParser->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("====================");
 loghandler.LogEntryShort("-Result_for_APDUHeader_in_APDUHeaderParser-");
 loghandler.LogEntryShort("====================");

 loghandler.LogEntry("");
 loghandler.logHandlerStampInteger((" counter = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->counter_inspect);
 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_Result_for_APDUHeader_in_APDUHeaderParser->pResult_for_APDUHeader_in_APDUHeaderParser);

//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - - 
 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---APDUHeader header---");
 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "         ---AppControlField control---");
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean FIR = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUHeader_in_APDUHeaderParser.header.control.FIR); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean FIN = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUHeader_in_APDUHeaderParser.header.control.FIN); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean CON = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUHeader_in_APDUHeaderParser.header.control.CON); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean UNS = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUHeader_in_APDUHeaderParser.header.control.UNS); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t SEQ = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUHeader_in_APDUHeaderParser.header.control.SEQ); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "         ---FunctionCode_uint8_t function---");

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("         uint16_t function = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                                                rResult_for_APDUHeader_in_APDUHeaderParser.header.function);
//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - - 

 loghandler.LogEntry("");

 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---RSeq_for_Uint16_t objects---");

 uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser.objects.hHasLength));
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t   length = "), len); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("    uint8_t buffer_[] = ");

 loghandler.logHandlerStampCharArray(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser.objects.buffer_, len);
}

//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------

void inspect_Result_for_APDUResponseHeader_in_APDUHeaderParser(Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser);

void inspect_Result_for_APDUResponseHeader_in_APDUHeaderParser(Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("=====================");
 loghandler.LogEntryShort("-Result_for_APDUResponseHeader_in_APDUHeaderParser-");
 loghandler.LogEntryShort("=====================");

 loghandler.LogEntry("");

 loghandler.logHandlerStampInteger((" counter = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->counter_inspect);

 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->pResult_for_APDUResponseHeader_in_APDUHeaderParser);

 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---APDUResponseHeader header---");

 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "         ---APDUHeader aAPDUHeader---");
 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "                 ---AppControlField control---");
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("           boolean FIR = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUResponseHeader_in_APDUHeaderParser.header.aAPDUHeader.control.FIR); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("           boolean FIN = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUResponseHeader_in_APDUHeaderParser.header.aAPDUHeader.control.FIN); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("           boolean CON = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUResponseHeader_in_APDUHeaderParser.header.aAPDUHeader.control.CON); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("           boolean UNS = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUResponseHeader_in_APDUHeaderParser.header.aAPDUHeader.control.UNS); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("           uint8_t SEQ = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                                            rResult_for_APDUResponseHeader_in_APDUHeaderParser.header.aAPDUHeader.control.SEQ); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "                 ---FunctionCode_uint8_t function---");

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("                 uint16_t function = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                                                rResult_for_APDUResponseHeader_in_APDUHeaderParser.header.aAPDUHeader.function);

 loghandler.LogEntry("");

 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---RSeq_for_Uint16_t payload---");

 uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser.objects.hHasLength));
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t   length = "), len); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("    uint8_t buffer_[] = ");

 loghandler.logHandlerStampCharArray(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser.objects.buffer_, len);
}
//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------
//-------------------ParsedRequest------------------------

void inspect_ParsedRequest(Memory_ParsedRequest* pMemory_ParsedRequest);

void inspect_ParsedRequest(Memory_ParsedRequest* pMemory_ParsedRequest)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_ParsedRequest->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("-ParsedRequest-");
 loghandler.LogEntryShort("===========================");

 loghandler.LogEntry("");

 loghandler.logHandlerStampInteger((" counter = "), pMemory_ParsedRequest->counter_inspect);

 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_ParsedRequest->pParsedRequest);

//- - - - - - - - - - - - - - - - - - - - Addresses addresses- - - - - - - - - - -  - - 
 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---Addresses addresses---");

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t source      = "), pMemory_ParsedRequest->mParsedRequest.addresses.source);

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t destination = "), pMemory_ParsedRequest->mParsedRequest.addresses.destination); 
//- - - - - - - - - - - - - - - - - - - - Addresses addresses- - - - - - - - - - -  - - 

//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - - 
 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---APDUHeader header---");
 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "         ---AppControlField control---");
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean FIR = "), pMemory_ParsedRequest->
                                                            mParsedRequest.header.control.FIR); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean FIN = "), pMemory_ParsedRequest->
                                                            mParsedRequest.header.control.FIN); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean CON = "), pMemory_ParsedRequest->
                                                            mParsedRequest.header.control.CON); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean UNS = "), pMemory_ParsedRequest->
                                                            mParsedRequest.header.control.UNS); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t SEQ = "), pMemory_ParsedRequest->
                                                            mParsedRequest.header.control.SEQ); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntry(               "         ---FunctionCode_uint8_t function---");

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("         uint16_t function = "), pMemory_ParsedRequest->
                                                                mParsedRequest.header.function);
//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - - 

 loghandler.LogEntry("");
 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---RSeq_for_Uint16_t objects---");

 uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_ParsedRequest->mParsedRequest.objects.hHasLength));
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint16_t   length = "), len); 

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("    uint8_t buffer_[] = ");

 loghandler.logHandlerStampCharArray(pMemory_ParsedRequest->mParsedRequest.objects.buffer_, len);
}
//-------------------ParsedRequest------------------------
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
void inspect_PairSer4cpp_for_IINField_AppControlField(Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField);

void inspect_PairSer4cpp_for_IINField_AppControlField(Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_PairSer4cpp_for_IINField_AppControlField->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("=====");
 loghandler.LogEntryShort("-PairSer4cpp_for_IINField_AppControlField-");
 loghandler.LogEntryShort("=====");

 loghandler.LogEntry("");
 loghandler.logHandlerStampInteger((" counter = "), pMemory_PairSer4cpp_for_IINField_AppControlField->counter_inspect);
 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_PairSer4cpp_for_IINField_AppControlField->pPairSer4cpp_for_IINField_AppControlField);

//- - - - - - - - - - - - - - - - - - - - IINField first- - - - - - - - - - -  - - 
 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---IINField first---");
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t LSB = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.first.LSB); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t MSB = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.first.MSB); 
//- - - - - - - - - - - - - - - - - - - - IINField first- - - - - - - - - - -  - - 
//- - - - - - - - - - - - - - - - - - - - AppControlField second- - - - - - - - - - -  - - 
 loghandler.LogEntryShort(title);
 loghandler.LogEntry("---AppControlField second---");
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean FIR = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.second.FIR); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean FIN = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.second.FIN); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean CON = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.second.CON); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    boolean UNS = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.second.UNS); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t SEQ = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                                            mPairSer4cpp_for_IINField_AppControlField.second.SEQ); 
//- - - - - - - - - - - - - - - - - - - - AppControlField second- - - - - - - - - - -  - - 
 loghandler.LogEntry("");
}
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
//-------------------ObjectHeader------------------------
void inspect_ObjectHeader(Memory_ObjectHeader* pMemory_ObjectHeader);

void inspect_ObjectHeader(Memory_ObjectHeader* pMemory_ObjectHeader)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_ObjectHeader->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("=====");
 loghandler.LogEntryShort("-ObjectHeader-");
 loghandler.LogEntryShort("=====");

 loghandler.LogEntry("");
 loghandler.logHandlerStampInteger((" counter = "), pMemory_ObjectHeader->counter_inspect);
 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_ObjectHeader->pObjectHeader);

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t group = "), pMemory_ObjectHeader->
                                                            mObjectHeader.group); 
 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t variation = "), pMemory_ObjectHeader->
                                                            mObjectHeader.variation); 

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t qualifier = "), pMemory_ObjectHeader->
                                                            mObjectHeader.qualifier); 

 loghandler.LogEntry("");
}
//-------------------ObjectHeader------------------------
//-------------------GroupVariationRecord------------------------
void inspect_GroupVariationRecord(Memory_GroupVariationRecord* pMemory_GroupVariationRecord);

void inspect_GroupVariationRecord(Memory_GroupVariationRecord* pMemory_GroupVariationRecord)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 void** tt = (void**)pMemory_GroupVariationRecord->title;
 char *title = (char*)tt[0];

 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("=====");
 loghandler.LogEntryShort("-GroupVariationRecord-");
 loghandler.LogEntryShort("=====");

 loghandler.LogEntry("");
 loghandler.logHandlerStampInteger((" counter = "), pMemory_GroupVariationRecord->counter_inspect);
 loghandler.logHandlerStampInteger32((" adr     = "), (uint32_t)pMemory_GroupVariationRecord->pGroupVariationRecord);

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    GroupVariation_uint16_t enumeration = "), pMemory_GroupVariationRecord->
                                                            mGroupVariationRecord.enumeration); 

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    GroupVariationType_int32_t type = "), pMemory_GroupVariationRecord->
                                                            mGroupVariationRecord.type); 

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t group = "), pMemory_GroupVariationRecord->
                                                            mGroupVariationRecord.group); 

 loghandler.LogEntryShort(title);
 loghandler.logHandlerStampInteger(("    uint8_t variation = "), pMemory_GroupVariationRecord->
                                                            mGroupVariationRecord.variation); 

 loghandler.LogEntry("");
}
//-------------------GroupVariationRecord------------------------
