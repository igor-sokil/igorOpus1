#ifndef OPENDNP3_NODE_TypedEventRecord_for_AnalogOutputStatusSpec_H
#define OPENDNP3_NODE_TypedEventRecord_for_AnalogOutputStatusSpec_H

//#include "HasLength.h"
#include "TypedEventRecord.h"
////#include <ser4cpp/container/Array.h>

////#include <cstdint>

//#include "EventStorage.h"
////namespace opendnp3
////{

////using list_size_type_t = uint32_t;

////template<class T> class Node
typedef struct
{
////public:
////    Node() = default;

////    T value;
  TypedEventRecord_for_AnalogOutputStatusSpec value;

////private:
////    Node* prev = nullptr;
////    Node_TypedEventRecord_for_AnalogOutputStatusSpec * prev;
  void * prev;
////    Node_TypedEventRecord_for_AnalogOutputStatusSpec * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_TypedEventRecord_for_AnalogOutputStatusSpec;

void Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Node_TypedEventRecord_for_AnalogOutputStatusSpec(
  Node_TypedEventRecord_for_AnalogOutputStatusSpec *pNode_TypedEventRecord_for_AnalogOutputStatusSpec);
#endif
