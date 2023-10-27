
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "MeasurementTypes.h"
#include "Serializer.h"

//------------------------Serializer_for_AnalogCommandEvent----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_AnalogCommandEvent(Serializer_for_AnalogCommandEvent *pSerializer_for_AnalogCommandEvent)
{
  return pSerializer_for_AnalogCommandEvent->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_AnalogCommandEvent(Serializer_for_AnalogCommandEvent *pSerializer_for_AnalogCommandEvent, RSeq_for_Uint16_t *buffer, AnalogCommandEvent *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogCommandEvent->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_AnalogCommandEvent(Serializer_for_AnalogCommandEvent *pSerializer_for_AnalogCommandEvent, AnalogCommandEvent *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogCommandEvent->write_func)(value, buffer);
}

void Serializer_for_AnalogCommandEvent_in_Serializer_for_AnalogCommandEvent(Serializer_for_AnalogCommandEvent *pSerializer_for_AnalogCommandEvent,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogCommandEvent  read_func,
    write_func_t_in_Serializer_for_AnalogCommandEvent write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_AnalogCommandEvent->size = size;
  pSerializer_for_AnalogCommandEvent->read_func = read_func;
  pSerializer_for_AnalogCommandEvent->write_func = write_func;
}
//------------------------Serializer_for_AnalogCommandEvent----------------------------------------------------
//------------------------Serializer_for_BinaryCommandEvent----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent)
{
  return pSerializer_for_BinaryCommandEvent->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent, RSeq_for_Uint16_t *buffer, BinaryCommandEvent *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_BinaryCommandEvent->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent, BinaryCommandEvent *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_BinaryCommandEvent->write_func)(value, buffer);
}

void Serializer_for_BinaryCommandEvent_in_Serializer_for_BinaryCommandEvent(Serializer_for_BinaryCommandEvent *pSerializer_for_BinaryCommandEvent,
    uint16_t size,
    read_func_t_in_Serializer_for_BinaryCommandEvent  read_func,
    write_func_t_in_Serializer_for_BinaryCommandEvent write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_BinaryCommandEvent->size = size;
  pSerializer_for_BinaryCommandEvent->read_func = read_func;
  pSerializer_for_BinaryCommandEvent->write_func = write_func;
}
//------------------------Serializer_for_BinaryCommandEvent----------------------------------------------------
//------------------------Serializer_for_FrozenCounter----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter)
{
  return pSerializer_for_FrozenCounter->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter, RSeq_for_Uint16_t *buffer, FrozenCounter *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_FrozenCounter->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter, FrozenCounter *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_FrozenCounter->write_func)(value, buffer);
}

void Serializer_for_FrozenCounter_in_Serializer_for_FrozenCounter(Serializer_for_FrozenCounter *pSerializer_for_FrozenCounter,
    uint16_t size,
    read_func_t_in_Serializer_for_FrozenCounter  read_func,
    write_func_t_in_Serializer_for_FrozenCounter write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_FrozenCounter->size = size;
  pSerializer_for_FrozenCounter->read_func = read_func;
  pSerializer_for_FrozenCounter->write_func = write_func;
}
//------------------------Serializer_for_FrozenCounter----------------------------------------------------
//------------------------Serializer_for_BinaryOutputStatus----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus)
{
  return pSerializer_for_BinaryOutputStatus->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus, RSeq_for_Uint16_t *buffer, BinaryOutputStatus *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_BinaryOutputStatus->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus, BinaryOutputStatus *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_BinaryOutputStatus->write_func)(value, buffer);
}

void Serializer_for_BinaryOutputStatus_in_Serializer_for_BinaryOutputStatus(Serializer_for_BinaryOutputStatus *pSerializer_for_BinaryOutputStatus,
    uint16_t size,
    read_func_t_in_Serializer_for_BinaryOutputStatus  read_func,
    write_func_t_in_Serializer_for_BinaryOutputStatus write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_BinaryOutputStatus->size = size;
  pSerializer_for_BinaryOutputStatus->read_func = read_func;
  pSerializer_for_BinaryOutputStatus->write_func = write_func;
}
//------------------------Serializer_for_BinaryOutputStatus----------------------------------------------------
//------------------------Serializer_for_DoubleBitBinary----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary)
{
  return pSerializer_for_DoubleBitBinary->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary, RSeq_for_Uint16_t *buffer, DoubleBitBinary *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_DoubleBitBinary->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary, DoubleBitBinary *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_DoubleBitBinary->write_func)(value, buffer);
}

void Serializer_for_DoubleBitBinary_in_Serializer_for_DoubleBitBinary(Serializer_for_DoubleBitBinary *pSerializer_for_DoubleBitBinary,
    uint16_t size,
    read_func_t_in_Serializer_for_DoubleBitBinary  read_func,
    write_func_t_in_Serializer_for_DoubleBitBinary write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_DoubleBitBinary->size = size;
  pSerializer_for_DoubleBitBinary->read_func = read_func;
  pSerializer_for_DoubleBitBinary->write_func = write_func;
}
//------------------------Serializer_for_DoubleBitBinary----------------------------------------------------
//------------------------Serializer_for_Binary----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary)
{
  return pSerializer_for_Binary->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary, RSeq_for_Uint16_t *buffer, Binary *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_Binary->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary, Binary *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_Binary->write_func)(value, buffer);
}

void Serializer_for_Binary_in_Serializer_for_Binary(Serializer_for_Binary *pSerializer_for_Binary,
    uint16_t size,
    read_func_t_in_Serializer_for_Binary  read_func,
    write_func_t_in_Serializer_for_Binary write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_Binary->size = size;
  pSerializer_for_Binary->read_func = read_func;
  pSerializer_for_Binary->write_func = write_func;
}
//------------------------Serializer_for_Binary----------------------------------------------------
//------------------------Serializer_for_OctetString----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString)
{
  return pSerializer_for_OctetString->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString, RSeq_for_Uint16_t *buffer, OctetString *output)
{
  return //POINTER_read_func_t_in_Serializer_for_OctetString_FUNCTION
    (pSerializer_for_OctetString->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString, OctetString *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_OctetString_FUNCTION
    (pSerializer_for_OctetString->write_func)(value, buffer);
}

void Serializer_for_OctetString_in_Serializer_for_OctetString(Serializer_for_OctetString *pSerializer_for_OctetString,
    uint16_t size,
    read_func_t_in_Serializer_for_OctetString  read_func,
    write_func_t_in_Serializer_for_OctetString write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_OctetString->size = size;
  pSerializer_for_OctetString->read_func = read_func;
  pSerializer_for_OctetString->write_func = write_func;
}
//------------------------Serializer_for_OctetString----------------------------------------------------
//------------------------Serializer_for_Counter----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter)
{
  return pSerializer_for_Counter->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter, RSeq_for_Uint16_t *buffer, Counter *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_Counter->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter, Counter *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_Counter->write_func)(value, buffer);
}

void Serializer_for_Counter_in_Serializer_for_Counter(Serializer_for_Counter *pSerializer_for_Counter,
    uint16_t size,
    read_func_t_in_Serializer_for_Counter  read_func,
    write_func_t_in_Serializer_for_Counter write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_Counter->size = size;
  pSerializer_for_Counter->read_func = read_func;
  pSerializer_for_Counter->write_func = write_func;
}
//------------------------Serializer_for_Counter----------------------------------------------------
//------------------------Serializer_for_Analog----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog)
{
  return pSerializer_for_Analog->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog, RSeq_for_Uint16_t *buffer, Analog *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_Analog->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
* записывает значение и перемещает буфер записи
 */
boolean write_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog, Analog *value, WSeq_for_Uint16_t *buffer)
{
/*
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"write_in_Serializer_for_Analog1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*buffer->buffer_= "<<std::dec<<(uint32_t)buffer->buffer_<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pSerializer_for_Analog->write_func= "<<std::dec<<(uint32_t)pSerializer_for_Analog->write_func<<'\n';
  decrement_stack_info();
#endif
*/
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_Analog->write_func)(value, buffer);
}

void Serializer_for_Analog_in_Serializer_for_Analog(Serializer_for_Analog *pSerializer_for_Analog,
    uint16_t size,
    read_func_t_in_Serializer_for_Analog  read_func,
    write_func_t_in_Serializer_for_Analog write_func)
{
/*
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Serializer_for_Analog_in_Serializer_for_Analog"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pSerializer_for_Analog->write_func= "<<std::dec<<(uint32_t)write_func<<'\n';
  decrement_stack_info();
#endif
*/
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_Analog->size = size;
  pSerializer_for_Analog->read_func = read_func;
  pSerializer_for_Analog->write_func = write_func;
}
//------------------------Serializer_for_Analog----------------------------------------------------
//------------------------Serializer_for_AnalogOutputStatus----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus)
{
  return pSerializer_for_AnalogOutputStatus->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus, RSeq_for_Uint16_t *buffer, AnalogOutputStatus *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputStatus->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus, AnalogOutputStatus *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputStatus->write_func)(value, buffer);
}

void Serializer_for_AnalogOutputStatus_in_Serializer_for_AnalogOutputStatus(Serializer_for_AnalogOutputStatus *pSerializer_for_AnalogOutputStatus,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputStatus  read_func,
    write_func_t_in_Serializer_for_AnalogOutputStatus write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_AnalogOutputStatus->size = size;
  pSerializer_for_AnalogOutputStatus->read_func = read_func;
  pSerializer_for_AnalogOutputStatus->write_func = write_func;
}
//------------------------Serializer_for_AnalogOutputStatus----------------------------------------------------
//------------------------Serializer_for_TimeAndInterval----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval)
{
  return pSerializer_for_TimeAndInterval->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval, RSeq_for_Uint16_t *buffer, TimeAndInterval *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_TimeAndInterval->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval, TimeAndInterval *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_TimeAndInterval->write_func)(value, buffer);
}

void Serializer_for_TimeAndInterval_in_Serializer_for_TimeAndInterval(Serializer_for_TimeAndInterval *pSerializer_for_TimeAndInterval,
    uint16_t size,
    read_func_t_in_Serializer_for_TimeAndInterval  read_func,
    write_func_t_in_Serializer_for_TimeAndInterval write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_TimeAndInterval->size = size;
  pSerializer_for_TimeAndInterval->read_func = read_func;
  pSerializer_for_TimeAndInterval->write_func = write_func;
}
//------------------------Serializer_for_TimeAndInterval----------------------------------------------------
//------------------------Serializer_for_ControlRelayOutputBlock----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock)
{
  return pSerializer_for_ControlRelayOutputBlock->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock, RSeq_for_Uint16_t *buffer, ControlRelayOutputBlock *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_ControlRelayOutputBlock->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock, ControlRelayOutputBlock *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_ControlRelayOutputBlock->write_func)(value, buffer);
}

void Serializer_for_ControlRelayOutputBlock_in_Serializer_for_ControlRelayOutputBlock(Serializer_for_ControlRelayOutputBlock *pSerializer_for_ControlRelayOutputBlock,
    uint16_t size,
    read_func_t_in_Serializer_for_ControlRelayOutputBlock  read_func,
    write_func_t_in_Serializer_for_ControlRelayOutputBlock write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_ControlRelayOutputBlock->size = size;
  pSerializer_for_ControlRelayOutputBlock->read_func = read_func;
  pSerializer_for_ControlRelayOutputBlock->write_func = write_func;
}
//------------------------Serializer_for_ControlRelayOutputBlock----------------------------------------------------
//------------------------Serializer_for_AnalogOutputInt16----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16)
{
  return pSerializer_for_AnalogOutputInt16->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16, RSeq_for_Uint16_t *buffer, AnalogOutputInt16 *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputInt16->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16, AnalogOutputInt16 *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputInt16->write_func)(value, buffer);
}

void Serializer_for_AnalogOutputInt16_in_Serializer_for_AnalogOutputInt16(Serializer_for_AnalogOutputInt16 *pSerializer_for_AnalogOutputInt16,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputInt16  read_func,
    write_func_t_in_Serializer_for_AnalogOutputInt16 write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_AnalogOutputInt16->size = size;
  pSerializer_for_AnalogOutputInt16->read_func = read_func;
  pSerializer_for_AnalogOutputInt16->write_func = write_func;
}
//------------------------Serializer_for_AnalogOutputInt16----------------------------------------------------
//------------------------Serializer_for_AnalogOutputInt32----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32)
{
  return pSerializer_for_AnalogOutputInt32->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32, RSeq_for_Uint16_t *buffer, AnalogOutputInt32 *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputInt32->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32, AnalogOutputInt32 *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputInt32->write_func)(value, buffer);
}

void Serializer_for_AnalogOutputInt32_in_Serializer_for_AnalogOutputInt32(Serializer_for_AnalogOutputInt32 *pSerializer_for_AnalogOutputInt32,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputInt32  read_func,
    write_func_t_in_Serializer_for_AnalogOutputInt32 write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_AnalogOutputInt32->size = size;
  pSerializer_for_AnalogOutputInt32->read_func = read_func;
  pSerializer_for_AnalogOutputInt32->write_func = write_func;
}
//------------------------Serializer_for_AnalogOutputInt32----------------------------------------------------
//------------------------Serializer_for_AnalogOutputFloat32----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32)
{
  return pSerializer_for_AnalogOutputFloat32->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32, RSeq_for_Uint16_t *buffer, AnalogOutputFloat32 *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputFloat32->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32, AnalogOutputFloat32 *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputFloat32->write_func)(value, buffer);
}

void Serializer_for_AnalogOutputFloat32_in_Serializer_for_AnalogOutputFloat32(Serializer_for_AnalogOutputFloat32 *pSerializer_for_AnalogOutputFloat32,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputFloat32  read_func,
    write_func_t_in_Serializer_for_AnalogOutputFloat32 write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_AnalogOutputFloat32->size = size;
  pSerializer_for_AnalogOutputFloat32->read_func = read_func;
  pSerializer_for_AnalogOutputFloat32->write_func = write_func;
}
//------------------------Serializer_for_AnalogOutputFloat32----------------------------------------------------
//------------------------Serializer_for_AnalogOutputDouble64----------------------------------------------------
/**
 * @return The size (in bytes) required for every call to read/write
 */
uint16_t get_size_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64)
{
  return pSerializer_for_AnalogOutputDouble64->size;
}

/**
 * reads the value and advances the read buffer
 */
boolean read_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64, RSeq_for_Uint16_t *buffer, AnalogOutputDouble64 *output)
{
  return //POINTER_read_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputDouble64->read_func)(buffer, output);

}

/**
 * writes the value and advances the write buffer
 */
boolean write_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64, AnalogOutputDouble64 *value, WSeq_for_Uint16_t *buffer)
{
  return //POINTER_write_func_t_in_Serializer_for_Binary_FUNCTION
    (pSerializer_for_AnalogOutputDouble64->write_func)(value, buffer);
}

void Serializer_for_AnalogOutputDouble64_in_Serializer_for_AnalogOutputDouble64(Serializer_for_AnalogOutputDouble64 *pSerializer_for_AnalogOutputDouble64,
    uint16_t size,
    read_func_t_in_Serializer_for_AnalogOutputDouble64  read_func,
    write_func_t_in_Serializer_for_AnalogOutputDouble64 write_func)
{
////        : size(size), read_func(read_func), write_func(write_func)
  pSerializer_for_AnalogOutputDouble64->size = size;
  pSerializer_for_AnalogOutputDouble64->read_func = read_func;
  pSerializer_for_AnalogOutputDouble64->write_func = write_func;
}
//------------------------Serializer_for_AnalogOutputDouble64----------------------------------------------------
