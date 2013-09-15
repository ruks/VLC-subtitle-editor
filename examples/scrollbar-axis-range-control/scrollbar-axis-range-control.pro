#-------------------------------------------------
#
# Project created by QtCreator 2013-07-25T20:43:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = scrollbar-axis-range-control
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../qcustomplot.cpp

HEADERS  += mainwindow.h \
    ../../qcustomplot.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/i386-linux-gnu/release/ -lsndfile
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/i386-linux-gnu/debug/ -lsndfile
else:symbian: LIBS += -lsndfile
else:unix: LIBS += -L$$PWD/../../../../../../../usr/lib/i386-linux-gnu/ -lsndfile

INCLUDEPATH += $$PWD/../../../../../../../usr/lib/i386-linux-gnu
DEPENDPATH += $$PWD/../../../../../../../usr/lib/i386-linux-gnu
