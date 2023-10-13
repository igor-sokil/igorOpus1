#CONFIG	    += console 
CONFIG	    += release

#TEMPLATE      = app
TEMPLATE      = lib


TARGET = qt_dnp3

QT += widgets

include(include_dnp3.pri)
include(qt_dnp3.pri)

#SOURCES      += qtsrc\MainWindow.cpp \
#                qtsrc\loghandler.cpp \
#                qtsrc\main.cpp 
SOURCES      += qtsrc\loghandler.cpp

#DESTDIR = d:\QT_5.12\Examples\release_programs
DESTDIR = .\dll


#                cpp\lib\src\app\parsing\APDUParser.cpp \
