CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestLinkFrame_9NotSupported

QT += widgets

INCLUDEPATH  += ..\..\..\qtsrc

include(TestLinkFrame_9NotSupported.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


