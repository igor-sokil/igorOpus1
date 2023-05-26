CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_EmptyHeadersWhenNotEnoughSpaceForSingleValue

QT += widgets

include(TestAPDUWriting_EmptyHeadersWhenNotEnoughSpaceForSingleValue.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


