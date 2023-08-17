
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

QString LogHandler::appendTimeStamp(QString str_response)
{
  QTime currentTime = QTime::currentTime();
  str_response.append((QString("0%1:").arg(QString::number(currentTime.hour(),   10))).right(3));
  str_response.append((QString("0%1:").arg(QString::number(currentTime.minute(), 10))).right(3));
  str_response.append((QString("0%1.").arg(QString::number(currentTime.second(), 10))).right(3));
  str_response.append((QString("000%1").arg(QString::number(currentTime.msec(), 10))).right(3));
  return str_response;
}

void LogHandler::logHandlerStampInteger(const char * title, int data)
{
  LogEntryShort(QString::fromLocal8Bit(title));
  QString str_response = "";//"====";
  QString insertStr = ((QString("000%1").arg(QString::number(data, 10))).right(4));
  str_response.append(insertStr);
  LogEntry(QString(str_response.toUpper()));
//  LogEntry("");
}//logHandlerStampInteger(const char * title, int data)

void LogHandler::logHandlerStampArray(const char * title, unsigned int *data, int rang_count)
{
  LogEntry(appendTimeStamp(QString::fromLocal8Bit(title)));
  LogEntryShort("====");
  for(int i=0; i<rang_count; i++)
  {
     QString insertStr = ((QString("000%1").arg(QString::number(data[i], 16))).right(4));
     loghandler.LogEntryShort(QString(insertStr.toUpper()));
     loghandler.LogEntryShort(" ");
  }//for
  LogEntry("");
  LogEntry("");
}//logHandlerStampArray(const char * title, unsigned int *data, int rang_count)
