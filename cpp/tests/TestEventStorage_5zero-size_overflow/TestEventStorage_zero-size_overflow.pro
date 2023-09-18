CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestEventStorage_zero-size_overflow

QT += widgets

INCLUDEPATH  += ..\..\..\qtsrc

include(TestEventStorage_zero-size_overflow.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


