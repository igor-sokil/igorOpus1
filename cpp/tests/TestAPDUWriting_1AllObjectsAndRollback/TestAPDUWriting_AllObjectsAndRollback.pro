CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestAPDUWriting_AllObjectsAndRollback

INCLUDEPATH  += .
INCLUDEPATH  += ..\..\..\cpp\tests\dnp3mocks\include\dnp3mocks

QT += widgets

include(TestAPDUWriting_AllObjectsAndRollback.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

DESTDIR = d:\QT_5.12\Examples\release_programs


