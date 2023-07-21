
//#undef  SIZE_TxBuffer_in_OutstationSolState
//#define SIZE_TxBuffer_in_OutstationSolState 200

#define SIZE_for_EventRecord                             SIZE_TypedEventRecord_for_AnalogOutputStatusSpec + \
                                                         SIZE_TypedEventRecord_for_AnalogSpec + \
                                                         SIZE_TypedEventRecord_for_BinaryOutputStatusSpec + \
                                                         SIZE_TypedEventRecord_for_BinarySpec + \
                                                         SIZE_TypedEventRecord_for_CounterSpec + \
                                                         SIZE_TypedEventRecord_for_DoubleBitBinarySpec + \
                                                         SIZE_TypedEventRecord_for_FrozenCounterSpec + \
                                                         SIZE_TypedEventRecord_for_OctetStringSpec 
