#ifndef CHESSCHATWIDGET_H
#define CHESSCHATWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class ChessChatWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessChatWidget)
public:
    static ChessChatWidget *instance();
    ~ChessChatWidget();

signals:
    void send(const QString &msg);

public slots:
    void sendMessage();
    void receiveMessage(const QString &msg);

private:
    void showMessage(bool isMe, const QString &msg);

    const static int maxLength;

    QLineEdit *inputLineEdit;
    QTextEdit *showTextEdit;
    QPushButton *sendPushButton;

    static ChessChatWidget *INSTANCE;

    explicit ChessChatWidget(QWidget *parent = 0);
};

#endif // ChessChatWidget_H
