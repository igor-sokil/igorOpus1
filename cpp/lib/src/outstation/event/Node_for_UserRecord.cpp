#include "header.h"
#include "Node_for_UserRecord.h"

#include <string.h>

void Node_for_UserRecord_in_Node_for_UserRecord(Node_for_UserRecord *pNode_for_UserRecord)
{
  UserRecord_in_UserRecord(&(pNode_for_UserRecord->value));
  pNode_for_UserRecord->prev = NULL;
  pNode_for_UserRecord->next = NULL;
}
