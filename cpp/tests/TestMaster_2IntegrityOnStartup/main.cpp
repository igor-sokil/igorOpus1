
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

qDebug()<<"********SUITE('2IntegrityOnStartup')********";
////    MasterParams params;
////    params.disableUnsolOnStartup = false;
////    MasterTestFixture t(params);
////    t.context->OnLowerLayerUp();
////    REQUIRE(t.exe->run_many() > 0);
////    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(0));

    MasterParams params;
    MasterParams_in_MasterParams(&params);
    params.disableUnsolOnStartup = false;

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
 setNumTask_in_MasterSchedulerBackend(pMasterSchedulerBackend, 2);
 CheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);

////    REQUIRE(t.exe->run_many() > 0);
////    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(0));
    ClassField  ctmp = AllClasses_in_ClassField_static();
    inspect_ClassField(&ctmp);
std::string stmp = IntegrityPoll_in_APDUHexBuilders(0, &ctmp);// = opendnp3::ClassField::AllClasses());
std::cout << "stmp= " << stmp<<'\n';

////    REQUIRE(t.exe->run_many() > 0);
////    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(0));
std::string  popstr = PopWriteAsHex_in_MockLowerLayer(&t.lower);
std::cout << "popstr= " << popstr<<'\n';

/*
////    REQUIRE(t.application->stateChanges.size() == 1);
   btemp = t.application.stateChanges.size();
  qDebug()<<"-----REQUIRE(t.application->stateChanges.size() == 1)";
  std::cout<<"boolean btemp= "<<btemp<<std::endl;

////    REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::OPEN);
  uint8_t dtemp = t.application.stateChanges.front();
  qDebug()<<"-----REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::OPEN))";
  std::cout<<"State_in_MockMasterApplication_OPEN= "<<State_in_MockMasterApplication_OPEN<<std::endl;
  std::cout<<"uint8_t dtemp= "<<(uint16_t)dtemp<<std::endl;

////    t.application->stateChanges.pop_front();
////    t.context->OnLowerLayerDown();
////    REQUIRE(t.application->stateChanges.size() == 1);
////    REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::CLOSED);
////    t.application->stateChanges.pop_front();

////    t.application->stateChanges.pop_front();
   t.application.stateChanges.pop_front();

////   t.context->OnLowerLayerDown();
 OnLowerLayerDown_in_MContext(t.context);

////    REQUIRE(t.application->stateChanges.size() == 1);
   btemp = t.application.stateChanges.size();
  qDebug()<<"-----REQUIRE(t.application->stateChanges.size() == 1)";
  std::cout<<"boolean btemp= "<<btemp<<std::endl;

////    REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::CLOSED);
  dtemp = t.application.stateChanges.front();
  qDebug()<<"-----REQUIRE(t.application->stateChanges.front() == MockMasterApplication::State::CLOSED))";
  std::cout<<"State_in_MockMasterApplication_CLOSED= "<<State_in_MockMasterApplication_CLOSED<<std::endl;
  std::cout<<"uint8_t dtemp= "<<(uint16_t)dtemp<<std::endl;
*/
/*
TEST_CASE(SUITE("2IntegrityOnStartup"))
{
    MasterParams params;
    params.disableUnsolOnStartup = false;
    MasterTestFixture t(params);
    t.context->OnLowerLayerUp();

    REQUIRE(t.exe->run_many() > 0);

    REQUIRE(t.lower->PopWriteAsHex() == hex::IntegrityPoll(0));
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

