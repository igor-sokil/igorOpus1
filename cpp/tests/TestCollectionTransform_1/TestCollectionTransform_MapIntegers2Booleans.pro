CONFIG	    += console 
CONFIG	    += release

TEMPLATE      = app

TARGET = TestCollectionTransform_MapIntegers2Booleans

QT += widgets


HEADERS       = ..\..\..\qtsrc\key_filter.h \
                ..\..\..\qtsrc\MainWindow.h 

HEADERS       += ICollection.h \
                 Collections.h

LIBS += "D:\MRZV_HOME\Xtended\dnp3\CODE_opendnp3-mrzs\opendnp3-mrzs\dll\libqt_dnp3.a"

include(../../../include_tests.pri)

SOURCES      += MainWindow.cpp \
                main.cpp 

#                \
#                onAPDUPacket.cpp \
#                onLinkLayerPacket.cpp \
#                onReadInputPacketLinkLayer.cpp \
#                onReadInputPacketAPDU.cpp \
#                constructorLinkLayer.cpp \
#                constructorAPDU.cpp 

#                \
#                txtLogEntry.cpp

#    onReadInputPacketEx.cpp \

DESTDIR = d:\QT_5.12\Examples\release_programs


