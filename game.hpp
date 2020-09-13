/*
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GAME_HPP
#define GAME_HPP

#include <QObject>
#include <memory>

#include "pimpl.hpp"

class QApplication;
class QGraphicsItem;
class QGraphicsScene;
class QGraphicsView;
class IKeyboardGrabber;

class GamePrivate;
// TODO: Document this class
class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QApplication* app,
                  std::unique_ptr<IKeyboardGrabber> keyboardGrabber,
                  QObject *parent = nullptr);
    ~Game();
public slots:
    void startGame();
signals:
    void quit();
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
