#include  "header.h"
#include  "TimeSyncHandler.h"

void TimeSyncHandler_in_TimeSyncHandler(TimeSyncHandler *pTimeSyncHandler)
{
  pTimeSyncHandler->m_valid = false;
  pTimeSyncHandler->m_time = 0;

  IAPDUHandler_in_IAPDUHandler(&(pTimeSyncHandler->iIAPDUHandler));

  pTimeSyncHandler->iIAPDUHandler.iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_TimeSyncHandler_override;
  pTimeSyncHandler->iIAPDUHandler.pProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler = ProcessHeader_in_TimeSyncHandler_override;
  setParentPointer_in_IAPDUHandler(&(pTimeSyncHandler->iIAPDUHandler), pTimeSyncHandler);
  setParentPointer_in_IWhiteList(&((pTimeSyncHandler->iIAPDUHandler).iIWhiteList), pTimeSyncHandler);
}

boolean GetTimeDelay_in_TimeSyncHandler(TimeSyncHandler *pTimeSyncHandler, uint16_t* time)
{
//boolean Any_in_IINField(IINField *pIINField);
//IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
////        if (this->Errors().Any())
  IINField tmp = Errors_in_IAPDUHandler(&(pTimeSyncHandler->iIAPDUHandler));
  if (Any_in_IINField(&tmp))
  {
    return false;
  }
  else
  {
    if (pTimeSyncHandler->m_valid)
    {
      *time = pTimeSyncHandler->m_time;
    }
    return pTimeSyncHandler->m_valid;
  }
}

boolean IsAllowed_in_TimeSyncHandler(TimeSyncHandler *pTimeSyncHandler, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(qc);
  UNUSED(pTimeSyncHandler);
  return (headerCount == 0) && (gv == GroupVariation_Group52Var2);
}
boolean IsAllowed_in_TimeSyncHandler_override(void *pIAPDUHandler, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  TimeSyncHandler *parent = (TimeSyncHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return IsAllowed_in_TimeSyncHandler(parent, headerCount, gv, qc);
}

IINField ProcessHeader_in_TimeSyncHandler(TimeSyncHandler *pTimeSyncHandler, CountHeader* header, ICollection_for_Group52Var2* times)
{
  UNUSED(header);

  Group52Var2 value;
  Group52Var2_in_Group52Var2(&value);

//boolean ReadOnlyValue_in_ICollection_for_Group52Var2(ICollection_for_Group52Var2 *pICollection_Group52Var2, Group52Var2* pValue)
////        if (times.ReadOnlyValue(value))
  if (ReadOnlyValue_in_ICollection_for_Group52Var2(times, &value))
  {
    pTimeSyncHandler->m_valid = true;
    pTimeSyncHandler->m_time = value.time_uint16_t;
////            return IINField::Empty();
    return Empty_in_IINField_static();
  }
  else
  {
////            return IINBit::PARAM_ERROR;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }
}
IINField ProcessHeader_in_TimeSyncHandler_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var2* times)
{
  TimeSyncHandler *parent = (TimeSyncHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_in_TimeSyncHandler(parent, header, times);
}
