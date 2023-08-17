CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestCollectionTransform_MapIntegers2Booleans

QT += widgets

INCLUDEPATH  += .
INCLUDEPATH  += ..\..\..\cpp\tests\dnp3mocks\include\dnp3mocks

include(TestCollectionTransform_MapIntegers2Booleans.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

#SOURCES      += __ICollection.cpp 

#SOURCES      += __List_for_EventRecord_part1.cpp \
#                __HasLength.cpp \
#                __EventStorage.cpp \
#                __EventLists.cpp \
#                __EventBufferConfig.cpp \
#                __ClazzCount.cpp \
#                __Array__for__Node_for_EventRecord.cpp

#SOURCES      += logEntry_EvenLists.cpp \
#                logEntry_List_for_EventRecord.cpp

DESTDIR = d:\QT_5.12\Examples\release_programs


