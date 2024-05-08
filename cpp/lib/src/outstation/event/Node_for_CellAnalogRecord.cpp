#include "header.h"
#include "Node_for_CellAnalogRecord.h"

#include <string.h>

void Node_for_CellAnalogRecord_in_Node_for_CellAnalogRecord(Node_for_CellAnalogRecord *pNode_for_CellAnalogRecord)
{
  CellAnalogRecord_in_CellAnalogRecord(&(pNode_for_CellAnalogRecord->value));
  pNode_for_CellAnalogRecord->prev = NULL;
  pNode_for_CellAnalogRecord->next = NULL;
}
