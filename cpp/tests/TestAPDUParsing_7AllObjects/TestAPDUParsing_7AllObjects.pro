CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_7AllObjects

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUParsing_7AllObjects.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


