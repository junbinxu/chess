#ifndef CHESSVERSIONDIALOG_H
#define CHESSVERSIONDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QCloseEvent;
QT_END_NAMESPACE

class ChessVersionDialog : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessVersionDialog)
public:
    static ChessVersionDialog * instance();
    ~ChessVersionDialog();

protected:
    void closeEvent(QCloseEvent * event);

signals:

public slots:
    void openUrl(const QString &url);
    void okPushButtonClicked();
    void checkForNew();
    void updateState();

private:
    static ChessVersionDialog * INSTANCE;
    explicit ChessVersionDialog(QWidget *parent = 0);

    QLabel *versionLabel;
    QLabel *buildTimeLabel;
    QLabel *lastestVersionLabel;
    QLabel *downloadLabel;

    QString lastestVersionString;

    QPushButton *checkPushButton;
    QPushButton *okPushButton;
};

#endif // CHESSVERSIONDIALOG_H
