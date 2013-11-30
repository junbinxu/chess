
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
    chesschatwidget.cpp \
    chessrule.cpp \
    chessdata.cpp \
    chesssound.cpp \
    chesscore.cpp \
    chessboardwidget.cpp \
    chesstipswidget.cpp \
    chessmanualwidget.cpp \
    chessfunctionwidget.cpp \
    chessdispatch.cpp \
    chessreplay.cpp \
    chessserver.cpp \
    chessclient.cpp \
    chessaicontrol.cpp

HEADERS += \
    chessdefine.h \
    chessmanual.h \
    chesssetting.h \
    chessinformation.h \
    chesslog.h \
    chess.h \
    chesscenterwidget.h \
    chesschatwidget.h \
    chessrule.h \
    chessdata.h \
    chesssound.h \
    chesscore.h \
    chessboardwidget.h \
    chesstipswidget.h \
    chessmanualwidget.h \
    chessfunctionwidget.h \
    chessdispatch.h \
    chessreplay.h \
    chessserver.h \
    chessclient.h \
    chessaicontrol.h

RESOURCES += \
    chess.qrc
