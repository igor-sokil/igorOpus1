#include <QApplication>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "header.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "DatabaseHelpers.h"

void TestFreezeOperation(std::string func, 
                        ////std::function<std::string(uint8_t)> freezeResponse,
                         std::string (*freezeResponse)(uint8_t v),
                         boolean clear);
