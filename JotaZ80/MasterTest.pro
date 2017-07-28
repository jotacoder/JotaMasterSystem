QT += core
QT -= gui

CONFIG += c++11

TARGET = MasterTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

win32: LIBS += -L$$PWD/../../googletest/lib/ -lgmock -lgmock_main

INCLUDEPATH += $$PWD/../../googletest/include
DEPENDPATH += $$PWD/../../googletest/include

win32:PRE_TARGETDEPS += $$PWD/../../googletest/lib/libgmock.a
win32:PRE_TARGETDEPS += $$PWD/../../googletest/lib/libgmock_main.a


SOURCES += z80.cpp \
    Memory.cpp \
    MasterSystem.cpp \
    instructions/load8bit.cpp \
    test/test_load8bit.cpp \
    instructions/initialization.cpp \
    test/test_load16bit.cpp \
    instructions/load16bit.cpp \
    test/test_stack.cpp \
    instructions/stack.cpp \
    test/test_exchange.cpp \
    instructions/exchange.cpp

HEADERS += \
    types.h \
    z80.h \
    Memory.h \
    MasterSystem.h \
    utils.h

