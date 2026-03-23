CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_16Group1Var2AllCountQualifiers

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUParsing_16Group1Var2AllCountQualifiers.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


