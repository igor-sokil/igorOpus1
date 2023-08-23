#ifndef __HEADER__
#define __HEADER__

#ifndef uint8_t
#define uint8_t  unsigned char
#endif
#ifndef int8_t
#define int8_t            char
#endif
#ifndef uint16_t
#define uint16_t unsigned short
#endif
#ifndef  int16_t
#define  int16_t          short
#endif
#ifndef uint32_t
#define uint32_t unsigned int
#endif
#ifndef  int32_t
#define  int32_t          int
#endif

#ifndef uint64_t
#define uint64_t unsigned long long
#endif
#ifndef  int64_t
#define  int64_t          long long
#endif

#ifndef  boolean
#define  boolean          int
#endif

#define UNUSED(x) (void)(x)

//макс к-сть EventRecord
#define MAX_EventRecord  10
#define SIZE_TypedEventRecord_for_AnalogOutputStatusSpec MAX_EventRecord
#define SIZE_TypedEventRecord_for_AnalogSpec             MAX_EventRecord
#define SIZE_TypedEventRecord_for_BinaryOutputStatusSpec MAX_EventRecord
#define SIZE_TypedEventRecord_for_BinarySpec             MAX_EventRecord
#define SIZE_TypedEventRecord_for_CounterSpec            MAX_EventRecord
#define SIZE_TypedEventRecord_for_DoubleBitBinarySpec    MAX_EventRecord
#define SIZE_TypedEventRecord_for_FrozenCounterSpec      MAX_EventRecord
#define SIZE_TypedEventRecord_for_OctetStringSpec        MAX_EventRecord

#define MAX_BufferSer4  292
#define SIZE_TxBuffer_in_OutstationSolState    MAX_BufferSer4
#define SIZE_TxBuffer_in_OutstationUnsolState  MAX_BufferSer4
#define SIZE_BufferSer4_in_DeferredRequest     MAX_BufferSer4

#define SIZE_CopyableBuffer  10

#include "memory_header.h"

#define SIZE_for_EventRecord                             SIZE_TypedEventRecord_for_AnalogOutputStatusSpec + \
                                                         SIZE_TypedEventRecord_for_AnalogSpec + \
                                                         SIZE_TypedEventRecord_for_BinaryOutputStatusSpec + \
                                                         SIZE_TypedEventRecord_for_BinarySpec + \
                                                         SIZE_TypedEventRecord_for_CounterSpec + \
                                                         SIZE_TypedEventRecord_for_DoubleBitBinarySpec + \
                                                         SIZE_TypedEventRecord_for_FrozenCounterSpec + \
                                                         SIZE_TypedEventRecord_for_OctetStringSpec 

extern void* pPointerGlobal1;
extern void* pPointerGlobal2;
extern void* pPointerGlobal3;

typedef void  (* pVoidVoidFunction(void));//указатель на ф-цию VoidVoid
#define VOIDVOID_FUNCTION(function)  (*(pVoidVoidFunction *)function)

#include "MemoryInspect.h"

#endif
