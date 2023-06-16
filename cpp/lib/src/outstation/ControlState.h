/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef OPENDNP3_CONTROLSTATE_H
#define OPENDNP3_CONTROLSTATE_H

////#include "app/AppSeqNum.h"
////#include "link/CRC.h"

////#include "opendnp3/gen/CommandStatus.h"
////#include "opendnp3/util/Timestamp.h"

#include "AppSeqNum.h"
#include "CRC.h"

#include "CommandStatus.h"
#include "Timestamp.h"

////namespace opendnp3
////{

///
/// Represent all of the mutable state for SBO controls
///
////class ControlState
typedef struct
{

////public:
////    ControlState() = default;

////    CommandStatus ValidateSelection(const AppSeqNum& seq,
////                                    const Timestamp& now,
////                                    const TimeDuration& timeout,
////                                    const ser4cpp::rseq_t& objects) const
////    {
////        if (selected && expectedSeq.Equals(seq))
////        {
////            if (selectTime <= now)
////            {
////                auto elapsed = now - selectTime;
////                if (elapsed < timeout)
////                {
////                    if (length == objects.length() && digest == CRC::CalcCrc(objects))
////                    {
////                        return CommandStatus::SUCCESS;
////                    }
////                    else
////                    {
////                        return CommandStatus::NO_SELECT;
////                    }
////                }
////                else
////                {
////                    return CommandStatus::TIMEOUT;
////                }
////            }
////            else
////            {
////                return CommandStatus::TIMEOUT;
////            }
////        }
////        else
////        {
////            return CommandStatus::NO_SELECT;
////        }
////    }

////    void Select(const AppSeqNum& currentSeqN, const Timestamp& now, const ser4cpp::rseq_t& objects)
////    {
////        selected = true;
////        selectTime = now;
////        expectedSeq = currentSeqN.Next();
////        digest = CRC::CalcCrc(objects);
////        length = objects.length();
////    }

////    void Unselect()
////    {
////        selected = false;
////    }

////private:
  boolean selected;// = false;
  AppSeqNum expectedSeq;
  Timestamp selectTime;
  uint16_t digest;// = 0;
  uint16_t length;// = 0;
} ControlState;

void Unselect_in_ControlState(ControlState *pControlState);
void Select_in_ControlState(ControlState *pControlState,  AppSeqNum* currentSeqN, Timestamp* now, RSeq_for_Uint16_t* objects);
CommandStatus_uint8_t ValidateSelection_in_ControlState(ControlState *pControlState,
    AppSeqNum* seq,
    Timestamp* now,
    TimeDuration* timeout,
    RSeq_for_Uint16_t* objects);
void ControlState_in_ControlStateOver1(ControlState *pControlState);

////} // namespace opendnp3

#endif
