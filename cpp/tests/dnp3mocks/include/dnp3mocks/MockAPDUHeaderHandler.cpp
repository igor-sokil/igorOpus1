#include <QApplication>
#include <iostream>
#include "header.h"
#include "MockAPDUHeaderHandler.h"

void *pPointerGlobal1_in_MockApduHeaderHandler;

void MockApduHeaderHandler_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler)
{
  IAPDUHandler_in_IAPDUHandler(&(pMockApduHeaderHandler->iIAPDUHandler));

  pMockApduHeaderHandler->iIAPDUHandler.iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_MockApduHeaderHandler_override;

  pMockApduHeaderHandler->iIAPDUHandler.pOnHeaderResult_in_IAPDUHandler                       = OnHeaderResult_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler = ProcessHeader_RangeHeader_Indexed_for_IINValue_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler = ProcessHeader_RangeHeader_Indexed_for_Binary_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler = ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler = ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MockApduHeaderHandler_override;

  setParentPointer_in_IAPDUHandler(&(pMockApduHeaderHandler->iIAPDUHandler), pMockApduHeaderHandler);
  setParentPointer_in_IWhiteList(&(pMockApduHeaderHandler->iIAPDUHandler.iIWhiteList), pMockApduHeaderHandler);
}
//-------------------------------RangeHeader_Indexed_for_Binary-----------------------------------
//  IINField (*pProcessHeader_RangeHeader_for_Binary_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_Binary* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>& values) final
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_Binary* values)
{
//IINField ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_Binary* meas,
//    std::vector<Indexed_for_Binary>* items);
////        return ProcessAny(header, values, staticBinaries);
return ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->staticBinaries));
}
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_Binary* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_RangeHeader_Indexed_for_Binary_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------RangeHeader_Indexed_for_Binary-----------------------------------
//-------------------------------RangeHeader_Indexed_for_IINValue-----------------------------------
//  IINField (*pProcessHeader_RangeHeader_for_IINValue_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_IINValue* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::IINValue>>& values) final
IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_IINValue* values)
{
//IINField ProcessAny_Indexed_for_IINValue_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_IINValue* meas,
//    std::vector<Indexed_for_IINValue>* items);
////        return ProcessAny(header, values, staticBinaries);
return ProcessAny_Indexed_for_IINValue_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->iinBits));
}
IINField ProcessHeader_RangeHeader_Indexed_for_IINValue_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_IINValue* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_RangeHeader_Indexed_for_IINValue_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------RangeHeader_Indexed_for_IINValue-----------------------------------
//-------------------------------RangeHeader_Indexed_for_BinaryOutputStatus-----------------------------------
//  IINField (*pProcessHeader_RangeHeader_for_BinaryOutputStatus_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>& values) final
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_BinaryOutputStatus* values)
{
//IINField ProcessAny_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_BinaryOutputStatus* meas,
//    std::vector<Indexed_for_BinaryOutputStatus>* items);
////        return ProcessAny(header, values, staticBinaries);
return ProcessAny_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->staticControlStatii));
}
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_BinaryOutputStatus* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------RangeHeader_Indexed_for_BinaryOutputStatus-----------------------------------
//-------------------------------RangeHeader_Indexed_for_OctetString-----------------------------------
//  IINField (*pProcessHeader_RangeHeader_for_OctetString_in_IAPDUHandler)(void*, RangeHeader* header, ICollection_Indexed_for_OctetString* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::RangeHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>& values) final
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, RangeHeader* header,
                                          ICollection_Indexed_for_OctetString* values)
{
//IINField ProcessAny_Indexed_for_OctetString_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_OctetString* meas,
//    std::vector<Indexed_for_OctetString>* items);
////        return ProcessAny(header, values, indexPrefixedOctets);
return ProcessAny_Indexed_for_OctetString_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->indexPrefixedOctets));
}
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MockApduHeaderHandler_override(void *pIAPDUHandler, RangeHeader* header,
                                          ICollection_Indexed_for_OctetString* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------RangeHeader_Indexed_for_OctetString-----------------------------------

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
  std::cout<<""<<'\n';
  std::cout<<"OnHeaderResult_in_MockApduHeaderHandler1"<<'\n';
  UNUSED(result);
  pMockApduHeaderHandler->records.push_back(*record);
}

//----------------------------uint16_t--------------------------------------
void add_for_uint16_in_MockApduHeaderHandler(uint16_t* v);
void add_for_uint16_in_MockApduHeaderHandler(uint16_t* v)
{
  std::cout<<""<<'\n';
  std::cout<<"add_for_uint16_in_MockApduHeaderHandler1"<<'\n';
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
//----------------------------Indexed_for_Binary--------------------------------------
void add_Indexed_for_Binary_in_MockApduHeaderHandler(Indexed_for_Binary* v);
void add_Indexed_for_Binary_in_MockApduHeaderHandler(Indexed_for_Binary* v)
{
  std::cout<<""<<'\n';
  std::cout<<"add_Indexed_for_Binary_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_Binary>* items = (std::vector<Indexed_for_Binary>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_Binary* meas,
    std::vector<Indexed_for_Binary>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_Binary(meas, add_Indexed_for_Binary_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_Binary--------------------------------------
//----------------------------Indexed_for_IINValue--------------------------------------
void add_Indexed_for_IINValue_in_MockApduHeaderHandler(Indexed_for_IINValue* v);
void add_Indexed_for_IINValue_in_MockApduHeaderHandler(Indexed_for_IINValue* v)
{
  std::cout<<""<<'\n';
  std::cout<<"add_Indexed_for_IINValue_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_IINValue>* items = (std::vector<Indexed_for_IINValue>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_IINValue_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_IINValue* meas,
    std::vector<Indexed_for_IINValue>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_IINValue(meas, add_Indexed_for_IINValue_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_IINValue--------------------------------------
//----------------------------Indexed_for_BinaryOutputStatus--------------------------------------
void add_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(Indexed_for_BinaryOutputStatus* v);
void add_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(Indexed_for_BinaryOutputStatus* v)
{
  std::cout<<""<<'\n';
  std::cout<<"add_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_BinaryOutputStatus>* items = (std::vector<Indexed_for_BinaryOutputStatus>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_BinaryOutputStatus* meas,
    std::vector<Indexed_for_BinaryOutputStatus>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_BinaryOutputStatus(meas, add_Indexed_for_BinaryOutputStatus_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_BinaryOutputStatus--------------------------------------
//----------------------------Indexed_for_OctetString--------------------------------------
void add_Indexed_for_OctetString_in_MockApduHeaderHandler(Indexed_for_OctetString* v);
void add_Indexed_for_OctetString_in_MockApduHeaderHandler(Indexed_for_OctetString* v)
{
  std::cout<<""<<'\n';
  std::cout<<"add_Indexed_for_OctetString_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_OctetString>* items = (std::vector<Indexed_for_OctetString>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_OctetString_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_OctetString* meas,
    std::vector<Indexed_for_OctetString>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_OctetString(meas, add_Indexed_for_OctetString_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_OctetString--------------------------------------
