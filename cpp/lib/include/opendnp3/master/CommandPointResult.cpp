#include "header.h"
#include "CommandPointResult.h"

    /// Fully construct based on all members
  void CommandPointResult_in_CommandPointResult(CommandPointResult *pCommandPointResult,
                                  uint32_t headerIndex_, uint16_t index_, CommandPointState_uint8_t state_, CommandStatus_uint8_t status_)
{
////    : headerIndex(headerIndex_), index(index_), state(state_), status(status_)
     pCommandPointResult->headerIndex = headerIndex_;
     pCommandPointResult->index = index_;
     pCommandPointResult->state = state_;
     pCommandPointResult->status = status_;
}

    /// Check the result for equality against another value
    boolean Equals_in_CommandPointResult(CommandPointResult *pCommandPointResult, CommandPointResult* other)
{
    return (pCommandPointResult->headerIndex == other->headerIndex) &&
           (pCommandPointResult->index == other->index) &&
           (pCommandPointResult->state == other->state) &&
           (pCommandPointResult->status == other->status);
}
