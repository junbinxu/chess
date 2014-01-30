#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QMenu;
class QToolBar;
class QAction;
class QToolBar;
QT_END_NAMESPACE

class Chess : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(Chess)
public:
    static Chess *instance();
    ~Chess();

signals:

public slots:
    void aboutQt();
    void newGame();
    void startGame();
    void exitGame();
    void changeGame();
    void saveGame();

protected:
    void closeEvent(QCloseEvent *event);

private:
    static Chess *INSTANCE;
    explicit Chess(QWidget *parent = 0);

    void initActions();
    void initMenuBar();
    void initToolBar();

    QAction *aboutQtAction;
    QAction *aboutChineseChessAction;
    QAction *newGameAction;
    QAction *exitGameAction;
    QAction *startGameAction;
    QAction *changeGameAction;
    QAction *saveGameAction;

    QMenu *helpMenu;

    QToolBar *toolbar;
};

#endif // CHESS_H
