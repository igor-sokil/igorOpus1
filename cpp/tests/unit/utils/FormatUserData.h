
#include "CRC.h"
#include "LinkFrame.h"
#include "LinkHeader.h"

#include "WSeq.h"
#include <string.h>

std::string FormatUserDataStr(
  boolean aIsMaster, boolean aIsConfirmed, int aDest, int aSrc, std::string& data, boolean aFcb);/// = false)
