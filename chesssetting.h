#ifndef CHESSSETTING_H
#define CHESSSETTING_H

#include <QHash>

class ChessSetting
{
    Q_DISABLE_COPY(ChessSetting)
public:
    static ChessSetting *instance();
    ~ChessSetting();
    QString get(const QString &key) const;
    void set(const QString &key, const QString &value);
    void saveSetting();
    void readSetting();

private:
    static ChessSetting *INSTANCE;
    explicit ChessSetting();

    QHash<QString, QString> setting;
    QString iniFileName;
};

#endif // CHESSSETTING_H
