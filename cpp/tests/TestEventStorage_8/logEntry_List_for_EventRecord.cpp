#include "loghandler.h"

#include "header.h"
#include "EventStorage.h"

void loghandler_List_for_EventRecord();
 extern EventStorage storage;

void loghandler_List_for_EventRecord()
{
 loghandler.LogEntry("");
 loghandler.LogEntry("");
 loghandler.LogEntry("");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("List_for_EventRecord");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.LogEntry("Iterator_in_List_for_EventRecord iIterator_in_List_for_EventRecord");
 loghandler.LogEntry("");
 loghandler.LogEntry("HasLength_for_Uint32_t hHasLength_for_Uint32_t");
 loghandler.logHandlerStampInteger(("hHasLength_for_Uint32_t.m_length = "), storage.state.events.hHasLength_for_Uint32_t.m_length);
 loghandler.LogEntry("");

// loghandler.LogEntry("Node_for_EventRecord* head");
 loghandler.logHandlerStampInteger(("Node_for_EventRecord* head = "), (unsigned int)storage.state.events.head);
 loghandler.logHandlerStampInteger(("Node_for_EventRecord* tail = "), (unsigned int)storage.state.events.tail);
 loghandler.logHandlerStampInteger(("Node_for_EventRecord* free = "), (unsigned int)storage.state.events.free);
 loghandler.LogEntry("");
 loghandler.LogEntry("Array__for__Node_for_EventRecord  underlying");
 loghandler.logHandlerStampInteger(("underlying.hHasLength_for_Uint32_t.m_length = "), storage.state.events.underlying.hHasLength_for_Uint32_t.m_length);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("List_for_EventRecord");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
}