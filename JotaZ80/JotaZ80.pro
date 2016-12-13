QT += core
QT -= gui

CONFIG += c++11

TARGET = JotaZ80
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    z80.cpp

HEADERS += \
    types.h \
    z80.h
