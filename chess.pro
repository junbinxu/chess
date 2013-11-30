
QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = chess
TEMPLATE = app

SOURCES += \
    main.cpp \
    chesschat.cpp \
    chessmanual.cpp \
    chesssetting.cpp \
    chessinformation.cpp \
    chesslog.cpp

HEADERS += \
    chesschat.h \
    chessdefine.h \
    chessmanual.h \
    chesssetting.h \
    chessinformation.h \
    chesslog.h

RESOURCES += \
    chess.qrc
