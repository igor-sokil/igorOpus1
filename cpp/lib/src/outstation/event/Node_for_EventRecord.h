#ifndef OPENDNP3_NODE_for_EventRecord_H
#define OPENDNP3_NODE_for_EventRecord_H

//#include <string.h>
//#include "HasLength.h"
#include "EventRecord.h"
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
  EventRecord value;

////private:
////    Node* prev = nullptr;
////    Node_for_EventRecord * prev;
  void * prev;
////    Node_for_EventRecord * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_for_EventRecord;

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord);
#endif
