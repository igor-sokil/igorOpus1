CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestLinkFrame_ConfirmedUserData

QT += widgets

INCLUDEPATH  += .
INCLUDEPATH  += ..\..\..\cpp\tests\dnp3mocks\include\dnp3mocks

include(TestLinkFrame_ConfirmedUserData.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

#SOURCES      += __ICollection.cpp 


#SOURCES      += logEntry_EvenLists.cpp \
#                logEntry_List_for_EventRecord.cpp

DESTDIR = d:\QT_5.12\Examples\release_programs


