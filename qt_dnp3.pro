CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = qt_dnp3

QT += widgets

include(qt_dnp3.pri)

SOURCES      += qtsrc\MainWindow.cpp \
                qtsrc\loghandler.cpp \
                qtsrc\main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


#                cpp\lib\src\app\parsing\APDUParser.cpp \
