#include "header.h"
#include "IMasterScan.h"

void Demand_in_IMasterScan(IMasterScan* pIMasterScan)
{
  (pIMasterScan->pDemand_in_IMasterScan)(pIMasterScan);
}

void* getParentPointer_in_IMasterScan(IMasterScan* pIMasterScan)
{
  return pIMasterScan->pParentPointer_in_IMasterScan;
}
void  setParentPointer_in_IMasterScan(IMasterScan* pIMasterScan, void* pParentPointer)
{
  pIMasterScan->pParentPointer_in_IMasterScan = pParentPointer;
}
