//#include <QtWidgets>
#include "header.h"
#include "ISteadyTimeSourceExe4cpp.h"

void ISteadyTimeSourceExe4cpp_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *pISteadyTimeSourceExe4cpp)
{
//qDebug()<<"ISteadyTimeSourceExe4cpp_in_ISteadyTimeSourceExe4cpp1= "<<(uint32_t)Get_time_in_ISteadyTimeSourceExe4cpp_override;
 pISteadyTimeSourceExe4cpp->pGet_time_in_ISteadyTimeSourceExe4cpp = Get_time_in_ISteadyTimeSourceExe4cpp_override;
}

uint64_t Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *pISteadyTimeSourceExe4cpp)
{
//qDebug()<<"pISteadyTimeSourceExe4cpp->pGet_time_in_ISteadyTimeSourceExe4cpp= "<<(uint32_t)pISteadyTimeSourceExe4cpp->pGet_time_in_ISteadyTimeSourceExe4cpp;
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
