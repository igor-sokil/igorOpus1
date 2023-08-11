#include <QtWidgets>
#include "header.h"
#include "TimerExe4cpp.h"

   void TimerExe4cpp_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp, ITimer* tim)
{
 pTimerExe4cpp->timerExe4cpp = tim;
}

boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp)
{
qDebug()<<"cancel_in_TimerExe4cpp1";
//  cancel_in_ITimer(pTimerExe4cpp->timerExe4cpp);
qDebug()<<"cancel_in_TimerExe4cpp2";
  return true;
}

uint32_t expires_at_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp)
{
  return expires_at_in_ITimer(pTimerExe4cpp->timerExe4cpp);
}
