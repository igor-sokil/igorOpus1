CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_CountWriteIteratorAllowsCountOfZero

QT += widgets

include(TestAPDUWriting_CountWriteIteratorAllowsCountOfZero.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


