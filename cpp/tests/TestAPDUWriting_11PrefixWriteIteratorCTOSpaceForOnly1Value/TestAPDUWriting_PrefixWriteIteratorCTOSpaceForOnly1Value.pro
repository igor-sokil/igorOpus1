CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_PrefixWriteIteratorCTOSpaceForOnly1Value

QT += widgets

include(TestAPDUWriting_PrefixWriteIteratorCTOSpaceForOnly1Value.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


