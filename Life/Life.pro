#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T08:08:28
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Life
TEMPLATE = app

INCLUDEPATH += ../

SOURCES += main.cpp\
    ../COMMON/MAP/ColorLinesTile.cpp \
    Life.cpp \
    ../COMMON/INTERFACES/AbstractColorLinesGame.cpp \
    ../COMMON/GUI/ColorLinesWidget.cpp \
    ../COMMON/MAP/ColorLinesTileMap.cpp \
    GameData.cpp \
    LifeBuilder.cpp \
    ../COMMON/INTERFACES/AbstractGameBuilder.cpp \

HEADERS  += \
    ../COMMON/MAP/ColorLinesTile.h \
    Life.h \
    ../COMMON/INTERFACES/AbstractColorLinesGame.h \
    ../COMMON/GUI/ColorLinesWidget.h \
    ../COMMON/MAP/ColorLinesTileMap.h \
    GameData.h \
    LifeBuilder.h \
    ../COMMON/INTERFACES/AbstractGameBuilder.h \
    ../COMMON/MISC/sign.h \
