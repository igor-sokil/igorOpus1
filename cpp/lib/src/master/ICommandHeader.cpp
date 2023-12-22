#include "header.h"
#include "ICommandHeader.h"

boolean Write_in_ICommandHeader(ICommandHeader *pICommandHeader, HeaderWriter* pHeaderWriter, IndexQualifierMode_uint8_t mode)
{
  return (pICommandHeader->pWrite_in_ICommandHeader)(pICommandHeader, pHeaderWriter, mode);
}

boolean AreAllSelected_in_ICommandHeader(ICommandHeader *pICommandHeader)
{
  return (pICommandHeader->pAreAllSelected_in_ICommandHeader)(pICommandHeader);
}

void ApplySelectResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands)
{
  (pICommandHeader->pApplySelectResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader)(pICommandHeader, code, commands);
}
void ApplySelectResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands)
{
  (pICommandHeader->pApplySelectResponse_Indexed_for_AnalogOutputInt16_in_ICommandHeader)(pICommandHeader, code, commands);
}

void ApplySelectResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands)
{
  (pICommandHeader->pApplySelectResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader)(pICommandHeader, code, commands);
}
void ApplySelectResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands)
{
  (pICommandHeader->pApplySelectResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader)(pICommandHeader, code, commands);
}

void ApplyOperateResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_ControlRelayOutputBlock* commands)
{
  (pICommandHeader->pApplyOperateResponse_Indexed_for_ControlRelayOutputBlock_in_ICommandHeader)(pICommandHeader, code, commands);
}
void ApplyOperateResponse_Indexed_for_for_AnalogOutputInt16_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt16* commands)
{
  (pICommandHeader->pApplyOperateResponse_Indexed_for_for_AnalogOutputInt16_in_ICommandHeader)(pICommandHeader, code, commands);
}
void ApplyOperateResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputInt32* commands)
{
  (pICommandHeader->pApplyOperateResponse_Indexed_for_AnalogOutputInt32_in_ICommandHeader)(pICommandHeader, code, commands);
}
void ApplyOperateResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader(ICommandHeader *pICommandHeader, QualifierCode_uint8_t code, ICollection_Indexed_for_AnalogOutputFloat32* commands)
{
  (pICommandHeader->pApplyOperateResponse_Indexed_for_AnalogOutputFloat32_in_ICommandHeader)(pICommandHeader, code, commands);
}

void* getParentPointer_in_ICommandHeader(ICommandHeader* pICommandHeader)
{
  return pICommandHeader->pParentPointer_in_ICommandHeader;
}

void  setParentPointer_in_ICommandHeader(ICommandHeader* pICommandHeader, void* pParentPointer)
{
  pICommandHeader->pParentPointer_in_ICommandHeader = pParentPointer;
}

void CommandState_in_CommandState(CommandState *pCommandState, uint16_t index_)
{
//// : state(CommandPointState::INIT), status(CommandStatus::UNDEFINED), index(index_) {}
  pCommandState->state = CommandPointState_INIT;
  pCommandState->status = CommandStatus_UNDEFINED;
  pCommandState->index = index_;
}
