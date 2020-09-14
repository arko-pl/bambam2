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
#include "screenmanager.hpp"

#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGuiApplication>
#include <QHash>
#include <QScreen>
#include <QWindow>

// TODO: debug
#include <QtDebug>

#include "randomizer.hpp"
/**
 * @brief Screen Manager Implementation Class.
 *
 */
class ScreenManagerPrivate {
public:
    explicit ScreenManagerPrivate() :
    m_randomizer() {}

    Randomizer m_randomizer;  /**< Random number generator. */
    QGraphicsScene m_scene; /**< Scene. */
    QHash<QScreen*, QGraphicsView*> m_screenToViewMap; /**< Screen to view
                                                            mapping. */
};

ScreenManager::ScreenManager(QObject *parent)
    : QObject(parent) {

    pImpl = std::make_unique<ScreenManagerPrivate>();

    createViews();
}

ScreenManager::~ScreenManager() {
    for (auto view : pImpl->m_screenToViewMap) {
        delete view;
    }
}

void ScreenManager::close() {
    for (auto view : pImpl->m_screenToViewMap) {
        view->close();
    }
}

void ScreenManager::addItem(QGraphicsItem* item) {
    auto view = getRandomView();
    auto scene = view->scene();
    auto sceneRect = view->sceneRect();

    qDebug() << sceneRect;
    auto itemSize = item->boundingRect().size();
    scene->addItem(item);
    auto availableSceneRect = getSceneBoundariesForItem(sceneRect,
                                QRectF(QPointF(0,0), itemSize * item->scale()));
    qDebug() << availableSceneRect;
    item->setPos(getRandomPosition(availableSceneRect));

    if (scene->items().count() > 30) {
        scene->clear();
    }
}

void ScreenManager::show()
{
    for (auto it = pImpl->m_screenToViewMap.cbegin();
         it != pImpl->m_screenToViewMap.cend(); ++it) {
        auto view = it.value();
        auto screen = it.key();
        view->show();
        view->windowHandle()->setScreen(screen);
        view->windowHandle()->setPosition(screen->geometry().topLeft());
        view->setFocus();
        view->showFullScreen();
    }
}

void ScreenManager::createViews() {
    /* TODO: add support for dynamic screen addition/removal */
    /* TODO: add support for configurable screens */
    QRect sceneRect(0,0,0,0);
    for (const auto screen : QGuiApplication::screens()) {
        auto geometry = screen->geometry();
        if (sceneRect.left() > geometry.left()) {
            sceneRect.setLeft(geometry.left());
        }
        if (sceneRect.top() > geometry.top()) {
            sceneRect.setTop(geometry.top());
        }
        if (sceneRect.right() < geometry.right()) {
            sceneRect.setRight(geometry.right());
        }
        if (sceneRect.bottom() < geometry.bottom()) {
            sceneRect.setBottom(geometry.bottom());
        }

        auto view = new QGraphicsView(&pImpl->m_scene);
        view->setSceneRect(screen->geometry());
        view->setHorizontalScrollBarPolicy(
                    Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(
                    Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        pImpl->m_screenToViewMap.insert(screen, view);
        insertShortHelp(*view);
    }

    pImpl->m_scene.setSceneRect(sceneRect);
    qDebug() << "Scene Rect: " << sceneRect;
}

QRectF ScreenManager::getSceneBoundariesForItem(const QRectF& sceneRect, const QRectF& itemRect) const {
    QRectF result = sceneRect;
    result.setBottomRight(sceneRect.bottomRight() - itemRect.bottomRight());
    return result;
}

QPointF ScreenManager::getRandomPosition(const QRectF& sceneRect) const {
    auto topLeft = sceneRect.topLeft();
    auto bottomRight = sceneRect.bottomRight();

    auto posX =
            pImpl->m_randomizer.getRandomReal(topLeft.x(),
                                              bottomRight.x());

    auto posY =
            pImpl->m_randomizer.getRandomReal(topLeft.y(),
                                              bottomRight.y());

    return QPointF(posX, posY);
}

QGraphicsView*ScreenManager::getRandomView() const {
    auto views = this->pImpl->m_screenToViewMap.values();
    if (views.count() == 1) {
        return views.at(0);
    }

    int viewNr = pImpl->m_randomizer.getRandomInt(0, views.count() - 1);

    return views.at(viewNr);
}

void ScreenManager::insertShortHelp(const QGraphicsView& view)
{
    auto item = new QGraphicsTextItem(tr("Type 'quit' to exit game"));
    item->setDefaultTextColor(QColor(0xc0,0xc0,0xc0));
    item->setPos(view.sceneRect().left(),
                 view.sceneRect().top());
    QFont font("Helvetica", 8);
    item->setFont(font);
    view.scene()->addItem(item);
}
