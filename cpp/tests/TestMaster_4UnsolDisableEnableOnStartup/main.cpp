
#include <QApplication>
#include <QtWidgets>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "key_filter.h"

#include "header.h"
#include "MasterTestFixture.h"
#include "APDUHexBuilders.h"

#define UNUSED(x) (void)(x)

key_filter *pkf;

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

qDebug()<<"********SUITE('3SolicitedResponseWithData')********";
////    MasterParams params;
////    MasterTestFixture t(params);
////    t.context->OnLowerLayerUp();
////    REQUIRE(t.exe->run_many() > 0);
    // disable unsol on grp 60 var2, var3, var4
////    REQUIRE(t.lower->PopWriteAsHex()
////            == hex::ClassTask(FunctionCode::DISABLE_UNSOLICITED, 0, ClassField::AllEventClasses()));

    MasterParams params;
    MasterParams_in_MasterParams(&params);
//    params.disableUnsolOnStartup = false;
//    params.unsolClassMask = None_in_ClassField_static();

////    MasterTestFixture t(params);
    MasterTestFixture t;

    Addresses addresses;
    Addresses_in_AddressesOver2(&addresses, 1, 1024);
    MasterTestFixture_in_MasterTestFixture(&t,
                      &params,
                      addresses,//& = opendnp3::Addresses(1, 1024),
                      //const std::string& id = "test",
                      //const std::shared_ptr<opendnp3::ILogHandler>& log = nullptr,
                      NULL,//MockExecutor* executor,// = nullptr,
                      NULL);//IMasterScheduler* scheduler);// = nullptr);


////   t.context->OnLowerLayerUp();
 OnLowerLayerUp_in_MContext(t.context);

 MasterSchedulerBackend* pMasterSchedulerBackend = (MasterSchedulerBackend*)getMasterScheduler_in_MasterTestFixture();
 setNumTask_in_MasterSchedulerBackend(pMasterSchedulerBackend, 5);
  CheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);

//ClassField  AllEventClasses_in_ClassField_static(void);
//std::string ClassTask_in_APDUHexBuilders(FunctionCode_uint8_t fc, uint8_t seq, ClassField* field)
////    REQUIRE(t.lower->PopWriteAsHex()
////            == hex::ClassTask(FunctionCode::DISABLE_UNSOLICITED, 0, ClassField::AllEventClasses()));
ClassField ctmp = AllEventClasses_in_ClassField_static();
inspect_ClassField(&ctmp);

std::string stmp = ClassTask_in_APDUHexBuilders(FunctionCode_DISABLE_UNSOLICITED, 0, &ctmp);
std::cout << "stmp= " << stmp<<'\n';

std::string  popstr = PopWriteAsHex_in_MockLowerLayer(&t.lower);
std::cout << "popstr= " << popstr<<'\n';

////    t.context->OnTxReady();
////    t.SendToMaster(hex::EmptyResponse(0));
////    t.exe->run_many();
////    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(1));

//boolean OnTxReady_in_MContext(MContext *pMContext);
////    t.context->OnTxReady();
 OnTxReady_in_MContext(t.context);

////    t.SendToMaster(hex::EmptyResponse(0));
  IINField iIINField2 = Empty_in_IINField_static();
std::string emptyStr = EmptyResponse_in_APDUHexBuilders(0, &iIINField2);// = opendnp3::IINField::Empty());

std::cout << "----SendToMaster_in_MasterTestFixture" <<'\n';
 SendToMaster_in_MasterTestFixture(&t, emptyStr);
std::cout << "emptyStr= " << emptyStr<<'\n';

////    t.exe->run_many();
 setNumTask_in_MasterSchedulerBackend(pMasterSchedulerBackend, 2);
 t.context->activeTask = NULL;
 CheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);

     ctmp = AllClasses_in_ClassField_static();
    inspect_ClassField(&ctmp);
 stmp = IntegrityPoll_in_APDUHexBuilders(1, &ctmp);// = opendnp3::ClassField::AllClasses());
std::cout << "stmp= " << stmp<<'\n';

////    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(1));
  popstr = PopWriteAsHex_in_MockLowerLayer(&t.lower);
std::cout << "popstr= " << popstr<<'\n';

/*
TEST_CASE(SUITE("4UnsolDisableEnableOnStartup"))
{
    MasterParams params;
    MasterTestFixture t(params);
    t.context->OnLowerLayerUp();

    REQUIRE(t.exe->run_many() > 0);

    // disable unsol on grp 60 var2, var3, var4
    REQUIRE(t.lower->PopWriteAsHex()
            == hex::ClassTask(FunctionCode::DISABLE_UNSOLICITED, 0, ClassField::AllEventClasses()));
    t.context->OnTxReady();
    t.SendToMaster(hex::EmptyResponse(0));

    t.exe->run_many();

    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(1));
    t.context->OnTxReady();
    t.SendToMaster(hex::EmptyResponse(1));

    t.exe->run_many();

    REQUIRE(t.lower->PopWriteAsHex()
            == hex::ClassTask(FunctionCode::ENABLE_UNSOLICITED, 2, ClassField::AllEventClasses()));
    t.context->OnTxReady();
    t.SendToMaster(hex::EmptyResponse(2));

    t.exe->run_many();

    REQUIRE(t.exe->num_pending_timers() == 1);
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

