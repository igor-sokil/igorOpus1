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
   void logHandlerStampCharArray(unsigned char *data, int rang_count);
   void logHandlerStampShortArray(unsigned short *data, int rang_count);
   void logHandlerStampInt32Array(unsigned int *data, int rang_count);
   void logHandlerStampInteger(const char * title, int data);
   void logHandlerStampInteger32(const char * title, int data);
   void logHandlerStampIntegerHex(const char * title, int data);
   void logHandlerStampInteger32Hex(const char * title, int data);
   QString appendTimeStamp(QString str_response);

 private:

    QFile file;
    QTextStream outLog;

};//

extern LogHandler loghandler;//логирование

#endif
