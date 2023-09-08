CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestControlRelayOutputBlock_4From

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestControlRelayOutputBlock_4From.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


