CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestEventStorage_7selected

QT += widgets

INCLUDEPATH  += ..\..\..\qtsrc

include(TestEventStorage_7selected.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


