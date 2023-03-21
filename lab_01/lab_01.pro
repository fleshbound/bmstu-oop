QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += inc/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    ./src/errors.cpp \
    ./src/action.cpp \
    src/canvas.cpp \
    src/edges.cpp \
    src/figure.cpp \
    src/fileio.cpp \
    src/math.cpp \
    src/point.cpp \
    src/points.cpp

HEADERS += \
    ./inc/mainwindow.h \
    ./inc/errors.h \
    ./inc/action.h \
    inc/canvas.h \
    inc/data.h \
    inc/edges.h \
    inc/figure.h \
    inc/fileio.h \
    inc/math.h \
    inc/point.h \
    inc/points.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data_in.txt \
    data_out.txt
