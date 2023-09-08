CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_AllObjectsReturnsFalseWhenFull

QT += widgets

include(TestAPDUWriting_AllObjectsReturnsFalseWhenFull.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


