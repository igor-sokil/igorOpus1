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
#include "header.h"
#include "SerializationTemplates.h"
#include "LinkHeader.h"

#include "CRC.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

void LinkHeader_in_LinkHeaderOver1(LinkHeader *pLinkHeader)
{
 pLinkHeader->length = 5; 
 pLinkHeader->src = 0;
 pLinkHeader->dest = 0;
 pLinkHeader->ctrl = 0;
}

void LinkHeader_in_LinkHeaderOver2(LinkHeader *pLinkHeader,
    uint8_t aLen, uint16_t aSrc, uint16_t aDest, boolean aFromMaster, boolean aFcvDfc, boolean aFcb, LinkFunction_uint8_t aCode)
{
    Set_in_LinkHeader(pLinkHeader, aLen, aSrc, aDest, aFromMaster, aFcvDfc, aFcb, aCode);
}

void Set_in_LinkHeader(LinkHeader *pLinkHeader,
    uint8_t aLen, uint16_t aSrc, uint16_t aDest, boolean aFromMaster, boolean aFcvDfc, boolean aFcb, LinkFunction_uint8_t aCode)
{
    pLinkHeader->length = aLen;
    pLinkHeader->src = aSrc;
    pLinkHeader->dest = aDest;
//    uint8_t ControlByte_in_LinkHeader_static(boolean isMaster, boolean fcb, boolean fcvdfc, LinkFunction_uint8_t func);
    pLinkHeader->ctrl = ControlByte_in_LinkHeader_static(aFromMaster, aFcb, aFcvDfc, aCode);
}

void ChangeFCB_in_LinkHeader(LinkHeader *pLinkHeader, boolean aFCB)
{
    if (aFCB)
    {
        pLinkHeader->ctrl |= ControlMask_MASK_FCB;
    }
    else
    {
        pLinkHeader->ctrl &= ~(int)ControlMask_MASK_FCB;
    }
}

uint8_t ControlByte_in_LinkHeader_static(boolean aIsMaster, boolean aFcb, boolean aFcvDfc, LinkFunction_uint8_t aFunc)
{
////    uint8_t ret = LinkFunctionSpec::to_type(aFunc);
    uint8_t ret = aFunc;

    if (aIsMaster)
        ret |= ControlMask_MASK_DIR;
    if (aFcb)
        ret |= ControlMask_MASK_FCB;
    if (aFcvDfc)
        ret |= ControlMask_MASK_FCV;

    return ret;
}

void Read_in_LinkHeader(LinkHeader *pLinkHeader, uint8_t* apBuff)
{
    pLinkHeader->length = apBuff[LinkHeaderIndex_LI_LENGTH];
////    ser4cpp::rseq_t buffer(apBuff + LinkHeaderIndex_LI_DESTINATION, 4);
    RSeq_for_Uint16_t buffer;
    RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&buffer, apBuff + LinkHeaderIndex_LI_DESTINATION, 4);
////    ser4cpp::UInt16::read_from(buffer, dest);
    read_from_in_UInt16_static(&buffer, &(pLinkHeader->dest));
////    ser4cpp::UInt16::read_from(buffer, src);
    read_from_in_UInt16_static(&buffer, &(pLinkHeader->src));
    pLinkHeader->ctrl = apBuff[LinkHeaderIndex_LI_CONTROL];
}

void Write_in_LinkHeader(LinkHeader *pLinkHeader, uint8_t* apBuff) 
{
    apBuff[LinkHeaderIndex_LI_START_05] = 0x05;
    apBuff[LinkHeaderIndex_LI_START_64] = 0x64;

    apBuff[LinkHeaderIndex_LI_LENGTH] = pLinkHeader->length;
////    ser4cpp::wseq_t buffer(apBuff + LinkHeaderIndex_LI_DESTINATION, 4);
    WSeq_for_Uint16_t buffer;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&buffer, apBuff + LinkHeaderIndex_LI_DESTINATION, 4);

////    ser4cpp::UInt16::write_to(buffer, dest);
    write_to_in_UInt16_static(&buffer, pLinkHeader->dest);

////    ser4cpp::UInt16::write_to(buffer, src);
    write_to_in_UInt16_static(&buffer, pLinkHeader->src);

    apBuff[LinkHeaderIndex_LI_CONTROL] = pLinkHeader->ctrl;

// void AddCrc_in_CRC_static(uint8_t* input, uint16_t length);
////    CRC::AddCrc(apBuff, LinkHeaderIndex_LI_CRC);
    AddCrc_in_CRC_static(apBuff, LinkHeaderIndex_LI_CRC);
}

////} // namespace opendnp3

   uint8_t GetControl_in_LinkHeader(LinkHeader *pLinkHeader) 
    {
        return pLinkHeader->ctrl;
    }

    // Getters
    uint8_t GetLength_in_LinkHeader(LinkHeader *pLinkHeader) 
    {
        return pLinkHeader->length;
    }
    uint16_t GetDest_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return pLinkHeader->dest;
    }
    uint16_t GetSrc_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return pLinkHeader->src;
    }
    boolean IsFromMaster_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return (pLinkHeader->ctrl & ControlMask_MASK_DIR) != 0;
    }
    boolean IsPriToSec_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return (pLinkHeader->ctrl & ControlMask_MASK_PRM) != 0;
    }
    boolean IsFcbSet_in_LinkHeader(LinkHeader *pLinkHeader) 
    {
        return (pLinkHeader->ctrl & ControlMask_MASK_FCB) != 0;
    }
    boolean IsFcvDfcSet_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return (pLinkHeader->ctrl & ControlMask_MASK_FCV) != 0;
    }
    uint8_t GetFuncByte_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return pLinkHeader->ctrl & ControlMask_MASK_FUNC;
    }
    LinkFunction_uint8_t GetFuncEnum_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return from_type_in_LinkFunctionSpec(pLinkHeader->ctrl & ControlMask_MASK_FUNC_OR_PRM);
    }

    boolean ValidLength_in_LinkHeader(LinkHeader *pLinkHeader)
    {
        return pLinkHeader->length > 4;
    }
