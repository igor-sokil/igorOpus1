CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = dnp_experiment1

QT += widgets

include(dnp_experiment1.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


#                cpp\lib\src\app\parsing\APDUParser.cpp \
