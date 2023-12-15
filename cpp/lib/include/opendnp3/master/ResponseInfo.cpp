
#include "header.h"
#include "ResponseInfo.h"

void ResponseInfo_in_ResponseInfo(ResponseInfo *pResponseInfo, boolean unsolicited, boolean fir, boolean fin)
{
  pResponseInfo -> unsolicited = unsolicited;
  pResponseInfo -> fir = fir;
  pResponseInfo -> fin = fin;
}
