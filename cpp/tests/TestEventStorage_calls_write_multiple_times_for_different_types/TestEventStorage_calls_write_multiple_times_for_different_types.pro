CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestEventStorage_calls_write_multiple_times_for_different_types

QT += widgets

include(TestEventStorage_calls_write_multiple_times_for_different_types.pri)

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

#SOURCES      += logEntry_EvenLists.cpp \
#                logEntry_List_for_EventRecord.cpp

DESTDIR = d:\QT_5.12\Examples\release_programs

