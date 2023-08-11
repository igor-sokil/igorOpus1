#include "header.h"
#include "LinkConfig.h"

void  LinkConfig_in_LinkConfig(LinkConfig *pLinkConfig, boolean isMaster)
{
  pLinkConfig->IsMaster = isMaster;
  pLinkConfig->LocalAddr = isMaster ? 1 : 1024;
  pLinkConfig->RemoteAddr = isMaster ? 1024 : 1;
//   TimeDuration Seconds_in_TimeDuration_static(int64_t seconds);
  pLinkConfig->Timeout = Seconds_in_TimeDuration_static(1);//(TimeDuration::Seconds(1)),
//   TimeDuration Minutes_in_TimeDuration_static(int64_t seconds);
  pLinkConfig->KeepAliveTimeout = Minutes_in_TimeDuration_static(1);//(TimeDuration::Minutes(1))
}
