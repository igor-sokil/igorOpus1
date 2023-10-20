
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "DatabaseHelpers.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

expectsContents_in_CountParser = true;
expectsContents_in_CountIndexParser = true;
expectsContents_in_RangeParser = true;

qDebug()<<"********SUITE('23static')********";
////    OutstationConfig config;

    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//StaticTypeBitField AllTypes_in_StaticTypeBitField_static(void);
////    config.params.typesAllowedInClass0 = StaticTypeBitField::AllTypes();
    config.params.typesAllowedInClass0 = AllTypes_in_StaticTypeBitField_static();

//DatabaseConfig octet_string_in_DatabaseHelpers(uint16_t num);
////    OutstationTestObject t(config, configure::by_count_of::octet_string(2));
DatabaseConfig tmp = octet_string_in_DatabaseHelpers(2);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    OctetString data;
//boolean Set_in_OctetDataOver2(OctetData *pOctetData,  char* input);
////    REQUIRE(data.Set("a"));
boolean btmp = Set_in_OctetDataOver2(&(data.oOctetData),  (char*) "a");
qDebug()<<"REQUIRE(data.Set('a'))";
std::cout << "btmp= " << btmp<<'\n';

//IUpdateHandler* GetUpdateHandler_in_OContext(OContext *pOContext);
//boolean Update_OctetString_in_IUpdateHandler(IUpdateHandler*, OctetString* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////    REQUIRE(t.context.GetUpdateHandler().Update(data, 0));
IUpdateHandler* itmp = GetUpdateHandler_in_OContext(&(t.context));
btmp = Update_OctetString_in_IUpdateHandler(itmp, &data, 0, EventMode_Detect);// = EventMode::Detect) = 0;
qDebug()<<"REQUIRE(t.context.GetUpdateHandler().Update(data, 0))";
std::cout << "btmp= " << btmp<<'\n';

////    REQUIRE(data.Set("bb"));
 btmp = Set_in_OctetDataOver2(&(data.oOctetData),  (char*) "bb");
qDebug()<<"REQUIRE(data.Set('bb'))";
std::cout << "btmp= " << btmp<<'\n';

////    REQUIRE(t.context.GetUpdateHandler().Update(data, 1));
//IUpdateHandler* itmp = GetUpdateHandler_in_OContext(&(t.context));
btmp = Update_OctetString_in_IUpdateHandler(itmp, &data, 1, EventMode_Detect);// = EventMode::Detect) = 0;
qDebug()<<"REQUIRE(t.context.GetUpdateHandler().Update(data, 1))";
std::cout << "btmp= " << btmp<<'\n';

    LowerLayerUp_in_OutstationTestObject(&t);

    std::string name("C0 01 3C 01 06");       
    SendToOutstation_in_OutstationTestObject(&t, name);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 6E 01 00 00 00 61 6E 02 00 01 01 62 62')";
std::cout << "temp= " << temp<<'\n';

/*
TEST_CASE(SUITE("23static octet strings switch headers if length differs"))
{
    OutstationConfig config;
    config.params.typesAllowedInClass0 = StaticTypeBitField::AllTypes();
    OutstationTestObject t(config, configure::by_count_of::octet_string(2));

    OctetString data;
    REQUIRE(data.Set("a"));
    REQUIRE(t.context.GetUpdateHandler().Update(data, 0));
    REQUIRE(data.Set("bb"));
    REQUIRE(t.context.GetUpdateHandler().Update(data, 1));

    t.LowerLayerUp();
    t.SendToOutstation("C0 01 3C 01 06"); // Read class 0

    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00 6E 01 00 00 00 61 6E 02 00 01 01 62 62");
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

