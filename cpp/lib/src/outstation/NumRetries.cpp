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

////#include "opendnp3/outstation/NumRetries.h"
#include "header.h"
#include "NumRetries.h"

////namespace opendnp3
////{

void NumRetries_in_NumRetries(NumRetries *pNumRetries, uint16_t maxNumRetries, boolean isInfinite)
{
  pNumRetries->numRetries = 0;
  pNumRetries->maxNumRetries = maxNumRetries;
  pNumRetries->isInfinite = isInfinite;
}

NumRetries Fixed_in_NumRetries_static(uint16_t maxNumRetries)
{
  NumRetries nNumRetries;
  NumRetries_in_NumRetries(&nNumRetries, maxNumRetries, false);
////    return NumRetries(maxNumRetries, false);
  return nNumRetries;
}

NumRetries Infinite_in_NumRetries_static(void)
{
  NumRetries nNumRetries;
  NumRetries_in_NumRetries(&nNumRetries, 0, true);
////    return NumRetries(0, true);
  return nNumRetries;
}

boolean Retry_in_NumRetries(NumRetries *pNumRetries)
{
  (pNumRetries->numRetries)++;

  return pNumRetries->isInfinite || (pNumRetries->numRetries <= pNumRetries->maxNumRetries);
}

void Reset_in_NumRetries(NumRetries *pNumRetries)
{
  pNumRetries->numRetries = 0;
}

////}; // namespace opendnp3
