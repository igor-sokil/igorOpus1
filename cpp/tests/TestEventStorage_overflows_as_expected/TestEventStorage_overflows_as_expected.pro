CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestEventStorage_overflows_as_expected

QT += widgets

include(TestEventStorage_overflows_as_expected.pri)

SOURCES      += MainWindow.cpp \
                loghandler.cpp \
                main.cpp 

#SOURCES      += __List_for_EventRecord_part1.cpp \
#                __HasLength.cpp \
#                __EventStorage.cpp \
#                __EventLists.cpp \
#                __EventBufferConfig.cpp \
#                __ClazzCount.cpp \
#                __Array__for__Node_for_EventRecord.cpp

#SOURCES      += __EventUpdate.cpp \

#SOURCES      += __EventLists.cpp \
#                __EventStorage.cpp \
#                __List_TypedEventRecord_for_AnalogSpec_part1.cpp 

#SOURCES      += logEntry_EvenLists.cpp \
#                logEntry_List_TypedEventRecord_for_AnalogSpec.cpp

DESTDIR = d:\QT_5.12\Examples\release_programs


