#ifndef GAME_HPP
#define GAME_HPP

#include <QObject>
#include <memory>

#include "pimpl.hpp"

class QApplication;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsView;

class GamePrivate;
// TODO: Document this class
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QApplication* app, QObject *parent = nullptr);
    ~Game();
public slots:
    void startGame();
private slots:
    void handleKeyPress(const QString&);
private:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void createViews();
    void setupInputWidget();
    void quitGame();

    PImpl<GamePrivate> pImpl;
};

#endif // GAME_HPP
