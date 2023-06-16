#include "header.h"
#include "LayerInterfaces.h"
#include <string.h>

  void HasLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer)
{
  pHasLowerLayer->pLowerLayer = NULL;
}

    void SetLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer, ILowerLayer* lowerLayer)
    {
////        assert(!pLowerLayer);
        pHasLowerLayer->pLowerLayer = lowerLayer;
    }

   void HasUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer)
{
  pHasUpperLayer->pUpperLayer = NULL;
}

    void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer)
    {
////        assert(!pUpperLayer);
        pHasUpperLayer->pUpperLayer = upperLayer;
    }
