CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_CountIterator_UInt8_boundary_condition

QT += widgets

include(TestAPDUWriting_CountIterator_UInt8_boundary_condition.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


