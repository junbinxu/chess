#ifndef CHESSCHAT_H
#define CHESSCHAT_H

#include "chessdefine.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class ChessChat : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessChat)
public:
    static ChessChat *instance();

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

    static ChessChat *INSTANCE;

    explicit ChessChat(QWidget *parent = 0);
};

#endif // CHESSCHAT_H
