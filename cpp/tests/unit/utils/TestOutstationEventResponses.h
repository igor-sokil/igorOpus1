#include <QApplication>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "header.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "DatabaseHelpers.h"

void TestEventRead(std::string& request,
                   std::string& response,
                   ////const std::function<void(IUpdateHandler& db)>& loadFun,
                   void (*loadFun)(IUpdateHandler* db),
                   ////const std::function<void(DatabaseConfig& db)>& configure = [](DatabaseConfig& view) {})
                   void (*configure)(DatabaseConfig* view));
