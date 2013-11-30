#include "chessdefine.h"
#include "chesssetting.h"
#include "chesslog.h"
#include "chessselectionwidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName(QObject::tr("Chinese Chess"));
    app.setApplicationVersion(QLatin1String(CHESS_VERSION_STR));
    app.setOrganizationName(QObject::tr("example"));
    app.setOrganizationDomain(QLatin1String("www.example.com"));

    Q_INIT_RESOURCE(chess);

    Chess_Info(QObject::tr("start Chinese Chess program"));

    Chess_Info(QObject::tr("start read configure file: chess.ini"));
    ChessSetting::instance()->readSetting();    //读取配置文件
    Chess_Info(QObject::tr("end read configure file: chess.ini"));

    ChessSelectionWidget sw;
    sw.show();

    return app.exec();
}
