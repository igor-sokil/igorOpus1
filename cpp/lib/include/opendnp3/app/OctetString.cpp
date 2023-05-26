#include "header.h"
#include "OctetString.h"

   void OctetString_in_OctetStringOver1(OctetString *pOctetString)
{
//// : OctetData() {}
  OctetData_in_OctetDataOver1(&(pOctetString->oOctetData));
}

   void OctetString_in_OctetStringOver2(OctetString *pOctetString, char* input)
{
//// : OctetData(input) {}
    OctetData_in_OctetDataOver2(&(pOctetString->oOctetData), input);
}

   void OctetString_in_OctetStringOver3(OctetString *pOctetString, Buffer *buffer)
{
//// : OctetData(buffer) {}
    OctetData_in_OctetDataOver3(&(pOctetString->oOctetData), buffer);
}
