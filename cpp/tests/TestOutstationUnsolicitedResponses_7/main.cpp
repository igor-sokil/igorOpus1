
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
#include "APDUHexBuilders.h"
#include "DatabaseHelpers.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void apply_in_7UnsolNumRetries(IUpdateHandler*);
void apply_in_7UnsolNumRetries(IUpdateHandler* db)
{
    std::cout << "apply_in_7UnsolNumRetries" <<'\n';
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true), 0); });
//void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
 Binary bBinary;
 Binary_in_BinaryOver2(&bBinary, true);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
 Update_Binary_in_IUpdateHandler(db, &bBinary, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);


qDebug()<<"********SUITE('7UnsolNumRetries')********";
qDebug()<<"{------------1";
////    OutstationConfig cfg;
////    cfg.params.allowUnsolicited = true;
////    cfg.params.unsolConfirmTimeout = TimeDuration::Seconds(5);
////    cfg.params.numUnsolRetries = NumRetries::Fixed(3);
////    cfg.params.unsolClassMask = ClassField::AllEventClasses();
////    cfg.eventBufferConfig = EventBufferConfig::AllTypes(5);
////    auto database = configure::by_count_of::binary_input(1);
////    OutstationTestObject t(cfg, std::move(database));
////    t.LowerLayerUp();
////    // Confirm the unsolicited NULL response
///    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)));

    OutstationConfig cfg;
    OutstationConfig_in_OutstationConfig(&cfg);

////    cfg.params.allowUnsolicited = true;
    cfg.params.allowUnsolicited = true;

////    config.params.unsolConfirmTimeout = TimeDuration::Seconds(5);
    cfg.params.unsolConfirmTimeout = Seconds_in_TimeDuration_static(5);

//NumRetries Fixed_in_NumRetries_static(uint16_t maxNumRetries);
////    cfg.params.numUnsolRetries = NumRetries::Fixed(3);
    cfg.params.numUnsolRetries = Fixed_in_NumRetries_static(3);

//ClassField  AllEventClasses_in_ClassField_static(void);
////    cfg.params.unsolClassMask = ClassField::AllEventClasses();
    cfg.params.unsolClassMask = AllEventClasses_in_ClassField_static();

//EventBufferConfig AllTypes_in_EventBufferConfig_static(uint16_t sizes);
////    cfg.eventBufferConfig = EventBufferConfig::AllTypes(5);
    cfg.eventBufferConfig = AllTypes_in_EventBufferConfig_static(5);

////    auto database = configure::by_count_of::binary_input(1);
    DatabaseConfig database = binary_input_in_DatabaseHelpers(1);

////    OutstationTestObject t(cfg, std::move(database));

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &cfg, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

///    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)));
 IINField iIINField;
 IINField_in_IINFieldOver2(&iIINField, IINBit_DEVICE_RESTART);
 std::string respond = NullUnsolicited_in_APDUHexBuilders(0, &iIINField);// = opendnp3::IINField(opendnp3::IINBit::DEVICE_RESTART));

    std::string temp1 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}------------1";

std::cout << "respond= " << respond<<'\n';
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)))";
std::cout << "temp1= " << temp1<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

qDebug()<<"{------------2";
////    t.SendToOutstation(hex::UnsolConfirm(0));
////    // Generate an event
////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true), 0); });
////    // Check original unsolicited response, followed by the 3 retries
///// Проверяем исходный незапрошенный ответ, а затем делаем 3 повторные попытки
////    for (unsigned int i = 0; i <= 3; ++i)
////    {
////        REQUIRE(t.NumPendingTimers() == 1); // confirm timer Число ожидающих таймеров
////        REQUIRE(t.AdvanceTime(TimeDuration::Seconds(5)));
////        REQUIRE(t.lower->PopWriteAsHex() == "F1 82 80 00 02 01 28 01 00 00 00 81");
////        t.OnTxReady();
////    }

////    t.SendToOutstation(hex::UnsolConfirm(0));
std::string unconstr2 = UnsolConfirm_in_APDUHexBuilders(0);
    SendToOutstation_in_OutstationTestObject(&t, unconstr2);  

////    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true), 0); });
    Transaction_in_OutstationTestObject(&t, apply_in_7UnsolNumRetries);//void (*apply)(IUpdateHandler*));

////    // Check original unsolicited response, followed by the 3 retries
///// Проверяем исходный незапрошенный ответ, а затем делаем 3 повторные попытки
////    for (unsigned int i = 0; i <= 3; ++i)
////    {
////        REQUIRE(t.NumPendingTimers() == 1); // confirm timer Число ожидающих таймеров
//uint16_t NumPendingTimers_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject);
     uint16_t num2 = NumPendingTimers_in_OutstationTestObject(&t);
qDebug()<<"}------------2";

qDebug()<<"REQUIRE(t.NumPendingTimers() == 1)";
std::cout << "num2= " << num2<<'\n';
std::cout << "unconstr2= " << unconstr2<<'\n';

////        REQUIRE(t.AdvanceTime(TimeDuration::Seconds(5)));
    TimeDuration ttmp3 = Seconds_in_TimeDuration_static(5);
    AdvanceTime_in_OutstationTestObject(&t, &ttmp3);

qDebug()<<"{------------timeout_RestartUnsolConfirmTimer_in_OContext";
  void timeout_RestartUnsolConfirmTimer_in_OContext(void);
  pPointerGlobal1 = &t.context;
  timeout_RestartUnsolConfirmTimer_in_OContext();
qDebug()<<"}------------timeout_RestartUnsolConfirmTimer_in_OContext";

qDebug()<<"{------------3";

////        REQUIRE(t.lower->PopWriteAsHex() == "F1 82 80 00 02 01 28 01 00 00 00 81");
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

qDebug()<<"}------------3";
qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == 'F1 82 80 00 02 01 28 01 00 00 00 81'";
std::cout << "temp3= " << temp3<<'\n';

////    }//for (unsigned int i = 0; i <= 3; ++i)


/*
////    t.SendToOutstation(hex::ClearRestartIIN(0));
std::string clrStr = ClearRestartIIN_in_APDUHexBuilders(0);
std::cout << "clrStr= " << clrStr<<'\n';
    SendToOutstation_in_OutstationTestObject(&t, clrStr);  

////    REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0));
  IINField iIINField2 = Empty_in_IINField_static();
std::string emptyStr = EmptyResponse_in_APDUHexBuilders(0, &iIINField2);// = opendnp3::IINField::Empty());
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
qDebug()<<"}------------2";

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::EmptyResponse(0))";
std::cout << "emptyStr= " << emptyStr<<'\n';
std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

////    // Continue sending unsolicited NULL responses
////    t.AdvanceTime(TimeDuration::Seconds(5));
    TimeDuration ttmp3 = Seconds_in_TimeDuration_static(5);
    AdvanceTime_in_OutstationTestObject(&t, &ttmp3);

qDebug()<<"{------------timeout_RestartUnsolConfirmTimer_in_OContext";
  void timeout_RestartUnsolConfirmTimer_in_OContext(void);
  pPointerGlobal1 = &t.context;
  timeout_RestartUnsolConfirmTimer_in_OContext();
qDebug()<<"}------------timeout_RestartUnsolConfirmTimer_in_OContext";

qDebug()<<"{------------3";
////    // Continue sending unsolicited NULL responses
////    t.AdvanceTime(TimeDuration::Seconds(5));
////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()));
////    REQUIRE(t.NumPendingTimers() == 1);


////    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()));
 IINField iIINField3;
 IINField_in_IINFieldOver1(&iIINField3);
 std::string respond3 = NullUnsolicited_in_APDUHexBuilders(1, &iIINField3);
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

////    REQUIRE(t.NumPendingTimers() == 1);
//uint16_t NumPendingTimers_in_OutstationTestObject(OutstationTestObject *pOutstationTestObject);
uint16_t num3 = NumPendingTimers_in_OutstationTestObject(&t);
qDebug()<<"}------------3";

qDebug()<<"REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(1, IINField()))";
std::cout << "respond3= " << respond3<<'\n';
std::cout << "temp3= " << temp3<<'\n';
qDebug()<<"REQUIRE(t.NumPendingTimers() == 1)";
std::cout << "num3= " << num3<<'\n';
*/
/*
TEST_CASE(SUITE("7UnsolNumRetries"))
{
    OutstationConfig cfg;
    cfg.params.allowUnsolicited = true;
    cfg.params.unsolConfirmTimeout = TimeDuration::Seconds(5);
    cfg.params.numUnsolRetries = NumRetries::Fixed(3);
    cfg.params.unsolClassMask = ClassField::AllEventClasses();
    cfg.eventBufferConfig = EventBufferConfig::AllTypes(5);
    auto database = configure::by_count_of::binary_input(1);
    OutstationTestObject t(cfg, std::move(database));

    t.LowerLayerUp();

    // Confirm the unsolicited NULL response
    REQUIRE(t.lower->PopWriteAsHex() == hex::NullUnsolicited(0, IINField(IINBit::DEVICE_RESTART)));
    t.OnTxReady();
    t.SendToOutstation(hex::UnsolConfirm(0));

    // Generate an event
    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(true), 0); });

    // Check original unsolicited response, followed by the 3 retries
// Проверяем исходный незапрошенный ответ, а затем делаем 3 повторные попытки
    for (unsigned int i = 0; i <= 3; ++i)
    {
        REQUIRE(t.NumPendingTimers() == 1); // confirm timer Число ожидающих таймеров
        REQUIRE(t.AdvanceTime(TimeDuration::Seconds(5)));
        REQUIRE(t.lower->PopWriteAsHex() == "F1 82 80 00 02 01 28 01 00 00 00 81");
        t.OnTxReady();
    }

    // Check that it stops sending stuff
// Проверяем, что он прекратил отправлять данные
    REQUIRE(t.NumPendingTimers() == 0); // no confirm timer
    REQUIRE(t.lower->PopWriteAsHex().empty());

    // Generate another event
    t.Transaction([](IUpdateHandler& db) { db.Update(Binary(false), 0); });

    // Check seq number increment and 3 retries
    for (unsigned int i = 0; i <= 3; ++i)
    {
        REQUIRE(t.NumPendingTimers() == 1); // confirm timer
        REQUIRE(t.AdvanceTime(TimeDuration::Seconds(5)));
        REQUIRE(t.lower->PopWriteAsHex() == "F2 82 80 00 02 01 28 02 00 00 00 81 00 00 01");
        t.OnTxReady();
    }

    // Check that it stops sending stuff
    REQUIRE(t.NumPendingTimers() == 0); // no confirm timer
    REQUIRE(t.lower->PopWriteAsHex().empty());
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

