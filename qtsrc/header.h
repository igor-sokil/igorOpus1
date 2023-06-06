#ifndef __HEADER__
#define __HEADER__

#define uint8_t  unsigned char
#define int8_t            char
#define uint16_t unsigned short
#define  int16_t          short
#define uint32_t unsigned int
#define  int32_t          int

#define uint64_t unsigned long long
#define  int64_t          long long

#define  boolean          int

//#define CommandStatus_uint8_t  uint8_t

#define UNUSED(x) (void)(x)

//#define  NULL          0
//макс к-сть EventRecord
#define MAX_EventRecord  10
#define SIZE_for_EventRecord                             (8*MAX_EventRecord)
#define SIZE_TypedEventRecord_for_AnalogOutputStatusSpec MAX_EventRecord
#define SIZE_TypedEventRecord_for_AnalogSpec             MAX_EventRecord
#define SIZE_TypedEventRecord_for_BinaryOutputStatusSpec MAX_EventRecord
#define SIZE_TypedEventRecord_for_BinarySpec             MAX_EventRecord
#define SIZE_TypedEventRecord_for_CounterSpec            MAX_EventRecord
#define SIZE_TypedEventRecord_for_DoubleBitBinarySpec    MAX_EventRecord
#define SIZE_TypedEventRecord_for_FrozenCounterSpec      MAX_EventRecord
#define SIZE_TypedEventRecord_for_OctetStringSpec        MAX_EventRecord

#endif
