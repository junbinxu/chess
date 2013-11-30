#include "chesssetting.h"
#include "chesslog.h"
#include <QSettings>
#include <QCoreApplication>

ChessSetting * ChessSetting::INSTANCE = 0;

ChessSetting * ChessSetting::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessSetting;
    }
    return INSTANCE;
}

ChessSetting::ChessSetting()
{
    iniFileName = QCoreApplication::applicationDirPath() + QLatin1String("/chess.ini");

    Chess_Trace(QObject::tr("new ChessSetting"));
}

ChessSetting::~ChessSetting()
{
    Chess_Trace(QObject::tr("delete ChessSetting"));
}

QString ChessSetting::get(const QString &key) const
{
    return setting.value(key.toLower(), QString()).toLower();
}

void ChessSetting::set(const QString &key, const QString &value)
{
    setting.insert(key.toLower(), value.toLower());
}

void ChessSetting::saveSetting()
{
    QSettings conf(iniFileName, QSettings::IniFormat);
    conf.setIniCodec("UTF-8");
    conf.beginGroup(QLatin1String("chess"));
    QHash<QString, QString>::const_iterator it = setting.constBegin();
    while (it != setting.constEnd())
    {
        conf.setValue(it.key().toLower(), it.value().toLower());
        ++it;
    }
    conf.endGroup();
}

void ChessSetting::readSetting()
{
    QSettings conf(iniFileName, QSettings::IniFormat);
    conf.setIniCodec("UTF-8");

}
