CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestOutstation_12DelayMeasureExtraData

QT += widgets

INCLUDEPATH  += ..\..\..\qtsrc

include(TestOutstation_12DelayMeasureExtraData.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


