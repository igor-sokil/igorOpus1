CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUParsing_HeaderParsesResponse

QT += widgets

include(TestAPDUParsing_HeaderParsesResponse.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


#                cpp\lib\src\app\parsing\APDUParser.cpp \
