#include "header.h"
#include "IINValue.h"

  void IINValue_in_IINValueOver1(IINValue *pIINValue)
{
  pIINValue->value = false;
}


////    IINValue(bool value_) : value(value_) {}
  void IINValue_in_IINValueOver2(IINValue *pIINValue, boolean value_)
{
  pIINValue->value = value_;
}
