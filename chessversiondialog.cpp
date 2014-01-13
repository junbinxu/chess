#include "chessversiondialog.h"
#include "chesslog.h"
#include "chessdefine.h"
#include "chessversion.h"
#include <QCloseEvent>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopServices>

ChessVersionDialog * ChessVersionDialog::INSTANCE = 0;
ChessVersionDialog * ChessVersionDialog::instance()
{
    if(!INSTANCE) INSTANCE = new ChessVersionDialog;
    return INSTANCE;
}

ChessVersionDialog::ChessVersionDialog(QWidget *parent) :
    QDialog(parent)
{
    //当前版本
    versionLabel = new QLabel(QString::fromUtf8("\xE5\xBD\x93\xE5\x89\x8D\xE7\x89\x88\xE6\x9C\xAC\xEF\xBC\x9A")
                              + CHESS_VERSION_STR);
    //编译日期
    buildTimeLabel = new QLabel(QString::fromUtf8("\xE7\xBC\x96\xE8\xAF\x91\xE6\x97\xA5\xE6\x9C\x9F\xEF\xBC\x9A")
                                + ChessVersion::instance()->buildTime());
    //最新版本 请检查更新
    lastestVersionString = QString::fromUtf8("\xE6\x9C\x80\xE6\x96\xB0\xE7\x89\x88\xE6\x9C\xAC\xEF\xBC\x9A");
    lastestVersionLabel = new QLabel(lastestVersionString
                                     + QString::fromUtf8("\xE8\xAF\xB7\xE6\xA3\x80\xE6\x9F\xA5\xE6\x9B\xB4\xE6\x96\xB0"));

    //下载地址
    downloadLabel = new QLabel(QString::fromUtf8("\xE4\xB8\x8B\xE8\xBD\xBD\xE5\x9C\xB0\xE5\x9D\x80\xEF\xBC\x9A")
                               + QLatin1String("<a href='http://huiwx.github.io/chess.html'>http://huiwx.github.io/chess.html</a>"));
    connect(downloadLabel, SIGNAL(linkActivated(QString)),
                                  this, SLOT(openUrl(QString)));

    //检查更新
    checkPushButton = new QPushButton(QString::fromUtf8("\xE6\xA3\x80\xE6\x9F\xA5\xE6\x9B\xB4\xE6\x96\xB0"));
    connect(checkPushButton, SIGNAL(clicked()), this, SLOT(checkForNew()));

    //确定
    okPushButton = new QPushButton(QString::fromUtf8("\xE7\xA1\xAE\xE5\xAE\x9A"));
    connect(okPushButton, SIGNAL(clicked()), this, SLOT(okPushButtonClicked()));

    QHBoxLayout *pbLayout = new QHBoxLayout;
    pbLayout->addStretch();
    pbLayout->addWidget(checkPushButton);
    pbLayout->addWidget(okPushButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(versionLabel);
    layout->addWidget(buildTimeLabel);
    layout->addWidget(lastestVersionLabel);
    layout->addWidget(downloadLabel);
    layout->addLayout(pbLayout);
    setLayout(layout);

    //关于中国象棋
    setWindowTitle(QString::fromUtf8("\xE5\x85\xB3\xE4\xBA\x8E\xE4\xB8\xAD\xE5\x9B\xBD\xE8\xB1\xA1\xE6\xA3\x8B"));

    Chess_Trace("new ChessVersionDialog");
}

ChessVersionDialog::~ChessVersionDialog()
{
    Chess_Trace("delete ChessVersionDialog");
}

void ChessVersionDialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
    this->hide();
}

void ChessVersionDialog::openUrl(const QString &url)
{
    QDesktopServices::openUrl(QUrl(url));
}

void ChessVersionDialog::okPushButtonClicked()
{
    this->hide();
}

void ChessVersionDialog::checkForNew()
{
    checkPushButton->setDisabled(true);
    lastestVersionLabel->setText(lastestVersionString
                                 + QString::fromUtf8("\xE6\xAD\xA3\xE5\x9C\xA8\xE6\xA3\x80\xE6\x9F\xA5\xE6\x9B\xB4\xE6\x96\xB0"));
    ChessVersion::instance()->checkForNew();
    connect(ChessVersion::instance(), SIGNAL(finished()),
            this, SLOT(updateState()));
}

void ChessVersionDialog::updateState()
{
    ChessVersion::State state = ChessVersion::instance()->state();
    QString tmp = lastestVersionString;
    if(ChessVersion::Old == state)
    {
        tmp.append(ChessVersion::instance()->newVersion());
    }
    else if(ChessVersion::Updated == state)
    {
        tmp.append(CHESS_VERSION_STR);
    }
    else
    {
        tmp.append(QString::fromUtf8("\xE5\x87\xBA\xE9\x94\x99"));
    }
    lastestVersionLabel->setText(tmp);
    checkPushButton->setEnabled(true);
}
