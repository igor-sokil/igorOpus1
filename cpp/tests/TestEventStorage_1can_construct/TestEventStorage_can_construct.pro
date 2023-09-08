CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestEventStorage_can_construct

QT += widgets

include(TestEventStorage_can_construct.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


