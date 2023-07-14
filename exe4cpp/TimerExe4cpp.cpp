#include "header.h"
#include "TimerExe4cpp.h"

boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp)
{
  pTimerExe4cpp->timerExe4cpp = 0;
  return true;
}

uint32_t expires_at_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp)
{
  return pTimerExe4cpp->timerExe4cpp;
}
