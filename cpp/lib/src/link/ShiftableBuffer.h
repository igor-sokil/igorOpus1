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
#ifndef OPENDNP3_SHIFTABLEBUFFER_H
#define OPENDNP3_SHIFTABLEBUFFER_H

////#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"

////namespace opendnp3
////{

/** @section DESCRIPTION
        Implements a buffer that can shift its contents as it is read */
////class ShiftableBuffer
typedef struct
{
////public:
  /**
   * Construct the facade over the specified underlying buffer
   */
////    ShiftableBuffer(uint8_t* pBuffer_, size_t size);

  // ------- Functions related to reading -----------

////    size_t NumBytesRead() const
////    {
////        return writePos - readPos;
////    }

  /// @return Pointer to the next byte to be read in the buffer
////    ser4cpp::rseq_t ReadBuffer() const
////    {
////        return ser4cpp::rseq_t(pBuffer + readPos, NumBytesRead());
///    }

  /// Signal that some bytes don't have to be stored any longer. They'll be recovered during the next shift operation.
////    void AdvanceRead(size_t aNumBytes);

  // ------- Functions related to writing -----------

  /// Shift the buffer back to front, writing over bytes that have already been read. The objective
  /// being to free space for further writing.
////    void Shift();

  /// Reset the buffer to its initial state, empty
////    void Reset();

  /// @return Bytes of available for writing
////    size_t NumWriteBytes() const
////    {
////        return M_SIZE - writePos;
////    }

  /// @return Pointer to the position in the buffer available for writing
////    uint8_t* WriteBuff() const
////    {
////        return pBuffer + writePos;
////    }

  /// Signal to the buffer bytes were written to the current write position
////    void AdvanceWrite(size_t numBytes);

  ////////////////////////////////////////////
  // Other functions
  ////////////////////////////////////////////

  /// Searches the read subsequence for 0x0564 sync bytes
  /// @return true if both sync bytes were found in the buffer.
////    bool Sync(size_t& skipCount);

////private:
  uint8_t* pBuffer;
  uint16_t M_SIZE;
  uint16_t writePos;
  uint16_t readPos;
} ShiftableBuffer;

void ShiftableBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint8_t* pBuffer_, uint16_t size);
uint16_t NumBytesRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
RSeq_for_Uint16_t ReadBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);

// ------- Functions related to reading -----------

/// Signal that some bytes don't have to be stored any longer. They'll be recovered during the next shift operation.
/// Сигнал о том, что некоторые байты больше не нужно хранить. Они будут восстановлены во время работы следующей смены.
void AdvanceRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t aNumBytes);

// ------- Functions related to writing -----------

/// Shift the buffer back to front, writing over bytes that have already been read. The objective
/// being to free space for further writing.
/// Сдвигаем буфер назад вперед, перезаписывая байты, которые уже были прочитаны. Цель
/// чтобы освободить место для дальнейшего написания.
void Shift_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);

/// Reset the buffer to its initial state, empty
/// Сброс буфера в исходное состояние, пустой
void Reset_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);

/// @return Bytes of available for writing
uint16_t NumWriteBytes_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);

/// @return Pointer to the position in the buffer available for writing
/// @return Указатель на доступную для записи позицию в буфере
uint8_t* WriteBuff_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);

/// Signal to the buffer bytes were written to the current write position
/// Сигнал в буфер байты были записаны в текущую позицию записи
void AdvanceWrite_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t numBytes);

////////////////////////////////////////////
// Other functions
////////////////////////////////////////////

/// Searches the read subsequence for 0x0564 sync bytes
/// @return true if both sync bytes were found in the buffer.
/// Ищет в прочитанной подпоследовательности 0x0564 байта синхронизации
/// @return true, если в буфере были найдены оба байта синхронизации.
boolean Sync_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t* skipCount);

////} // namespace opendnp3

#endif
