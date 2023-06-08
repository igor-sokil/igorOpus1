#include "loghandler.h"

#include "header.h"
#include "EventStorage.h"

void loghandler_List_TypedEventRecord_for_AnalogSpec();
 extern EventStorage *pEventStorage;

void loghandler_List_TypedEventRecord_for_AnalogSpec()
{
 loghandler.LogEntry("");
 loghandler.LogEntry("");
 loghandler.LogEntry("");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("List_TypedEventRecord_for_AnalogSpec");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.LogEntry("Iterator_in_List_TypedEventRecord_for_AnalogSpec iIterator_in_List_TypedEventRecord_for_AnalogSpec");
 loghandler.LogEntry("");
 loghandler.LogEntry("HasLength_for_Uint32_t hHasLength_for_Uint32_t");
 loghandler.logHandlerStampInteger(("hHasLength_for_Uint32_t.m_length = "), pEventStorage->state.analog.hHasLength_for_Uint32_t.m_length);
 loghandler.LogEntry("");

// loghandler.LogEntry("Node_for_EventRecord* head");
 loghandler.logHandlerStampInteger(("Node_TypedEventRecord_for_AnalogSpec* head = "), (unsigned int)pEventStorage->state.analog.head);
 loghandler.logHandlerStampInteger(("Node_TypedEventRecord_for_AnalogSpec* tail = "), (unsigned int)pEventStorage->state.analog.tail);
 loghandler.logHandlerStampInteger(("Node_TypedEventRecord_for_AnalogSpec* free = "), (unsigned int)pEventStorage->state.analog.free);
 loghandler.LogEntry("");
 loghandler.logHandlerStampInteger(("sizeof Array__for__Node_TypedEventRecord_for_AnalogSpec  underlying = "), sizeof(pEventStorage->state.analog.underlying));
 loghandler.logHandlerStampInteger(("underlying.hHasLength_for_Uint32_t.m_length = "), pEventStorage->state.analog.underlying.hHasLength_for_Uint32_t.m_length);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("List_TypedEventRecord_for_AnalogSpec");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
}