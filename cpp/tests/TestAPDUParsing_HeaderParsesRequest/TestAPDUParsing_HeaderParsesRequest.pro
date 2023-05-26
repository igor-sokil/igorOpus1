CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_HeaderParsesRequest

QT += widgets

include(TestAPDUParsing_HeaderParsesRequest.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


#                cpp\lib\src\app\parsing\APDUParser.cpp \
