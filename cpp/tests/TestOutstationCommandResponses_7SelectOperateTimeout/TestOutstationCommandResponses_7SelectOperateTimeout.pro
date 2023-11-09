CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestOutstationCommandResponses_7SelectOperateTimeout

QT += widgets


HEADERS       = ..\..\..\qtsrc\key_filter.h \
                ..\..\..\qtsrc\MainWindow.h 

LIBS += "D:\MRZV_HOME\Xtended\dnp3\CODE_opendnp3-mrzs\opendnp3-mrzs\dll\libqt_dnp3.a"

include(../../../include_tests.pri)

SOURCES      += MainWindow.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


