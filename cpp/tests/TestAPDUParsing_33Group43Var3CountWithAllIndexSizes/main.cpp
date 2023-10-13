
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
#include "BufferHelpers.h"
//#include "loghandler.h"
#include "MockAPDUHeaderHandler.h"
#include "HexConversions.h"
#include "APDUParser.h"

#include "TestAPDUParsing.h"

#define UNUSED(x) (void)(x)


key_filter *pkf;

MainWindow *mainWindow;

void validate(MockApduHeaderHandler*);
void validate(MockApduHeaderHandler* mock)
{
qDebug()<<"REQUIRE(1 == mock.analogCommandEvents.size())";
 uint16_t size = mock->analogCommandEvents.size();
qDebug()<<"uint16_t size ="<<size;
  if(size!=1) return;
/*
{

qDebug()<<"";
qDebug()<<"Indexed<DoubleBitBinary> event1(DoubleBitBinary(DoubleBit::INDETERMINATE, Flags(0x01), DNPTime(7)), 3)";
qDebug()<<"REQUIRE((event1 == mock.eventDoubleBinaries[0]))";

Indexed_for_DoubleBitBinary value = mock->eventDoubleBinaries[0];
qDebug()<<"value.index= "<<value.index;

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 0x01);

 DNPTime dDNPTime;
 DNPTime_in_DNPTimeOver2(&dDNPTime, 7);

 DoubleBitBinary dDoubleBitBinary;
 DoubleBitBinary_in_DoubleBitBinaryOver6(&dDoubleBitBinary, DoubleBit_INDETERMINATE, fFlags, dDNPTime);

qDebug()<<"value.tTypedMeasurement_for_DoubleBit_uint8_t.value== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.value ->"<<(
                                      value.value.tTypedMeasurement_for_DoubleBit_uint8_t.value== 
                                 dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.value);

qDebug()<<"value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags ->"<<(
                                    value.value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags.value== 
                               dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags.value);
qDebug()<<"value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value ->"<<(value.value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value);

}
{
qDebug()<<"";
qDebug()<<"Indexed<DoubleBitBinary> event2(DoubleBitBinary(DoubleBit::DETERMINED_OFF, Flags(0x01), DNPTime(9)), 5)";
qDebug()<<"REQUIRE((event2 == mock.eventDoubleBinaries[1]))";

Indexed_for_DoubleBitBinary value = mock->eventDoubleBinaries[1];
qDebug()<<"value.index= "<<value.index;

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 0x01);

 DNPTime dDNPTime;
 DNPTime_in_DNPTimeOver2(&dDNPTime, 9);

 DoubleBitBinary dDoubleBitBinary;
 DoubleBitBinary_in_DoubleBitBinaryOver6(&dDoubleBitBinary, DoubleBit_DETERMINED_OFF, fFlags, dDNPTime);

qDebug()<<"value.tTypedMeasurement_for_DoubleBit_uint8_t.value== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.value ->"<<(
                                      value.value.tTypedMeasurement_for_DoubleBit_uint8_t.value== 
                                 dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.value);

qDebug()<<"value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags ->"<<(
                                    value.value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags.value== 
                               dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.flags.value);
qDebug()<<"value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value ->"<<(value.value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value== dDoubleBitBinary.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value);

}
*/
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  key_filter kf;
  app.installEventFilter(pkf=&kf);

expectsContents_in_CountIndexParser = true;
expectsContents_in_RangeParser = true;

qDebug()<<"********SUITE('33Group43Var3CountWithAllIndexSizes')********";
void validate(MockApduHeaderHandler*);
{
  std::string name("2B 03 17 01 09 01 32 00 00 00 88 6E D0 92 4A 01");       
ParseResult_uint8_t temp = TestComplex(name, validate);
qDebug()<<"TestComplex('2B 03 17 01 09 01 32 00 00 00 88 6E D0 92 4A 01', ParseResult::OK, 1, [](MockApduHeaderHandler& mock)";
qDebug()<<"ParseResult_uint8_t result= "<<temp;
}
{
  std::string name("2B 03 28 01 00 09 00 01 32 00 00 00 88 6E D0 92 4A 01");       
ParseResult_uint8_t temp = TestComplex(name, validate);
qDebug()<<"TestComplex('2B 03 28 01 00 09 00 01 32 00 00 00 88 6E D0 92 4A 01', ParseResult::OK, 1, [](MockApduHeaderHandler& mock)";
qDebug()<<"ParseResult_uint8_t result= "<<temp;
}

/*
TEST_CASE(SUITE("33Group43Var3CountWithAllIndexSizes"))
{
    auto validator = [](MockApduHeaderHandler& mock) {
        REQUIRE(1 == mock.analogCommandEvents.size());
        Indexed<AnalogCommandEvent> value(AnalogCommandEvent(50, CommandStatus::TIMEOUT, DNPTime(1419802341000)), 9);
        REQUIRE((value == mock.analogCommandEvents[0]));
    };

    // 1 byte count, 1 byte index, index == 09, status = 0x01, value = 0x32, time = 1419802341000 (014A92D06E88 in hex /
    // 886ED0924A01 little endian)
    TestComplex("2B 03 17 01 09 01 32 00 00 00 88 6E D0 92 4A 01", ParseResult::OK, 1, validator);
    TestComplex("2B 03 28 01 00 09 00 01 32 00 00 00 88 6E D0 92 4A 01", ParseResult::OK, 1, validator);
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

