#include "header.h"
#include "ICommandAction.h"

CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_ICommandAction(ICommandAction * pICommandAction, ControlRelayOutputBlock* arCommand, uint16_t aIndex)
{
 return (pICommandAction->pAction_ControlRelayOutputBlock_in_ICommandAction)(pICommandAction, arCommand, aIndex);
}

CommandStatus_uint8_t Action_AnalogOutputInt16_in_ICommandAction(ICommandAction *pICommandAction, AnalogOutputInt16* arCommand, uint16_t aIndex)
{
 return (pICommandAction->pAction_AnalogOutputInt16_in_ICommandAction)(pICommandAction, arCommand, aIndex);
}

CommandStatus_uint8_t Action_AnalogOutputInt32_in_ICommandAction(ICommandAction *pICommandAction, AnalogOutputInt32* arCommand, uint16_t aIndex)
{
 return (pICommandAction->pAction_AnalogOutputInt32_in_ICommandAction)(pICommandAction, arCommand, aIndex);
}
CommandStatus_uint8_t Action_AnalogOutputFloat32_in_ICommandAction(ICommandAction *pICommandAction, AnalogOutputFloat32* arCommand, uint16_t aIndex)
{
 return (pICommandAction->pAction_AnalogOutputFloat32_in_ICommandAction)(pICommandAction, arCommand, aIndex);
}
CommandStatus_uint8_t Action_AnalogOutputDouble64_in_ICommandAction(ICommandAction *pICommandAction, AnalogOutputDouble64* arCommand, uint16_t aIndex)
{
 return (pICommandAction->pAction_AnalogOutputDouble64_in_ICommandAction)(pICommandAction, arCommand, aIndex);
}

void* getParentPointer_in_ICommandAction(ICommandAction* pICommandAction)
{
  return pICommandAction->pParentPointer_in_ICommandAction;
}

void  setParentPointer_in_ICommandAction(ICommandAction* pICommandAction, void* pParentPointer)
{
  pICommandAction->pParentPointer_in_ICommandAction = pParentPointer;
}
