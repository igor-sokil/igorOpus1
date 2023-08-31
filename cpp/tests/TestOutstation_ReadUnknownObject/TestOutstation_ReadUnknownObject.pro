CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestOutstation_ReadUnknownObject

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestOutstation_ReadUnknownObject.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


