#include "loghandler.h"

#include "header.h"
#include "Message.h"
#include "Addresses.h"

//void loghandler_EvenLists();
// extern EventStorage *pEventStorage;

void inspect_Message(const char * title, Message *pMessage);

void inspect_Message(const char * title, Message *pMessage)
{
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));

 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("-Message-");
 loghandler.LogEntryShort(title);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry("---Addresses addresses---");
 loghandler.logHandlerStampInteger(("    uint16_t source      = "), pMessage->addresses.source);
 loghandler.logHandlerStampInteger(("    uint16_t destination = "), pMessage->addresses.destination); 

 loghandler.LogEntry("");
 loghandler.LogEntry("---RSeq_for_Uint16_t payload---");
uint16_t len = length_in_HasLength_for_Uint16_t(&(pMessage->payload.hHasLength));
 loghandler.logHandlerStampInteger(("    uint16_t   length = "), len); 
           loghandler.LogEntryShort("    uint8_t buffer_[] = ");
 loghandler.logHandlerStampCharArray(pMessage->payload.buffer_, len);

/*
 loghandler.LogEntry("");
 loghandler.LogEntry("");
 loghandler.LogEntry("");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("EventLists");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.LogEntry("EventClassCounters counters;");
 loghandler.LogEntry("List_for_EventRecord events;");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("EventLists");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");


 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("EventClassCounters counters");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.LogEntry("ClazzCount total;");
 loghandler.LogEntry("ClazzCount written;");
 loghandler.logHandlerStampInteger(("uint32_t selected = "), pEventStorage->state.counters.selected);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("EventClassCounters counters");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");

 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount total");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.logHandlerStampInteger(("uint32_t num_class_1 = "), pEventStorage->state.counters.total.num_class_1);
 loghandler.logHandlerStampInteger(("uint32_t num_class_2 = "), pEventStorage->state.counters.total.num_class_2);
 loghandler.logHandlerStampInteger(("uint32_t num_class_3 = "), pEventStorage->state.counters.total.num_class_3);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount total");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");

 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount written");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.logHandlerStampInteger(("uint32_t num_class_1 = "), pEventStorage->state.counters.written.num_class_1);
 loghandler.logHandlerStampInteger(("uint32_t num_class_2 = "), pEventStorage->state.counters.written.num_class_2);
 loghandler.logHandlerStampInteger(("uint32_t num_class_3 = "), pEventStorage->state.counters.written.num_class_3);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount written");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
*/
}

