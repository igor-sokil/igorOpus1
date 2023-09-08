#include <QApplication>
#include "header.h"
#include "MockAPDUHeaderHandler.h"

void MockApduHeaderHandler_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler)
{
  IAPDUHandler_in_IAPDUHandler(&(pMockApduHeaderHandler->iIAPDUHandler));

  pMockApduHeaderHandler->iIAPDUHandler.iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pOnHeaderResult_in_IAPDUHandler = OnHeaderResult_in_MockApduHeaderHandler_override;

  setParentPointer_in_IAPDUHandler(&(pMockApduHeaderHandler->iIAPDUHandler), pMockApduHeaderHandler);
  setParentPointer_in_IWhiteList(&(pMockApduHeaderHandler->iIAPDUHandler.iIWhiteList), pMockApduHeaderHandler);
}

  boolean IsAllowed_in_MockApduHeaderHandler_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IWhiteList((IWhiteList*)pIWhiteList);
  return IsAllowed_in_MockApduHeaderHandler(parent, headerCount, gv, qc);
}
  boolean IsAllowed_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
    {
UNUSED(pMockApduHeaderHandler);
UNUSED(headerCount);
UNUSED(gv);
UNUSED(qc);
        return true;
    }

  void OnHeaderResult_in_MockApduHeaderHandler_override(void *pIAPDUHandler, HeaderRecord* record, IINField* result)
    {
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
   OnHeaderResult_in_MockApduHeaderHandler(parent, record, result);
}
  void OnHeaderResult_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, HeaderRecord* record, IINField* result)
    {
UNUSED(result);
        pMockApduHeaderHandler->records.push_back(*record);
    }

//----------------------------uint16_t--------------------------------------
void add_for_uint16_in_MockApduHeaderHandler(uint16_t* v);
void add_for_uint16_in_MockApduHeaderHandler(uint16_t* v)
{
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<uint16_t>* items = (std::vector<uint16_t>*)pPointerGlobal1;
  items->push_back(*v);
}

IINField ProcessAny_for_uint16_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_for_uint16* meas,
    std::vector<uint16_t>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1 = items;
  ForeachItem_in_ICollection_for_uint16(meas, add_for_uint16_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------uint16_t--------------------------------------
