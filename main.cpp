#include "chesschat.h"
#include "chessmanual.h"
#include "chesssetting.h"
#include "chesslog.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(QObject::tr("Chinese Chess"));
    app.setApplicationVersion(QLatin1String(CHESS_VERSION_STR));
    app.setOrganizationName(QObject::tr("example"));
    app.setOrganizationDomain(QLatin1String("www.example.com"));

    //读取配置文件
    ChessSetting::instance()->readSetting();

    Chess_Debug("fdsfads");

    QWidget w;
    w.show();

    return app.exec();
}
