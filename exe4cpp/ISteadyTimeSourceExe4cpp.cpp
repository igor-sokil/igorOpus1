#include "header.h"
#include "ISteadyTimeSourceExe4cpp.h"

uint64_t Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *pISteadyTimeSourceExe4cpp)
{
  return (pISteadyTimeSourceExe4cpp->pGet_time_in_ISteadyTimeSourceExe4cpp)(pISteadyTimeSourceExe4cpp);
}


void* getParentPointer_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp* pISteadyTimeSourceExe4cpp)
{
  return pISteadyTimeSourceExe4cpp->pParentPointer_in_ISteadyTimeSourceExe4cpp;
}

void  setParentPointer_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp* pISteadyTimeSourceExe4cpp, void* pParentPointer)
{
  pISteadyTimeSourceExe4cpp->pParentPointer_in_ISteadyTimeSourceExe4cpp = pParentPointer;
}
