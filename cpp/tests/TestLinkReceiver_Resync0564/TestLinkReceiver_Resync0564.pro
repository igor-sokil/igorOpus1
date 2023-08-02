CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestLinkReceiver_Resync0564

QT += widgets

INCLUDEPATH  += .
INCLUDEPATH  += ..\..\..\cpp\tests\dnp3mocks\include\dnp3mocks

include(TestLinkReceiver_Resync0564.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

#SOURCES      += __ICollection.cpp 


#SOURCES      += logEntry_EvenLists.cpp \
#                logEntry_List_for_EventRecord.cpp

DESTDIR = d:\QT_5.12\Examples\release_programs


