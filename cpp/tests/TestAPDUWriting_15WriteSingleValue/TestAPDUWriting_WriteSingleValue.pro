CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_WriteSingleValue

QT += widgets

include(TestAPDUWriting_WriteSingleValue.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


