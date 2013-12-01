#include "chesstipswidget.h"
#include "chesslog.h"
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDateTime>

ChessTipsWidget * ChessTipsWidget::INSTANCE = 0;
ChessTipsWidget * ChessTipsWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessTipsWidget;
    }
    return INSTANCE;
}

ChessTipsWidget::ChessTipsWidget(QWidget *parent) :
    QWidget(parent)
{
    titleLabel = new QLabel(tr("system information"));
    tipsTextEdit = new QTextEdit;
    tipsTextEdit->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(tipsTextEdit);
    setLayout(layout);

    Chess_Trace(tr("new ChessTipsWidget"));
}

ChessTipsWidget::~ChessTipsWidget()
{
    Chess_Trace(tr("delete ChessTipsWidget"));
}

void ChessTipsWidget::addTips(const QString &message, TipsLevel level)
{
    QString msg = message.trimmed();
    if(msg.isEmpty()) return;
    QString color;
    switch(level)
    {
    case(NormalLevel): color = QLatin1String("black"); break;
    case(ImportantLevel): color = QLatin1String("blue"); break;
    case(SeriousLevel): color = QLatin1String("red"); break;
    default: color = QLatin1String("yellow"); break;
    }
    QString currentTime = QDateTime::currentDateTime()
            .toString(QLatin1String("HH:mm:ss"));
    tipsTextEdit->append(QString("<font color='%1'>%2 %3</font>")
                         .arg(color)
                         .arg(currentTime)
                         .arg(msg));
}
