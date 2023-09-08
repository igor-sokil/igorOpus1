CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_13SingleValueWithIndexCROBLatchOn

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUWriting_13SingleValueWithIndexCROBLatchOn.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


