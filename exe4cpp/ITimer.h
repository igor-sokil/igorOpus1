/*
 * Copyright (c) 2018, Automatak LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef EXE4CPP_ITIMER_H
#define EXE4CPP_ITIMER_H

////#include "exe4cpp/Typedefs.h"

////namespace exe4cpp
////{

/**
 * Timer are used to defer events for a later time on an executor.
* “аймер используетс€ дл€ отсрочки событий на исполнителе на более позднее врем€.
 */
////class ITimer
typedef struct
{
////public:
////    virtual ~ITimer() = default;

  void (*pcancel_in_ITimer)(void*);// = 0;
  uint32_t (*pexpires_at_in_ITimer)(void*);// = 0;

  void* pParentPointer_in_ITimer;
  void* psource_in_ITimer;
} ITimer;

void cancel_in_ITimer(ITimer*);
uint32_t expires_at_in_ITimer(ITimer*);

void* getParentPointer_in_ITimer(ITimer*);
void  setParentPointer_in_ITimer(ITimer*, void*);


////}

#endif
