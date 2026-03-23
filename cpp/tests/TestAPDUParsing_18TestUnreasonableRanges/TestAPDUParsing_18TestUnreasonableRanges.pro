CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_18TestUnreasonableRanges

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUParsing_18TestUnreasonableRanges.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


