#ifndef __HEADER__
#define __HEADER__

#define  boolean          int

#include "constants.h"
#include "fatfs.h"
#include "lib.h"
#include "variables_external.h"
#include "functions_external.h"

#include "variables_external_m.h"


#define MAX_EventRecord  10
#define SIZE_TypedEventRecord_for_AnalogOutputStatusSpec MAX_EventRecord
#define SIZE_TypedEventRecord_for_AnalogSpec             MAX_EventRecord
#define SIZE_TypedEventRecord_for_BinaryOutputStatusSpec MAX_EventRecord
#define SIZE_TypedEventRecord_for_BinarySpec             MAX_EventRecord
#define SIZE_TypedEventRecord_for_CounterSpec            MAX_EventRecord
#define SIZE_TypedEventRecord_for_DoubleBitBinarySpec    MAX_EventRecord
#define SIZE_TypedEventRecord_for_FrozenCounterSpec      MAX_EventRecord
#define SIZE_TypedEventRecord_for_OctetStringSpec        MAX_EventRecord
#define SIZE_for_EventRecord                             SIZE_TypedEventRecord_for_AnalogOutputStatusSpec + \
                                                         SIZE_TypedEventRecord_for_AnalogSpec + \
                                                         SIZE_TypedEventRecord_for_BinaryOutputStatusSpec + \
                                                         SIZE_TypedEventRecord_for_BinarySpec + \
                                                         SIZE_TypedEventRecord_for_CounterSpec + \
                                                         SIZE_TypedEventRecord_for_DoubleBitBinarySpec + \
                                                         SIZE_TypedEventRecord_for_FrozenCounterSpec + \
                                                         SIZE_TypedEventRecord_for_OctetStringSpec 
#define MAX_BufferSer4  292

extern void* pPointerGlobal1;
extern void* pPointerGlobal2;
extern void* pPointerGlobal3;

#endif
