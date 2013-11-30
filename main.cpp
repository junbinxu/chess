#include "chesschat.h"
#include "chessmanual.h"
#include "chesssetting.h"
#include "chesslog.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(QObject::tr("Chinese Chess"));
    app.setApplicationVersion(QLatin1String(CHESS_VERSION_STR));
    app.setOrganizationName(QObject::tr("example"));
    app.setOrganizationDomain(QLatin1String("www.example.com"));

    Chess_Info(QObject::tr("start chess program"));

    Chess_Info(QObject::tr("red configure file: chess.ini"));
    ChessSetting::instance()->readSetting();    //读取配置文件

    Chess_Info(QObject::tr("init main gui"));

    ChessChat::instance()->show();

    return app.exec();
}
