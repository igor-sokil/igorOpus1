#include "header.h"
#include "LinkLayerConfig.h"

void LinkLayerConfig_in_LinkLayerConfig(LinkLayerConfig *pLinkLayerConfig, LinkConfig* config, boolean respondToAnySource)
{
////        : LinkConfig(config), respondToAnySource(respondToAnySource)
  pLinkLayerConfig->lLinkConfig = *config;
  pLinkLayerConfig->respondToAnySource = respondToAnySource;
}
