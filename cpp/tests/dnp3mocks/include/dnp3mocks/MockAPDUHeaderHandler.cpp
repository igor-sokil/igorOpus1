#include <QApplication>
#include "log_info.h"
//#ifndef  LOG_INFO_INC
#include <iostream>
//#endif
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

  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler = ProcessHeader_PrefixHeader_for_uint16_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler_override;
  pMockApduHeaderHandler->iIAPDUHandler.pProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler = ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler_override;

  setParentPointer_in_IAPDUHandler(&(pMockApduHeaderHandler->iIAPDUHandler), pMockApduHeaderHandler);
  setParentPointer_in_IWhiteList(&(pMockApduHeaderHandler->iIAPDUHandler.iIWhiteList), pMockApduHeaderHandler);
}
//-------------------------------PrefixHeader_for_uint16-----------------------------------
//  IINField (*pProcessHeader_PrefixHeader_for_uint16_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_for_uint16* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>& values) final
IINField ProcessHeader_PrefixHeader_for_uint16_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, PrefixHeader* header,
                                          ICollection_for_uint16* values)
{
   std::cout<<'\n';
   std::cout<<"ProcessHeader_PrefixHeader_for_uint16_in_MockApduHeaderHandler1"<<'\n';
//IINField ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_Binary* meas,
//    std::vector<Indexed_for_Binary>* items);
////        return ProcessAny(header, values, indices);
return ProcessAny_for_uint16_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->indices));
}
IINField ProcessHeader_PrefixHeader_for_uint16_in_MockApduHeaderHandler_override(void *pIAPDUHandler, PrefixHeader* header,
                                          ICollection_for_uint16* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_PrefixHeader_for_uint16_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------PrefixHeader_for_uint16-----------------------------------
//-------------------------------PrefixHeader_Indexed_for_Binary-----------------------------------
//  IINField (*pProcessHeader_PrefixHeader_for_Binary_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_Binary* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>& values) final
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_Binary* values)
{
//IINField ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_Binary* meas,
//    std::vector<Indexed_for_Binary>* items);
////        return ProcessAny(header, values, eventBinaries);
return ProcessAny_Indexed_for_Binary_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->eventBinaries));
}
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MockApduHeaderHandler_override(void *pIAPDUHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_Binary* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------PrefixHeader_Indexed_for_Binary-----------------------------------
//-------------------------------PrefixHeader_Indexed_for_AnalogCommandEvent-----------------------------------
//  IINField (*pProcessHeader_PrefixHeader_for_AnalogCommandEvent_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>& values) final
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_AnalogCommandEvent* values)
{
//IINField ProcessAny_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_AnalogCommandEvent* meas,
//    std::vector<Indexed_for_AnalogCommandEvent>* items);
////        return ProcessAny(header, values, analogCommandEvents);
return ProcessAny_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->analogCommandEvents));
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler_override(void *pIAPDUHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_AnalogCommandEvent* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------PrefixHeader_Indexed_for_AnalogCommandEvent-----------------------------------
//-------------------------------PrefixHeader_Indexed_for_BinaryCommandEvent-----------------------------------
//  IINField (*pProcessHeader_PrefixHeader_for_BinaryCommandEvent_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>& values) final
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_BinaryCommandEvent* values)
{
//IINField ProcessAny_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_BinaryCommandEvent* meas,
//    std::vector<Indexed_for_BinaryCommandEvent>* items);
////        return ProcessAny(header, values, binaryCommandEvents);
return ProcessAny_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord),
    values,
    &(pMockApduHeaderHandler->binaryCommandEvents));
}
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler_override(void *pIAPDUHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_BinaryCommandEvent* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------PrefixHeader_Indexed_for_BinaryCommandEvent-----------------------------------
//-------------------------------PrefixHeader_Indexed_for_DoubleBitBinary-----------------------------------
//  IINField (*pProcessHeader_PrefixHeader_for_DoubleBitBinary_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>& values) final
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_DoubleBitBinary* values)
{
//IINField ProcessAny_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_DoubleBitBinary* meas,
//    std::vector<Indexed_for_DoubleBitBinary>* items);
////        return ProcessAny(header, values, eventDoubleBinaries);
return ProcessAny_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord), values, &(pMockApduHeaderHandler->eventDoubleBinaries));
}
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler_override(void *pIAPDUHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_DoubleBitBinary* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------PrefixHeader_Indexed_for_DoubleBitBinary-----------------------------------
//-------------------------------PrefixHeader_Indexed_for_ControlRelayOutputBlock-----------------------------------
//  IINField (*pProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler)(void*, PrefixHeader* header, ICollection_Indexed_for_ControlRelayOutputBlock* values);
////    opendnp3::IINField ProcessHeader(const opendnp3::PrefixHeader& header,
////                                     const opendnp3::ICollection<opendnp3::Indexed<opendnp3::ControlRelayOutputBlock>>& values) final
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
//IINField ProcessAny_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
//    HeaderRecord* record,
//    ICollection_Indexed_for_ControlRelayOutputBlock* meas,
//    std::vector<Indexed_for_ControlRelayOutputBlock>* items);
////        return ProcessAny(header, values, crobRequests);
return ProcessAny_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(pMockApduHeaderHandler,
    &(header->hHeaderRecord), values, &(pMockApduHeaderHandler->crobRequests));
}
IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler_override(void *pIAPDUHandler, PrefixHeader* header,
                                          ICollection_Indexed_for_ControlRelayOutputBlock* values)
{
  MockApduHeaderHandler* parent = (MockApduHeaderHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
 return ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(parent, header, values);
}
//-------------------------------PrefixHeader_Indexed_for_ControlRelayOutputBlock-----------------------------------

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
    &(header->hHeaderRecord), values, &(pMockApduHeaderHandler->staticBinaries));
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
    &(header->hHeaderRecord), values, &(pMockApduHeaderHandler->iinBits));
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
    &(header->hHeaderRecord), values, &(pMockApduHeaderHandler->staticControlStatii));
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
    &(header->hHeaderRecord), values, &(pMockApduHeaderHandler->indexPrefixedOctets));
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
    std::cout<<'\n';
    std::cout<<"OnHeaderResult_in_MockApduHeaderHandler1"<<'\n';
  UNUSED(result);
  pMockApduHeaderHandler->records.push_back(*record);
}

//----------------------------uint16_t--------------------------------------
void add_for_uint16_in_MockApduHeaderHandler(uint16_t* v);
void add_for_uint16_in_MockApduHeaderHandler(uint16_t* v)
{
    std::cout<<'\n';
    std::cout<<"add_for_uint16_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<uint16_t>* items = (std::vector<uint16_t>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_for_uint16_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_for_uint16* meas,
    std::vector<uint16_t>* items)
{
  std::cout<<'\n';
  std::cout<<"ProcessAny_for_uint16_in_MockApduHeaderHandler1"<<'\n';

  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
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
    std::cout<<'\n';
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
//----------------------------Indexed_for_AnalogCommandEvent--------------------------------------
void add_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(Indexed_for_AnalogCommandEvent* v);
void add_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(Indexed_for_AnalogCommandEvent* v)
{
    std::cout<<'\n';
    std::cout<<"add_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_AnalogCommandEvent>* items = (std::vector<Indexed_for_AnalogCommandEvent>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogCommandEvent* meas,
    std::vector<Indexed_for_AnalogCommandEvent>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(meas, add_Indexed_for_AnalogCommandEvent_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_AnalogCommandEvent--------------------------------------
//----------------------------Indexed_for_BinaryCommandEvent--------------------------------------
void add_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(Indexed_for_BinaryCommandEvent* v);
void add_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(Indexed_for_BinaryCommandEvent* v)
{
    std::cout<<""<<'\n';
    std::cout<<"add_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_BinaryCommandEvent>* items = (std::vector<Indexed_for_BinaryCommandEvent>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_BinaryCommandEvent* meas,
    std::vector<Indexed_for_BinaryCommandEvent>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_BinaryCommandEvent(meas, add_Indexed_for_BinaryCommandEvent_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_BinaryCommandEvent--------------------------------------
//----------------------------Indexed_for_DoubleBitBinary--------------------------------------
void add_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(Indexed_for_DoubleBitBinary* v);
void add_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(Indexed_for_DoubleBitBinary* v)
{
    std::cout<<'\n';
    std::cout<<"add_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_DoubleBitBinary>* items = (std::vector<Indexed_for_DoubleBitBinary>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_DoubleBitBinary* meas,
    std::vector<Indexed_for_DoubleBitBinary>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(meas, add_Indexed_for_DoubleBitBinary_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_DoubleBitBinary--------------------------------------
//----------------------------Indexed_for_IINValue--------------------------------------
void add_Indexed_for_IINValue_in_MockApduHeaderHandler(Indexed_for_IINValue* v);
void add_Indexed_for_IINValue_in_MockApduHeaderHandler(Indexed_for_IINValue* v)
{
    std::cout<<'\n';
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
    std::cout<<'\n';
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
    std::cout<<'\n';
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
//----------------------------Indexed_for_ControlRelayOutputBlock--------------------------------------
void add_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(Indexed_for_ControlRelayOutputBlock* v);
void add_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(Indexed_for_ControlRelayOutputBlock* v)
{
    std::cout<<'\n';
    std::cout<<"add_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler1"<<'\n';
////        auto add = [&items](const T& v) { items.push_back(v); };
  std::vector<Indexed_for_ControlRelayOutputBlock>* items = (std::vector<Indexed_for_ControlRelayOutputBlock>*)pPointerGlobal1_in_MockApduHeaderHandler;
  items->push_back(*v);
}

IINField ProcessAny_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler(MockApduHeaderHandler *pMockApduHeaderHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_ControlRelayOutputBlock* meas,
    std::vector<Indexed_for_ControlRelayOutputBlock>* items)
{
  UNUSED(pMockApduHeaderHandler);
  UNUSED(record);
////        auto add = [&items](const T& v) { items.push_back(v); };
//void ForeachItem_in_ICollection_for_uint16(ICollection_for_uint16 *pICollection_for_uint16, void (*fun)(uint16_t* item));
////        meas.ForeachItem(add);
  pPointerGlobal1_in_MockApduHeaderHandler = items;
  ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(meas, add_Indexed_for_ControlRelayOutputBlock_in_MockApduHeaderHandler);//void (*fun)(uint16_t* item));
//IINField Empty_in_IINField_static(void);
////        return opendnp3::IINField::Empty();
  return Empty_in_IINField_static();
}
//----------------------------Indexed_for_ControlRelayOutputBlock--------------------------------------
