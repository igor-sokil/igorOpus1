
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "HexConversions.h"
#include "APDUHexBuilders.h"

#define UNUSED(x) (void)(x)

void* pPointerGlobal1;
void* pPointerGlobal2;
void* pPointerGlobal3;

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('7WriteIIN')********";
////    OutstationConfig config;
////    OutstationTestObject t(config);
////    t.LowerLayerUp();
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);
//    OutstationTestObject t;
//    OutstationTestObject_in_OutstationTestObject(&t, &config);
    DatabaseConfig tmp;
    DatabaseConfig_in_DatabaseConfig(&tmp, 0);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

////    t.SendToOutstation(hex::ClearRestartIIN(0));
std::string str = ClearRestartIIN_in_APDUHexBuilders(0);
std::cout << "str= " << str<<'\n';

    SendToOutstation_in_OutstationTestObject(&t, str);  

////    REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0));
    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0))";
std::cout << "temp= " << temp<<'\n';

IINField iin = Empty_in_IINField_static();

 str = EmptyResponse_in_APDUHexBuilders(0, &iin);
std::cout << "str= " << str<<'\n';

/*
TEST_CASE(SUITE("7WriteIIN"))
{
    OutstationConfig config;
    OutstationTestObject t(config);
    t.LowerLayerUp();

    t.SendToOutstation(hex::ClearRestartIIN(0));
    REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0));
}
*/
/*
////    OutstationConfig config;
////    OutstationTestObject t(config);
////    t.LowerLayerUp();
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);
//    OutstationTestObject t;
//    OutstationTestObject_in_OutstationTestObject(&t, &config);
    DatabaseConfig tmp;
    DatabaseConfig_in_DatabaseConfig(&tmp, 0);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

    // outstation shouldn't respond to any of these
    std::vector<FunctionCode_uint8_t> codes;
    codes.push_back(FunctionCode_DIRECT_OPERATE_NR);
    codes.push_back(FunctionCode_FREEZE_AT_TIME_NR);
    codes.push_back(FunctionCode_FREEZE_CLEAR_NR);
    codes.push_back(FunctionCode_FREEZE_AT_TIME_NR);

    uint8_t sequence = 0;

    for (auto code : codes)
    {
        uint8_t bytes[2];
//void AppControlField_in_AppControlFieldOver4(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns, uint8_t seq);
////        AppControlField control(true, true, false, false, sequence);
 AppControlField control;
 AppControlField_in_AppControlFieldOver4(&control, true, true, false, false, sequence);

//uint8_t ToByte_in_AppControlField(AppControlField *);
////        bytes[0] = control.ToByte();
        bytes[0] = ToByte_in_AppControlField(&control);

////        bytes[1] = static_cast<uint8_t>(code);
        bytes[1] = (uint8_t)(code);

//std::string to_hex_in_HexConversions(const uint8_t* buffer, size_t length, bool spaced = false);
////        auto request = HexConversions::to_hex(bytes, 2, true);
  std::string  str = to_hex_in_HexConversions(bytes, 2, true);
std::cout << "str= " << str<<'\n';

qDebug()<<"6NoResponseToNoAckCodes1";
////        t.SendToOutstation(request);
    SendToOutstation_in_OutstationTestObject(&t, str);  

qDebug()<<"6NoResponseToNoAckCodes2";

////        REQUIRE(t.lower->PopWriteAsHex().empty());
    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex().empty())";
std::cout << "temp= " << temp<<'\n';

        ++sequence;
    }
*/

  MainWindow mainWindowObj;
  mainWindow = &mainWindowObj;


  mainWindowObj.resize(600, 800);
  mainWindowObj.show();
  return app.exec();
}


key_filter::key_filter(QObject *parent)
  : QObject(parent)
{
}

bool key_filter::eventFilter(QObject *obj, QEvent *event)
{
  UNUSED(obj);

  if(event->type() == QEvent::KeyPress)
  {
    QKeyEvent *ke = static_cast<QKeyEvent*>(event);
    int myKey = ke->key();

    switch(myKey)
    {
    case  Qt::Key_Asterisk:
      emit sig_key_asterisk();
      return true;
    }//switch

    if(ke->modifiers()==Qt::NoModifier)
    switch(myKey)
    {
    case  Qt::Key_1:
      emit sig_key_1();
      return true;
    case  Qt::Key_2:
      emit sig_key_2();
      return true;
    case  Qt::Key_3:
      emit sig_key_3();
      return true;
    case  Qt::Key_4:
      emit sig_key_4();
      return true;

    case  Qt::Key_5:
      emit sig_key_5();
      return true;
    case  Qt::Key_6:
      emit sig_key_6();
      return true;
    case  Qt::Key_7:
      emit sig_key_7();
      return true;
    case  Qt::Key_8:
      emit sig_key_8();
      return true;

    case  Qt::Key_Up:
      emit sig_key_up();
      return true;
    case  Qt::Key_Down:
      emit sig_key_down();
      return true;
    case  Qt::Key_PageDown:
      emit sig_key_pgDown();
      return true;
    case  Qt::Key_PageUp:
      emit sig_key_pgUp();
      return true;
    case  Qt::Key_Left:
      emit sig_key_left();
      return true;
    case  Qt::Key_Right:
      emit sig_key_right();
      return true;
    case  Qt::Key_Home:
      emit sig_key_home();
      return true;
    case  Qt::Key_End:
      emit sig_key_end();
      return true;
    case  Qt::Key_Insert:
      emit sig_key_enter();
      return true;
    case  Qt::Key_Delete:
      emit sig_key_esc();
      return true;
    case  Qt::Key_Escape:
      emit sig_key_esc();
      return true;

    case  Qt::Key_F1:
      emit sig_key_f1();
      return true;
    case  Qt::Key_F2:
      emit sig_key_f2();
      return true;
    case  Qt::Key_F3:
      emit sig_key_f3();
      return true;

    case  Qt::Key_F8:
      emit sig_key_f8();
      return true;
    }//switch

   if(ke->modifiers()!=Qt::ControlModifier) return false;
    switch(myKey)
    {
    case  Qt::Key_1:
      emit sig_ctrlkey(0);
      return true;
    case  Qt::Key_2:
      emit sig_ctrlkey(1);
      return true;
    case  Qt::Key_3:
      emit sig_ctrlkey(2);
      return true;
    case  Qt::Key_4:
      emit sig_ctrlkey(3);
      return true;
    case  Qt::Key_5:
      emit sig_ctrlkey(4);
      return true;
    case  Qt::Key_6:
      emit sig_ctrlkey(5);
      return true;
    case  Qt::Key_7:
      emit sig_ctrlkey(6);
      return true;
    case  Qt::Key_8:
      emit sig_ctrlkey(7);
      return true;
    }//switch

  }
  return false;
}

