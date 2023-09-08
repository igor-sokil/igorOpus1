CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_4RangeIterator

QT += widgets


INCLUDEPATH  += ..\..\..\qtsrc

include(TestAPDUWriting_4RangeIterator.pri)

SOURCES      += MainWindow.cpp \
                ..\..\..\qtsrc\loghandler.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


