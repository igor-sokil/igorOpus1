
#include "header.h"
#include "ResponseInfo.h"

 void ResponseInfo_In_ResponseInfo(ResponseInfo *pResponseInfo, bool unsolicited, bool fir, bool fin)
{
  pResponseInfo -> unsolicited = unsolicited;
  pResponseInfo -> fir = fir;
  pResponseInfo -> fin = fin;
}
