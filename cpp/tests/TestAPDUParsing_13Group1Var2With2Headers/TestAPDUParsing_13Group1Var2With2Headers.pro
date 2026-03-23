CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_13Group1Var2With2Headers

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUParsing_13Group1Var2With2Headers.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


