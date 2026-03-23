CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_15Group1Var2Range16

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUParsing_15Group1Var2Range16.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


