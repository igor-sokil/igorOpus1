CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_14SingleValueWithIndexCROBLatchOff

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUWriting_14SingleValueWithIndexCROBLatchOff.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


