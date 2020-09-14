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
#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#include <QObject>
#include "pimpl.hpp"

class Randomizer;
class ScreenManagerPrivate;
class QGraphicsItem;
class QGraphicsView;

/**
 * @brief Screen Manager.
 *
 * This class is responsible for managing screens and everything
 * that is displayed on these screens.
 *
 */
class ScreenManager : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The constructor.
     *
     * @param randomizer Pointer to the Randomizer instance.
     * @param parent Pointer to QObject parent class.
     */
    explicit ScreenManager(QObject* parent = nullptr);
    /**
     * @brief The destructor.
     *
     */
    ~ScreenManager();
    /**
     * @brief Close all views.
     *
     */
    void close();
    /**
     * @brief Add QGraphicsItem to screen.
     *
     * @param item QGraphicsItem to add.
     */
    void addItem(QGraphicsItem* item);
    /**
     * @brief Show all views.
     *
     * Shows all views in full screen mode. For multiple monitors each view is
     * placed on its screen.
     */
    void show();
private:
    ScreenManager(const ScreenManager&) = delete;
    ScreenManager& operator=(const ScreenManager&) = delete;
    /**
     * @brief Create views.
     *
     * Create view for each screen.
     * For multiple monitor configuration it resizes the scene for the maximum
     * resolution. Each view is paired with its screen, this mapping is stored
     * in m_screenToViewMap.
     *
     */
    void createViews();   
    /**
     * @brief Get scene boundaries that new element will fit to screen.
     *
     * @param sceneRect Scene rectangle.
     * @param itemRect Item rectangle.
     * @return QRectF Scene boundaries.
     */
    QRectF getSceneBoundariesForItem(const QRectF& sceneRect,
                                     const QRectF& itemRect) const;
    /**
     * @brief Get random position on @p sceneRect.
     *
     * @param sceneRect Scene rectangle.
     * @return QPointF Random position coordinates.
     */
    QPointF getRandomPosition(const QRectF& sceneRect) const;
    /**
     * @brief Get random view.
     *
     * @return QGraphicsView Random view.
     */
    QGraphicsView* getRandomView() const;
    /**
     * @brief Insert short help string on top of @p view.
     * @param view View to insert the help.
     */
    void insertShortHelp(const QGraphicsView& view);

    PImpl<ScreenManagerPrivate> pImpl; /**< Pointer to the implementation. */
};

#endif // SCREENMANAGER_HPP
