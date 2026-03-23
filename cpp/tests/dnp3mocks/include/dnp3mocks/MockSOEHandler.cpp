#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "MockSOEHandler.h"

//---------------------------------Binary-----------------------------------------------
void Record_for_Binary_in_MockSOEHandler_in_Record_for_Binary_in_MockSOEHandlerOver1(Record_for_Binary_in_MockSOEHandler *pRecord_for_Binary_in_MockSOEHandler)
{
  pRecord_for_Binary_in_MockSOEHandler->sequence = 0;
}
void Record_for_Binary_in_MockSOEHandler_in_Record_for_Binary_in_MockSOEHandlerOver2(Record_for_Binary_in_MockSOEHandler *pRecord_for_Binary_in_MockSOEHandler,
    Binary* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_Binary_in_MockSOEHandler->meas = *meas_;
  pRecord_for_Binary_in_MockSOEHandler->info = *info_;
  pRecord_for_Binary_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_Binary_in_MockSOEHandler>* recordsGlobal_for_Binary_in_MockSOEHandler;
void process_for_Binary_in_MockSOEHandler(Indexed_for_Binary pair);
void process_for_Binary_in_MockSOEHandler(Indexed_for_Binary pair)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
//  increment_stack_info();
//  std::cout<<getString_stack_info();
  std::cout<<"{process_for_Binary_in_MockSOEHandler1"<<'\n';
  std::cout<<"*pair->index= "<<pair.index<<'\n';
#endif
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_Binary_in_MockSOEHandler>* records = recordsGlobal_for_Binary_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_Binary_in_MockSOEHandler record;
  Record_for_Binary_in_MockSOEHandler_in_Record_for_Binary_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
#ifdef  LOG_INFO
  std::cout<<'\n';
//  increment_stack_info();
//  std::cout<<getString_stack_info();
  std::cout<<"}process_for_Binary_in_MockSOEHandler_"<<'\n';
#endif
}
void RecordAny_for_Binary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_Binary* values,
    std::map<uint16_t, Record_for_Binary_in_MockSOEHandler>& records)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
//  increment_stack_info();
//  std::cout<<getString_stack_info();
  std::cout<<"{RecordAny_for_Binary_in_MockSOEHandler1"<<'\n';
#endif
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_Binary_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_Binary(values, process_for_Binary_in_MockSOEHandler);
#ifdef  LOG_INFO
//  increment_stack_info();
//  std::cout<<getString_stack_info();
  std::cout<<"}RecordAny_for_Binary_in_MockSOEHandler_"<<'\n';
#endif
}
//---------------------------------Binary-----------------------------------------------
//---------------------------------DoubleBitBinary-----------------------------------------------

void Record_for_DoubleBitBinary_in_MockSOEHandler_in_Record_for_DoubleBitBinary_in_MockSOEHandlerOver1(Record_for_DoubleBitBinary_in_MockSOEHandler *pRecord_for_DoubleBitBinary_in_MockSOEHandler)
{
  pRecord_for_DoubleBitBinary_in_MockSOEHandler->sequence = 0;
}
void Record_for_DoubleBitBinary_in_MockSOEHandler_in_Record_for_DoubleBitBinary_in_MockSOEHandlerOver2(Record_for_DoubleBitBinary_in_MockSOEHandler *pRecord_for_DoubleBitBinary_in_MockSOEHandler,
    DoubleBitBinary* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_DoubleBitBinary_in_MockSOEHandler->meas = *meas_;
  pRecord_for_DoubleBitBinary_in_MockSOEHandler->info = *info_;
  pRecord_for_DoubleBitBinary_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_DoubleBitBinary_in_MockSOEHandler>* recordsGlobal_for_DoubleBitBinary_in_MockSOEHandler;
void process_for_DoubleBitBinary_in_MockSOEHandler(Indexed_for_DoubleBitBinary pair);
void process_for_DoubleBitBinary_in_MockSOEHandler(Indexed_for_DoubleBitBinary pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_DoubleBitBinary_in_MockSOEHandler>* records = recordsGlobal_for_DoubleBitBinary_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_DoubleBitBinary_in_MockSOEHandler record;
  Record_for_DoubleBitBinary_in_MockSOEHandler_in_Record_for_DoubleBitBinary_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_DoubleBitBinary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_DoubleBitBinary* values,
    std::map<uint16_t, Record_for_DoubleBitBinary_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_DoubleBitBinary_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_DoubleBitBinary(values, process_for_DoubleBitBinary_in_MockSOEHandler);
}
//---------------------------------DoubleBitBinary-----------------------------------------------
//---------------------------------Analog-----------------------------------------------

void Record_for_Analog_in_MockSOEHandler_in_Record_for_Analog_in_MockSOEHandlerOver1(Record_for_Analog_in_MockSOEHandler *pRecord_for_Analog_in_MockSOEHandler)
{
  pRecord_for_Analog_in_MockSOEHandler->sequence = 0;
}
void Record_for_Analog_in_MockSOEHandler_in_Record_for_Analog_in_MockSOEHandlerOver2(Record_for_Analog_in_MockSOEHandler *pRecord_for_Analog_in_MockSOEHandler,
    Analog* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_Analog_in_MockSOEHandler->meas = *meas_;
  pRecord_for_Analog_in_MockSOEHandler->info = *info_;
  pRecord_for_Analog_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_Analog_in_MockSOEHandler>* recordsGlobal_for_Analog_in_MockSOEHandler;
void process_for_Analog_in_MockSOEHandler(Indexed_for_Analog pair);
void process_for_Analog_in_MockSOEHandler(Indexed_for_Analog pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_Analog_in_MockSOEHandler>* records = recordsGlobal_for_Analog_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_Analog_in_MockSOEHandler record;
  Record_for_Analog_in_MockSOEHandler_in_Record_for_Analog_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_Analog_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_Analog* values,
    std::map<uint16_t, Record_for_Analog_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_Analog_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_Analog(values, process_for_Analog_in_MockSOEHandler);
}
//---------------------------------Analog-----------------------------------------------
//---------------------------------Counter-----------------------------------------------

void Record_for_Counter_in_MockSOEHandler_in_Record_for_Counter_in_MockSOEHandlerOver1(Record_for_Counter_in_MockSOEHandler *pRecord_for_Counter_in_MockSOEHandler)
{
  pRecord_for_Counter_in_MockSOEHandler->sequence = 0;
}
void Record_for_Counter_in_MockSOEHandler_in_Record_for_Counter_in_MockSOEHandlerOver2(Record_for_Counter_in_MockSOEHandler *pRecord_for_Counter_in_MockSOEHandler,
    Counter* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_Counter_in_MockSOEHandler->meas = *meas_;
  pRecord_for_Counter_in_MockSOEHandler->info = *info_;
  pRecord_for_Counter_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_Counter_in_MockSOEHandler>* recordsGlobal_for_Counter_in_MockSOEHandler;
void process_for_Counter_in_MockSOEHandler(Indexed_for_Counter pair);
void process_for_Counter_in_MockSOEHandler(Indexed_for_Counter pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_Counter_in_MockSOEHandler>* records = recordsGlobal_for_Counter_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_Counter_in_MockSOEHandler record;
  Record_for_Counter_in_MockSOEHandler_in_Record_for_Counter_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_Counter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_Counter* values,
    std::map<uint16_t, Record_for_Counter_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_Counter_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_Counter(values, process_for_Counter_in_MockSOEHandler);
}
//---------------------------------Counter-----------------------------------------------
//---------------------------------FrozenCounter-----------------------------------------------

void Record_for_FrozenCounter_in_MockSOEHandler_in_Record_for_FrozenCounter_in_MockSOEHandlerOver1(Record_for_FrozenCounter_in_MockSOEHandler *pRecord_for_FrozenCounter_in_MockSOEHandler)
{
  pRecord_for_FrozenCounter_in_MockSOEHandler->sequence = 0;
}
void Record_for_FrozenCounter_in_MockSOEHandler_in_Record_for_FrozenCounter_in_MockSOEHandlerOver2(Record_for_FrozenCounter_in_MockSOEHandler *pRecord_for_FrozenCounter_in_MockSOEHandler,
    FrozenCounter* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_FrozenCounter_in_MockSOEHandler->meas = *meas_;
  pRecord_for_FrozenCounter_in_MockSOEHandler->info = *info_;
  pRecord_for_FrozenCounter_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_FrozenCounter_in_MockSOEHandler>* recordsGlobal_for_FrozenCounter_in_MockSOEHandler;
void process_for_FrozenCounter_in_MockSOEHandler(Indexed_for_FrozenCounter pair);
void process_for_FrozenCounter_in_MockSOEHandler(Indexed_for_FrozenCounter pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_FrozenCounter_in_MockSOEHandler>* records = recordsGlobal_for_FrozenCounter_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_FrozenCounter_in_MockSOEHandler record;
  Record_for_FrozenCounter_in_MockSOEHandler_in_Record_for_FrozenCounter_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_FrozenCounter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_FrozenCounter* values,
    std::map<uint16_t, Record_for_FrozenCounter_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_FrozenCounter_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_FrozenCounter(values, process_for_FrozenCounter_in_MockSOEHandler);
}
//---------------------------------FrozenCounter-----------------------------------------------
//---------------------------------BinaryOutputStatus-----------------------------------------------
void Record_for_BinaryOutputStatus_in_MockSOEHandler_in_Record_for_BinaryOutputStatus_in_MockSOEHandlerOver1(Record_for_BinaryOutputStatus_in_MockSOEHandler *pRecord_for_BinaryOutputStatus_in_MockSOEHandler)
{
  pRecord_for_BinaryOutputStatus_in_MockSOEHandler->sequence = 0;
}
void Record_for_BinaryOutputStatus_in_MockSOEHandler_in_Record_for_BinaryOutputStatus_in_MockSOEHandlerOver2(Record_for_BinaryOutputStatus_in_MockSOEHandler *pRecord_for_BinaryOutputStatus_in_MockSOEHandler,
    BinaryOutputStatus* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_BinaryOutputStatus_in_MockSOEHandler->meas = *meas_;
  pRecord_for_BinaryOutputStatus_in_MockSOEHandler->info = *info_;
  pRecord_for_BinaryOutputStatus_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_BinaryOutputStatus_in_MockSOEHandler>* recordsGlobal_for_BinaryOutputStatus_in_MockSOEHandler;
void process_for_BinaryOutputStatus_in_MockSOEHandler(Indexed_for_BinaryOutputStatus pair);
void process_for_BinaryOutputStatus_in_MockSOEHandler(Indexed_for_BinaryOutputStatus pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_BinaryOutputStatus_in_MockSOEHandler>* records = recordsGlobal_for_BinaryOutputStatus_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_BinaryOutputStatus_in_MockSOEHandler record;
  Record_for_BinaryOutputStatus_in_MockSOEHandler_in_Record_for_BinaryOutputStatus_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_BinaryOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_BinaryOutputStatus* values,
    std::map<uint16_t, Record_for_BinaryOutputStatus_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_BinaryOutputStatus_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_BinaryOutputStatus(values, process_for_BinaryOutputStatus_in_MockSOEHandler);
}
//---------------------------------BinaryOutputStatus-----------------------------------------------
//---------------------------------AnalogOutputStatus-----------------------------------------------
void Record_for_AnalogOutputStatus_in_MockSOEHandler_in_Record_for_AnalogOutputStatus_in_MockSOEHandlerOver1(Record_for_AnalogOutputStatus_in_MockSOEHandler *pRecord_for_AnalogOutputStatus_in_MockSOEHandler)
{
  pRecord_for_AnalogOutputStatus_in_MockSOEHandler->sequence = 0;
}
void Record_for_AnalogOutputStatus_in_MockSOEHandler_in_Record_for_AnalogOutputStatus_in_MockSOEHandlerOver2(Record_for_AnalogOutputStatus_in_MockSOEHandler *pRecord_for_AnalogOutputStatus_in_MockSOEHandler,
    AnalogOutputStatus* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_AnalogOutputStatus_in_MockSOEHandler->meas = *meas_;
  pRecord_for_AnalogOutputStatus_in_MockSOEHandler->info = *info_;
  pRecord_for_AnalogOutputStatus_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_AnalogOutputStatus_in_MockSOEHandler>* recordsGlobal_for_AnalogOutputStatus_in_MockSOEHandler;
void process_for_AnalogOutputStatus_in_MockSOEHandler(Indexed_for_AnalogOutputStatus pair);
void process_for_AnalogOutputStatus_in_MockSOEHandler(Indexed_for_AnalogOutputStatus pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_AnalogOutputStatus_in_MockSOEHandler>* records = recordsGlobal_for_AnalogOutputStatus_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_AnalogOutputStatus_in_MockSOEHandler record;
  Record_for_AnalogOutputStatus_in_MockSOEHandler_in_Record_for_AnalogOutputStatus_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_AnalogOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_AnalogOutputStatus* values,
    std::map<uint16_t, Record_for_AnalogOutputStatus_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_AnalogOutputStatus_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_AnalogOutputStatus(values, process_for_AnalogOutputStatus_in_MockSOEHandler);
}
//---------------------------------AnalogOutputStatus-----------------------------------------------
//---------------------------------OctetString-----------------------------------------------

void Record_for_OctetString_in_MockSOEHandler_in_Record_for_OctetString_in_MockSOEHandlerOver1(Record_for_OctetString_in_MockSOEHandler *pRecord_for_OctetString_in_MockSOEHandler)
{
  pRecord_for_OctetString_in_MockSOEHandler->sequence = 0;
}
void Record_for_OctetString_in_MockSOEHandler_in_Record_for_OctetString_in_MockSOEHandlerOver2(Record_for_OctetString_in_MockSOEHandler *pRecord_for_OctetString_in_MockSOEHandler,
    OctetString* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_OctetString_in_MockSOEHandler->meas = *meas_;
  pRecord_for_OctetString_in_MockSOEHandler->info = *info_;
  pRecord_for_OctetString_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_OctetString_in_MockSOEHandler>* recordsGlobal_for_OctetString_in_MockSOEHandler;
void process_for_OctetString_in_MockSOEHandler(Indexed_for_OctetString pair);
void process_for_OctetString_in_MockSOEHandler(Indexed_for_OctetString pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_OctetString_in_MockSOEHandler>* records = recordsGlobal_for_OctetString_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_OctetString_in_MockSOEHandler record;
  Record_for_OctetString_in_MockSOEHandler_in_Record_for_OctetString_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_OctetString_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_OctetString* values,
    std::map<uint16_t, Record_for_OctetString_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_OctetString_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_OctetString(values, process_for_OctetString_in_MockSOEHandler);
}
//---------------------------------OctetString-----------------------------------------------
//---------------------------------TimeAndInterval-----------------------------------------------

void Record_for_TimeAndInterval_in_MockSOEHandler_in_Record_for_TimeAndInterval_in_MockSOEHandlerOver1(Record_for_TimeAndInterval_in_MockSOEHandler *pRecord_for_TimeAndInterval_in_MockSOEHandler)
{
  pRecord_for_TimeAndInterval_in_MockSOEHandler->sequence = 0;
}
void Record_for_TimeAndInterval_in_MockSOEHandler_in_Record_for_TimeAndInterval_in_MockSOEHandlerOver2(Record_for_TimeAndInterval_in_MockSOEHandler *pRecord_for_TimeAndInterval_in_MockSOEHandler,
    TimeAndInterval* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_TimeAndInterval_in_MockSOEHandler->meas = *meas_;
  pRecord_for_TimeAndInterval_in_MockSOEHandler->info = *info_;
  pRecord_for_TimeAndInterval_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_TimeAndInterval_in_MockSOEHandler>* recordsGlobal_for_TimeAndInterval_in_MockSOEHandler;
void process_for_TimeAndInterval_in_MockSOEHandler(Indexed_for_TimeAndInterval pair);
void process_for_TimeAndInterval_in_MockSOEHandler(Indexed_for_TimeAndInterval pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_TimeAndInterval_in_MockSOEHandler>* records = recordsGlobal_for_TimeAndInterval_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_TimeAndInterval_in_MockSOEHandler record;
  Record_for_TimeAndInterval_in_MockSOEHandler_in_Record_for_TimeAndInterval_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_TimeAndInterval_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_TimeAndInterval* values,
    std::map<uint16_t, Record_for_TimeAndInterval_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_TimeAndInterval_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_TimeAndInterval(values, process_for_TimeAndInterval_in_MockSOEHandler);
}
//---------------------------------TimeAndInterval-----------------------------------------------
//---------------------------------BinaryCommandEvent-----------------------------------------------

void Record_for_BinaryCommandEvent_in_MockSOEHandler_in_Record_for_BinaryCommandEvent_in_MockSOEHandlerOver1(Record_for_BinaryCommandEvent_in_MockSOEHandler *pRecord_for_BinaryCommandEvent_in_MockSOEHandler)
{
  pRecord_for_BinaryCommandEvent_in_MockSOEHandler->sequence = 0;
}
void Record_for_BinaryCommandEvent_in_MockSOEHandler_in_Record_for_BinaryCommandEvent_in_MockSOEHandlerOver2(Record_for_BinaryCommandEvent_in_MockSOEHandler *pRecord_for_BinaryCommandEvent_in_MockSOEHandler,
    BinaryCommandEvent* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_BinaryCommandEvent_in_MockSOEHandler->meas = *meas_;
  pRecord_for_BinaryCommandEvent_in_MockSOEHandler->info = *info_;
  pRecord_for_BinaryCommandEvent_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_BinaryCommandEvent_in_MockSOEHandler>* recordsGlobal_for_BinaryCommandEvent_in_MockSOEHandler;
void process_for_BinaryCommandEvent_in_MockSOEHandler(Indexed_for_BinaryCommandEvent pair);
void process_for_BinaryCommandEvent_in_MockSOEHandler(Indexed_for_BinaryCommandEvent pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_BinaryCommandEvent_in_MockSOEHandler>* records = recordsGlobal_for_BinaryCommandEvent_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_BinaryCommandEvent_in_MockSOEHandler record;
  Record_for_BinaryCommandEvent_in_MockSOEHandler_in_Record_for_BinaryCommandEvent_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_BinaryCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_BinaryCommandEvent* values,
    std::map<uint16_t, Record_for_BinaryCommandEvent_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_BinaryCommandEvent_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_BinaryCommandEvent(values, process_for_BinaryCommandEvent_in_MockSOEHandler);
}
//---------------------------------BinaryCommandEvent-----------------------------------------------
//---------------------------------AnalogCommandEvent-----------------------------------------------
void Record_for_AnalogCommandEvent_in_MockSOEHandler_in_Record_for_AnalogCommandEvent_in_MockSOEHandlerOver1(Record_for_AnalogCommandEvent_in_MockSOEHandler *pRecord_for_AnalogCommandEvent_in_MockSOEHandler)
{
  pRecord_for_AnalogCommandEvent_in_MockSOEHandler->sequence = 0;
}
void Record_for_AnalogCommandEvent_in_MockSOEHandler_in_Record_for_AnalogCommandEvent_in_MockSOEHandlerOver2(Record_for_AnalogCommandEvent_in_MockSOEHandler *pRecord_for_AnalogCommandEvent_in_MockSOEHandler,
    AnalogCommandEvent* meas_, HeaderInfo* info_, uint32_t sequence_)
{
  pRecord_for_AnalogCommandEvent_in_MockSOEHandler->meas = *meas_;
  pRecord_for_AnalogCommandEvent_in_MockSOEHandler->info = *info_;
  pRecord_for_AnalogCommandEvent_in_MockSOEHandler->sequence = sequence_;
}

std::map<uint16_t, Record_for_AnalogCommandEvent_in_MockSOEHandler>* recordsGlobal_for_AnalogCommandEvent_in_MockSOEHandler;
void process_for_AnalogCommandEvent_in_MockSOEHandler(Indexed_for_AnalogCommandEvent pair);
void process_for_AnalogCommandEvent_in_MockSOEHandler(Indexed_for_AnalogCommandEvent pair)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };

  std::map<uint16_t, Record_for_AnalogCommandEvent_in_MockSOEHandler>* records = recordsGlobal_for_AnalogCommandEvent_in_MockSOEHandler;
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  HeaderInfo* info = (HeaderInfo*)pPointerGlobal2;

////            Record<T> record(pair.value, info, soeCount);
  Record_for_AnalogCommandEvent_in_MockSOEHandler record;
  Record_for_AnalogCommandEvent_in_MockSOEHandler_in_Record_for_AnalogCommandEvent_in_MockSOEHandlerOver2(&record, &(pair.value), info, pMockSOEHandler->soeCount);
////            records[pair.index] = record;
  (*records)[pair.index] = record;
////            ++this->soeCount;
  ++pMockSOEHandler->soeCount;
}
void RecordAny_for_AnalogCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info,
    ICollection_Indexed_for_AnalogCommandEvent* values,
    std::map<uint16_t, Record_for_AnalogCommandEvent_in_MockSOEHandler>& records)
{
////        auto process = [this, info, &records](const opendnp3::Indexed<T>& pair) {
////            Record<T> record(pair.value, info, soeCount);
////            records[pair.index] = record;
////            ++this->soeCount;
////        };
  recordsGlobal_for_AnalogCommandEvent_in_MockSOEHandler = &records;
  pPointerGlobal1 = pMockSOEHandler;
  pPointerGlobal2 = info;
  ForeachItem_in_ICollection_Indexed_for_AnalogCommandEvent(values, process_for_AnalogCommandEvent_in_MockSOEHandler);
}
//---------------------------------AnalogCommandEvent-----------------------------------------------

void MockSOEHandler_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler)
{
  pMockSOEHandler->soeCount = 0;

  pMockSOEHandler->iISOEHandler.pBeginFragment_in_ISOEHandler = BeginFragment_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pEndFragment_in_ISOEHandler   = EndFragment_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_Binary_in_ISOEHandler = Process_Indexed_for_Binary_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_DoubleBitBinary_in_ISOEHandler = Process_Indexed_for_DoubleBitBinary_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_Analog_in_ISOEHandler = Process_Indexed_for_Analog_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_Counter_in_ISOEHandler =  Process_Indexed_for_Counter_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_FrozenCounter_in_ISOEHandler = Process_Indexed_for_FrozenCounter_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_BinaryOutputStatus_in_ISOEHandler = Process_Indexed_for_BinaryOutputStatus_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_AnalogOutputStatus_in_ISOEHandler = Process_Indexed_for_AnalogOutputStatus_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_OctetString_in_ISOEHandler = Process_Indexed_for_OctetString_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_TimeAndInterval_in_ISOEHandler = Process_Indexed_for_TimeAndInterval_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_BinaryCommandEvent_in_ISOEHandler = Process_Indexed_for_BinaryCommandEvent_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_Indexed_for_AnalogCommandEvent_in_ISOEHandler = Process_Indexed_for_AnalogCommandEvent_in_MockSOEHandler_override;
  pMockSOEHandler->iISOEHandler.pProcess_for_DNPTime_in_ISOEHandler = Process_for_DNPTime_in_MockSOEHandler_override;

  setParentPointer_in_ISOEHandler(&(pMockSOEHandler->iISOEHandler), pMockSOEHandler);
}

void BeginFragment_in_MockSOEHandler_override(void *pISOEHandler, ResponseInfo* info)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  BeginFragment_in_MockSOEHandler(parent, info);
}
void BeginFragment_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, ResponseInfo* info)
{
  UNUSED(pMockSOEHandler);
  UNUSED(info);
}

void EndFragment_in_MockSOEHandler_override(void *pISOEHandler, ResponseInfo* info)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  EndFragment_in_MockSOEHandler(parent, info);
}

void EndFragment_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, ResponseInfo* info)
{
  UNUSED(pMockSOEHandler);
  UNUSED(info);
}

uint32_t TotalReceived_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler)
{
  return pMockSOEHandler->soeCount;
}

void Process_Indexed_for_Binary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values)
{
////        this->RecordAny(info, values, this->binarySOE);
  RecordAny_for_Binary_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->binarySOE);
}
void Process_Indexed_for_Binary_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_Binary_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_DoubleBitBinary_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values)
{
////        this->RecordAny(info, values, this->doubleBinarySOE);
  RecordAny_for_DoubleBitBinary_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->doubleBinarySOE);
}
void Process_Indexed_for_DoubleBitBinary_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_DoubleBitBinary_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_Analog_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values)
{
////        this->RecordAny(info, values, this->analogSOE);
  RecordAny_for_Analog_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->analogSOE);
}
void Process_Indexed_for_Analog_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_Analog_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_Counter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values)
{
////        this->RecordAny(info, values, this->counterSOE);
  RecordAny_for_Counter_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->counterSOE);
}
void Process_Indexed_for_Counter_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_Counter_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_FrozenCounter_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values)
{
////        this->RecordAny(info, values, this->frozenCounterSOE);
  RecordAny_for_FrozenCounter_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->frozenCounterSOE);
}
void Process_Indexed_for_FrozenCounter_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_FrozenCounter_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_BinaryOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values)
{
////        this->RecordAny(info, values, this->binaryOutputStatusSOE);
  RecordAny_for_BinaryOutputStatus_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->binaryOutputStatusSOE);
}
void Process_Indexed_for_BinaryOutputStatus_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_BinaryOutputStatus_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_AnalogOutputStatus_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values)
{
////        this->RecordAny(info, values, this->analogOutputStatusSOE);
  RecordAny_for_AnalogOutputStatus_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->analogOutputStatusSOE);
}
void Process_Indexed_for_AnalogOutputStatus_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutputStatus* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_AnalogOutputStatus_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_OctetString_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values)
{
////        this->RecordAny(info, values, this->octetStringSOE);
  RecordAny_for_OctetString_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->octetStringSOE);
}
void Process_Indexed_for_OctetString_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_OctetString_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_TimeAndInterval_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values)
{
////        this->RecordAny(info, values, this->timeAndIntervalSOE);
  RecordAny_for_TimeAndInterval_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->timeAndIntervalSOE);
}
void Process_Indexed_for_TimeAndInterval_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_TimeAndInterval_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_BinaryCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values)
{
////        this->RecordAny(info, values, this->binaryCommandEventSOE);
  RecordAny_for_BinaryCommandEvent_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->binaryCommandEventSOE);
}
void Process_Indexed_for_BinaryCommandEvent_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommandEvent* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_BinaryCommandEvent_in_MockSOEHandler(parent, info, values);
}

void Process_Indexed_for_AnalogCommandEvent_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values)
{
////        this->RecordAny(info, values, this->analogCommandEventSOE);
  RecordAny_for_AnalogCommandEvent_in_MockSOEHandler(pMockSOEHandler, info, values, pMockSOEHandler->analogCommandEventSOE);
}
void Process_Indexed_for_AnalogCommandEvent_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommandEvent* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_Indexed_for_AnalogCommandEvent_in_MockSOEHandler(parent, info, values);
}

void fun_for_DNPTime_in_MockSOEHandler(DNPTime value);
void fun_for_DNPTime_in_MockSOEHandler(DNPTime value)
{
    std::cout<<'\n';
    std::cout<<"fun_for_DNPTime_in_MockSOEHandler1"<<'\n';
////        values.ForeachItem([this](const opendnp3::DNPTime& value) {
////            ++this->soeCount;
////            this->timeSOE.push_back(value);
////        });
  MockSOEHandler * pMockSOEHandler = (MockSOEHandler *)pPointerGlobal1;
  ++pMockSOEHandler->soeCount;
  pMockSOEHandler->timeSOE.push_back(value);
}
void Process_for_DNPTime_in_MockSOEHandler(MockSOEHandler *pMockSOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values)
{
    std::cout<<'\n';
    std::cout<<"{Process_for_DNPTime_in_MockSOEHandler1"<<'\n';

  UNUSED(info);
////        values.ForeachItem([this](const opendnp3::DNPTime& value) {
////            ++this->soeCount;
////            this->timeSOE.push_back(value);
////        });
  pPointerGlobal1 = pMockSOEHandler;
  ForeachItem_in_ICollection_for_DNPTime(values, fun_for_DNPTime_in_MockSOEHandler);

    std::cout<<"}Process_for_DNPTime_in_MockSOEHandler_"<<'\n';
}
void Process_for_DNPTime_in_MockSOEHandler_override(void *pISOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values)
{
  MockSOEHandler* parent = (MockSOEHandler*) getParentPointer_in_ISOEHandler((ISOEHandler*)pISOEHandler);
  Process_for_DNPTime_in_MockSOEHandler(parent, info, values);
}
