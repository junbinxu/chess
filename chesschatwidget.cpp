#include "chesschatwidget.h"
#include "chesslog.h"
#include "chessinformation.h"
#include "chessprotocol.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateTime>
#include <QKeyEvent>

ChessChatWidget * ChessChatWidget::INSTANCE = 0;

ChessChatWidget * ChessChatWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessChatWidget;
    }
    return INSTANCE;
}

const int ChessChatWidget::maxLength = 20;

ChessChatWidget::ChessChatWidget(QWidget *parent) :
    QWidget(parent)
{
    // 聊天
    titleLabel = new QLabel(QString::fromUtf8("\xe8\x81\x8a\xe5\xa4\xa9"));
    inputLineEdit = new QLineEdit;
    inputLineEdit->setMaxLength(maxLength);
    showTextEdit = new QTextEdit;
    showTextEdit->setReadOnly(true);
    showTextEdit->document()->setMaximumBlockCount(500);
    // 发送
    sendPushButton = new QPushButton(QString::fromUtf8("\xe5\x8f\x91\xe9\x80\x81"));

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(inputLineEdit);
    lay1->addWidget(sendPushButton);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(showTextEdit);
    layout->addLayout(lay1);
    setLayout(layout);



    ChessType chessType = ChessInformation::instance()->getChessType();
    if((ReplayType == chessType) || (AIType == chessType))
    {
        setDisabled(true);
    }
    else
    {
        connect(sendPushButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
        connect(ChessProtocol::instance(), SIGNAL(receiveChatMessage(QString)),
                this, SLOT(receiveMessage(QString)));
    }

    Chess_Trace(tr("new ChessChatWidget"));
}

ChessChatWidget::~ChessChatWidget()
{
    Chess_Trace(tr("delete ChessChatWidget"));
}

void ChessChatWidget::sendMessage()
{
    QString message = inputLineEdit->text().trimmed();
    if(message.isEmpty()) return;
    if(message.size() > maxLength) return;
    ChessProtocol::instance()->sendChatMessage(toUtf8(message));
    inputLineEdit->clear();
    showMessage(true, message);
}

void ChessChatWidget::receiveMessage(const QString &msg)
{
    showMessage(false, fromUtf8(msg));
}

void ChessChatWidget::showMessage(bool isMe, const QString &msg)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString currentTime = dateTime.toString(QLatin1String("yyyy-MM-dd HH:mm:ss"));
    QString speaker;
    if(isMe)
    {
        // 自己
        speaker = QString::fromUtf8("\xe8\x87\xaa\xe5\xb7\xb1");
    }
    else
    {
        // 对方
        speaker = QString::fromUtf8("\xe5\xaf\xb9\xe6\x96\xb9");
    }
    QString message = QString("%1 [%2]\n%3").arg(currentTime).arg(speaker).arg(msg);
    showTextEdit->append(message);
}

void ChessChatWidget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
    {
        return sendMessage();
    }
    return QWidget::keyPressEvent(e);
}

QString ChessChatWidget::toUtf8(const QString &msg) const
{
    if(msg.isEmpty()) return QString();
    QByteArray ba = msg.toUtf8();
    int size = ba.size();
    QString out;
    for(int i=0; i<size; ++i)
    {
        quint8 c = ba.at(i);
        uint num = c;
        QString utf8 = "_" +  QString::number(num, 16).toUpper();
        out.append(utf8);
    }
    return out;
}

QString ChessChatWidget::fromUtf8(const QString &utf8) const
{
    QStringList sl = utf8.split(QChar('_'), QString::SkipEmptyParts);
    int sl_size = sl.size();
    char *buf = new char[sl_size+1];
    for(int i=0; i<sl_size; ++i)
    {
        buf[i] = (char)(sl.at(i).toUShort(0, 16));
    }
    buf[sl_size] = '\0';
    QString out = QString::fromUtf8(buf);
    delete []buf;
    return out;
}
