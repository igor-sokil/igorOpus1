#include "header.h"
#include "OutstationConfig.h"

 void OutstationConfig_in_OutstationConfig(OutstationConfig *pOutstationConfig)
{
  OutstationParams_in_OutstationParams(&(pOutstationConfig->params));
  EventBufferConfig_in_EventBufferConfigOver2(&(pOutstationConfig->eventBufferConfig), 0, 0, 0, 0, 0, 0, 0, 0);
}
