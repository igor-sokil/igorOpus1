CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_PrefixWriteIteratorCTO

QT += widgets

include(TestAPDUWriting_PrefixWriteIteratorCTO.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


