#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QFile>
#include <QTextStream>

class LogHandler
{
 public:
   LogHandler();
   void LogEntry(const char* message);
   void LogEntry(QString message);
   void LogEntry(QString &message);
   void LogEntryShort(const char* message);
   void LogEntryShort(QString message);
   void LogEntryShort(QString &message);
   void clearFileLog();
   void logHandlerStampArray(const char * title, unsigned int *data, int size);
   void logHandlerStampInteger(const char * title, int data);
   QString appendTimeStamp(QString str_response);

 private:

    QFile file;
    QTextStream outLog;

};//

extern LogHandler loghandler;//логирование

#endif
