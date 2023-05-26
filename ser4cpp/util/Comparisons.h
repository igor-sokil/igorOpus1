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
#ifndef SER4CPP_COMPARISONS_H
#define SER4CPP_COMPARISONS_H

 uint16_t min_for_Uint16_t(uint16_t a, uint16_t b);
 uint16_t max_for_Uint16_t(uint16_t a, uint16_t b);
 uint16_t boundedTemplateUint16_t(uint16_t value, uint16_t minimum, uint16_t maximum);
boolean is_within_limitsTemplateUint16_t(uint16_t value, uint16_t min, uint16_t max);
//----------------------------------------------------------------
// int8_t minTemplateUint8_t(uint8_t a, uint8_t b);
// int8_t maxTemplateUint8_t(uint8_t a, uint8_t b);
// int8_t boundedTemplateUint8_t(uint8_t value, uint8_t minimum, uint8_t maximum);
//boolean is_within_limitsTemplateUint8_t(uint8_t value, uint8_t min, uint8_t max);

boolean float_equalTemplateFloat(float a, float b, float epsillon);//// = 1e-6)

////namespace ser4cpp
////{

////template <class T>
////inline T min(T a, T b)

////}

#endif
