#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CommandResponseHandler.h"
#include "CommandActionAdapter.h"

#include "Group12.h"
#include "Group41.h"
#include <string.h>

IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogOutputInt16* meas)
{
  UNUSED(record);
//IINField  RespondToHeader_for_AnalogOutputInt16_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//    QualifierCode_uint8_t qualifier,
//    DNP3Serializer_for_AnalogOutputInt16* serializer,
//    ICollection_Indexed_for_AnalogOutputInt16* values)
//DNP3Serializer_for_AnalogOutputInt16  Inst_in_Group12Var1_static(void);
////    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                          Group41Var2::Inst(), meas);
  DNP3Serializer_for_AnalogOutputInt16 tmp = Inst_in_Group41Var2_static();
  return  RespondToHeader_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(pCommandResponseHandler,
          QualifierCode_UINT8_CNT_UINT8_INDEX, &tmp, meas);
}

IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogOutputInt16* meas)
{
  UNUSED(record);
// IINField  RespondToHeader_for_AnalogOutputInt16_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                                      QualifierCode_uint8_t qualifier,
//                                                     DNP3Serializer_for_AnalogOutputInt16* serializer,
//                                                     ICollection_Indexed_for_AnalogOutputInt16* values
//                                                      );
//DNP3Serializer_for_AnalogOutputInt16  Inst_in_Group12Var1_static(void);
////    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                           Group41Var2::Inst(), meas);
  DNP3Serializer_for_AnalogOutputInt16 temp = Inst_in_Group41Var2_static();
  return  RespondToHeader_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(pCommandResponseHandler,
          QualifierCode_UINT16_CNT_UINT16_INDEX, &temp, meas);
}

////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
IINField ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler1"<<'\n';
#endif
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
  if (GetQualifierCode_in_HeaderRecord(record) == QualifierCode_UINT8_CNT_UINT8_INDEX)
  {
//    IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                            HeaderRecord* record,
//                                        ICollection_Indexed_for_AnalogOutputInt16* meas);
////        return ProcessIndexPrefixOneByte(record, meas);
    IINField tmp = ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(pCommandResponseHandler,
           record, meas);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
////        return ProcessIndexPrefixTwoByte(record, meas);
    IINField tmp = ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(pCommandResponseHandler,
           record, meas);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return tmp;
  }
}

IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandResponseHandler_override(void *pIAPDUHandler,
    PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt16* meas)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandResponseHandler_override1"<<'\n';
#endif

  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    template<class T> IINField ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas);
//     IINField ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                       HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas);
////    return this->ProcessAny(header, meas);
  IINField tmp = ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

//-------------------------------------------------UInt16-------------------------------------------------------
IINField  RespondToHeader_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values)
{
  if (pCommandResponseHandler->pWriter)
  {
//  PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt16* serializer);
////        auto iter = pWriter->IterateOverCountWithPrefix<IndexType, Target>(qualifier, serializer);
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 iter = IterateOverCountWithPrefix_for_UInt16_AnalogOutputInt16_in_HeaderWriter(
          pCommandResponseHandler->pWriter,
          qualifier, serializer);
//IINField RespondToHeaderWithIterator_for_AnalogOutputInt16_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                         QualifierCode_uint8_t qualifier,
//                                         DNP3Serializer_for_AnalogOutputInt16* serializer,
//                                         ICollection_Indexed_for_AnalogOutputInt16* values,
//                                         PrefixedWriteIterator_for_UInt16_AnalogOutputInt16* pIterator
//                                        );
////        return this->RespondToHeaderWithIterator<Target, IndexType>(qualifier, serializer, values, &iter);
    IINField tmp = RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(pCommandResponseHandler,
           qualifier, serializer, values, &iter);
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(&iter);
    return tmp;
  }
  else
  {
////        return this->RespondToHeaderWithIterator<Target, IndexType>(qualifier, serializer, values);

    return RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(pCommandResponseHandler,
           qualifier, serializer, values, NULL);
  }
}

void process_for_UInt16_AnalogOutputInt16_in_CommandResponseHandler(Indexed_for_AnalogOutputInt16* pair);
void process_for_UInt16_AnalogOutputInt16_in_CommandResponseHandler(Indexed_for_AnalogOutputInt16* pair)
{
  CommandResponseHandler* pCommandResponseHandler = (CommandResponseHandler*)pPointerGlobal1;//CommandResponseHandler*
  PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 * pIterator =
    (PrefixedWriteIterator_for_UInt16_AnalogOutputInt16*)pPointerGlobal2;//PrefixedWriteIterator_for_UInt16_AnalogOutputInt16*
  IINField* ret = (IINField*) pPointerGlobal3;//IINField*

////        Target response(pair.value);
  AnalogOutputInt16 response;
  response = pair->value;

// CommandStatus_uint8_t ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                               AnalogOutputInt16* command, uint16_t index)
//    CommandStatus_uint8_t status;
////        response.status = this->ProcessCommand(pair.value, pair.index);
  response.aAnalogOutput_for_Int16.status = ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler(pCommandResponseHandler,
                    &(pair->value), pair->index);


  switch (response.aAnalogOutput_for_Int16.status)
  {
  case (CommandStatus_SUCCESS):
    ++(pCommandResponseHandler->numSuccess);
    break;
  case (CommandStatus_NOT_SUPPORTED):
//    void SetBit_in_IINField(IINField *, IINBit_uint8_t bit);
////            ret.SetBit(IINBit::PARAM_ERROR);
    SetBit_in_IINField(ret, IINBit_PARAM_ERROR);
    break;
  default:
    break;
  }

  if (pIterator)
  {
//    boolean Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(PrefixedWriteIterator_for_UInt16_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt16_AnalogOutputInt16,
//                                                                  AnalogOutputInt16* value, uint16_t index);
////            pIterator->Write(response, static_cast<typename IndexType::type_t>(pair.index));
    Write_in_PrefixedWriteIterator_for_UInt16_AnalogOutputInt16(pIterator,
        &response, pair->index);
  }
}

IINField RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values,
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16* pIterator)
{
  UNUSED(qualifier);
  UNUSED(serializer);
  UNUSED(values);

  IINField ret;
  IINField_in_IINFieldOver1(&ret);

  pPointerGlobal1 = pCommandResponseHandler;//CommandResponseHandler*
  pPointerGlobal2 = pIterator;//PrefixedWriteIterator_for_UInt16_AnalogOutputInt16*
  pPointerGlobal3 = &ret;//IINField*

////
////    auto process = [this, pIterator, &ret](const Indexed<Target>& pair) {
////        Target response(pair.value);
////        response.status = this->ProcessCommand(pair.value, pair.index);
////
////        switch (response.status)
////        {
////        case (CommandStatus::SUCCESS):
////            ++this->numSuccess;
////            break;
////        case (CommandStatus::NOT_SUPPORTED):
////            ret.SetBit(IINBit::PARAM_ERROR);
////            break;
////        default:
////            break;
////        }
////
////        if (pIterator)
////        {
////            pIterator->Write(response, static_cast<typename IndexType::type_t>(pair.index));
////        }
////    };
////
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(
//      ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
//        void (*fun)(Indexed_for_AnalogOutputInt16* item));

////    values.ForeachItem(process);
  ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(values,
      process_for_UInt16_AnalogOutputInt16_in_CommandResponseHandler);

  return ret;
}
//-------------------------------------------------UInt16-------------------------------------------------------
//-------------------------------------------------UInt8-------------------------------------------------------
IINField  RespondToHeader_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RespondToHeader_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler1"<<'\n';
#endif

  if (pCommandResponseHandler->pWriter)
  {
//  PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, DNP3Serializer_for_AnalogOutputInt16* serializer);
////        auto iter = pWriter->IterateOverCountWithPrefix<IndexType, Target>(qualifier, serializer);
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 iter = IterateOverCountWithPrefix_for_UInt8_AnalogOutputInt16_in_HeaderWriter(
          pCommandResponseHandler->pWriter,
          qualifier, serializer);
//IINField RespondToHeaderWithIterator_for_AnalogOutputInt16_uint8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                         QualifierCode_uint8_t qualifier,
//                                         DNP3Serializer_for_AnalogOutputInt16* serializer,
//                                         ICollection_Indexed_for_AnalogOutputInt16* values,
//                                         PrefixedWriteIterator_for_UInt8_AnalogOutputInt16* pIterator
//                                        );
////        return this->RespondToHeaderWithIterator<Target, IndexType>(qualifier, serializer, values, &iter);
    IINField tmp = RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(pCommandResponseHandler,
           qualifier, serializer, values, &iter);
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16_destr_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(&iter);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
////        return this->RespondToHeaderWithIterator<Target, IndexType>(qualifier, serializer, values);

    IINField tmp = RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(pCommandResponseHandler,
           qualifier, serializer, values, NULL);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return tmp;
  }
}

void process_for_UInt8_AnalogOutputInt16_in_CommandResponseHandler(Indexed_for_AnalogOutputInt16* pair);
void process_for_UInt8_AnalogOutputInt16_in_CommandResponseHandler(Indexed_for_AnalogOutputInt16* pair)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"process_for_UInt8_AnalogOutputInt16_in_CommandResponseHandler1"<<'\n';
#endif

  CommandResponseHandler* pCommandResponseHandler = (CommandResponseHandler*)pPointerGlobal1;//CommandResponseHandler*
  PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 * pIterator =
    (PrefixedWriteIterator_for_UInt8_AnalogOutputInt16*)pPointerGlobal2;
  IINField* ret = (IINField*) pPointerGlobal3;//IINField*

////        Target response(pair.value);
  AnalogOutputInt16 response;
  response = pair->value;

// CommandStatus_uint8_t ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                               AnalogOutputInt16* command, uint16_t index)
//    CommandStatus_uint8_t status;
////        response.status = this->ProcessCommand(pair.value, pair.index);
  response.aAnalogOutput_for_Int16.status = ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler(pCommandResponseHandler,
                    &(pair->value), pair->index);

#ifdef  LOG_INFO
//  response.status = CommandStatus_NOT_SUPPORTED;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*response.status ="<<(uint16_t)response.aAnalogOutput_for_Int16.status<<'\n';
#endif

  switch (response.aAnalogOutput_for_Int16.status)
  {
  case (CommandStatus_SUCCESS):
    ++(pCommandResponseHandler->numSuccess);
    break;
  case (CommandStatus_NOT_SUPPORTED):
//    void SetBit_in_IINField(IINField *, IINBit_uint8_t bit);
////            ret.SetBit(IINBit::PARAM_ERROR);
    SetBit_in_IINField(ret, IINBit_PARAM_ERROR);
    break;
  default:
    break;
  }

  if (pIterator)
  {
//    boolean Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(PrefixedWriteIterator_for_UInt8_AnalogOutputInt16 *pPrefixedWriteIterator_for_UInt8_AnalogOutputInt16,
//                                                                  AnalogOutputInt16* value, uint16_t index);
////            pIterator->Write(response, static_cast<typename IndexType::type_t>(pair.index));
    Write_in_PrefixedWriteIterator_for_UInt8_AnalogOutputInt16(pIterator,
        &response, pair->index);
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

IINField RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values,
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16* pIterator)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler1"<<'\n';
#endif

  UNUSED(qualifier);
  UNUSED(serializer);
//  UNUSED(values);

  IINField ret;
  IINField_in_IINFieldOver1(&ret);

  pPointerGlobal1 = pCommandResponseHandler;//CommandResponseHandler*
  pPointerGlobal2 = pIterator;
  pPointerGlobal3 = &ret;//IINField*

////
////    auto process = [this, pIterator, &ret](const Indexed<Target>& pair) {
////        Target response(pair.value);
////        response.status = this->ProcessCommand(pair.value, pair.index);
////
////        switch (response.status)
////        {
////        case (CommandStatus::SUCCESS):
////            ++this->numSuccess;
////            break;
////        case (CommandStatus::NOT_SUPPORTED):
////            ret.SetBit(IINBit::PARAM_ERROR);
////            break;
////        default:
////            break;
////        }
////
////        if (pIterator)
////        {
////            pIterator->Write(response, static_cast<typename IndexType::type_t>(pair.index));
////        }
////    };
////
//void ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(
//      ICollection_Indexed_for_AnalogOutputInt16 *pICollection_Indexed_for_AnalogOutputInt16,
//        void (*fun)(Indexed_for_AnalogOutputInt16* item));

////    values.ForeachItem(process);
  ForeachItem_in_ICollection_Indexed_for_AnalogOutputInt16(values,
      process_for_UInt8_AnalogOutputInt16_in_CommandResponseHandler);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return ret;
}
//-------------------------------------------------UInt8-------------------------------------------------------
