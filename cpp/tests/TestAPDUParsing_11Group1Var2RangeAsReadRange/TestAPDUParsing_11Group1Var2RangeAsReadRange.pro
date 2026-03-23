CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_11Group1Var2RangeAsReadRange

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUParsing_11Group1Var2RangeAsReadRange.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


