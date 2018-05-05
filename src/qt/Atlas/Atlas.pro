#-------------------------------------------------
#
# Project created by QtCreator 2018-03-18T16:30:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atlas
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

LIBS += $$system(/usr/local/bin/pkg-config --cflags --libs libbitcoin libbitcoin-client libcurl jsoncpp libcrypto)

mac {
    PKG_CONFIG = /usr/local/bin/pkg-config
    CONFIG += link_pkgconfig
    PKGCONFIG += libbitcoin
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        app.cpp \
    restore_wallet.cpp \
    start_menu.cpp \
    ../../wallet/wallet.cpp \
    ../../wallet/transaction.cpp \
    ../../wallet/utxo.cpp \
    ../../wallet/error.cpp \
    ../../network/network.cpp \
    ../../script/script.cpp \
    ../../script/operation.cpp

HEADERS += \
        app.h \
    restore_wallet.h \
    start_menu.h \
    ../../wallet/stdafx.h

FORMS += \
        app.ui \
    restore_wallet.ui \
    start_menu.ui
