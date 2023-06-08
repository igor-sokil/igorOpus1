
#include <QtWidgets>
#include "loghandler.h"

LogHandler::LogHandler()
{
  file.setFileName("log.txt");
  file.open(QIODevice::WriteOnly|QIODevice::Text);
  outLog.setDevice(&file);
}//

void LogHandler::LogEntry(const char * message)
{
  outLog<<QString::fromLocal8Bit(message)<<endl;
}//LogEntry(char *message)

void LogHandler::LogEntryShort(const char * message)
{
  outLog<<QString::fromLocal8Bit(message);//<<endl;
}//LogEntry(char *message)

void LogHandler::LogEntryShort(QString  message)
{
  LogEntryShort(message.toLocal8Bit().data());//логирование
}//LogEntry(char *message)

void LogHandler::LogEntry(QString  message)
{
  LogEntry(message.toLocal8Bit().data());//логирование
}//LogEntry(char *message)

void LogHandler::clearFileLog()
{
  file.close();
  file.setFileName("log.txt");
  file.open(QIODevice::WriteOnly|QIODevice::Text);
}//LogEntry(char *message)
