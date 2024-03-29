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
#ifndef EXE4CPP_ISTEADYTIMESOURCE_H
#define EXE4CPP_ISTEADYTIMESOURCE_H

////#include "exe4cpp/Typedefs.h"

////namespace exe4cpp
////{

////class ISteadyTimeSource
typedef struct
{
////public:
////    virtual ~ISteadyTimeSource() = default;

  /// @return a non-absolute timestamp for the monotonic time source
////    virtual steady_time_t get_time() = 0;
  uint64_t (*pGet_time_in_ISteadyTimeSourceExe4cpp)(void*);// = 0;

  void* pParentPointer_in_ISteadyTimeSourceExe4cpp;
} ISteadyTimeSourceExe4cpp;

void ISteadyTimeSourceExe4cpp_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *pISteadyTimeSourceExe4cpp);

uint64_t Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
uint64_t Get_time_in_ISteadyTimeSourceExe4cpp_override(void *);

void* getParentPointer_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp*);
void  setParentPointer_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp*, void*);

////}

#endif
