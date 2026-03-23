CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestStaticDataMap_2can

QT += widgets


HEADERS       = ..\..\..\qtsrc\key_filter.h \
                ..\..\..\qtsrc\MainWindow.h 

#INCLUDEPATH += D:\PYTHON_HOME\PYTHON_39\include
#DEPENDPATH  += D:\PYTHON_HOME\PYTHON_39\include
#LIBS += -LD:\PYTHON_HOME\PYTHON_39\libs -lpython39
#LIBS += "D:\PYTHON_HOME\PYTHON_39\libs\python39.a"

LIBS += "D:\MRZV_HOME\Xtended\dnp3\CODE_opendnp3-mrzs\opendnp3-mrzs\dll\libqt_dnp3.a"


include(../../../include_tests.pri)

SOURCES      += MainWindow.cpp \
                main.cpp 


DESTDIR = d:\QT_5.12\Examples\release_programs


