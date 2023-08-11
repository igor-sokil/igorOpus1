#include "header.h"
#include "IClassAssigner.h"

Range AssignClassToAll_in_IClassAssigner(IClassAssigner *pIClassAssigner, AssignClassType_uint8_t type, PointClass_uint8_t clazz)
{
  return (pIClassAssigner->pAssignClassToAll_in_IClassAssigner)(pIClassAssigner, type, clazz);
}

Range AssignClassToRange_in_IClassAssigner(IClassAssigner *pIClassAssigner, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range)
{
  return (pIClassAssigner->pAssignClassToRange_in_IClassAssigner)(pIClassAssigner, type, clazz, range);
}

void* getParentPointer_in_IClassAssigner(IClassAssigner* pIClassAssigner)
{
  return pIClassAssigner->pParentPointer_in_IClassAssigner;
}

void  setParentPointer_in_IClassAssigner(IClassAssigner* pIClassAssigner, void* pParentPointer)
{
  pIClassAssigner->pParentPointer_in_IClassAssigner = pParentPointer;
}
