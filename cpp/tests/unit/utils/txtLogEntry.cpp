#include <iostream>
#include <string>
#include "log_info.h"
#include "loghandler.h"

#include "header.h"

void inspect_LogEntry(std::string &message);
void inspect_LogEntry(std::string &message)
{
  loghandler.LogEntry("");
  loghandler.LogEntry(loghandler.appendTimeStamp(QString::fromLocal8Bit("====== ")));
  loghandler.LogEntry(QString::fromLocal8Bit(message.c_str()));
  loghandler.LogEntry("");
}

