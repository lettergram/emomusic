#-------------------------------------------------
#
# Project created by QtCreator 2014-05-03T14:01:37
#
#-------------------------------------------------

 QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = emomusic
TEMPLATE = app


SOURCES += main.cpp\
        tsong.cpp\
        user.cpp\
        musicplayer.cpp

HEADERS  += musicplayer.h\
            user.h\
            tsong.h

FORMS    += musicplayer.ui

CONFIG += mobility
MOBILITY = 

