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
#include <opendnp3/gen/AnalogQuality.h>

#include <app/WriteConversions.h>
#include <catch.hpp>

using namespace opendnp3;

#define SUITE(name) "WriteConversionTestSuite - " name

TEST_CASE(SUITE("1Group30Var2ConvertsWithinRange"))
{
    Analog a(12);
    auto gv = ConvertGroup30Var2::Apply(a);

    CHECK(gv.value == 12);
    CHECK(gv.flags == AnalogQualitySpec::to_type(AnalogQuality::ONLINE));
}

TEST_CASE(SUITE("2Group30Var2ConvertsOverrange"))
{
    Analog a(32768);
    auto gv = ConvertGroup30Var2::Apply(a);

    CHECK(gv.value == 32767);
    CHECK(
        gv.flags
        == (AnalogQualitySpec::to_type(AnalogQuality::ONLINE) | AnalogQualitySpec::to_type(AnalogQuality::OVERRANGE)));
}

TEST_CASE(SUITE("3Group30Var2ConvertsUnderrange"))
{
    Analog a(-32769);
    auto gv = ConvertGroup30Var2::Apply(a);

    CHECK(gv.value == -32768);
    CHECK(
        gv.flags
        == (AnalogQualitySpec::to_type(AnalogQuality::ONLINE) | AnalogQualitySpec::to_type(AnalogQuality::OVERRANGE)));
}
