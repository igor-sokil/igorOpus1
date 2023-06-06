CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestEventStorage_calls_write_multiple_times_for_different_variations

QT += widgets

include(TestEventStorage_calls_write_multiple_times_for_different_variations.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


