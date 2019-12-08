#-------------------------------------------------
#
# Project created by QtCreator 2018-02-27T21:11:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = avl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -fexec-charset=utf-8

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    AVL.cpp \
    ChildAVL.cpp \
    file.cpp \
    dialog.cpp \
    apply_user.cpp \
    apply_hobby.cpp \
    apply_random.cpp \
    apply_specialfunction.cpp \
    set.cpp \
    apply_relation.cpp

HEADERS += \
        mainwindow.h \
    head.h \
    dialog.h \
    picosha2.h

FORMS += \
        mainwindow.ui \
    dialog.ui

SUBDIRS += \
    avl.pro

DISTFILES += \
    avl.pro.user

RESOURCES +=
