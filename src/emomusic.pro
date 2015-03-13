#-------------------------------------------------
#
# Project created by QtCreator 2014-05-03T14:01:37
#
#-------------------------------------------------

 QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = emomusic
TEMPLATE = app

LIBS += -L$$/usr/local/lib/EmotivSDKLib-PREMIUM -ledk

SOURCES += main.cpp\
        tsong.cpp\
        user.cpp\
        worker.cpp\
        ../lib/remotiv.cpp \
        musicplayer.cpp

HEADERS  += musicplayer.h\
            user.h\
            worker.h\
            ../lib/edk.h \
            ../lib/edkErrorCode.h \
            ../lib/EmoStateDLL.h \
            ../lib/remotiv.h \
            tsong.h

FORMS    += musicplayer.ui

CONFIG += mobility
MOBILITY = 

