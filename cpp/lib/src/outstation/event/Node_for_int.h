#ifndef OPENDNP3_NODE_for_int_H
#define OPENDNP3_NODE_for_int_H

//#include "HasLength.h"
//#include "int.h"
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
  int value;

////private:
////    Node* prev = nullptr;
////    Node_for_int * prev;
  void * prev;
////    Node_for_int * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_for_int;

void Node_for_int_in_Node_for_int(Node_for_int *pNode_for_int);
#endif
