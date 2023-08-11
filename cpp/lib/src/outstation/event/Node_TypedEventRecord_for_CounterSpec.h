#ifndef OPENDNP3_NODE_TypedEventRecord_for_CounterSpec_H
#define OPENDNP3_NODE_TypedEventRecord_for_CounterSpec_H

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
  TypedEventRecord_for_CounterSpec value;

////private:
////    Node* prev = nullptr;
////    Node_TypedEventRecord_for_CounterSpec * prev;
  void * prev;
////    Node_TypedEventRecord_for_CounterSpec * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_TypedEventRecord_for_CounterSpec;

void Node_TypedEventRecord_for_CounterSpec_in_Node_TypedEventRecord_for_CounterSpec(
  Node_TypedEventRecord_for_CounterSpec *pNode_TypedEventRecord_for_CounterSpec);
#endif
