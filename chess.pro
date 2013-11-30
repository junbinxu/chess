
QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = chess
TEMPLATE = app

SOURCES += \
    main.cpp \
    chessmanual.cpp \
    chesssetting.cpp \
    chessinformation.cpp \
    chesslog.cpp \
    chess.cpp \
    chesscenterwidget.cpp \
    chesschatwidget.cpp

HEADERS += \
    chessdefine.h \
    chessmanual.h \
    chesssetting.h \
    chessinformation.h \
    chesslog.h \
    chess.h \
    chesscenterwidget.h \
    chesschatwidget.h

RESOURCES += \
    chess.qrc
