CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestLinkFrame_7UnconfirmedUserData

QT += widgets

INCLUDEPATH  += ..\..\..\qtsrc

include(TestLinkFrame_7UnconfirmedUserData.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


