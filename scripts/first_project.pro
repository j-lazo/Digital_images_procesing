#-------------------------------------------------
#
# Project created by QtCreator 2019-08-14T13:47:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = first_project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    brigthnes_dialog.cpp \
    high_contrast_window.cpp

HEADERS  += mainwindow.h \
    brigthnes_dialog.h \
    high_contrast_window.h

FORMS    += mainwindow.ui \
    brigthnes_dialog.ui \
    high_contrast_window.ui
