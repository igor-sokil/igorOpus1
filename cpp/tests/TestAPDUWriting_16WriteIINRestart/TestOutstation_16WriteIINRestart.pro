CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestOutstation_16WriteIINRestart

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestOutstation_16WriteIINRestart.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


