CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestControlRelayOutputBlock_2From

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestControlRelayOutputBlock_2From.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


