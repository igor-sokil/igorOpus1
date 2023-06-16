#include "header.h"
#include "OutstationConfig.h"

 void OutstationConfig_in_OutstationConfig(OutstationConfig *pOutstationConfig)
{
  OutstationParams_in_OutstationParams(&(pOutstationConfig->params));
  EventBufferConfig_in_EventBufferConfigOver1(&(pOutstationConfig->eventBufferConfig));
}
