TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

SOURCES += main.cpp \
    DataReaderFromXML.cpp \
    DataReader.cpp \
    DataSaver.cpp \
    DataSaverToXML.cpp \
    PrimeNumbers.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    definitions.h \
    DataReaderFromXML.h \
    DataReader.h \
    DataSaver.h \
    DataSaverToXML.h \
    PrimeNumbers.h

