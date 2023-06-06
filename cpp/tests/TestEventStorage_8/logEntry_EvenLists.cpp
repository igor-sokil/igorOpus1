#include "loghandler.h"

#include "header.h"
#include "EventStorage.h"

void loghandler_EvenLists();
 extern EventStorage storage;

void loghandler_EvenLists()
{
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
 loghandler.logHandlerStampInteger(("uint32_t selected = "), storage.state.counters.selected);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("EventClassCounters counters");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");

 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount total");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.logHandlerStampInteger(("uint32_t num_class_1 = "), storage.state.counters.total.num_class_1);
 loghandler.logHandlerStampInteger(("uint32_t num_class_2 = "), storage.state.counters.total.num_class_2);
 loghandler.logHandlerStampInteger(("uint32_t num_class_3 = "), storage.state.counters.total.num_class_3);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount total");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");

 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount written");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
 loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("")));
 loghandler.logHandlerStampInteger(("uint32_t num_class_1 = "), storage.state.counters.written.num_class_1);
 loghandler.logHandlerStampInteger(("uint32_t num_class_2 = "), storage.state.counters.written.num_class_2);
 loghandler.logHandlerStampInteger(("uint32_t num_class_3 = "), storage.state.counters.written.num_class_3);
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntryShort("ClazzCount written");
 loghandler.LogEntryShort("===========================");
 loghandler.LogEntry("");
}

