CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestOutstation_4NotEnoughData

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestOutstation_4NotEnoughData.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


