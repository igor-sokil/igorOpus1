CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestOutstation_4ColdRestart

QT += widgets

INCLUDEPATH  += ..\..\..\qtsrc

include(TestOutstation_4ColdRestart.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


