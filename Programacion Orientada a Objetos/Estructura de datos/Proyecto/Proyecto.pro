#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T11:44:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../adadf/hola.cpp

HEADERS  += mainwindow.h \
    ../adadf/Arista.h \
    ../adadf/Grafo.h \
    ../adadf/GrafoUtils.h \
    ../adadf/redNeuronal.h \
    ../adadf/Vertice.h

FORMS    += mainwindow.ui
