
//#include <QtWidgets>
#include <iostream>
#include <string>
#include "log_info.h"
#include "loghandler.h"

#include "header.h"
#include "IEventType.h"


static int16_t stack_info = -1;//рівень стеку для info

void inspect_ClassField(ClassField *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_ClassField**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*uint8_t bitfield= "<<(uint16_t)b->bitfield<<'\n';
}

void inspect_IINField(IINField *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_IINField**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*uint8_t LSB= "<<(uint16_t)b->LSB<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*uint8_t MSB= "<<(uint16_t)b->MSB<<'\n';
}

void inspect_DNPTime(DNPTime *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_DNPTime**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*uint64_t value= "<<(uint32_t)b->value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*TimestampQuality_uint8_t quality= "<<(uint32_t)b->quality<<'\n';
}

void inspect_Analog(Analog *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_Analog**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*boolean value= "<<(uint16_t)b->tTypedMeasurement_for_Double64.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*Flags flags.value= "<<(uint16_t)b->tTypedMeasurement_for_Double64.mMeasurement.flags.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.value= "<<(uint32_t)b->tTypedMeasurement_for_Double64.mMeasurement.timeDNPTime.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.quality= "<<(uint32_t)b->tTypedMeasurement_for_Double64.mMeasurement.timeDNPTime.quality<<'\n';
}
void inspect_Binary(Binary *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_Binary**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*boolean value= "<<(uint16_t)b->tTypedMeasurement_for_Boolean.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*Flags flags.value= "<<(uint16_t)b->tTypedMeasurement_for_Boolean.mMeasurement.flags.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.value= "<<(uint32_t)b->tTypedMeasurement_for_Boolean.mMeasurement.timeDNPTime.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.quality= "<<(uint32_t)b->tTypedMeasurement_for_Boolean.mMeasurement.timeDNPTime.quality<<'\n';
}
void inspect_Indexed_for_Binary(Indexed_for_Binary *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_Indexed_for_Binary**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*uint16_t index= "<<(uint16_t)b->index<<'\n';
  inspect_Binary(&(b->value));
}
void inspect_Counter(Counter *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_Counter**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*boolean value= "<<(uint16_t)b->tTypedMeasurement_for_Uint32.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*Flags flags.value= "<<(uint16_t)b->tTypedMeasurement_for_Uint32.mMeasurement.flags.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.value= "<<(uint32_t)b->tTypedMeasurement_for_Uint32.mMeasurement.timeDNPTime.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.quality= "<<(uint32_t)b->tTypedMeasurement_for_Uint32.mMeasurement.timeDNPTime.quality<<'\n';
}
void inspect_FrozenCounter(FrozenCounter *b)
{
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_FrozenCounter**"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*boolean value= "<<(uint16_t)b->tTypedMeasurement_for_Uint32.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*Flags flags.value= "<<(uint16_t)b->tTypedMeasurement_for_Uint32.mMeasurement.flags.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.value= "<<(uint32_t)b->tTypedMeasurement_for_Uint32.mMeasurement.timeDNPTime.value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*DNPTime timeDNPTime.quality= "<<(uint32_t)b->tTypedMeasurement_for_Uint32.mMeasurement.timeDNPTime.quality<<'\n';
}

int16_t get_stack_info(void);
int16_t get_stack_info(void)
{
  return stack_info;
}

void increment_stack_info(void)
{
  stack_info ++;
}

void decrement_stack_info(void)
{
  stack_info --;
  if(stack_info < 0) stack_info = 0;
}

std::string getString_stack_info(void)
{
  std::string name("    ");       
  std::string res("");       
  for(int i=0; i<stack_info; i++) res = res + name;
  return res;
}

void inspect_RSeq(RSeq_for_Uint16_t *buffer)
{
 if(!buffer) return;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"**inspect_RSeq**"<<'\n';
  for(int i=0; i<length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)); i++)
 {
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@*buffer->buffer_[i]= "<<std::hex<<(uint16_t)buffer->buffer_[i]<<std::dec<<'\n';
 }//for
}

#ifdef TTTTT
void inspect_WSeq(WSeq_for_Uint16_t *buffer)
{
 if(!buffer) return;
  for(int i=0; i<length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)); i++)
 {
  std::cout<<"*"<<getString_stack_info();
  qDebug()<<"*buffer->buffer_[i]= "<<hex<<buffer->buffer_[i];
 }//for
}

//-------------------Message------------------------
void inspect_Message(Memory_Message* pMemory_Message, int maxCount);

void inspect_Message(Memory_Message* pMemory_Message, int maxCount)
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

  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_Message->pMessage);

  for(uint16_t idxInspect=0; idxInspect<pMemory_Message->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_Message) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---Addresses addresses---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t source      = "), pMemory_Message->mMessage[idxInspect].addresses.source);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t destination = "), pMemory_Message->mMessage[idxInspect].addresses.destination);

    loghandler.LogEntry("");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---RSeq_for_Uint16_t payload---");

    uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_Message->mMessage[idxInspect].payload.hHasLength));
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t   length = "), len);

    loghandler.LogEntryShort(title);
    loghandler.LogEntryShort("    uint8_t buffer_[] = ");

    loghandler.logHandlerStampCharArray(pMemory_Message->mMessage[idxInspect].payload.buffer_, len);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------Message------------------------
//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

void inspect_Result_for_APDUHeader_in_APDUHeaderParser(Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser, int maxCount);

void inspect_Result_for_APDUHeader_in_APDUHeaderParser(Memory_Result_for_APDUHeader_in_APDUHeaderParser* pMemory_Result_for_APDUHeader_in_APDUHeaderParser, int maxCount)
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
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_Result_for_APDUHeader_in_APDUHeaderParser->pResult_for_APDUHeader_in_APDUHeaderParser);

  for(uint16_t idxInspect=0; idxInspect<pMemory_Result_for_APDUHeader_in_APDUHeaderParser->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_Result_for_APDUHeader_in_APDUHeaderParser) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
//  loghandler.LogEntry("");
//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - -
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---APDUHeader header---");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "         ---AppControlField control---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean FIR = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                      rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].header.control.FIR);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean FIN = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                      rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].header.control.FIN);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean CON = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                      rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].header.control.CON);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean UNS = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                      rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].header.control.UNS);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t SEQ = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                      rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].header.control.SEQ);

    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "         ---FunctionCode_uint8_t function---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("         uint16_t function = "), pMemory_Result_for_APDUHeader_in_APDUHeaderParser->
                                      rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].header.function);
//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - -

    loghandler.LogEntry("");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---RSeq_for_Uint16_t objects---");

    uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].objects.hHasLength));
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t   length = "), len);

    loghandler.LogEntryShort(title);
    loghandler.LogEntryShort("    uint8_t buffer_[] = ");

    loghandler.logHandlerStampCharArray(pMemory_Result_for_APDUHeader_in_APDUHeaderParser->rResult_for_APDUHeader_in_APDUHeaderParser[idxInspect].objects.buffer_, len);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}

//-------------------Result_for_APDUHeader_in_APDUHeaderParser------------------------

//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------

void inspect_Result_for_APDUResponseHeader_in_APDUHeaderParser(Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser, int maxCount);

void inspect_Result_for_APDUResponseHeader_in_APDUHeaderParser(Memory_Result_for_APDUResponseHeader_in_APDUHeaderParser* pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser, int maxCount)
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

  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->pResult_for_APDUResponseHeader_in_APDUHeaderParser);

  for(uint16_t idxInspect=0; idxInspect<pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_Result_for_APDUResponseHeader_in_APDUHeaderParser) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---APDUResponseHeader header---");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "         ---APDUHeader aAPDUHeader---");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "                 ---AppControlField control---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("           boolean FIR = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                      rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].header.aAPDUHeader.control.FIR);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("           boolean FIN = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                      rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].header.aAPDUHeader.control.FIN);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("           boolean CON = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                      rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].header.aAPDUHeader.control.CON);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("           boolean UNS = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                      rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].header.aAPDUHeader.control.UNS);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("           uint8_t SEQ = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                      rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].header.aAPDUHeader.control.SEQ);

    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "                 ---FunctionCode_uint8_t function---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("                 uint16_t function = "), pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->
                                      rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].header.aAPDUHeader.function);

    loghandler.LogEntry("");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---RSeq_for_Uint16_t payload---");

    uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].objects.hHasLength));
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t   length = "), len);

    loghandler.LogEntryShort(title);
    loghandler.LogEntryShort("    uint8_t buffer_[] = ");

    loghandler.logHandlerStampCharArray(pMemory_Result_for_APDUResponseHeader_in_APDUHeaderParser->rResult_for_APDUResponseHeader_in_APDUHeaderParser[idxInspect].objects.buffer_, len);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------Result_for_APDUResponseHeader_in_APDUHeaderParser------------------------
//-------------------ParsedRequest------------------------

void inspect_ParsedRequest(Memory_ParsedRequest* pMemory_ParsedRequest, int maxCount);

void inspect_ParsedRequest(Memory_ParsedRequest* pMemory_ParsedRequest, int maxCount)
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

  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_ParsedRequest->pParsedRequest);

  for(uint16_t idxInspect=0; idxInspect<pMemory_ParsedRequest->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_ParsedRequest) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

//- - - - - - - - - - - - - - - - - - - - Addresses addresses- - - - - - - - - - -  - -
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---Addresses addresses---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t source      = "), pMemory_ParsedRequest->mParsedRequest[idxInspect].addresses.source);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t destination = "), pMemory_ParsedRequest->mParsedRequest[idxInspect].addresses.destination);
//- - - - - - - - - - - - - - - - - - - - Addresses addresses- - - - - - - - - - -  - -

//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - -
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---APDUHeader header---");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "         ---AppControlField control---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean FIR = "), pMemory_ParsedRequest->
                                      mParsedRequest[idxInspect].header.control.FIR);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean FIN = "), pMemory_ParsedRequest->
                                      mParsedRequest[idxInspect].header.control.FIN);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean CON = "), pMemory_ParsedRequest->
                                      mParsedRequest[idxInspect].header.control.CON);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean UNS = "), pMemory_ParsedRequest->
                                      mParsedRequest[idxInspect].header.control.UNS);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t SEQ = "), pMemory_ParsedRequest->
                                      mParsedRequest[idxInspect].header.control.SEQ);

    loghandler.LogEntryShort(title);
    loghandler.LogEntry(               "         ---FunctionCode_uint8_t function---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("         uint16_t function = "), pMemory_ParsedRequest->
                                      mParsedRequest[idxInspect].header.function);
//- - - - - - - - - - - - - - - - - - - - APDUHeader header- - - - - - - - - - -  - -

    loghandler.LogEntry("");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---RSeq_for_Uint16_t objects---");

    uint16_t len = length_in_HasLength_for_Uint16_t(&(pMemory_ParsedRequest->mParsedRequest[idxInspect].objects.hHasLength));
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint16_t   length = "), len);

    loghandler.LogEntryShort(title);
    loghandler.LogEntryShort("    uint8_t buffer_[] = ");

    loghandler.logHandlerStampCharArray(pMemory_ParsedRequest->mParsedRequest[idxInspect].objects.buffer_, len);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------ParsedRequest------------------------
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
void inspect_PairSer4cpp_for_IINField_AppControlField(Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField, int maxCount);

void inspect_PairSer4cpp_for_IINField_AppControlField(Memory_PairSer4cpp_for_IINField_AppControlField* pMemory_PairSer4cpp_for_IINField_AppControlField, int maxCount)
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
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_PairSer4cpp_for_IINField_AppControlField->pPairSer4cpp_for_IINField_AppControlField);

  for(uint16_t idxInspect=0; idxInspect<pMemory_PairSer4cpp_for_IINField_AppControlField->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_PairSer4cpp_for_IINField_AppControlField) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
//- - - - - - - - - - - - - - - - - - - - IINField first- - - - - - - - - - -  - -
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---IINField first---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger32Hex(("    uint8_t LSB = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                           mPairSer4cpp_for_IINField_AppControlField[idxInspect].first.LSB);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger32Hex(("    uint8_t MSB = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                           mPairSer4cpp_for_IINField_AppControlField[idxInspect].first.MSB);
//- - - - - - - - - - - - - - - - - - - - IINField first- - - - - - - - - - -  - -
//- - - - - - - - - - - - - - - - - - - - AppControlField second- - - - - - - - - - -  - -
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---AppControlField second---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean FIR = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                      mPairSer4cpp_for_IINField_AppControlField[idxInspect].second.FIR);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean FIN = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                      mPairSer4cpp_for_IINField_AppControlField[idxInspect].second.FIN);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean CON = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                      mPairSer4cpp_for_IINField_AppControlField[idxInspect].second.CON);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    boolean UNS = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                      mPairSer4cpp_for_IINField_AppControlField[idxInspect].second.UNS);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t SEQ = "), pMemory_PairSer4cpp_for_IINField_AppControlField->
                                      mPairSer4cpp_for_IINField_AppControlField[idxInspect].second.SEQ);
//- - - - - - - - - - - - - - - - - - - - AppControlField second- - - - - - - - - - -  - -
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------PairSer4cpp_for_IINField_AppControlField------------------------
//-------------------ObjectHeader------------------------
void inspect_ObjectHeader(Memory_ObjectHeader* pMemory_ObjectHeader, int maxCount);

void inspect_ObjectHeader(Memory_ObjectHeader* pMemory_ObjectHeader, int maxCount)
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
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_ObjectHeader->pObjectHeader);

  for(uint16_t idxInspect=0; idxInspect<pMemory_ObjectHeader->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_ObjectHeader) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t group = "), pMemory_ObjectHeader->
                                      mObjectHeader[idxInspect].group);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t variation = "), pMemory_ObjectHeader->
                                      mObjectHeader[idxInspect].variation);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t qualifier = "), pMemory_ObjectHeader->
                                      mObjectHeader[idxInspect].qualifier);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------ObjectHeader------------------------
//-------------------GroupVariationRecord------------------------
void inspect_GroupVariationRecord(Memory_GroupVariationRecord* pMemory_GroupVariationRecord, int maxCount);

void inspect_GroupVariationRecord(Memory_GroupVariationRecord* pMemory_GroupVariationRecord, int maxCount)
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
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_GroupVariationRecord->pGroupVariationRecord);

  for(uint16_t idxInspect=0; idxInspect<pMemory_GroupVariationRecord->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_GroupVariationRecord) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    GroupVariation_uint16_t enumeration = "), pMemory_GroupVariationRecord->
                                      mGroupVariationRecord[idxInspect].enumeration);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    GroupVariationType_int32_t type = "), pMemory_GroupVariationRecord->
                                      mGroupVariationRecord[idxInspect].type);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t group = "), pMemory_GroupVariationRecord->
                                      mGroupVariationRecord[idxInspect].group);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t variation = "), pMemory_GroupVariationRecord->
                                      mGroupVariationRecord[idxInspect].variation);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------GroupVariationRecord------------------------
//-------------------HeaderRecord------------------------
void inspect_HeaderRecord(Memory_HeaderRecord* pMemory_HeaderRecord, int maxCount);

void inspect_HeaderRecord(Memory_HeaderRecord* pMemory_HeaderRecord, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_HeaderRecord->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-HeaderRecord-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_HeaderRecord->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_HeaderRecord->pHeaderRecord);

  for(uint16_t idxInspect=0; idxInspect<pMemory_HeaderRecord->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_HeaderRecord) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---GroupVariationRecord gGroupVariationRecord---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampIntegerHex(("    GroupVariation_uint16_t enumeration = "), pMemory_HeaderRecord->
                                         mHeaderRecord[idxInspect].gGroupVariationRecord.enumeration);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    GroupVariationType_int32_t type = "), pMemory_HeaderRecord->
                                      mHeaderRecord[idxInspect].gGroupVariationRecord.type);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t group = "), pMemory_HeaderRecord->
                                      mHeaderRecord[idxInspect].gGroupVariationRecord.group);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    uint8_t variation = "), pMemory_HeaderRecord->
                                      mHeaderRecord[idxInspect].gGroupVariationRecord.variation);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("uint8_t qualifier = "), pMemory_HeaderRecord->mHeaderRecord[idxInspect].qualifier);
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("uint8_t headerIndex = "), pMemory_HeaderRecord->mHeaderRecord[idxInspect].headerIndex);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------HeaderRecord------------------------
//-------------------EventLists------------------------
void inspect_EventLists(Memory_EventLists* pMemory_EventLists, int maxCount);

void inspect_EventLists(Memory_EventLists* pMemory_EventLists, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_EventLists->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-EventLists-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_EventLists->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_EventLists->pEventLists);

  for(uint16_t idxInspect=0; idxInspect<pMemory_EventLists->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_EventLists) break;
    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---List_for_EventRecord events---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    sizeof(events) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].events));

    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry("     -1-Iterator_in_List_for_EventRecord iIterator_in_List_for_EventRecord-1-");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("         sizeof(iIterator_in_List_for_EventRecord) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].events.iIterator_in_List_for_EventRecord));
    loghandler.LogEntry("");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger32Hex(("         -1.1-Node_for_EventRecord * current= "), (uint32_t)pMemory_EventLists->mEventLists[idxInspect].events.iIterator_in_List_for_EventRecord.current);

    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry("     -2-HasLength_for_Uint32_t hHasLength_for_Uint32_t-2-");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("         uint32_t m_length = "), pMemory_EventLists->mEventLists[idxInspect].
        events.hHasLength_for_Uint32_t.m_length);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger32Hex("     -3-Node_for_EventRecord* head= ", (uint32_t)pMemory_EventLists->mEventLists[idxInspect].
        events.head);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger32Hex("     -4-Node_for_EventRecord* tail= ", (uint32_t)pMemory_EventLists->mEventLists[idxInspect].
        events.tail);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger32Hex("     -5-Node_for_EventRecord* free= ", (uint32_t)pMemory_EventLists->mEventLists[idxInspect].
        events.free);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry("     -6-Array__for__Node_for_EventRecord  underlying-6-");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("         sizeof(underlying) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].events.underlying));

    loghandler.LogEntry("");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.LogEntry("         -6.1-HasLength_for_Uint32_t hHasLength_for_Uint32_t-6.1-");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("             uint32_t m_length = "), pMemory_EventLists->mEventLists[idxInspect].
        events.underlying.hHasLength_for_Uint32_t.m_length);
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.LogEntry("         -6.2-Node_for_EventRecord buffer[SIZE_for_EventRecord]-6.2-");
    /*            */loghandler.LogEntryShort(title);
    /*            */Node_for_EventRecord *pNode_for_EventRecordBuffer = pMemory_EventLists->mEventLists[idxInspect].events.underlying.buffer;
    /*            */loghandler.logHandlerStampInteger(("             sizeof(buffer) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].events.underlying.buffer));

    loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.1-EventRecord value-3-(index, clazz, state)= ");
    /*                */for(int i=0; i<SIZE_for_EventRecord; i++)
      /*                */{
      /*                */loghandler.LogEntryShort("{");
      /*                */uint16_t buffer_[3];
      buffer_[0] = pNode_for_EventRecordBuffer[i].value.index;
      buffer_[1] = pNode_for_EventRecordBuffer[i].value.clazz;
      buffer_[2] = pNode_for_EventRecordBuffer[i].value.state;
      /*                */loghandler.logHandlerStampShortArray(buffer_, 3);
      /*                */loghandler.LogEntryShort("}");
      /*                */
    }//for
    /*                */loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.1-EventRecord value-3-(type, storage_node)= ");
    /*                */for(int i=0; i<SIZE_for_EventRecord; i++)
      /*                */{
      /*                */loghandler.LogEntryShort("{");
      /*                */uint32_t buffer_[2];
      buffer_[0] = (uint32_t)pNode_for_EventRecordBuffer[i].value.type;
      buffer_[1] = (uint32_t)pNode_for_EventRecordBuffer[i].value.storage_node;
      /*                */loghandler.logHandlerStampInt32Array(buffer_, 2);
      /*                */loghandler.LogEntryShort("}");
      /*                */
    }//for
    /*                */loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.2-Node_for_EventRecord * prev= ");
    /*                */for(int i=0; i<SIZE_for_EventRecord; i++)
      /*                */{
      /*                */uint32_t buffer_[1];
      buffer_[0] = (uint32_t)pNode_for_EventRecordBuffer[i].prev;
      /*                */loghandler.logHandlerStampInt32Array(buffer_, 1);
      /*                */
    }//for
    /*                */loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.3-Node_for_EventRecord * next= ");
    /*                */for(int i=0; i<SIZE_for_EventRecord; i++)
      /*                */{
      /*                */uint32_t buffer_[1];
      buffer_[0] = (uint32_t)pNode_for_EventRecordBuffer[i].next;
      /*                */loghandler.logHandlerStampInt32Array(buffer_, 1);
      /*                */
    }//for
    /*                */loghandler.LogEntry("");

    loghandler.LogEntry("");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---EventClassCounters counters---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("    sizeof(counters) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].counters));
    /*        */loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("     -1-uint32_t selected= "), pMemory_EventLists->mEventLists[idxInspect].counters.selected);
    /*        */loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry(("     -2-ClazzCount total-2-"));
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("    sizeof(total) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].counters.total));
    /*            */loghandler.LogEntry("");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("         -2.1-uint32_t num_class_1= "), pMemory_EventLists->mEventLists[idxInspect].counters.total.num_class_1);
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("         -2.2-uint32_t num_class_2= "), pMemory_EventLists->mEventLists[idxInspect].counters.total.num_class_2);
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("         -2.3-uint32_t num_class_3= "), pMemory_EventLists->mEventLists[idxInspect].counters.total.num_class_3);
    /*        */loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry(("     -3-ClazzCount written-3-"));
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("    sizeof(written) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].counters.written));
    /*            */loghandler.LogEntry("");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("         -3.1-uint32_t num_class_1= "), pMemory_EventLists->mEventLists[idxInspect].counters.written.num_class_1);
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("         -3.2-uint32_t num_class_2= "), pMemory_EventLists->mEventLists[idxInspect].counters.written.num_class_2);
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("         -3.3-uint32_t num_class_3= "), pMemory_EventLists->mEventLists[idxInspect].counters.written.num_class_3);

    loghandler.LogEntry("");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---List_TypedEventRecord_for_BinarySpec binary---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("        sizeof(binary) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].binary));
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry("     -1-Iterator_in_List_TypedEventRecord_for_BinarySpec iIterator_in_List_TypedEventRecord_for_BinarySpec-1-");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("         sizeof(iIterator_in_List_TypedEventRecord_for_BinarySpec) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].binary.iIterator_in_List_TypedEventRecord_for_BinarySpec));
    loghandler.LogEntry("");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger32Hex(("         -1.1-Node_TypedEventRecord_for_BinarySpec * current= "), (uint32_t)pMemory_EventLists->mEventLists[idxInspect].binary.iIterator_in_List_TypedEventRecord_for_BinarySpec.current);

    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry("     -2-HasLength_for_Uint32_t hHasLength_for_Uint32_t-2-");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("         uint32_t m_length = "), pMemory_EventLists->mEventLists[idxInspect].
        binary.hHasLength_for_Uint32_t.m_length);

    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger32Hex("     -3-Node_TypedEventRecord_for_BinarySpec* head= ", (uint32_t)pMemory_EventLists->mEventLists[idxInspect].
        binary.head);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger32Hex("     -4-Node_TypedEventRecord_for_BinarySpec* tail= ", (uint32_t)pMemory_EventLists->mEventLists[idxInspect].
        binary.tail);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger32Hex("     -5-Node_TypedEventRecord_for_BinarySpec* free= ", (uint32_t)pMemory_EventLists->mEventLists[idxInspect].
        binary.free);
    loghandler.LogEntry("");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.LogEntry("     -6-Array__for__Node_TypedEventRecord_for_BinarySpec  underlying-6-");
    /*        */loghandler.LogEntryShort(title);
    /*        */loghandler.logHandlerStampInteger(("         sizeof(underlying) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].binary.underlying));

    loghandler.LogEntry("");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.LogEntry("         -6.1-HasLength_for_Uint32_t hHasLength_for_Uint32_t-6.1-");
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.logHandlerStampInteger(("             uint32_t m_length = "), pMemory_EventLists->mEventLists[idxInspect].
        binary.underlying.hHasLength_for_Uint32_t.m_length);
    /*            */loghandler.LogEntryShort(title);
    /*            */loghandler.LogEntry("         -6.2-Node_TypedEventRecord_for_BinarySpec buffer[SIZE_TypedEventRecord_for_BinarySpec]-6.2-");
    /*            */loghandler.LogEntryShort(title);
    /*            */Node_TypedEventRecord_for_BinarySpec *pNode_TypedEventRecord_for_BinarySpec = pMemory_EventLists->mEventLists[idxInspect].binary.underlying.buffer;
    /*            */loghandler.logHandlerStampInteger(("             sizeof(buffer) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].binary.underlying.buffer));

    loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.1-TypedEventRecord_for_BinarySpec value-3-(defaultVariation, selectedVariation)= ");
    /*                */for(int i=0; i<SIZE_TypedEventRecord_for_BinarySpec; i++)
      /*                */{
      /*                */loghandler.LogEntryShort("{");
      /*                */uint16_t buffer_[2];
      buffer_[0] = pNode_TypedEventRecord_for_BinarySpec[i].value.defaultVariation;
      buffer_[1] = pNode_TypedEventRecord_for_BinarySpec[i].value.selectedVariation;
      /*                */loghandler.logHandlerStampShortArray(buffer_, 2);
      /*                */loghandler.LogEntryShort("}");
      /*                */
    }//for
    loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.2-Node_for_EventRecord* record= ");
    /*                */for(int i=0; i<SIZE_TypedEventRecord_for_BinarySpec; i++)
      /*                */{
      /*                */uint32_t buffer_[1];
      buffer_[0] = (uint32_t)pNode_TypedEventRecord_for_BinarySpec[i].value.record;
      /*                */loghandler.logHandlerStampInt32Array(buffer_, 1);
      /*                */
    }//for
    /*                */ loghandler.LogEntry("");
    loghandler.LogEntry("");
    /*                */loghandler.LogEntryShort(title);
    /*                */loghandler.LogEntryShort("             -6.2.3-Binary value-6.2.3-(TypedMeasurement_for_Boolean tTypedMeasurement_for_Boolean)");
    /*                */for(int i=0; i<SIZE_TypedEventRecord_for_BinarySpec; i++)
      /*                */{
      /*                */loghandler.LogEntryShort("{");
      /*                */uint32_t buffer_[1];
      buffer_[0] = pNode_TypedEventRecord_for_BinarySpec[i].value.value.tTypedMeasurement_for_Boolean.value;
      /*                */loghandler.logHandlerStampInt32Array(buffer_, 1);
      /*                */loghandler.LogEntryShort("}");
      /*                */
    }//for
    /*                */ loghandler.LogEntry("");

    loghandler.LogEntry("");
    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---List_TypedEventRecord_for_AnalogSpec analog---");
    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("        sizeof(analog) = "), sizeof(pMemory_EventLists->mEventLists[idxInspect].analog));

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------EventLists------------------------
//-------------------EventRecord------------------------
void inspect_EventRecord(Memory_EventRecord* pMemory_EventRecord, int maxCount);

void inspect_EventRecord(Memory_EventRecord* pMemory_EventRecord, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_EventRecord->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-EventRecord-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_EventRecord->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_EventRecord->pEventRecord);

  for(uint16_t idxInspect=0; idxInspect<pMemory_EventRecord->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_EventRecord) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  uint16_t index = "), pMemory_EventRecord->mEventRecord[idxInspect].index);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  EventClass_uint8_t clazz = "), pMemory_EventRecord->mEventRecord[idxInspect].clazz);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  EventState_uint8_t state = "), pMemory_EventRecord->mEventRecord[idxInspect].state);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger32Hex(("  IEventType* type = "), (uint32_t)pMemory_EventRecord->mEventRecord[idxInspect].type);
    if(pMemory_EventRecord->mEventRecord[idxInspect].type)
    {
      loghandler.LogEntry("");
      loghandler.LogEntryShort(title);
      loghandler.LogEntry("---IEventType* type---");

      loghandler.LogEntryShort(title);
      loghandler.logHandlerStampInteger(("    EventType_uint16_t value = "), ((IEventType*)pMemory_EventRecord->mEventRecord[idxInspect].type)->value);
    }//if

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger32Hex(("  void* storage_node = "), (uint32_t)pMemory_EventRecord->mEventRecord[idxInspect].storage_node);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------EventRecord------------------------
//-------------------LinkHeader------------------------
void inspect_LinkHeader(Memory_LinkHeader* pMemory_LinkHeader, int maxCount);

void inspect_LinkHeader(Memory_LinkHeader* pMemory_LinkHeader, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_LinkHeader->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-LinkHeader-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_LinkHeader->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_LinkHeader->pLinkHeader);

  for(uint16_t idxInspect=0; idxInspect<pMemory_LinkHeader->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_LinkHeader) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  uint8_t length = "), pMemory_LinkHeader->mLinkHeader[idxInspect].length);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  uint16_t src = "), pMemory_LinkHeader->mLinkHeader[idxInspect].src);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  uint16_t dest = "), pMemory_LinkHeader->mLinkHeader[idxInspect].dest);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  uint8_t ctrl = "), pMemory_LinkHeader->mLinkHeader[idxInspect].ctrl);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------LinkHeader------------------------
//-------------------LinkHeaderFields------------------------
void inspect_LinkHeaderFields(Memory_LinkHeaderFields* pMemory_LinkHeaderFields, int maxCount);

void inspect_LinkHeaderFields(Memory_LinkHeaderFields* pMemory_LinkHeaderFields, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_LinkHeaderFields->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-LinkHeaderFields-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_LinkHeaderFields->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_LinkHeaderFields->pLinkHeaderFields);

  for(uint16_t idxInspect=0; idxInspect<pMemory_LinkHeaderFields->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_LinkHeaderFields) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  LinkFunction_uint8_t func = "), pMemory_LinkHeaderFields->mLinkHeaderFields[idxInspect].func);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  boolean isFromMaster = "), pMemory_LinkHeaderFields->mLinkHeaderFields[idxInspect].isFromMaster);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  boolean fcb = "), pMemory_LinkHeaderFields->mLinkHeaderFields[idxInspect].fcb);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("  boolean fcvdfc = "), pMemory_LinkHeaderFields->mLinkHeaderFields[idxInspect].fcvdfc);

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---Addresses addresses---");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("      uint16_t source = "), pMemory_LinkHeaderFields->mLinkHeaderFields[idxInspect].addresses.source);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger(("      uint16_t destination = "), pMemory_LinkHeaderFields->mLinkHeaderFields[idxInspect].addresses.destination);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------LinkHeaderFields------------------------
//-------------------IINField------------------------
void inspect_IINField(Memory_IINField* pMemory_IINField, int maxCount);

void inspect_IINField(Memory_IINField* pMemory_IINField, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_IINField->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-IINField-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_IINField->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_IINField->pIINField);

  for(uint16_t idxInspect=0; idxInspect<pMemory_IINField->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_IINField) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger32Hex(("  uint8_t LSB = "), pMemory_IINField->mIINField[idxInspect].LSB);

    loghandler.LogEntryShort(title);
    loghandler.logHandlerStampInteger32Hex(("  uint8_t MSB = "), pMemory_IINField->mIINField[idxInspect].MSB);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------IINField------------------------
//-------------------RangeHeader------------------------
void inspect_RangeHeader(Memory_RangeHeader* pMemory_RangeHeader, int maxCount);

void inspect_RangeHeader(Memory_RangeHeader* pMemory_RangeHeader, int maxCount)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

  void** tt = (void**)pMemory_RangeHeader->title;
  char *title = (char*)tt[0];

  loghandler.LogEntryShort(title);
  loghandler.LogEntryShort("=====");
  loghandler.LogEntryShort("-RangeHeader-");
  loghandler.LogEntryShort("=====");

  loghandler.LogEntry("");
  loghandler.logHandlerStampInteger((" counter = "), pMemory_RangeHeader->counter_inspect);
  loghandler.logHandlerStampInteger32Hex((" adr     = "), (uint32_t)pMemory_RangeHeader->pRangeHeader);

  for(uint16_t idxInspect=0; idxInspect<pMemory_RangeHeader->counter_inspect; idxInspect++)
  {
    if(idxInspect==maxCount) break;
    if(idxInspect==COUNT_RangeHeader) break;

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("---HeaderRecord hHeaderRecord---");

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("    ------GroupVariationRecord gGroupVariationRecord------");

    loghandler.LogEntryShort((char*)"*GroupVariationRecord");
    loghandler.logHandlerStampIntegerHex(("       GroupVariation_uint16_t enumeration = "), pMemory_RangeHeader->
                                         mRangeHeader[idxInspect].hHeaderRecord.gGroupVariationRecord.enumeration);

    loghandler.LogEntryShort((char*)"*GroupVariationRecord");
    loghandler.logHandlerStampInteger(("       GroupVariationType_int32_t type = "), pMemory_RangeHeader->
                                      mRangeHeader[idxInspect].hHeaderRecord.gGroupVariationRecord.type);

    loghandler.LogEntryShort((char*)"*GroupVariationRecord");
    loghandler.logHandlerStampInteger(("       uint8_t group = "), pMemory_RangeHeader->
                                      mRangeHeader[idxInspect].hHeaderRecord.gGroupVariationRecord.group);

    loghandler.LogEntryShort((char*)"*GroupVariationRecord");
    loghandler.logHandlerStampInteger(("       uint8_t variation = "), pMemory_RangeHeader->
                                      mRangeHeader[idxInspect].hHeaderRecord.gGroupVariationRecord.variation);

    loghandler.LogEntryShort((char*)"*GroupVariationRecord");
    loghandler.logHandlerStampInteger(("  uint8_t qualifier = "), pMemory_RangeHeader->
                                                 mRangeHeader[idxInspect].hHeaderRecord.qualifier);
    loghandler.LogEntryShort((char*)"*GroupVariationRecord");
    loghandler.logHandlerStampInteger(("  uint8_t headerIndex = "), pMemory_RangeHeader->
                                                 mRangeHeader[idxInspect].hHeaderRecord.headerIndex);

    loghandler.LogEntryShort(title);
    loghandler.LogEntry("    ------Range range------");

    loghandler.LogEntryShort((char*)"*Range");
    loghandler.logHandlerStampInteger32Hex(("  uint16_t start = "), pMemory_RangeHeader->mRangeHeader[idxInspect].range.start);

    loghandler.LogEntryShort((char*)"*Range");
    loghandler.logHandlerStampInteger32Hex(("  uint16_t stop = "), pMemory_RangeHeader->mRangeHeader[idxInspect].range.stop);

    loghandler.logHandlerStampInteger(("|-- "), idxInspect+1);
    loghandler.LogEntry("|----------------------------------------------------");
    loghandler.LogEntry("");
  }//for
}
//-------------------RangeHeader------------------------
#endif
