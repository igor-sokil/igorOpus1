#include "header.h"
#include "ConstantCommandAction.h"

void ConstantCommandAction_in_ConstantCommandAction(ConstantCommandAction *pConstantCommandAction, CommandStatus_uint8_t status_)
{
  pConstantCommandAction->status = status_;

  (pConstantCommandAction->iICommandAction).pAction_ControlRelayOutputBlock_in_ICommandAction = Action_ControlRelayOutputBlock_in_ConstantCommandAction_override;
  (pConstantCommandAction->iICommandAction).pAction_AnalogOutputInt16_in_ICommandAction = Action_AnalogOutputInt16_in_ConstantCommandAction_override;
  (pConstantCommandAction->iICommandAction).pAction_AnalogOutputInt32_in_ICommandAction = Action_AnalogOutputInt32_in_ConstantCommandAction_override;
  (pConstantCommandAction->iICommandAction).pAction_AnalogOutputFloat32_in_ICommandAction = Action_AnalogOutputFloat32_in_ConstantCommandAction_override;
  (pConstantCommandAction->iICommandAction).pAction_AnalogOutputDouble64_in_ICommandAction = Action_AnalogOutputDouble64_in_ConstantCommandAction_override;

  setParentPointer_in_ICommandAction(&(pConstantCommandAction->iICommandAction), pConstantCommandAction);
}

////    virtual CommandStatus Action(const ControlRelayOutputBlock& command, uint16_t aIndex) final
CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_ConstantCommandAction_override(void *pICommandAction, ControlRelayOutputBlock* arCommand, uint16_t aIndex)
{
  UNUSED(arCommand);
  UNUSED(aIndex);
  ConstantCommandAction* parent = (ConstantCommandAction*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
  return parent->status;
}

////    virtual CommandStatus Action(const AnalogOutputInt16& command, uint16_t aIndex) final
CommandStatus_uint8_t Action_AnalogOutputInt16_in_ConstantCommandAction_override(void *pICommandAction, AnalogOutputInt16* arCommand, uint16_t aIndex)
{
  UNUSED(arCommand);
  UNUSED(aIndex);
  ConstantCommandAction* parent = (ConstantCommandAction*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
  return parent->status;
}

////    virtual CommandStatus Action(const AnalogOutputInt32& command, uint16_t aIndex) final
CommandStatus_uint8_t Action_AnalogOutputInt32_in_ConstantCommandAction_override(void *pICommandAction, AnalogOutputInt32* arCommand, uint16_t aIndex)
{
  UNUSED(arCommand);
  UNUSED(aIndex);
  ConstantCommandAction* parent = (ConstantCommandAction*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
  return parent->status;
}

////    virtual CommandStatus Action(const AnalogOutputFloat32& command, uint16_t aIndex) final
CommandStatus_uint8_t Action_AnalogOutputFloat32_in_ConstantCommandAction_override(void *pICommandAction, AnalogOutputFloat32* arCommand, uint16_t aIndex)
{
  UNUSED(arCommand);
  UNUSED(aIndex);
  ConstantCommandAction* parent = (ConstantCommandAction*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
  return parent->status;
}

////    virtual CommandStatus Action(const AnalogOutputDouble64& command, uint16_t aIndex) final
CommandStatus_uint8_t Action_AnalogOutputDouble64_in_ConstantCommandAction_override(void *pICommandAction, AnalogOutputDouble64* arCommand, uint16_t aIndex)
{
  UNUSED(arCommand);
  UNUSED(aIndex);
  ConstantCommandAction* parent = (ConstantCommandAction*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
  return parent->status;
}
