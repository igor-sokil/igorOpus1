#ifndef OPENDNP3_COMMAND_STATE_H
#define OPENDNP3_COMMAND_STATE_H

#include "CommandPointResult.h"

////struct CommandState
typedef struct
{
////    CommandState(uint16_t index_) : state(CommandPointState::INIT), status(CommandStatus::UNDEFINED), index(index_) {}

  CommandPointState_uint8_t state;
  CommandStatus_uint8_t status;
  uint16_t index;
} CommandState;

void CommandState_in_CommandState(CommandState *pCommandState, uint16_t index_);

#endif
