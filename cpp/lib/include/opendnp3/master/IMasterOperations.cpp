#include <QApplication>
#include "header.h"
#include "IMasterOperations.h"

IMasterScan* AddScan_in_IMasterOperations(IMasterOperations* pIMasterOperations, TimeDuration period,
    std::vector<Header>& headers,
    ISOEHandler* soe_handler,
    TaskConfig* config)
{
  return (pIMasterOperations->pAddScan_in_IMasterOperations)(pIMasterOperations, period, headers, soe_handler, config);
}

IMasterScan* AddAllObjectsScan_in_IMasterOperations(IMasterOperations* pIMasterOperations, GroupVariationID gvId,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig* config)
{
  return (pIMasterOperations->pAddAllObjectsScan_in_IMasterOperations)(pIMasterOperations, gvId, period, soe_handler, config);
}

IMasterScan* AddClassScan_in_IMasterOperations(IMasterOperations* pIMasterOperations, ClassField* field,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig* config)
{
  return (pIMasterOperations->pAddClassScan_in_IMasterOperations)(pIMasterOperations, field, period, soe_handler, config);
}

IMasterScan* AddRangeScan_in_IMasterOperations(IMasterOperations* pIMasterOperations, GroupVariationID gvId,
    uint16_t start,
    uint16_t stop,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig* config)
{
  return (pIMasterOperations->pAddRangeScan_in_IMasterOperations)(pIMasterOperations, gvId, start, stop, period, soe_handler, config);
}

void Scan_in_IMasterOperations(IMasterOperations* pIMasterOperations, const std::vector<Header>& headers,
                               ISOEHandler* soe_handler,
                               TaskConfig* config)
{
  (pIMasterOperations->pScan_in_IMasterOperations)(pIMasterOperations, headers, soe_handler, config);
}

void ScanAllObjects_in_IMasterOperations(IMasterOperations* pIMasterOperations, GroupVariationID gvId,
    ISOEHandler* soe_handler,
    TaskConfig* config)
{
  (pIMasterOperations->pScanAllObjects_in_IMasterOperations)(pIMasterOperations, gvId, soe_handler, config);
}

void ScanClasses_in_IMasterOperations(IMasterOperations* pIMasterOperations, ClassField* field,
                                      ISOEHandler* soe_handler,
                                      TaskConfig* config)
{
  (pIMasterOperations->pScanClasses_in_IMasterOperations)(pIMasterOperations, field, soe_handler, config);
}

void ScanRange_in_IMasterOperations(IMasterOperations* pIMasterOperations, GroupVariationID gvId,
                                    uint16_t start,
                                    uint16_t stop,
                                    ISOEHandler* soe_handler,
                                    TaskConfig* config)
{
  (pIMasterOperations->pScanRange_in_IMasterOperations)(pIMasterOperations, gvId, start, stop, soe_handler, config);
}

void Write_in_IMasterOperations(IMasterOperations* pIMasterOperations, TimeAndInterval* value, uint16_t index, TaskConfig* config)
{
  (pIMasterOperations->pWrite_in_IMasterOperations)(pIMasterOperations, value, index, config);
}

void Restart_in_IMasterOperations(IMasterOperations* pIMasterOperations, RestartType_uint8_t op,
                                  RestartOperationCallbackT callback,
                                  TaskConfig* config)
{
  (pIMasterOperations->pRestart_in_IMasterOperations)(pIMasterOperations, op, callback, config);
}

void PerformFunction_in_IMasterOperations(IMasterOperations* pIMasterOperations, std::string& name,
    FunctionCode_uint8_t func,
    std::vector<Header>& headers,
    TaskConfig* config)
{
  (pIMasterOperations->pPerformFunction_in_IMasterOperations)(pIMasterOperations, name, func, headers, config);
}

void* getParentPointer_in_IMasterOperations(IMasterOperations* pIMasterOperations)
{
  return pIMasterOperations->pParentPointer_in_IMasterOperations;
}
void  setParentPointer_in_IMasterOperations(IMasterOperations* pIMasterOperations, void* pParentPointer)
{
  pIMasterOperations->pParentPointer_in_IMasterOperations = pParentPointer;
}
